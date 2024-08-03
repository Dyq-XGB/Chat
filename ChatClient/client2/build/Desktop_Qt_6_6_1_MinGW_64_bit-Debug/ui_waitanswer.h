/********************************************************************************
** Form generated from reading UI file 'waitanswer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITANSWER_H
#define UI_WAITANSWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitAnswer
{
public:
    QLabel *pix;
    QLabel *name;
    QLabel *id;
    QPushButton *ok;
    QLabel *time;

    void setupUi(QWidget *WaitAnswer)
    {
        if (WaitAnswer->objectName().isEmpty())
            WaitAnswer->setObjectName("WaitAnswer");
        WaitAnswer->resize(250, 140);
        WaitAnswer->setMinimumSize(QSize(250, 140));
        WaitAnswer->setMaximumSize(QSize(250, 140));
        pix = new QLabel(WaitAnswer);
        pix->setObjectName("pix");
        pix->setGeometry(QRect(40, 40, 60, 60));
        pix->setMinimumSize(QSize(60, 60));
        pix->setMaximumSize(QSize(60, 60));
        pix->setFrameShape(QFrame::Box);
        pix->setAlignment(Qt::AlignCenter);
        name = new QLabel(WaitAnswer);
        name->setObjectName("name");
        name->setGeometry(QRect(110, 40, 80, 25));
        name->setMinimumSize(QSize(80, 25));
        name->setMaximumSize(QSize(80, 25));
        name->setFrameShape(QFrame::Box);
        name->setAlignment(Qt::AlignCenter);
        id = new QLabel(WaitAnswer);
        id->setObjectName("id");
        id->setGeometry(QRect(110, 70, 80, 25));
        id->setMinimumSize(QSize(80, 25));
        id->setFrameShape(QFrame::Box);
        id->setAlignment(Qt::AlignCenter);
        ok = new QPushButton(WaitAnswer);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(80, 110, 80, 25));
        ok->setMinimumSize(QSize(80, 25));
        ok->setMaximumSize(QSize(80, 25));
        time = new QLabel(WaitAnswer);
        time->setObjectName("time");
        time->setGeometry(QRect(60, 10, 120, 15));
        time->setAlignment(Qt::AlignCenter);

        retranslateUi(WaitAnswer);

        QMetaObject::connectSlotsByName(WaitAnswer);
    } // setupUi

    void retranslateUi(QWidget *WaitAnswer)
    {
        WaitAnswer->setWindowTitle(QCoreApplication::translate("WaitAnswer", "Form", nullptr));
        pix->setText(QCoreApplication::translate("WaitAnswer", "\345\244\264\345\203\217", nullptr));
        name->setText(QCoreApplication::translate("WaitAnswer", "name", nullptr));
        id->setText(QCoreApplication::translate("WaitAnswer", "id", nullptr));
        ok->setText(QCoreApplication::translate("WaitAnswer", "\346\216\245\345\217\227", nullptr));
        time->setText(QCoreApplication::translate("WaitAnswer", "\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitAnswer: public Ui_WaitAnswer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITANSWER_H
