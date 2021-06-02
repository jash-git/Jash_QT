/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Thu Aug 5 22:04:05 2010
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
    QPushButton *createButton;
    QPushButton *runButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(206, 36);
        createButton = new QPushButton(Dialog);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(0, 0, 92, 28));
        runButton = new QPushButton(Dialog);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setGeometry(QRect(100, 0, 92, 28));

        retranslateUi(Dialog);
        QObject::connect(createButton, SIGNAL(clicked()), Dialog, SLOT(slotCreate()));
        QObject::connect(runButton, SIGNAL(clicked()), Dialog, SLOT(slotRun()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        createButton->setText(QApplication::translate("Dialog", "Create Bash", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("Dialog", "Run Bash", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
