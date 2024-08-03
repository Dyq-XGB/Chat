#ifndef ALLWORKER_H
#define ALLWORKER_H

#include "connecttoserver.h"
#include "dealfile.h"
#include "dealmessage.h"
#include "pasuremessage.h"
#include <QApplication>
#include <QObject>
#include <QFileInfo>

class AllWorker : public QObject
{
    Q_OBJECT
public:
    explicit AllWorker(QHostAddress Serverip, QString AllFileDir, QString AllpixDir, QString friendpixmaDir, QString allUserinfoDir,
                       QString id, unsigned short port, int Loginkey, QObject *parent = nullptr);
    ~AllWorker();

public slots:
    void DeleteAll();
    void StartDelete();
private slots:
    void on_startwork();
signals:
    void startwork();
    void hadDeleteAll();
    void startPasure(QString id);

signals:
    void saveAllinfo();
    void sendInfoToserver();
public:
    QString id;
    QHostAddress serverip;

    ConnectToServer*con;
    QThread* t_con;

    PasureMessage*pasure;
    QThread* p_t;

    DealFile*file;
    QThread*t_f;

    DealMessage*message;
    QThread*m_t;


    QString AllFileDir;
    QString AllpixDir;
    QString friendpixmaDir;
    QString allUserinfoDir;
};

#endif // ALLWORKER_H
