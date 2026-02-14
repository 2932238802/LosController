#pragma once
#include <QObject>
#include <QTcpSocket>
#include "protocal.pb.h"

namespace LosNet
{

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
	void onErrorOccur();
	void onReadyRead();

signals:
	void _connected(bool is_connected);

private:
	void initConnect();

private:
	QTcpSocket* LOS_tcp;
	QByteArray LOS_byte;
};
}
