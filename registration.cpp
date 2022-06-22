#include "registration.h"
#include "ui_registration.h"

Registration::Registration(MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_2_clicked()
{
    this->mainWindow->goToAuth();
}


void Registration::on_pushButton_clicked()
{
    QString username = ui->textEdit->toPlainText();
    QString password = ui->textEdit_2->toPlainText();
    QString passwordConfirm = ui->textEdit_3->toPlainText();

    if (password != passwordConfirm) {
        mainWindow->changeStatusBar("Пароли не совпадают");
        return;
    }

    mainWindow->changeStatusBar("");
    this->mainWindow->sendMessage("[Registration]" + username +";password=" + password);
}

