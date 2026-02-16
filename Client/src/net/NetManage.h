#pragma once
#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <qpixmap.h>
#include <qstringview.h>
#include "logger.h"
#include "protocal.pb.h"

namespace LosNet
{
/// <summary>
/// 26_2_15
/// - 单例模式 实现
/// </summary>
class NetManage : public QObject {
	Q_OBJECT

public:
	static NetManage& instance()
	{
		static NetManage net;
		return net;
	}
	
	void conn(const QString& ip, uint16_t port);
	void disConn();
	void sendMessage(const los_protocal::LosMessage& msg);

private:
	explicit NetManage(QObject* parent = nullptr);
	NetManage(const NetManage&) = delete;
	NetManage& operator= (const NetManage&) = delete;
	~NetManage();

public slots:
	void onErrorOccur(QAbstractSocket::SocketError error);
	void onReadyRead();

signals:
	void _connected(bool is_connected);
	void _imageFromLinux(const QPixmap& pix);
private:
	void initConnect();
	void processData(const QByteArray& data);

private:
	QTcpSocket* LOS_tcp;
	QByteArray LOS_byte;
};
}
