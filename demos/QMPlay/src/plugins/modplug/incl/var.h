#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <modplug.h>

#include "QLib.cpp"
#include "QOut.cpp"

Qmp *QLib = NULL;
QMPOut *QOut;

bool setMFInit,bolStop,plSpec,IsPlaying,IsPaused, BS = false;
int savsek;
int timRefValue(25),tmptime;
int chn, bits, rate, Resampling, bass1, bass2, reverb1, reverb2, surround1, surround2, vol;
bool loop, surround(0), reverb(0), bass(0), Oversampling, NoiseR, showTime(0);
QString curF;

int spd(0),tmp(0),row(0),typ(0),chnmod(0),pat(0)  ,  inst(0),smpl(0),numpat(0),numchn(0)  ,  _pat(0)  ,  oldPat(0), oldRow(0);
unsigned int rowCount(0);

int fmsW,fmsH;

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
int plMaxtime(0);
QString QMPConf;
QTimer timref, setupTimer;
QSettings * QMPset;
QDesktopWidget qdw;

bool hOptions(1);
QString getBR("n/a");

ModPlug_Settings mpset;
ModPlugFile *module;

QWidget *tmpWidget;

ModPlugNote* mpn;

#endif
