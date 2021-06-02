/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created: Mon Oct 13 11:41:57 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWebView *webView00;
    QWebView *webView01;
    QLabel *label;
    QLineEdit *lineEdit00;
    QLineEdit *lineEdit01;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit02;
    QLabel *label_4;
    QLineEdit *lineEdit03;
    QLabel *label_5;
    QLineEdit *lineEdit04;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(433, 300);
        webView00 = new QWebView(Form);
        webView00->setObjectName(QString::fromUtf8("webView00"));
        webView00->setGeometry(QRect(0, 100, 211, 201));
        webView00->setUrl(QUrl(QString::fromUtf8("about:blank")));
        webView01 = new QWebView(Form);
        webView01->setObjectName(QString::fromUtf8("webView01"));
        webView01->setGeometry(QRect(220, 100, 211, 201));
        webView01->setUrl(QUrl(QString::fromUtf8("about:blank")));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 62, 18));
        lineEdit00 = new QLineEdit(Form);
        lineEdit00->setObjectName(QString::fromUtf8("lineEdit00"));
        lineEdit00->setGeometry(QRect(80, 0, 351, 26));
        lineEdit01 = new QLineEdit(Form);
        lineEdit01->setObjectName(QString::fromUtf8("lineEdit01"));
        lineEdit01->setGeometry(QRect(80, 30, 113, 26));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 71, 18));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 30, 101, 21));
        lineEdit02 = new QLineEdit(Form);
        lineEdit02->setObjectName(QString::fromUtf8("lineEdit02"));
        lineEdit02->setGeometry(QRect(320, 30, 113, 26));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 60, 62, 18));
        lineEdit03 = new QLineEdit(Form);
        lineEdit03->setObjectName(QString::fromUtf8("lineEdit03"));
        lineEdit03->setGeometry(QRect(80, 60, 113, 26));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 60, 101, 18));
        lineEdit04 = new QLineEdit(Form);
        lineEdit04->setObjectName(QString::fromUtf8("lineEdit04"));
        lineEdit04->setGeometry(QRect(320, 60, 113, 26));

        retranslateUi(Form);
        QObject::connect(webView00, SIGNAL(loadFinished(bool)), Form, SLOT(slotReadNodeList()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "NowNewstoH264-IP=19 (12\347\211\210)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Step \347\213\200\346\205\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "\350\275\211\346\252\224\347\270\275\346\257\224\346\225\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "\347\233\256\345\211\215\345\206\215\350\275\211\347\254\254\345\271\276\347\255\206", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "UID", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "WMV FileName", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
