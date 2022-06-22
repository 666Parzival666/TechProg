#include "client.h"

Client::Client()
{
    this->socket = new QTcpSocket();
    socket->connectToHost("localhost", 33337);
    QAbstractSocket::connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
}
