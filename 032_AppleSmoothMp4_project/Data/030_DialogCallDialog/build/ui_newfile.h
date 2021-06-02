/********************************************************************************
** Form generated from reading ui file 'newfile.ui'
**
** Created: Wed Aug 4 22:18:01 2010
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEWFILE_H
#define UI_NEWFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog01
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog01)
    {
        if (Dialog01->objectName().isEmpty())
            Dialog01->setObjectName(QString::fromUtf8("Dialog01"));
        Dialog01->resize(247, 52);
        lineEdit = new QLineEdit(Dialog01);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 113, 26));
        pushButton = new QPushButton(Dialog01);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 10, 92, 28));

        retranslateUi(Dialog01);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog01, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog01);
    } // setupUi

    void retranslateUi(QDialog *Dialog01)
    {
        Dialog01->setWindowTitle(QApplication::translate("Dialog01", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog01", "PushButton", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog01);
    } // retranslateUi

};

namespace Ui {
    class Dialog01: public Ui_Dialog01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILE_H
