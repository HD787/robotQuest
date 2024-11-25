// #include <unitree/robot/go2/video/video_client.hpp>
// #include <unitree/robot/go2/lidar/lidar_client.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <arpa/inet.h>


#define PORT 8080

int main(){

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
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    std::cout << "UDP Server running on port " << PORT << std::endl;

    socklen_t len = sizeof(client_addr);

    while (true) {
        sendto(sockfd, "", 0, 0, (const struct sockaddr *)&client_addr, len);

        //THIS IS WHERE THE LIDAR CODE WILL GO
        // std::vector<uint8_t> image_sample;
        // int ret = video_client.GetImageSample(image_sample);

        // if (ret == 0 && !image_sample.empty()) {
        //     sendto(sockfd, image_sample.data(), image_sample.size(), 0, (const struct sockaddr *)&client_addr, len);
        //     std::cout << "Sent a frame of size: " << image_sample.size() << " bytes" << std::endl;
        // }

        usleep(1);
    }

    close(sockfd);
    return 0;
}