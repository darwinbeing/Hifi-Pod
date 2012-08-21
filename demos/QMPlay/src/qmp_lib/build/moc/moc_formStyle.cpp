/****************************************************************************
** Meta object code from reading C++ file 'formStyle.h'
**
** Created: Tue Aug 21 08:06:26 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/formStyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formStyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FormStyle[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      21,   10,   10,   10, 0x0a,
      36,   10,   10,   10, 0x0a,
      62,   10,   10,   10, 0x0a,
      76,   10,   10,   10, 0x0a,
      87,   10,   10,   10, 0x0a,
     101,   10,   10,   10, 0x0a,
     114,   10,   10,   10, 0x0a,
     127,   10,   10,   10, 0x0a,
     136,   10,   10,   10, 0x0a,
     152,   10,   10,   10, 0x0a,
     174,   10,   10,   10, 0x0a,
     201,   10,   10,   10, 0x0a,
     217,   10,   10,   10, 0x0a,
     230,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FormStyle[] = {
    "FormStyle\0\0zamknij()\0SetStyleConn()\0"
    "GlobalColorButtonCliked()\0applyColors()\0"
    "newColor()\0deleteColor()\0SetEnabled()\0"
    "ChIndex(int)\0rename()\0LoadColorList()\0"
    "PictureButtonCliked()\0mainWindowSetsEnabled(int)\0"
    "resetColorMnu()\0resetColor()\0"
    "quickSetColor()\0"
};

const QMetaObject FormStyle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormStyle,
      qt_meta_data_FormStyle, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormStyle))
        return static_cast<void*>(const_cast< FormStyle*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zamknij(); break;
        case 1: SetStyleConn(); break;
        case 2: GlobalColorButtonCliked(); break;
        case 3: applyColors(); break;
        case 4: newColor(); break;
        case 5: deleteColor(); break;
        case 6: SetEnabled(); break;
        case 7: ChIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: rename(); break;
        case 9: LoadColorList(); break;
        case 10: PictureButtonCliked(); break;
        case 11: mainWindowSetsEnabled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: resetColorMnu(); break;
        case 13: resetColor(); break;
        case 14: quickSetColor(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
