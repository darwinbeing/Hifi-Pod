#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QSettings>
#include <QMessageBox>
#include <ao/ao.h>

#include "QLib.cpp"

QString errStr;
bool PlErr;
bool Enabled;
bool isOpen, hOptions(1);
ao_device *AO_Device;
ao_sample_format fmt;
int drv, Left,Right;
QString QMPConf;
QSettings *QMPset;
bool mustReset(0);
int drvid(0),drvcount(0);
ao_info **aoinfo;

#endif
