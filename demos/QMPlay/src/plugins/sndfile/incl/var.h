#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

#include <sndfile.h>

#include "QLib.cpp"
#include "QOut.cpp"

Qmp *QLib = NULL;
QMPOut *QOut = NULL;

bool bolStop,plSpec,IsPlaying,IsPaused, updateF(0), BS = false;
int rate,chn;
int savsek;
int timRefValue(160);
QString curF, getBR;

bool tagWindowOpened(0);
QWidget *tagEditorWin = NULL;

int fosW,fosH;

QTimer setupTimer;
QString title;
QString formatSupport;
int pltime(0);
int NumPos(0);
int SongPos(0);
bool MUSerr(0);
bool pauseD(0);
bool mustReset(0);
bool endSong(0);
int plMaxtime(0);
QString QMPConf;
QTimer timref;
QSettings *QMPset;
bool Enabled, hOptions(1);

bool nowReading = false;
bool seeking = false;
SNDFILE *snd = NULL;
SF_INFO sndInfo;

QString sndfileInfoStr;
QImage pix;

QWidget *tmpWidget = NULL;

#endif
