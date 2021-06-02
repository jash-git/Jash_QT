/****************************************************************************
** Meta object code from reading C++ file 'guiinfothread.h'
**
** Created: Tue Feb 12 11:02:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/guiinfothread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiinfothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GUIInfoThread[] = {

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
      27,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   14,   14,   14, 0x0a,
      72,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GUIInfoThread[] = {
    "GUIInfoThread\0\0socketError\0"
    "error(QTcpSocket::SocketError)\0"
    "readMessage()\0sendMessage()\0"
};

void GUIInfoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GUIInfoThread *_t = static_cast<GUIInfoThread *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->readMessage(); break;
        case 2: _t->sendMessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GUIInfoThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GUIInfoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GUIInfoThread,
      qt_meta_data_GUIInfoThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GUIInfoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GUIInfoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GUIInfoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUIInfoThread))
        return static_cast<void*>(const_cast< GUIInfoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int GUIInfoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void GUIInfoThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
