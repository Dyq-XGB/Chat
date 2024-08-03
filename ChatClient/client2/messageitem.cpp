#include "messageitem.h"
#include "ui_messageitem.h"

#include <QResizeEvent>
#include <QPixmap>
#include <QTime>
#include <QResizeEvent>
#include <QJsonArray>

MessageItem::MessageItem(QString friendid, QString name, QString pixpath, QJsonArray *messagerecord, QWidget *parent)
    : QWidget(parent),friendid(friendid),name(name),messagerecord(messagerecord)
    , ui(new Ui::MessageItem)
{
    ui->setupUi(this);

    ui->message->setScaledContents(true);

    ui->headshot->setPixmap(QPixmap(pixpath).scaled(ui->headshot->size()));

    ui->nickname->setText(name);

    QString message;
    QString time;

    if(!messagerecord->isEmpty())
    {
        QJsonArray lastarray=messagerecord->last().toArray();

        QString lastmessagetype=lastarray.at(0).toString();

        if(lastmessagetype=="afile")
            message="[文件]";
        else if(lastmessagetype=="apix")
            message="[图片]";
        else
            message=lastarray.at(3).toString();

        time=lastarray.last().toString();
    }

    else
    {
        message="";
        time="";
    }

    ui->message->setText(message);
    ui->time->setText(time);

    ui->NotGetMessageNumber->setNum(number);

    ui->headshot->move(5,5);
    ui->nickname->move(55,5);
    ui->message->move(55,30);


    ui->time->move(this->width()-55,5);
    ui->NotGetMessageNumber->move(this->width()-55,30);
}

MessageItem::~MessageItem()
{
    delete ui;
    qDebug()<<"MessageItem::~MessageItem()";
}

void MessageItem::changelastmessage(QString lastmessage, QString lastmessagetime, bool chatwidgetIsexits)
{
    if(chatwidgetIsexits)
        number=0;
    else
        number+=1;
    ui->message->setText(lastmessage);
    ui->time->setText(lastmessagetime);
    ui->NotGetMessageNumber->setNum(number);
}

void MessageItem::changename(QString &name)
{
    ui->nickname->setText(name);
}

void MessageItem::clearNotSeemessage()
{
    number=0;
    ui->NotGetMessageNumber->setNum(number);
}

