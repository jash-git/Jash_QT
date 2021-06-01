/****************************************************************************
** Meta object code from reading C++ file 'dialogimpl.h'
**
** Created: Tue Mar 16 09:42:46 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogImpl[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogImpl[] = {
    "DialogImpl\0\0Timerslot()\0slot1()\0slot2()\0"
    "slot3(QString)\0"
};

const QMetaObject DialogImpl::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogImpl,
      qt_meta_data_DialogImpl, 0 }
};

const QMetaObject *DialogImpl::metaObject() const
{
    return &staticMetaObject;
}

void *DialogImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogImpl))
        return static_cast<void*>(const_cast< DialogImpl*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< DialogImpl*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Timerslot(); break;
        case 1: slot1(); break;
        case 2: slot2(); break;
        case 3: slot3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
