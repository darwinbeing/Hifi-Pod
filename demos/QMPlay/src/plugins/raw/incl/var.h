#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

#include "QLib.cpp"
#include "QOut.cpp"

Qmp *QLib = NULL;
QMPOut *QOut = NULL;

bool bolStop,plSpec,IsPlaying,IsPaused, BS = false;
int rate,chn;
int savsek;
int bits;
QString curF, getBR;
int skipB = 0;

QTimer setupTimer;
bool posNow;
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
QSettings *QMPset;
bool Enabled, hOptions(1);

int srateB, BITS, chnB;
bool u8B, be;

QWidget *tmpWidget = NULL;

FILE *fE = NULL;

#endif
