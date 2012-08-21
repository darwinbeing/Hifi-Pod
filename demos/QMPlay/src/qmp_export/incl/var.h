#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QLibrary>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QFileDialog>

QStringList Texts;
const int langCount(3);

#include "QLib.cpp"

Qmp *QLib = NULL;

int bits2;
QString errStr, fPth, ext;
bool PlErr, hOptions(1);
bool isOpen, raw, sch;
FILE *file = NULL;
QSettings *QMPset;
QString QMPConf;

#endif
