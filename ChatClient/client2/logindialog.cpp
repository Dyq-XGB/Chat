#include "logindialog.h"
#include "ui_logindialog.h"
#include "regitdialog.h"

#include <QJsonArray>
#include <QJsonDocument>
LoginDialog::LoginDialog(QString savepixdir,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog),savepixdir(savepixdir)
{
    ui->setupUi(this);

    udp=new QUdpSocket();
    udp->bind(port);
    connect(udp,&QUdpSocket::readyRead,this,&LoginDialog::GetCheckReslute);
}

LoginDialog::~LoginDialog()
{
    qDebug()<<"~LoginDialog()";
    udp->close();
    delete udp;
    delete ui;
}

int LoginDialog::doLogin(QString &Id,unsigned short &Port,int&LoginKey,QHostAddress&Serverip)
{
    int reslute=exec();
    if(reslute==Accepted)
    {
        Id=id;
        Port=port;
        LoginKey=loginKey;
        Serverip=serverip;
        return 1;
    }
    else
    {
        return 0;
    }
}

void LoginDialog::on_Regit_clicked()
{
    serverip=QHostAddress(ui->serverIplineEdit->text());
    RegitDialog*regit=new RegitDialog(serverip,savepixdir);
    regit->exec();
    delete regit;
}


void LoginDialog::on_Login_clicked()
{
    id=ui->IdLineEdit->text();
    serverip=QHostAddress(ui->serverIplineEdit->text());
    QString password=ui->PasswordLineEdit->text();
    QJsonArray array;
    array.push_back(id);
    array.push_back(password);
    QJsonDocument doc(array);
    udp->writeDatagram(doc.toJson(),serverip,loginport);
    port=udp->localPort();
    udp->flush();
}

void LoginDialog::GetCheckReslute()
{
    qDebug()<<"LoginDialog::GetCheckReslute()";
    QByteArray reslute;
    reslute.resize(udp->pendingDatagramSize());
    udp->readDatagram(reslute.data(),reslute.size());
    int re=reslute.toInt();
    qDebug()<<"re:"<<re;
    if(re==-1)
        qDebug()<<"账号或密码错误！";
    else
    {
        loginKey=reslute.toInt();
        accept();
    }
}

