/********************************************************************************
** Form generated from reading UI file 'frienditem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frienditem
{
public:
    QLabel *message;
    QLabel *nickname;
    QLabel *headshot;

    void setupUi(QWidget *Frienditem)
    {
        if (Frienditem->objectName().isEmpty())
            Frienditem->setObjectName("Frienditem");
        Frienditem->resize(250, 60);
        Frienditem->setMinimumSize(QSize(250, 60));
        Frienditem->setMaximumSize(QSize(250, 60));
        message = new QLabel(Frienditem);
        message->setObjectName("message");
        message->setGeometry(QRect(80, 30, 190, 25));
        message->setMinimumSize(QSize(190, 25));
        message->setMaximumSize(QSize(190, 25));
        nickname = new QLabel(Frienditem);
        nickname->setObjectName("nickname");
        nickname->setGeometry(QRect(90, 10, 100, 25));
        nickname->setMinimumSize(QSize(100, 25));
        nickname->setMaximumSize(QSize(100, 25));
        headshot = new QLabel(Frienditem);
        headshot->setObjectName("headshot");
        headshot->setGeometry(QRect(10, 10, 50, 50));
        headshot->setMinimumSize(QSize(50, 50));
        headshot->setMaximumSize(QSize(50, 50));
        headshot->setAlignment(Qt::AlignCenter);

        retranslateUi(Frienditem);

        QMetaObject::connectSlotsByName(Frienditem);
    } // setupUi

    void retranslateUi(QWidget *Frienditem)
    {
        Frienditem->setWindowTitle(QCoreApplication::translate("Frienditem", "Form", nullptr));
        message->setText(QCoreApplication::translate("Frienditem", "\344\277\241\346\201\257", nullptr));
        nickname->setText(QCoreApplication::translate("Frienditem", "\346\230\265\347\247\260", nullptr));
        headshot->setText(QCoreApplication::translate("Frienditem", "\345\244\264\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frienditem: public Ui_Frienditem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
