/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Aug 18 14:02:43 2010
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
    QAction *toHistgram;
    QAction *toThresh;
    QAction *toDynamicThresh;
    QAction *toR;
    QAction *toG;
    QAction *toB;
    QAction *toGradient;
    QAction *toLaplacian;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
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
        toHistgram = new QAction(MainWindow);
        toHistgram->setObjectName(QString::fromUtf8("toHistgram"));
        toThresh = new QAction(MainWindow);
        toThresh->setObjectName(QString::fromUtf8("toThresh"));
        toDynamicThresh = new QAction(MainWindow);
        toDynamicThresh->setObjectName(QString::fromUtf8("toDynamicThresh"));
        toR = new QAction(MainWindow);
        toR->setObjectName(QString::fromUtf8("toR"));
        toG = new QAction(MainWindow);
        toG->setObjectName(QString::fromUtf8("toG"));
        toB = new QAction(MainWindow);
        toB->setObjectName(QString::fromUtf8("toB"));
        toGradient = new QAction(MainWindow);
        toGradient->setObjectName(QString::fromUtf8("toGradient"));
        toLaplacian = new QAction(MainWindow);
        toLaplacian->setObjectName(QString::fromUtf8("toLaplacian"));
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
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        FileToolBar = new QToolBar(MainWindow);
        FileToolBar->setObjectName(QString::fromUtf8("FileToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, FileToolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(OpenFile);
        menu->addAction(Close);
        menu_2->addAction(toGray);
        menu_2->addAction(toHistgram);
        menu_2->addAction(toThresh);
        menu_2->addAction(toDynamicThresh);
        menu_2->addAction(toR);
        menu_2->addAction(toG);
        menu_2->addAction(toB);
        menu_3->addAction(toGradient);
        menu_3->addAction(toLaplacian);
        FileToolBar->addAction(OpenFile);
        FileToolBar->addAction(toGray);

        retranslateUi(MainWindow);
        QObject::connect(OpenFile, SIGNAL(activated()), MainWindow, SLOT(slotOpenFile()));
        QObject::connect(Close, SIGNAL(activated()), MainWindow, SLOT(slotClose()));
        QObject::connect(toGray, SIGNAL(activated()), MainWindow, SLOT(slotGray()));
        QObject::connect(toHistgram, SIGNAL(activated()), MainWindow, SLOT(slotHistgram()));
        QObject::connect(toThresh, SIGNAL(activated()), MainWindow, SLOT(slotThresh()));
        QObject::connect(toDynamicThresh, SIGNAL(activated()), MainWindow, SLOT(slotDockWidget()));
        QObject::connect(toB, SIGNAL(activated()), MainWindow, SLOT(slotImB()));
        QObject::connect(toG, SIGNAL(activated()), MainWindow, SLOT(slotImG()));
        QObject::connect(toR, SIGNAL(activated()), MainWindow, SLOT(slotImR()));
        QObject::connect(toGradient, SIGNAL(activated()), MainWindow, SLOT(slotGradient()));
        QObject::connect(toLaplacian, SIGNAL(activated()), MainWindow, SLOT(slotLaplacian()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        OpenFile->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\350\210\212\346\252\224", 0, QApplication::UnicodeUTF8));
        Close->setText(QApplication::translate("MainWindow", "\351\227\234\351\226\211\347\250\213\345\274\217", 0, QApplication::UnicodeUTF8));
        toGray->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216", 0, QApplication::UnicodeUTF8));
        toHistgram->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\234\226", 0, QApplication::UnicodeUTF8));
        toThresh->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226", 0, QApplication::UnicodeUTF8));
        toDynamicThresh->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\210\345\213\225\346\205\213\350\252\277\346\225\264\357\274\211", 0, QApplication::UnicodeUTF8));
        toR->setText(QApplication::translate("MainWindow", "\347\264\224R", 0, QApplication::UnicodeUTF8));
        toG->setText(QApplication::translate("MainWindow", "\347\264\224G", 0, QApplication::UnicodeUTF8));
        toB->setText(QApplication::translate("MainWindow", "\347\264\224B", 0, QApplication::UnicodeUTF8));
        toGradient->setText(QApplication::translate("MainWindow", "\346\242\257\345\272\246\351\201\213\347\256\227", 0, QApplication::UnicodeUTF8));
        toLaplacian->setText(QApplication::translate("MainWindow", "\346\213\211\346\231\256\345\225\246\346\226\257\351\201\213\347\256\227", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\252\224\346\241\210", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\267\250\350\274\257", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\202\212\347\267\243\346\252\242\346\270\254", 0, QApplication::UnicodeUTF8));
        FileToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
