/****************************************************************************
** Meta object code from reading C++ file 'formFunc.h'
**
** Created: Tue Aug 21 19:58:28 2012
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,    9,    9,    9, 0x0a,
      42,    9,    9,    9, 0x0a,
      50,    9,    9,    9, 0x0a,
      58,    9,    9,    9, 0x0a,
      65,    9,    9,    9, 0x0a,
      73,    9,    9,    9, 0x0a,
      85,    9,    9,    9, 0x0a,
      95,    9,    9,    9, 0x0a,
     104,    9,    9,    9, 0x0a,
     114,    9,    9,    9, 0x0a,
     126,    9,    9,    9, 0x0a,
     138,    9,    9,    9, 0x0a,
     149,    9,    9,    9, 0x0a,
     165,    9,    9,    9, 0x0a,
     173,    9,    9,    9, 0x0a,
     185,    9,    9,    9, 0x0a,
     198,    9,    9,    9, 0x0a,
     207,    9,    9,    9, 0x0a,
     231,    9,    9,    9, 0x0a,
     247,    9,    9,    9, 0x0a,
     270,  268,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormFunc[] = {
    "FormFunc\0\0infoLUpdated(QString)\0"
    "searchB()\0nextB()\0prevB()\0clrB()\0"
    "playB()\0downloadB()\0setPage()\0abortB()\0"
    "timeOut()\0mnuTPopup()\0mnuQPopup()\0"
    "copyAddr()\0delQueueEntry()\0dwnPB()\0"
    "copyAddr2()\0chPage(bool)\0queueB()\0"
    "searchAddressAfterThr()\0openInBrowser()\0"
    "updateInfoL(QString)\0s\0infoL(QString)\0"
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
        case 0: infoLUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: searchB(); break;
        case 2: nextB(); break;
        case 3: prevB(); break;
        case 4: clrB(); break;
        case 5: playB(); break;
        case 6: downloadB(); break;
        case 7: setPage(); break;
        case 8: abortB(); break;
        case 9: timeOut(); break;
        case 10: mnuTPopup(); break;
        case 11: mnuQPopup(); break;
        case 12: copyAddr(); break;
        case 13: delQueueEntry(); break;
        case 14: dwnPB(); break;
        case 15: copyAddr2(); break;
        case 16: chPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: queueB(); break;
        case 18: searchAddressAfterThr(); break;
        case 19: openInBrowser(); break;
        case 20: updateInfoL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: infoL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void FormFunc::infoLUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
