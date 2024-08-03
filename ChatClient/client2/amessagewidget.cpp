#include "amessagewidget.h"
#include "ui_amessagewidget.h"

#include <QEvent>
#include <QSize>
#include <QFileDialog>
#include <QJsonArray>
#include <QSize>
#include <QDesktopServices>
aMessagewidget::aMessagewidget(QString pixpath, QString message, QString time, int side, QWidget *parent) ://普通消息
    QWidget(parent),
    ui(new Ui::aMessagewidget)
{
    ui->setupUi(this);
    ui->message->installEventFilter(this);

    qDebug()<<"aMessage";

    ui->message->setText(message);
    ui->message->setWordWrap(true);
    ui->message->adjustSize();

    qDebug()<<ui->message->size();
    QSize size=ui->message->size();
    qDebug()<<"QSize size=ui->message->size()"<<size;

    int h=size.height();

    ui->time->setText(time);

    QPixmap headshot(pixpath);
    ui->headshot->setPixmap(headshot);

    resize(width(),70+h);


    T="amessage";

    ui->time->move(355,10);
    if(side==0)
    {
        ui->headshot->move(15,40);
        ui->message->move(75,65);
    }
    else if(side==1)
    {
        ui->headshot->move(width()-15-50,40);
        ui->message->move(width()-75-ui->message->width(),70);
    }
}

aMessagewidget::aMessagewidget(QString pixpath, QString type, QString filename, double filesize,
                               QString key, QString state, QString time, int side, QWidget *parent) ://waitget
    QWidget(parent),state(state),Key(key),filepath(filename),
    ui(new Ui::aMessagewidget)
{
    ui->setupUi(this);
    ui->message->setAlignment(Qt::AlignCenter);
    ui->message->installEventFilter(this);
    ui->time->setScaledContents(true);

    T=type;

    qDebug()<<"aWaitGetfile";
    QString con=filename+"+"+key+"+"+QString::number(filesize);
    QSize size(160,60);

    ui->message->resize(size);
    ui->message->setText(con);

    int h=size.height();

    ui->time->setText(time);

    QPixmap headshot(pixpath);
    ui->headshot->setPixmap(headshot);

    resize(width(),70+h);

    ui->time->move(355,10);
    if(side==0)
    {
    ui->headshot->move(15,40);
    ui->message->move(75,65);
    }
    else if(side==1)
    {
    ui->headshot->move(width()-15-50,40);
    ui->message->move(width()-75-ui->message->width(),70);
    }
}

aMessagewidget::aMessagewidget(QString pixpath, QString type, QString filepath, QString state, QString time, int side, QWidget *parent)://Sending
    QWidget(parent),T(type),state(state),filepath(filepath),
    ui(new Ui::aMessagewidget)
{
    qDebug()<<"state:"<<state<<"type:"<<type;
    ui->setupUi(this);
    ui->message->setAlignment(Qt::AlignCenter);
    ui->message->installEventFilter(this);

    ui->time->setScaledContents(true);


    QFileInfo info(filepath);
    QString filename=info.fileName();
    double filesize=info.size();
    QString con=filename+"+"+QString::number(filesize);
    QSize size(160,60);
    ui->message->resize(size);
    ui->message->setText(con);


    int h=size.height();

    ui->time->setText(time);

    QPixmap headshot(pixpath);
    ui->headshot->setPixmap(headshot);

    resize(width(),70+h);

    ui->time->move(355,10);
    if(side==0)
    {
    ui->headshot->move(15,40);
    ui->message->move(75,65);
    }
    else if(side==1)
    {
    ui->headshot->move(width()-15-50,40);
    ui->message->move(width()-75-ui->message->width(),70);
    }
}



aMessagewidget::aMessagewidget(QString pixpath, QString type, QString filepath, QString time, int side, QWidget *parent)://图片
    QWidget(parent),T(type),filepath(filepath),
    ui(new Ui::aMessagewidget)
{
    ui->setupUi(this);
    ui->message->installEventFilter(this);
    ui->time->setScaledContents(true);
    ui->message->setAlignment(Qt::AlignCenter);


    qDebug()<<"Pix";

    qDebug()<<1;
    QPixmap pixmap(filepath);
    QSize size=pixmap.size();
    int w=size.width();
    int h=size.height();

    int maxw=ui->message->maximumWidth();
    int maxh=ui->message->maximumHeight();

    if(w>maxw||h>maxh)
    {
    int rate;
    if(w>h)
    {
        rate=w/maxw;
        pixmap=pixmap.scaled(w,h*rate);
    }
    else if(h>w||h==w)
    {
        rate=h/maxh;
        pixmap.scaled(w*rate,h);
    }
    }

    ui->message->resize(pixmap.size());

    ui->message->setPixmap(pixmap.scaled(ui->message->size()));

    QPixmap headshot(pixpath);
    ui->headshot->setPixmap(headshot);

    resize(width(),70+h);
    qDebug()<<6;
    ui->time->setText(time);

    ui->time->move(355,10);
    if(side==0)
    {
    ui->headshot->move(15,40);
    ui->message->move(75,65);
    }
    else if(side==1)
    {
    ui->headshot->move(width()-15-50,40);
    ui->message->move(width()-75-ui->message->width(),70);
    }
}


aMessagewidget::~aMessagewidget()
{
    qDebug()<<"aMessagewidget::~aMessagewidget()";
    delete ui;
}

void aMessagewidget::GetFileSuccess()
{
    qDebug()<<"GetFileSuccess()";
    state="haveGet";
}

void aMessagewidget::GetFileFaile()
{
    qDebug()<<"GetFileFaile";
}

void aMessagewidget::Getasize(int size)
{
    qDebug()<<"Getasize(int size)"<<size;
}

void aMessagewidget::SendFileSuccess(QString key)
{
    qDebug()<<"SendFileSuccess()"<<key;
    state="haveSend";
    Key=key;
    emit SendaFileok(Key,filepath);
}

void aMessagewidget::SendFileFaile()
{
    qDebug()<<"SendFileFaile()";
}

void aMessagewidget::Sendasize(int size)
{
    qDebug()<<"Sendasize(int size)"<<size;
}


bool aMessagewidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched->objectName()==ui->message->objectName())
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            if(T=="amessage")
            {
                qDebug()<<"amessage";
            }
            else if(T=="afile")
            {
                if(state=="waitGet")//没有接收的文件都是waitGet
                {
                    QString savedir=QFileDialog::getExistingDirectory(nullptr,"选择保存文件路径");
                    QString savepath=savedir+"/"+filepath;
                    filepath=savepath;
                    qDebug()<<filepath;
                    emit GetaFile(filepath,Key,this);
                }
                else if(state=="waitSend")//比如用户已经在发送三个或以上文件时，则需要等待
                {
                    //暂时不处理
                    qDebug()<<"踢出等待发送队列";
                }
                else if(state=="haveSend"||state=="haveGet")//已经接收完或接收完
                {
                    //打开
                    qDebug()<<state;
                    QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
                }
                else if(state=="Getting")
                {
                    //取消接收
                qDebug()<<"取消接受";
                emit stopGetfile();
                }
                else if(state=="Sending")
                {
                    //取消发送
                qDebug()<<"取消发送";
                emit stopSendfile();
                }
            }
            else if(T=="apix")
            {
                //放大图片
                qDebug()<<"T==apix";
                QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
            }
        }
    }
    return false;
}

