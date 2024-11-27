#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/ros2/PointCloud2_.hpp>

#define TOPIC_CLOUD "rt/utlidar/cloud"
#define PORT 8080
#define CHUNK_SIZE 60000  // Slightly less than max UDP size
#define HEADER_SIZE 8 

using namespace unitree::robot;
using namespace unitree::common;

struct PacketHeader {
    uint32_t total_chunks;
    uint32_t chunk_index;
};

void Handler(const void *message) {
    const sensor_msgs::msg::dds_::PointCloud2_ *cloud_msg = 
        (const sensor_msgs::msg::dds_::PointCloud2_ *)message;
    std::cout << "Received a raw cloud here!"
              << "\n\tstamp = " << cloud_msg->header().stamp().sec() 
              << "." << cloud_msg->header().stamp().nanosec()
              << "\n\tframe = " << cloud_msg->header().frame_id()
              << "\n\tpoints number = " << cloud_msg->width()
              << std::endl << std::endl;
}

int main(int argc, char** argv) {
    // Initialize video client
    unitree::robot::ChannelFactory::Instance()->Init(0);
    unitree::robot::go2::VideoClient video_client;
    video_client.SetTimeout(1.0f);
    video_client.Init();
    std::vector<uint8_t> image_sample;
    int imageSuccessCode;

    // Create and configure socket
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    
    // Create socket with explicit IPv4 protocol
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Clear the structures before use
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Configure server address
    server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Configure client address
    client_addr.sin_family = AF_INET;
    // client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Localhost
    // client_addr.sin_addr.s_addr = inet_addr("192.168.168.120"); 
    client_addr.sin_addr.s_addr = inet_addr("172.20.10.11"); 
    client_addr.sin_port = htons(8081);

    // Bind socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    std::cout << "UDP Server running on port " << PORT << std::endl;

    socklen_t len = sizeof(client_addr);
    std::vector<uint8_t> packet_buffer(CHUNK_SIZE + HEADER_SIZE);

    while (true) {
        // Get the image data
        imageSuccessCode = video_client.GetImageSample(image_sample);
        if (imageSuccessCode != 0) {
            std::cerr << "Failed to get image sample" << std::endl;
            continue;
        }
        
        std::cout << "Image size: " << image_sample.size() << " bytes" << std::endl;

        // Calculate total chunks needed
        uint32_t total_chunks = (image_sample.size() + CHUNK_SIZE - 1) / CHUNK_SIZE;
        
        // Send data in chunks
        for (uint32_t i = 0; i < total_chunks; i++) {
            // Prepare header
            PacketHeader header;
            header.total_chunks = total_chunks;
            header.chunk_index = i;

            // Copy header to buffer
            std::memcpy(packet_buffer.data(), &header, HEADER_SIZE);

            // Calculate chunk size for this packet
            size_t chunk_start = i * CHUNK_SIZE;
            size_t remaining_bytes = image_sample.size() - chunk_start;
            size_t this_chunk_size = std::min(remaining_bytes, (size_t)CHUNK_SIZE);

            // Copy chunk data to buffer after header
            std::memcpy(packet_buffer.data() + HEADER_SIZE, 
                       image_sample.data() + chunk_start, 
                       this_chunk_size);

            // Send the packet
            ssize_t sent_bytes = sendto(sockfd, packet_buffer.data(), 
                                      this_chunk_size + HEADER_SIZE, 0,
                                      (const struct sockaddr *)&client_addr, len);

            if (sent_bytes < 0) {
                perror("Failed to send data");
                break;
            }
        }

        usleep(1000);  // 1ms delay between frames
    }

    close(sockfd);
    return 0;
}