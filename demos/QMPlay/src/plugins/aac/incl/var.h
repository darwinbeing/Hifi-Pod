#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QThread>
#define HAVE_STDINT_H
#include <mp4ff.h>
#undef HAVE_STDINT_H
#include <faad.h>

#include "QLib.cpp"
Qmp *QLib = NULL;

#include "QOut.cpp"

QMPOut *QOut = NULL;

bool setMFInit,bolStop,plSpec,IsPlaying,IsPaused,hOptions(1),updateF(0), BS = false;
int savsek;
int timRefValue(160);
QString curF;

int fosW,fosH;

QString Title, Artist, id3Str;
bool tagWindowOpened(0);
QWidget *tagEditorWin = NULL;

QString title;
QString formatSupport;
int pltime(0);
int NumPos(0);
int SongPos(0);
bool MUSerr(0);
bool pauseD(0);
bool mustReset(0);
bool endSong(0);
int  plMaxtime(0);
QString QMPConf;
QTimer timref;
QSettings *QMPset;
QDesktopWidget qdw;
bool Enabled(1);
QString getBR;
uint tmptime(0);
float TMPint(0);
bool canUpdateEntry(1);

#include "QMPInternet_Load.cpp"

#endif
