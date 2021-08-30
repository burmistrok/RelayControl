#include "mainwindow.h"

#include <QApplication>

#include "commuartwraper.h"
#include "backendapp.h"
#include <QObject>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CommUARTWraper commVar;
    BackEndApp backEndAppVar;


    QObject::connect(&commVar, &CommUARTWraper::ReportError, &w, &MainWindow::ReporError);
    QObject::connect(&w, &MainWindow::ReportmsgToCommPort, &commVar, &CommUARTWraper::WriteData);

    QObject::connect(&backEndAppVar, &BackEndApp::CheckDataFromCommPort , &commVar, &CommUARTWraper::DataReceived);
     QObject::connect(&commVar, &CommUARTWraper::readyRead , &commVar, &CommUARTWraper::DataReceived);
    w.show();
    commVar.IsConnected();

    backEndAppVar.start();
    backEndAppVar.yieldCurrentThread();
    return a.exec();
}
