#ifndef DEALUSERCONNECT_H
#define DEALUSERCONNECT_H

#include "myserver.h"
#include <QObject>
#include <QTcpServer>
#include <QUdpSocket>
class DealUserConnect : public QObject
{
    Q_OBJECT
public:
    explicit DealUserConnect(QObject *parent = nullptr);
    virtual ~DealUserConnect();
public slots:
    void startwork(QHostAddress ip);
private slots:
    void aUserConnect(qintptr handle);
signals:
    void TheConnectHandle(qintptr handle);
    void aRequest(QByteArray bytes);

    void saveThisinfo(QString info);
private:
    unsigned short Port=8888;
    Myserver*server;
};

#endif // DEALUSERCONNECT_H
