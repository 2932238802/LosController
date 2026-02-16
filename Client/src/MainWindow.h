#pragma once

#include <QWidget>
#include <QObject>
#include <QPoint>
#include <QMouseEvent>
#include"MainWindow_style.h"
#include"component/InitPage/InitPage.h"

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
	void initStyle();
	void initConnect();

private:
	Ui::MainWindow* ui;
};