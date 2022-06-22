#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>

class Client
{
public:
    Client();
    QString registration(QString username, QString password);
    QString auth(QString username, QString password);
    void sendMessage(QString message);

public slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
