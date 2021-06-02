/********************************************************************************
** Form generated from reading ui file 'ThreshDialog.ui'
**
** Created: Tue Aug 17 10:49:56 2010
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_THRESHDIALOG_H
#define UI_THRESHDIALOG_H

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

class Ui_Dialog01
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog01)
    {
        if (Dialog01->objectName().isEmpty())
            Dialog01->setObjectName(QString::fromUtf8("Dialog01"));
        Dialog01->resize(303, 35);
        lineEdit = new QLineEdit(Dialog01);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 0, 113, 26));
        label = new QLabel(Dialog01);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 81, 21));
        pushButton = new QPushButton(Dialog01);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 0, 92, 28));

        retranslateUi(Dialog01);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog01, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog01);
    } // setupUi

    void retranslateUi(QDialog *Dialog01)
    {
        Dialog01->setWindowTitle(QApplication::translate("Dialog01", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog01", "\351\226\200\351\226\245\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog01", "\347\242\272\345\256\232", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog01);
    } // retranslateUi

};

namespace Ui {
    class Dialog01: public Ui_Dialog01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHDIALOG_H
