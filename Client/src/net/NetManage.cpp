#include "NetManage.h"

namespace LosNet
{
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="parent"></param>
	NetManage::NetManage(QObject* parent):
		QObject(parent)
	{
		LOS_tcp = new QTcpSocket(this);
	}



	/// <summary>
	/// 26_2_13
	/// - 析构
	/// </summary>
	NetManage::~NetManage()
	{

	}



	/// <summary>
	/// 26_2_13
	/// - 初始化连接
	/// </summary>
	void NetManage::initConnect()
	{
	}



	/// <summary>
	/// 连接
	/// </summary>
	/// <param name="ip"></param>
	/// <param name="port"></param>
	void NetManage::conn(const QString& ip, uint16_t port)
	{
		if (LOS_tcp->state() == QAbstractSocket::UnconnectedState)
		{
			LOS_tcp->connectToHost(ip, port);
		}
	}



	/// <summary>
	/// 26_2_13
	/// - 断开连接
	/// </summary>
	void NetManage::disConn()
	{
		LOS_tcp->disconnectFromHost();
	}



	/// <summary>
	/// 26_2_13
	/// - 发送信息
	/// </summary>
	/// <param name="msg"></param>
	void NetManage::sendMessage(const los_protocal::LosMessage& msg)
	{

	}




}
