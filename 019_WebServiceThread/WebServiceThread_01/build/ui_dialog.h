/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Mon Mar 15 22:39:04 2010
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWebView *webView;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        webView = new QWebView(Dialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(10, 10, 391, 201));
        webView->setUrl(QUrl("about:blank"));
        pushButton_1 = new QPushButton(Dialog);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 220, 92, 28));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 220, 92, 28));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 260, 113, 26));

        retranslateUi(Dialog);
        QObject::connect(pushButton_1, SIGNAL(clicked()), Dialog, SLOT(slot1()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog, SLOT(slot2()));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), Dialog, SLOT(slot3(QString)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
