/****************************************************************************
** Main_Window meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Apr 23 12:49:22 2002
**      by: The Qt MOC ($Id: moc_mainwindow.cpp,v 1.1.1.1 2002/04/23 21:14:21 rdiamond Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Main_Window::className() const
{
    return "Main_Window";
}

QMetaObject *Main_Window::metaObj = 0;

void Main_Window::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("Main_Window","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Main_Window::tr(const char* s)
{
    return qApp->translate( "Main_Window", s, 0 );
}

QString Main_Window::tr(const char* s, const char * c)
{
    return qApp->translate( "Main_Window", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Main_Window::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Main_Window::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &Main_Window::post_comment;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "post_comment()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"Main_Window", "QWidget",
	slot_tbl, 1,
	0, 0,
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
