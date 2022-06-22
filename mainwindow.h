#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sendMessage(QString message);
    void goToRegistration();
    void goToAuth();
    void goToMain();
    void changeStatusBar(QString message);

public slots:
    void onReadyRead();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QWidget *auth;
    QWidget *registration;
    QWidget *tasks;
};
#endif // MAINWINDOW_H
