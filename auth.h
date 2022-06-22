#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~Auth();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Auth *ui;
    MainWindow *mainWindow;
};

#endif // AUTH_H
