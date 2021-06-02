/****************************************************************************
** Form implementation generated from reading ui file 'login.ui'
**
** Created: Tue Apr 23 12:49:11 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "login.h"

#include <qcheckbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a LoginDialog which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
LoginDialog::LoginDialog( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "LoginDialog" );
    resize( 226, 141 ); 
    setCaption( tr( "Log In" ) );
    setSizeGripEnabled( TRUE );

    QWidget* privateLayoutWidget = new QWidget( this, "Layout14" );
    privateLayoutWidget->setGeometry( QRect( 0, 0, 220, 135 ) ); 
    Layout14 = new QVBoxLayout( privateLayoutWidget ); 
    Layout14->setSpacing( 6 );
    Layout14->setMargin( 0 );

    Layout4 = new QGridLayout; 
    Layout4->setSpacing( 6 );
    Layout4->setMargin( 0 );

    TextLabel1 = new QLabel( privateLayoutWidget, "TextLabel1" );
    TextLabel1->setText( tr( "User Name" ) );

    Layout4->addWidget( TextLabel1, 0, 0 );

    Password = new QLineEdit( privateLayoutWidget, "Password" );
    Password->setEchoMode( QLineEdit::Password );

    Layout4->addWidget( Password, 1, 1 );

    TextLabel2 = new QLabel( privateLayoutWidget, "TextLabel2" );
    TextLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel2->sizePolicy().hasHeightForWidth() ) );
    TextLabel2->setText( tr( "Password" ) );

    Layout4->addWidget( TextLabel2, 1, 0 );

    userName = new QComboBox( FALSE, privateLayoutWidget, "userName" );
    userName->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, userName->sizePolicy().hasHeightForWidth() ) );
    userName->setEditable( TRUE );

    Layout4->addWidget( userName, 0, 1 );
    Layout14->addLayout( Layout4 );

    Layout13 = new QHBoxLayout; 
    Layout13->setSpacing( 6 );
    Layout13->setMargin( 0 );

    AutoLogin = new QCheckBox( privateLayoutWidget, "AutoLogin" );
    QFont AutoLogin_font(  AutoLogin->font() );
    AutoLogin_font.setFamily( "adobe-helvetica" );
    AutoLogin_font.setPointSize( 10 );
    AutoLogin->setFont( AutoLogin_font ); 
    AutoLogin->setText( tr( "Auto Login" ) );
    Layout13->addWidget( AutoLogin );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout13->addItem( spacer );

    SavePassword = new QCheckBox( privateLayoutWidget, "SavePassword" );
    QFont SavePassword_font(  SavePassword->font() );
    SavePassword_font.setFamily( "adobe-helvetica" );
    SavePassword_font.setPointSize( 10 );
    SavePassword->setFont( SavePassword_font ); 
    SavePassword->setText( tr( "Save Password" ) );
    Layout13->addWidget( SavePassword );
    Layout14->addLayout( Layout13 );

    Layout1 = new QHBoxLayout; 
    Layout1->setSpacing( 6 );
    Layout1->setMargin( 0 );

    buttonOk = new QPushButton( privateLayoutWidget, "buttonOk" );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    Layout1->addWidget( buttonOk );

    buttonCancel = new QPushButton( privateLayoutWidget, "buttonCancel" );
    buttonCancel->setText( tr( "&Cancel" ) );
    buttonCancel->setAutoDefault( TRUE );
    Layout1->addWidget( buttonCancel );
    Layout14->addLayout( Layout1 );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );

    // tab order
    setTabOrder( userName, Password );
    setTabOrder( Password, AutoLogin );
    setTabOrder( AutoLogin, SavePassword );
    setTabOrder( SavePassword, buttonOk );
    setTabOrder( buttonOk, buttonCancel );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
LoginDialog::~LoginDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool LoginDialog::event( QEvent* ev )
{
    bool ret = QDialog::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont AutoLogin_font(  AutoLogin->font() );
	AutoLogin_font.setFamily( "adobe-helvetica" );
	AutoLogin_font.setPointSize( 10 );
	AutoLogin->setFont( AutoLogin_font ); 
	QFont SavePassword_font(  SavePassword->font() );
	SavePassword_font.setFamily( "adobe-helvetica" );
	SavePassword_font.setPointSize( 10 );
	SavePassword->setFont( SavePassword_font ); 
    }
    return ret;
}

