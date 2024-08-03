#include "dealfile.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QThread>

DealFile::DealFile(QHostAddress serverip,QObject *parent)
    : QObject{parent},serverip(serverip)
{

}
DealFile::~DealFile()
{
    t_pool->clear();
    delete t_pool;
    qDebug()<<"DealFile::~DealFile()";
}
void DealFile:: startwork()
{
    qDebug()<<"DealFile:: startwork()";
    t_pool=new QThreadPool();
}

void DealFile::GetaFile(QString savefilepath,QString key,aMessagewidget*widget)
{
    qDebug()<<"DealFile::GetaFile(QString savefilepath,QString key,aMessagewidget*widget)";
    aget*a=new aget(serverip,savefilepath,key,widget);
    t_pool->start(a);
}

void DealFile::SendaFile(QString filepath,aMessagewidget*widget)
{
    qDebug()<<"DealFile::SendaFile(QString filepath,aMessagewidget*widget)";
    asend*a=new asend(serverip,filepath,widget);
    t_pool->start(a);
}




asend::asend(QHostAddress serverip, QString filepath, aMessagewidget *widget, QObject *parent)
    :QObject(parent),filepath(filepath),widget(widget),serverip(serverip)
{

}
asend::~asend()
{
    qDebug()<<"asend::~asend()";
}

void asend::Stopsend()
{
    qDebug()<<"asend::Stopsend()";
    send=false;
}

void asend::run()
{
    qDebug()<<QThread::currentThreadId();
    qDebug()<<"asend::run()";
    //传一个进度条绑定信号槽来显示进度
    connect(this,&asend::sendFileSuccess,widget,&aMessagewidget::SendFileSuccess);
    connect(this,&asend::sendFileFaile,widget,&aMessagewidget::SendFileFaile);
    connect(this,&asend::sendAsize,widget,&aMessagewidget::Sendasize);
    connect(widget,&aMessagewidget::stopSendfile,this,&asend::Stopsend);


    QFile file(filepath);
    QFileInfo fileinfo(file);
    QString filesuffix=QString(".")+fileinfo.suffix();
    double filesize=fileinfo.size();

    QJsonArray array;
    array.push_back(filesuffix);
    array.push_back(filesize);
    QJsonDocument doc(array);
    QByteArray info=doc.toJson();
    socket=new QTcpSocket();
    socket->connectToHost(serverip,serverGetFileport);

    if(!socket->waitForConnected(5000))
    {
        qDebug()<<"服务器繁忙！";
        socket->close();
        emit sendFileFaile();
        return;
    }
    qDebug()<<"连接成功！";
    socket->write(info);
    qDebug()<<"已发送文件信息  等待接收Key";

    if(!socket->waitForReadyRead(10000))
    {
        qDebug()<<"服务器繁忙！";
        socket->close();
        emit sendFileFaile();
        return;
    }

    QString key(socket->readAll());//稍后处理
    qDebug()<<"以获得key:"<<key<<"开始发送文件";

    file.open(QFile::ReadOnly);
    double havesend=0;

    while(!file.atEnd())
    {
        if(send)
        {
            havesend+=socket->write(file.read(areadsize));
            qDebug()<<"已发送："<<havesend;
            socket->flush();
            QThread::msleep(100);
        }
        else
            break;
    }
    if(send)
    {
        if(!socket->waitForReadyRead(10000))
        {
            qDebug()<<"服务器繁忙！";
            socket->close();
            emit sendFileFaile();
            return;
        }

        QString reslute(socket->readAll());
        if(reslute==success)
            emit sendFileSuccess(key);
        else
            emit sendFileFaile();
    }
    socket->disconnectFromHost();
    socket->close();
    delete socket;
}




aget::aget(QHostAddress serverip, QString savefilepath, QString key, aMessagewidget *widget, QObject *parent)
    :QObject(parent),savefilepath(savefilepath),key(key),widget(widget),serverip(serverip)
{
}
aget::~aget()
{
    qDebug()<<"aget::~aget()";
    delete socket;
}
void aget::run()
{
    qDebug()<<"aget::run()";
    connect(this,&aget::getFileSuccess,widget,&aMessagewidget::GetFileSuccess);
    connect(this,&aget::getFileFaile,widget,&aMessagewidget::GetFileFaile);
    connect(this,&aget::getAsize,widget,&aMessagewidget::Getasize);


    QFile savefile(savefilepath);
    savefile.open(QFile::WriteOnly);
    //传入进度条指针绑定信号更新进度
    socket=new QTcpSocket();
    socket->connectToHost(serverip,serverSendFileport);
    if(!socket->waitForConnected(5000))
    {
        qDebug()<<"服务器繁忙！";
        socket->close();
        emit getFileFaile();
        return;
    }
    qDebug()<<"连接成功！";
    socket->write(key.toUtf8());
    qDebug()<<"已发送key值";
    if(!socket->waitForReadyRead(10000))
    {
        qDebug()<<"服务器繁忙！";
        socket->close();
        emit getFileFaile();
        return;
    }
    double size=socket->readAll().toDouble();
    qDebug()<<"需要接受收文件的大小："<<size;
    QString answer="pleaseSend";
    socket->write(answer.toUtf8());
    double haveGet=0;
    qDebug()<<"等待接收文件";
    while(socket->waitForReadyRead(5000))
    {
        qDebug()<<"已接受："<<(haveGet+=savefile.write(socket->readAll()));
        if(haveGet==size)
            break;
    }
    qDebug()<<"接收完成！";
    if(socket->bytesAvailable())
        savefile.write(socket->readAll());

    savefile.close();
    if(haveGet==size)
    {
        qDebug()<<"getFileSuccess";
        emit getFileSuccess();
    }
    else
    {
        qDebug()<<"getFileFaile";
        qDebug()<<"HaveGet:"<<haveGet;
        emit getFileFaile();
    }
    socket->disconnectFromHost();
    socket->close();
}










