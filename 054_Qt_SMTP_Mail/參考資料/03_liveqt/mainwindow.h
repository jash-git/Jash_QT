/****************************************************************************
** Form interface generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Apr 23 12:48:39 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QCheckBox;
class QComboBox;
class QLabel;
class QLineEdit;
class QMultiLineEdit;
class QPushButton;
class QTabWidget;

class Main_Window : public QWidget
{ 
    Q_OBJECT

public:
    Main_Window( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Main_Window();

    QTabWidget* TabWidget2;
    QWidget* tab;
    QLabel* TextLabel1_3;
    QLineEdit* subject;
    QMultiLineEdit* message;
    QPushButton* postOk;
    QPushButton* postCancel;
    QWidget* tab_2;
    QLabel* TextLabel1;
    QLabel* TextLabel1_2;
    QLabel* TextLabel2;
    QLabel* TextLabel3;
    QLabel* TextLabel4;
    QComboBox* Mood;
    QLineEdit* Music;
    QComboBox* Picture;
    QComboBox* Visibility;
    QComboBox* JournalSelect;
    QCheckBox* AutoFormat;
    QCheckBox* AllowComments;

public slots:
    virtual void post_comment();

protected:
    QVBoxLayout* Layout9;
    QHBoxLayout* Layout8;
    QHBoxLayout* Layout2;
    QVBoxLayout* Layout11;
    QHBoxLayout* Layout10;
    QVBoxLayout* Layout4;
    QVBoxLayout* Layout9_2;
    QHBoxLayout* Layout6;
};

#endif // MAIN_WINDOW_H
