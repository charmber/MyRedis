#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<string.h>
#include "../public/SharedDate.h"
#include "../ParseChar/ParseComm.h"



class Serve{
public:
    Serve();
    void run();

private:
    int sock;
};

Serve::Serve() {


    struct sockaddr_in sever_address;
    bzero(&sever_address,sizeof(sever_address));
    sever_address.sin_family = PF_INET;
    sever_address.sin_addr.s_addr = htons(INADDR_ANY);
    sever_address.sin_port = htons(8888);

    sock = socket(AF_INET,SOCK_STREAM,0);

    assert(sock>=0);

    int ret = bind(sock, (struct sockaddr*)&sever_address,sizeof(sever_address));
    assert(ret != -1);

    ret = listen(sock,128);
    assert(ret != -1);
}

void Serve::run() {
    while(1)
    {
        struct sockaddr_in client;
        socklen_t client_addrlength = sizeof(client);
        connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
        if(connfd<0)
        {
            printf("errno\n");
        }
        else{
            char request[1024]="";
            recv(connfd,request,1024,0);
            request[strlen(request)+1]='\0';
            strcpy(COMM,request);
            printf("%s\n",request);

            //分离字符串和命令，并调用相应操作命令函数
            CommOperate(parseOperate(request,1024),opCom);

        }
    }
}




