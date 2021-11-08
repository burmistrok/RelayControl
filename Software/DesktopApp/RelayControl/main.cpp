#include "mainwindow.h"

#include <QApplication>

#include "commuart.h"
#include "backendapp.h"
#include <QObject>
#include <QThread>
#include "Std_Types.h"



void ConnectAppToBackEnd(MainWindow& l_MainWindow, BackEndApp& l_BackEndApp);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    BackEndApp backEndAppVar;

    QThread* thread = new QThread;
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    ConnectAppToBackEnd(w, backEndAppVar);

    w.show();
    backEndAppVar.moveToThread(thread);
    backEndAppVar.start();

    thread->yieldCurrentThread();
    thread->start();

    return a.exec();
}

void ConnectAppToBackEnd(MainWindow& l_MainWindow, BackEndApp& l_BackEndApp)
{
    QObject::connect(&l_BackEndApp, &BackEndApp::ReportError, &l_MainWindow, &MainWindow::ReporError);
    QObject::connect(&l_BackEndApp, &BackEndApp::ShowStatus, &l_MainWindow, &MainWindow::GetStatus);
    QObject::connect(&l_BackEndApp, &BackEndApp::InstalInitActuatorMsg, &l_MainWindow, &MainWindow::SetInitActuatorMsg);


    QObject::connect(&l_MainWindow, &MainWindow::SendCmdToDevice, &l_BackEndApp, &BackEndApp::GetCmdToDevice);
    QObject::connect(&l_MainWindow, &MainWindow::AppWillClose, &l_BackEndApp, &BackEndApp::AppWillCloseNotify);
    QObject::connect(&l_MainWindow, &MainWindow::SaveData, &l_BackEndApp, &BackEndApp::SaveMsgFromTextBox);
}
