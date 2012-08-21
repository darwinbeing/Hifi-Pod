#include <QApplication>
#include <QFileSystemWatcher>
#include <signal.h>
#include <stdio.h>

#include "musicInfo.h"
#include "miniQMP.h"
#include "formDockCh.h"
#include "formDownload.h"
#include "formCp.h"
#include "formProp.h"
#include "formLang.h"
#include "formStyle.h"
#include "formSL.h"
#include "formFunc.h"
#include "formPlaylist.h"
#include "formSetup.h"
#include "formAbout.h"
#include "form1.h"

void connecty();
void sigInt(int);

#include "QLib.cpp"

Qmp *QLib;
QString QMPConf, QsignalE, QMPfiles;
QFileSystemWatcher sysW;

Form1 &f1 = *new Form1;
FormPlaylist &fp = *new FormPlaylist;
FormSetup &fs = *new FormSetup;
FormFunc &ff = *new FormFunc;
FormSL &fsl = *new FormSL;
FormStyle &fst = *new FormStyle;
FormAbout &fa = *new FormAbout;
FormLang &fl = *new FormLang;
FormProp &fpr = *new FormProp;
FormCp &fcp = *new FormCp;
FormDownload &fd = *new FormDownload;
FormDock &fdck = *new FormDock;
miniQmp &mQ = *new miniQmp;
musicInfo &mI = *new musicInfo;

#include "forms.cpp"

#ifdef Q_OS_MAC
void qt_mac_set_dock_menu( QMenu * );
#endif

void showTray()
{
	tray.setIcon( QMPIcon );
	tray.setToolTip("QMPlay");
#ifdef Q_OS_MAC
	qt_mac_set_dock_menu( &trayMnu );
#else
	tray.setContextMenu( &trayMnu );
#endif
}

void setIcons()
{
	QMPIconPix = QPixmap( ":/icons/play_64x64.png" );

	QMPIcon = QIcon( ":/icons/play_64x64.png" );

	PlayIcon = QIcon( ":/icons/play.png" );
	StopIcon = QIcon( ":/icons/stop.png" );
	NxtIcon = QIcon( ":/icons/nxt.png" );
	PrevIcon = QIcon( ":/icons/prev.png" );
	PauseIcon = QIcon( ":/icons/pause.png" );
	RecIcon = QIcon( ":/icons/rec.png" );


	f1.ui.pauseButton->setIcon( PauseIcon );
	f1.ui.stopButton->setIcon( StopIcon );
	f1.ui.nextButton->setIcon( NxtIcon );
	f1.ui.prevButton->setIcon( PrevIcon );
	f1.ui.playButton->setIcon( PlayIcon );
	f1.ui.QMPB->setIcon( QMPIcon );

	f1.ui.actionPause->setIcon( PauseIcon );
	f1.ui.actionStop->setIcon( StopIcon );
	f1.ui.actionNext->setIcon( NxtIcon );
	f1.ui.actionPrevious->setIcon( PrevIcon );
	f1.ui.actionPlay->setIcon( PlayIcon );

	mQ.ui.pauseB->setIcon( PauseIcon );
	mQ.ui.stopB->setIcon( StopIcon );
	mQ.ui.nextB->setIcon( NxtIcon );
	mQ.ui.prevB->setIcon( PrevIcon );
	mQ.ui.playB->setIcon( PlayIcon );


	f1.ui.actionAB->setIcon( QMPIcon );


	qApp->setWindowIcon( QMPIcon );

	f1.setWindowIcon( qApp->windowIcon() );
	fp.setWindowIcon( qApp->windowIcon() );
	fs.setWindowIcon( qApp->windowIcon() );
	ff.setWindowIcon( qApp->windowIcon() );
	fsl.setWindowIcon( qApp->windowIcon() );
	fst.setWindowIcon( qApp->windowIcon() );
	fa.setWindowIcon( qApp->windowIcon() );
	fl.setWindowIcon( qApp->windowIcon() );
	fpr.setWindowIcon( qApp->windowIcon() );
	fd.setWindowIcon( qApp->windowIcon() );
	fdck.setWindowIcon( qApp->windowIcon() );
	mQ.setWindowIcon( qApp->windowIcon() );
	mI.setWindowIcon( qApp->windowIcon() );
}

void QmpMain( const QStringList &argv, Qmp* _QLib, QString _QMPConf, QString _QsignalE, QString _QMPfiles )
{
	QMPConf = _QMPConf;
	QMPfiles = _QMPfiles;
	QsignalE = _QsignalE;
	QLib = _QLib;

#ifdef Q_OS_WIN
	if ( !isOldWindows )
#endif
		signal( SIGINT, sigInt );

#ifdef Q_OS_UNIX
	if ( getenv( "KDE_FULL_SESSION" ) )
		UnixOpenCommand = "kfmclient exec ";
	else if ( getenv( "GNOME_DESKTOP_SESSION_ID" ) )
		UnixOpenCommand = "gnome-open ";
	else
		UnixOpenCommand = "xdg-open ";
#endif
#ifdef Q_OS_MAC
	UnixOpenCommand = "open ";
#endif

	fp.LOAD();
	connecty();
	qApp->setQuitOnLastWindowClosed(false);
	int argc = argv.size();
	if ( argc > 1 )
	{
		opcja = argv[ 1 ];
		if ( opcja[0] == '-' && argc > 2 && ( opcja == "--alast" || opcja == "-al" ) )
			opcja = "-np";
		else if ( opcja[0] == '-' && argc > 2 && opcja != "--noplay" && opcja != "-np" && opcja != "-a" && opcja != "--add" )
			opcja = argv[ 2 ];
	}
	setIcons();

	showTray();
	f1.Init();
}

void sigInt(int)
{
#ifndef Q_WS_WIN
	const int SC = SIGKILL;
#else
	const int SC = SIGBREAK;
#endif
	static int ile = 0;
	printf("\nQMP received signal: SIGINT...\n");
	ile++;
	if ( ile == 1 )
		QTimer::singleShot( 0, &f1, SLOT( close() ) );
	else
		raise(SC);
}

void pu( char param )
{
	switch ( param )
	{
		case 0x0:  fp.pu0(); break;
		case 0x1:  fp.pu1(); break;
		case 0x2:  fp.pu2(); break;
		case 0x3:  fp.pu3(); break;
		case 0x4:  fp.pu4(); break;
	}
}

void _selA()
{
	if ( f1.ui.selMusA->isChecked() )
	{
		f1.ui.selMusA->setChecked( false );
		selMus = false;
	}
	else
	{
		f1.ui.selMusA->setChecked( true );
		selMus = true;
	}
}

void _NextXs()
{
	if ( f1.ui.nextXs->isChecked() )
	{
		f1.ui.nextXs->setChecked( false );
		nextXs = false;
	}
	else
	{
		f1.ui.nextXs->setChecked( true );
		nextXs = true;
	}
}

void Play()
{
	if ( plistthr.isRunning() )
		signal_Play = true;
	else
		f1.play();
}

void lastOnList()
{
	if ( plistthr.isRunning() )
		signal_lastOnList = true;
	else if ( titlelist->count() > 0 )
		titlelist->setCurrentRow( titlelist->count() - 1 );
}

void addToPlayList( QStringList aName, int where )
{
	if ( aName.isEmpty() )
		return;
	plistthr.tcr = titlelist->currentRow();

	QStringList pths;
	for ( int i = 0 ; i < aName.count() ; i++ )
		if ( !fp.listPLstChk( aName[i] ) )
			pths += aName[i];

	if ( pths.isEmpty() )
		return;
	fp.addToList( pths, where );
	pths.clear();
}

void control( char sig, int param )
{
	switch ( sig )
	{
		case 0x0:  Play(); break;
		case 0x1:  f1.stop(); break;
		case 0x2:  f1.nextB(); break;
		case 0x3:  f1.prevB(); break;
		case 0x4:  f1.MinMax(); break;
		case 0x5:  f1.seekP( param ); break;
		case 0x6:  f1.quit(); break;
		case 0x7:  f1.opcje(); break;
		case 0x8:  f1.showplaylist(); break;
		case 0x9:  f1.pause(); break;
		case 0xA:
			if ( !param )
				f1.musinfo();
			else if ( param == 1 )
				f1.musinfoClose();
			break;
		case 0xB:  f1.funkcje_opn(); break;
		case 0xC:  f1.aWAV(); break;
		case 0xD:  f1.miniQMP(); break;
		case 0xE:  f1.SoH(); break;
		case 0xF:  fp.wlasciwosci(); break;
		case 0x10: _NextXs(); break;
		case 0x11: _selA(); break;
		case 0x12: pu( param ); break;
		case 0x13: fp.loadPL(); break;
		case 0x14: fp.nextPL(); break;
		case 0x15: fp.prevPL(); break;
		case 0x16: fp.clrlist(); break;
		case 0x17: fp.clrplist(); break;
		case 0x18:
			if ( titlelist->count() > param )
				titlelist->setCurrentRow(param);
			break;
		case 0x19:
			lastPosChMusInfo = -2;
			fp.chMusInfo();
			break;
		case 0x20:
			if ( Func.chkFNr( nrplay ) )
				fp.updatePlistEntryIfNeed( nrplay );
			break;
		case 0x21:
			f1.volup();
			break;
		case 0x22:
			f1.voldown();
			break;
		case 0x23:
			f1.Tpause();
			break;
	}
}

void getWindowFrame( int *s1, int *s2 )
{
	f1.getFrameSize();
	if (s1)
		*s1 = titleBS;
	if (s2)
		*s2 = frameS;
}

void getVol( int *vol )
{
	vol[0] = f1.ui.volLS->value();
	vol[1] = f1.ui.volRS->value();
}

void setVol( int *vol )
{
	f1.setVolR( vol );
}

void getPlistEntry( QStringList *list )
{
	list[0] += playList[0];
	list[1] += playList[1];
	list[2] += playList[2];
	list[3] += playList[3];
	list[4] += playList[4];
}

QString getSupportedExts()
{
	return Func.getExts(1);
}

void showMessage( QString title, QString msg, int icon, int msec, bool showOnlyInWindowIsNotVisible )
{
	Tray.showTrayMessage( title, msg, icon, msec, showOnlyInWindowIsNotVisible, NULL );
}
void showMessageAct( QString title, QString msg, int icon, int msec, bool showOnlyInWindowIsNotVisible, void (*act)() )
{
	Tray.showTrayMessage( title, msg, icon, msec, showOnlyInWindowIsNotVisible, act );
}

void updateCurrPlistEntry( QString s )
{
	if ( !s.isEmpty() && isPlaying && nrplay < playList[0].count() )
	{
		playList[0][ nrplay ] = s;
		fp.updatePlistEntry2( nrplay );
	}
}

bool chkState( ChkState p )
{
	switch(p)
	{
		case IS_PLAYING:
			return isPlaying;
			break;
		default:
			return 0;
	}
}

QWidget *getParent( getPar p )
{
	switch ( p )
	{
		case QMP_MAIN:
			return &f1;
			break;
		case QMP_PLAYLIST:
			return &fp;
			break;
		case QMP_SETUP:
			return &fs;
			break;
		case QMP_FUNC:
			return &ff;
			break;
		case QMP_ABOUT:
			return &fa;
			break;
		case QMP_MAIN_OR_PLIST:
			if ( f1.isActiveWindow() || fpnf1 )
				return &f1;
			else
				return &fp;
			break;
		case QMP_MINI:
			return &mQ;
			break;
		default:
			return 0;
			break;
	}
}

bool chkLoad( ChkLoad p )
{
	switch ( p )
	{
		case QMP_LOADED:
			return timref.isActive();
			break;
		case QMP_PLUGINS_LOADED:
			return pluginsLoaded;
			break;
		default:
			return 0;
			break;
	}
}

QString getFileName( FileName fn )
{
	switch (fn)
	{
		case QMP_CONF:
			return QMPConf;
			break;
		case OS_LIBEXT:
			return libExt;
			break;
		case OS_PPN:
			return ppN;
			break;
		case QMP_INTERNET:
			return QMPInternetf;
			break;
		default:
			return "";
			break;
	}
}

void addToLog(QString s)
{
	fa.add(s);
}

QSize getOkienkoSize()
{
	return f1.ui.okno->size();
}

QMPOut *getOutLib()
{
	return QOut;
}

void dockInF1(QWidget *w,bool f,void(*_unDock)())
{
	f1.dockInF1(w,f,_unDock);
}
QWidget *InDock()
{
	return inDock;
}

void MiniQMP(bool visible, QPoint pos, int W)
{
	if ( visible )
	{
		if ( mQ.isVisible() )
			mQ.close();
		mQ.dockVis = !f1.isVisible();
		mQ.setPos( pos );
		mQ.setW( W );
		mQ.Show( false );
	}
	else
		mQ.close();
}

QString currPath(QString *s)
{
	if ( s )
		Func.CURP(*s);
	return curP;
}

QString getPlugFNameForName( const char *plugName )
{
	QString plugFName;
	for ( int i = 0 ; i < pluginInfoList.count() ; i++ )
	{
		if ( !strcmp(pluginInfoList[i]->Name, plugName ) && pluginsList[3][i] == "y" )
		{
			plugFName = pluginsList[0][i];
			break;
		}
	}
	return plugFName;
}

int getInfo( QMP_INFO qi )
{
	switch(qi)
	{
		case QMP_NRPLAY:
			return nrplay;
			break;
		case QMP_CURRITEMSEL:
			return Func.nr();
			break;
		default:
			return -1;
			break;
	}
}

int getCpuSpeed()
{
	return Func.getCpuSpeed();
}

QList<VisPlugin*> getVPluginsList()
{
	return Vplugins;
}

bool open( QString file )
{
	return Func.open( file );
}

QStringList fileDialog( QMP_FILEDIALOG type, QWidget *parent, QString caption, QString dir, QString filter, QString *selectedFilter )
{
	return Func.fileDialog( type, parent, caption, dir, filter, selectedFilter );
}

QIcon getIcon( QMP_GETICON icon )
{
	switch ( icon )
	{
		case PLAY_ICON:
			return PlayIcon;
			break;
		case STOP_ICON:
			return StopIcon;
			break;
		case NXT_ICON:
			return NxtIcon;
			break;
		case PREV_ICON:
			return PrevIcon;
			break;
		case PAUSE_ICON:
			return PauseIcon;
			break;
		case REC_ICON:
			return RecIcon;
			break;
		default:
			return QIcon();
	}
}

QString getFSize( long long s )
{
	return Func.getFSize( s );
}

QString stringOperations( QMP_STRINGOPERATIONS QMP_StringOperations, QString str )
{
	switch ( QMP_StringOperations )
	{
		case PLIK_BEZ_SCIEZKI:
			return Func.plikbezsciezki( str );
		case SCIEZKA_DO_PLIKU:
			return Func.sciezkadopliku( str );
		default:
			return "";
	}
}

Qmp qmp =
{
	QmpMain,
	control,
	getVol,
	setVol,
	getWindowFrame,
	addToPlayList,
	lastOnList,
	getPlistEntry,
	getSupportedExts,
	showMessage,
	updateCurrPlistEntry,
	getParent,
	chkLoad,
	getFileName,
	addToLog,
	chkState,
	getOkienkoSize,
	showMessageAct,
	getOutLib,
	dockInF1,
	InDock,
	MiniQMP,
	QMPVer,
	currPath,
	getPlugFNameForName,
	getInfo,
	getCpuSpeed,
	getVPluginsList,
	open,
	fileDialog,
	getIcon,
	getFSize,
	stringOperations
};
