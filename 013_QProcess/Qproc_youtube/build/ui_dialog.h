/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Fri Feb 15 13:15:30 2013
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pb_Download;
    QLineEdit *line_Input;
    QLabel *label;
    QLabel *lab_Data;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        pb_Download = new QPushButton(Dialog);
        pb_Download->setObjectName(QString::fromUtf8("pb_Download"));
        pb_Download->setGeometry(QRect(310, 40, 85, 27));
        line_Input = new QLineEdit(Dialog);
        line_Input->setObjectName(QString::fromUtf8("line_Input"));
        line_Input->setGeometry(QRect(0, 10, 391, 25));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 70, 71, 16));
        lab_Data = new QLabel(Dialog);
        lab_Data->setObjectName(QString::fromUtf8("lab_Data"));
        lab_Data->setGeometry(QRect(30, 90, 351, 191));

        retranslateUi(Dialog);
        QObject::connect(pb_Download, SIGNAL(clicked()), Dialog, SLOT(slotDownload()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pb_Download->setText(QApplication::translate("Dialog", "Download", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "output info:", 0, QApplication::UnicodeUTF8));
        lab_Data->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
