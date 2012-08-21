/****************************************************************************
** Meta object code from reading C++ file 'FormVis.h'
**
** Created: Tue Aug 21 20:30:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/FormVis.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FormVis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyVis[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,    6,    6,    6, 0x0a,
      41,    6,    6,    6, 0x0a,
      51,    6,    6,    6, 0x0a,
      62,    6,    6,    6, 0x0a,
      71,    6,    6,    6, 0x0a,
      80,    6,    6,    6, 0x0a,
      90,    6,    6,    6, 0x0a,
     109,    6,    6,    6, 0x0a,
     124,    6,    6,    6, 0x0a,
     139,    6,    6,    6, 0x0a,
     153,    6,    6,    6, 0x0a,
     160,    6,    6,    6, 0x0a,
     182,  180,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyVis[] = {
    "MyVis\0\0startTimerSignal(int)\0popupMenu()\0"
    "turnOff()\0closeWin()\0odlacz()\0_opcje()\0"
    "podlacz()\0toggleFullScreen()\0"
    "showControls()\0hideControls()\0"
    "cursorTimDo()\0fKey()\0startTimerSlot(int)\0"
    "i\0startTimer(int)\0"
};

const QMetaObject MyVis::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyVis,
      qt_meta_data_MyVis, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyVis::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyVis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyVis::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyVis))
        return static_cast<void*>(const_cast< MyVis*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyVis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startTimerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: popupMenu(); break;
        case 2: turnOff(); break;
        case 3: closeWin(); break;
        case 4: odlacz(); break;
        case 5: _opcje(); break;
        case 6: podlacz(); break;
        case 7: toggleFullScreen(); break;
        case 8: showControls(); break;
        case 9: hideControls(); break;
        case 10: cursorTimDo(); break;
        case 11: fKey(); break;
        case 12: startTimerSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: startTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyVis::startTimerSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
