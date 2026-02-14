/********************************************************************************
** Form generated from reading UI file 'InitPage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITPAGE_H
#define UI_INITPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitPage
{
public:
    QVBoxLayout *verticalLayout_Main;
    QSpacerItem *verticalSpacer_Top;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_Left;
    QVBoxLayout *verticalLayout_Content;
    QFrame *loginCard;
    QVBoxLayout *verticalLayout_Card;
    QLabel *label_IP;
    QLineEdit *lineEdit_IP;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QLabel *label_Auth;
    QLineEdit *lineEdit_Password;
    QPushButton *btnConnect;
    QHBoxLayout *horizontalLayout_Status;
    QSpacerItem *horizontalSpacer_StatusLeft;
    QLabel *lblStatus;
    QSpacerItem *horizontalSpacer_StatusRight;
    QSpacerItem *horizontalSpacer_Right;
    QSpacerItem *verticalSpacer_Bottom;

    void setupUi(QWidget *InitPage)
    {
        if (InitPage->objectName().isEmpty())
            InitPage->setObjectName("InitPage");
        InitPage->resize(1000, 700);
        verticalLayout_Main = new QVBoxLayout(InitPage);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 40);
        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Main->addItem(verticalSpacer_Top);

        horizontalLayout_Center = new QHBoxLayout();
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_Left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_Left);

        verticalLayout_Content = new QVBoxLayout();
        verticalLayout_Content->setSpacing(30);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        loginCard = new QFrame(InitPage);
        loginCard->setObjectName("loginCard");
        loginCard->setMinimumSize(QSize(400, 0));
        loginCard->setFrameShape(QFrame::Shape::StyledPanel);
        loginCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_Card = new QVBoxLayout(loginCard);
        verticalLayout_Card->setSpacing(10);
        verticalLayout_Card->setObjectName("verticalLayout_Card");
        verticalLayout_Card->setContentsMargins(40, 40, 40, 40);
        label_IP = new QLabel(loginCard);
        label_IP->setObjectName("label_IP");

        verticalLayout_Card->addWidget(label_IP);

        lineEdit_IP = new QLineEdit(loginCard);
        lineEdit_IP->setObjectName("lineEdit_IP");

        verticalLayout_Card->addWidget(lineEdit_IP);

        label_Port = new QLabel(loginCard);
        label_Port->setObjectName("label_Port");

        verticalLayout_Card->addWidget(label_Port);

        lineEdit_Port = new QLineEdit(loginCard);
        lineEdit_Port->setObjectName("lineEdit_Port");

        verticalLayout_Card->addWidget(lineEdit_Port);

        label_Auth = new QLabel(loginCard);
        label_Auth->setObjectName("label_Auth");

        verticalLayout_Card->addWidget(label_Auth);

        lineEdit_Password = new QLineEdit(loginCard);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_Card->addWidget(lineEdit_Password);

        btnConnect = new QPushButton(loginCard);
        btnConnect->setObjectName("btnConnect");
        btnConnect->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Card->addWidget(btnConnect);


        verticalLayout_Content->addWidget(loginCard);

        horizontalLayout_Status = new QHBoxLayout();
        horizontalLayout_Status->setObjectName("horizontalLayout_Status");
        horizontalSpacer_StatusLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Status->addItem(horizontalSpacer_StatusLeft);

        lblStatus = new QLabel(InitPage);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_Status->addWidget(lblStatus);

        horizontalSpacer_StatusRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Status->addItem(horizontalSpacer_StatusRight);


        verticalLayout_Content->addLayout(horizontalLayout_Status);


        horizontalLayout_Center->addLayout(verticalLayout_Content);

        horizontalSpacer_Right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_Right);


        verticalLayout_Main->addLayout(horizontalLayout_Center);

        verticalSpacer_Bottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Main->addItem(verticalSpacer_Bottom);


        retranslateUi(InitPage);

        QMetaObject::connectSlotsByName(InitPage);
    } // setupUi

    void retranslateUi(QWidget *InitPage)
    {
        InitPage->setWindowTitle(QCoreApplication::translate("InitPage", "Remote Control Client", nullptr));
        label_IP->setText(QCoreApplication::translate("InitPage", "Remote IP Address", nullptr));
        label_IP->setProperty("class", QVariant(QCoreApplication::translate("InitPage", "input-label", nullptr)));
        lineEdit_IP->setText(QCoreApplication::translate("InitPage", "192.168.1.100", nullptr));
        lineEdit_IP->setPlaceholderText(QCoreApplication::translate("InitPage", "Enter IP...", nullptr));
        label_Port->setText(QCoreApplication::translate("InitPage", "Port", nullptr));
        label_Port->setProperty("class", QVariant(QCoreApplication::translate("InitPage", "input-label", nullptr)));
        lineEdit_Port->setText(QCoreApplication::translate("InitPage", "5900", nullptr));
        lineEdit_Port->setPlaceholderText(QCoreApplication::translate("InitPage", "Enter Port...", nullptr));
        label_Auth->setText(QCoreApplication::translate("InitPage", "Auth Password (Optional)", nullptr));
        label_Auth->setProperty("class", QVariant(QCoreApplication::translate("InitPage", "input-label", nullptr)));
        lineEdit_Password->setText(QCoreApplication::translate("InitPage", "********", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("InitPage", "Password...", nullptr));
        btnConnect->setText(QCoreApplication::translate("InitPage", "Connect", nullptr));
        lblStatus->setText(QCoreApplication::translate("InitPage", "[STATUS] No remote device connected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitPage: public Ui_InitPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITPAGE_H
