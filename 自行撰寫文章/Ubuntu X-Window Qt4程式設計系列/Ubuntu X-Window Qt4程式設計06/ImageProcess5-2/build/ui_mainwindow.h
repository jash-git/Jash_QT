/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Oct 24 16:28:35 2010
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *OpenFile;
    QAction *Close;
    QAction *Gray;
    QAction *Source;
    QAction *FixedThreshold;
    QAction *OTSUThreshold;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 388);
        OpenFile = new QAction(MainWindow);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        Close = new QAction(MainWindow);
        Close->setObjectName(QString::fromUtf8("Close"));
        Gray = new QAction(MainWindow);
        Gray->setObjectName(QString::fromUtf8("Gray"));
        Source = new QAction(MainWindow);
        Source->setObjectName(QString::fromUtf8("Source"));
        FixedThreshold = new QAction(MainWindow);
        FixedThreshold->setObjectName(QString::fromUtf8("FixedThreshold"));
        OTSUThreshold = new QAction(MainWindow);
        OTSUThreshold->setObjectName(QString::fromUtf8("OTSUThreshold"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(OpenFile);
        menu->addAction(Close);
        menu_2->addAction(Source);
        menu_2->addAction(Gray);
        menu_2->addAction(FixedThreshold);
        menu_2->addAction(OTSUThreshold);

        retranslateUi(MainWindow);
        QObject::connect(OpenFile, SIGNAL(activated()), MainWindow, SLOT(slotOpenFile()));
        QObject::connect(Close, SIGNAL(activated()), MainWindow, SLOT(slotClose()));
        QObject::connect(Gray, SIGNAL(activated()), MainWindow, SLOT(slotGray()));
        QObject::connect(Source, SIGNAL(activated()), MainWindow, SLOT(slotSource()));
        QObject::connect(FixedThreshold, SIGNAL(activated()), MainWindow, SLOT(slotFixedThreshold()));
        QObject::connect(OTSUThreshold, SIGNAL(activated()), MainWindow, SLOT(slotOTSUThreshold()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        OpenFile->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\350\210\212\346\252\224", 0, QApplication::UnicodeUTF8));
        Close->setText(QApplication::translate("MainWindow", "\351\227\234\351\226\211\347\250\213\345\274\217", 0, QApplication::UnicodeUTF8));
        Gray->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216\350\275\211\346\217\233", 0, QApplication::UnicodeUTF8));
        Source->setText(QApplication::translate("MainWindow", "\351\241\257\347\244\272\345\216\237\345\234\226", 0, QApplication::UnicodeUTF8));
        FixedThreshold->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\210\345\233\272\345\256\232\351\226\200\351\226\245\345\200\274\357\274\211", 0, QApplication::UnicodeUTF8));
        OTSUThreshold->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\210OTSU\357\274\211", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\252\224\346\241\210", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\237\272\347\244\216\351\201\213\347\256\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
