/****************************************************************************
** Meta object code from reading C++ file 'formDownload.h'
**
** Created: Tue Aug 21 08:06:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/formDownload.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formDownload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FormDownload[] = {

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
      14,   13,   13,   13, 0x0a,
      24,   13,   13,   13, 0x0a,
      35,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormDownload[] = {
    "FormDownload\0\0zamknij()\0timDwnDo()\0"
    "install()\0"
};

const QMetaObject FormDownload::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormDownload,
      qt_meta_data_FormDownload, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormDownload::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormDownload))
        return static_cast<void*>(const_cast< FormDownload*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormDownload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zamknij(); break;
        case 1: timDwnDo(); break;
        case 2: install(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
