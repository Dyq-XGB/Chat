/********************************************************************************
** Form generated from reading UI file 'afindreslute.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFINDRESLUTE_H
#define UI_AFINDRESLUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afindReslute
{
public:
    QLabel *label;
    QLabel *name;
    QLabel *id;
    QPushButton *pushButton;

    void setupUi(QWidget *afindReslute)
    {
        if (afindReslute->objectName().isEmpty())
            afindReslute->setObjectName("afindReslute");
        afindReslute->resize(180, 130);
        afindReslute->setMinimumSize(QSize(180, 130));
        afindReslute->setMaximumSize(QSize(180, 130));
        label = new QLabel(afindReslute);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 60, 60));
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 60));
        label->setAlignment(Qt::AlignCenter);
        name = new QLabel(afindReslute);
        name->setObjectName("name");
        name->setGeometry(QRect(90, 10, 80, 20));
        name->setMinimumSize(QSize(80, 20));
        name->setMaximumSize(QSize(80, 20));
        name->setFrameShape(QFrame::Box);
        id = new QLabel(afindReslute);
        id->setObjectName("id");
        id->setGeometry(QRect(90, 40, 80, 20));
        id->setMinimumSize(QSize(80, 20));
        id->setMaximumSize(QSize(80, 20));
        id->setFrameShape(QFrame::Box);
        pushButton = new QPushButton(afindReslute);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 90, 80, 20));
        pushButton->setMinimumSize(QSize(80, 20));
        pushButton->setMaximumSize(QSize(80, 20));

        retranslateUi(afindReslute);

        QMetaObject::connectSlotsByName(afindReslute);
    } // setupUi

    void retranslateUi(QWidget *afindReslute)
    {
        afindReslute->setWindowTitle(QCoreApplication::translate("afindReslute", "Form", nullptr));
        label->setText(QCoreApplication::translate("afindReslute", "\345\244\264\345\203\217", nullptr));
        name->setText(QCoreApplication::translate("afindReslute", "name", nullptr));
        id->setText(QCoreApplication::translate("afindReslute", "id", nullptr));
        pushButton->setText(QCoreApplication::translate("afindReslute", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class afindReslute: public Ui_afindReslute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFINDRESLUTE_H
