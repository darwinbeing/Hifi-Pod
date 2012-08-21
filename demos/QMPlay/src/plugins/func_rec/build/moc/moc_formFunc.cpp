/****************************************************************************
** Meta object code from reading C++ file 'formFunc.h'
**
** Created: Tue Aug 21 19:58:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/formFunc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formFunc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form1[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      13,    6,    6,    6, 0x0a,
      20,    6,    6,    6, 0x0a,
      29,    6,    6,    6, 0x0a,
      36,    6,    6,    6, 0x0a,
      45,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Form1[] = {
    "Form1\0\0rec()\0Stop()\0pauseB()\0sndB()\0"
    "timerF()\0timRefF()\0"
};

const QMetaObject Form1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form1,
      qt_meta_data_Form1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form1))
        return static_cast<void*>(const_cast< Form1*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rec(); break;
        case 1: Stop(); break;
        case 2: pauseB(); break;
        case 3: sndB(); break;
        case 4: timerF(); break;
        case 5: timRefF(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
