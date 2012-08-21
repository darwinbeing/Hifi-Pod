/****************************************************************************
** Meta object code from reading C++ file 'miniQMP.h'
**
** Created: Tue Aug 21 08:06:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/miniQMP.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miniQMP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_miniQmp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_miniQmp[] = {
    "miniQmp\0\0plist()\0"
};

const QMetaObject miniQmp::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_miniQmp,
      qt_meta_data_miniQmp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &miniQmp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *miniQmp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *miniQmp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_miniQmp))
        return static_cast<void*>(const_cast< miniQmp*>(this));
    return QFrame::qt_metacast(_clname);
}

int miniQmp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: plist(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
