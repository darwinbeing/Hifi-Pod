struct titleThr : public QThread
{
	void run()
	{
		fil->getTitle();
		if( fil->title && fil->title != Title )
		{
			getMusInfo( fil, &title, &Title, 0 );
			*QOut->title = Title;
			updateF = true;
		}
	}
	void doExit()
	{
		if ( isRunning() )
			wait(1500);
		if ( isRunning() )
		{
			terminate();
			wait(500);
		}
	}
} titleThr;

void CLOSE()
{
	fil->aacClose();
	unloadCURL();
	IsPlaying = false;
	delete fil;

	id3Str.clear();
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	titleThr.doExit();
	CLOSE();
	endSong=true;
}

void ERROR2( QString errStr )
{
	fo->Close();
	MUSerr = true;
	title = errStr;
	QLib->showMessage( "Błąd", errStr, 2, 0, true );
}

void ERROR( QString errStr )
{
	clrPos();
	ERROR2(errStr);
	CLOSE();
}

void play( const char *fileE, int type )
{
	if ( type != 0 && type != 2 )
		return ERROR2("Wtyczka obsługuje tylko odczyt plików i strumienia internetowego!");

	if ( type == 2 )
	{
		QString tmp = loadCURL();
		if ( !CURLloaded )
			return ERROR2( "Nie można załadować biblioteki: "+QMPInternetf+libExt+"\n"+tmp );
	}

	if ( curF != fileE )
		clrPos();

	clrSet();

	curF = fileE;

	fil = new AACFile;
	fil->setUrl( fileE );

	if ( type == 2 )
		title = "Czekaj, trwa otwieranie...";

	fil->aacInit( type );

	if ( !fil->loaded )
	{
		if ( fil->Internet )
			return ERROR( "Nie można otworzyć strumienia internetowego!" );
		else
			return ERROR( "Błąd odczytu pliku!" );
	}

	AACUpdate();

	if ( title.isEmpty() && type == 2 )
		title = fileE;

	if ( type == 2 || ( type == 0 && fileE[0] == '/' && fileE[1] == '/' ) )
		QOut->useQMPBuffer();
	QOut->Init( AudioInfo( fil->rate, 16, fil->chn ), true, 0, fileE, /*title*/Title );

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!" );
	}

	IsPlaying = true;
	for(;;)
	{
		if (bolStop)
			break;

		if ( !IsPaused && !*QOut->mustReset )
		{
			fil->aacDecode();

			if ( !fil->audio_buffer )
				break;

			QOut->Play( fil->audio_buffer, fil->samples, pltime, false );
			AACUpdate2( fil->samples );
		}
		else
			QOut->Play(NULL,0,pltime,true);
	}
	STOP();
}

void getMusInfo( AACFile *fil, QString *t, QString *T, QString *A )
{
	QString Artist, Title, title;

	if ( fil->Internet )
		fil->getTitle();

	if ( fil->artist )
		Artist = fil->artist;
	if ( fil->title )
		Title = fil->title;

	if ( !fil->Internet )
	{
		if ( !Title.isEmpty() )
		{
			title = Title;
			if ( !Artist.isEmpty() )
				title = Artist + " - " + Title;
		}
	}
	else
	{
		if ( !Title.isEmpty() )
			title += Title;
		if ( !Title.isEmpty() && !Artist.isEmpty() )
			title += " - " + Artist;
		if ( !Artist.isEmpty() && Title.isEmpty() )
			title += Artist;
	}

	if ( t )
		*t = title;
	if ( T )
		*T = Title;
	if ( A )
		*A = Artist;
}

void AACUpdate()
{
	getMusInfo( fil, &title, &Title, &Artist );

	updateF = true;

	plMaxtime = fil->length;
	NumPos = plMaxtime-1;

	if (savsek != 0 )
	{
		seek(savsek);
		pltime = -1;
	}
	savsek = 0;

	TMPint = 0;

	if ( fil->Internet && QLib )
		QLib->updateCurrPlistEntry( Artist );
}

void AACUpdate2( long BUF_SIZE )
{
	tmptime += BUF_SIZE;
	pltime = tmptime / ( fil->rate*fil->chn*2 );
	TMPint += (float)BUF_SIZE / ( fil->rate*fil->chn*2. );

	if ( fil->Internet && TMPint >= 10 )
	{
		TMPint = 0;
		if ( !titleThr.isRunning() )
			titleThr.start();
	}

	SongPos = pltime;
}

void stop()
{
	bolStop=true;
}

void seek(int &i)
{
	i = -1;
}

void togglePause()
{
	IsPaused = !IsPaused;
}

void getQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
	QOut = QLib->getOutLib();

	Tag_editor_load_lib( QLib );
	if ( tag_editor )
		fo->ui.id3B->setIcon( *tag_editor->Icon );
}

void Init( bool b, int type )
{
	BS = mustReset = false;
	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
	if ( type >= 0 )
		canUpdateEntry = !type;
}

void setFormInfo( int *siz )
{
	if ( siz )
		fo->resize( siz[0], siz[1] );
	else
		fo->Close();
}

QWidget *Show( QWidget* w )
{
	if ( fo->isVisible() )
		   fo->closeEvent(NULL);
	fo->setParent(w);
	fo->Init();
	fo->show();
	return fo;
}

void clrSet()
{
	getBR = "n/a";
	tmptime = 0;
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	plMaxtime = 0;
	IsPaused = false;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	endSong = false;
}

void clrPos()
{
	savsek = 0;
}

void savPos()
{
	savsek = SongPos;
}

void closePlug(bool x,bool z)
{
	mustReset = false;
	if ( !x && !z )
	{
		fs.setParent(NULL);
		fs.close();
		return;
	}
	if (x)
		savPos();
	Save.zapiszopcje();
	BS = true;
	stop();
	if (fo->isVisible())
		fo->Close();
	if ( timref.isActive() )
		timref.stop();
}

void opcje(QWidget *w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

const QString PlugInfoStr("AAC Output Plugin");
void about(QWidget* w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr,0,0);
}

void getMusInfo( const char *fileE, uint type, int *time, QString *title )
{
	if ( type == 2 )
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -1;
		return;
	}
	if ( type != 0 )
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -2;
		return;
	}
	if ( type == 0 )
	{
		AACFile *fil = new AACFile;
		fil->setUrl(fileE);
		fil->aacInit( 0 );
		if ( title )
			getMusInfo( fil, title , 0 , 0 );
		if ( time )
			*time = fil->length;
		fil->aacClose();
		delete fil;
	}
}

bool FileFormatSupport( const char *fileE )
{
	AACFile *fil = new AACFile;
	bool loaded(0);
	fil->setUrl(fileE);
	fil->aacInit( 0,0 );
	loaded = fil->loaded;
	fil->aacClose();
	delete fil;
	return loaded;
}

QString InternetFormatSupport( const char* address )
{
	loadCURL();
	if ( !CURLloaded )
		return "";
	AACFile *fil = new AACFile;
	bool loaded(0);
	fil->setUrl(address);
	fil->aacInit( 1 );
	loaded = fil->loaded;
	fil->aacClose();
	delete fil;
	unloadCURL();
	if ( loaded )
		return plugName;
	else
		return "";
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}

void infoWindow( QWidget *w, const char *fileE, int type )
{
	if ( type != 0 )
		return;
	if ( tag_editor )
		tag_editor->openWindow( fileE, w, false, false );
}

QString getMusStr(const char *fileE, int type, QPixmap &pix)
{
	QString musStr;
	pix = NULL;
	if ( type == 0 && tag_editor )
	{
		musStr = tag_editor->getData( fileE, NULL );
		if ( !musStr.isEmpty() )
			musStr = "\n"+musStr;
	}
	return musStr;
}
