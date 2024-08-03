#ifndef AFINDRESLUTE_H
#define AFINDRESLUTE_H

#include <QWidget>

namespace Ui {
class afindReslute;
}

class afindReslute : public QWidget
{
    Q_OBJECT

public:
    explicit afindReslute(QString id,QString name,QString path,QWidget *parent = nullptr);
    ~afindReslute();
signals:
    void addthisfriend(QString id);
private slots:
    void on_pushButton_clicked();

private:
    Ui::afindReslute *ui;
};

#endif // AFINDRESLUTE_H
