#include <string>



//把解析字符串存入key，并返回剩下字符串
std::string segmentSpace(std::string str,std::string &Key){
    std::string tmp;
    int i;
    std::string Value;
    for(i=0;i<str.size();i++){
        if(str[i]==' '){
            tmp.assign(str,0,i);
            break;
        }
    }
    if(i==str.size()){
        Key=str;
    } else{
        Key=tmp;
        Value.assign(str,i+1,str.size()-(i+1));
    }

    return Value;
}
