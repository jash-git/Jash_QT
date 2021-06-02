/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Fri May 6 17:04:16 2011
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
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *InsertButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 100, 391, 192));
        InsertButton = new QPushButton(Dialog);
        InsertButton->setObjectName(QString::fromUtf8("InsertButton"));
        InsertButton->setGeometry(QRect(50, 60, 98, 27));

        retranslateUi(Dialog);
        QObject::connect(InsertButton, SIGNAL(clicked()), Dialog, SLOT(slotInsertData()));
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), Dialog, SLOT(slotSelectData(int,int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "JL_calendar", 0, QApplication::UnicodeUTF8));
        InsertButton->setText(QApplication::translate("Dialog", "Insert Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
