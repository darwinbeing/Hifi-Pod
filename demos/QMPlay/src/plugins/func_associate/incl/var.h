#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

#include "QLib.cpp"
Qmp *QLib = NULL;

QTimer timer;

QWidget *tmpWidget = NULL;

const int langCount(5);
QStringList Texts;

bool hOptions(0), hFuncWin(1), mustGetExts(0), as(0), notInFunc(0);
bool once = false;

QSettings *QMPset;

QString QMPConf, libExt;

#endif
