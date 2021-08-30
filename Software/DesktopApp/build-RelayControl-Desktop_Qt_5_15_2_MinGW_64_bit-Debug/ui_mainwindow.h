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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *CommConnect;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *UpdBoxSts;
    QPushButton *SendUpdates;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *BoxDebuger;
    QCheckBox *BoxKL15;
    QCheckBox *BoxKL56;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTextEdit *ErrPos1_1;
    QComboBox *comboBoxErr1_1;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *ErrPos1_2;
    QComboBox *comboBoxErr1_2;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *ErrPos1_3;
    QComboBox *comboBoxErr1_3;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *ErrPos1_4;
    QComboBox *comboBoxErr1_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *ErrPos2_1;
    QComboBox *comboBoxErr2_1;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *ErrPos2_2;
    QComboBox *comboBoxErr2_2;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *ErrPos2_3;
    QComboBox *comboBoxErr2_3;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *ErrPos2_4;
    QComboBox *comboBoxErr2_4;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QPushButton *setInitStsButton;
    QPushButton *OnlyDbgButton;
    QPushButton *turnOffAllButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 972);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CommConnect = new QPushButton(centralwidget);
        CommConnect->setObjectName(QString::fromUtf8("CommConnect"));
        CommConnect->setGeometry(QRect(0, 0, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(620, 10, 148, 48));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UpdBoxSts = new QCheckBox(layoutWidget);
        UpdBoxSts->setObjectName(QString::fromUtf8("UpdBoxSts"));

        verticalLayout->addWidget(UpdBoxSts);

        SendUpdates = new QPushButton(layoutWidget);
        SendUpdates->setObjectName(QString::fromUtf8("SendUpdates"));

        verticalLayout->addWidget(SendUpdates);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 128, 65));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BoxDebuger = new QCheckBox(layoutWidget1);
        BoxDebuger->setObjectName(QString::fromUtf8("BoxDebuger"));

        verticalLayout_2->addWidget(BoxDebuger);

        BoxKL15 = new QCheckBox(layoutWidget1);
        BoxKL15->setObjectName(QString::fromUtf8("BoxKL15"));

        verticalLayout_2->addWidget(BoxKL15);

        BoxKL56 = new QCheckBox(layoutWidget1);
        BoxKL56->setObjectName(QString::fromUtf8("BoxKL56"));

        verticalLayout_2->addWidget(BoxKL56);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 120, 678, 798));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ErrPos1_1 = new QTextEdit(widget);
        ErrPos1_1->setObjectName(QString::fromUtf8("ErrPos1_1"));

        horizontalLayout->addWidget(ErrPos1_1);

        comboBoxErr1_1 = new QComboBox(widget);
        comboBoxErr1_1->setObjectName(QString::fromUtf8("comboBoxErr1_1"));

        horizontalLayout->addWidget(comboBoxErr1_1);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ErrPos1_2 = new QTextEdit(widget);
        ErrPos1_2->setObjectName(QString::fromUtf8("ErrPos1_2"));

        horizontalLayout_2->addWidget(ErrPos1_2);

        comboBoxErr1_2 = new QComboBox(widget);
        comboBoxErr1_2->setObjectName(QString::fromUtf8("comboBoxErr1_2"));

        horizontalLayout_2->addWidget(comboBoxErr1_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ErrPos1_3 = new QTextEdit(widget);
        ErrPos1_3->setObjectName(QString::fromUtf8("ErrPos1_3"));

        horizontalLayout_3->addWidget(ErrPos1_3);

        comboBoxErr1_3 = new QComboBox(widget);
        comboBoxErr1_3->setObjectName(QString::fromUtf8("comboBoxErr1_3"));

        horizontalLayout_3->addWidget(comboBoxErr1_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ErrPos1_4 = new QTextEdit(widget);
        ErrPos1_4->setObjectName(QString::fromUtf8("ErrPos1_4"));

        horizontalLayout_4->addWidget(ErrPos1_4);

        comboBoxErr1_4 = new QComboBox(widget);
        comboBoxErr1_4->setObjectName(QString::fromUtf8("comboBoxErr1_4"));

        horizontalLayout_4->addWidget(comboBoxErr1_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ErrPos2_1 = new QTextEdit(widget);
        ErrPos2_1->setObjectName(QString::fromUtf8("ErrPos2_1"));

        horizontalLayout_5->addWidget(ErrPos2_1);

        comboBoxErr2_1 = new QComboBox(widget);
        comboBoxErr2_1->setObjectName(QString::fromUtf8("comboBoxErr2_1"));

        horizontalLayout_5->addWidget(comboBoxErr2_1);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ErrPos2_2 = new QTextEdit(widget);
        ErrPos2_2->setObjectName(QString::fromUtf8("ErrPos2_2"));

        horizontalLayout_6->addWidget(ErrPos2_2);

        comboBoxErr2_2 = new QComboBox(widget);
        comboBoxErr2_2->setObjectName(QString::fromUtf8("comboBoxErr2_2"));

        horizontalLayout_6->addWidget(comboBoxErr2_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ErrPos2_3 = new QTextEdit(widget);
        ErrPos2_3->setObjectName(QString::fromUtf8("ErrPos2_3"));

        horizontalLayout_7->addWidget(ErrPos2_3);

        comboBoxErr2_3 = new QComboBox(widget);
        comboBoxErr2_3->setObjectName(QString::fromUtf8("comboBoxErr2_3"));

        horizontalLayout_7->addWidget(comboBoxErr2_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ErrPos2_4 = new QTextEdit(widget);
        ErrPos2_4->setObjectName(QString::fromUtf8("ErrPos2_4"));

        horizontalLayout_8->addWidget(ErrPos2_4);

        comboBoxErr2_4 = new QComboBox(widget);
        comboBoxErr2_4->setObjectName(QString::fromUtf8("comboBoxErr2_4"));

        horizontalLayout_8->addWidget(comboBoxErr2_4);


        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(200, 0, 341, 81));
        horizontalLayout_10 = new QHBoxLayout(widget1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        setInitStsButton = new QPushButton(widget1);
        setInitStsButton->setObjectName(QString::fromUtf8("setInitStsButton"));

        verticalLayout_5->addWidget(setInitStsButton);

        OnlyDbgButton = new QPushButton(widget1);
        OnlyDbgButton->setObjectName(QString::fromUtf8("OnlyDbgButton"));

        verticalLayout_5->addWidget(OnlyDbgButton);


        horizontalLayout_10->addLayout(verticalLayout_5);

        turnOffAllButton = new QPushButton(widget1);
        turnOffAllButton->setObjectName(QString::fromUtf8("turnOffAllButton"));

        horizontalLayout_10->addWidget(turnOffAllButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 791, 21));
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
        UpdBoxSts->setText(QCoreApplication::translate("MainWindow", "Send on click/at command", nullptr));
        SendUpdates->setText(QCoreApplication::translate("MainWindow", "Send all updates", nullptr));
        BoxDebuger->setText(QCoreApplication::translate("MainWindow", "Turn On/Off Debuger", nullptr));
        BoxKL15->setText(QCoreApplication::translate("MainWindow", "Tunr On/Off KL15", nullptr));
        BoxKL56->setText(QCoreApplication::translate("MainWindow", "Turn On/Off KL56", nullptr));
        setInitStsButton->setText(QCoreApplication::translate("MainWindow", "Set Initial State", nullptr));
        OnlyDbgButton->setText(QCoreApplication::translate("MainWindow", "Only Debuger", nullptr));
        turnOffAllButton->setText(QCoreApplication::translate("MainWindow", "Turn OFF All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
