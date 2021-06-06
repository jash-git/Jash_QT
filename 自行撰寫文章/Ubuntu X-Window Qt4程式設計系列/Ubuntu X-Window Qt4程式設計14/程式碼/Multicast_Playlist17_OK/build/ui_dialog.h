/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Sep 13 15:22:06 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *line_PlayListUrl;
    QLineEdit *line_LiveMulticastUrl;
    QLabel *lab_PlayListUrl;
    QLabel *lab_LiveMulticastUrl;
    QLabel *lab_MulticastPar01;
    QLineEdit *line_MulticastPar01;
    QLabel *lab_MulticastPar02;
    QLineEdit *line_MulticastPar02;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QLabel *lab_Date;
    QLabel *lab_Time;
    QGroupBox *groupBox_2;
    QLabel *lab_AfterTime;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(699, 452);
        line_PlayListUrl = new QLineEdit(Dialog);
        line_PlayListUrl->setObjectName(QString::fromUtf8("line_PlayListUrl"));
        line_PlayListUrl->setGeometry(QRect(140, 10, 391, 27));
        line_LiveMulticastUrl = new QLineEdit(Dialog);
        line_LiveMulticastUrl->setObjectName(QString::fromUtf8("line_LiveMulticastUrl"));
        line_LiveMulticastUrl->setGeometry(QRect(140, 50, 391, 27));
        lab_PlayListUrl = new QLabel(Dialog);
        lab_PlayListUrl->setObjectName(QString::fromUtf8("lab_PlayListUrl"));
        lab_PlayListUrl->setGeometry(QRect(10, 10, 121, 20));
        lab_LiveMulticastUrl = new QLabel(Dialog);
        lab_LiveMulticastUrl->setObjectName(QString::fromUtf8("lab_LiveMulticastUrl"));
        lab_LiveMulticastUrl->setGeometry(QRect(10, 50, 111, 21));
        lab_MulticastPar01 = new QLabel(Dialog);
        lab_MulticastPar01->setObjectName(QString::fromUtf8("lab_MulticastPar01"));
        lab_MulticastPar01->setGeometry(QRect(10, 90, 111, 21));
        line_MulticastPar01 = new QLineEdit(Dialog);
        line_MulticastPar01->setObjectName(QString::fromUtf8("line_MulticastPar01"));
        line_MulticastPar01->setGeometry(QRect(140, 90, 391, 27));
        lab_MulticastPar02 = new QLabel(Dialog);
        lab_MulticastPar02->setObjectName(QString::fromUtf8("lab_MulticastPar02"));
        lab_MulticastPar02->setGeometry(QRect(10, 130, 111, 21));
        line_MulticastPar02 = new QLineEdit(Dialog);
        line_MulticastPar02->setObjectName(QString::fromUtf8("line_MulticastPar02"));
        line_MulticastPar02->setGeometry(QRect(140, 130, 391, 27));
        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 160, 681, 281));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(530, 0, 171, 80));
        lab_Date = new QLabel(groupBox);
        lab_Date->setObjectName(QString::fromUtf8("lab_Date"));
        lab_Date->setGeometry(QRect(0, 20, 141, 21));
        lab_Time = new QLabel(groupBox);
        lab_Time->setObjectName(QString::fromUtf8("lab_Time"));
        lab_Time->setGeometry(QRect(0, 50, 151, 21));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(530, 80, 161, 80));
        lab_AfterTime = new QLabel(groupBox_2);
        lab_AfterTime->setObjectName(QString::fromUtf8("lab_AfterTime"));
        lab_AfterTime->setGeometry(QRect(10, 30, 121, 17));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lab_PlayListUrl->setText(QApplication::translate("Dialog", "PlayListUrl", 0, QApplication::UnicodeUTF8));
        lab_LiveMulticastUrl->setText(QApplication::translate("Dialog", "LiveMulticastUrl", 0, QApplication::UnicodeUTF8));
        lab_MulticastPar01->setText(QApplication::translate("Dialog", "MulticastPar01", 0, QApplication::UnicodeUTF8));
        lab_MulticastPar02->setText(QApplication::translate("Dialog", "MulticastPar02", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "now time", 0, QApplication::UnicodeUTF8));
        lab_Date->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        lab_Time->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog", "next time", 0, QApplication::UnicodeUTF8));
        lab_AfterTime->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
