/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/component/InitPage/InitPage.h"
#include "src/component/SettingPage/SettingPage.h"
#include "src/component/TopWidget/TopWidget.h"
#include "src/component/connectPage/connectPage.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    LosComponent::TopWidget *widgetTop;
    QHBoxLayout *horizontalLayoutTop;
    QLabel *lblLogo;
    QHBoxLayout *navLayout;
    QWidget *blankWidget;
    QPushButton *btnNavHome;
    QPushButton *btnNavConnect;
    QPushButton *btnNavSettings;
    QSpacerItem *spacerWindow;
    QWidget *widgetWindowControls;
    QHBoxLayout *windowControlsLayout;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QWidget *widgetBottom;
    QHBoxLayout *horizontalLayoutBottom;
    QStackedWidget *stackedWidget;
    LosComponent::InitPage *initPage;
    LosComponent::ConnectPage *connectPage;
    LosComponent::SettingPage *settingPage;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 675);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTop = new LosComponent::TopWidget(MainWindow);
        widgetTop->setObjectName("widgetTop");
        widgetTop->setMinimumSize(QSize(0, 70));
        widgetTop->setMaximumSize(QSize(16777215, 70));
        horizontalLayoutTop = new QHBoxLayout(widgetTop);
        horizontalLayoutTop->setSpacing(0);
        horizontalLayoutTop->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutTop->setObjectName("horizontalLayoutTop");
        lblLogo = new QLabel(widgetTop);
        lblLogo->setObjectName("lblLogo");

        horizontalLayoutTop->addWidget(lblLogo);

        navLayout = new QHBoxLayout();
        navLayout->setSpacing(5);
        navLayout->setObjectName("navLayout");
        blankWidget = new QWidget(widgetTop);
        blankWidget->setObjectName("blankWidget");
        blankWidget->setMinimumSize(QSize(40, 0));
        blankWidget->setMaximumSize(QSize(40, 16777215));

        navLayout->addWidget(blankWidget);

        btnNavHome = new QPushButton(widgetTop);
        btnNavHome->setObjectName("btnNavHome");
        btnNavHome->setCheckable(true);
        btnNavHome->setChecked(true);
        btnNavHome->setAutoExclusive(true);

        navLayout->addWidget(btnNavHome);

        btnNavConnect = new QPushButton(widgetTop);
        btnNavConnect->setObjectName("btnNavConnect");
        btnNavConnect->setCheckable(true);
        btnNavConnect->setAutoExclusive(true);

        navLayout->addWidget(btnNavConnect);

        btnNavSettings = new QPushButton(widgetTop);
        btnNavSettings->setObjectName("btnNavSettings");
        btnNavSettings->setCheckable(true);
        btnNavSettings->setAutoExclusive(true);

        navLayout->addWidget(btnNavSettings);


        horizontalLayoutTop->addLayout(navLayout);

        spacerWindow = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutTop->addItem(spacerWindow);

        widgetWindowControls = new QWidget(widgetTop);
        widgetWindowControls->setObjectName("widgetWindowControls");
        windowControlsLayout = new QHBoxLayout(widgetWindowControls);
        windowControlsLayout->setSpacing(0);
        windowControlsLayout->setContentsMargins(0, 0, 0, 0);
        windowControlsLayout->setObjectName("windowControlsLayout");
        btnMin = new QPushButton(widgetWindowControls);
        btnMin->setObjectName("btnMin");

        windowControlsLayout->addWidget(btnMin);

        btnClose = new QPushButton(widgetWindowControls);
        btnClose->setObjectName("btnClose");

        windowControlsLayout->addWidget(btnClose);


        horizontalLayoutTop->addWidget(widgetWindowControls);


        verticalLayout->addWidget(widgetTop);

        widgetBottom = new QWidget(MainWindow);
        widgetBottom->setObjectName("widgetBottom");
        horizontalLayoutBottom = new QHBoxLayout(widgetBottom);
        horizontalLayoutBottom->setSpacing(0);
        horizontalLayoutBottom->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutBottom->setObjectName("horizontalLayoutBottom");
        stackedWidget = new QStackedWidget(widgetBottom);
        stackedWidget->setObjectName("stackedWidget");
        initPage = new LosComponent::InitPage();
        initPage->setObjectName("initPage");
        stackedWidget->addWidget(initPage);
        connectPage = new LosComponent::ConnectPage();
        connectPage->setObjectName("connectPage");
        stackedWidget->addWidget(connectPage);
        settingPage = new LosComponent::SettingPage();
        settingPage->setObjectName("settingPage");
        stackedWidget->addWidget(settingPage);

        horizontalLayoutBottom->addWidget(stackedWidget);


        verticalLayout->addWidget(widgetBottom);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        lblLogo->setText(QCoreApplication::translate("MainWindow", "LOS_CONTROLLER", nullptr));
        btnNavHome->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        btnNavHome->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-item", nullptr)));
        btnNavConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btnNavConnect->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-item", nullptr)));
        btnNavSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        btnNavSettings->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-item", nullptr)));
        btnMin->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnClose->setText(QCoreApplication::translate("MainWindow", "\342\234\225", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
