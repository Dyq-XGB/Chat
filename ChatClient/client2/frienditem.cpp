#include "frienditem.h"
#include "ui_frienditem.h"

Frienditem::Frienditem(QString friendid,QString friendname,QString pixpath,QWidget *parent) :
    QWidget(parent),friendid(friendid),friendname(friendname),
    ui(new Ui::Frienditem)
{
    ui->setupUi(this);

    ui->message->setScaledContents(true);

    ui->headshot->setPixmap(QPixmap(pixpath).scaled(ui->headshot->size()));

    QString idandname=friendname+"("+friendid+")";

    ui->nickname->setText(idandname);
    ui->message->setText("我的好友");

    ui->headshot->move(5,5);
    ui->nickname->move(55,5);
    ui->message->move(55,30);
}

Frienditem::~Frienditem()
{
    delete ui;
}
