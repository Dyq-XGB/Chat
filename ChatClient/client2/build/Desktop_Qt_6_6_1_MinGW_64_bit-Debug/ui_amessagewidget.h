/********************************************************************************
** Form generated from reading UI file 'amessagewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMESSAGEWIDGET_H
#define UI_AMESSAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aMessagewidget
{
public:
    QLabel *headshot;
    QLabel *time;
    QLabel *message;

    void setupUi(QWidget *aMessagewidget)
    {
        if (aMessagewidget->objectName().isEmpty())
            aMessagewidget->setObjectName("aMessagewidget");
        aMessagewidget->resize(730, 358);
        aMessagewidget->setMinimumSize(QSize(730, 110));
        aMessagewidget->setMaximumSize(QSize(730, 16777215));
        headshot = new QLabel(aMessagewidget);
        headshot->setObjectName("headshot");
        headshot->setGeometry(QRect(10, 40, 50, 50));
        headshot->setMinimumSize(QSize(50, 50));
        headshot->setMaximumSize(QSize(50, 50));
        headshot->setFrameShape(QFrame::Box);
        time = new QLabel(aMessagewidget);
        time->setObjectName("time");
        time->setGeometry(QRect(300, 10, 120, 20));
        time->setMinimumSize(QSize(0, 0));
        time->setMaximumSize(QSize(16777215, 16777215));
        time->setFrameShape(QFrame::NoFrame);
        time->setAlignment(Qt::AlignCenter);
        message = new QLabel(aMessagewidget);
        message->setObjectName("message");
        message->setGeometry(QRect(70, 70, 61, 20));
        message->setMinimumSize(QSize(60, 20));
        message->setMaximumSize(QSize(240, 270));
        message->setFrameShape(QFrame::StyledPanel);

        retranslateUi(aMessagewidget);

        QMetaObject::connectSlotsByName(aMessagewidget);
    } // setupUi

    void retranslateUi(QWidget *aMessagewidget)
    {
        aMessagewidget->setWindowTitle(QCoreApplication::translate("aMessagewidget", "Form", nullptr));
        headshot->setText(QCoreApplication::translate("aMessagewidget", "\345\244\264\345\203\217", nullptr));
        time->setText(QCoreApplication::translate("aMessagewidget", "\346\227\266\351\227\264", nullptr));
        message->setText(QCoreApplication::translate("aMessagewidget", "\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aMessagewidget: public Ui_aMessagewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMESSAGEWIDGET_H
