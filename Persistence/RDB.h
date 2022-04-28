#include "../DataStruct/ReString.h"



//struct RdbString{
//    int type;       //数据类型  1:string,2:set,.....
//    int DataNumber;      //数据库号
//    long long exp;          //失效时间
//
//    std::string key;     //键
//    std::string value;      //值
//
//    std::string end;        //结束标识
//};

void String_Rdb(std::ofstream& OpFile);

void RDB_Write(){
    std::ofstream OpFile;
    OpFile.open("/Users/macbook/Desktop/aof.rd",std::ios::out|std::ios::app);
    if(!OpFile){
        std::cout<<"Open File Fail."<<std::endl;
        exit(1);
    }
    String_Rdb(OpFile);

}


//string类型持久化
void String_Rdb(std::ofstream& OpFile){
    std::string body;
    std::string head="1 1\n";     //数据类型and数据库号
    if(!RString.empty()){
        for(auto it:RString){
            body=body+std::to_string(it.second.second)+" "+it.first+" "+it.second.first+" ";
        }
        body.pop_back();
        body+="\n";
    }
    OpFile<<head;
    OpFile<<body;
    OpFile<<"END\n";
}
