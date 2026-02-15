#include "InitPage.h"
#include "NetManage.h"
#include "ui_InitPage.h"

namespace LosComponent {

/// <summary>
///
/// </summary>
/// <param name="parent"></param>
InitPage::InitPage(QWidget *parent) : QWidget(parent), ui(new Ui::InitPage) {
  ui->setupUi(this);
  initStyle();
  initConnect();
}

/// <summary>
///
/// </summary>
InitPage::~InitPage() { delete ui; }

/// <summary>
///
/// </summary>
void InitPage::initConnect() {
  connect(ui->btnConnect, &QPushButton::clicked, this,
          &InitPage::onConnectBtnClicked);
  connect(&LosNet::NetManage::instance(), &LosNet::NetManage::_connected, this,
          &InitPage::onConnected);
}

/**
26_2_10
- 连接 按钮的点击
*/
void InitPage::onConnectBtnClicked() {

  QString ip = ui->lineEdit_IP->text();
  QString port = ui->lineEdit_Port->text();
  ushort portToUShort = port.toUShort();

  if (ip.isEmpty() || portToUShort == 0) {
    LOGE("ip is emptr or port is not set");
    ui->lblStatus->setText("[STATUS] wrong in port and ip");
    return;
  }

  ui->lblStatus->setText("[STATUS] connecting ...");
  LosNet::NetManage::instance().conn(ip, portToUShort);
}

/**
26_2_15
- 建立的连接的时候 应该进行界面跳转
*/
void InitPage::onConnected(bool is_connect) {
  if (is_connect) {
    emit _connected_InitPage(is_connect);
  }
  else{
    ui->lblStatus->setText("[STATUS] connected failed");
    ui->lblStatus->setStyleSheet("color:red;"); 
  }
}

/**
26_2_10
- 初始化 样式
*/
void InitPage::initStyle() { this->setStyleSheet(InitPageStyle::style); }

} // namespace LosComponent
