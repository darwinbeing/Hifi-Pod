#include <Functions.cpp>

QString plikbezsciezki( QString pth )
{
	return QLib->stringOperations( PLIK_BEZ_SCIEZKI, pth );
}

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
	if ( fE )
		fclose(fE);
	IsPlaying = false;
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	CLOSE();
	endSong=true;
}

void ERROR2( QString errStr )
{
	MUSerr = true;
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

	fE = qmp_fopen( fileE, "rb" );

	if ( !fE )
		return ERROR( "Błąd odczytu pliku!" );

	curF = fileE;

	WAVUpdate();

	int BUF_SIZE = 1024 * ( bits / 8 ) * chn;

	title = plikbezsciezki( fileE );

	QOut->Init( AudioInfo( rate, BITS, chn ), true, 0, fileE, title );

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!" );
	}

	bool _u8B = u8B;

	char audio_buffer[BUF_SIZE];
	while ( !feof( fE ) )
	{
		if ( bolStop )
			break;
		if ( !IsPaused && !*QOut->mustReset  )
		{
			int bread = fread( audio_buffer, 1, BUF_SIZE, fE );

			if ( _u8B )
				memset( audio_buffer + bread, 0x80, BUF_SIZE - bread );
			else
				memset( audio_buffer + bread, 0x0, BUF_SIZE - bread );

			bool convert;
			if ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
				convert = !be;
			else if ( QSysInfo::ByteOrder == QSysInfo::LittleEndian )
				convert = be;
			if ( convert )
			{
				char tmpAB,tmpAB2;
				if ( bits == 16 || bits == 24 )
				{
					int pl;
					if ( bits == 16 )
						pl = 1;
					else
						pl = 2;
					for ( int i = 0 ; i < BUF_SIZE ; i += bits/8 )
					{
						tmpAB = audio_buffer[i+0];
						audio_buffer[i+0] = audio_buffer[i+pl];
						audio_buffer[i+pl] = tmpAB;
					}
				}
				if ( bits == 32 )
				{
					for ( int i = 0 ; i < BUF_SIZE ; i += 4 )
					{
						tmpAB = audio_buffer[i+0];
						tmpAB2 = audio_buffer[i+1];
						audio_buffer[i+0] = audio_buffer[i+3];
						audio_buffer[i+1] = audio_buffer[i+2];
						audio_buffer[i+2] = tmpAB2;
						audio_buffer[i+3] = tmpAB;
					}
				}
			}

			if ( _u8B ) //konwersja unsigned do signed PCM
				convert_Signed_Unsigned_PCM( audio_buffer, BUF_SIZE );

			QOut->Play(audio_buffer,BUF_SIZE,pltime,false);
			if ( *QOut->PlErr )
				break;

			WAVUpdate2();
		}
		else
			QOut->Play( NULL, 0, pltime, true );
	}
	STOP();
}

void WAVUpdate()
{
	getBR = "n/a";

	fseek( fE, 0, 2 );
	int size = ftell( fE );
	fseek( fE, skipB, 0 );

	rate = srateB;
	bits = BITS;
	if ( bits == 33 )
		bits = 32;
	chn = chnB;

	plMaxtime = size / rate / ( bits / 8 ) / chn;
	NumPos = plMaxtime-1;

	if (savsek != 0 )
		seek( savsek );
	savsek = 0;

	IsPlaying = true;
}

void stop()
{
	bolStop = true;
}

void seek(int &i)
{
	if ( i > NumPos )
	{
		i = -1;
		return;
	}
	pauseD = false;
	IsPaused = false;
	fseek( fE, ( i * rate * (bits / 8) * chn ) + skipB, 0 );
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

void WAVUpdate2()
{
	pltime = ftell(fE) / rate / (bits / 8) / chn;
	SongPos = pltime;
}

void clrSet()
{
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

const QString PlugInfoStr("RAW Input Plugin");
void about(QWidget *w)
{
	QMessageBox::information( w, PlugInfoStr, PlugInfoStr );
}

void getMusInfo( const char *fileE, uint type, int *time, QString * )
{
	if ( type != 0 || !time )
		return;

	FILE *fil = qmp_fopen( fileE, "rb" );
	if ( !fil )
		return;

	fseek( fil, 0, 2 );
	int size = ftell( fil );
	fclose(fil);

	int bits = BITS;
	if ( bits == 33 )
		bits = 32;
	*time = size / srateB / ( bits / 8 ) / chnB;
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

void infoWindow(QWidget *w, const char *fileE,int type)
{
	if ( type != 0 )
		return;
	QMessageBox::information( w, PlugInfoStr, fileE );
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
