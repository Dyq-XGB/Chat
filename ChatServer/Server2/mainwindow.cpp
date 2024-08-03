#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QThread>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QFileInfo>
void MainWindow::deleteAllok()
{
    qDebug()<<"MainWindow::deleteAllok()";
    delete ui;
    needClose=true;
    close();
}

MainWindow::MainWindow(QString logfilepath,QString AlluserInfoDir, QString AllFileDir, QString Alluserinfopath,
                       QString Allfileinfopath, QString AllserverPath,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<"MainWindow::MainWindow(QWidget *parent)"<<QThread::currentThread();
    setAttribute(Qt::WA_DeleteOnClose);

    logFilepath=logfilepath;
    logfile=new QFile(logfilepath);
    logfile->open(QFile::WriteOnly);

    alluserinfoDir=AlluserInfoDir;
    qDebug()<<"alluserinfoDir:"<<alluserinfoDir;
    alluserbaseinfoPath=Alluserinfopath;
    qDebug()<<"alluserbaseinfoPath:"<<alluserbaseinfoPath;
    allfileinfoDir=AllFileDir;
    qDebug()<<"allfileinfoDir:"<<allfileinfoDir;
    allfielinfoPath=Allfileinfopath;
    qDebug()<<"alluserbaseinfoPath:"<<allfielinfoPath;
    allserverDir=AllserverPath;
    qDebug()<<"allserverDir:"<<allserverDir;

    AllwaitConnect=new QMap<int,QString>();

    AllidAndpassword=new QMap<QString,QString>();

    baseinfo=new QMap<QString,QPair<QString,QString>>();

    AllNotGetMessaeg=new QMap<QString,QMap<QString,QJsonArray>*>();

    onlineusers=new AllOnlineUser(AlluserInfoDir,AllwaitConnect,AllNotGetMessaeg);
    connect(onlineusers,&AllOnlineUser::saveThisinfo,this,&MainWindow::saveThisinfo);
    online_t=new QThread();
    onlineusers->moveToThread(online_t);
    online_t->start();


    QFile alluserbaseinfo(alluserbaseinfoPath);
    QFileInfo info(alluserbaseinfo);
    qDebug()<<info.size();
    alluserbaseinfo.open(QFile::ReadOnly);
    qDebug()<<alluserbaseinfo.size();
    QJsonDocument doc=QJsonDocument::fromJson(alluserbaseinfo.readAll());
    alluserbaseinfo.close();
    QJsonObject baseobject(doc.object());
    qDebug()<<baseobject.size();
    QJsonObject::Iterator i=baseobject.begin();
    while(i!=baseobject.end())
    {
        qDebug()<<"i!=baseobject.end()";
        QJsonArray infoarray=i.value().toArray();

        QString id=i.key();

        QString name=infoarray.at(0).toString();
        QString password=infoarray.at(1).toString();

        qDebug()<<id<<name<<password;


        QString pix=infoarray.at(2).toString();
        qDebug()<<id<<password;
        AllidAndpassword->insert(id,password);
        baseinfo->insert(id,QPair<QString,QString>(name,pix));

        QString filepath=AlluserInfoDir+id+"/notgetmessage.json";
        QFile file(filepath);
        file.open(QFile::ReadOnly);
        QJsonDocument doc=QJsonDocument::fromJson(file.readAll());
        file.close();
        QJsonObject object(doc.object());
        QMap<QString,QJsonArray>*messageMap=new QMap<QString,QJsonArray>();
        QJsonObject::Iterator x=object.begin();
        while(x!=object.end())
        {
            messageMap->insert(x.key(),x.value().toArray());
            ++x;
        }
        AllNotGetMessaeg->insert(id,messageMap);
        ++i;
    }

    connect(onlineusers,&AllOnlineUser::aconnect,this,&MainWindow::aOnline);
    connect(onlineusers,&AllOnlineUser::adisconnect,this,&MainWindow::adeLine);
}

MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow::~MainWindow()";
    logfile->close();
    delete logfile;

    if(haveInit)
    {
        delete dealRegit;

        Regit_t->quit();
        Regit_t->wait();
        delete Regit_t;

        delete dealLogin;

        Login_t->quit();
        Login_t->wait();
        delete Login_t;

        delete Dealconnect;

        connect_t->quit();
        connect_t->wait();
        delete connect_t;

        delete onlineusers;

        online_t->quit();
        online_t->wait();
        delete online_t;


        delete file;

        file_t->quit();
        file_t->wait();
        delete file_t;

        delete Dealmessage;

        message_t->quit();
        message_t->wait();
        delete message_t;



        QJsonObject baseobject;
        QMap<QString,QString>::Iterator i1=AllidAndpassword->begin();
        QMap<QString,QPair<QString,QString>>::Iterator x1=baseinfo->begin();

        while(i1!=AllidAndpassword->end())
        {
            QJsonArray array;
            array.push_back(x1.value().first);
            array.push_back(i1.value());
            array.push_back(x1.value().second);

            baseobject.insert(i1.key(),array);
            ++x1;
            ++i1;
        }

        QFile file(alluserbaseinfoPath);
        file.open(QFile::WriteOnly);
        QJsonDocument doc(baseobject);
        file.write(doc.toJson());
        file.close();

        delete AllidAndpassword;

        delete baseinfo;

        delete AllwaitConnect;


        QMap<QString,QMap<QString,QJsonArray>*>::iterator i2=AllNotGetMessaeg->begin();
        while(i2!=AllNotGetMessaeg->end())
        {
            QString filepath=alluserinfoDir+i2.key()+"/notgetmessage.json";
            QJsonObject object;

            QMap<QString,QJsonArray>*afriendrecord=i2.value();
            QMap<QString,QJsonArray>::Iterator i3=afriendrecord->begin();
            while(i3!=afriendrecord->end())
            {
                object.insert(i3.key(),i3.value());
                ++i3;
            }
            QJsonDocument doc(object);
            QFile file(filepath);
            file.open(QFile::WriteOnly);
            file.write(doc.toJson());
            file.close();
            delete i2.value();
            ++i2;
        }
        delete AllNotGetMessaeg;
        qDebug()<<"AllWorker::deleteAll() over";
    }
}




void MainWindow::aOnline(QString id,QHostAddress ip,unsigned short port,QString time)
{
    qDebug()<<"MainWindow::aOnline(QString id,QHostAddress ip,unsigned short port,QString time)";
    int rowcount=ui->onlineTable->rowCount()+1;
    ui->onlineTable->setRowCount(rowcount);

    QTableWidgetItem*item1=new QTableWidgetItem(id);
    ui->onlineTable->setItem(rowcount-1,0,item1);

    QTableWidgetItem*item2=new QTableWidgetItem(ip.toString());
    ui->onlineTable->setItem(rowcount-1,1,item2);

    QTableWidgetItem*item3=new QTableWidgetItem(QString::number(port));
    ui->onlineTable->setItem(rowcount-1,2,item3);

    QTableWidgetItem*item4=new QTableWidgetItem(time);
    ui->onlineTable->setItem(rowcount-1,3,item4);
}




void MainWindow::adeLine(QString id,QString time)
{
    qDebug()<<" MainWindow::adeLine(QString id,QString time)";

    QTableWidgetItem*item=ui->onlineTable->findItems(id,Qt::MatchExactly).at(0);
    int atrow=item->row();
    ui->onlineTable->removeRow(atrow);


    int rowcount=ui->DeLineTabel->rowCount()+1;
    ui->DeLineTabel->setRowCount(rowcount);

    QTableWidgetItem*item1=new QTableWidgetItem(id);
    ui->DeLineTabel->setItem(rowcount-1,0,item1);

    QTableWidgetItem*item2=new QTableWidgetItem(time);
    ui->DeLineTabel->setItem(rowcount-1,1,item2);
}




void MainWindow::on_startlisen_clicked()
{
    QHostAddress ip=QHostAddress(ui->ServerIP->text());
    ui->startlisen->setText("已启动！");
    ui->startlisen->setEnabled(false);
    haveInit=true;

    logfile=new QFile(logFilepath);
    logfile->open(QFile::WriteOnly|QFile::Append|QFile::Text);

    QString time=QTime::currentTime().toString();
    QString info=QString("\n")+time+"\nAllworkerStart\n";
    qDebug()<<logfile->write(info.toUtf8());
    logfile->flush();

    qDebug()<<"AllWorker::startInitServer";
    dealLogin=new DealUserLogin(AllidAndpassword,AllwaitConnect);
    connect(this,&MainWindow::start,dealLogin,&DealUserLogin::startwork);
    connect(dealLogin,&DealUserLogin::saveThisinfo,this,&MainWindow::saveThisinfo);
    Login_t=new QThread();
    dealLogin->moveToThread(Login_t);
    Login_t->start();

    dealRegit=new DealUserRegit(alluserinfoDir,AllidAndpassword,baseinfo,AllNotGetMessaeg);
    connect(this,&MainWindow::start,dealRegit,&DealUserRegit::startwork);
    connect(dealRegit,&DealUserRegit::saveThisinfo,this,&MainWindow::saveThisinfo);
    Regit_t=new QThread();
    dealRegit->moveToThread(Regit_t);
    Regit_t->start();

    Dealconnect=new DealUserConnect();
    connect(this,&MainWindow::start,Dealconnect,&DealUserConnect::startwork);
    connect(Dealconnect,&DealUserConnect::TheConnectHandle,onlineusers,&AllOnlineUser::CreateAonline);
    connect(Dealconnect,&DealUserConnect::saveThisinfo,this,&MainWindow::saveThisinfo);
    connect_t=new QThread();
    Dealconnect->moveToThread(connect_t);
    connect_t->start();

    file=new DealFile(allfileinfoDir);
    connect(this,&MainWindow::start,file,&DealFile::startwork);
    connect(file,&DealFile::saveThisinfo,this,&MainWindow::saveThisinfo);
    file_t=new QThread();
    file->moveToThread(file_t);
    file_t->start();

    Dealmessage=new DealMessage(alluserinfoDir,onlineusers,AllNotGetMessaeg);
    connect(this,&MainWindow::start,Dealmessage,&DealMessage::startwork);
    connect(Dealmessage,&DealMessage::saveThisinfo,this,&MainWindow::saveThisinfo);
    message_t=new QThread();
    Dealmessage->moveToThread(message_t);
    message_t->start();



    Dealaddfriend=new DealAddFriend(allfileinfoDir,baseinfo);
    connect(this,&MainWindow::start,Dealaddfriend,&DealAddFriend::startwork);
    connect(Dealaddfriend,&DealAddFriend::saveThisInfo,this,&MainWindow::saveThisinfo);
    add_t=new QThread();
    Dealaddfriend->moveToThread(add_t);
    add_t->start();

    emit start(ip);
}

void MainWindow::saveThisinfo(QString message)
{
    qDebug()<<"info";
    QString time=QTime::currentTime().toString();
    QString Info=time+"\n"+message+"\n";
    logfile->write(Info.toUtf8());
    logfile->flush();
}

