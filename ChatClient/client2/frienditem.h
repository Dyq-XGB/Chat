#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>

namespace Ui {
class Frienditem;
}

class Frienditem : public QWidget
{
    Q_OBJECT

public:
    explicit Frienditem(QString friendid, QString friendname, QString pixpath, QWidget *parent = nullptr);
    ~Frienditem();


    QString friendid;
    QString friendname;
private:

    Ui::Frienditem *ui;
};

#endif // FRIENDITEM_H
