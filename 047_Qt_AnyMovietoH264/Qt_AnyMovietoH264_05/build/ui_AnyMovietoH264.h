/********************************************************************************
** Form generated from reading UI file 'AnyMovietoH264.ui'
**
** Created: Sat Apr 14 16:04:01 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANYMOVIETOH264_H
#define UI_ANYMOVIETOH264_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AnyMovietoH264
{
public:
    QLineEdit *Edit_Path;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Edit_Name;
    QPushButton *Button_Select;
    QPushButton *Button_Detail;
    QLabel *label_3;
    QLineEdit *Edit_Duration;
    QLabel *label_4;
    QLineEdit *Edit_Size;
    QLabel *label_5;
    QLineEdit *Edit_Format;
    QGroupBox *groupBox;
    QLabel *label_6;
    QComboBox *combo_Size;
    QLabel *label_7;
    QLabel *label_VideoFormat;
    QLabel *label_8;
    QLabel *label_AudioFormat;
    QLabel *label_9;
    QLabel *label_AudioSample;
    QLabel *label_10;
    QLabel *label_AudioBitrate;
    QLabel *label_11;
    QComboBox *combo_VideoBitrate;
    QLabel *label_12;
    QLabel *label_VideoFsp;
    QLabel *label_13;
    QComboBox *combo_CPU;
    QPushButton *Button_Run;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AnyMovietoH264)
    {
        if (AnyMovietoH264->objectName().isEmpty())
            AnyMovietoH264->setObjectName(QString::fromUtf8("AnyMovietoH264"));
        AnyMovietoH264->resize(400, 544);
        Edit_Path = new QLineEdit(AnyMovietoH264);
        Edit_Path->setObjectName(QString::fromUtf8("Edit_Path"));
        Edit_Path->setGeometry(QRect(90, 10, 291, 27));
        label = new QLabel(AnyMovietoH264);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 67, 17));
        label_2 = new QLabel(AnyMovietoH264);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 67, 17));
        Edit_Name = new QLineEdit(AnyMovietoH264);
        Edit_Name->setObjectName(QString::fromUtf8("Edit_Name"));
        Edit_Name->setGeometry(QRect(90, 40, 291, 27));
        Button_Select = new QPushButton(AnyMovietoH264);
        Button_Select->setObjectName(QString::fromUtf8("Button_Select"));
        Button_Select->setGeometry(QRect(280, 70, 98, 27));
        Button_Detail = new QPushButton(AnyMovietoH264);
        Button_Detail->setObjectName(QString::fromUtf8("Button_Detail"));
        Button_Detail->setGeometry(QRect(130, 80, 111, 20));
        label_3 = new QLabel(AnyMovietoH264);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 67, 17));
        Edit_Duration = new QLineEdit(AnyMovietoH264);
        Edit_Duration->setObjectName(QString::fromUtf8("Edit_Duration"));
        Edit_Duration->setGeometry(QRect(90, 120, 131, 27));
        label_4 = new QLabel(AnyMovietoH264);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 150, 71, 17));
        Edit_Size = new QLineEdit(AnyMovietoH264);
        Edit_Size->setObjectName(QString::fromUtf8("Edit_Size"));
        Edit_Size->setGeometry(QRect(90, 150, 131, 27));
        label_5 = new QLabel(AnyMovietoH264);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 180, 71, 17));
        Edit_Format = new QLineEdit(AnyMovietoH264);
        Edit_Format->setObjectName(QString::fromUtf8("Edit_Format"));
        Edit_Format->setGeometry(QRect(90, 180, 211, 27));
        groupBox = new QGroupBox(AnyMovietoH264);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 210, 391, 291));
        groupBox->setAutoFillBackground(false);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 30, 101, 17));
        combo_Size = new QComboBox(groupBox);
        combo_Size->setObjectName(QString::fromUtf8("combo_Size"));
        combo_Size->setGeometry(QRect(140, 30, 131, 27));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 200, 101, 17));
        label_VideoFormat = new QLabel(groupBox);
        label_VideoFormat->setObjectName(QString::fromUtf8("label_VideoFormat"));
        label_VideoFormat->setGeometry(QRect(140, 200, 91, 17));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 230, 101, 17));
        label_AudioFormat = new QLabel(groupBox);
        label_AudioFormat->setObjectName(QString::fromUtf8("label_AudioFormat"));
        label_AudioFormat->setGeometry(QRect(140, 230, 91, 17));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 170, 101, 17));
        label_AudioSample = new QLabel(groupBox);
        label_AudioSample->setObjectName(QString::fromUtf8("label_AudioSample"));
        label_AudioSample->setGeometry(QRect(140, 170, 91, 17));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 140, 121, 17));
        label_AudioBitrate = new QLabel(groupBox);
        label_AudioBitrate->setObjectName(QString::fromUtf8("label_AudioBitrate"));
        label_AudioBitrate->setGeometry(QRect(140, 140, 91, 17));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 70, 121, 17));
        combo_VideoBitrate = new QComboBox(groupBox);
        combo_VideoBitrate->setObjectName(QString::fromUtf8("combo_VideoBitrate"));
        combo_VideoBitrate->setGeometry(QRect(140, 70, 131, 27));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 110, 121, 17));
        label_VideoFsp = new QLabel(groupBox);
        label_VideoFsp->setObjectName(QString::fromUtf8("label_VideoFsp"));
        label_VideoFsp->setGeometry(QRect(140, 110, 91, 17));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 260, 101, 17));
        combo_CPU = new QComboBox(groupBox);
        combo_CPU->setObjectName(QString::fromUtf8("combo_CPU"));
        combo_CPU->setGeometry(QRect(140, 260, 121, 27));
        Button_Run = new QPushButton(AnyMovietoH264);
        Button_Run->setObjectName(QString::fromUtf8("Button_Run"));
        Button_Run->setGeometry(QRect(280, 510, 98, 27));
        textBrowser = new QTextBrowser(AnyMovietoH264);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 500, 256, 41));

        retranslateUi(AnyMovietoH264);
        QObject::connect(Button_Select, SIGNAL(clicked()), AnyMovietoH264, SLOT(slotSelect()));
        QObject::connect(Button_Detail, SIGNAL(clicked()), AnyMovietoH264, SLOT(slotDetail()));
        QObject::connect(Button_Run, SIGNAL(clicked()), AnyMovietoH264, SLOT(slotRun()));

        QMetaObject::connectSlotsByName(AnyMovietoH264);
    } // setupUi

    void retranslateUi(QDialog *AnyMovietoH264)
    {
        AnyMovietoH264->setWindowTitle(QApplication::translate("AnyMovietoH264", "AnyMovietoH264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AnyMovietoH264", "\350\267\257    \345\276\221\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AnyMovietoH264", "\346\252\224\346\241\210\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        Button_Select->setText(QApplication::translate("AnyMovietoH264", "Select File", 0, QApplication::UnicodeUTF8));
        Button_Detail->setText(QApplication::translate("AnyMovietoH264", "Detail Setting", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AnyMovietoH264", "\347\211\207    \351\225\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AnyMovietoH264", "\345\275\261\347\211\207\347\225\253\351\235\242\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AnyMovietoH264", "\346\240\274    \345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AnyMovietoH264", "\350\275\211\346\252\224\345\217\203\346\225\270\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AnyMovietoH264", "\350\274\270\345\207\272\345\275\261\347\211\207\347\225\253\351\235\242\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AnyMovietoH264", "\345\275\261\345\203\217\350\275\211\346\252\224\346\240\274\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_VideoFormat->setText(QApplication::translate("AnyMovietoH264", "libx264", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AnyMovietoH264", "\350\201\262\351\237\263\350\275\211\346\252\224\346\240\274\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_AudioFormat->setText(QApplication::translate("AnyMovietoH264", "libfaac", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AnyMovietoH264", "\350\201\262\351\237\263\345\217\226\346\250\243\351\240\273\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_AudioSample->setText(QApplication::translate("AnyMovietoH264", "44100", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AnyMovietoH264", "\350\201\262\351\237\263\350\275\211\346\252\224Bitrate\357\274\232", 0, QApplication::UnicodeUTF8));
        label_AudioBitrate->setText(QApplication::translate("AnyMovietoH264", "40k", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AnyMovietoH264", "\345\275\261\345\203\217\350\275\211\346\252\224Bitrate\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("AnyMovietoH264", "\345\275\261\345\203\217\346\257\217\347\247\222\345\274\265\346\225\270\357\274\232", 0, QApplication::UnicodeUTF8));
        label_VideoFsp->setText(QApplication::translate("AnyMovietoH264", "29.97", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AnyMovietoH264", "CPU\344\275\277\347\224\250\346\225\270\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        Button_Run->setText(QApplication::translate("AnyMovietoH264", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnyMovietoH264: public Ui_AnyMovietoH264 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANYMOVIETOH264_H
