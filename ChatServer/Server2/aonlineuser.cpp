#include "aonlineuser.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTime>
#include <QTime>

aOnlineUser::aOnlineUser(QString alluserinfoDir, QString id, QHostAddress ip, unsigned short port,
                         QTcpSocket*socket, QObject *parent)
    : QObject{parent},Id(id),ip(ip),port(port),socket(socket)
{
    saveDir=alluserinfoDir;
    savepath=saveDir+Id+"/"+Id+".json";
    LoginTime=QTime::currentTime().toString();
    connect(socket,&QTcpSocket::disconnected,this,&aOnlineUser::DisConnect);
    connect(socket,&QTcpSocket::readyRead,this,&aOnlineUser::GetUserNeedSaveInfo);
    qDebug()<<"aOnlineUser:"<<LoginTime<<id<<ip<<port;
}

aOnlineUser::~aOnlineUser()
{
    qDebug()<<"~aOnlineUser()"<<Id<<ip<<port;
    socket->close();
    delete socket;
}

QString aOnlineUser::getId() const
{
    return Id;
}

QPair<QHostAddress, unsigned short> aOnlineUser::getIpAndPort() const
{
    return QPair<QHostAddress, unsigned short>(ip,port);
}



void aOnlineUser::DisConnect()
{
    QString time=QTime::currentTime().toString();
    emit UserDisConnect(Id,ip,port,time);
}

void aOnlineUser::GetUserNeedSaveInfo()//当用户离线时要保存数据
{
    qDebug()<<"aOnlineUser::GetUserNeedSaveInfo()";
    QString answer="send";
    double size=socket->readAll().toDouble();//得到用户数据大小
    qDebug()<<"size:"<<size;


    socket->write(answer.toUtf8());//发送回复要用户开始发送
    socket->flush();
    int currentsize=0;
    QByteArray bytes;
    while(socket->waitForReadyRead(10000))
    {
        bytes.append(socket->readAll());
        currentsize=bytes.size();
        qDebug()<<"已经获得数据："<<currentsize;
        if(currentsize==size)
            break;
    }

    if(socket->bytesAvailable())
    {
        bytes.append(socket->readAll());
        qDebug()<<"已经获得数据："<<bytes.size();
    }

    QString getok="getok";
    QString getfaile="getfaile";

    if(bytes.size()==size)
    {
        qDebug()<<"接收成功";
        socket->write(getok.toUtf8());
        QFile file(saveDir+Id+"/"+Id+".json");
        file.open(QFile::WriteOnly);
        file.write(bytes);
    }
    else
    {
        qDebug()<<"接受失败";
        socket->write(getfaile.toUtf8());
    }
}
