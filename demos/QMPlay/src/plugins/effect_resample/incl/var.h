#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QLibrary>

QList<float *> dataI;
QList<float *> dataO;
QList<void * > Handle;

#include <cmath>

float tmpfactor = 0;
float oldfactor = 0;
float dz = 0;
int oldchn = 0, oldBUFSIZE = 0, oldBits = 0;

bool Enabled, autoFactor, hOptions(1), canChFactor(0), HQ(0), oldHQ(0);
float factor;
QString QMPConf;
QSettings *QMPset;

#include <libresample.h>

#endif
