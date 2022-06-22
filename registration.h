#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Registration *ui;
    MainWindow *mainWindow;
};

#endif // REGISTRATION_H
