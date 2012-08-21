/****************************************************************************
** Meta object code from reading C++ file 'FormVis.h'
**
** Created: Tue Aug 21 20:30:15 2012
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
      16,   14, // methods
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
      60,    6,    6,    6, 0x0a,
      69,    6,    6,    6, 0x0a,
      79,    6,    6,    6, 0x0a,
      98,    6,    6,    6, 0x0a,
     113,    6,    6,    6, 0x0a,
     128,    6,    6,    6, 0x0a,
     142,    6,    6,    6, 0x0a,
     149,    6,    6,    6, 0x0a,
     171,  169,    6,    6, 0x0a,
     192,  187,    6,    6, 0x0a,
     236,  187,    6,    6, 0x0a,
     284,  280,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyVis[] = {
    "MyVis\0\0startTimerSignal(int)\0popupMenu()\0"
    "turnOff()\0odlacz()\0_opcje()\0podlacz()\0"
    "toggleFullScreen()\0showControls()\0"
    "hideControls()\0cursorTimDo()\0fKey()\0"
    "startTimerSlot(int)\0i\0startTimer(int)\0"
    ",,,,\0drawLine(QPainter*,float,float,float,float)\0"
    "fillRect(QPainter*,float,float,float,float)\0"
    ",,,\0setColor(QPainter*,float,float,float)\0"
};

const QMetaObject MyVis::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyVis,
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
    return QWidget::qt_metacast(_clname);
}

int MyVis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startTimerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: popupMenu(); break;
        case 2: turnOff(); break;
        case 3: odlacz(); break;
        case 4: _opcje(); break;
        case 5: podlacz(); break;
        case 6: toggleFullScreen(); break;
        case 7: showControls(); break;
        case 8: hideControls(); break;
        case 9: cursorTimDo(); break;
        case 10: fKey(); break;
        case 11: startTimerSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: startTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: drawLine((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 14: fillRect((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 15: setColor((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 16;
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
