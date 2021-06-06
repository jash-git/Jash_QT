/********************************************************************************
** Form generated from reading UI file 'SetScaleDlg.ui'
**
** Created: Sat Dec 11 18:48:09 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSCALEDLG_H
#define UI_SETSCALEDLG_H

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

class Ui_SetScaleDlg
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *SetScaleDlg)
    {
        if (SetScaleDlg->objectName().isEmpty())
            SetScaleDlg->setObjectName(QString::fromUtf8("SetScaleDlg"));
        SetScaleDlg->resize(295, 45);
        pushButton = new QPushButton(SetScaleDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 10, 98, 27));
        lineEdit = new QLineEdit(SetScaleDlg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 113, 27));
        label = new QLabel(SetScaleDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 67, 17));

        retranslateUi(SetScaleDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), SetScaleDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(SetScaleDlg);
    } // setupUi

    void retranslateUi(QDialog *SetScaleDlg)
    {
        SetScaleDlg->setWindowTitle(QApplication::translate("SetScaleDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SetScaleDlg", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetScaleDlg", "\347\270\256\346\224\276\346\257\224\344\276\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetScaleDlg: public Ui_SetScaleDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSCALEDLG_H
