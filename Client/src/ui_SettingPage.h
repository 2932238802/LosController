/********************************************************************************
** Form generated from reading UI file 'SettingPage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPAGE_H
#define UI_SETTINGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingPage
{
public:
    QHBoxLayout *mainLayout;
    QListWidget *navBar;
    QVBoxLayout *contentLayout;
    QLabel *lblTitle;
    QHBoxLayout *row1;
    QLabel *lblPort;
    QLineEdit *editPort;
    QHBoxLayout *row2;
    QLabel *lblRetry;
    QComboBox *comboRetry;
    QHBoxLayout *row3;
    QLabel *lblTimeout;
    QLineEdit *editTimeout;
    QHBoxLayout *row4;
    QLabel *lblHistory;
    QCheckBox *checkHistory;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingPage)
    {
        if (SettingPage->objectName().isEmpty())
            SettingPage->setObjectName("SettingPage");
        SettingPage->resize(1000, 600);
        mainLayout = new QHBoxLayout(SettingPage);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        navBar = new QListWidget(SettingPage);
        new QListWidgetItem(navBar);
        new QListWidgetItem(navBar);
        new QListWidgetItem(navBar);
        new QListWidgetItem(navBar);
        navBar->setObjectName("navBar");

        mainLayout->addWidget(navBar);

        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(20);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(50, 40, 50, -1);
        lblTitle = new QLabel(SettingPage);
        lblTitle->setObjectName("lblTitle");

        contentLayout->addWidget(lblTitle);

        row1 = new QHBoxLayout();
        row1->setObjectName("row1");
        lblPort = new QLabel(SettingPage);
        lblPort->setObjectName("lblPort");

        row1->addWidget(lblPort);

        editPort = new QLineEdit(SettingPage);
        editPort->setObjectName("editPort");

        row1->addWidget(editPort);


        contentLayout->addLayout(row1);

        row2 = new QHBoxLayout();
        row2->setObjectName("row2");
        lblRetry = new QLabel(SettingPage);
        lblRetry->setObjectName("lblRetry");

        row2->addWidget(lblRetry);

        comboRetry = new QComboBox(SettingPage);
        comboRetry->addItem(QString());
        comboRetry->addItem(QString());
        comboRetry->addItem(QString());
        comboRetry->setObjectName("comboRetry");

        row2->addWidget(comboRetry);


        contentLayout->addLayout(row2);

        row3 = new QHBoxLayout();
        row3->setObjectName("row3");
        lblTimeout = new QLabel(SettingPage);
        lblTimeout->setObjectName("lblTimeout");

        row3->addWidget(lblTimeout);

        editTimeout = new QLineEdit(SettingPage);
        editTimeout->setObjectName("editTimeout");

        row3->addWidget(editTimeout);


        contentLayout->addLayout(row3);

        row4 = new QHBoxLayout();
        row4->setObjectName("row4");
        lblHistory = new QLabel(SettingPage);
        lblHistory->setObjectName("lblHistory");

        row4->addWidget(lblHistory);

        checkHistory = new QCheckBox(SettingPage);
        checkHistory->setObjectName("checkHistory");
        checkHistory->setChecked(true);

        row4->addWidget(checkHistory);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        row4->addItem(horizontalSpacer);


        contentLayout->addLayout(row4);

        btnSave = new QPushButton(SettingPage);
        btnSave->setObjectName("btnSave");

        contentLayout->addWidget(btnSave);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        contentLayout->addItem(verticalSpacer);


        mainLayout->addLayout(contentLayout);

        mainLayout->setStretch(0, 1);
        mainLayout->setStretch(1, 4);

        retranslateUi(SettingPage);

        QMetaObject::connectSlotsByName(SettingPage);
    } // setupUi

    void retranslateUi(QWidget *SettingPage)
    {

        const bool __sortingEnabled = navBar->isSortingEnabled();
        navBar->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = navBar->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("SettingPage", "Basic", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = navBar->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("SettingPage", "Display", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = navBar->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("SettingPage", "Hotkeys", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = navBar->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("SettingPage", "Security", nullptr));
        navBar->setSortingEnabled(__sortingEnabled);

        lblTitle->setText(QCoreApplication::translate("SettingPage", "Basic Settings", nullptr));
        lblPort->setText(QCoreApplication::translate("SettingPage", "Local Port", nullptr));
        lblPort->setProperty("class", QVariant(QCoreApplication::translate("SettingPage", "field-label", nullptr)));
        editPort->setText(QCoreApplication::translate("SettingPage", "5900", nullptr));
        lblRetry->setText(QCoreApplication::translate("SettingPage", "Reconnect Times", nullptr));
        lblRetry->setProperty("class", QVariant(QCoreApplication::translate("SettingPage", "field-label", nullptr)));
        comboRetry->setItemText(0, QCoreApplication::translate("SettingPage", "3 Times", nullptr));
        comboRetry->setItemText(1, QCoreApplication::translate("SettingPage", "5 Times", nullptr));
        comboRetry->setItemText(2, QCoreApplication::translate("SettingPage", "Unlimited", nullptr));

        lblTimeout->setText(QCoreApplication::translate("SettingPage", "Timeout (s)", nullptr));
        lblTimeout->setProperty("class", QVariant(QCoreApplication::translate("SettingPage", "field-label", nullptr)));
        editTimeout->setText(QCoreApplication::translate("SettingPage", "10", nullptr));
        lblHistory->setText(QCoreApplication::translate("SettingPage", "Save History", nullptr));
        lblHistory->setProperty("class", QVariant(QCoreApplication::translate("SettingPage", "field-label", nullptr)));
        btnSave->setText(QCoreApplication::translate("SettingPage", "Save Config", nullptr));
        (void)SettingPage;
    } // retranslateUi

};

namespace Ui {
    class SettingPage: public Ui_SettingPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPAGE_H
