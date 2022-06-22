#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <task.h>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33337)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
        this->db = QSqlDatabase::addDatabase("QSQLITE");
        this->db.setDatabaseName("database.db");
        bool ok = db.open();
        if (ok) {
            qDebug() << "Database is working";
        } else {
            qDebug() << "Database isn't working";
        }
    }
}

void MyTcpServer::slotNewConnection(){
    // получаем новое соединение
    auto socket = mTcpServer->nextPendingConnection();
    qDebug() << "new connection";
    // добавляем в список клиентов
    Client* client = new Client(socket);
    clients.push_back(client);
    client->sendMessage("Hello, World!!! I am echo server!");
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this,&MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead(){
    auto socket = (QTcpSocket*)sender();

    Client* client = nullptr;
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i]->getSocket() == socket) {
            client = clients[i];
            break;
        }
    }

    while(socket->bytesAvailable() > 0)
    {
        QByteArray array = socket->readAll();
        QString message = QString(array);
        if (!client->checkAuth()) {
            if (message.startsWith("[Auth]")) {
                message = message.mid(6);
                int indexPassword = message.indexOf(";password=");
                QString username = message.mid(0, indexPassword);
                QString password = message.mid(indexPassword + 10);
                qDebug() << "Username: " << username;
                qDebug() << "Password: " << password;

                QSqlQuery query("SELECT id FROM users WHERE username = '" + username + "' AND password = '" + password + "'");
                if (query.next()) {
                    client->sendMessage("[AuthSuccessful]");
                    client->setAuth();
                } else {
                    client->sendMessage("[Failed]Неверный логин или пароль");
                }

                return;
            }

            if (message.startsWith("[Registration]")) {
                message = message.mid(14);
                int indexPassword = message.indexOf(";password=");
                QString username = message.mid(0, indexPassword);
                QString password = message.mid(indexPassword + 10);

                QSqlQuery query("SELECT id FROM users WHERE username = '" + username + "'");
                if (query.next()) {
                    client->sendMessage("[Failed]Логин уже занят. Попробуйте другой.");
                    return;
                }

                db.exec("INSERT INTO users (username, password) VALUES ('" + username +"', '" + password + "')");
                client->sendMessage("[RegistrationSuccessful]");

                return;
            }

            client->sendMessage("[Failed]Вы должны авторизоваться");
            return;
        }

        if (message.startsWith("[Task]")) {
            message = message.mid(6);
            Task task(message);
            client->sendMessage("[Task]" + task.resolve());
        }
    }
}


void MyTcpServer::slotClientDisconnected(){
    // если ктото отключился, то делаем ему disconnect();
    int index = -1;
    for (int i = 0; i < clients.size(); i++) {
        Client* client = clients[i];
        if (client->getSocket()->state() == QAbstractSocket::UnconnectedState) {
            client->getSocket()->disconnect();
            index = i;
            break;
        }
    }
    clients.removeAt(index);
    qDebug() << "client was disconnected";
}
