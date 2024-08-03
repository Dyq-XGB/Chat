#include "connecttoserver.h"

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <QTime>


ConnectToServer::ConnectToServer(QHostAddress Serverip, QString clientinfoDir, QString id, int loginkey, unsigned short port, QObject *parent)
    : QObject{parent},id(id),loginkey(loginkey),port(port),clientInfoDir(clientinfoDir),serverip(Serverip)
{

}

ConnectToServer::~ConnectToServer()
{
    qDebug()<<"ConnectToServer::~ConnectToServer()";
}

void ConnectToServer::slot_startwork(bool NeedGetAllInfo)
{
    qDebug()<<"ConnectToServer::slot_startwork(int Loginkey,unsigned short port, bool NeedGetAllInfo)"<<loginkey<<port<<NeedGetAllInfo;
    tcp=new QTcpSocket();
    connect(tcp,&QTcpSocket::disconnected,this,[=](){qDebug()<<QTime::currentTime().toString()<<"与服务器断开连接！";});
    tcp->bind(port);
    tcp->connectToHost(serverip,serverport);
    QByteArray Loginkey;
    Loginkey.setNum(loginkey);
    if(!tcp->waitForConnected(10000))
    {
        qDebug()<<"服务器繁忙！连接超时！";
        emit ConnectFaile();
        return;
    }
    qDebug()<<"连接成功！";
    tcp->write(Loginkey);

    QByteArray NotGetMessage;
    if(!tcp->waitForReadyRead(5000))
    {
        qDebug()<<"服务器繁忙!";
        emit ConnectFaile();
        return;
    }
    qDebug()<<"得到离线时未接收的数据";
    QByteArray byte=tcp->readAll();
    int needgetsize=byte.toInt();
    qDebug()<<"needgetsize:"<<needgetsize;

    QString answer="pleaseSend";
    tcp->write(answer.toUtf8());
    while(tcp->waitForReadyRead(3000))
    {
        NotGetMessage.append(tcp->readAll());
        if(NotGetMessage.size()==needgetsize)
            break;
    }
    qDebug()<<"接收完成离线时未接收的数据";
    if(NeedGetAllInfo)
    {
        QString request="GetAllInfo";
        tcp->write(request.toUtf8());//告诉服务器要获得所有的数据
        tcp->flush();
        if(!tcp->waitForReadyRead(10000))
        {
            qDebug()<<"服务器繁忙！无法获取！";
            emit ConnectFaile();
            return;
        }
        else
        {
            qDebug()<<"开始接收所有信息";
            QByteArray size=tcp->readAll();
            int needgetsize=size.toInt();
            qDebug()<<"所有信息大小："<<needgetsize;
            int havegetsize=0;
            QString answer="pleaseSend";//告诉服务器可以开始发送了
            tcp->write(answer.toUtf8());
            tcp->flush();
            QByteArray Allinfo;
            while(tcp->waitForReadyRead(5000))
            {
                QByteArray bytes=tcp->readAll();
                Allinfo.append(bytes);
                qDebug()<<"读取了所有信息里的："<<Allinfo.size();
                havegetsize+=bytes.size();
                if(havegetsize==needgetsize)
                    break;
            }
            while(tcp->bytesAvailable())
                Allinfo.append(tcp->readAll());

            qDebug()<<"接收完成所有信息";


            QDir infoDir(clientInfoDir);
            infoDir.mkdir(id);
            QString filepath=clientInfoDir+id+"/"+id+".json";

            QFile file(filepath);
            file.open(QFile::WriteOnly);
            file.write(Allinfo);
            file.close();
        }
    }
    emit PasureNotgetMessage(NotGetMessage);
    emit ConnectSuccess();
}

void ConnectToServer::SendAllinfotoServer()
{
    qDebug()<<"ConnectToServer::SendAllinfotoServer()";
    QString filepath=clientInfoDir+id+"/"+id+".json";
    qDebug()<<filepath;
    QFile file(filepath);
    qDebug()<<1;
    file.open(QFile::ReadOnly);
    QByteArray size;
    size.setNum(file.size());

    qDebug()<<tcp->write(size);
    tcp->flush();
    qDebug()<<2;
    qDebug()<<tcp->waitForReadyRead(10000);
    QString answer=QString(tcp->readAll());
    qDebug()<<"answer:"<<answer;
    if(answer=="send")
    {
        int havesend=0;
        while(!file.atEnd())
            qDebug()<<"已发送："<<(havesend+=tcp->write(file.read(sendasize)));
    }
    qDebug()<<3;
    if(tcp->waitForReadyRead(10000))
    {
        QString re=QString(tcp->readAll());
        qDebug()<<re;
    }
    file.close();
    qDebug()<<4;
    tcp->disconnectFromHost();
    tcp->close();
    delete tcp;
    emit sendOk();
}




