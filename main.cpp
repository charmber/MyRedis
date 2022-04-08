#include "ServerCommun/server.h"

int main()
{
    Serve s;
    s.run();
    return 0;
}

//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <string.h>
//#include <ctype.h>
//#include <arpa/inet.h>
//#include<stdlib.h>
//
//
//
//#define SERVER_PORT 6666
//
//int main(void){
//
//    int sock;//代表信箱
//    struct sockaddr_in server_addr;
//
//
//    //1.美女创建信箱
//    sock = socket(AF_INET, SOCK_STREAM, 0);
//
//    //2.清空标签，写上地址和端口号
//    bzero(&server_addr, sizeof(server_addr));
//
//    server_addr.sin_family = AF_INET;//选择协议族IPV4
//    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//监听本地所有IP地址
//    server_addr.sin_port = htons(SERVER_PORT);//绑定端口号
//
//    //实现标签贴到收信得信箱上
//    bind(sock, (struct sockaddr *)&server_addr,  sizeof(server_addr));
//
//    //把信箱挂置到传达室，这样，就可以接收信件了
//    listen(sock, 128);
//
//    //万事俱备，只等来信
//    printf("等待客户端的连接\n");
//
//
//    int done =1;
//
//    while(done){
//        struct sockaddr_in client;
//        int client_sock, len, i;
//        char client_ip[64];
//        char buf[256];
//
//        socklen_t  client_addr_len;
//        client_addr_len = sizeof(client);
//        client_sock = accept(sock, (struct sockaddr *)&client, &client_addr_len);
//
//        //打印客服端IP地址和端口号
//        printf("client ip: %s\t port : %d\n",
//               inet_ntop(AF_INET, &client.sin_addr.s_addr,client_ip,sizeof(client_ip)),
//               ntohs(client.sin_port));
//        /*读取客户端发送的数据*/
//        len = read(client_sock, buf, sizeof(buf)-1);
//        buf[len] = '\0';
//        printf("receive[%d]: %s\n", len, buf);
//
//        //转换成大写
//        for(i=0; i<len; i++){
//            /*if(buf[i]>='a' && buf[i]<='z'){
//                buf[i] = buf[i] - 32;
//            }*/
//            buf[i] = toupper(buf[i]);
//        }
//
//
//        len = write(client_sock, buf, len);
//
//        printf("finished. len: %d\n", len);
//        close(client_sock);
//
//    }
//    close(sock);
//    return 0;
//}
