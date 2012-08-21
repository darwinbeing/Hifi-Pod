#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTimer>
#include <QMenu>
#include <math.h>

#include "QLib.cpp"
Qmp *QLib = NULL;

QString homeP = QDir::homePath();
bool Enabled;
bool isOpen, closing;
QString QMPConf;
QSettings *QMPset;
QDesktopWidget qdw;
int chn;
bool okno,sB,lpB,sngTB,okienko;
QString textFile;
int VisX,VisY,VisW,VisH;
int tims(0),timRefValue;
QTimer timRef, setupTimer, cursorTim;

bool noShow(0), inDock(0), dockEnable(0);

#define maxSmpl 96000
#define maxChn 8

float X(-1.0f);
QList<float *> y_1;
float x_1[maxSmpl];
float f[maxChn] = { -.5,.5 };
int bytes;

bool cleaning(0);

int l,r;

float sl2,sr2;
float sl,sr;

bool wasInDock = false;
QAction *fsAct = NULL;

QString qwe;
bool napref,hOptions(1);

QList<float *> v;
int lastChn = 2;
int tm = 0;

float tmpSek = 0;

QMenu p;

QWidget *oW, *qW, *okienkoParent;

bool kolor2(0), kreski(0), paski(0);

#endif
