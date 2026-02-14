#include "ConnectPage.h"
#include "ui_ConnectPage.h"


namespace LosComponent {

	/// <summary>
	/// 26_2_13
	/// - 构造函数
	/// </summary>
	/// <param name="parent"></param>
	ConnectPage::ConnectPage(QWidget* parent) :
		QWidget{ parent },
		ui(new Ui::ConnectPage)
	{
		ui->setupUi(this);
		initStyle();
	}


	/// <summary>
	/// 26_2_13
	/// - 析构函数
	/// </summary>
	ConnectPage::~ConnectPage()
	{
		delete ui;
	}



	/// <summary>
	/// 26_2_13
	/// - 初始化连接
	/// </summary>
	void ConnectPage::initConnect()
	{

	}




	/// <summary>
	/// 26_2_13
	/// - 初始化样式
	/// </summary>
	void ConnectPage::initStyle()
	{
		this->setStyleSheet(ConnectPageStyle::style);
	}

}