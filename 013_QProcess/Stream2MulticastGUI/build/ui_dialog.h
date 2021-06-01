/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Jul 23 14:24:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
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
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QTextEdit *Edit_Url;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *EditBitRate1;
    QTextEdit *EditBitRate2;
    QLabel *label_4;
    QPushButton *ButtonRunStop;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 137);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 21));
        Edit_Url = new QTextEdit(Dialog);
        Edit_Url->setObjectName(QString::fromUtf8("Edit_Url"));
        Edit_Url->setGeometry(QRect(80, 10, 311, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 71, 21));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 40, 71, 21));
        EditBitRate1 = new QTextEdit(Dialog);
        EditBitRate1->setObjectName(QString::fromUtf8("EditBitRate1"));
        EditBitRate1->setGeometry(QRect(80, 40, 104, 21));
        EditBitRate2 = new QTextEdit(Dialog);
        EditBitRate2->setObjectName(QString::fromUtf8("EditBitRate2"));
        EditBitRate2->setGeometry(QRect(270, 40, 104, 21));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 371, 17));
        ButtonRunStop = new QPushButton(Dialog);
        ButtonRunStop->setObjectName(QString::fromUtf8("ButtonRunStop"));
        ButtonRunStop->setGeometry(QRect(14, 100, 361, 27));

        retranslateUi(Dialog);
        QObject::connect(ButtonRunStop, SIGNAL(clicked()), Dialog, SLOT(slotRunStop()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Stream2MulticastGUI", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "stream url:", 0, QApplication::UnicodeUTF8));
        Edit_Url->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">http://192.168.200.93/live/ftv_900k.stream/playlist.m3u8?pf=monitor</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "bitrate1 (k):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "bitrate2 (k):", 0, QApplication::UnicodeUTF8));
        EditBitRate1->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">900</p></body></html>", 0, QApplication::UnicodeUTF8));
        EditBitRate2->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">450</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Multicast IP : 224.8.8.135 ;; Multicast port : 13511,13521", 0, QApplication::UnicodeUTF8));
        ButtonRunStop->setText(QApplication::translate("Dialog", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
