/****************************************************************************
** Meta object code from reading C++ file 'form1.h'
**
** Created: Tue Aug 21 08:06:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../forms/form1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form1[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      14,    6,    6,    6, 0x0a,
      21,    6,    6,    6, 0x0a,
      31,    6,    6,    6, 0x0a,
      38,    6,    6,    6, 0x0a,
      44,    6,    6,    6, 0x0a,
      50,    6,    6,    6, 0x0a,
      58,    6,    6,    6, 0x0a,
      73,    6,    6,    6, 0x0a,
      84,    6,    6,    6, 0x0a,
      98,    6,    6,    6, 0x0a,
     105,    6,    6,    6, 0x0a,
     112,    6,    6,    6, 0x0a,
     122,    6,    6,    6, 0x0a,
     134,    6,    6,    6, 0x0a,
     143,    6,    6,    6, 0x0a,
     151,    6,    6,    6, 0x0a,
     159,    6,    6,    6, 0x0a,
     170,    6,    6,    6, 0x0a,
     179,    6,    6,    6, 0x0a,
     187,    6,    6,    6, 0x0a,
     197,    6,    6,    6, 0x0a,
     208,    6,    6,    6, 0x0a,
     220,    6,    6,    6, 0x0a,
     234,    6,    6,    6, 0x0a,
     240,    6,    6,    6, 0x0a,
     246,    6,    6,    6, 0x0a,
     253,    6,    6,    6, 0x0a,
     260,    6,    6,    6, 0x0a,
     266,    6,    6,    6, 0x0a,
     308,    6,    6,    6, 0x0a,
     329,    6,    6,    6, 0x0a,
     344,    6,    6,    6, 0x0a,
     357,    6,    6,    6, 0x0a,
     367,    6,    6,    6, 0x0a,
     376,    6,    6,    6, 0x0a,
     385,    6,    6,    6, 0x0a,
     399,    6,    6,    6, 0x0a,
     420,    6,    6,    6, 0x0a,
     433,    6,    6,    6, 0x0a,
     443,    6,    6,    6, 0x0a,
     457,    6,    6,    6, 0x0a,
     480,    6,    6,    6, 0x0a,
     490,    6,    6,    6, 0x0a,
     508,    6,    6,    6, 0x0a,
     522,    6,    6,    6, 0x0a,
     535,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Form1[] = {
    "Form1\0\0quit()\0play()\0musinfo()\0stop()\0"
    "slR()\0slP()\0opcje()\0showplaylist()\0"
    "timrefDo()\0funkcje_opn()\0info()\0aWAV()\0"
    "slAT(int)\0setVol(int)\0savMus()\0nextB()\0"
    "prevB()\0AboutQMP()\0NextXs()\0volup()\0"
    "voldown()\0minimize()\0seekP(bool)\0"
    "setVolR(int*)\0pwp()\0pwl()\0netA()\0"
    "selA()\0SoH()\0mnuAct(QSystemTrayIcon::ActivationReason)\0"
    "checkUpdatesButton()\0checkUpdates()\0"
    "updateQVis()\0BTpause()\0showEq()\0"
    "volMnu()\0setBothVolB()\0TrayMessageClicked()\0"
    "showMnuOpt()\0miniQMP()\0showTrayMnu()\0"
    "setVolFromMiniQMP(int)\0opisQMP()\0"
    "resetInfoWindow()\0miniVersion()\0"
    "copyTitleA()\0fileChanged()\0"
};

const QMetaObject Form1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Form1,
      qt_meta_data_Form1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form1))
        return static_cast<void*>(const_cast< Form1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Form1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quit(); break;
        case 1: play(); break;
        case 2: musinfo(); break;
        case 3: stop(); break;
        case 4: slR(); break;
        case 5: slP(); break;
        case 6: opcje(); break;
        case 7: showplaylist(); break;
        case 8: timrefDo(); break;
        case 9: funkcje_opn(); break;
        case 10: info(); break;
        case 11: aWAV(); break;
        case 12: slAT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: setVol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: savMus(); break;
        case 15: nextB(); break;
        case 16: prevB(); break;
        case 17: AboutQMP(); break;
        case 18: NextXs(); break;
        case 19: volup(); break;
        case 20: voldown(); break;
        case 21: minimize(); break;
        case 22: seekP((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: setVolR((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 24: pwp(); break;
        case 25: pwl(); break;
        case 26: netA(); break;
        case 27: selA(); break;
        case 28: SoH(); break;
        case 29: mnuAct((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 30: checkUpdatesButton(); break;
        case 31: checkUpdates(); break;
        case 32: updateQVis(); break;
        case 33: BTpause(); break;
        case 34: showEq(); break;
        case 35: volMnu(); break;
        case 36: setBothVolB(); break;
        case 37: TrayMessageClicked(); break;
        case 38: showMnuOpt(); break;
        case 39: miniQMP(); break;
        case 40: showTrayMnu(); break;
        case 41: setVolFromMiniQMP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: opisQMP(); break;
        case 43: resetInfoWindow(); break;
        case 44: miniVersion(); break;
        case 45: copyTitleA(); break;
        case 46: fileChanged(); break;
        default: ;
        }
        _id -= 47;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
