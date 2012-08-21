/****************************************************************************
** Meta object code from reading C++ file 'formSetup.h'
**
** Created: Tue Aug 21 08:06:18 2012
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      22,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      35,   10,   10,   10, 0x0a,
      47,   10,   10,   10, 0x0a,
      59,   10,   10,   10, 0x0a,
      72,   10,   10,   10, 0x0a,
      84,   10,   10,   10, 0x0a,
      96,   10,   10,   10, 0x0a,
     105,   10,   10,   10, 0x0a,
     115,   10,   10,   10, 0x0a,
     130,   10,   10,   10, 0x0a,
     141,   10,   10,   10, 0x0a,
     149,   10,   10,   10, 0x0a,
     156,   10,   10,   10, 0x0a,
     165,   10,   10,   10, 0x0a,
     177,   10,   10,   10, 0x0a,
     191,   10,   10,   10, 0x0a,
     200,   10,   10,   10, 0x0a,
     218,   10,   10,   10, 0x0a,
     235,   10,   10,   10, 0x0a,
     252,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormSetup[] = {
    "FormSetup\0\0APPLYQMP()\0naf1()\0lpB()\0"
    "aboutPlug()\0QMPButton()\0prevButton()\0"
    "nxtButton()\0setStyleB()\0zxplCC()\0"
    "opcjePB()\0pluglistMenu()\0delSetsB()\0"
    "langB()\0toUp()\0toDown()\0OnOffPlug()\0"
    "OnOffOnList()\0proxyB()\0pluginsChRow(int)\0"
    "formDockChOpen()\0restoreAddress()\0"
    "fileStructBClicked(int)\0"
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
        case 0: APPLYQMP(); break;
        case 1: naf1(); break;
        case 2: lpB(); break;
        case 3: aboutPlug(); break;
        case 4: QMPButton(); break;
        case 5: prevButton(); break;
        case 6: nxtButton(); break;
        case 7: setStyleB(); break;
        case 8: zxplCC(); break;
        case 9: opcjePB(); break;
        case 10: pluglistMenu(); break;
        case 11: delSetsB(); break;
        case 12: langB(); break;
        case 13: toUp(); break;
        case 14: toDown(); break;
        case 15: OnOffPlug(); break;
        case 16: OnOffOnList(); break;
        case 17: proxyB(); break;
        case 18: pluginsChRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: formDockChOpen(); break;
        case 20: restoreAddress(); break;
        case 21: fileStructBClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
