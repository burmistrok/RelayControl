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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionSave;
    QAction *actionSupport;
    QAction *actionSource_code;
    QWidget *centralwidget;
    QWidget *layoutWidget;
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
    QHBoxLayout *horizontalLayout_12;
    QPlainTextEdit *ErrPos1_5;
    QComboBox *comboBoxErr1_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *UpdBoxSts;
    QPushButton *SendUpdates;
    QPushButton *OnlyDbgButton;
    QPushButton *setInitStsButton;
    QPushButton *turnOffAllButton;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *BoxDebuger;
    QCheckBox *BoxKL15;
    QCheckBox *BoxKL56;
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
    QMenuBar *menubar;
    QMenu *menuWorkspace;
    QMenu *menuCommunication;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 847);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSupport = new QAction(MainWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        actionSource_code = new QAction(MainWindow);
        actionSource_code->setObjectName(QString::fromUtf8("actionSource_code"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 681, 791));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ErrPos1_1 = new QTextEdit(layoutWidget);
        ErrPos1_1->setObjectName(QString::fromUtf8("ErrPos1_1"));

        horizontalLayout->addWidget(ErrPos1_1);

        comboBoxErr1_1 = new QComboBox(layoutWidget);
        comboBoxErr1_1->setObjectName(QString::fromUtf8("comboBoxErr1_1"));

        horizontalLayout->addWidget(comboBoxErr1_1);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ErrPos1_2 = new QTextEdit(layoutWidget);
        ErrPos1_2->setObjectName(QString::fromUtf8("ErrPos1_2"));

        horizontalLayout_2->addWidget(ErrPos1_2);

        comboBoxErr1_2 = new QComboBox(layoutWidget);
        comboBoxErr1_2->setObjectName(QString::fromUtf8("comboBoxErr1_2"));

        horizontalLayout_2->addWidget(comboBoxErr1_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ErrPos1_3 = new QTextEdit(layoutWidget);
        ErrPos1_3->setObjectName(QString::fromUtf8("ErrPos1_3"));

        horizontalLayout_3->addWidget(ErrPos1_3);

        comboBoxErr1_3 = new QComboBox(layoutWidget);
        comboBoxErr1_3->setObjectName(QString::fromUtf8("comboBoxErr1_3"));

        horizontalLayout_3->addWidget(comboBoxErr1_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ErrPos1_4 = new QTextEdit(layoutWidget);
        ErrPos1_4->setObjectName(QString::fromUtf8("ErrPos1_4"));

        horizontalLayout_4->addWidget(ErrPos1_4);

        comboBoxErr1_4 = new QComboBox(layoutWidget);
        comboBoxErr1_4->setObjectName(QString::fromUtf8("comboBoxErr1_4"));

        horizontalLayout_4->addWidget(comboBoxErr1_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        ErrPos1_5 = new QPlainTextEdit(layoutWidget);
        ErrPos1_5->setObjectName(QString::fromUtf8("ErrPos1_5"));

        horizontalLayout_12->addWidget(ErrPos1_5);

        comboBoxErr1_5 = new QComboBox(layoutWidget);
        comboBoxErr1_5->setObjectName(QString::fromUtf8("comboBoxErr1_5"));

        horizontalLayout_12->addWidget(comboBoxErr1_5);


        verticalLayout_3->addLayout(horizontalLayout_12);


        horizontalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        UpdBoxSts = new QCheckBox(layoutWidget);
        UpdBoxSts->setObjectName(QString::fromUtf8("UpdBoxSts"));

        verticalLayout->addWidget(UpdBoxSts);

        SendUpdates = new QPushButton(layoutWidget);
        SendUpdates->setObjectName(QString::fromUtf8("SendUpdates"));

        verticalLayout->addWidget(SendUpdates);

        OnlyDbgButton = new QPushButton(layoutWidget);
        OnlyDbgButton->setObjectName(QString::fromUtf8("OnlyDbgButton"));

        verticalLayout->addWidget(OnlyDbgButton);

        setInitStsButton = new QPushButton(layoutWidget);
        setInitStsButton->setObjectName(QString::fromUtf8("setInitStsButton"));

        verticalLayout->addWidget(setInitStsButton);

        turnOffAllButton = new QPushButton(layoutWidget);
        turnOffAllButton->setObjectName(QString::fromUtf8("turnOffAllButton"));

        verticalLayout->addWidget(turnOffAllButton);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        BoxDebuger = new QCheckBox(layoutWidget);
        BoxDebuger->setObjectName(QString::fromUtf8("BoxDebuger"));

        horizontalLayout_10->addWidget(BoxDebuger);

        BoxKL15 = new QCheckBox(layoutWidget);
        BoxKL15->setObjectName(QString::fromUtf8("BoxKL15"));

        horizontalLayout_10->addWidget(BoxKL15);

        BoxKL56 = new QCheckBox(layoutWidget);
        BoxKL56->setObjectName(QString::fromUtf8("BoxKL56"));

        horizontalLayout_10->addWidget(BoxKL56);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ErrPos2_1 = new QTextEdit(layoutWidget);
        ErrPos2_1->setObjectName(QString::fromUtf8("ErrPos2_1"));

        horizontalLayout_5->addWidget(ErrPos2_1);

        comboBoxErr2_1 = new QComboBox(layoutWidget);
        comboBoxErr2_1->setObjectName(QString::fromUtf8("comboBoxErr2_1"));

        horizontalLayout_5->addWidget(comboBoxErr2_1);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ErrPos2_2 = new QTextEdit(layoutWidget);
        ErrPos2_2->setObjectName(QString::fromUtf8("ErrPos2_2"));

        horizontalLayout_6->addWidget(ErrPos2_2);

        comboBoxErr2_2 = new QComboBox(layoutWidget);
        comboBoxErr2_2->setObjectName(QString::fromUtf8("comboBoxErr2_2"));

        horizontalLayout_6->addWidget(comboBoxErr2_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ErrPos2_3 = new QTextEdit(layoutWidget);
        ErrPos2_3->setObjectName(QString::fromUtf8("ErrPos2_3"));

        horizontalLayout_7->addWidget(ErrPos2_3);

        comboBoxErr2_3 = new QComboBox(layoutWidget);
        comboBoxErr2_3->setObjectName(QString::fromUtf8("comboBoxErr2_3"));

        horizontalLayout_7->addWidget(comboBoxErr2_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ErrPos2_4 = new QTextEdit(layoutWidget);
        ErrPos2_4->setObjectName(QString::fromUtf8("ErrPos2_4"));

        horizontalLayout_8->addWidget(ErrPos2_4);

        comboBoxErr2_4 = new QComboBox(layoutWidget);
        comboBoxErr2_4->setObjectName(QString::fromUtf8("comboBoxErr2_4"));

        horizontalLayout_8->addWidget(comboBoxErr2_4);


        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 699, 21));
        menuWorkspace = new QMenu(menubar);
        menuWorkspace->setObjectName(QString::fromUtf8("menuWorkspace"));
        menuCommunication = new QMenu(menubar);
        menuCommunication->setObjectName(QString::fromUtf8("menuCommunication"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuWorkspace->menuAction());
        menubar->addAction(menuCommunication->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuWorkspace->addAction(actionSave);
        menuCommunication->addAction(actionConnect);
        menuHelp->addAction(actionSupport);
        menuHelp->addAction(actionSource_code);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSupport->setText(QCoreApplication::translate("MainWindow", "Support", nullptr));
        actionSource_code->setText(QCoreApplication::translate("MainWindow", "Source code", nullptr));
        UpdBoxSts->setText(QCoreApplication::translate("MainWindow", "Send on click/at command", nullptr));
        SendUpdates->setText(QCoreApplication::translate("MainWindow", "Send all updates", nullptr));
        OnlyDbgButton->setText(QCoreApplication::translate("MainWindow", "Only Debuger", nullptr));
        setInitStsButton->setText(QCoreApplication::translate("MainWindow", "Set Initial State", nullptr));
        turnOffAllButton->setText(QCoreApplication::translate("MainWindow", "Turn OFF All", nullptr));
        BoxDebuger->setText(QCoreApplication::translate("MainWindow", "Turn On/Off Debuger", nullptr));
        BoxKL15->setText(QCoreApplication::translate("MainWindow", "Tunr On/Off KL15", nullptr));
        BoxKL56->setText(QCoreApplication::translate("MainWindow", "Turn On/Off KL56", nullptr));
        menuWorkspace->setTitle(QCoreApplication::translate("MainWindow", "Workspace", nullptr));
        menuCommunication->setTitle(QCoreApplication::translate("MainWindow", "Communication", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
