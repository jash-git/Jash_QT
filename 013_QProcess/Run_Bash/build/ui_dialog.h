/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Aug 15 09:42:17 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *lab01;
    QLabel *lab_old;
    QLabel *lab_now;
    QLabel *lab02;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(286, 76);
        lab01 = new QLabel(Dialog);
        lab01->setObjectName(QString::fromUtf8("lab01"));
        lab01->setGeometry(QRect(10, 10, 67, 17));
        lab_old = new QLabel(Dialog);
        lab_old->setObjectName(QString::fromUtf8("lab_old"));
        lab_old->setGeometry(QRect(90, 10, 181, 17));
        lab_now = new QLabel(Dialog);
        lab_now->setObjectName(QString::fromUtf8("lab_now"));
        lab_now->setGeometry(QRect(90, 40, 181, 17));
        lab02 = new QLabel(Dialog);
        lab02->setObjectName(QString::fromUtf8("lab02"));
        lab02->setGeometry(QRect(10, 40, 67, 17));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lab01->setText(QApplication::translate("Dialog", "old date", 0, QApplication::UnicodeUTF8));
        lab_old->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        lab_now->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        lab02->setText(QApplication::translate("Dialog", "now date", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
