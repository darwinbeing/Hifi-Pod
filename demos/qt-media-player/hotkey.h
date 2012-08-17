#pragma once
#include <QObject>
#include <QKeySequence>

class Hotkey : public QObject {
    Q_OBJECT
public:
    Hotkey(QString shortcut, QObject* parent = 0);
    ~Hotkey();
public slots:
    void activate();
signals:
    void activated();
private:
    quint32 mods,key;
};
