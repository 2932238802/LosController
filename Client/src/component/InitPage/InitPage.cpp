#include "InitPage.h"
#include "ui_InitPage.h"

namespace LosComponent
{

/// <summary>
/// 
/// </summary>
/// <param name="parent"></param>
InitPage::InitPage(QWidget* parent):
	QWidget(parent),
	ui(new Ui::InitPage)
{
	ui->setupUi(this);
	initStyle();
}


/// <summary>
/// 
/// </summary>
InitPage::~InitPage()
{
	delete ui;
}



/// <summary>
/// 
/// </summary>
void InitPage::initConnect()
{
}



/// <summary>
/// 
/// </summary>
void InitPage::initStyle()
{
	this->setStyleSheet(InitPageStyle::style);
}


}

