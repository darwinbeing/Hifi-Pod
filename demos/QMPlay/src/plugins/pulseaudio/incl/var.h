#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QSettings>
#include <QMessageBox>

#include "QLib.cpp"

QString errStr;
bool PlErr;
bool Enabled;
bool isOpen, hOptions = true;
int Left,Right;
QString QMPConf;
QSettings *QMPset;
bool mustReset = false, REC = false, pauseD = false;
double delay = 0.08;

#endif
