/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Fri Mar 12 13:47:15 2010
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
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushLogin;
    QPushButton *pushPutFile;
    QWebView *webView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(276, 243);
        pushLogin = new QPushButton(Dialog);
        pushLogin->setObjectName(QString::fromUtf8("pushLogin"));
        pushLogin->setGeometry(QRect(0, 20, 92, 28));
        pushPutFile = new QPushButton(Dialog);
        pushPutFile->setObjectName(QString::fromUtf8("pushPutFile"));
        pushPutFile->setGeometry(QRect(120, 20, 92, 28));
        webView = new QWebView(Dialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(0, 50, 271, 181));
        webView->setUrl(QUrl("about:blank"));

        retranslateUi(Dialog);
        QObject::connect(pushLogin, SIGNAL(clicked()), Dialog, SLOT(slotLogin()));
        QObject::connect(pushPutFile, SIGNAL(clicked()), Dialog, SLOT(slotPut()));
        QObject::connect(webView, SIGNAL(loadFinished(bool)), Dialog, SLOT(slotwebloaded(bool)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushLogin->setText(QApplication::translate("Dialog", "Login", 0, QApplication::UnicodeUTF8));
        pushPutFile->setText(QApplication::translate("Dialog", "Put File", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
