/****************************************************************************
** LoginDialog meta object code from reading C++ file 'login.h'
**
** Created: Tue Apr 23 12:49:25 2002
**      by: The Qt MOC ($Id: moc_login.cpp,v 1.1.1.1 2002/04/23 21:14:21 rdiamond Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "login.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *LoginDialog::className() const
{
    return "LoginDialog";
}

QMetaObject *LoginDialog::metaObj = 0;

void LoginDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("LoginDialog","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString LoginDialog::tr(const char* s)
{
    return qApp->translate( "LoginDialog", s, 0 );
}

QString LoginDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "LoginDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* LoginDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"LoginDialog", "QDialog",
	0, 0,
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
