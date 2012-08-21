/****************************************************************************
** Meta object code from reading C++ file 'FormVis.h'
**
** Created: Tue Aug 21 20:30:25 2012
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      19,    6,    6,    6, 0x0a,
      29,    6,    6,    6, 0x0a,
      40,    6,    6,    6, 0x0a,
      49,    6,    6,    6, 0x0a,
      58,    6,    6,    6, 0x0a,
      68,    6,    6,    6, 0x0a,
      87,    6,    6,    6, 0x0a,
     102,    6,    6,    6, 0x0a,
     117,    6,    6,    6, 0x0a,
     131,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyVis[] = {
    "MyVis\0\0popupMenu()\0turnOff()\0closeWin()\0"
    "odlacz()\0_opcje()\0podlacz()\0"
    "toggleFullScreen()\0showControls()\0"
    "hideControls()\0cursorTimDo()\0fKey()\0"
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
        case 0: popupMenu(); break;
        case 1: turnOff(); break;
        case 2: closeWin(); break;
        case 3: odlacz(); break;
        case 4: _opcje(); break;
        case 5: podlacz(); break;
        case 6: toggleFullScreen(); break;
        case 7: showControls(); break;
        case 8: hideControls(); break;
        case 9: cursorTimDo(); break;
        case 10: fKey(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
