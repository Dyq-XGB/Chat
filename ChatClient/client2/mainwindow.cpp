#include "mainwindow.h"
#include "addfriendwidget.h"
#include "ui_mainwindow.h"
#include "messageitem.h"
#include "waitanswer.h"
#include "frienditem.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QThread>
#include <QListWidgetItem>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QCloseEvent>
#include <QIcon>


MainWindow::MainWindow(QHostAddress Serverip, QString AllFileDir, QString AllpixDir,
                       QString friendpixmaDir,QString allUserinfoDir, QString id,
                       unsigned short port, int Loginkey, QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow),
    id(id),port(port),Loginkey(Loginkey),
    Serverip(Serverip),allUserinfoDir(allUserinfoDir),
    friendpixmapDir(friendpixmaDir),
    savepixDir(AllpixDir),savefileDir(AllFileDir)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/qq.ico"));

    setAttribute(Qt::WA_DeleteOnClose);

    allmessageitem=new QMap<QString,MessageItem*>();
    allfriendwidget=new QMap<QString,Frienditem*>();
    allchatwidget=new QMap<QString,ChatWidget*>();
    allwaitanswer=new QMap<QString,WaitAnswer*>();
    messagerecord=new QMap<QString,QJsonArray*>();


    pasure=new PasureMessage(AllpixDir,allUserinfoDir,friendpixmaDir,id,baseinfoobject,
                            friendsobject,messageitemarray,otherRequestme,messagerecord);
    connect(this,&MainWindow::startPasure,pasure,&PasureMessage::PrepareAllinfo);

    connect(this,&MainWindow::answerThisFriend,pasure,&PasureMessage::PasureasendMessage);
    connect(pasure,&PasureMessage::TheBaseInfo,this,&MainWindow::setBaseinfo);
    connect(pasure,&PasureMessage::TheFrienditem,this,&MainWindow::setFriendItem);
    connect(pasure,&PasureMessage::TheMessageitem,this,&MainWindow::setMessageItem);
    //connect(pasure,&PasureMessage::TheMessagerecord,this,&MainWindow::setMessagereocrd);
    connect(pasure,&PasureMessage::TheOtherRequestAdd,this,&MainWindow::setOtherRequestAdd);
    connect(pasure,&PasureMessage::aMessage,this,&MainWindow::aMessage);
    connect(pasure,&PasureMessage::aFile,this,&MainWindow::aFile);
    connect(pasure,&PasureMessage::aPixmap,this,&MainWindow::aPixmap);
    connect(pasure,&PasureMessage::isaAddfriendanswer,this,&MainWindow::aAddfriendanswer);
    connect(pasure,&PasureMessage::isaAddfriendrequest,this,&MainWindow::aAddfriendrequest);
    p_t=new QThread();
    pasure->moveToThread(p_t);
    p_t->start();


    con=new ConnectToServer(Serverip,allUserinfoDir,id,Loginkey,port);
    connect(pasure,&PasureMessage::isNeedGetAllInfo,con,&ConnectToServer::slot_startwork);
    connect(con,&ConnectToServer::PasureNotgetMessage,pasure,&PasureMessage::PasureNotgetmessage);
    connect(this,&MainWindow::SendInfoToServer,con,&ConnectToServer::SendAllinfotoServer);
    connect(con,&ConnectToServer::ConnectFaile,this,[](){qDebug()<<"服务器繁忙！";});
    connect(con,&ConnectToServer::sendOk,this,&MainWindow::DeleteAll);
    t_con=new QThread();
    con->moveToThread(t_con);
    t_con->start();


    file=new DealFile(Serverip);
    connect(con,&ConnectToServer::ConnectSuccess,file,&DealFile::startwork);
    t_f=new QThread();
    file->moveToThread(t_f);
    t_f->start();

    message=new DealMessage(Serverip,port);
    connect(message,&DealMessage::aMessage,pasure,&PasureMessage::PasureaMessage);
    connect(pasure,&PasureMessage::sendaMessage,message,&DealMessage::SendaMessage);
    connect(con,&ConnectToServer::ConnectSuccess,message,&DealMessage::startwork);

    m_t=new QThread();
    message->moveToThread(m_t);
    m_t->start();
}


MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow::~MainWindow()";
}

void MainWindow::Init()
{
    qDebug()<<"MainWindow::Init()";
    emit startPasure(id,baseinfoobject,friendsobject,messageitemarray,otherRequestme,messagerecord);
}



void MainWindow::setBaseinfo()//QJsonObject* object)
{
    qDebug()<<"MainWindow::setBaseinfo(QJsonObject* object)";
//    baseinfoobject=object;

    name=baseinfoobject.find("nickname")->toString();
    QString pixpath=friendpixmapDir+id+".png";
    QPixmap pixmap(pixpath);

    ui->headshot->setPixmap(pixmap.scaled(ui->headshot->size()));
    ui->id->setText(id);
    ui->name->setText(name);
}



void MainWindow::CreateaChatWidget(QString friendid,QString friendname,QJsonArray*messagerecord)
{
    qDebug()<<"CreateaChatWidget(QString friendid,QJsonArray*array)";

    ChatWidget*achatwidget=new ChatWidget(friendpixmapDir,savepixDir,savefileDir,friendid,friendname,id,messagerecord);
    connect(achatwidget,&ChatWidget::SendaMessage,pasure,&PasureMessage::PasureasendMessage);
    connect(achatwidget,&ChatWidget::SendaFile,file,&DealFile::SendaFile);
    connect(achatwidget,&ChatWidget::GetaFile,file,&DealFile::GetaFile);
    connect(achatwidget,&ChatWidget::HaveDelete,this,&MainWindow::removeaChatWidget);

    allchatwidget->insert(friendid,achatwidget);
    achatwidget->show();
}


void MainWindow::on_MessageList_itemDoubleClicked(QListWidgetItem *item)
{

    qDebug()<<"MainWindow::on_MessageList_itemDoubleClicked(QListWidgetItem *item)";
    MessageItem*messagewidget=static_cast<MessageItem*>(ui->MessageList->itemWidget(item));

    QString friendid=messagewidget->friendid;
    QMap<QString,ChatWidget*>::Iterator i=allchatwidget->find(friendid);
    if(i!=allchatwidget->end())
    {
        ChatWidget*chat=i.value();
        chat->activateWindow();
        chat->setWindowState((chat->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    }
    else
    {
        QString friendname=messagewidget->name;
        CreateaChatWidget(friendid,friendname,messagewidget->messagerecord);
    }
}


void MainWindow::on_FriendList_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<"on_FriendList_itemDoubleClicked(QListWidgetItem *item)";
    Frienditem*frienditem=static_cast<Frienditem*>(ui->FriendList->itemWidget(item));
    QString friendid=frienditem->friendid;
    QString friendname=frienditem->friendname;
    qDebug()<<"friendid:"<<friendid;

    QMap<QString,ChatWidget*>::Iterator i=allchatwidget->find(friendid);
    if(i!=allchatwidget->end())
    {
        ChatWidget*widget=i.value();
        widget->activateWindow();
        widget->setWindowState((widget->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    }
    else
    {
        if(!allmessageitem->contains(friendid))
            addAMessageitem(friendid);
        CreateaChatWidget(friendid,friendname,messagerecord->find(friendid).value());
    }
}

void MainWindow::removeaChatWidget(QString friendid)
{
    qDebug()<<"MainWindow::removeaChatWidget(QString friendid)"<<friendid;
    delete allchatwidget->find(friendid).value();
    allchatwidget->remove(friendid);
}



void MainWindow::aMessage(QString friendid,QString message,QString time)
{
    qDebug()<<"MainWindow::aMessage(QString friendid,QString message,QString time)";


    QMap<QString,MessageItem*>::Iterator i=allmessageitem->find(friendid);
    if(i==allmessageitem->end())
    {
        addAMessageitem(friendid);
    }
    else
    {
        QMap<QString,ChatWidget*>::Iterator x=allchatwidget->find(friendid);
        bool chatwidgetIsexist=false;
        if (x!=allchatwidget->end())
        {
            ChatWidget*widget=x.value();
            widget->CreateAMessageWidget(message,0,time);
            chatwidgetIsexist=true;
        }
        MessageItem*itemwidget=i.value();
        itemwidget->changelastmessage(message,time,chatwidgetIsexist);
    }
}

void MainWindow::aFile(QString friendid, QString key, double filesize, QString filename, QString time)
{
    qDebug()<<"MainWindow::aFile(QString friendid, QString key, double filesize, QString filename, QString time)";


    QMap<QString,MessageItem*>::Iterator i=allmessageitem->find(friendid);
    if(i==allmessageitem->end())
    {
        addAMessageitem(friendid);
    }
    else
    {
        QMap<QString,ChatWidget*>::Iterator x=allchatwidget->find(friendid);
        bool chatwidgetIsexist=false;
        if (x!=allchatwidget->end())
        {
            ChatWidget*widget=x.value();
            widget->CreateAWaitGetFileWidget(filename,filesize,key,time,0);
            chatwidgetIsexist=true;
        }
        MessageItem*itemwidget=i.value();
        itemwidget->changelastmessage("[文件]",time,chatwidgetIsexist);
    }
}

void MainWindow::aPixmap(QString friendid, QString pixsavepath, QString time)
{
    qDebug()<<"MainWindow::aPixmap(QString friendid, QString pixsavepath, QString time)";


    QMap<QString,MessageItem*>::Iterator i=allmessageitem->find(friendid);
    if(i==allmessageitem->end())
    {
        addAMessageitem(friendid);
    }
    else
    {
        QMap<QString,ChatWidget*>::Iterator x=allchatwidget->find(friendid);
        bool chatwidgetIsexist=false;
        if (x!=allchatwidget->end())
        {
            ChatWidget*widget=x.value();
            widget->CreateAPixWidget(pixsavepath,time,0);
            chatwidgetIsexist=true;
        }
        MessageItem*itemwidget=i.value();
        itemwidget->changelastmessage("[图片]",time,chatwidgetIsexist);
    }
}



void MainWindow::aAddfriendanswer(QString friendid,QString friendname,QString pixpath)
{
    qDebug()<<"MainWindow::aAddfriendanswer(QString id, QString name, QString path, QString time)";
    addAFrienditem(friendid,friendname,pixpath);
    addAMessageitem(friendid);
}

void MainWindow::aAddfriendrequest(QString friendid,QString friendname,QString pixpath,QString time)
{
    qDebug()<<"MainWindow::aAddfriendrequest(QString id, QString name, QString path, QString time)"<<friendid<<friendname<<pixpath<<time;
    WaitAnswer*awaitanswer=new WaitAnswer(friendid,friendname,pixpath,time);
    connect(awaitanswer,&WaitAnswer::answerThisFriend,this,&MainWindow::do_addThisFriend);
    QListWidgetItem*item=new QListWidgetItem(ui->waitWidget);
    item->setSizeHint(awaitanswer->size());
    ui->waitWidget->setItemWidget(item,awaitanswer);

    allwaitanswer->insert(friendid,awaitanswer);
}


void MainWindow::setFriendItem()//QJsonObject *object)
{
    qDebug()<<"MainWindow::setFriendItem(QJsonObject *object)";
    //friendsobject=object;
    QJsonObject::Iterator i=friendsobject.begin();
    while(i!=friendsobject.end())
    {
        QString friendid=i.key();
        QJsonArray infoarray=i.value().toArray();
        QString friendname=infoarray.at(0).toString();
        QString pixpath=friendpixmapDir+friendid+".png";
        addAFrienditem(friendid,friendname,pixpath);
        ++i;
    }
}

void MainWindow::setMessageItem()//QJsonArray *array)//以后array里面只需要记录friendid
{
    //messageitemarray=array;
    QJsonArray::Iterator i=messageitemarray.begin();
    while(i!=messageitemarray.end())
    {
        addAMessageitem(i->toString());
        ++i;
    }
}

void MainWindow::setOtherRequestAdd()//QJsonArray *array)
{
    qDebug()<<"MainWindow::setOtherRequestAdd(QJsonArray *array)";
    QJsonArray::Iterator i=otherRequestme.begin();
    while(i!=otherRequestme.end())
    {
        QJsonArray infoarray=i->toArray();
        QString friendid=infoarray.at(1).toString();
        QString friendname=infoarray.at(3).toString();
        QString time=infoarray.last().toString();
        QString pixpath=friendpixmapDir+friendid+".png";
        aAddfriendrequest(friendid,friendname,pixpath,time);
        ++i;
    }
}

//void MainWindow::setMessagereocrd(QMap<QString, QJsonArray*> *allrecord)
//{
//    //messagerecord=allrecord;
//}

void MainWindow::addAMessageitem(QString friendid)
{
    qDebug()<<"MainWindow::addAMessageitem(QString friendid)"<<friendid;
    QJsonArray* recordarray=messagerecord->find(friendid).value();

    QJsonArray infoarray=friendsobject.find(friendid).value().toArray();
    QString friendname=infoarray.at(0).toString();
    QString pixpath=friendpixmapDir+friendid+".png";
    QListWidgetItem*listitem=new QListWidgetItem(ui->MessageList);
    MessageItem*item=new MessageItem(friendid,friendname,pixpath,recordarray);
    listitem->setSizeHint(item->minimumSize());
    listitem->setData(Qt::UserRole,id);
    ui->MessageList->setItemWidget(listitem,item);
    allmessageitem->insert(friendid,item);
}

void MainWindow::addAFrienditem(QString friendid,QString friendname,QString pixpath)
{
    qDebug()<<"MainWindow::addAFrienditem(QString friendid,QString friendname,QString pixpath)"<<friendid<<friendname<<pixpath;
    QListWidgetItem*listitem=new QListWidgetItem(ui->FriendList);
    Frienditem*item=new Frienditem(friendid,friendname,pixpath,ui->FriendList);
    listitem->setSizeHint(item->maximumSize());
    listitem->setData(Qt::UserRole,friendid);
    ui->FriendList->setItemWidget(listitem,item);
    allfriendwidget->insert(friendid,item);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(needClose)
    {
        qDebug()<<"needClose";
        QMainWindow::closeEvent(event);
        event->accept();
    }
    else
    {
        event->accept();
        m_t->quit();
        m_t->wait();
        delete m_t;
        delete message;

        delete file;
        t_f->quit();
        t_f->wait();
        delete t_f;

        delete pasure;
        p_t->quit();
        p_t->wait();
        delete p_t;

        qDebug()<<"1";
        {
            QMap<QString,MessageItem*>::Iterator i=allmessageitem->begin();
            QJsonArray array;
            while(i!=allmessageitem->end())
            {
                QString friendid=i.value()->friendid;
                array.push_back(friendid);
                //delete i.value();
                ++i;
            }
            delete allmessageitem;
            qDebug()<<2;
            QJsonObject object5;
            QMap<QString,QJsonArray*>::Iterator x=messagerecord->begin();
            while(x!=messagerecord->end())
            {
                object5.insert(x.key(),*(x.value()));
                delete x.value();
                ++x;
            }
            delete messagerecord;
qDebug()<<3;

            QJsonObject allinfoObject;
            allinfoObject.insert("baseinfo",baseinfoobject);
            allinfoObject.insert("messagerecord",object5);
            allinfoObject.insert("friends",friendsobject);
            allinfoObject.insert("messageitem",array);
            allinfoObject.insert("requestaddfriend",otherRequestme);

            QJsonDocument allinfo(allinfoObject);
            QByteArray bytes=allinfo.toJson();
            QFile infofile(allUserinfoDir+id+"/"+id+".json");
            infofile.open(QFile::WriteOnly);
            QDataStream stream(&infofile);
            stream.writeRawData(bytes,bytes.size());
            infofile.close();
            qDebug()<<4;
        }
qDebug()<<5;
        {
            QMap<QString,Frienditem*>::Iterator x=allfriendwidget->begin();
            while(x!=allfriendwidget->end())
            {
                delete x.value();
                ++x;
            }
            delete allfriendwidget;
        }
qDebug()<<6;
        {
            QMap<QString,ChatWidget*>::Iterator j=allchatwidget->begin();
            while(j!=allchatwidget->end())
            {
                delete j.value();
                ++j;
            }
            delete allchatwidget;
        }
        qDebug()<<7;
        {
            if(!allwaitanswer->isEmpty())
            {
                QMap<QString,WaitAnswer*>::Iterator k=allwaitanswer->begin();
                while(k!=allwaitanswer->end())
                {
                    delete k.value();
                    ++k;
                }
            }
            delete allwaitanswer;
        }
//        if(findfriendwidget!=nullptr)
//            delete findfriendwidget;
        qDebug()<<8;
        emit SendInfoToServer();
    }
}

void MainWindow::on_addFriend_clicked()
{
    qDebug()<<"MainWindow::on_addFriend_clicked()";
    findfriendwidget=new AddFriendWidget(friendpixmapDir,id,name);
    connect(findfriendwidget,&AddFriendWidget::FindFriend,message,&DealMessage::FindFriend);
    connect(findfriendwidget,&AddFriendWidget::addaFriend,pasure,&PasureMessage::PasureasendMessage);
    connect(pasure,&PasureMessage::isFindfriendReslute,findfriendwidget,&AddFriendWidget::GetFindReslute);
    findfriendwidget->show();
}

void MainWindow::do_addThisFriend(QString friendid,QString friendname,QString pixpath)
{
    qDebug()<<"MainWindow::do_addThisFriend(QString friendid, QString friendname, QString pixpath)"<<friendid<<friendname<<pixpath;


    QFile file(friendpixmapDir+id+".png");
    file.open(QFile::ReadOnly);
    QByteArray bytes=file.readAll();
    file.close();
    QString pix=bytes.toBase64();


    qDebug()<<"1";
    QJsonArray infoarray;
    qDebug()<<"2";
    infoarray.push_back(friendname);
    qDebug()<<"3";
    infoarray.push_back(pix);
    qDebug()<<"4";
    friendsobject.insert(friendid,infoarray);
    qDebug()<<"5";
    QJsonArray* nullarray=new QJsonArray();
    messagerecord->insert(friendid,nullarray);
    qDebug()<<"6";

    addAMessageitem(friendid);
    addAFrienditem(friendid,friendname,pixpath);

    QJsonArray answerarray;
    QString time=QTime::currentTime().toString();
    answerarray.push_back("addfriendanswer");
    answerarray.push_back(id);
    answerarray.push_back(friendid);
    answerarray.push_back(name);
    answerarray.push_back(pix);
    answerarray.push_back(time);
    emit answerThisFriend(friendid,answerarray);
}

void MainWindow::DeleteAll()
{
    qDebug()<<"MainWindow::DeleteAll()";

    delete con;
    t_con->quit();
    t_con->wait();
    delete t_con;

    needClose=true;
    close();
}

