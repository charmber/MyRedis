#include "../DataStruct/ReString.h"
#include "../DataStruct/ReSet.h"


//当前操作命令字符串
std::string opCom;



//解析操作命令给opCom，并返回剩下字符串
std::string parseOperate(char str[], int len){
    std::string Value;
    std::string Sc(str);
    int tmp=0;
    for(int i=0;i<len;i++){
        if(Sc[i]==' '){
            opCom.assign(Sc,tmp,i-tmp);
            tmp=i+1;
            break;
        }
    }
    Value.assign(str,tmp,len-tmp);
    return Value;
}

//传入剩下字符串，以及对应的操作命令
void CommOperate(std::string str,std::string comm){
    if(comm=="SET"){
        ReSet(str);
    }else if(comm=="DEL"){
        ReDel(str);
    }else if(comm=="GET"){
        ReGet(str);
    }else if(comm=="SADD"){
        SetAdd(str);
    }
    else{
        std::cout<<"未找到命令"<<std::endl;
    }
}