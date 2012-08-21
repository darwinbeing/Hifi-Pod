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
bool isOpen, closing;
QString QMPConf;
QSettings *QMPset;
QDesktopWidget qdw;
bool okno,okienko,hOptions(1);
int VisX,VisY,VisW,VisH;
QTimer timRef, setupTimer, cursorTim;

bool cleaning(0);

bool wasInDock = false;
QAction *fsAct = NULL;

float y_1[1024];
float x_1[1024];

float tmp;
float v[1024];
int tm = 0;

int bytes;

int lpaski;
int *F = NULL;
float *f = NULL, *f2 = NULL;

float *spec;
kiss_fft_cpx *out = NULL;

int fftsize,scale,przesun,fftsize2,timRefValue;

bool fftP,fftL,fullScope,fftK;

const int fftDef(128);
const int sclDef(100);

bool noShow(0), inDock(0), dockEnable(0);

QMenu p;

QWidget *oW, *qW, *okienkoParent;

kiss_fft_cfg cfg = NULL;

#endif
