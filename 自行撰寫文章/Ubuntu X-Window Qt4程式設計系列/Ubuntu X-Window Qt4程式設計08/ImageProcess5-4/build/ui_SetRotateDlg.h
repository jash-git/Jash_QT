/********************************************************************************
** Form generated from reading UI file 'SetRotateDlg.ui'
**
** Created: Sun Feb 6 17:29:39 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETROTATEDLG_H
#define UI_SETROTATEDLG_H

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

class Ui_SetRotateDlg
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SetRotateDlg)
    {
        if (SetRotateDlg->objectName().isEmpty())
            SetRotateDlg->setObjectName(QString::fromUtf8("SetRotateDlg"));
        SetRotateDlg->resize(289, 45);
        pushButton = new QPushButton(SetRotateDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 10, 98, 27));
        label = new QLabel(SetRotateDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 67, 17));
        lineEdit = new QLineEdit(SetRotateDlg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 113, 27));

        retranslateUi(SetRotateDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), SetRotateDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(SetRotateDlg);
    } // setupUi

    void retranslateUi(QDialog *SetRotateDlg)
    {
        SetRotateDlg->setWindowTitle(QApplication::translate("SetRotateDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SetRotateDlg", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetRotateDlg", "\346\227\213\350\275\211\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetRotateDlg: public Ui_SetRotateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETROTATEDLG_H
