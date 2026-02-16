
#pragma once

#include<QWidget>
#include<QObject>
#include <qtmetamacros.h>
#include"ConnectPage_style.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class ConnectPage;
}
QT_END_NAMESPACE


namespace LosComponent{

	class ConnectPage : public QWidget
	{
		Q_OBJECT
	private:


	public:
		explicit ConnectPage(QWidget* parent = nullptr);
		~ConnectPage();

	private:
		void initConnect();
		void initStyle();
		
	private slots:
		void onImageReceived(const QPixmap &pixmap);


	private:
		Ui::ConnectPage* ui;
	};
}
