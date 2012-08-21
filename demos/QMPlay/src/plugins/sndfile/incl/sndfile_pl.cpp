#include <fcntl.h>

#ifndef O_BINARY
	#define O_BINARY 0
#endif

int qmp_open( const char *name, int flags )
{
#ifdef Q_WS_WIN
	if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) //old Windows
		return open( QString( name ).toLocal8Bit(), flags );
	else
		return _wopen( ( const wchar_t * )QString( name ).utf16(), flags );
#else
		return open( name, flags );
#endif
}

QString plikbezsciezki( QString pth )
{
	return QLib->stringOperations( PLIK_BEZ_SCIEZKI, pth );
}

void CLOSE()
{
	if ( snd )
	{
		sf_close( snd );
		snd = NULL;
	}
	IsPlaying = false;

	sndfileInfoStr.clear();
	pix = QImage();
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	CLOSE();
	endSong=true;
}

void ERROR2( QString errStr )
{
	fo->close();
	MUSerr = true;
	title = errStr;
}

void ERROR( QString errStr )
{
	clrPos();
	ERROR2(errStr);
	CLOSE();
}

QString getFormatStr( int format )
{
	format &= SF_FORMAT_SUBMASK;
	switch ( format )
	{
		case SF_FORMAT_PCM_S8:
			return "Signed 8bit";
		case SF_FORMAT_PCM_16:
			return "16bit";
		case SF_FORMAT_PCM_24:
			return "24bit";
		case SF_FORMAT_PCM_32:
			return "32bit";
		case SF_FORMAT_PCM_U8:
			return "Unsigned 8bit";
		case SF_FORMAT_FLOAT:
			return "32bit float";
		case SF_FORMAT_DOUBLE:
			return "64bit double";
		case SF_FORMAT_ULAW:
			return "U-Law";
		case SF_FORMAT_ALAW:
			return "A-Law";
		case SF_FORMAT_IMA_ADPCM:
			return "IMA_ADPCM";
		case SF_FORMAT_MS_ADPCM:
			return "MS_ADPCM";
		case SF_FORMAT_GSM610:
			return "GSM6.10";
		case SF_FORMAT_VOX_ADPCM:
			return "VOX_ADPCM";
		case SF_FORMAT_G721_32:
			return "G721_32";
		case SF_FORMAT_G723_24:
			return "G723_24";
		case SF_FORMAT_G723_40:
			return "G723_40";
		case SF_FORMAT_DWVW_12:
			return "DWVW_12";
		case SF_FORMAT_DWVW_16:
			return "DWVW_16";
		case SF_FORMAT_DWVW_24:
			return "DWVW_24";
		case SF_FORMAT_DWVW_N:
			return "DWVW_N";
		case SF_FORMAT_DPCM_8:
			return "DPCM_8";
		case SF_FORMAT_DPCM_16:
			return "DPCM_16";
		case SF_FORMAT_VORBIS:
			return "Vorbis";
		default:
			return QString();
	}
}

void play( const char *fileE, int type )
{
	if ( type != 0 )
		return ERROR2( "Wtyczka obsługuje tylko odczyt plików!" );

	if ( fileE != curF )
		clrPos();

	clrSet();

	int fd = qmp_open( fileE, O_RDONLY|O_BINARY );
	snd = sf_open_fd( fd, SFM_READ, &sndInfo, 1 );
	if ( !snd )
		return ERROR( "Błąd odczytu pliku!" );

	curF = fileE;

	WAVUpdate( sndInfo );

	if ( title.isEmpty() )
		title = plikbezsciezki( fileE );

	QString bitsStr = getFormatStr( sndInfo.format );
	QOut->Init( AudioInfo( rate, 33, chn, bitsStr ), true, 0, fileE, title );
	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!" );
	}

	int BUF_SIZE = 1024 * chn;

	float audio_buffer[ BUF_SIZE ];
	memset( audio_buffer, 0, BUF_SIZE * sizeof(float) );

	sf_count_t readFrames = 0;
	do
	{
		if ( bolStop )
			break;
		if ( !IsPaused && !*QOut->mustReset && !seeking )
		{
			nowReading = true;
			readFrames = sf_read_float( snd, audio_buffer, BUF_SIZE );
			nowReading = false;

			QOut->Play( audio_buffer, readFrames * sizeof(float), pltime, false );
			if ( *QOut->PlErr )
				break;

			WAVUpdate2();
		}
		else
			QOut->Play( NULL, 0, pltime, true );
	} while ( readFrames > 0 );

	STOP();
}

void getMusInfo( SNDFILE *_snd, QString *title )
{
	if ( _snd == snd /* jeżeli wywołanie jest podczas odtwarzania muzyki */ && tag_editor )
	{
		sndfileInfoStr = tag_editor->getData( curF.toUtf8(), &pix );
		if ( !pix.isNull() )
			pix = pix.scaledToWidth( 46, Qt::SmoothTransformation );
	}

	if ( title )
	{
		QString t = sf_get_string( _snd, SF_STR_TITLE );
		QString a = sf_get_string( _snd, SF_STR_ARTIST );

		if ( !a.isEmpty() )
			*title = a;
		if ( !t.isEmpty() && !a.isEmpty() )
			*title += " - " + t;
		if ( !t.isEmpty() && a.isEmpty() )
			*title = t;
	}
}

void WAVUpdate( SF_INFO sndInfo )
{
	getBR = "n/a";

	rate = sndInfo.samplerate;
	chn = sndInfo.channels;

	plMaxtime = sndInfo.frames / rate;
	NumPos = plMaxtime-1;

	getMusInfo( snd, &title );

	if ( savsek != 0 )
	{
		seek( savsek );
		pltime = -1;
	}
	savsek = 0;

	IsPlaying = true;
	updateF = true;
}

void WAVUpdate2()
{
	pltime = sf_seek( snd, 0, SEEK_CUR ) / rate;
	SongPos = pltime;
}

void seek( int &i )
{
	if ( i > NumPos || nowReading )
	{
		i = -1;
		return;
	}
	seeking = true;
	pauseD = false;
	IsPaused = false;
	sf_seek( snd, i * rate, SEEK_SET );
	seeking = false;
}

void stop()
{
	bolStop = true;
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
		fo->ui.tagB->setIcon( *tag_editor->Icon );
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
		fo->resize( siz[0], siz[1] );
	else
		fo->close();
}

void clrSet()
{
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	plMaxtime = 0;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	IsPaused = seeking = nowReading = endSong = false;
	curF.clear();
	title.clear();
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
	if ( x )
		savPos();
	Save.zapiszopcje();
	BS = true;
	stop();
	if (fo->isVisible())
		fo->close();
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

const QString PlugInfoStr("Sndfile Input Plugin");
void about(QWidget *w)
{
	QMessageBox::information( w, PlugInfoStr, PlugInfoStr );
}

void getMusInfo( const char *fileE, uint type, int *time, QString *title )
{
	if ( type != 0 )
		return;

	SF_INFO sndInfo;
	int fd = qmp_open( fileE, O_RDONLY|O_BINARY );
	SNDFILE *snd = sf_open_fd( fd, SFM_READ, &sndInfo, 1 );
	if ( !snd )
		return;

	getMusInfo( snd, title );

	if ( time )
		*time = sndInfo.frames / sndInfo.samplerate;

	sf_close( snd );

	return;
}

QString getMusStr(const char *fileE, int type, QPixmap &pix)
{
	QString musStr;
	pix = NULL;
	if ( type == 0 )
	{
		SF_INFO sndInfo;
		int fd = qmp_open( fileE, O_RDONLY|O_BINARY );
		SNDFILE *snd = sf_open_fd( fd, SFM_READ, &sndInfo, 1 );
		if ( snd )
		{
			musStr += "\nSamplerate	" + QString::number( sndInfo.samplerate );
			musStr += "\nChannels	" + QString::number( sndInfo.channels );
			musStr += "\nFormat	"    + getFormatStr( sndInfo.format );
			sf_close( snd );
		}
		if ( tag_editor )
		{
			QImage img;
			QString data = tag_editor->getData( fileE, &img );
			if ( !data.isEmpty() )
				musStr += "\n\n" + data;
			pix = QPixmap::fromImage( img );
		}
	}
	return musStr;
}

bool FileFormatSupport( const char *fileE )
{
	SF_INFO sndInfo;
	int fd = qmp_open( fileE, O_RDONLY|O_BINARY );
	SNDFILE *snd = sf_open_fd( fd, SFM_READ, &sndInfo, 1 );
	if ( snd )
	{
		sf_close( snd );
		return true;
	}
	return false;
}

void infoWindow( QWidget *w, const char *fileE, int type )
{
	if ( type == 0 && tag_editor )
		tag_editor->openWindow( fileE, w, false, false );
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
