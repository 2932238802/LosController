
#include "LosTcpServer.h"
#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <cstdint>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>



LosTcpServer::LosTcpServer():
    LOS_clientFd(-1),
    LOS_serverFd(-1)
{
}

LosTcpServer::~LosTcpServer(){
    stop_l();
}


/**
26_2_15
- 开始倾听 接口
*/
bool LosTcpServer::start_l(uint16_t port){
    LOS_serverFd = socket(AF_INET,SOCK_STREAM, 0);
    if(LOS_serverFd == -1) return false;

    int opt = 1;
    setsockopt(LOS_serverFd, SOL_SOCKET, SO_REUSEADDR,&opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;         // 监听所有网卡

    if(bind(LOS_serverFd, (struct sockaddr*)(&addr), sizeof(addr)) < 0)
    {
        return false;
    }

    if(listen(LOS_serverFd , 5) < 0 )
    {
        return false;
    }

    LOGI("server start on port ...");
    return true;
}


bool LosTcpServer::accept_l(){
    sockaddr_in clientAddr{};
    socklen_t addrlen = sizeof(clientAddr);

    LOS_clientFd = accept(LOS_serverFd, (struct sockaddr*)&clientAddr, &addrlen);

    if(LOS_clientFd > 0)
    {
        int flag = 1;
        setsockopt(LOS_clientFd, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(int));
        LOGI("client connected: ");
        LOGI(inet_ntoa(clientAddr.sin_addr));
        return true;
    }

    return false;
}




/**

*/
bool LosTcpServer::send_l(const los_protocal::LosMessage& msg) {
    if (LOS_clientFd == -1) return false;

    std::string out;
    if (!msg.SerializeToString(&out)) return false;

    uint32_t size = htonl(static_cast<uint32_t>(out.size()));

    if (sendAll(LOS_clientFd, &size, 4) < 0) return false;
    if (sendAll(LOS_clientFd, out.data(), out.size()) < 0) return false;

    return true;
}



/**
26_2_15
- 暂停的逻辑
*/
void LosTcpServer::stop_l(){

    if(LOS_serverFd != -1) close(LOS_serverFd);
    if(LOS_clientFd != -1) close(LOS_serverFd);
    LOS_serverFd = -1;
    LOS_clientFd = -1;
}




/**
26_2_16
- 一次性 发送完毕的函数
- -1 就是 大报错
*/
ssize_t LosTcpServer::sendAll(int fd , const void* buf ,size_t len){
    ssize_t totalHasSend = 0;
    const char* ptr = (const char*)(buf);

    while(totalHasSend < len)
    {
        ssize_t size = send(fd,ptr+totalHasSend,len - totalHasSend ,0);

        if(size < 0) return -1;
        totalHasSend += size;
    }
    return totalHasSend;
}




/**
26_2_15
- 发送数据

26_2_16
- 弃用
*/
// bool LosTcpServer::send_l(const std::vector<unsigned char>& data)
// {
//     if( -1 == LOS_clientFd) return false;

//     uint32_t dataSize = static_cast<uint32_t>(data.size());
//     uint32_t netSize = htonl(dataSize);

//     if(send(LOS_clientFd, &netSize,  sizeof(netSize), 0) <= 0)
//     {
//         return false;
//     }

//     if(send(LOS_clientFd,data.data() , data.size(),0) <= 0)
//     {
//         return false;
//     }

//     return true;
// }
