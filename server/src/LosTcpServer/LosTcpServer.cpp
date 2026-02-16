
#include "LosTcpServer.h"
#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <cstdint>
#include <netinet/in.h>
#include <sys/socket.h>
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
26_2_15
- 发送数据
*/
bool LosTcpServer::send_l(const std::vector<unsigned char>& data)
{
    if( -1 == LOS_clientFd) return false;

    uint32_t dataSize = static_cast<uint32_t>(data.size());
    uint32_t netSize = htonl(dataSize);

    if(send(LOS_clientFd, &netSize,  sizeof(netSize), 0) <= 0)
    {
        return false;
    }

    if(send(LOS_clientFd,data.data() , data.size(),0) <= 0)
    {
        return false;
    }

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