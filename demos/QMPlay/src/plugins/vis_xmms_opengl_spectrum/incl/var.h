#ifndef __VAR_H__
#define __VAR_H__

#include <QMenu>
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

bool Enabled, isON = false;
bool isOpen, _startTimer, closing;
QString QMPConf;
QSettings *QMPset;
QDesktopWidget qdw;
bool okno,okienko,hOptions(1), clr(0);
int VisX,VisY,VisW,VisH;
QTimer timRef, setupTimer, cursorTim;

bool wasInDock = false;
QAction *fsAct = NULL;

bool noShow(0), inDock(0), dockEnable(0);

short *spec;
float *real,*outreal,*outimag;
int timRefValue;

QMenu p;

QWidget *oW, *qW, *okienkoParent;

kiss_fft_cfg cfg = NULL;

#endif
