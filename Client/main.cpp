#include "./communicate/ServerInit.h"
#include "./Parse/ParseComm.h"

int main(){
    int fd;
    while (1){
        fd= InitSocker();
        COM c;
        char str[1024]="";
        char buf[1024]="";
        std::cout<<"MyRedis>";
        std::string comm;
        std::string Value;
        std::cin>>comm;
        if(!c.JudgeComm(comm)){
            std::cout<<"No find command"<<std::endl;
            setbuf(stdin, NULL);
            continue;
        }
        std::getline(std::cin,Value);
        comm=comm+Value;

        strcpy(str,comm.c_str());

        Write(fd,str);
        read(fd, buf, sizeof(buf)-1);

        std::cout<<buf<<std::endl;

    }
    close(fd);
}


