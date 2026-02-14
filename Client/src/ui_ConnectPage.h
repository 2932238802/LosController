/********************************************************************************
** Form generated from reading UI file 'ConnectPage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTPAGE_H
#define UI_CONNECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectPage
{
public:
    QHBoxLayout *mainLayout;
    QFrame *videoSurface;
    QVBoxLayout *videoLayout;
    QLabel *lblStreamPlaceholder;
    QFrame *sidebar;
    QVBoxLayout *sidebarLayout;
    QFrame *infoCard;
    QVBoxLayout *infoLayout;
    QLabel *lblTitleInfo;
    QFormLayout *formInfo;
    QLabel *lblIpKey;
    QLabel *lblIpVal;
    QLabel *lblPortKey;
    QLabel *lblPortVal;
    QLabel *lblDurKey;
    QLabel *lblDurVal;
    QFrame *controlCard;
    QVBoxLayout *controlLayout;
    QLabel *lblTitleControl;
    QVBoxLayout *btnLayout;
    QPushButton *btnCad;
    QPushButton *btnFull;
    QPushButton *btnQuality;
    QSpacerItem *verticalSpacer;
    QPushButton *btnDisconnect;

    void setupUi(QWidget *ConnectPage)
    {
        if (ConnectPage->objectName().isEmpty())
            ConnectPage->setObjectName("ConnectPage");
        ConnectPage->resize(1200, 800);
        mainLayout = new QHBoxLayout(ConnectPage);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(10, 10, 0, 10);
        videoSurface = new QFrame(ConnectPage);
        videoSurface->setObjectName("videoSurface");
        videoLayout = new QVBoxLayout(videoSurface);
        videoLayout->setObjectName("videoLayout");
        lblStreamPlaceholder = new QLabel(videoSurface);
        lblStreamPlaceholder->setObjectName("lblStreamPlaceholder");

        videoLayout->addWidget(lblStreamPlaceholder);


        mainLayout->addWidget(videoSurface);

        sidebar = new QFrame(ConnectPage);
        sidebar->setObjectName("sidebar");
        sidebarLayout = new QVBoxLayout(sidebar);
        sidebarLayout->setSpacing(20);
        sidebarLayout->setObjectName("sidebarLayout");
        sidebarLayout->setContentsMargins(20, 20, 20, -1);
        infoCard = new QFrame(sidebar);
        infoCard->setObjectName("infoCard");
        infoLayout = new QVBoxLayout(infoCard);
        infoLayout->setObjectName("infoLayout");
        lblTitleInfo = new QLabel(infoCard);
        lblTitleInfo->setObjectName("lblTitleInfo");

        infoLayout->addWidget(lblTitleInfo);

        formInfo = new QFormLayout();
        formInfo->setObjectName("formInfo");
        formInfo->setHorizontalSpacing(20);
        formInfo->setVerticalSpacing(10);
        formInfo->setContentsMargins(10, -1, 10, 10);
        lblIpKey = new QLabel(infoCard);
        lblIpKey->setObjectName("lblIpKey");

        formInfo->setWidget(0, QFormLayout::ItemRole::LabelRole, lblIpKey);

        lblIpVal = new QLabel(infoCard);
        lblIpVal->setObjectName("lblIpVal");

        formInfo->setWidget(0, QFormLayout::ItemRole::FieldRole, lblIpVal);

        lblPortKey = new QLabel(infoCard);
        lblPortKey->setObjectName("lblPortKey");

        formInfo->setWidget(1, QFormLayout::ItemRole::LabelRole, lblPortKey);

        lblPortVal = new QLabel(infoCard);
        lblPortVal->setObjectName("lblPortVal");

        formInfo->setWidget(1, QFormLayout::ItemRole::FieldRole, lblPortVal);

        lblDurKey = new QLabel(infoCard);
        lblDurKey->setObjectName("lblDurKey");

        formInfo->setWidget(2, QFormLayout::ItemRole::LabelRole, lblDurKey);

        lblDurVal = new QLabel(infoCard);
        lblDurVal->setObjectName("lblDurVal");

        formInfo->setWidget(2, QFormLayout::ItemRole::FieldRole, lblDurVal);


        infoLayout->addLayout(formInfo);


        sidebarLayout->addWidget(infoCard);

        controlCard = new QFrame(sidebar);
        controlCard->setObjectName("controlCard");
        controlLayout = new QVBoxLayout(controlCard);
        controlLayout->setObjectName("controlLayout");
        lblTitleControl = new QLabel(controlCard);
        lblTitleControl->setObjectName("lblTitleControl");

        controlLayout->addWidget(lblTitleControl);

        btnLayout = new QVBoxLayout();
        btnLayout->setSpacing(8);
        btnLayout->setObjectName("btnLayout");
        btnLayout->setContentsMargins(10, -1, 10, 10);
        btnCad = new QPushButton(controlCard);
        btnCad->setObjectName("btnCad");

        btnLayout->addWidget(btnCad);

        btnFull = new QPushButton(controlCard);
        btnFull->setObjectName("btnFull");

        btnLayout->addWidget(btnFull);

        btnQuality = new QPushButton(controlCard);
        btnQuality->setObjectName("btnQuality");

        btnLayout->addWidget(btnQuality);


        controlLayout->addLayout(btnLayout);


        sidebarLayout->addWidget(controlCard);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(verticalSpacer);

        btnDisconnect = new QPushButton(sidebar);
        btnDisconnect->setObjectName("btnDisconnect");
        btnDisconnect->setMinimumSize(QSize(0, 50));

        sidebarLayout->addWidget(btnDisconnect);


        mainLayout->addWidget(sidebar);


        retranslateUi(ConnectPage);

        QMetaObject::connectSlotsByName(ConnectPage);
    } // setupUi

    void retranslateUi(QWidget *ConnectPage)
    {
        lblStreamPlaceholder->setText(QCoreApplication::translate("ConnectPage", "REMOTE SCREEN STREAM", nullptr));
        infoCard->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "card", nullptr)));
        lblTitleInfo->setText(QCoreApplication::translate("ConnectPage", "CONNECTION INFO", nullptr));
        lblTitleInfo->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "card-title", nullptr)));
        lblIpKey->setText(QCoreApplication::translate("ConnectPage", "IP:", nullptr));
        lblIpKey->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-key", nullptr)));
        lblIpVal->setText(QCoreApplication::translate("ConnectPage", "192.168.1.100", nullptr));
        lblIpVal->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-value", nullptr)));
        lblPortKey->setText(QCoreApplication::translate("ConnectPage", "PORT:", nullptr));
        lblPortKey->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-key", nullptr)));
        lblPortVal->setText(QCoreApplication::translate("ConnectPage", "5900", nullptr));
        lblPortVal->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-value", nullptr)));
        lblDurKey->setText(QCoreApplication::translate("ConnectPage", "DURATION:", nullptr));
        lblDurKey->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-key", nullptr)));
        lblDurVal->setText(QCoreApplication::translate("ConnectPage", "00:12:35", nullptr));
        lblDurVal->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "info-value", nullptr)));
        controlCard->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "card", nullptr)));
        lblTitleControl->setText(QCoreApplication::translate("ConnectPage", "DEVICE CONTROL", nullptr));
        lblTitleControl->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "card-title", nullptr)));
        btnCad->setText(QCoreApplication::translate("ConnectPage", "Ctrl+Alt+Del", nullptr));
        btnCad->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "action-btn", nullptr)));
        btnFull->setText(QCoreApplication::translate("ConnectPage", "Fullscreen", nullptr));
        btnFull->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "action-btn", nullptr)));
        btnQuality->setText(QCoreApplication::translate("ConnectPage", "Quality", nullptr));
        btnQuality->setProperty("class", QVariant(QCoreApplication::translate("ConnectPage", "action-btn", nullptr)));
        btnDisconnect->setText(QCoreApplication::translate("ConnectPage", "DISCONNECT", nullptr));
        (void)ConnectPage;
    } // retranslateUi

};

namespace Ui {
    class ConnectPage: public Ui_ConnectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTPAGE_H
