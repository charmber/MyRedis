#include <string>
#include <set>

const std::string DEL="DEL";        //删除键

//定义命令常量，字符串相关
const std::string SET="SET";        //设置字符串key的值

const std::string GET="GET";         //获取key的值
const std::string GETSET="GETSET";   //获取key的值并设置为value，返回旧值
const std::string MGET="MGET";      //获取所有(一个或多个)给定 key 的值。

//集合相关

const std::string SADD="SADD";        //设置字符串key的值




class COM{
public:
    std::set<std::string> COMM;
    COM();
    bool JudgeComm(std::string str);

};

COM::COM() {
    COMM.insert(SET);
    COMM.insert(DEL);
    COMM.insert(GET);
    COMM.insert(GETSET);
    COMM.insert(MGET);
    COMM.insert(SADD);
}


bool COM::JudgeComm(std::string str) {
    if(COMM.find(str)!=COMM.end()){
        return true;
    }
    return false;
}