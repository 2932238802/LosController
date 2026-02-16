#pragma once

#include<QWidget>
#include<QObject>
#include"InitPage_style.h"
#include"logger.h"
#include"NetManage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class InitPage;
}
QT_END_NAMESPACE

namespace LosComponent {

class InitPage : public QWidget
{
	Q_OBJECT
private:


public:
	explicit InitPage(QWidget* parent = nullptr);
	~InitPage();

private:
	void initConnect();
	void initStyle();

public slots:
	void onConnectBtnClicked();
	void onConnected(bool is_connect);

signals:
	void _connected_InitPage(bool is_connected);

private:
	Ui::InitPage* ui;
};

}
