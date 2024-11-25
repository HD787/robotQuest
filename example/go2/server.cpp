#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>


#include <unistd.h>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
// #include "subscribe_pointcloud.cpp"

#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/ros2/PointCloud2_.hpp>

#define TOPIC_CLOUD "rt/utlidar/cloud"

using namespace unitree::robot;
using namespace unitree::common;

#define PORT 8080

//LIDAR HANDLER
void Handler(const void *message)
{
  const sensor_msgs::msg::dds_::PointCloud2_ *cloud_msg = (const sensor_msgs::msg::dds_::PointCloud2_ *)message;
  std::cout << "Received a raw cloud here!"
            << "\n\tstamp = " << cloud_msg->header().stamp().sec() << "." << cloud_msg->header().stamp().nanosec()
            << "\n\tframe = " << cloud_msg->header().frame_id()
            << "\n\tpoints number = " << cloud_msg->width()
            << std::endl
            << std::endl;
}


int main(int argc, char** argv){


    //THIS WILL BE THE IMAGE CODE
    unitree::robot::ChannelFactory::Instance()->Init(0);
    unitree::robot::go2::VideoClient video_client;
    video_client.SetTimeout(1.0f);
    video_client.Init();
    std::vector<uint8_t> image_sample;
    int imageSuccessCode;


    //THIS IS THE SERVER CODE
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024 * 64];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    //this is gonna be local from now on
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_port = htons(8081);
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    std::cout << "UDP Server running on port " << PORT << std::endl;

    socklen_t len = sizeof(client_addr);

    //THIS IS THE LIDAR HANDLER CALL
    // ChannelFactory::Instance()->Init(0, argv[1]);
    // ChannelSubscriber<sensor_msgs::msg::dds_::PointCloud2_> subscriber(TOPIC_CLOUD);
    // subscriber.InitChannel(Handler);

    while (true) {
        //get the image data
        imageSuccessCode = video_client.GetImageSample(image_sample);
        

        sendto(sockfd, image_sample.data(), image_sample.size(), 0, (const struct sockaddr *)&client_addr, len);
        std::cout << image_sample.size() << std::endl;
        //THIS IS WHERE THE LIDAR CODE WILL GO
        // std::vector<uint8_t> image_sample;
        // int ret = video_client.GetImageSample(image_sample);


        usleep(1);
    }

    close(sockfd);
    return 0;
}