#include "addfriendwidget.h"
#include "qpushbutton.h"
#include "ui_addfriendwidget.h"

#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

#include "afindreslute.h"

AddFriendWidget::AddFriendWidget(QString friendpixmapDir, QString id, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddFriendWidget),id(id),name(name),friendpixmapDir(friendpixmapDir)
{

    ui->setupUi(this);

    ui->FindEdit->move(145,50);
    ui->FindButton->move(475,55);

}

AddFriendWidget::~AddFriendWidget()
{
    delete ui;
}

void AddFriendWidget::GetFindReslute(QJsonArray array)
{
    qDebug()<<"AddFriendWidget::GetFindReslute(QJsonArray array)";
    //传回来 id name 头像

    if(array.size()==1)
    {
        QMessageBox::information(this,"提示","该用户不存在！");
        return;
    }


    QString id=array.at(1).toString();
    qDebug()<<"id:"<<id;
    QString name=array.at(2).toString();
    qDebug()<<"name:"<<name;
    QString filepath=array.at(3).toString();

    afindReslute*reslute=new afindReslute(id,name,filepath,this);
    qDebug()<<"reslutesize"<<reslute->size();
    connect(reslute,&afindReslute::addthisfriend,this,&AddFriendWidget::AddThisFriend);
    if(x<4)
        reslute->move(40+x*220,130);
    else
        reslute->move(40+(x/4)*220,330);
    ++x;
    reslute->show();
}

void AddFriendWidget::on_FindButton_clicked()
{
    qDebug()<<" AddFriendWidget::on_FindButton_clicked()";
    QString findId=ui->FindEdit->text();
    if(findId.isEmpty())
        return;
    qDebug()<<findId;
    emit FindFriend(findId);
}

void AddFriendWidget::AddThisFriend(QString friendid)
{
    QString pixpath=friendpixmapDir+id+".png";
    qDebug()<<pixpath;
    QFile file(pixpath);
    file.open(QFile::ReadOnly);
    QByteArray bytes=file.readAll();
    qDebug()<<bytes.size();
    file.close();
    QString pixstr=bytes.toBase64();
    qDebug()<<pixstr;
    qDebug()<<"AddFriendWidget::AddThisFriend(QString toid)"<<friendid;
    QString time=QTime::currentTime().toString();
    QJsonArray array;
    array.push_back("addfriendrequest");
    array.push_back(id);
    array.push_back(friendid);
    array.push_back(name);
    array.push_back(pixstr);
    array.push_back(time);
    emit addaFriend(friendid,array);
}

