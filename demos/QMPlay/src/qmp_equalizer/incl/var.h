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

#include "kiss_fft.h"

#include "QLib.cpp"
Qmp *QLib = NULL;

bool Enabled,hOptions(1),inSW;
QString QMPConf;
QSettings * QMPset;
QDesktopWidget qdw;
int valEq[9];
int bands = 9;
QWidget *EqW;
QRect eqgeo;
int wc(0);
bool sw(0), glW(0);
QTimer timEq;

bool first(1);

bool noShow(0);

const int len (1024);
const int len2(512);
QList<float *> buff;
QList<float *> buf;
float *buffer = NULL, *lastWindow = NULL, *thisWindow = NULL, *filterFunc = new float[ len2 ], mn, *WinFunc = NULL;
bool mustClrEqBuff = false;

int oldbufsize(0), oldchn(0), oldBits(0);

int min(0), max(0);

bool frq(0);
char mode(0);

bool invert = true, doing = false;

kiss_fft_cfg cfg1 = NULL;
kiss_fft_cfg cfg2 = NULL;
kiss_fft_cpx *in = NULL, *out = NULL;

#endif
