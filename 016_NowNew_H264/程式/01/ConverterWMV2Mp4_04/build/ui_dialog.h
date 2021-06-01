/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Tue Mar 9 14:42:39 2010
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
    QLineEdit *lineEdit01;
    QLineEdit *lineEdit02;
    QLineEdit *lineEdit03;
    QLineEdit *lineEdit04;
    QLineEdit *lineEdit05;
    QLineEdit *lineEdit06;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_7;
    QLineEdit *lineEdit07;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(503, 300);
        lineEdit01 = new QLineEdit(Dialog);
        lineEdit01->setObjectName(QString::fromUtf8("lineEdit01"));
        lineEdit01->setGeometry(QRect(80, 10, 411, 26));
        lineEdit02 = new QLineEdit(Dialog);
        lineEdit02->setObjectName(QString::fromUtf8("lineEdit02"));
        lineEdit02->setGeometry(QRect(80, 40, 411, 26));
        lineEdit03 = new QLineEdit(Dialog);
        lineEdit03->setObjectName(QString::fromUtf8("lineEdit03"));
        lineEdit03->setGeometry(QRect(80, 70, 411, 26));
        lineEdit04 = new QLineEdit(Dialog);
        lineEdit04->setObjectName(QString::fromUtf8("lineEdit04"));
        lineEdit04->setGeometry(QRect(80, 100, 411, 26));
        lineEdit05 = new QLineEdit(Dialog);
        lineEdit05->setObjectName(QString::fromUtf8("lineEdit05"));
        lineEdit05->setGeometry(QRect(80, 130, 411, 26));
        lineEdit06 = new QLineEdit(Dialog);
        lineEdit06->setObjectName(QString::fromUtf8("lineEdit06"));
        lineEdit06->setGeometry(QRect(80, 160, 411, 26));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 62, 18));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 40, 62, 18));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 70, 62, 18));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 100, 62, 18));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 130, 62, 18));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 160, 62, 18));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 240, 92, 28));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 190, 62, 18));
        lineEdit07 = new QLineEdit(Dialog);
        lineEdit07->setObjectName(QString::fromUtf8("lineEdit07"));
        lineEdit07->setGeometry(QRect(80, 190, 61, 26));

        retranslateUi(Dialog);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog, SLOT(slot1()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\347\233\256\345\211\215\347\233\256\351\214\204", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "\350\275\211\346\252\224\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "\345\217\226\345\276\227\346\270\205\345\226\256", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "\346\270\205\345\226\256\345\220\215\347\250\261", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "\344\276\206\346\272\220\350\267\257\345\276\221", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "\350\274\270\345\207\272\350\267\257\345\276\221", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "\345\267\262\350\275\211\347\255\206\346\225\270", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
