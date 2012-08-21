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

#include <Functions.cpp>

#include <mpg123.h>

mpg123_frameinfo frameinfo;
mpg123_handle *musicfile = NULL;

#include "QLib.cpp"
Qmp *QLib = NULL;

#include "QOut.cpp"

#include "ID3.cpp"

QMPOut *QOut = NULL;

bool setMFInit,bolStop,plSpec,IsPlaying,IsPaused,updateF = false, BS = false;
int chn;
long rate;
int savsek;
int timRefValue(160);
QString curF;

int fosW,fosH;

QString Title, Artist, id3Str;
QImage pix;
bool tagWindowOpened(0), notReadID3(0);
QWidget *tagEditorWin = NULL;

bool posNow, knownSize;
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
QTimer timref, setupTimer;
QSettings *QMPset;
QDesktopWidget qdw;
bool Enabled;
int Type;
bool hOptions(1);
QString getBR;
int TMPint(0);
int tmpPltime(0);
bool canUpdateEntry(1);
long currBytes(0);

bool wait4Data(1), searchParts(1);

QWidget *tmpWidget = NULL;

#include "QMPInternet_Load.cpp"

#endif
