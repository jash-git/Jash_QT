/****************************************************************************
** LJHttp meta object code from reading C++ file 'ljhttp.h'
**
** Created: Tue Apr 23 12:49:15 2002
**      by: The Qt MOC ($Id: moc_ljhttp.cpp,v 1.1.1.1 2002/04/23 21:14:19 rdiamond Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "ljhttp.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *LJHttp::className() const
{
    return "LJHttp";
}

QMetaObject *LJHttp::metaObj = 0;

void LJHttp::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("LJHttp","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString LJHttp::tr(const char* s)
{
    return qApp->translate( "LJHttp", s, 0 );
}

QString LJHttp::tr(const char* s, const char * c)
{
    return qApp->translate( "LJHttp", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* LJHttp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (LJHttp::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (LJHttp::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (LJHttp::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (LJHttp::*m1_t3)(int);
    typedef void (QObject::*om1_t3)(int);
    typedef void (LJHttp::*m1_t4)(int);
    typedef void (QObject::*om1_t4)(int);
    m1_t0 v1_0 = &LJHttp::sendPostRequest;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &LJHttp::receivePostData;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &LJHttp::parsePostData;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &LJHttp::error;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &LJHttp::bytesWritten;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    QMetaData *slot_tbl = QMetaObject::new_metadata(5);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(5);
    slot_tbl[0].name = "sendPostRequest()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "receivePostData()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "parsePostData()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "error(int)";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "bytesWritten(int)";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"LJHttp", "QObject",
	slot_tbl, 5,
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
