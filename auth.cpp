#include "auth.h"
#include "ui_auth.h"

Auth::Auth(MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
}

Auth::~Auth()
{
    delete ui;
}

void Auth::on_pushButton_clicked()
{
    QString username = ui->textEdit->toPlainText();
    QString password = ui->textEdit_2->toPlainText();
    this->mainWindow->sendMessage("[Auth]" + username +";password=" + password);
}


void Auth::on_pushButton_2_clicked()
{
    this->mainWindow->goToRegistration();
}

