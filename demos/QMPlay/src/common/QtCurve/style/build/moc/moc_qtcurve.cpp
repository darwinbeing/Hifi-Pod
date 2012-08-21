/****************************************************************************
** Meta object code from reading C++ file 'qtcurve.h'
**
** Created: Tue Aug 21 20:30:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtcurve.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtcurve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtCurveStyle[] = {

 // content:
       4,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
      18,   13,

 // slots: signature, parameters, type, tag, flags
      42,   40,   39,   39, 0x08,
      92,   74,   68,   39, 0x08,
     181,  170,   68,   39, 0x28,
     248,  244,   68,   39, 0x28,
     339,  295,  291,   39, 0x08,
     475,  469,   39,   39, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtCurveStyle[] = {
    "QtCurveStyle\0true\0X-KDE-CustomElements\0"
    "\0o\0widgetDestroyed(QObject*)\0QIcon\0"
    "pix,option,widget\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*,const QW"
    "idget*)\0"
    "pix,option\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*)\0"
    "pix\0standardIconImplementation(StandardPixmap)\0"
    "int\0control1,control2,orientation,option,widget\0"
    "layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::Cont"
    "rolType,Qt::Orientation,const QStyleOption*,const QWidget*)\0"
    "type,\0kdeGlobalSettingsChange(int,int)\0"
};

const QMetaObject QtCurveStyle::staticMetaObject = {
    { &QCommonStyle::staticMetaObject, qt_meta_stringdata_QtCurveStyle,
      qt_meta_data_QtCurveStyle, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtCurveStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtCurveStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtCurveStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtCurveStyle))
        return static_cast<void*>(const_cast< QtCurveStyle*>(this));
    return QCommonStyle::qt_metacast(_clname);
}

int QtCurveStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCommonStyle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: widgetDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: { QIcon _r = standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])),(*reinterpret_cast< const QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 2: { QIcon _r = standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 3: { QIcon _r = standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 4: { int _r = layoutSpacingImplementation((*reinterpret_cast< QSizePolicy::ControlType(*)>(_a[1])),(*reinterpret_cast< QSizePolicy::ControlType(*)>(_a[2])),(*reinterpret_cast< Qt::Orientation(*)>(_a[3])),(*reinterpret_cast< const QStyleOption*(*)>(_a[4])),(*reinterpret_cast< const QWidget*(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: kdeGlobalSettingsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
