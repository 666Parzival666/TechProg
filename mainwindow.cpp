#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <auth.h>
#include <registration.h>
#include <tasks.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auth = new Auth(this, this);
    auth->close();
    registration = new Registration(this, this);
    registration->close();
    tasks = new Tasks(this, this);
    tasks->close();

    goToAuth();
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost", 33337);
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReadyRead()
{
    QByteArray datas = socket->readAll();
    QString message = QString(datas);
    if (message == "[AuthSuccessful]") {
        changeStatusBar("");
        goToMain();
        return;
    }

    if (message == "[RegistrationSuccessful]") {
        changeStatusBar("Вы были успешно зарегестрированы. Пожалуйста авторизуйтесь");
        goToAuth();
        return;
    }

    if (message.startsWith("[Task]")) {
        message = message.mid(6);
        ((Tasks*)tasks)->setSolution(message);
        return;
    }

    if (message.startsWith("[Failed]")) {
        changeStatusBar(message.mid(8));
        return;
    }
}

void MainWindow::sendMessage(QString message)
{
    QByteArray array = message.toLocal8Bit();
    char* buffer = array.data();
    this->socket->write(buffer);
}

void MainWindow::goToAuth()
{
    registration->close();
    auth->show();
}

void MainWindow::goToRegistration()
{
    auth->close();
    registration->show();
}

void MainWindow::goToMain()
{
    auth->close();
    registration->close();
    tasks->show();
}

void MainWindow::changeStatusBar(QString message)
{
    this->ui->logs->setText(message);
}

