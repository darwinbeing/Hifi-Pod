/****************************************************************************
** Meta object code from reading C++ file 'formSetup.h'
**
** Created: Tue Aug 21 19:58:06 2012
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      20,   10,   10,   10, 0x0a,
      28,   10,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,
      50,   10,   10,   10, 0x0a,
      60,   10,   10,   10, 0x0a,
      71,   10,   10,   10, 0x0a,
      84,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormSetup[] = {
    "FormSetup\0\0ApplyB()\0addCD()\0FsetupTimer()\0"
    "eject()\0closeTB()\0setDrive()\0CHKENABLED()\0"
    "driveE(QString)\0"
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
        case 0: ApplyB(); break;
        case 1: addCD(); break;
        case 2: FsetupTimer(); break;
        case 3: eject(); break;
        case 4: closeTB(); break;
        case 5: setDrive(); break;
        case 6: CHKENABLED(); break;
        case 7: driveE((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
