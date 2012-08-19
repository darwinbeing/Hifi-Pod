#include "hotkey.h"
#include <QAbstractEventDispatcher>
#include <QHash>
#include <QX11Info>
#include <X11/Xlib.h>

static QHash<QPair<quint32, quint32>, Hotkey*> hotkeys;
static bool eventFilter(void* message) {
    XEvent* event = static_cast<XEvent*>(message);
    if (event->type == KeyPress) {
        XKeyEvent* key = (XKeyEvent*) event;
        Hotkey* hotkey = hotkeys.value(QPair<quint32, quint32>(
                key->keycode, key->state & (ShiftMask | ControlMask | Mod1Mask | Mod4Mask) ));
        if( hotkey ) hotkey->activate();
    }
    return false;
}

Hotkey::Hotkey(QString shortcut, QObject* parent ) : QObject(parent) {
    QAbstractEventDispatcher::instance()->setEventFilter(::eventFilter);
    Qt::KeyboardModifiers allMods = Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier | Qt::MetaModifier;
    Qt::KeyboardModifiers modifiers(QKeySequence(shortcut)[0] & allMods);
    mods = 0;
    if (modifiers & Qt::ShiftModifier) mods |= ShiftMask;
    if (modifiers & Qt::ControlModifier) mods |= ControlMask;
    if (modifiers & Qt::AltModifier) mods |= Mod1Mask;
    if (modifiers & Qt::MetaModifier) mods |= Mod4Mask;
    QString keystring = QKeySequence((QKeySequence(shortcut)[0] ^ allMods) & QKeySequence(shortcut)[0]).toString();
    KeySym keysym = XStringToKeysym(keystring.toLatin1().data());
    if(!keysym && shortcut=="XF86AudioPlay") keysym=0x1008ff14;
    key=XKeysymToKeycode(QX11Info::display(),keysym );
    hotkeys[QPair<quint32, quint32>(key,mods)] = this;
//    XGrabKey(QX11Info::display(), key, mods, QX11Info::appRootWindow(), True, GrabModeAsync, GrabModeAsync);
//    XGrabKey(QX11Info::display(), key, mods|Mod2Mask, QX11Info::appRootWindow(), True, GrabModeAsync, GrabModeAsync);
    XSync(QX11Info::display(), False);
}
void Hotkey::activate() { emit activated(); }
Hotkey::~Hotkey() {
//    XUngrabKey(QX11Info::display(), key, mods, QX11Info::appRootWindow());
//    XUngrabKey(QX11Info::display(), key, mods|Mod2Mask, QX11Info::appRootWindow());
    XSync(QX11Info::display(), False);
}
