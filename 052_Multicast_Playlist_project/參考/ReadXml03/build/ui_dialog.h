/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Tue May 25 11:13:02 2010
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButtReadNodeList;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        pushButtReadNodeList = new QPushButton(Dialog);
        pushButtReadNodeList->setObjectName(QString::fromUtf8("pushButtReadNodeList"));
        pushButtReadNodeList->setGeometry(QRect(0, 0, 161, 41));

        retranslateUi(Dialog);
        QObject::connect(pushButtReadNodeList, SIGNAL(clicked()), Dialog, SLOT(slotReadNodeList()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtReadNodeList->setText(QApplication::translate("Dialog", "Read NodeList", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
