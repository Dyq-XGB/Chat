#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
class ConnectToServer : public QObject
{
    Q_OBJECT
public:
    explicit ConnectToServer(QHostAddress Serverip, QString clientinfoDir, QString id, int loginkey, unsigned short port, QObject *parent = nullptr);
    virtual ~ConnectToServer();
public slots:
    void slot_startwork(bool NeedGetAllInfo);

    void SendAllinfotoServer();

    //void slots_TryGetInfoAgain();
signals:
    //void TryGetInfoAgain();
    void ConnectFaile();
    void ConnectSuccess();
    void sendOk();
    void PasureNotgetMessage(QByteArray bytes);
private:
    QString id;
    int loginkey;
    unsigned short port;
    QString clientInfoDir;

    unsigned short serverport=8888;
    QHostAddress serverip;

    QTcpSocket*tcp;

    int sendasize=4*1024;
};

#endif // CONNECTTOSERVER_H
