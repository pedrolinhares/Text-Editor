/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Mon Jul 19 17:43:20 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   29,   11, 0x08,
      48,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updateTabTitle()\0bool\0"
    "newDocument()\0pageChanged(int)\0"
    "closeTab(int)\0openFile()\0saveFile()\0"
    "saveAs()\0copy()\0cut()\0paste()\0undo()\0"
    "redo()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateTabTitle(); break;
        case 1: { bool _r = newDocument();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: pageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: openFile(); break;
        case 5: saveFile(); break;
        case 6: saveAs(); break;
        case 7: copy(); break;
        case 8: cut(); break;
        case 9: paste(); break;
        case 10: undo(); break;
        case 11: redo(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
