/****************************************************************************
** Meta object code from reading C++ file 'FileBrowser.h'
**
** Created: Sat Nov 13 16:12:44 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/FileBrowser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileBrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileBrowser[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileBrowser[] = {
    "FileBrowser\0\0picked(QString&)\0"
    "itemSelected(QListWidgetItem*)\0"
};

const QMetaObject FileBrowser::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_FileBrowser,
      qt_meta_data_FileBrowser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileBrowser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileBrowser))
        return static_cast<void*>(const_cast< FileBrowser*>(this));
    return QListWidget::qt_metacast(_clname);
}

int FileBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: picked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: itemSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FileBrowser::picked(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
