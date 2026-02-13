#pragma once

#include<QWidget>
#include<QObject>

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QWidget
{
	Q_OBJECT
private:


public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow* ui;
};