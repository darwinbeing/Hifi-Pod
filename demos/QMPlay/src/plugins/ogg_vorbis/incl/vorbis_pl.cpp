const long BUF_SIZE = 4096;
int size;
bool sek(0),sek2(0), Internet(0);

static ov_callbacks OV_CALLBACKS_URL =
{
	(size_t (*)(void *, size_t, size_t, void *)) url_fread,
	NULL,
	(int (*)(void *)) url_fclose,
	NULL
};

FILE *fE;
URL_FILE *uF;

FILE *qmp_fopen( const char *name, const char *params )
{
#ifdef Q_WS_WIN
	if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) //old Windows
		return fopen( QString( name ).toLocal8Bit(), params );
	else
		return _wfopen( ( const wchar_t * )QString( name ).utf16(), ( const wchar_t * )QString( params ).utf16() );
#else
	return fopen( name, params );
#endif
}

void CLOSE( bool b )
{
	if(!b)
		ov_clear(&musicfile);
	if (b)
	{
		if ( fE && !Internet )
			fclose(fE);
		if ( uF && Internet )
			url_fclose(uF);
	}

	unloadCURL();
	IsPlaying = false;
	vorbisInfoStr.clear();
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	pltime = 0;
	CLOSE(0);
	endSong = true;
}

void ERROR2( QString errStr )
{
	fo->close();
	MUSerr = true;
	title = errStr;
	QLib->showMessage( "Błąd", errStr, 2, 0, true );
}

void ERROR( QString errStr, bool b )
{
	clrPos();
	ERROR2(errStr);
	CLOSE(b);
}

void getMusInfo( OggVorbis_File mus, QString *_t, QString *T, QString *A, const char *fileE, QString *vIS )
{
	QString Title, Artist, t, vorbisInfoStr;

	if ( tag_editor && fileE )
		vorbisInfoStr = tag_editor->getData( fileE, NULL );
	else
	{
		vorbis_comment *comm = ov_comment(&mus, 0);
		if ( comm )
		{
			if ( vorbis_comment_query(comm,(char*)"title",0) )
				vorbisInfoStr += "Title	"+ QString( vorbis_comment_query(comm,(char*)"title",0) ) + "\n";
			if ( vorbis_comment_query(comm,(char*)"artist",0) )
				vorbisInfoStr += "Artist	"+ QString( vorbis_comment_query(comm,(char*)"artist",0) ) + "\n";
			if ( vorbis_comment_query(comm,(char*)"album",0) )
				vorbisInfoStr += "Album	"+ QString( vorbis_comment_query(comm,(char*)"album",0) ) + "\n";
			if ( vorbis_comment_query(comm,(char*)"date",0) )
				vorbisInfoStr += "Year	"+ QString( vorbis_comment_query(comm,(char*)"date",0) ) + "\n";
			if ( vorbis_comment_query(comm,(char*)"comment",0) )
				vorbisInfoStr += "Comment	"+ QString( vorbis_comment_query(comm,(char*)"comment",0) ) + "\n";
			vorbisInfoStr.truncate( vorbisInfoStr.length() - 1 );
		}
	}

	if ( vIS )
		*vIS = vorbisInfoStr;

	Artist = getTagFromData( vorbisInfoStr, "Artist" );
	Title = getTagFromData( vorbisInfoStr, "Title" );

	if ( fileE )
	{
		if ( !Title.isEmpty() )
		{
			t = Title;
			if ( !Artist.isEmpty() )
				t = Artist + " - " + Title;
		}
	}
	else
	{
		if ( !Title.isEmpty() )
			t += Title;
		if ( !Title.isEmpty() && !Artist.isEmpty() )
			t += " - "+Artist;
		if ( !Artist.isEmpty() && Title.isEmpty() )
			t += Artist;
	}

	if ( _t )
		*_t = t;
	if ( T )
		*T = Title;
	if ( A )
		*A = Artist;
}

void play( const char *fileE, int type )
{
	sek = 0;
	sek2 = 0;
	if ( type != 0 && type != 2 )
		return ERROR2( "Wtyczka obsługuje tylko odczyt plików i strumienia internetowego!" );

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

	if ( type == 0 )
		fE = qmp_fopen(fileE,"rb");
	if ( type == 2 )
	{
		title = "Czekaj, trwa otwieranie...";
		uF = url_fopen( fileE );
	}

	bool loaded(0);

	if ( type == 0 )
	{
		loaded = !ov_open(fE,&musicfile,NULL,0);
		Internet = false;
	}
	if ( type == 2 )
	{
		if (uF)
			loaded = !ov_open_callbacks(uF, &musicfile, NULL, 0, OV_CALLBACKS_URL);
		else
			loaded = 0;
		Internet = true;
	}

	if ( !loaded )
	{
		if ( type == 2 )
			return ERROR( "Nie można otworzyć strumienia internetowego!" , 1 );
		else
			return ERROR( "Błąd odczytu pliku!" , 1 );
	}


	OGGUpdate();

	if ( title.isEmpty() && type == 2 )
		title = fileE;

	if ( type == 2 || ( type == 0 && fileE[0] == '/' && fileE[1] == '/' ) )
		QOut->useQMPBuffer();
	QOut->Init( AudioInfo( rate, 16, chn ), true, 0, fileE, title );

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!", 0 );
	}

	long s = 0;
	IsPlaying=true;
	char audio_buffer[BUF_SIZE];
	QTime tim_i_u;
	if ( Internet )
		tim_i_u.start();
	do
	{
		if ( bolStop )
			break;
		if ( !sek2 && !*QOut->mustReset && !IsPaused )
		{
			sek = 1;
			s = ov_read( &musicfile, audio_buffer, BUF_SIZE, Q_BYTE_ORDER == Q_BIG_ENDIAN, 2, 1, 0 );
			sek = 0;
			QOut->Play( audio_buffer, s, pltime, false );
			OGGUpdate2(s);
		}
		else
			QOut->Play(NULL,0,pltime,true);

		if ( Internet && tim_i_u.elapsed() >= 10000 )
		{
			tim_i_u.restart();
			QString tit;
			getMusInfo( musicfile, &tit, &Title, &Artist, NULL, &vorbisInfoStr );
			if ( !tit.isEmpty() )
				title = tit;
			updateF = true;
		}
	} while ( s != 0 );
	STOP();
}

void OGGUpdate()
{
	Artist = "";
	Title = "";
	title = "";

	getMusInfo( musicfile, &title, &Title, &Artist, Internet ? NULL : curF.toUtf8().data(), &vorbisInfoStr );

	if ( Internet )
	{
		QString header = getHeader( uF );
		char *a = NULL;
		if ( !header.isEmpty() )
		{
			a = getICYName( header.toAscii().data(), header.length() );
			if ( a && *a )
			{
				QLib->updateCurrPlistEntry( a );
				if ( title.isEmpty() )
					title = a;
			}
		}
		if ( !a )
			QLib->updateCurrPlistEntry( title );
		else
			free( a );
	}

	vorbis_info *vi = ov_info(&musicfile,0);

	rate = vi->rate;
	chn = vi->channels;

	updateF = true;

	plMaxtime = ov_time_total (&musicfile,0);
	NumPos = plMaxtime-1;

	getBR = QString::number( ov_bitrate(&musicfile,-1)/1000 ,10 )+"kbps";

	if (savsek != 0 )
	{
		seek( savsek );
		pltime = -1;
	}
	savsek = 0;
}

void OGGUpdate2(long BUF_SIZE)
{
	if ( !Internet )
	{
		pltime = ov_time_tell(&musicfile);
		SongPos = ov_time_tell(&musicfile);
	}
	else
	{
		currBytes += BUF_SIZE;
		pltime = currBytes / (rate*chn*2);
	}
}

void stop()
{
	bolStop=true;
}

void seek(int &i)
{
	if (!sek)
	{
		if ( i > NumPos )
		{
			i = -1;
			return;
		}
		sek2=1;
		pauseD=false;
		IsPaused = false;
		ov_time_seek(&musicfile,i);
		sek2=0;
	}
	else
		i = -1;
}

void togglePause()
{
	if ( IsPaused )
		IsPaused = false;
	else
		IsPaused=true;
}

void getQLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
	QOut = QLib->getOutLib();

	Tag_editor_load_lib( QLib );
	if ( tag_editor )
		fo->ui.tagB->setIcon( *tag_editor->Icon );
}

void Init( bool b, int type )
{
	BS = mustReset = false;
	if ( !b )
	{
		if ( pm.isNull() )
			pm = QPixmap( ":/vorbis.png" );
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
	if ( type > -1 )
		canUpdateEntry = !type;
}

void setFormInfo( int *siz )
{
	if ( siz )
		fo->resize( siz[0], siz[1] );
	else
		fo->close();
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
	currBytes = 0;
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
		fo->close();
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

const QString PlugInfoStr("OGG Vorbis Input Plugin");
void about(QWidget* w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr);
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
	if ( type == 1 )
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -2;
		return;
	}
	if ( type == 0 )
	{
		OggVorbis_File mus;
		FILE *fil = NULL;
		fil = qmp_fopen(fileE,"rb");
		if ( ov_open(fil,&mus,NULL,0) )
		{
			if (fil)
				fclose(fil);

			if ( title )
				*title = "";
			if ( time )
				*time = -2;
			return;
		}

		if ( title )
			getMusInfo( mus, title, NULL, NULL, fileE, NULL );
		if ( time )
			*time = ov_time_total (&mus,0);

		ov_clear(&mus);
	}
}

void infoWindow( QWidget *w, const char *fileE, int type )
{
	if ( type != 0 )
		return;

	if ( tag_editor )
	{
		tag_editor->openWindow( fileE, w, false, false );
		return;
	}

	OggVorbis_File mus;

	FILE *fil = qmp_fopen( fileE, "rb" );
	if ( ov_open(fil,&mus,NULL,0) )
	{
		if (fil)
			fclose(fil);
		ov_clear(&mus);
		return;
	}

	QString txt;
	getMusInfo( mus, NULL, NULL, NULL, NULL, &txt );
	txt = "\n\n" + txt;

	ov_clear(&mus);

	QMessageBox::information( w, PlugInfoStr, "File path: \"" + QString( fileE ) + "\"" + txt);
}

bool FileFormatSupport( const char *fileE )
{
	fE = qmp_fopen(fileE,"rb");
	if (!fE)
		return 0;
	bool loaded(0);
	OggVorbis_File mus;
	loaded = !ov_open(fE,&mus,NULL,0);
	if (loaded)
		ov_clear(&mus);
	else
		fclose(fE);
	return loaded;
}

QString getMusStr(const char *fileE, int type, QPixmap &pix)
{
	QString musStr;
	pix = NULL;
	if ( type == 0 )
	{
		if ( tag_editor )
		{
			musStr = tag_editor->getData( fileE, NULL );
			if ( !musStr.isEmpty() )
				musStr = "\n"+musStr;
			return musStr;
		}
		OggVorbis_File mus;
		FILE *fil = NULL;
		fil = qmp_fopen(fileE,"rb");
		if ( ov_open(fil,&mus,NULL,0) )
		{
			if (fil)
				fclose(fil);
			return "";
		}

		getMusInfo( mus, NULL, NULL, NULL, NULL, &musStr );
		musStr = "\n" + musStr;

		ov_clear(&mus);
	}
	return musStr;
}

QString InternetFormatSupport( const char* address )
{
	loadCURL();
	if ( !CURLloaded )
		return "";
	OggVorbis_File mus;
	URL_FILE *uF = NULL;
	uF = url_fopen( address );
	bool loaded = !ov_open_callbacks(uF, &mus, NULL, 0, OV_CALLBACKS_URL);
	ov_clear(&mus);
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
