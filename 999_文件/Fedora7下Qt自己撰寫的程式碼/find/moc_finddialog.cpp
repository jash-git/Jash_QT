/****************************************************************************
** FindDialog meta object code from reading C++ file 'finddialog.h'
**
** Created: Mon Aug 20 11:08:18 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "finddialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FindDialog::className() const
{
    return "FindDialog";
}

QMetaObject *FindDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FindDialog( "FindDialog", &FindDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FindDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FindDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FindDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FindDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FindDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"findClicked", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"enableFindButton", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "findClicked()", &slot_0, QMetaData::Private },
	{ "enableFindButton(const QString&)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In },
	{ "caseSensitive", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"findNext", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In },
	{ "caseSensitive", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"findPrev", 2, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "findNext(const QString&,bool)", &signal_0, QMetaData::Public },
	{ "findPrev(const QString&,bool)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FindDialog", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FindDialog.setMetaObject( metaObj );
    return metaObj;
}

void* FindDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FindDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL findNext
void FindDialog::findNext( const QString& t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL findPrev
void FindDialog::findPrev( const QString& t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

bool FindDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: findClicked(); break;
    case 1: enableFindButton((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FindDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: findNext((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 1: findPrev((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FindDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool FindDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
