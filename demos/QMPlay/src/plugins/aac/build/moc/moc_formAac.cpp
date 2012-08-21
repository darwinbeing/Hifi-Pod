/****************************************************************************
** Meta object code from reading C++ file 'formAac.h'
**
** Created: Tue Aug 21 19:54:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/formAac.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formAac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FormAac[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      19,    8,    8,    8, 0x0a,
      30,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormAac[] = {
    "FormAac\0\0zamknij()\0timRefDo()\0editId3()\0"
};

const QMetaObject FormAac::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormAac,
      qt_meta_data_FormAac, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormAac::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormAac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormAac::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormAac))
        return static_cast<void*>(const_cast< FormAac*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormAac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zamknij(); break;
        case 1: timRefDo(); break;
        case 2: editId3(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
