/****************************************************************************
** Form interface generated from reading ui file 'login.ui'
**
** Created: Tue Apr 23 12:48:39 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QCheckBox;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{ 
    Q_OBJECT

public:
    LoginDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~LoginDialog();

    QLabel* TextLabel1;
    QLineEdit* Password;
    QLabel* TextLabel2;
    QComboBox* userName;
    QCheckBox* AutoLogin;
    QCheckBox* SavePassword;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;

protected:
    QVBoxLayout* Layout14;
    QGridLayout* Layout4;
    QHBoxLayout* Layout13;
    QHBoxLayout* Layout1;
    bool event( QEvent* );
};

#endif // LOGINDIALOG_H
