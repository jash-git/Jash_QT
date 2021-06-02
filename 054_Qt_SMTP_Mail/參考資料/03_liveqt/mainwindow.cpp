/****************************************************************************
** Form implementation generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Apr 23 12:49:06 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "mainwindow.h"

#include <qcheckbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a Main_Window which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
Main_Window::Main_Window( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Main_Window" );
    resize( 239, 304 ); 
    setCaption( tr( "LiveQt" ) );

    TabWidget2 = new QTabWidget( this, "TabWidget2" );
    TabWidget2->setGeometry( QRect( 0, 0, 235, 300 ) ); 

    tab = new QWidget( TabWidget2, "tab" );

    QWidget* privateLayoutWidget = new QWidget( tab, "Layout9" );
    privateLayoutWidget->setGeometry( QRect( 0, 0, 230, 270 ) ); 
    Layout9 = new QVBoxLayout( privateLayoutWidget ); 
    Layout9->setSpacing( 6 );
    Layout9->setMargin( 0 );

    Layout8 = new QHBoxLayout; 
    Layout8->setSpacing( 6 );
    Layout8->setMargin( 0 );

    TextLabel1_3 = new QLabel( privateLayoutWidget, "TextLabel1_3" );
    TextLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, TextLabel1_3->sizePolicy().hasHeightForWidth() ) );
    TextLabel1_3->setText( tr( "Subject" ) );
    Layout8->addWidget( TextLabel1_3 );

    subject = new QLineEdit( privateLayoutWidget, "subject" );
    Layout8->addWidget( subject );
    Layout9->addLayout( Layout8 );

    message = new QMultiLineEdit( privateLayoutWidget, "message" );
    message->setWordWrap( QMultiLineEdit::WidgetWidth );
    message->setWrapColumnOrWidth( -1 );
    Layout9->addWidget( message );

    Layout2 = new QHBoxLayout; 
    Layout2->setSpacing( 6 );
    Layout2->setMargin( 0 );

    postOk = new QPushButton( privateLayoutWidget, "postOk" );
    postOk->setText( tr( "Ok" ) );
    Layout2->addWidget( postOk );

    postCancel = new QPushButton( privateLayoutWidget, "postCancel" );
    postCancel->setText( tr( "Close" ) );
    Layout2->addWidget( postCancel );
    Layout9->addLayout( Layout2 );
    TabWidget2->insertTab( tab, tr( "Post" ) );

    tab_2 = new QWidget( TabWidget2, "tab_2" );

    QWidget* privateLayoutWidget_2 = new QWidget( tab_2, "Layout11" );
    privateLayoutWidget_2->setGeometry( QRect( 0, 0, 250, 200 ) ); 
    Layout11 = new QVBoxLayout( privateLayoutWidget_2 ); 
    Layout11->setSpacing( 6 );
    Layout11->setMargin( 0 );

    Layout10 = new QHBoxLayout; 
    Layout10->setSpacing( 6 );
    Layout10->setMargin( 0 );

    Layout4 = new QVBoxLayout; 
    Layout4->setSpacing( 6 );
    Layout4->setMargin( 0 );

    TextLabel1 = new QLabel( privateLayoutWidget_2, "TextLabel1" );
    TextLabel1->setText( tr( "Mood" ) );
    Layout4->addWidget( TextLabel1 );

    TextLabel1_2 = new QLabel( privateLayoutWidget_2, "TextLabel1_2" );
    TextLabel1_2->setText( tr( "Music" ) );
    Layout4->addWidget( TextLabel1_2 );

    TextLabel2 = new QLabel( privateLayoutWidget_2, "TextLabel2" );
    TextLabel2->setText( tr( "Picture" ) );
    Layout4->addWidget( TextLabel2 );

    TextLabel3 = new QLabel( privateLayoutWidget_2, "TextLabel3" );
    TextLabel3->setText( tr( "Visibility" ) );
    Layout4->addWidget( TextLabel3 );

    TextLabel4 = new QLabel( privateLayoutWidget_2, "TextLabel4" );
    TextLabel4->setText( tr( "Journal to use" ) );
    Layout4->addWidget( TextLabel4 );
    Layout10->addLayout( Layout4 );

    Layout9_2 = new QVBoxLayout; 
    Layout9_2->setSpacing( 6 );
    Layout9_2->setMargin( 0 );

    Mood = new QComboBox( FALSE, privateLayoutWidget_2, "Mood" );
    Mood->insertItem( tr( "(None)" ) );
    Mood->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, Mood->sizePolicy().hasHeightForWidth() ) );
    Mood->setEditable( TRUE );
    Layout9_2->addWidget( Mood );

    Music = new QLineEdit( privateLayoutWidget_2, "Music" );
    Layout9_2->addWidget( Music );

    Picture = new QComboBox( FALSE, privateLayoutWidget_2, "Picture" );
    Layout9_2->addWidget( Picture );

    Visibility = new QComboBox( FALSE, privateLayoutWidget_2, "Visibility" );
    Layout9_2->addWidget( Visibility );

    JournalSelect = new QComboBox( FALSE, privateLayoutWidget_2, "JournalSelect" );
    Layout9_2->addWidget( JournalSelect );
    Layout10->addLayout( Layout9_2 );
    Layout11->addLayout( Layout10 );

    Layout6 = new QHBoxLayout; 
    Layout6->setSpacing( 6 );
    Layout6->setMargin( 0 );

    AutoFormat = new QCheckBox( privateLayoutWidget_2, "AutoFormat" );
    AutoFormat->setText( tr( "Autoformat" ) );
    Layout6->addWidget( AutoFormat );

    AllowComments = new QCheckBox( privateLayoutWidget_2, "AllowComments" );
    AllowComments->setText( tr( "Allow Comments" ) );
    Layout6->addWidget( AllowComments );
    Layout11->addLayout( Layout6 );
    TabWidget2->insertTab( tab_2, tr( "Options" ) );

    // signals and slots connections
    connect( postOk, SIGNAL( clicked() ), this, SLOT( post_comment() ) );
    connect( postCancel, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( Mood, Music );
    setTabOrder( Music, Picture );
    setTabOrder( Picture, Visibility );
    setTabOrder( Visibility, JournalSelect );
    setTabOrder( JournalSelect, AutoFormat );
    setTabOrder( AutoFormat, AllowComments );
    setTabOrder( AllowComments, TabWidget2 );
    setTabOrder( TabWidget2, subject );
    setTabOrder( subject, message );
    setTabOrder( message, postOk );
    setTabOrder( postOk, postCancel );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
Main_Window::~Main_Window()
{
    // no need to delete child widgets, Qt does it all for us
}

void Main_Window::post_comment()
{
    qWarning( "Main_Window::post_comment(): Not implemented yet!" );
}

