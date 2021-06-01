/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Mon May 17 13:02:28 2010
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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEditFile;
    QLabel *label;
    QPushButton *pushButSelect;
    QPushButton *pushButAdd;
    QListWidget *listWidgetFile;
    QPushButton *pushButExe;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 345);
        lineEditFile = new QLineEdit(Dialog);
        lineEditFile->setObjectName(QString::fromUtf8("lineEditFile"));
        lineEditFile->setGeometry(QRect(70, 20, 321, 26));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 62, 18));
        pushButSelect = new QPushButton(Dialog);
        pushButSelect->setObjectName(QString::fromUtf8("pushButSelect"));
        pushButSelect->setGeometry(QRect(10, 50, 92, 28));
        pushButAdd = new QPushButton(Dialog);
        pushButAdd->setObjectName(QString::fromUtf8("pushButAdd"));
        pushButAdd->setGeometry(QRect(120, 50, 92, 28));
        listWidgetFile = new QListWidget(Dialog);
        listWidgetFile->setObjectName(QString::fromUtf8("listWidgetFile"));
        listWidgetFile->setGeometry(QRect(10, 80, 381, 211));
        pushButExe = new QPushButton(Dialog);
        pushButExe->setObjectName(QString::fromUtf8("pushButExe"));
        pushButExe->setGeometry(QRect(290, 300, 92, 28));

        retranslateUi(Dialog);
        QObject::connect(pushButSelect, SIGNAL(clicked()), Dialog, SLOT(slotSelect()));
        QObject::connect(pushButAdd, SIGNAL(clicked()), Dialog, SLOT(slotAdd()));
        QObject::connect(pushButExe, SIGNAL(clicked()), Dialog, SLOT(slotExe()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "FilePath:", 0, QApplication::UnicodeUTF8));
        pushButSelect->setText(QApplication::translate("Dialog", "Select File", 0, QApplication::UnicodeUTF8));
        pushButAdd->setText(QApplication::translate("Dialog", "Add File", 0, QApplication::UnicodeUTF8));
        pushButExe->setText(QApplication::translate("Dialog", "Exe", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
