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

	setWindowFlag(Qt::FramelessWindowHint);
	initStyle();
	initConnect();
}



/// <summary>
/// 26_2_13
/// - 析构函数
/// </summary>
/// <param name="parent"></param>
MainWindow::~MainWindow() {
	delete ui;
}




/// <summary>
/// 26_2_13
/// - 初始化样式
/// </summary>
void MainWindow::initStyle()
{
	this->setStyleSheet(MainWindowStyle::style);
}



/// <summary>
/// 26_2_13
/// - 初始化连接
/// </summary>
void MainWindow::initConnect()
{
	connect(ui->btnMin, &QPushButton::clicked, this, &QWidget::showMinimized); 
	connect(ui->btnClose, &QPushButton::clicked, this,&QWidget::close);
	connect(ui->btnNavHome, &QPushButton::clicked, this, [this]() {
		ui->stackedWidget->setCurrentIndex(0);
		});
	connect(ui->btnNavConnect, &QPushButton::clicked, this, [this]() {
		ui->stackedWidget->setCurrentIndex(1);
	});
	connect(ui->btnNavSettings, &QPushButton::clicked, this, [this]() {
		ui->stackedWidget->setCurrentIndex(2);
		});
	connect(ui->initPage, &LosComponent::InitPage::_connected_InitPage,this,[this](bool is_connected){
		if(is_connected)
			ui->stackedWidget->setCurrentIndex(1);	
	}
	);
}
