#include <Functions.cpp>

#define BUF_SIZE 4096
char *audio_buffer;

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

bool MMInit()
{
#if (LIBMIKMOD_VERSION > 0x30106)
	return MikMod_Init((char*)"");
#else
	return MikMod_Init();
#endif
}

bool IsPlaying(0);
void CLOSE()
{
	if (module)
	{
		Player_Stop();
		Player_Free(module);
		MikMod_Exit();
	}
	IsPlaying = 0;
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	delete[] audio_buffer;
	CLOSE();
	endSong=true;
}

void ERROR2( QString errStr )
{
	fm->close();
	MODerr = true;
	title = errStr;
}

void _ERROR( QString errStr )
{
	clrPos();
	ERROR2(errStr);
	CLOSE();
}

void play( const char *fileE, int type )
{
	if ( type != 0 )
		return ERROR2( "Wtyczka obsługuje tylko odczyt plików!" );

	int chn,bits;

	if (bits16)
		bits=16;
	else
		bits=8;

	if (stereo)
		chn=2;
	else
		chn=1;

	if ( fileE != curF )
		clrPos();

	clrSet();

	if ( MMInit() )
		return _ERROR( "Błąd: " + QString( MikMod_strerror( MikMod_errno ) ) );

	IsPlaying = 1;

	FILE *f = qmp_fopen( fileE, "rb" );
	if ( f )
	{
		module = Player_LoadFP( f, chnMAX, 0 );
		fclose(f);
	}
	else
		return _ERROR( "Błąd odczytu pliku!" );

	if (module)
	{
		QString file = fileE;
		QOut->Init( AudioInfo( mdmixfreq, bits, chn ), true, 0, file, title );

		if ( *QOut->PlErr )
		{
			*QOut->PlErr = false;
			return _ERROR( "Błąd zwraca wtyczka wyjściowa!" );
		}

		Player_Start(module);
		MMUpdate();
		curF=fileE;

		audio_buffer = new char[BUF_SIZE];
		while ( Player_Active() )
		{
			if (bolStop)
				break;
			if ( pauseD || *QOut->mustReset )
			{
				QOut->Play(audio_buffer,BUF_SIZE,pltime,true);
				continue;
			}
			if ( VC_WriteBytes( (SBYTE*) audio_buffer, BUF_SIZE ) != 0 )
			{
				if ( !bits16 )
					convert_Signed_Unsigned_PCM( audio_buffer, BUF_SIZE );
				QOut->Play(audio_buffer,BUF_SIZE,pltime,false);
			}
			MMUpdate2();
		}
		STOP();
	}
	else
		return _ERROR( "Błąd: " + QString( MikMod_strerror( MikMod_errno ) ) );
}

void setUp()
{
	if (interp) md_mode|=DMODE_INTERP; else md_mode&=~DMODE_INTERP;
	if (hqmixer) md_mode|=DMODE_HQMIXER; else md_mode&=~DMODE_HQMIXER;
	if (surround) md_mode|=DMODE_SURROUND; else md_mode&=~DMODE_SURROUND;
	if (bits16) md_mode|=DMODE_16BITS; else md_mode&=~DMODE_16BITS;
	if (stereo) md_mode|=DMODE_STEREO; else md_mode&=~DMODE_STEREO;
	if (reverse) md_mode|=DMODE_REVERSE; else md_mode&=~DMODE_REVERSE;
	md_pansep = pansep;
	md_reverb = reverb;
	md_volume = mdvolume;
	if (mdmixfreq > 0) md_mixfreq = mdmixfreq;
}

void MMUpdate()
{
	title = module->songname;
	NumPos = module->numpos-1;
	if (loop) module->loop=true; else module->loop=false;
	if (fadeout) module->fadeout=true; else module->fadeout=false;
	if (savsek != 0 )
	{
		pltime = -1;
		seek(savsek);
		Player_SetSpeed(savspd);
		Player_SetTempo(savbpm);
	}
	savsek=0;
	savspd=0;
	savbpm=0;
	setMFInit=true;
}

void stop()
{
	bolStop=true;
}

void seek(int &i)
{
	pauseD=false;
	Player_SetPosition( i );
}

void togglePause()
{
	Player_TogglePause();
}

void getQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
	QOut = QLib->getOutLib();
}

void Init( bool b, int )
{
	BS = mustReset = false;
	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.APPLY();
	}
	if (!oneReg)
	{
		oneReg=true;
		MikMod_RegisterAllLoaders();
		MikMod_RegisterDriver(&drv_qmp);
	}
}

QString getInstr()
{
	if (module->flags&UF_INST)
		return QString::number(module->numins,10);
	else
		return "0";
}

void setFormInfo( int *siz )
{
	if ( siz )
		fm->resize( siz[0], siz[1] );
	else
		fm->close();
}

QWidget *Show( QWidget* w )
{
	if ( fm->isVisible() )
		fm->closeEvent(NULL);
	fm->setParent(w);
	fm->Init();
	fm->show();
	return fm;
}

void MMUpdate2()
{
	pltime = module->sngtime / 1024;
	SongPos = module->sngpos;
	savspd = module->sngspd;
	savbpm = module->bpm;
}

void clrSet()
{
	title = "";
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	endSong = false;
	module=NULL;
	curF="";
}

void clrPos()
{
	savsek = 0;
	savspd = 0;
	savbpm = 0;
}

void savPos()
{
	savsek = SongPos;
}


void closePlug(bool x,bool z)
{
	plSpec = false;
	BS = mustReset = false;
	if ( !x && !z )
	{
		fs.setParent(NULL);
		fs.close();
		return;
	}
	if (x)
		savPos();
	Save.zapiszopcje();
	stop();
	if (fm->isVisible())
		fm->close();
	if (fsi.isVisible())
		fsi.close();
	if (fms.isVisible())
		fms.close();
	if ( timref.isActive() )
		timref.stop();
}

void showOptions()
{
	QWidget *qW = QLib->getParent(QMP_MAIN_OR_PLIST);
	fs.setParent( NULL );
	fs.move( qW->x() + qW->width()/2 - fs.width()/2 , qW->y() + qW->height()/2 - fs.height()/2 );
	fs.show();
}

void opcje(QWidget *w)
{
	if (w)
	{
		w->setMinimumSize( fs.minimumSize() );
		w->setMaximumSize( fs.maximumSize() );
		tmpWidget = w;
	}
	fs.setParent(tmpWidget);
	fs.move(0,0);
	fs.show();
}

void plugSpec(QWidget * par, bool y)
{
	if (y)
	{
		fms.setParent(par);
		if ( ! timref.isActive() )
			timref.start( timRefValue );
		fms.move(0,0);
		fms.resize( QLib->getOkienkoSize() );
		fms.show();
		plSpec=true;
	}
	else
	{
		plSpec=false;
		if ( ! fm->isVisible() )
		{
			fms.close();
			timref.stop();
		}
		else
			fm->closeEvent(NULL);
			fm->Init();
	}
}

const QString PlugInfoStr("MikMod Input Plugin");
void about(QWidget *w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr,0,0);
}

void getMusInfo( const char *fileE, uint type, int *time, QString *title )
{
	if ( type > 0 )
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -2;
		return;
	}
	if ( title )
	{
		FILE *f = qmp_fopen( fileE, "rb" );
		if ( f )
		{
			*title = Player_LoadTitleFP( f );
			fclose( f );
		}
		else
			*title = "";
	}
	if ( time )
		*time = -1;
}

bool FileFormatSupport( const char *fileE )
{
	char *t = NULL;
	FILE *f = qmp_fopen( fileE, "rb" );
	if ( f )
	{
		t = Player_LoadTitleFP( f );
		fclose( f );
	}
	if ( t )
	{
		free( t );
		return true;
	}
	else
		return false;
}

void infoWindow( QWidget *w, const char *fileE, int type )
{
	if ( type != 0 )
		return;
	FILE *f = qmp_fopen( fileE, "rb" );
	if ( f )
	{
		QMessageBox::information( w, PlugInfoStr, "Plik: " + QString( fileE ) + "\nTytuł: " + QString( Player_LoadTitleFP( f ) ) );
		fclose( f );
	}
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
