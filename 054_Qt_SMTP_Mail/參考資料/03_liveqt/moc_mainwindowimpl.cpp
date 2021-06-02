/****************************************************************************
** MainWindowImpl meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created: Tue Apr 23 12:49:18 2002
**      by: The Qt MOC ($Id: moc_mainwindowimpl.cpp,v 1.1.1.1 2002/04/23 21:14:21 rdiamond Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mainwindowimpl.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *MainWindowImpl::className() const
{
    return "MainWindowImpl";
}

QMetaObject *MainWindowImpl::metaObj = 0;

void MainWindowImpl::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(Main_Window::className(), "Main_Window") != 0 )
	badSuperclassWarning("MainWindowImpl","Main_Window");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString MainWindowImpl::tr(const char* s)
{
    return qApp->translate( "MainWindowImpl", s, 0 );
}

QString MainWindowImpl::tr(const char* s, const char * c)
{
    return qApp->translate( "MainWindowImpl", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindowImpl::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Main_Window::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (MainWindowImpl::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (MainWindowImpl::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (MainWindowImpl::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (MainWindowImpl::*m1_t3)(const QString&);
    typedef void (QObject::*om1_t3)(const QString&);
    m1_t0 v1_0 = &MainWindowImpl::post_comment;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &MainWindowImpl::login_accept;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &MainWindowImpl::login_cancel;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &MainWindowImpl::user_changed;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "post_comment()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "login_accept()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "login_cancel()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "user_changed(const QString&)";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Public;
    typedef void (MainWindowImpl::*m2_t0)();
    typedef void (QObject::*om2_t0)();
    m2_t0 v2_0 = &MainWindowImpl::timeToDieSignal;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "timeToDieSignal()";
    signal_tbl[0].ptr = (QMember)ov2_0;
    metaObj = QMetaObject::new_metaobject(
	"MainWindowImpl", "Main_Window",
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL timeToDieSignal
void MainWindowImpl::timeToDieSignal()
{
    activate_signal( "timeToDieSignal()" );
}
