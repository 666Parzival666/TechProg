#include "tasks.h"
#include "ui_tasks.h"

Tasks::Tasks(MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
}

Tasks::~Tasks()
{
    delete ui;
}

void Tasks::on_task1_clicked()
{
    mainWindow->sendMessage("[Task]1");
}


void Tasks::on_task2_clicked()
{
    mainWindow->sendMessage("[Task]2");
}


void Tasks::on_task3_clicked()
{
    mainWindow->sendMessage("[Task]3");
}


void Tasks::on_task4_clicked()
{
    mainWindow->sendMessage("[Task]4");
}

void Tasks::setSolution(QString solution)
{
    ui->solution->setText(solution);
}

