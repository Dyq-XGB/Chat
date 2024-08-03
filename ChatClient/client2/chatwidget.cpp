#include "chatwidget.h"
#include "qlistwidget.h"
#include "ui_chatwidget.h"

#include <QJsonArray>
#include <QFileDialog>
#include <QCloseEvent>

//里面的消息右边是自己，左边是friend  左0，右1
ChatWidget::ChatWidget(QString friendpixmap,QString SavepixDir,QString SavefileDir,QString fid, QString friendname, QString myid, QJsonArray *array, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget),myid(myid),friendid(fid),friendpixmap(friendpixmap),SavepixDir(SavepixDir),SavefileDir(SavefileDir)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    friendpixpath=friendpixmap+fid+".png";
    mypixpath=friendpixmap+myid+".png";


    ui->friendid->move(25,10);
    ui->listWidget->move(25,40);
    ui->InputMessage->move(175,510);
    ui->file->move(95,510);
    ui->pixmap->move(95,550);
    ui->send->move(630,620);

    ui->friendid->setText(friendname+"("+friendid+")");
    allmessagewidget=new QVector<aMessagewidget*>();
    QJsonArray::Iterator x=array->begin();
    QJsonArray  amessage;
    while(x!=array->end())
    {
        amessage=x->toArray();

        QString type=amessage.at(0).toString();
        qDebug()<<"type:"<<type;
        QString friendid=amessage.at(1).toString();

        QString pixpath;
        int side=friendid==myid?1:0;
        if(side==1)
            pixpath=mypixpath;
        else
            pixpath=friendpixpath;

        QString time=amessage.last().toString();
        if(type=="amessage")
        {
            QString message=amessage.at(3).toString();
            CreateAMessageWidget(message,side,time);
        }
        else if(type=="afile")
        {
            QString filekey=amessage.at(3).toString();
            QString filename=amessage.at(4).toString();
            double filesize=amessage.at(5).toDouble();
            CreateAWaitGetFileWidget(filename,filesize,filekey,time,side);
        }
        else if(type=="apix")
        {
            QString t=time.remove(':');
            QString suffix=amessage.at(4).toString();
            QString savepath=SavepixDir+t+suffix;
            CreateAPixWidget(savepath,time,side);
        }
        ++x;
    }
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

//void ChatWidget::GetaMessage(QString message,QString time)
//{
//    qDebug()<<"ChatWidget::GetaMessage(QJsonArray *amessage)";
//    CreateAMessageWidget(friendpixpath,message,0,time);
//}

//void ChatWidget::GetaFile(QString key,double filesize,QString filename,QString time)
//{
//    qDebug()<<"ChatWidget::GetaFile(QString friendid,QString key,double filesize,QString filename,QString time)";
//    CreateAWaitGetFileWidget(friendpixpath,filename,filesize,key,time,0);
//}

//void ChatWidget::GetaPixmap(QString pixsavepath,QString time)
//{
//    qDebug()<<"ChatWidget::GetaPixmap(QString pixsavepath,QString time)";
//    CreateAPixWidget(friendpixpath,pixsavepath,time,0);
//}

void ChatWidget::on_send_clicked()
{
    QString message=ui->InputMessage->toPlainText();
    ui->InputMessage->clear();
    if(message.isEmpty())
        return;

    QString time=QTime::currentTime().toString();
    qDebug()<<"ChatWidget::on_send_clicked()";
    QJsonArray amessage;
    amessage.push_back(aMessage);
    amessage.push_back(myid);
    amessage.push_back(friendid);
    amessage.push_back(message);
    amessage.push_back(time);
    emit SendaMessage(friendid,amessage);

    CreateAMessageWidget(message,1,time);
}


void ChatWidget::on_file_clicked()
{
    QString filepath=QFileDialog::getOpenFileName(this,"选择需要发送的文件",nullptr,"*.*;;*.text;;*.word;;*.jpg;;.png");
    if(filepath.isEmpty())
        return;
    QString time=QTime::currentTime().toString();
    qDebug()<<"ChatWidget::on_file_clicked()";
    CreateASendFileWidget(filepath,time,1);
}


void ChatWidget::on_pixmap_clicked()
{
    QString filepath=QFileDialog::getOpenFileName(this,"选择需要发送的图片",nullptr,"*.*;;*.jpg;;.png");
    if(filepath.isEmpty())
        return;
    qDebug()<<"ChatWidget::on_pixmap_clicked()"<<filepath;
    QString time=QTime::currentTime().toString();
    QFile file(filepath);
    QFileInfo info(filepath);
    QString suffix=info.suffix();
    file.open(QFile::ReadOnly);
    QByteArray *bytes=new QByteArray(file.readAll());
    file.close();
    QString pix(bytes->toBase64());
    QJsonArray pixarray;
    pixarray.push_back(aPixmap);
    pixarray.push_back(myid);
    pixarray.push_back(friendid);
    pixarray.push_back(pix);
    pixarray.push_back(QString(".")+suffix);
    pixarray.push_back(time);

    CreateAPixWidget(filepath,time,1);
    emit SendaMessage(friendid,pixarray);
}

void ChatWidget::SendaFileOk(QString key, QString filepath)
{
    QString time=QTime::currentTime().toString();
    QFileInfo info(filepath);
    QString filename=info.fileName();
    double filesize=info.size();


    QJsonArray  filemessage;
    filemessage.push_back(aFile);
    filemessage.push_back(myid);
    filemessage.push_back(friendid);
    filemessage.push_back(key);
    filemessage.push_back(filename);
    filemessage.push_back(filesize);
    filemessage.push_back(time);

    emit SendaMessage(friendid,filemessage);
}

void ChatWidget::CreateAMessageWidget(QString message,int side,QString time)
{
    QString pixpath;
    if(side==0)
        pixpath=friendpixpath;
    else
        pixpath=mypixpath;
    aMessagewidget*awidget=new aMessagewidget(pixpath,message,time,side);
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(awidget->maximumSize().width(),awidget->height()));
    ui->listWidget->setItemWidget(item,awidget);
    allmessagewidget->push_back(awidget);
}

void ChatWidget::CreateASendFileWidget(QString filepath,QString time,int side)
{
    QString pixpath;
    if(side==0)
        pixpath=friendpixpath;
    else
        pixpath=mypixpath;
    QString state="Sending";
    aMessagewidget*awidget=new aMessagewidget(pixpath,aFile,filepath,state,time,side);
    connect(awidget,&aMessagewidget::SendaFileok,this,&ChatWidget::SendaFileOk);

    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(awidget->maximumSize().width(),200));
    ui->listWidget->setItemWidget(item,awidget);
    allmessagewidget->push_back(awidget);

    emit SendaFile(filepath,awidget);
}



void ChatWidget::CreateAWaitGetFileWidget(QString filename, double filesize, QString filekey,QString time,int side)
{
    qDebug()<<"ChatWidget::CreateAWaitGetFileWidget(QString filename, double filesize, QString filekey,QString time,int side)";
    QString pixpath;
    if(side==0)
        pixpath=friendpixpath;
    else
        pixpath=mypixpath;
    QString state="waitGet";
    aMessagewidget*awidget=new aMessagewidget(pixpath,aFile,filename,filesize,filekey,state,time,side);
    connect(awidget,&aMessagewidget::GetaFile,this,&ChatWidget::GetaFile);
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(awidget->maximumSize().width(),200));
    ui->listWidget->setItemWidget(item,awidget);
    allmessagewidget->push_back(awidget);
}

void ChatWidget::CreateAPixWidget(QString filepath, QString time,int side)
{
    QString pixpath;
    if(side==0)
        pixpath=friendpixpath;
    else
        pixpath=mypixpath;
    qDebug()<<"CreateAPixWidget(QString filepath)";
    aMessagewidget*awidget=new aMessagewidget(pixpath,aPixmap,filepath,time,side);
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(awidget->size());
    ui->listWidget->setItemWidget(item,awidget);
    allmessagewidget->push_back(awidget);
}



void ChatWidget::closeEvent(QCloseEvent *event)
{
    qDebug()<<"ChatWidget::closeEvent(QCloseEvent *event)";
    emit HaveDelete(friendid);
    QWidget::closeEvent(event);
}
