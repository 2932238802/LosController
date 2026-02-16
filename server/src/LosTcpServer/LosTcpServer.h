

#include <cstdint>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#include "logger.h"


/**
26_2_15
- 服务器 连接类
*/
class LosTcpServer {

private:
    int LOS_serverFd;
    int LOS_clientFd;

public:
    LosTcpServer();
    ~LosTcpServer();
    bool start_l(uint16_t port);
    bool accept_l();
    bool send_l(const std::vector<unsigned char>& data);
    void stop_l();
};