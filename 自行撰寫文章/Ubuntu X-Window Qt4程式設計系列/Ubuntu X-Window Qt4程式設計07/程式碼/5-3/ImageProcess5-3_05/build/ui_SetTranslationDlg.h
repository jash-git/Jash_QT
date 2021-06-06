/********************************************************************************
** Form generated from reading UI file 'SetTranslationDlg.ui'
**
** Created: Sat Dec 11 18:48:09 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTRANSLATIONDLG_H
#define UI_SETTRANSLATIONDLG_H

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

class Ui_SetTranslationDlg
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLabel *label_2;

    void setupUi(QDialog *SetTranslationDlg)
    {
        if (SetTranslationDlg->objectName().isEmpty())
            SetTranslationDlg->setObjectName(QString::fromUtf8("SetTranslationDlg"));
        SetTranslationDlg->resize(328, 141);
        pushButton = new QPushButton(SetTranslationDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 110, 98, 27));
        label = new QLabel(SetTranslationDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 91, 17));
        lineEdit_1 = new QLineEdit(SetTranslationDlg);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(100, 20, 113, 27));
        lineEdit_2 = new QLineEdit(SetTranslationDlg);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 60, 113, 27));
        label_2 = new QLabel(SetTranslationDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 60, 91, 17));

        retranslateUi(SetTranslationDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), SetTranslationDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(SetTranslationDlg);
    } // setupUi

    void retranslateUi(QDialog *SetTranslationDlg)
    {
        SetTranslationDlg->setWindowTitle(QApplication::translate("SetTranslationDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SetTranslationDlg", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetTranslationDlg", "X\350\273\270\347\247\273\345\213\225\351\207\217 :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SetTranslationDlg", "Y\350\273\270\347\247\273\345\213\225\351\207\217 :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetTranslationDlg: public Ui_SetTranslationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTRANSLATIONDLG_H
