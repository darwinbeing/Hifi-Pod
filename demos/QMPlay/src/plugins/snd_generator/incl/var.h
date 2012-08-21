#include <QString>
#include <QTimer>
#include <QFile>
#include <QSettings>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QMenu>
#include <math.h>

#include "QLib.cpp"
Qmp *QLib = NULL;

#include "QOut.cpp"

QMPOut *QOut = NULL;
bool IsPlaying, bolStop, IsPaused, BS = false;
QString title;
QString formatSupport;
int pltime(0);
int NumPos(0);
int SongPos(0);
bool MUSerr(0);
bool pauseD(0);
bool mustReset(0);
bool endSong(0);
bool canUpdateEntry(0);
int plMaxtime(0);
QString QMPConf;
QTimer setupTimer;
QSettings *QMPset;
QDesktopWidget qdw;
bool Enabled;
int _chn;
bool hOptions(1);
QString getBR = "n/a";
int Hz,Hz2,Hz3,Hz4,Hz5,Hz6,Hz7,Hz8,_srate;

QWidget *tmpWidget = NULL;

QMenu mnu;
