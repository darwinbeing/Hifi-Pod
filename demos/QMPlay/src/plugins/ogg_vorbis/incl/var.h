#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDesktopWidget>
#include <QTime>
#include <QMessageBox>

#include <vorbis/vorbisfile.h>

#include "QOut.cpp"
#include "QLib.cpp"
Qmp *QLib;

QMPOut *QOut;

bool setMFInit,bolStop,plSpec,IsPlaying,IsPaused,hOptions(1),updateF(0), BS = false;
int chn;
long rate;
int savsek;
int timRefValue(160);
QString curF;

bool tagWindowOpened(0);
QWidget *tagEditorWin = NULL;

int fosW,fosH;

QString Title, Artist;
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
QSettings * QMPset;
QDesktopWidget qdw;
bool Enabled(1);
QString getBR;
bool canUpdateEntry(1);

QString vorbisInfoStr;

long currBytes(0);

OggVorbis_File musicfile;

#include "QMPInternet_Load.cpp"

#endif
