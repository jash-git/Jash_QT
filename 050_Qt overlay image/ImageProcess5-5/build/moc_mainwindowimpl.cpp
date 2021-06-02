/****************************************************************************
** Meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created: Thu May 17 14:36:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindowimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowImpl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      31,   15,   15,   15, 0x08,
      43,   15,   15,   15, 0x08,
      54,   15,   15,   15, 0x08,
      67,   15,   15,   15, 0x08,
      88,   15,   15,   15, 0x08,
     108,   15,   15,   15, 0x08,
     124,   15,   15,   15, 0x08,
     139,   15,   15,   15, 0x08,
     154,   15,   15,   15, 0x08,
     172,   15,   15,   15, 0x08,
     188,   15,   15,   15, 0x08,
     204,   15,   15,   15, 0x08,
     220,   15,   15,   15, 0x08,
     232,   15,   15,   15, 0x08,
     245,   15,   15,   15, 0x08,
     257,   15,   15,   15, 0x08,
     271,   15,   15,   15, 0x08,
     287,   15,   15,   15, 0x08,
     301,   15,   15,   15, 0x08,
     316,   15,   15,   15, 0x08,
     335,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowImpl[] = {
    "MainWindowImpl\0\0slotOpenFile()\0"
    "slotClose()\0slotGray()\0slotSource()\0"
    "slotFixedThreshold()\0slotOTSUThreshold()\0"
    "slotHistogram()\0slotEqualize()\0"
    "slotSaveFile()\0slotTranslation()\0"
    "slotHorMirror()\0slotVerMirror()\0"
    "slotTranspose()\0slotScale()\0slotRotate()\0"
    "slotSobel()\0slotRoberts()\0slotLaplacian()\0"
    "slotPrewitt()\0slotThinning()\0"
    "slotOverlayImage()\0slotOverlayText()\0"
};

const QMetaObject MainWindowImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowImpl,
      qt_meta_data_MainWindowImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        case 1: slotClose(); break;
        case 2: slotGray(); break;
        case 3: slotSource(); break;
        case 4: slotFixedThreshold(); break;
        case 5: slotOTSUThreshold(); break;
        case 6: slotHistogram(); break;
        case 7: slotEqualize(); break;
        case 8: slotSaveFile(); break;
        case 9: slotTranslation(); break;
        case 10: slotHorMirror(); break;
        case 11: slotVerMirror(); break;
        case 12: slotTranspose(); break;
        case 13: slotScale(); break;
        case 14: slotRotate(); break;
        case 15: slotSobel(); break;
        case 16: slotRoberts(); break;
        case 17: slotLaplacian(); break;
        case 18: slotPrewitt(); break;
        case 19: slotThinning(); break;
        case 20: slotOverlayImage(); break;
        case 21: slotOverlayText(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
