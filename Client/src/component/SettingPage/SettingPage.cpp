#include "SettingPage.h"
#include "ui_SettingPage.h"


namespace LosComponent
{
	SettingPage::SettingPage(QWidget* parent):
		QWidget(parent),
		ui(new Ui::SettingPage)
	{
		ui->setupUi(this);
	}

	SettingPage::~SettingPage()
	{
		delete ui;
	}

	void SettingPage::initConnect()
	{
	}

	void SettingPage::initStyle()
	{
		this->setStyleSheet(SettingsPageStyle::style);
	}

}
