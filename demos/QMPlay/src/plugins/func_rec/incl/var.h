#ifndef __VAR_H__
#define __VAR_H__

#include <QLibrary>
#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

QTimer timer;
int rate, bits, chn, snd, tim;
bool doEnd, hOptions(0), hFuncWin(1), sav, Pause, problem(0), timAdd(0);
bool trwa(0);

QString QMPConf;
QSettings *QMPset;
QString text;

const int timRefValue(250);
QTimer timRef;

#include "QLib.cpp"
#include "QOut.cpp"

QMPOut *QOut = 0;

#ifdef Q_WS_WIN
	const QString QMPOutf = "lib/qmp_out";
#else
	const QString QMPOutf = "lib/libqmp_out";
#endif

#ifdef Q_WS_MAC
	const QString libExt = ".dylib";
#endif
#ifdef Q_WS_WIN
	const QString libExt = ".dll";
#endif
#ifdef Q_WS_X11
	const QString libExt = ".so";
#endif

#endif
