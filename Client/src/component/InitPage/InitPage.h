#pragma once

#include<QWidget>
#include<QObject>
#include"InitPage_style.h"

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

private:
	Ui::InitPage* ui;
};

}
