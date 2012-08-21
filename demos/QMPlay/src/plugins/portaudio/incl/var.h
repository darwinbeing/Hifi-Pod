#ifndef __VAR_H__
#define __VAR_H__

#include <QLibrary>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <portaudio.h>
#include <QTextCodec>

#include "QLib.cpp"

Qmp *QLib = NULL;
QString errStr;
bool PlErr;
double lB, lNB;
QStringList devices[2],devicesN[2];
bool Enabled,zB;
bool isOpen, hOptions(1);
int Left,Right;
QString QMPConf;
QSettings * QMPset;
QDesktopWidget qdw;
PaStreamParameters outputParameters, inputParameters;
PaStream *stream;
int rate,bits,chn,devIndex,devIndexPA,devIndexN,devIndexNPA;
bool pauseD, REC(0), mustReset(0), fromBtn;
QString dN, dNN;

#ifdef Q_OS_LINUX
	bool autoSurround;
#endif

#endif
