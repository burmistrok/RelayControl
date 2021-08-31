#include "mainwindow.h"

#include <QApplication>

#include "commuart.h"
#include "backendapp.h"
#include <QObject>
#include <QThread>
#include "Std_Types.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    BackEndApp backEndAppVar;

    QThread* thread = new QThread;
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    QObject::connect(&backEndAppVar, &BackEndApp::ReportError, &w, &MainWindow::ReporError);
    QObject::connect(&w, &MainWindow::SendCmdToDevice, &backEndAppVar, &BackEndApp::GetCmdToDevice);
    QObject::connect(&backEndAppVar, &BackEndApp::ShowStatus, &w, &MainWindow::GetStatus);

    w.show();

    backEndAppVar.start();

    thread->yieldCurrentThread();
    thread->start();

    return a.exec();
}
