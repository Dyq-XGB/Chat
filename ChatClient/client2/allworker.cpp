#include "allworker.h"
#include "pasuremessage.h"

#include <QDir>
#include <QJsonArray>

AllWorker::AllWorker(QHostAddress Serverip,QString AllFileDir, QString AllpixDir, QString friendpixmaDir, QString allUserinfoDir, QString id,
                     unsigned short port, int Loginkey, QObject *parent)
    : QObject{parent},id(id),serverip(Serverip),AllFileDir(AllFileDir),AllpixDir(AllpixDir),friendpixmaDir(friendpixmaDir),allUserinfoDir(allUserinfoDir)
{
    connect(this,&AllWorker::startwork,this,&AllWorker::on_startwork);

    pasure=new PasureMessage(AllpixDir,allUserinfoDir,friendpixmaDir);
    connect(this,&AllWorker::startPasure,pasure,&PasureMessage::PrepareAllinfo);
    connect(this,&AllWorker::saveAllinfo,pasure,&PasureMessage::saveAllInfo);
    connect(pasure,&PasureMessage::SaveAllinfoOk,this,&AllWorker::StartDelete);

    p_t=new QThread();
    pasure->moveToThread(p_t);
    p_t->start();


    con=new ConnectToServer(serverip,allUserinfoDir,id,Loginkey,port);
    connect(pasure,&PasureMessage::isNeedGetAllInfo,con,&ConnectToServer::slot_startwork);
    connect(this,&AllWorker::sendInfoToserver,con,&ConnectToServer::SendAllinfotoServer);
    connect(con,&ConnectToServer::PasureNotgetMessage,pasure,&PasureMessage::PasureNotgetmessage);
    connect(con,&ConnectToServer::ConnectFaile,this,[](){qDebug()<<"服务器繁忙！";});
    connect(con,&ConnectToServer::sendOk,this,[=](){qDebug()<<"sendok";delete this;});
    t_con=new QThread();
    con->moveToThread(t_con);
    t_con->start();


    file=new DealFile(serverip);
    connect(con,&ConnectToServer::ConnectSuccess,file,&DealFile::startwork);
    t_f=new QThread();
    file->moveToThread(t_f);
    t_f->start();

    message=new DealMessage(serverip,port);
    connect(message,&DealMessage::aMessage,pasure,&PasureMessage::PasureaMessage);
    connect(pasure,&PasureMessage::sendaMessage,message,&DealMessage::SendaMessage);
    connect(con,&ConnectToServer::ConnectSuccess,message,&DealMessage::startwork);
    m_t=new QThread();
    message->moveToThread(m_t);
    m_t->start();
}
AllWorker::~AllWorker()
{
    qDebug()<<"AllWorker::~AllWorker()";

    p_t->quit();
    p_t->wait();
    delete p_t;

    t_con->quit();
    t_con->wait();
    delete t_con;


    emit hadDeleteAll();

    QThread::msleep(1000);
    this->thread()->quit();
}


void AllWorker::DeleteAll()
{
    qDebug()<<" AllWorker::DeleteAll()";
    delete file;
    t_f->quit();
    t_f->wait();
    delete t_f;

    delete message;
    m_t->quit();
    m_t->wait();
    delete m_t;

    emit saveAllinfo();
}

void AllWorker::StartDelete()
{
    qDebug()<<"AllWorker::StartDelete()";
    emit sendInfoToserver();
}

void AllWorker::on_startwork()
{
    qRegisterMetaType<QJsonArray>("QJsonArray");
    emit startPasure(id);
}




