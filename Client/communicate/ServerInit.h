#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

#define SERVER_IP  "127.0.0.1"


int InitSocker(int SERVER_PORT=8888){
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, '\0', sizeof(struct sockaddr_in));

    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERVER_PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    return sockfd;
}


//接收
int readComm(int fd,char buf[]){
    int n;
    n = read(fd, buf, sizeof(buf)-1);
    return n;
}


//发送
int Write(int fd,char comm[]){
    write(fd, comm, strlen(comm));
}