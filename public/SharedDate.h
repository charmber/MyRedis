#include <string>
#include <unordered_map>
#include <list>

//KEY的数据类型
std::unordered_map<std::string,std::string> KeyType;

//内存淘汰队列
std::list<std::string> CacheList;




//客户端发送命令字符串接收
char COMM[1024];

int connfd;



void StrChangeChar(std::string str,char msg[]) {
    strcpy(msg,str.c_str());
}