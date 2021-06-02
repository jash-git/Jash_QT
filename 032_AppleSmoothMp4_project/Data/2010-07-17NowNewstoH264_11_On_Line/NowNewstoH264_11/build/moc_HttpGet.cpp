/****************************************************************************
** Meta object code from reading C++ file 'HttpGet.h'
**
** Created: Fri Jul 16 10:23:11 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/HttpGet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpGet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHttpGet[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   17,    9,    9, 0x08,
      46,   38,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CHttpGet[] = {
    "CHttpGet\0\0done()\0error\0httpDone(bool)\0"
    "i,error\0httpReqDone(int,bool)\0"
};

const QMetaObject CHttpGet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CHttpGet,
      qt_meta_data_CHttpGet, 0 }
};

const QMetaObject *CHttpGet::metaObject() const
{
    return &staticMetaObject;
}

void *CHttpGet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpGet))
        return static_cast<void*>(const_cast< CHttpGet*>(this));
    return QObject::qt_metacast(_clname);
}

int CHttpGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: done(); break;
        case 1: httpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: httpReqDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CHttpGet::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
