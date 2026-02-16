#include "ConnectPage.h"
#include "NetManage.h"
#include "ui_ConnectPage.h"
#include <qpushbutton.h>


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
		initConnect();
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
		connect(&LosNet::NetManage::instance(),
			&LosNet::NetManage::_imageFromLinux,
			this,
			&ConnectPage::onImageReceived	
		);

	}


	/**
	26_2_16
	- 接受到 图片数据
	*/
	void ConnectPage::onImageReceived(const QPixmap &pixmap){
		ui->lblStreamPlaceholder->setPixmap(pixmap.scaled(ui->lblStreamPlaceholder->size(), 
                             Qt::KeepAspectRatio, 
                             Qt::SmoothTransformation));
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