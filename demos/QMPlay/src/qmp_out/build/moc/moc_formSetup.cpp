/****************************************************************************
** Meta object code from reading C++ file 'formSetup.h'
**
** Created: Tue Aug 21 08:06:52 2012
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   10,   10,   10, 0x0a,
      62,   10,   10,   10, 0x0a,
      71,   10,   10,   10, 0x0a,
      83,   10,   10,   10, 0x0a,
      91,   10,   10,   10, 0x0a,
     103,   10,   10,   10, 0x0a,
     115,   10,   10,   10, 0x0a,
     126,   10,   10,   10, 0x0a,
     136,   10,   10,   10, 0x0a,
     147,   11,   10,   10, 0x0a,
     194,  185,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormSetup[] = {
    "FormSetup\0\0,,\0bufferSizeUpdated(QString,QString,int)\0"
    "ApplyB()\0playSB()\0setVol(int)\0bBset()\0"
    "userRateB()\0userBitsB()\0userChnB()\0"
    "_buffQB()\0_titleHB()\0"
    "updateBufferSize(QString,QString,int)\0"
    "s1,s2,s3\0bufferSize(QString,QString,int)\0"
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
        case 0: bufferSizeUpdated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: ApplyB(); break;
        case 2: playSB(); break;
        case 3: setVol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: bBset(); break;
        case 5: userRateB(); break;
        case 6: userBitsB(); break;
        case 7: userChnB(); break;
        case 8: _buffQB(); break;
        case 9: _titleHB(); break;
        case 10: updateBufferSize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: bufferSize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FormSetup::bufferSizeUpdated(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
