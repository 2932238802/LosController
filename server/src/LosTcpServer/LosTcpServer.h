

#include <arpa/inet.h>
#include <cstddef>
#include <cstdint>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#include "logger.h"
#include "protocal.pb.h"

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
//   bool send_l(const std::vector<unsigned char> &data);
  bool send_l(const los_protocal::LosMessage& msg);
  void stop_l();

private:
    static ssize_t sendAll(int fd , const void* buf ,size_t len);
};