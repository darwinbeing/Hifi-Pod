void QOut_STOP_AND_WAIT()
{
	if ( QOut->busy[1] )
		QOut->control( QOUT_STOP_AND_WAIT );
}

struct clsThrC : public QThread
{
	void (*func)();
	virtual void run()
	{
		if (func)
			func();
	}
};
bool QMPWait_n_close( void func() )
{
	bool b = true;
	clsThrC *clsThr = new clsThrC;
	clsThr->func = func;
	clsThr->start();
	clsThr->wait(2500);
	if ( clsThr->isRunning() )
	{
		clsThr->terminate();
		clsThr->wait(1000);
		b = false;
	}
	clsThr->func = NULL;
	delete clsThr;
	return b;
}

#include "func.h"

void plthr::setType()
{
	int X = nrplay = Func.nr();

	if ( playList[1][X] == "file" )
	{
		type = 0;
		path = file;
	}
	else if ( playList[1][X].left( 7 ) == "plugin:" )
	{
		type = 1;
		path = Func.getFNamePlugin( file, type );
	}
	else if ( playList[1][X].left( 9 ) == "internet:" )
	{
		type = 2;
		path = file;
	}
	else
		clr();
}
void plthr::run()
{
	if ( QOut->musParam[3] == "2" && priority() != QThread::TimeCriticalPriority )
		setPriority( QThread::TimeCriticalPriority );
	else if ( QOut->musParam[3] == "1" && priority() != QThread::HighestPriority )
		setPriority( QThread::HighestPriority );
	else if ( QOut->musParam[3] == "0" && priority() != QThread::HighPriority )
		setPriority( QThread::HighPriority );

	Func.getVol();

	QOut->busy[0] = true;
	isPlaying = true;

	if ( type < 0 && path.isEmpty() )
	{
		*Iplug->PlugErr = true;
		*Iplug->title = "Unknown error!";
	}
	else
		Iplug->play( path.toUtf8(), type );

	clr();
}
void plthr::clr()
{
	path.clear();
	type = -1;
}

bool plthr::doExit()
{
	if ( QOut->busy[0] )
	{
		if ( !na3 )
			QOut->control( QOUT_SILENCE );
		QOut->control( QOUT_MUST_STOP );
	}

	qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );

	if ( isPlaying || ( ( *QOut->mustReset && !QOut->busy[1] ) || *Iplug->mustReset ) )
		Iplug->closePlug(true,false); //zapis pozycji odtw. muzyki
	else
		Iplug->closePlug(false,true);

	*Iplug->mustReset = false;
	wait(4750);
	if ( isRunning() )
	{
		terminate();
		wait(1000);
		return true;
	}
	return false;
}


void plistthr::run()
{
	if ( runTitles )
		fp.titles();
	else
		fp.thrListRef2();
}
void plistthr::doExit()
{
	stop=true;
	wait(2000);
	if ( isRunning() )
	{
		terminate();
		wait(1000);
	}
}

void cpthr::run()
{
	val = 0;
	br = false;
	serror = 1;
	bool error = 1;

	if ( !c )
	{
		Count = 1;

		if ( QFile::exists( selfile ) )
			QFile::remove( selfile );

		error = QFile::copy( playList[2][X], selfile );
		if ( !error )
			fa.add( Texts[65] /**Copy*/ + " - " + Texts[83] /**Błąd*/ + ": " + Func.plikbezsciezki(selfile) );
		else
			fa.add( Texts[65] /**Copy*/ + " - OK: " + Func.plikbezsciezki(selfile) );

		serror = error;

		val = 1;
		return;
	}

	Count = titlelist->selectedItems().size();
	count = titlelist->count();
	selfile = Func.sciezkadopliku( selfile );
	for ( int i = 0 ; i < count ; i++ )
	{
		if ( br )
			break;
		if ( titlelist->item( i )->isSelected() )
		{
			fPth = playList[2][i];
			fName = Func.plikbezsciezki(fPth);
			if ( fPth != selfile+"/"+fName )
			{
				if ( QFile::exists( selfile+"/"+fName ) )
					QFile::remove( selfile+"/"+fName );

				error = QFile::copy( fPth , selfile+"/"+fName );
				if ( !error )
					fa.add( Texts[65] /**Copy*/ + " - " + Texts[83] /**Błąd*/ + ": " + fName );
				else
					fa.add( Texts[65] /**Copy*/ + " - OK: " + fName );

				if ( !error & serror )
					serror = error;

				val++;
			}
		}
	}
}
void cpthr::doExit()
{
	br = true;
	wait(1000);
	if ( isRunning() )
	{
		terminate();
		wait(1000);
	}
}

void addthr::run()
{
	br = false;
	added = false;
	QDir iDir;
	QString DIRpath, tmp2;
	int entryListSize;
	QStringList entryList;
	int DIRlistSize;

	if ( !scat )
	{
		DIRlistSize = DIRlist.size();
		for ( int i = 0 ; i < DIRlistSize ; i++ )
		{
			entryList.clear();
			iDir = DIRlist[i];
			DIRpath = DIRlist[i];
			entryList = iDir.entryList( QDir::Dirs | QDir::NoDotAndDotDot );
			entryListSize = entryList.size();
			for ( int j = 0 ; j < entryListSize ; j++ )
			{
				DIRlist += DIRpath + "/" + entryList[j];
				DIRlistSize++;
				if ( br )
					break;
			}
			if ( br )
				break;
		}
	}

	DIRlistSize = DIRlist.size();
	for ( int i = 0 ; i < DIRlistSize ; i++ )
	{
		entryList.clear();
		iDir = DIRlist[i];
		DIRpath = DIRlist[i];
		entryList = iDir.entryList( QDir::Files );
		entryListSize = entryList.size();
		for ( int j = 0 ; j < entryListSize ; j++ )
		{
			tmp2 = DIRpath + "/" +entryList[j];
			if ( !fp.listPLstChk( tmp2 ) )
				pths += tmp2;
			if ( br )
				break;
		}
		if ( br )
			break;
	}

	if ( fileFilter )
		Func.chkFileFormat( pths, &br );

	added = true;
}
void addthr::doExit()
{
	br = true;
	wait(1000);
	if ( isRunning() )
	{
		terminate();
		wait(1000);
		added = true;
	}
}

void downloadThr::doExit()
{
	bolBr = true;
	wait(4000);
	if ( isRunning() )
	{
		terminate();
		wait(1000);
	}
}

void downloadThr::run()
{
	spd = 0;
	dwn = 0;
	error = false;
	finished = false;
	bolBr = false;
	errStr.clear();
	pC = 0;

	FILE *f = fopen( path.toAscii(), "wb" );
	if ( !f )
	{
		errStr = Texts[111] /*"Nie udalo sie utworzyc pliku na dysku"*/;
		error = true;
		return;
	}
	URL_FILE *uF = url_fopen( true, addr.toAscii(), true );
	if ( !uF )
	{
		fclose(f);
		f = NULL;
		remove( path.toAscii() ); //usuń niepobrany plik
		errStr = Texts[107];
		error = true;
		return;
	}
	char *buff = new char[1024];
	int ile = 3;
	uint bread(0);
	while( !url_feof(uF) )
	{
		bread = url_fread( buff, 1, 1024, uF );

		if ( !bread && !url_feof( uF ) && !--ile )
		{
			errStr = Texts[112] /*"Plik na serwerze nie istnieje lub jest pusty!"*/;
			fclose(f); //zamknij plik
			f = NULL;
			remove( path.toAscii() ); //usuń niepobrany plik
			error = true;
			break;
		}
		if ( bread )
			ile = 3;

		fwrite( buff, 1, bread, f );
		spd = getNetInfo(uF,DOWNLOAD_SPEED);
		dwn = getNetInfo(uF,BYTES_DOWNLOADED);
		pC  = ( (double)dwn / getNetInfo(uF,FILE_SIZE) ) * 100.;
		if ( bolBr )
			break;
	}
	spd = 0;
	pC = 100;
	delete[] buff;
	if ( f )
		fclose(f);
	url_fclose(uF);
	if ( !error && !bolBr )
	{
#ifndef Q_WS_WIN
		QFile::setPermissions( path.toAscii(), QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner | QFile::ReadUser | QFile::WriteUser | QFile::ExeUser | QFile::ReadGroup | QFile::WriteGroup | QFile::ExeGroup | QFile::ReadOther | QFile::WriteOther | QFile::ExeOther );
#endif
		finished = true;
	}
}

void chkUpdatesThr::clr()
{
	QMPlay_addr_and_file.clear();
	Ver = 0;
	updates = -1;
}
void chkUpdatesThr::run()
{
	clr();

	loadCURL();
	if ( !CURLloaded )
		return;

	URL_FILE *f = url_fopen( QString( svrAddress + "qmplay_dwn_info" ).toAscii() );
	if ( f )
	{
		updates = 0;
		QString data;
		int ile = 3;
		while ( !url_feof( f ) )
		{
			char c;
			if ( url_fread( &c, 1, 1, f ) == 1 )
			{
				data += c;
				ile = 3;
			}
			else if ( !--ile )
			{
				data.clear();
				break;
			}
		}
		url_fclose( f );
		QStringList QMPlay_files_on_svr = data.split( '\n' );
		if ( QMPlay_files_on_svr.count() >= 5 )
		{
			QMPlay_addr_and_file = QMPlay_files_on_svr[ getOS() ].split( ';' );
			if ( QMPlay_addr_and_file.count() == 2 )
			{
				Ver = QMPlay_files_on_svr[ 0 ].toInt();
				if ( Ver > QMPVer )
					updates = 1;
				if ( Ver == QMPVer )
					updates = 2;
			}
			else
				QMPlay_addr_and_file.clear();
		}
	}

	unloadCURL();
}
