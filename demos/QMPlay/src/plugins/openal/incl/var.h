#ifndef __VAR_H__
#define __VAR_H__

#include <QLibrary>
#include <QString>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTimer>
#include <AL/alc.h>
#include <AL/al.h>

#include <Functions.cpp>

#include "QLib.cpp"
Qmp *QLib = NULL;

QString errStr;
bool PlErr;
bool Enabled;
bool isOpen, hOptions(1);
int Left,Right;
QString QMPConf;
QSettings *QMPset;
QDesktopWidget qdw;
bool mustReset(0), REC(0);
bool onlyMultiChn(0);

QString devName;

ALCcontext *pContext = NULL;
ALCdevice *pDevice = NULL;
ALCdevice *captureDevice = NULL;
int NUM_BUFFERS;
ALuint *Buffers = NULL;
ALuint Source;
ALenum format;
ALint state, processed;
int tmpBC, bits, chn, srate;

#endif
