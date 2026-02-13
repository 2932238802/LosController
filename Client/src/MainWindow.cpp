#include "MainWindow.h"
#include "ui_MainWindow.h"


/// <summary>
/// 26_2_13
/// - 初始化构造函数
/// </summary>
/// <param name="parent"></param>
MainWindow::MainWindow(QWidget* parent):
	QWidget(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}



/// <summary>
/// 26_2_13
/// - 析构函数
/// </summary>
/// <param name="parent"></param>
MainWindow::~MainWindow() {
	delete ui;
}
