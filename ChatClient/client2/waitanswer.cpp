#include "waitanswer.h"
#include "ui_waitanswer.h"

WaitAnswer::WaitAnswer(QString friendid,QString friendname,QString pixpath,QString time,QWidget *parent) :
    QWidget(parent),friendid(friendid),friendname(friendname), pixpath(pixpath),
    ui(new Ui::WaitAnswer)
{
    ui->setupUi(this);

    ui->time->move(65,10);
    ui->pix->move(45,35);
    ui->name->move(123,35);
    ui->id->move(125,70);
    ui->ok->move(85,105);

    ui->id->setText(friendid);
    ui->name->setText(friendname);
    ui->pix->setPixmap(QPixmap(pixpath).scaled(ui->pix->size()));
    ui->time->setText(time);
}

WaitAnswer::~WaitAnswer()
{
    delete ui;
}

void WaitAnswer::on_ok_clicked()
{
    ui->ok->setText("已接受");
    ui->ok->setDisabled(true);
    emit answerThisFriend(friendid,friendname,pixpath);
}

