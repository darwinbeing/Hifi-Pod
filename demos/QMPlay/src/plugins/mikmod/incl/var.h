#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <mikmod.h>

#include "QLib.cpp"
#include "QOut.cpp"

Qmp *QLib = NULL;
QMPOut *QOut = NULL;

bool interp,hqmixer,surround,bits16,stereo,reverse,softmusic,softsndfx,fadeout,loop;
bool setMFInit,bolStop,oneReg(0),plSpec, BS = false;
int mdmixfreq,pansep,reverb,chnMAX,mdvolume;
int savsek,savbpm,savspd;
int timRefValue;
QString curF;

int fsiposX,fsiposY;
int fsisW,fsisH, fmsW,fmsH;

bool Enabled;
QString title;
QString formatSupport;
int pltime(0);
int NumPos(0);
int SongPos(0);
bool MODerr(0);
bool pauseD(0);
bool mustReset(0);
bool endSong(0);
int plMaxtime(-1);
QString QMPConf;
QTimer timref, setupTimer;
QSettings *QMPset;
QDesktopWidget qdw;

bool hOptions(1);
QString getBR("n/a");

MODULE *module;

QWidget *tmpWidget;

#include "drv_qmp.cpp"

#endif
