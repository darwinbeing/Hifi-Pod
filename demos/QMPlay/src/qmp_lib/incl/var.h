#include <QDesktopWidget>
#include <QStyleFactory>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QSettings>
#include <QTimer>
#include <QLibrary>
#include <QDir>
#include <QUrl>
#include <QDate>
#include <QTime>
#include <QSystemTrayIcon>
#include <QScrollArea>
#include <QColorDialog>
#include <QClipboard>
#ifdef Q_WS_WIN
	#include <process.h>
	#include <windows.h>
	#include <shlwapi.h>
#endif
#include <math.h>

#include <Functions.cpp>

enum QMP_RUN_OS
{
	QMP_LINUX = 1, QMP_WINDOWS, QMP_FREEBSD, QMP_MAC
};
QMP_RUN_OS getOS()
{
#ifdef Q_OS_LINUX
	return QMP_LINUX;
#endif
#ifdef Q_WS_WIN
	return QMP_WINDOWS;
#endif
#ifdef Q_OS_FREEBSD
	return QMP_FREEBSD;
#endif
#ifdef Q_OS_MAC
	return QMP_MAC;
#endif
}

#ifdef Q_WS_WIN
	bool isOldWindows = QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based;
#endif

enum ObjectPos
{
	None, Top, Bottom, Left, Right
};

#ifdef Q_WS_X11
		const QString UP_ARROW("ᐱ");
		const QString DOWN_ARROW("ᐯ");
#else
		const QString UP_ARROW("ˆ");
		const QString DOWN_ARROW("˘");
#endif

const uint QMPlayOutVer = 1516-1;
const uint QMPlayOutputPluginVer = 1521-1;
const uint QMPlayInputPluginVer = 1529-1;
const uint QMPlayVisPluginVer = 1506-1;
const uint QMPlayEffectPluginVer = 1516-1;
const uint QMPlayFuncPluginVer = 1528-1;
const uint QMPlayPlaylistPluginVer = 1529-1;
const uint QMPlayExportVer = 1528-1;
const uint QMPlayEqualizerVer = 1516-1;
const uint QMPlayLangVer = 1544-1;

extern const uint  QMPVersionI(154);
extern const uchar QMPVer2(06-1);
extern const uint  QMPVer( QMPVersionI * 10 + QMPVer2 );
extern const QString QMPVersion("v"+QString::number(QMPVersionI/100.)+"."+(QMPVer2+1<10?"0":"")+QString::number(QMPVer2+1));
extern const char QMPlayUpdatesAddress[] = { "http://zaps166.sourceforge.net/?dwn=qmplay/" };
extern const QString LogFile( QDir::tempPath() + "/QMPlay.log" );

uint lastVer = 0;

QString Default_QMP_style  = "QtCurve";
const QString Default_QMP_style2 = "Plastique";
#ifndef Q_OS_MAC
const QString defColorScheme = "QMPlay";
#else
const QString defColorScheme = "MacOS";
#endif

QIcon QMPIcon, PlayIcon, StopIcon, NxtIcon, PrevIcon, PauseIcon, RecIcon;
QPixmap QMPIconPix;

#ifdef Q_WS_WIN
	const QString ppN = "qmp_plugin_";
#else
	const QString ppN = "libqmp_plugin_";
#endif

#ifdef Q_WS_WIN
	const QString QMPWav = "lib/qmp_export";
	const QString QMPEqu = "lib/qmp_equalizer";
	const QString QMPOutf = "lib/qmp_out";
#else
	const QString QMPWav = "lib/libqmp_export";
	const QString QMPEqu = "lib/libqmp_equalizer";
	const QString QMPOutf = "lib/libqmp_out";
#endif

#include "libExt.h"

QStringList Texts;

#include "InputPlugin.cpp"
#include "OutputPlugin.cpp"
#include "EffectPlugin.cpp"
#include "VisPlugin.cpp"
#include "FuncPlugin.cpp"
#include "PlaylistPlugin.cpp"
#include "QOut.cpp"
#include "QExport.cpp"
#include "QMPInternet_Load.cpp"

QLibrary QOut_lib;
QLibrary WAVE;
QLibrary equalizer_lib;
QLibrary TmpLibrary;


QMPOut *QOut = NULL;
QMP_Export *QExport = NULL;
QMP_effects *equalizer = NULL;
QList<InputPlugin*> Iplugins;
QList<OutputPlugin*> Oplugins;
QList<QMP_effects*> Eplugins;
QList<VisPlugin*> Vplugins;
QList<FuncPlugin*> Fplugins;
QList<PlaylistPlugin*> Pplugins;
QList<PluginInfo*> pluginInfoList;
InputPlugin *Iplug;

#ifndef Q_WS_WIN
	QString UnixOpenCommand;
#endif

QFont _bold,_normal,_italic,_bolditalic;

QWidget *QOutWidget = new QWidget, *QEqWidget = new QWidget, *QExportWidget = new QWidget;
QWidget *inDock = NULL;
QString inDockObjName;
QList<QScrollArea*> scrolls;
QList<QWidget*> tabs;

QTimer timref, timCp, timQVis, timChImgs;
QString curP;
QStringList pluginsList[4]; //pluginy 0:nazwa pliku 1:nazwa 2:typ 3:czy zaladowany

QStringList playList[5]; //playlista 0:tytul 1:typ 2:nazwa pliku 3:czas w sek. 4:czy zaznaczony
QList< int > itemsQueue;

QStringList listPLst[2]; //lista playlist 0:nazwa pliku 1:nazwa
QString plistTimeStr;
QString styl;
QString language, langFile;
QStringList InternetProtocols;

QMenu &tLMenu = *new QMenu;
QMenu &pLMenu = *new QMenu;
QMenu &plugLM = *new QMenu;
QMenu &trayMnu = *new QMenu;
QMenu &menuFromPlugin = *new QMenu;
QMenu &menuAdd = *new QMenu;
QMenu &menuVol = *new QMenu;
QMenu &menuPlistAct = *new QMenu;
QMenu &mnuPlistWindow = *new QMenu;
QMenu &mnuDock = *new QMenu;
QMenu &mnuSearch = *new QMenu;

QAction *searchAction = new QAction(NULL);

QSystemTrayIcon tray;
QClipboard *clipboard = qApp->clipboard();

bool FirstTime = false;
bool problem(0),selMus(0), inTray(0), piAdd(0), signal_lastOnList(0), signal_Play(0), bladinfoB(0), bezzapisulisty(0), seekTime(0), eoplB(1);
int proce, po, nrplay;
int lastPosChMusInfo = -2;
bool wasShow(0), mQmpVisible(0), canShowPlaylist(0);

bool autoUpdates = true;
QString svrAddress;

bool ignore_sig(0);

bool Bpmpp(0); //Podglad muzyki podczas przewijania
bool secondLoad(0), fsMaximized(0), fileFilter(1);
int MusicPosVal(0);

bool isPlaying, plOnstrt, closeExportOnNxt, usunSets, uPLe, uPLeL,  chImgs, chImgsOnce(false);
QString file;
QString opcja, colorScheme;
int plistTime;
bool fpzf1, shwplaylist,fpnf1,zipl,zvpl,zplV,zdefB,zxplC;
bool ycPos, nextXs;
bool errnxt, playnxt, listplaylist, savplist;
bool npSng, slPressed;
QSettings *QMPset;
QDesktopWidget qdw;
int nextXsV(0), kBB;
QString title, exportTitle, oldExportTitle;
bool fileStruct, unknownType, pluginsLoaded(0); //rozpoznawanie plików po strukturze

//Window positions
QRect f1Geo, fsGeo, fpGeo, ffGeo, faGeo;
QPoint fprPos;

bool na(0); //pozostawia tytul
bool na4(0); //nie wywołuje czyscf1()
bool na3(0); //przełączanie piosenki

int frameS(0) /* grubość obramowania okna */;
int titleBS2(0) /* grubość paska tytułowego + frameS */;
int titleBS(0) /* grubość paska tytułowego */;
int f1h; //f1.minimumSize().height()
int f1w; //f1.minimumSize().width()
bool nrplay_update(0), MusInfoOpened(0), FileFormatSupportOpened(0);

QString formatSupport;
void closePlug(bool,bool){};
int pltime;
int NumPos;
int SongPos;
bool PlugErr;
bool pauseD;
bool mustReset;
bool endSong;
int plMaxtime;
void seek(int&){};
void togglePause(){};
void Init(bool,int){};
void clrPos(){};
QString getBR;
InputPlugin N0input =
{
	NULL,
	&formatSupport,
	NULL,
	NULL,
	closePlug,
	&PlugErr,
	&endSong,
	&mustReset,
	&pauseD,
	&NumPos,
	&SongPos,
	seek,
	togglePause,
	Init,
	NULL,
	&pltime,
	&plMaxtime,
	NULL,
	clrPos,
	&title,
	NULL,
	&getBR,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};
