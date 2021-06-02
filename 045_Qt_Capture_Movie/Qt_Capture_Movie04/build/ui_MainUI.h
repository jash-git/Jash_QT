/********************************************************************************
** Form generated from reading UI file 'MainUI.ui'
**
** Created: Sat Feb 18 17:39:10 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QPushButton *ButCapture01;
    QPushButton *ButVideo;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(251, 48);
        ButCapture01 = new QPushButton(MainForm);
        ButCapture01->setObjectName(QString::fromUtf8("ButCapture01"));
        ButCapture01->setGeometry(QRect(0, 10, 131, 27));
        ButVideo = new QPushButton(MainForm);
        ButVideo->setObjectName(QString::fromUtf8("ButVideo"));
        ButVideo->setGeometry(QRect(150, 10, 98, 27));

        retranslateUi(MainForm);
        QObject::connect(ButCapture01, SIGNAL(clicked()), MainForm, SLOT(slotCapture01()));
        QObject::connect(ButVideo, SIGNAL(clicked()), MainForm, SLOT(slotVideo()));

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "JL_Make Movie", 0, QApplication::UnicodeUTF8));
        ButCapture01->setText(QApplication::translate("MainForm", "Capture a image", 0, QApplication::UnicodeUTF8));
        ButVideo->setText(QApplication::translate("MainForm", "Start Video", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
