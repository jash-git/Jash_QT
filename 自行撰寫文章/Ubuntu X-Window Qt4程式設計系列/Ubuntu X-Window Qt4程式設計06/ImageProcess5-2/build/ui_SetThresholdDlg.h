/********************************************************************************
** Form generated from reading ui file 'SetThresholdDlg.ui'
**
** Created: Sun Oct 24 16:28:35 2010
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SETTHRESHOLDDLG_H
#define UI_SETTHRESHOLDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetThreshold
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *SetThreshold)
    {
        if (SetThreshold->objectName().isEmpty())
            SetThreshold->setObjectName(QString::fromUtf8("SetThreshold"));
        SetThreshold->resize(290, 34);
        pushButton = new QPushButton(SetThreshold);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 0, 92, 28));
        lineEdit = new QLineEdit(SetThreshold);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 0, 113, 26));
        label = new QLabel(SetThreshold);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 62, 18));

        retranslateUi(SetThreshold);
        QObject::connect(pushButton, SIGNAL(clicked()), SetThreshold, SLOT(accept()));

        QMetaObject::connectSlotsByName(SetThreshold);
    } // setupUi

    void retranslateUi(QDialog *SetThreshold)
    {
        SetThreshold->setWindowTitle(QApplication::translate("SetThreshold", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SetThreshold", "\347\242\272\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetThreshold", "\351\226\200\351\226\245\345\200\274", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SetThreshold);
    } // retranslateUi

};

namespace Ui {
    class SetThreshold: public Ui_SetThreshold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTHRESHOLDDLG_H
