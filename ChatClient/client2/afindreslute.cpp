#include "afindreslute.h"
#include "ui_afindreslute.h"

#include <QLabel>
#include <QPushButton>

afindReslute::afindReslute(QString id,QString name,QString path,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::afindReslute)
{
    qDebug()<<"afindReslute::afindReslute(QString id,QString name,QString path,QWidget *parent) :";
    ui->setupUi(this);

    resize(180,130);

    QPixmap pixmap(path);

    ui->label->move(20,20);
    ui->id->move(90,55);
    ui->name->move(90,25);
    ui->pushButton->move(30,100);

    ui->label->setPixmap(pixmap.scaled(ui->label->size()));
    ui->id->setText(id);
    ui->name->setText(name);
}

afindReslute::~afindReslute()
{
    delete ui;
}

void afindReslute::on_pushButton_clicked()
{
    qDebug()<<"afindReslute::on_pushButton_clicked()";
    QString friendid=ui->id->text();
    qDebug()<<friendid;
    emit addthisfriend(friendid);
}

