#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QFile>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QMenu>
#include <QTimer>
#include <QDir>
#include <QKeyEvent>
#include <QFileInfo>

#include <cddb/cddb.h>
#include <cdio/cdio.h>

#define BYTES_PER_SECTOR 2352

QMenu mnu;
QString currCD;
int currBytes(0);
bool seeked(0);
int sectorsToSeek(0);

#include "QLib.cpp"
Qmp *QLib = NULL;

const int langCount(12+1);
QStringList Texts;

#include "QOut.cpp"
QMPOut *QOut;

bool bolStop,IsPlaying,IsPaused, updateEdits(0), updateEditsDrive(0), BS = false;
int chn;
int savsek;
QString curF, getBR;

QTimer timRef;

int fisW, fisH;

bool useUserDatabase(0), useFDB(1), useCddbp(0), readCDTXT(1);
QString userDatabaseServer;

bool loadFirst(0), useCDDB(1), clrB(1);
bool useDefaultCacheDir(0), useProxy(0);
unsigned short proxyPort(0);
QString proxyAddr;

bool posNow;
QString title;
#ifdef Q_WS_WIN
	QString formatSupport("cda");
#else
	QString formatSupport;
#endif
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
QDesktopWidget qdw;
bool Enabled, hOptions(1);

QTimer setupTimer;
QWidget *tmpWidget;

int speed;

#endif
