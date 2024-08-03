#include "dealuserconnect.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QThread>
#include <QTime>


DealUserConnect::DealUserConnect(QObject *parent)
    :QObject{parent}
{

}

DealUserConnect::~DealUserConnect()
{
    qDebug()<<"~DealUserConnect()";
    server->close();
    delete server;
}

void DealUserConnect::startwork(QHostAddress ip)
{
    qDebug()<<ip;
    server=new Myserver();
    server->listen(ip,Port);
    if(server->isListening())
    {
        qDebug()<<"isListening()";
        emit saveThisinfo("DealUserConnect::startwork()  Listening");
    }
    else
        emit saveThisinfo("DealUserConnect::startwork()  NotListening");
    connect(server,&Myserver::TheHandle,this,&DealUserConnect::aUserConnect);


    qDebug()<<"DealUserConnect::startwork()"<<QThread::currentThreadId();
}

void DealUserConnect::aUserConnect(qintptr handle)
{
    qDebug()<<"DealUserConnect::aUserConnect(qintptr handle)"<<handle;
    emit TheConnectHandle(handle);
    emit saveThisinfo("DealUserConnect::aUserConnect  aclient Try To connect"+QString::number(handle));
}


