#include "dealfile.h"
#include "qjsonobject.h"
#include <QRandomGenerator>
#include <QTime>
#include <QMutex>
#include <QDir>
#include <QRandomGenerator>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTime>
#include <QDate>
#include <QThread>
#include <QElapsedTimer>
DealFile::DealFile(QString allfileDir, QObject *parent)
    : QObject{parent}
{
    fileDir=allfileDir;
}

DealFile::~DealFile()
{
    delete filelib;

    get_t->quit();
    get_t->wait();
    delete get_t;

    send_t->quit();
    send_t->wait();
    delete send_t;

    delete get;
    delete send;
}
void DealFile::startwork(QHostAddress ip)
{
    qDebug()<<"DealFile::startwork()";
    filelib=new FileLib(fileDir);

    qDebug()<<"get";
    get=new GetFile(fileDir,filelib);
    connect(this,&DealFile::start,get,&GetFile::startdo);
    connect(get,&GetFile::saveThisinfo,this,&DealFile::saveThisinfo);

    send=new SendFile(fileDir,filelib);
    connect(this,&DealFile::start,send,&SendFile::startdo);
    connect(send,&SendFile::saveThisinfo,this,&DealFile::saveThisinfo);
    qDebug()<<"send";


    get_t=new QThread();

    send_t=new QThread();

    get->moveToThread(get_t);
    send->moveToThread(send_t);

    get_t->start();
    send_t->start();

    emit start(ip);
    emit saveThisinfo("DealFile::startwork()");
    qDebug()<<"DealFile::startwork()"<<QThread::currentThread();
}



//--------------MyServer---------------


//==========================GetFile=========================
GetFile::GetFile(QString filedir, FileLib *filelib, QObject *parent)
    :QObject(parent),filelib(filelib)
{
    Filedir=filedir;
}

GetFile::~GetFile()
{
    getfilepool->waitForDone(10000);
    getfilepool->clear();
    delete getfilepool;

    get_server->close();
    delete get_server;
}

void GetFile::startdo(QHostAddress ip)
{
    qDebug()<<"GetFile::startdo()";
    getfilepool=new QThreadPool();

    get_server=new Myserver();
    get_server->listen(ip,port);
    connect(get_server,&Myserver::TheHandle,this,&GetFile::GetaFile);
    emit saveThisinfo("GetFile::startdo()");
    qDebug()<<"GetFile::startdo()"<<QThread::currentThreadId();
}



void GetFile::GetaFile(qintptr handle)
{
    aget*a=new aget(Filedir,filelib,handle);
    connect(a,&aget::saveThisinfo,this,&GetFile::saveThisinfo);
    getfilepool->start(a);
}


//========================aget=============================================

aget::aget(QString allFileDir, FileLib *filelib, qintptr handle, QObject *parent)
    :QObject(parent),handle(handle),filelib(filelib)
{
    SaveFileDir=allFileDir;
}

aget::~aget()
{
    delete socket;
}

void aget::run()
{
    emit saveThisinfo(QString("aget::run():")+QString::number(handle));
    qDebug()<<"aget::run()";
    socket=new QTcpSocket();
    socket->setSocketDescriptor(handle);

    qDebug()<<"等待读取需要接受文件的信息！";
    if(!socket->waitForReadyRead(5000)&&!socket->bytesAvailable())
    {
        qDebug()<<"error";
        socket->abort();
        return;
    }
    qDebug()<<"开始接收文件信息";
    QByteArray bytes;
    bytes=socket->readAll();
    QJsonDocument info=QJsonDocument::fromJson(bytes);
    QJsonArray infoarray(info.array());
    QString suffix=infoarray.at(0).toString();
    double size=infoarray.at(1).toDouble();
    QString key=filelib->GetaNotUseKey();

    qDebug()<<suffix<<size<<key;

    QString savepath=SaveFileDir+key+suffix;
    qDebug()<<"savepath:"<<savepath;

    QFile savefile(savepath);
    savefile.open(QFile::WriteOnly);
    socket->write(key.toUtf8());
    qDebug()<<"已经发送key 等待接收文件";

    QElapsedTimer aelapesed;
    aelapesed.start();
    while(socket->waitForReadyRead(5000))
    {
        qDebug()<<"已接收："<<(haveGet+=savefile.write(socket->readAll()));
        if(haveGet==size)
            break;
    }
    qDebug()<<"接收完成！";
    qDebug()<<aelapesed.elapsed();
    bool reslute=false;
    if(haveGet==size)
    {
        reslute=true;
        socket->write(success.toUtf8());
    }
    else
        socket->write(faile.toUtf8());
    qDebug()<<"reslute:"<<reslute<<"Havereadsize:"<<haveGet;

    if(socket->isValid())
        socket->waitForDisconnected(5000);
    qDebug()<<"已断开连接";
    savefile.close();
    socket->close();

    if(reslute)
    {
        QString time=QTime::currentTime().toString();
        QJsonArray* infoarray=new QJsonArray();
        infoarray->push_back(suffix);
        infoarray->push_back(size);
        infoarray->push_back(time);

        filelib->AddIntoFileLib(key,infoarray);
        emit saveThisinfo(QString("aget::run():")+QString::number(handle)+"success"+savepath);
    }
    else
        emit saveThisinfo(QString("aget::run():")+QString::number(handle)+"faile");
}



//==========================SendFile=======================
SendFile::SendFile(QString filedir, FileLib*filelib, QObject *parent)
    :QObject(parent),filelib(filelib)
{
    fileDir=filedir;
}

SendFile::~SendFile()
{
    sendpool->waitForDone(10000);
    sendpool->clear();
    delete sendpool;

    send_server->close();
    delete send_server;
}

void SendFile::startdo(QHostAddress ip)
{
    sendpool=new QThreadPool();

    send_server=new Myserver();
    send_server->listen(ip,port);
    connect(send_server,&Myserver::TheHandle,this,&SendFile::SendaFile);

    emit saveThisinfo("SendFile::startdo()");
    qDebug()<<"SendFile::startdo()"<<QThread::currentThreadId();
}

void SendFile::SendaFile(qintptr handle)
{
    asend*a=new asend(fileDir,filelib,handle);
    connect(a,&asend::saveThisinfo,this,&SendFile::saveThisinfo);
    sendpool->start(a);
}
//================================asend====================================
asend::asend(QString allfileDir, FileLib*filelib, qintptr handle, QObject *parent )
    :QObject(parent),handle(handle),filelib(filelib)
{
    FileDir=allfileDir;
}
asend::~asend()
{
    qDebug()<<"asend::~asend()";
    delete socket;
}
void asend::run()
{
    emit saveThisinfo(QString("asend")+QString::number(handle));
    qDebug()<<"asend::run()";
    socket=new QTcpSocket();
    socket->setSocketDescriptor(handle);
    if(!socket->waitForReadyRead(5000))
    {
        qDebug()<<"error";
        socket->abort();
        return;
    }
    QString key(socket->readAll());
    qDebug()<<"已得到key值"<<key;

    QJsonArray* infoarray=filelib->GetaFile(key);
    QString filesuffix=infoarray->at(0).toString();
    qDebug()<<"suffix:"<<filesuffix;
    double filesize=infoarray->at(1).toDouble();
    qDebug()<<"filesize:"<<filesize;
    QString filepath=FileDir+key+filesuffix;
    qDebug()<<filepath;

    QFile file(filepath);
    QByteArray sendsize;
    sendsize.setNum(filesize);
    socket->write(sendsize);

    if(socket->waitForReadyRead(5000))
    {
        QString re=QString(socket->readAll());
        if(re=="pleaseSend")
            qDebug()<<"开始发送";
    }
    file.open(QFile::ReadOnly);
    while(!file.atEnd())
    {
        qDebug()<<"已发送："<<socket->write(file.read(asize));
        socket->flush();
        QThread::msleep(100);
    }
    file.close();
    socket->waitForDisconnected(5000);
    qDebug()<<"发送完成！";
    socket->close();
    emit saveThisinfo(QString("asend over")+QString::number(handle)+"   "+filepath);
}

//=========================FileLib=============================
FileLib::FileLib(QString allfileinfoDir, QObject *parent)
    : QObject(parent)
{
    FilelibDir=allfileinfoDir;
    FilekeyAndInfoPath=FilelibDir+"keyAndinfo.json";
    keyAndfileinfo=new QMap<QString,QJsonArray*>();
    notuseKey=new QVector<QString>();
    QFile keyAndinfo(FilekeyAndInfoPath);
    keyAndinfo.open(QFile::ReadOnly);
    QJsonDocument doc=QJsonDocument::fromJson(keyAndinfo.readAll());
    keyAndinfo.close();
    QJsonObject keyAndinfoObject(doc.object());
    if(keyAndinfoObject.empty())
        qDebug()<<"null";
    else
    {
        QJsonObject::Iterator i=keyAndinfoObject.begin();
        QJsonArray *array;
        while(i!=keyAndinfoObject.end())
        {
            array=new QJsonArray(i.value().toArray());
            keyAndfileinfo->insert(i.key(),array);
            ++i;
        }
    }
        int x=50;
        while(x>0)
        {
            notuseKey->push_back(CreateaKey());
            --x;
        }
        qDebug()<<"filelibover";
}

FileLib::~FileLib()
{
        delete notuseKey;
        QFile file(FilekeyAndInfoPath);
        file.open(QFile::WriteOnly);
        QMap<QString,QJsonArray*>::Iterator i=keyAndfileinfo->begin();
        QJsonObject object;
        while(i!=keyAndfileinfo->end())
        {
            object.insert(i.key(),*i.value());
            delete i.value();
            ++i;
        }
        QJsonDocument doc(object);
        file.write(doc.toJson());
        file.close();
        delete keyAndfileinfo;
}


QString FileLib::GetaNotUseKey()
{
    QString key=notuseKey->at(notuseKey->size()-1);
    notuseKey->removeAt(notuseKey->size()-1);

    return key;
}

void FileLib::AddIntoFileLib(QString key, QJsonArray *array)
{
    qDebug()<<"AddIntoFileLib(QString key, QJsonArray *array)";
    keyAndfileinfo->insert(key,array);
}

QJsonArray* FileLib::GetaFile(QString key)
{
    qDebug()<<"FileLib::GetaFile(QString &key)";
    return keyAndfileinfo->find(key).value();
}

bool FileLib::isExits(QString &key)
{
    return keyAndfileinfo->contains(key);
}

QString FileLib::CreateaKey()
{
    QString key;
    do{
        key=QString::number(QRandomGenerator::global()->bounded(0,100000));
    }while(keyAndfileinfo->contains(key));
    return key;
}

