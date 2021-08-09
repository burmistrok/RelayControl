/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *CommConnect;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBoxErr1_1;
    QComboBox *comboBoxErr2_1;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *UpdBoxSts;
    QPushButton *SendUpdates;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *BoxDebuger;
    QCheckBox *BoxKL15;
    QCheckBox *BoxKL56;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CommConnect = new QPushButton(centralwidget);
        CommConnect->setObjectName(QString::fromUtf8("CommConnect"));
        CommConnect->setGeometry(QRect(0, 0, 75, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 0, 111, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 0, 75, 23));
        comboBoxErr1_1 = new QComboBox(centralwidget);
        comboBoxErr1_1->setObjectName(QString::fromUtf8("comboBoxErr1_1"));
        comboBoxErr1_1->setGeometry(QRect(190, 180, 69, 22));
        comboBoxErr2_1 = new QComboBox(centralwidget);
        comboBoxErr2_1->setObjectName(QString::fromUtf8("comboBoxErr2_1"));
        comboBoxErr2_1->setGeometry(QRect(700, 180, 69, 22));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(620, 10, 148, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UpdBoxSts = new QCheckBox(widget);
        UpdBoxSts->setObjectName(QString::fromUtf8("UpdBoxSts"));

        verticalLayout->addWidget(UpdBoxSts);

        SendUpdates = new QPushButton(widget);
        SendUpdates->setObjectName(QString::fromUtf8("SendUpdates"));

        verticalLayout->addWidget(SendUpdates);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 30, 128, 65));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BoxDebuger = new QCheckBox(widget1);
        BoxDebuger->setObjectName(QString::fromUtf8("BoxDebuger"));

        verticalLayout_2->addWidget(BoxDebuger);

        BoxKL15 = new QCheckBox(widget1);
        BoxKL15->setObjectName(QString::fromUtf8("BoxKL15"));

        verticalLayout_2->addWidget(BoxKL15);

        BoxKL56 = new QCheckBox(widget1);
        BoxKL56->setObjectName(QString::fromUtf8("BoxKL56"));

        verticalLayout_2->addWidget(BoxKL56);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CommConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Set Initial State", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Turn OFF All", nullptr));
        UpdBoxSts->setText(QCoreApplication::translate("MainWindow", "Send on click/at command", nullptr));
        SendUpdates->setText(QCoreApplication::translate("MainWindow", "Send all updates", nullptr));
        BoxDebuger->setText(QCoreApplication::translate("MainWindow", "Turn On/Off Debuger", nullptr));
        BoxKL15->setText(QCoreApplication::translate("MainWindow", "Tunr On/Off KL15", nullptr));
        BoxKL56->setText(QCoreApplication::translate("MainWindow", "Turn On/Off KL56", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
