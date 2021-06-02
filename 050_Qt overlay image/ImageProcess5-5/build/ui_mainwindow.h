/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 17 14:36:25 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
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
    QAction *Histogram;
    QAction *Equalize_Gray;
    QAction *SaveFile;
    QAction *Translation;
    QAction *HorMirror;
    QAction *VerMirror;
    QAction *Transpose;
    QAction *Scale;
    QAction *Rotate;
    QAction *Sobel;
    QAction *Roberts;
    QAction *Laplacian;
    QAction *Prewitt;
    QAction *Thinning;
    QAction *Overlay_Image;
    QAction *Overlay_Text;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
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
        Histogram = new QAction(MainWindow);
        Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Equalize_Gray = new QAction(MainWindow);
        Equalize_Gray->setObjectName(QString::fromUtf8("Equalize_Gray"));
        SaveFile = new QAction(MainWindow);
        SaveFile->setObjectName(QString::fromUtf8("SaveFile"));
        Translation = new QAction(MainWindow);
        Translation->setObjectName(QString::fromUtf8("Translation"));
        HorMirror = new QAction(MainWindow);
        HorMirror->setObjectName(QString::fromUtf8("HorMirror"));
        VerMirror = new QAction(MainWindow);
        VerMirror->setObjectName(QString::fromUtf8("VerMirror"));
        Transpose = new QAction(MainWindow);
        Transpose->setObjectName(QString::fromUtf8("Transpose"));
        Scale = new QAction(MainWindow);
        Scale->setObjectName(QString::fromUtf8("Scale"));
        Rotate = new QAction(MainWindow);
        Rotate->setObjectName(QString::fromUtf8("Rotate"));
        Sobel = new QAction(MainWindow);
        Sobel->setObjectName(QString::fromUtf8("Sobel"));
        Roberts = new QAction(MainWindow);
        Roberts->setObjectName(QString::fromUtf8("Roberts"));
        Laplacian = new QAction(MainWindow);
        Laplacian->setObjectName(QString::fromUtf8("Laplacian"));
        Prewitt = new QAction(MainWindow);
        Prewitt->setObjectName(QString::fromUtf8("Prewitt"));
        Thinning = new QAction(MainWindow);
        Thinning->setObjectName(QString::fromUtf8("Thinning"));
        Overlay_Image = new QAction(MainWindow);
        Overlay_Image->setObjectName(QString::fromUtf8("Overlay_Image"));
        Overlay_Text = new QAction(MainWindow);
        Overlay_Text->setObjectName(QString::fromUtf8("Overlay_Text"));
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
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(OpenFile);
        menu->addAction(SaveFile);
        menu->addAction(Close);
        menu_2->addAction(Source);
        menu_2->addAction(Gray);
        menu_2->addAction(Histogram);
        menu_2->addAction(FixedThreshold);
        menu_2->addAction(OTSUThreshold);
        menu_2->addSeparator();
        menu_2->addAction(Equalize_Gray);
        menu_2->addAction(Overlay_Image);
        menu_2->addAction(Overlay_Text);
        menu_3->addAction(Translation);
        menu_3->addAction(HorMirror);
        menu_3->addAction(VerMirror);
        menu_3->addAction(Transpose);
        menu_3->addAction(Scale);
        menu_3->addAction(Rotate);
        menu_4->addAction(Sobel);
        menu_4->addAction(Roberts);
        menu_4->addAction(Laplacian);
        menu_4->addAction(Prewitt);
        menu_4->addSeparator();
        menu_4->addAction(Thinning);

        retranslateUi(MainWindow);
        QObject::connect(OpenFile, SIGNAL(activated()), MainWindow, SLOT(slotOpenFile()));
        QObject::connect(Close, SIGNAL(activated()), MainWindow, SLOT(slotClose()));
        QObject::connect(Gray, SIGNAL(activated()), MainWindow, SLOT(slotGray()));
        QObject::connect(Source, SIGNAL(activated()), MainWindow, SLOT(slotSource()));
        QObject::connect(FixedThreshold, SIGNAL(activated()), MainWindow, SLOT(slotFixedThreshold()));
        QObject::connect(OTSUThreshold, SIGNAL(activated()), MainWindow, SLOT(slotOTSUThreshold()));
        QObject::connect(Histogram, SIGNAL(activated()), MainWindow, SLOT(slotHistogram()));
        QObject::connect(Equalize_Gray, SIGNAL(activated()), MainWindow, SLOT(slotEqualize()));
        QObject::connect(SaveFile, SIGNAL(activated()), MainWindow, SLOT(slotSaveFile()));
        QObject::connect(Translation, SIGNAL(activated()), MainWindow, SLOT(slotTranslation()));
        QObject::connect(HorMirror, SIGNAL(activated()), MainWindow, SLOT(slotHorMirror()));
        QObject::connect(VerMirror, SIGNAL(activated()), MainWindow, SLOT(slotVerMirror()));
        QObject::connect(Transpose, SIGNAL(activated()), MainWindow, SLOT(slotTranspose()));
        QObject::connect(Scale, SIGNAL(activated()), MainWindow, SLOT(slotScale()));
        QObject::connect(Rotate, SIGNAL(activated()), MainWindow, SLOT(slotRotate()));
        QObject::connect(Sobel, SIGNAL(activated()), MainWindow, SLOT(slotSobel()));
        QObject::connect(Roberts, SIGNAL(activated()), MainWindow, SLOT(slotRoberts()));
        QObject::connect(Laplacian, SIGNAL(activated()), MainWindow, SLOT(slotLaplacian()));
        QObject::connect(Prewitt, SIGNAL(activated()), MainWindow, SLOT(slotPrewitt()));
        QObject::connect(Thinning, SIGNAL(activated()), MainWindow, SLOT(slotThinning()));
        QObject::connect(Overlay_Image, SIGNAL(activated()), MainWindow, SLOT(slotOverlayImage()));
        QObject::connect(Overlay_Text, SIGNAL(activated()), MainWindow, SLOT(slotOverlayText()));

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
        Histogram->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\234\226", 0, QApplication::UnicodeUTF8));
        Equalize_Gray->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216\345\235\207\345\214\226", 0, QApplication::UnicodeUTF8));
        SaveFile->setText(QApplication::translate("MainWindow", "\345\204\262\345\255\230\346\252\224\346\241\210", 0, QApplication::UnicodeUTF8));
        Translation->setText(QApplication::translate("MainWindow", "\345\234\226\345\275\242\347\247\273\345\213\225", 0, QApplication::UnicodeUTF8));
        HorMirror->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\277\273\350\275\211", 0, QApplication::UnicodeUTF8));
        VerMirror->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\211", 0, QApplication::UnicodeUTF8));
        Transpose->setText(QApplication::translate("MainWindow", "\345\234\226\345\275\242\350\275\211\347\275\256", 0, QApplication::UnicodeUTF8));
        Scale->setText(QApplication::translate("MainWindow", "\345\234\226\345\275\242\347\270\256\346\224\276", 0, QApplication::UnicodeUTF8));
        Rotate->setText(QApplication::translate("MainWindow", "\345\234\226\345\275\242\346\227\213\350\275\211", 0, QApplication::UnicodeUTF8));
        Sobel->setText(QApplication::translate("MainWindow", "Sobel", 0, QApplication::UnicodeUTF8));
        Roberts->setText(QApplication::translate("MainWindow", "Roberts", 0, QApplication::UnicodeUTF8));
        Laplacian->setText(QApplication::translate("MainWindow", "Laplacian", 0, QApplication::UnicodeUTF8));
        Prewitt->setText(QApplication::translate("MainWindow", "Prewitt", 0, QApplication::UnicodeUTF8));
        Thinning->setText(QApplication::translate("MainWindow", "\347\264\260\347\267\232\345\214\226", 0, QApplication::UnicodeUTF8));
        Overlay_Image->setText(QApplication::translate("MainWindow", "Overlay Image", 0, QApplication::UnicodeUTF8));
        Overlay_Text->setText(QApplication::translate("MainWindow", "Overlay Text", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\252\224\346\241\210", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\237\272\347\244\216\351\201\213\347\256\227", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\271\276\344\275\225\351\201\213\347\256\227", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\223\267\345\217\226\350\274\252\345\273\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
