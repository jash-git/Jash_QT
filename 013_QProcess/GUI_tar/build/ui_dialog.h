/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Aug 23 09:22:48 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *lab_source;
    QPushButton *pushsource;
    QLabel *label_2;
    QLabel *lab_target;
    QPushButton *pushtarget;
    QPushButton *pushRun;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 114);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 81, 16));
        lab_source = new QLabel(Dialog);
        lab_source->setObjectName(QString::fromUtf8("lab_source"));
        lab_source->setGeometry(QRect(90, 10, 211, 16));
        pushsource = new QPushButton(Dialog);
        pushsource->setObjectName(QString::fromUtf8("pushsource"));
        pushsource->setGeometry(QRect(310, 10, 85, 27));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 50, 81, 16));
        lab_target = new QLabel(Dialog);
        lab_target->setObjectName(QString::fromUtf8("lab_target"));
        lab_target->setGeometry(QRect(90, 50, 211, 16));
        pushtarget = new QPushButton(Dialog);
        pushtarget->setObjectName(QString::fromUtf8("pushtarget"));
        pushtarget->setGeometry(QRect(310, 50, 85, 27));
        pushRun = new QPushButton(Dialog);
        pushRun->setObjectName(QString::fromUtf8("pushRun"));
        pushRun->setGeometry(QRect(130, 80, 85, 27));

        retranslateUi(Dialog);
        QObject::connect(pushsource, SIGNAL(clicked()), Dialog, SLOT(slotsource()));
        QObject::connect(pushtarget, SIGNAL(clicked()), Dialog, SLOT(slottarget()));
        QObject::connect(pushRun, SIGNAL(clicked()), Dialog, SLOT(slotRun()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "GUI_tar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "source folder", 0, QApplication::UnicodeUTF8));
        lab_source->setText(QString());
        pushsource->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "target folder", 0, QApplication::UnicodeUTF8));
        lab_target->setText(QString());
        pushtarget->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        pushRun->setText(QApplication::translate("Dialog", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
