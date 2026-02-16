
#pragma once

#include<QWidget>
#include<QObject>
#include"SettingPage_style.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class SettingPage;
}
QT_END_NAMESPACE

namespace LosComponent{
	class SettingPage : public QWidget
	{
		Q_OBJECT
	private:


	public:
		explicit SettingPage(QWidget* parent = nullptr);
		~SettingPage();

	private:
		void initConnect();
		void initStyle();

	private:
		Ui::SettingPage* ui;
	};
}
