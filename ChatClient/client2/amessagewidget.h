#ifndef AMESSAGEWIDGET_H
#define AMESSAGEWIDGET_H

#include <QWidget>

namespace Ui {
class aMessagewidget;
}

class aMessagewidget : public QWidget
{
    Q_OBJECT
    //里面的消息右边是自己，左边是friend  左0，右1
public:
    explicit aMessagewidget(QString pixpath,QString message,QString time,int side,QWidget *parent = nullptr);//aMessage

    explicit aMessagewidget(QString pixpath,QString type, QString filepath,QString state,QString time,int side,QWidget *parent = nullptr);//sendfile



    explicit aMessagewidget(QString pixpath,QString type, QString filename,double filesize,
                            QString key,QString state,QString time,int side,QWidget *parent = nullptr);//getfile

    // 状态 waitGet  waitSend  haveSend  haveGet  Getting  Sending
    // aFile
    explicit aMessagewidget(QString pixpath,QString type,QString filepath,QString time,int side,QWidget *parent = nullptr);//pixmap

    ~aMessagewidget();
public slots:
    void GetFileSuccess();
    void GetFileFaile();
    void Getasize(int size);

    void SendFileSuccess(QString key);
    void SendFileFaile();
    void Sendasize(int size);

signals:
    void GetaFile(QString savefilepath,QString key,aMessagewidget*widget);
    void SendaFileok(QString key,QString filepath);


signals:
    void stopSendfile();
    void stopGetfile();

private:

    QString T;//消息只有这个


    QString state;  //waitGet  waitSend   Getting   Sending  haveSend  haveGet
    QString Key;

    double filesize;
    QString filepath;//文件全都有

    Ui::aMessagewidget *ui;
    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // AMESSAGEWIDGET_H
