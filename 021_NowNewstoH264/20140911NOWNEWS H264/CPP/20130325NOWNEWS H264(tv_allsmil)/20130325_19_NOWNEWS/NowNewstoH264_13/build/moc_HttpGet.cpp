/****************************************************************************
** Meta object code from reading C++ file 'HttpGet.h'
**
** Created: Wed Jul 31 11:21:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/HttpGet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpGet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHttpGet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

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

void CHttpGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CHttpGet *_t = static_cast<CHttpGet *>(_o);
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->httpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->httpReqDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CHttpGet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CHttpGet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CHttpGet,
      qt_meta_data_CHttpGet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHttpGet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHttpGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
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
