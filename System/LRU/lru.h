#include <iostream>
#include <unistd.h>
#include <sstream>
#include "../../public/SharedDate.h"
#include "../../DataStruct/ReString.h"

using namespace std;

template<typename T> inline string toString(const T& var) {
    stringstream ss;
    ss << var;
    return ss.str();
}

// 获取当前进程占有内存
int getMem(pid_t pid) {
    string file_name = "/proc/" + toString(pid) + "/status";
    FILE *fd = fopen(file_name.c_str(), "r");
    char key_value[1024];
    string key;
    int value = -1;
    stringstream ss;
    while(fgets(key_value, sizeof(key_value), fd)) {
        ss.str("");
        ss.clear();
        ss << key_value;
        ss >> key >> value;
        if(key.compare("RssAnon:") == 0)
            break;
    }
    fclose(fd);
    return value;
}

//获取系统空闲内存
int getSystemMen(){
    string file_name = "/proc/meminfo";
    FILE *fd = fopen(file_name.c_str(), "r");
    char key_value[1024];
    string key;
    int value = -1;
    stringstream ss;
    while(fgets(key_value, sizeof(key_value), fd)) {
        ss.str("");
        ss.clear();
        ss << key_value;
        ss >> key >> value;
        if(key.compare("MemFree:") == 0)
            break;
    }
    fclose(fd);
    return value;
}


//内存淘汰最后一个key
void Lru(){
    std::string key=CacheList.back();
    CacheList.pop_back();

    //调用删除函数
    ReDel(key);


}


//判断是否超过使用或者达到内存上限阀值
void ExecLru(){
    int Remain=getSystemMen();
    int UseMen= getMem(getpid());
    if(Remain<100000){      //系统可用内存小于100mb
        Lru();
    } else if(UseMen>1000000){      //使用缓存超过1gb
        Lru();
    }
}

