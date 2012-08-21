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

void CLOSE()
{
	if(module)
		ModPlug_Unload(module);
	IsPlaying = false;
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

void ERROR( QString errStr )
{
	clrPos();
	ERROR2(errStr);
	CLOSE();
}

void play( const char *fileE, int type )
{
	if ( type != 0 )
		return ERROR2( "Wtyczka obsługuje tylko odczyt plików!" );

	if ( fileE != curF )
		clrPos();

	clrSet();

	long size(0);
	char *fileData;
	FILE *f;
	f = qmp_fopen(fileE, "rb");
	if (!f)
		return ERROR2( "Błąd odczytu pliku!" );
	fseek(f, 0, 2);
	size = ftell(f);
	rewind(f);
	fileData = new char[size];
	fread(fileData, size, sizeof(char), f);
	fclose(f);
	module = ModPlug_Load( fileData,size );
	delete fileData;

	if ( !module )
		return ERROR( "Błąd odczytu pliku!" );

	MPUpdate();
	setUp();

	QOut->Init( AudioInfo( rate, bits, chn ), true, 0, fileE, title );
	bool bits2(0);
	if ( bits == 8 )
		bits2 = 1;

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!" );
	}

	int s = 1;

	curF=fileE;

	audio_buffer = new char[BUF_SIZE];
	while ( s != 0 )
	{
		if (bolStop)
			break;
		if ( !IsPaused && !*QOut->mustReset  )
		{
			s = ModPlug_Read(module,audio_buffer,BUF_SIZE);

			if ( bits2 )
				convert_Signed_Unsigned_PCM(audio_buffer,BUF_SIZE);

			QOut->Play(audio_buffer,BUF_SIZE,pltime,false);
			MPUpdate2();
		}
		else
			QOut->Play(audio_buffer,BUF_SIZE,pltime,true);
	}
	STOP();
}

void setUp()
{
	if ( !Oversampling )
		mpset.mFlags &= ~MODPLUG_ENABLE_OVERSAMPLING;
	else
		mpset.mFlags |= MODPLUG_ENABLE_OVERSAMPLING;

	if ( !NoiseR )
		mpset.mFlags &= ~MODPLUG_ENABLE_NOISE_REDUCTION;
	else
		mpset.mFlags |= MODPLUG_ENABLE_NOISE_REDUCTION;

	if ( !reverb )
		mpset.mFlags &= ~MODPLUG_ENABLE_REVERB;
	else
		mpset.mFlags |= MODPLUG_ENABLE_REVERB;

	if ( !bass )
		mpset.mFlags &= ~MODPLUG_ENABLE_MEGABASS;
	else
		mpset.mFlags |= MODPLUG_ENABLE_MEGABASS;

	if ( !surround )
		mpset.mFlags &= ~MODPLUG_ENABLE_SURROUND;
	else
		mpset.mFlags |= MODPLUG_ENABLE_SURROUND;

	mpset.mChannels = chn;
	mpset.mBits = bits;
	mpset.mFrequency = rate;
	mpset.mResamplingMode = Resampling;
	mpset.mReverbDepth = reverb1;
	mpset.mReverbDelay = reverb2;
	mpset.mBassAmount = bass1;
	mpset.mBassRange = bass2;
	mpset.mSurroundDepth = surround1;
	mpset.mSurroundDelay = surround2;
	mpset.mLoopCount = loop;

	ModPlug_SetSettings( &mpset );

	if ( IsPlaying )
	{
		if ( !showTime )
			NumPos = ModPlug_NumPatterns(module) -1;
		else
			NumPos = plMaxtime -1;

		if ( module )
			ModPlug_SetMasterVolume(module,vol);
	}
}

void MPUpdate()
{
	tmptime = 0;
	pltime = 0;
	title = ModPlug_GetName( module );
	plMaxtime = ModPlug_GetLength(module) / 1000;

	if (savsek != 0 )
	{
		seek(savsek);
		pltime = -1;
	}

	savsek=0;
	setMFInit=true;
	IsPlaying=true;
}

void stop()
{
	bolStop=true;
}

void seek(int &i)
{
	pauseD=false;
	IsPaused=false;
	if ( !showTime )
		ModPlug_SeekOrder(module,i);
	else
	{
		ModPlug_Seek(module,i*1000);
		pltime = i;
		tmptime = 0;
	}
}

void togglePause()
{
	if ( IsPaused )
		IsPaused=false;
	else
		IsPaused=true;
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
		fs.ApplyB();
	}
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

void MPUpdate2()
{
	tmptime++;

	if ( tmptime >= ( rate*chn*(bits/8) ) / BUF_SIZE )
	{
		tmptime = 0;
		pltime++;
	}

	if ( !showTime )
		SongPos = ModPlug_GetCurrentOrder(module);
	else
		SongPos = pltime;
}

void clrSet()
{
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	plMaxtime = 0;
	IsPaused = false;
	module = NULL;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	endSong = false;
	curF.clear();
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
	plSpec = false;
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
 	if (fm->isVisible())
		fm->close();
 	if (fm2.isVisible())
		fm2.close();
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

void plugSpec(QWidget* par, bool y)
{
	if (y)
	{
		fm2.setParent(par);
		if ( ! timref.isActive() )
			timref.start( timRefValue );
		fm2.move(0,0);
		fm2.resize( QLib->getOkienkoSize() );
		fm2.show();
		plSpec=true;
	}
	else
	{
		plSpec=false;
		if ( !fm->isVisible() )
		{
			fm2.close();
			timref.stop();
		}
		else
			fm->closeEvent(NULL);
			fm->Init();
	}
}

bool FileFormatSupport( const char *fileE )
{
	int len2 = strlen( fileE );
	QString ext;

	for ( int k = len2 ; k > 0 ; k-- )
	{
		if ( fileE[k] == '.' )
		{
			char *Ext = new char[len2-k];
			memcpy( Ext, &fileE[k+1], len2-k-1 );
			Ext[len2-k-1] = 0;
			ext = Ext;
			delete[] Ext;
			break;
		}
	}

	if ( ext.isEmpty() )
		return 0;

	ext = ext.toLower();

	QString ext2, formatSupport2;
	formatSupport2 = formatSupport.toLower();
	int len = formatSupport2.length();
	if ( formatSupport2[ len - 1 ] != ';' )
	{
		formatSupport2 += ";";
		len++;
	}

	for ( int i = 0 ; i < len ; i++ )
	{
		if ( formatSupport2[i] != ';' )
			ext2 += formatSupport2[i];
		else
		{
			if ( ext == ext2 )
			{
				ext2.clear();
				return 1;
			}
			ext2.clear();
		}
	}
	return 0;
}

const QString PlugInfoStr("ModPlug Input Plugin");
void about(QWidget* w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr);
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

	ModPlugFile *mus;
	long size(0);
	char *fileData;
	FILE *f;
	f = qmp_fopen(fileE, "rb");
	if (!f)
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -2;
		return;
	}
	fseek(f, 0L, SEEK_END);
	size = ftell(f);
	rewind(f);
	fileData = new char[size];
	fread(fileData, size, sizeof(char), f);
	fclose(f);
	mus = ModPlug_Load( fileData,size );
	delete fileData;

	if ( !mus )
	{
		if ( title )
			*title = "";
		if ( time )
			*time = -2;
		return;
	}

	if ( title )
		*title = ModPlug_GetName( mus );
	if ( time )
		*time = ModPlug_GetLength(mus)/1000;

	ModPlug_Unload(mus);
}

void infoWindow(QWidget *w, const char *fileE,int type)
{
	if ( type != 0 )
		return;
	ModPlugFile *mus;

	long size(0);
	char *fileData;
	FILE *f;
	f = qmp_fopen(fileE, "rb");
	if (!f)
		return;
	fseek(f, 0L, SEEK_END);
	size = ftell(f);
	rewind(f);
	fileData = new char[size];
	fread(fileData, size, sizeof(char), f);
	fclose(f);
	mus = ModPlug_Load( fileData,size );
	delete fileData;

	if ( mus == NULL )
		return;
	QString t = ModPlug_GetName(mus);
	QString l = QString::number(ModPlug_GetLength(mus)/1000)+"s";
	QString inst = QString::number(ModPlug_NumInstruments(mus));
	QString smpl = QString::number(ModPlug_NumSamples(mus));
	QString numpat = QString::number(ModPlug_NumPatterns(mus));
	QString numchn = QString::number(ModPlug_NumChannels(mus));

	QMessageBox::information(w,PlugInfoStr,"Plik: "+QString(fileE)+"\nTytuł: "+t+"\nDługość: "+l+"\nInstrumenty: "+inst+"\nSample: "+smpl+"\nPattern: "+numpat+"\nKanały: "+numchn,0,0);

	ModPlug_Unload(mus);
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
