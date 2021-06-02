/****************************************************************************
** Meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created: Sat Aug 21 11:51:43 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindowimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowImpl[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      31,   15,   15,   15, 0x08,
      46,   15,   15,   15, 0x08,
      58,   15,   15,   15, 0x08,
      69,   15,   15,   15, 0x08,
      84,   15,   15,   15, 0x08,
      97,   15,   15,   15, 0x08,
     114,   15,   15,   15, 0x08,
     137,   15,   15,   15, 0x08,
     147,   15,   15,   15, 0x08,
     157,   15,   15,   15, 0x08,
     167,   15,   15,   15, 0x08,
     182,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowImpl[] = {
    "MainWindowImpl\0\0slotOpenFile()\0"
    "slotSaveFile()\0slotClose()\0slotGray()\0"
    "slotHistgram()\0slotThresh()\0"
    "slotDockWidget()\0slotDynamicThresh(int)\0"
    "slotImR()\0slotImG()\0slotImB()\0"
    "slotGradient()\0slotLaplacian()\0"
};

const QMetaObject MainWindowImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowImpl,
      qt_meta_data_MainWindowImpl, 0 }
};

const QMetaObject *MainWindowImpl::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindowImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowImpl))
        return static_cast<void*>(const_cast< MainWindowImpl*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindowImpl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotOpenFile(); break;
        case 1: slotSaveFile(); break;
        case 2: slotClose(); break;
        case 3: slotGray(); break;
        case 4: slotHistgram(); break;
        case 5: slotThresh(); break;
        case 6: slotDockWidget(); break;
        case 7: slotDynamicThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: slotImR(); break;
        case 9: slotImG(); break;
        case 10: slotImB(); break;
        case 11: slotGradient(); break;
        case 12: slotLaplacian(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
