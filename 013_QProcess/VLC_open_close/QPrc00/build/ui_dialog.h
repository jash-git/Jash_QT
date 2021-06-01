/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Aug 16 21:17:35 2012
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushRun;
    QPushButton *pushClose;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(229, 65);
        pushRun = new QPushButton(Dialog);
        pushRun->setObjectName(QString::fromUtf8("pushRun"));
        pushRun->setGeometry(QRect(0, 20, 98, 27));
        pushClose = new QPushButton(Dialog);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setGeometry(QRect(120, 20, 98, 27));

        retranslateUi(Dialog);
        QObject::connect(pushClose, SIGNAL(clicked()), Dialog, SLOT(slotClose()));
        QObject::connect(pushRun, SIGNAL(clicked()), Dialog, SLOT(slotRun()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushRun->setText(QApplication::translate("Dialog", "Run", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("Dialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
