//集合相关实现
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string,std::vector<std::string>> RedSet;


void SetAdd(std::string str){
    std::string key;
    std::string aof=str;
    str= segmentSpace(str,key);
    while (str!=""){
        std::string value;
        str= segmentSpace(str,value);
        RedSet[key].push_back(value);
    }
    AOF_Write("SADD "+aof);
    std::cout<<"SADD "+aof<<std::endl;
    char buf[1024]="ok!";
    send(connfd,buf, strlen(buf),0);
    close(connfd);
}

void SMEMBERS(std::string key){
    int len=RedSet[key].size();
    std::string tmp;
    for(int i=0;i<len;i++){
        tmp+=RedSet[key][i];
        tmp+=" ";
    }

}
