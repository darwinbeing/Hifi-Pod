/****************************************************************************
** Meta object code from reading C++ file 'formSetup.h'
**
** Created: Tue Aug 21 08:07:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/formSetup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formSetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FormSetup[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      17,   10,   10,   10, 0x0a,
      23,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      35,   10,   10,   10, 0x0a,
      41,   10,   10,   10, 0x0a,
      47,   10,   10,   10, 0x0a,
      53,   10,   10,   10, 0x0a,
      59,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,
      71,   10,   10,   10, 0x0a,
      78,   10,   10,   10, 0x0a,
      84,   10,   10,   10, 0x0a,
      91,   10,   10,   10, 0x0a,
     102,   10,   10,   10, 0x0a,
     111,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormSetup[] = {
    "FormSetup\0\0swB()\0sl0()\0sl1()\0sl2()\0"
    "sl3()\0sl4()\0sl5()\0sl6()\0sl7()\0sl8()\0"
    "clrB()\0upB()\0dwnB()\0enabledB()\0_timEq()\0"
    "_glW()\0"
};

const QMetaObject FormSetup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormSetup,
      qt_meta_data_FormSetup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormSetup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormSetup))
        return static_cast<void*>(const_cast< FormSetup*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: swB(); break;
        case 1: sl0(); break;
        case 2: sl1(); break;
        case 3: sl2(); break;
        case 4: sl3(); break;
        case 5: sl4(); break;
        case 6: sl5(); break;
        case 7: sl6(); break;
        case 8: sl7(); break;
        case 9: sl8(); break;
        case 10: clrB(); break;
        case 11: upB(); break;
        case 12: dwnB(); break;
        case 13: enabledB(); break;
        case 14: _timEq(); break;
        case 15: _glW(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
