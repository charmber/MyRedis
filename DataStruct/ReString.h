#include <unordered_map>
#include "../Persistence/AOF.h"
#include "../ParseChar/ParseString.h"

std::unordered_map<std::string,std::pair<std::string,long long>> RString;
std::unordered_map<std::string,std::pair<std::string,long long>> RString1;




//字符串类型添加命令
void ReSet(std::string str){
    std::string key;
    str=segmentSpace(str,key);
    std::string value;
    str=segmentSpace(str,value);
    if(str!=""){
        std::cout<<"command error"<<std::endl;
        char buf[1024]="command error!\0";
        send(connfd,buf,strlen(buf),0);//发送响应
        close(connfd);
    }else{
        KeyType[key]="RString";         //设置全局key，内存淘汰
        RString[key].first=value;
        char buf[1024]="ok!\0";
        send(connfd,buf,strlen(buf),0);//发送响应
        close(connfd);
        std::cout<<"SET: "<<key<<" success! value="<<RString[key].first<<std::endl;

        //持久化操作AOF
        std::string tmp="SET "+key+" "+RString[key].first;
        AOF_Write(tmp);
    }
}

//字符串类型删除命令
void ReDel(std::string str){
    std::string key;
    while (str!=""){
        str=segmentSpace(str,key);

        //查询该键是否存在键-值类型表KeyType
        if(KeyType.find(key)!=KeyType.end()){
            std::string type=KeyType[key];      //保存该键类型
            KeyType.erase(key);
            if(type=="ReString"){       //如果是字符串类型，调用字符串类型删除
                if(RString.find(key)!=RString.end()){
                    RString.erase(key);
                    std::cout<<"DEL:"<<key<<" success"<<std::endl;
                    char buf[1024]="ok!";
                    send(connfd,buf, strlen(buf),0);
                    close(connfd);
                    //持久化操作AOF
                    std::string tmp="DEL "+key+" "+RString[key].first;
                    AOF_Write(tmp);
                } else{
                    std::string tmp="Key:"+key+" no find\0";
                    std::cout<<tmp<<std::endl;
                    char buf[1024]="";
                    StrChangeChar(tmp,buf);
                    send(connfd,buf, 1024,0);
                    close(connfd);
                }
            } else if(type=="ReSet"){       //调用删除集合类型函数

            }
        }


    }
}

void ReGet(std::string key){
    if(RString.find(key)!=RString.end()){
        char buf[1024]="";
        StrChangeChar(RString[key].first,buf);
        send(connfd,buf,1024,0);
        close(connfd);
        std::cout<<"GET:"<<key<<" success"<<std::endl;
    }else{
        std::string tmp="Key:"+key+" no find\0";
        std::cout<<tmp<<std::endl;
        char buf[1024]="";
        StrChangeChar(tmp,buf);
        send(connfd,buf, 1024,0);
        close(connfd);
    }
}