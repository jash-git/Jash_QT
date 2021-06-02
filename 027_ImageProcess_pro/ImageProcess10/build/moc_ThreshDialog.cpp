/****************************************************************************
** Meta object code from reading C++ file 'ThreshDialog.h'
**
** Created: Tue Aug 17 17:17:26 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ThreshDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreshDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreshDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_ThreshDialog[] = {
    "ThreshDialog\0"
};

const QMetaObject ThreshDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ThreshDialog,
      qt_meta_data_ThreshDialog, 0 }
};

const QMetaObject *ThreshDialog::metaObject() const
{
    return &staticMetaObject;
}

void *ThreshDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreshDialog))
        return static_cast<void*>(const_cast< ThreshDialog*>(this));
    if (!strcmp(_clname, "Ui::Dialog01"))
        return static_cast< Ui::Dialog01*>(const_cast< ThreshDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ThreshDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
