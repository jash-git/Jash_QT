/********************************************************************************
** Form generated from reading UI file 'ShowHistogramDlg.ui'
**
** Created: Tue Dec 7 21:50:46 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWHISTOGRAMDLG_H
#define UI_SHOWHISTOGRAMDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ShowHistogram
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Min;
    QLineEdit *lineEdit_Max;

    void setupUi(QDialog *ShowHistogram)
    {
        if (ShowHistogram->objectName().isEmpty())
            ShowHistogram->setObjectName(QString::fromUtf8("ShowHistogram"));
        ShowHistogram->resize(512, 400);
        label = new QLabel(ShowHistogram);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 512, 256));
        label_2 = new QLabel(ShowHistogram);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 280, 71, 18));
        label_3 = new QLabel(ShowHistogram);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 320, 71, 18));
        lineEdit_Min = new QLineEdit(ShowHistogram);
        lineEdit_Min->setObjectName(QString::fromUtf8("lineEdit_Min"));
        lineEdit_Min->setGeometry(QRect(80, 280, 113, 26));
        lineEdit_Max = new QLineEdit(ShowHistogram);
        lineEdit_Max->setObjectName(QString::fromUtf8("lineEdit_Max"));
        lineEdit_Max->setGeometry(QRect(80, 320, 113, 26));

        retranslateUi(ShowHistogram);

        QMetaObject::connectSlotsByName(ShowHistogram);
    } // setupUi

    void retranslateUi(QDialog *ShowHistogram)
    {
        ShowHistogram->setWindowTitle(QApplication::translate("ShowHistogram", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("ShowHistogram", "Gray_Min", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ShowHistogram", "Gray_Max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowHistogram: public Ui_ShowHistogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWHISTOGRAMDLG_H
