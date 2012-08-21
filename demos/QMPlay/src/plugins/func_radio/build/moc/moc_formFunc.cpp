/****************************************************************************
** Meta object code from reading C++ file 'formFunc.h'
**
** Created: Tue Aug 21 19:58:34 2012
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
static const uint qt_meta_data_FormFunc[] = {

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
      10,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      51,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FormFunc[] = {
    "FormFunc\0\0openLink(QListWidgetItem*)\0"
    "thrFinished()\0createList()\0"
};

const QMetaObject FormFunc::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormFunc,
      qt_meta_data_FormFunc, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormFunc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormFunc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormFunc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormFunc))
        return static_cast<void*>(const_cast< FormFunc*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormFunc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openLink((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: thrFinished(); break;
        case 2: createList(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
