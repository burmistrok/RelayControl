#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Std_Types.h"
#include "commondata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void closeEvent(QCloseEvent* event);
private:
    typedef struct{
        bool isStateChangedByGUI;
        int actualSts;
        QComboBox* comboBox_ptr;
        QCheckBox* checkBox_ptr;

    }TS_SignalsSts;
    Ui::MainWindow *ui;
    bool isQMessageBoxOpened;
    QStringList simpleComboBoxList;
    QStringList advanceComboBoxList;
    TS_SignalsSts as_SignalsState[CommonData::EndOfSignals];
    void FillUpSimpleComboBoxList();
    void FillUpAdvanceComboBoxList();
    void ActionHandler(int signal, int sts);
    void StatusHandler(int signal, int sts);
    void InitActsSts(void);
    void InitActsStr(void);

signals:
    void SendCmdToDevice(int signal, int msg);
    void AppWillClose(void);
    void SaveData(QStringList msgLst);

public slots:
void ReporError(QString status, QString Msg);
void QMessageBoxCloseEvent(void);
void GetStatus(int signal, int sts);
void SetInitActuatorMsg(QStringList msgLst);

private slots:
void on_turnOffAllButton_clicked();
void on_comboBoxErr1_1_currentIndexChanged(const QString &arg1);
void on_actionConnect_triggered();
void on_actionSave_triggered();

void on_UpdBoxSts_toggled(bool checked);
void on_BoxDebuger_toggled(bool checked);
void on_BoxKL15_toggled(bool checked);
void on_BoxKL56_toggled(bool checked);
void on_setInitStsButton_clicked();
void on_OnlyDbgButton_clicked();
void on_comboBoxErr1_2_currentIndexChanged(const QString &arg1);
void on_comboBoxErr1_3_currentIndexChanged(const QString &arg1);
void on_comboBoxErr1_4_currentIndexChanged(const QString &arg1);
void on_comboBoxErr2_1_currentIndexChanged(const QString &arg1);
void on_comboBoxErr2_2_currentIndexChanged(const QString &arg1);
void on_comboBoxErr2_3_currentIndexChanged(const QString &arg1);
void on_comboBoxErr2_4_currentIndexChanged(const QString &arg1);
void on_SendUpdates_clicked();
void on_comboBoxErr1_5_currentIndexChanged(const QString &arg1);
void on_actionSupport_triggered();
void on_actionSource_code_triggered();
};
#endif // MAINWINDOW_H
