/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Aug 1 13:08:06 2010
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
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *OpenFile;
    QAction *Close;
    QAction *toGray;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *FileToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 388);
        OpenFile = new QAction(MainWindow);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/OpenFile/icon/OpenFile.PNG")), QIcon::Normal, QIcon::Off);
        OpenFile->setIcon(icon);
        Close = new QAction(MainWindow);
        Close->setObjectName(QString::fromUtf8("Close"));
        toGray = new QAction(MainWindow);
        toGray->setObjectName(QString::fromUtf8("toGray"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/Gray/icon/Gray.PNG")), QIcon::Normal, QIcon::Off);
        toGray->setIcon(icon1);
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
        FileToolBar = new QToolBar(MainWindow);
        FileToolBar->setObjectName(QString::fromUtf8("FileToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, FileToolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(OpenFile);
        menu->addAction(Close);
        menu_2->addAction(toGray);
        FileToolBar->addAction(OpenFile);
        FileToolBar->addAction(toGray);

        retranslateUi(MainWindow);
        QObject::connect(OpenFile, SIGNAL(activated()), MainWindow, SLOT(slotOpenFile()));
        QObject::connect(Close, SIGNAL(activated()), MainWindow, SLOT(slotClose()));
        QObject::connect(toGray, SIGNAL(activated()), MainWindow, SLOT(slotGray()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        OpenFile->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\350\210\212\346\252\224", 0, QApplication::UnicodeUTF8));
        Close->setText(QApplication::translate("MainWindow", "\351\227\234\351\226\211\347\250\213\345\274\217", 0, QApplication::UnicodeUTF8));
        toGray->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\252\224\346\241\210", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\267\250\350\274\257", 0, QApplication::UnicodeUTF8));
        FileToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
