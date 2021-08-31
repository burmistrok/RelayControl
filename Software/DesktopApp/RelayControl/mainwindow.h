#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    bool isQMessageBoxOpened;

signals:
    void SendCmdToDevice(QString Msg);


public slots:
void ReporError(QString status, QString Msg);
void QMessageBoxCloseEvent(void);
void GetStatus(QString Msg);

private slots:
void on_turnOffAllButton_clicked();
};
#endif // MAINWINDOW_H
