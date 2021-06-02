/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Fri Aug 6 10:28:45 2010
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
    QPushButton *ansiButton;
    QPushButton *utf8Button;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(240, 62);
        ansiButton = new QPushButton(Dialog);
        ansiButton->setObjectName(QString::fromUtf8("ansiButton"));
        ansiButton->setGeometry(QRect(10, 20, 92, 28));
        utf8Button = new QPushButton(Dialog);
        utf8Button->setObjectName(QString::fromUtf8("utf8Button"));
        utf8Button->setGeometry(QRect(130, 20, 92, 28));

        retranslateUi(Dialog);
        QObject::connect(ansiButton, SIGNAL(clicked()), Dialog, SLOT(slotANSI()));
        QObject::connect(utf8Button, SIGNAL(clicked()), Dialog, SLOT(slotUTF8()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        ansiButton->setText(QApplication::translate("Dialog", "ANSI", 0, QApplication::UnicodeUTF8));
        utf8Button->setText(QApplication::translate("Dialog", "UTF-8", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
