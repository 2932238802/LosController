#include "NetManage.h"
#include "protocal.pb.h"
#include <cstdint>
#include <qabstractsocket.h>
#include <qendian.h>
#include <qpixmap.h>
#include <qstringview.h>
#include <qtcpsocket.h>
#include <string>

namespace LosNet {

/// <summary>
///
/// </summary>
/// <param name="parent"></param>
NetManage::NetManage(QObject *parent) : QObject(parent) {
  LOS_tcp = new QTcpSocket(this);
  initConnect();
}

/// <summary>
/// 26_2_13
/// - 析构
/// </summary>
NetManage::~NetManage() {
  if (LOS_tcp)
    LOS_tcp->abort();
}


/**
26_2_15
- 读取 信息

26_2_16
- 修正 通过大端 进行读取
*/
void NetManage::onReadyRead() {
  // 读出 所有的数据
  LOS_byte.append(LOS_tcp->readAll());

  while (LOS_byte.size() >= (int)sizeof(uint32_t)) {
    uint32_t size;
    memcpy(&size, LOS_byte.data(), sizeof(uint32_t));
    uint32_t sizeBig = qFromBigEndian(size);       // 变成大端
    
    if (LOS_byte.size() < (int)(sizeBig + sizeof(uint32_t)))
      break;

    QByteArray packet = LOS_byte.mid(sizeof(uint32_t), sizeBig);

    processData(packet);

    LOS_byte.remove(0, sizeof(uint32_t) + sizeBig);
  }
}

void NetManage::onErrorOccur(QAbstractSocket::SocketError error) {

  QString errMsg = LOS_tcp->errorString();

  switch (error) {
  case QAbstractSocket::ConnectionRefusedError: {
    LOGE(QString("connect refuse: %1").arg(errMsg).toStdString());
    return;
  }
  case QAbstractSocket::HostNotFoundError: {
    LOGE(QString("host not found: %1").arg(errMsg).toStdString())
    return;
  }
  case QAbstractSocket::SocketTimeoutError: {
    LOGE(QString("socket timeout : %1").arg(errMsg).toStdString())
    return;
  }
  case QAbstractSocket::NetworkError: {
    LOGE(QString("network error: %1").arg(errMsg).toStdString());
    return;
  }
  default: {
    LOGE(QString("unkown error: %1").arg(errMsg).toStdString());
    return;
  }
  }
}

/// <summary>
/// 26_2_13
/// - 初始化连接
/// </summary>
void NetManage::initConnect() {
  connect(LOS_tcp, &QTcpSocket::errorOccurred, this, &NetManage::onErrorOccur);
  connect(LOS_tcp, &QTcpSocket::readyRead, this, &NetManage::onReadyRead);
  connect(LOS_tcp, &QTcpSocket::connected, this, [&]() {
    LOGI("connected");
    emit _connected(true);
  });
  connect(LOS_tcp , &QTcpSocket::disconnected,this,[&](){
	LOGI("unconnected");
	LOS_byte.clear();
	emit _connected(false);
  });
}

/// <summary>
/// 26_2_15
/// - 处理处理
/// </summary>
/// <param name="data"></param>
void NetManage::processData(const QByteArray &data) {
  los_protocal::LosMessage msg;

  if (!msg.ParseFromArray(data.data(), data.size())) {
    LOGE("parsing failed!");
    return;
  }

  switch (msg.type()) {
  case los_protocal::Msgtype::IMAGE: {
    const auto& frame = msg.image_frame();
    QByteArray jpegData(frame.data().c_str(),(int)frame.data().size());
    QPixmap pixmap;

    if(pixmap.loadFromData(jpegData,"JPEG"))    // 转成 jpeg
    {
      emit _imageFromLinux(pixmap);
      LOGD("receive image");
    }
    break;
  }
  case los_protocal::Msgtype::MOUSE: {
    LOGD("receive mouse");
    break;
  }
  case los_protocal::Msgtype::KEYBOARD: {
    LOGD("receive keyborad");
    break;
  }
  case los_protocal::Msgtype::HEARTBEAT: {
    LOGD("receive heartbeat");
    break;
  }
  default: {
    LOGW("unkown data");
    break;
  }
  }
}

/// <summary>
/// 连接
/// </summary.
/// <param name="ip"></param>
/// <param name="port"></param>
void NetManage::conn(const QString &ip, uint16_t port) {
  if (LOS_tcp->state() == QAbstractSocket::UnconnectedState) {
    LOS_tcp->connectToHost(ip, port);
  }
}



/**
26_2_13
- 断开连接
 */
void NetManage::disConn() { LOS_tcp->disconnectFromHost(); }



/**
26_2_13
- 发送信息

26_2_16
- 转成大端的逻辑
*/
void NetManage::sendMessage(const los_protocal::LosMessage &msg) {
  if (!(LOS_tcp->state() == QTcpSocket::ConnectedState)) {
    LOGW("unconnected");
    return;
  }

  std::string serialiseMsg = msg.SerializeAsString();
  uint32_t size = static_cast<uint32_t>(serialiseMsg.size());
  uint32_t sizeBigEnd = qToBigEndian(size);               // 转成大端的逻辑

  QByteArray block;
  block.append(reinterpret_cast<const char *>(&sizeBigEnd), sizeof(int32_t));
  block.append(serialiseMsg.c_str(), serialiseMsg.size());

  LOS_tcp->write(block);
}
} // namespace LosNet
