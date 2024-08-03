#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QObject>

class Myserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Myserver(QObject *parent = nullptr);
signals:
    void TheHandle(qintptr handle);
    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle) override;
};


#endif // MYSERVER_H
