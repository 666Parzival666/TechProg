#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33336)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    // поулаем новое соединение
    auto client = mTcpServer->nextPendingConnection();
    qDebug() << "new connection";
    // добавляем в список клиентов
    clients.push_back(client);
    client->write("Hello, World!!! I am echo server!\r\n");
    connect(client, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(client, &QTcpSocket::disconnected, this,&MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead(){
    // если ктото отправил сообщение то отправляем их всем подключенным клиентам
   // for (int j = 0; j < clients.size(); j++) {
        auto client = (QTcpSocket*)sender();
        while(client->bytesAvailable() > 0)
        {
            QByteArray array = client->readAll();
            client->write(array);
            }
        //return;
        //}
    }


void MyTcpServer::slotClientDisconnected(){
    // если ктото отключился, то делаем ему disconnect();
    int index = -1;
    for (int i = 0; i < clients.size(); i++) {
        auto client = clients[i];
        if (client->state() == QAbstractSocket::UnconnectedState) {
            client->disconnect();
            index = i;
            break;
        }
    }
    clients.removeAt(index);
    qDebug() << "client was disconnected";
}
