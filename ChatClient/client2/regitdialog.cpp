#include "regitdialog.h"
#include "ui_regitdialog.h"

#include <QEvent>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>

RegitDialog::RegitDialog(QHostAddress Serverip, QString SavepixDir, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegitDialog),SavepixDir(SavepixDir)
{
    ui->setupUi(this);
    qRegisterMetaType<QUdpSocket::SocketError>("SocketError");
    udp=new QUdpSocket();
    udp->setSocketOption(QAbstractSocket::KeepAliveOption,1);
    udp->bind(port);
    qDebug()<<udp->localAddress();
    connect(udp,&QUdpSocket::readyRead,this,&RegitDialog::GetId);
    connect(udp,&QUdpSocket::errorOccurred,this,[=](QUdpSocket::SocketError error){qDebug()<<error;});
    serverip=Serverip;

    ui->headshot->installEventFilter(this);
}

RegitDialog::~RegitDialog()
{
    delete ui;
    udp->close();
    delete udp;
    qDebug()<<"~RegitDialog()";
}

void RegitDialog::on_pushButton_clicked()
{
    QString Password=ui->lineEdit->text();
    QString nickname=ui->nickname->text();
    if(Password.isEmpty()||nickname.isEmpty()||havesavepath.isEmpty())
    {
        QMessageBox::warning(this,"警告","请填满信息");
        return;
    }
    QFile file(havesavepath);
    file.open(QFile::ReadOnly);
    QByteArray pixbytes=file.readAll();
    //qDebug()<<pixbytes;
    file.close();
    QString pix=QString(pixbytes.toBase64());
    //qDebug()<<pix;
    QJsonArray array;
    array.push_back(nickname);
    array.push_back(Password);
    array.push_back(pix);

    QJsonDocument doc(array);
    QByteArray bytes=doc.toJson();
    qDebug()<<bytes.size();
    qDebug()<<udp->writeDatagram(bytes,serverip,regitport);
    udp->flush();
}

void RegitDialog::GetId()
{
    qDebug()<<" RegitDialog::GetId()";
    QByteArray Id;
    Id.resize(udp->pendingDatagramSize());
    udp->readDatagram(Id.data(),Id.size());
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText(QString(Id));
    qDebug()<<"id:"<<Id;
}


void RegitDialog::on_pushButton_2_clicked()
{
    this->accept();
}

bool RegitDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched->objectName()==ui->headshot->objectName())
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QString pixpath=QFileDialog::getOpenFileName(nullptr,"选择一张头像",QString(),"*.jpg;;*.png");
            if(!pixpath.isEmpty())
            {
                QPixmap pix=QPixmap(pixpath).scaled(ui->headshot->size());
                ui->headshot->setPixmap(pix);
                QString time=QTime::currentTime().toString().remove(':');
                havesavepath=SavepixDir+time+".png";
                QFile file(havesavepath);
                file.open(QFile::WriteOnly);
                qDebug()<<pix.save(havesavepath);
                file.close();
            }
        }
    }
    return false;
}
