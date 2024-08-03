#include "myserver.h"

Myserver::Myserver(QObject *parent)
    : QTcpServer{parent}
{

}

void Myserver::incomingConnection(qintptr handle)
{
    emit TheHandle(handle);
}
