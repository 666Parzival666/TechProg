#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "formtask.h"
#include <QMainWindow>
#include <QMessageBox>
#include "authreg.h"
#include "..\client\singletonclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void set_log(QString log);
    void on_Exit_clicked();
    void on_actionExit_triggered();

    void on_Task1_clicked();

    void on_actionTask_1_triggered();

    void on_Stat_clicked();

    void on_Task2_clicked();

    void on_Task3_clicked();

    void on_Task4_clicked();

    void on_actionTask_2_triggered();

    void on_actionTask_3_triggered();

    void on_actionTask_4_triggered();

private:
    Ui::MainWindow *ui;
    FormTask *ui_task;
    authreg *ui_auth;
};
#endif // MAINWINDOW_H
