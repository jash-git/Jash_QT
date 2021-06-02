/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Sat May 7 19:46:03 2011
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *InsertButton;
    QLabel *label;
    QComboBox *comboYear;
    QLabel *label_2;
    QComboBox *comboMonth;
    QLabel *label_3;
    QComboBox *comboDay;
    QLabel *label_4;
    QComboBox *comboHour;
    QLabel *label_5;
    QComboBox *comboMinute;
    QLineEdit *lineEditNote;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboSwitch;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(721, 419);
        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 121, 711, 291));
        InsertButton = new QPushButton(Dialog);
        InsertButton->setObjectName(QString::fromUtf8("InsertButton"));
        InsertButton->setGeometry(QRect(0, 80, 98, 27));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 51, 17));
        comboYear = new QComboBox(Dialog);
        comboYear->setObjectName(QString::fromUtf8("comboYear"));
        comboYear->setGeometry(QRect(50, 0, 85, 27));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 0, 61, 21));
        comboMonth = new QComboBox(Dialog);
        comboMonth->setObjectName(QString::fromUtf8("comboMonth"));
        comboMonth->setGeometry(QRect(200, 0, 85, 27));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 0, 51, 21));
        comboDay = new QComboBox(Dialog);
        comboDay->setObjectName(QString::fromUtf8("comboDay"));
        comboDay->setGeometry(QRect(340, 0, 85, 27));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 0, 51, 21));
        comboHour = new QComboBox(Dialog);
        comboHour->setObjectName(QString::fromUtf8("comboHour"));
        comboHour->setGeometry(QRect(480, 0, 85, 27));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(570, 0, 61, 21));
        comboMinute = new QComboBox(Dialog);
        comboMinute->setObjectName(QString::fromUtf8("comboMinute"));
        comboMinute->setGeometry(QRect(630, 0, 85, 27));
        lineEditNote = new QLineEdit(Dialog);
        lineEditNote->setObjectName(QString::fromUtf8("lineEditNote"));
        lineEditNote->setGeometry(QRect(50, 40, 511, 27));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 40, 51, 17));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(570, 40, 61, 21));
        comboSwitch = new QComboBox(Dialog);
        comboSwitch->setObjectName(QString::fromUtf8("comboSwitch"));
        comboSwitch->setGeometry(QRect(630, 40, 85, 27));

        retranslateUi(Dialog);
        QObject::connect(InsertButton, SIGNAL(clicked()), Dialog, SLOT(slotInsertData()));
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), Dialog, SLOT(slotSelectData(int,int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "JL_calendar", 0, QApplication::UnicodeUTF8));
        InsertButton->setText(QApplication::translate("Dialog", "Insert Data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Year:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Month:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Day:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Hour:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "Minute:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "Note:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "Switch:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
