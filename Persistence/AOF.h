#include <string>
#include <iostream>
#include<fstream>

void AOF_Write(std::string comm){
    std::ofstream OpFile;
    OpFile.open("/Users/macbook/Desktop/aof.re",std::ios::out|std::ios::app);
    if(!OpFile){
        std::cout<<"Open File Fail."<<std::endl;
        exit(1);
    }
    OpFile<<comm<<std::endl;
}

void AOF_Read(){
    std::ifstream OpFile;
    std::string comm;
    OpFile.open("/Users/macbook/Desktop/aof.re",std::ios::in);
    while(OpFile>>comm){
        //持久化操作
    }
}
