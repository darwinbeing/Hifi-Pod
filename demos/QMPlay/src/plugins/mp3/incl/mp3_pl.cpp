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
FILE *qmp_fopen( const char *name, const char *params )
{
#ifdef Q_WS_WIN
	return _wfopen( ( const wchar_t * )QString( name ).utf16(), ( const wchar_t * )QString( params ).utf16() );
#else
	return fopen( name, params );
#endif
}

const int BUF_SIZE = 4096;
const int DATA_BUFF = 16384;
int _DATA_BUFF = 0;
char *audio_buffer, *data;

typedef unsigned long long uint64_t;

uint64_t doSeek;

QString plikbezsciezki( QString pth )
{
	return QLib->stringOperations( PLIK_BEZ_SCIEZKI, pth );
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

URL_FILE *f = NULL;
int fd = -1;

struct titleThr : public QThread
{
	public:
		void run()
		{
			QString tmpT;
			getMusInfo( 0, 0, 0, &title, &tmpT, &Artist, 2, "" );
			if ( tmpT != Title )
			{
				Title = tmpT;
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
	mpg123_close(musicfile);
	mpg123_delete(musicfile);
	if ( fd > -1 )
	{
		close( fd );
		fd = -1;
	}

	if ( Type == 2 )
	{
		delete[] data;
		if ( f )
			url_fclose(f);
		f = NULL;
	}

	if ( Type == 2 )
		unloadCURL();

	IsPlaying = false;

	pix = QImage();
	id3Str.clear();

	_DATA_BUFF = 0;
}

void STOP()
{
	QOut->control( QOUT_FLUSH );
	delete[] audio_buffer;
	titleThr.doExit();
	CLOSE();
	endSong = true;
}

void ERROR2( QString errStr )
{
	fo->close();
	MUSerr = true;
	title = errStr;
	QLib->showMessage( "Błąd", errStr, 2, 0, true );
}

void ERROR( QString errStr )
{
	clrPos();
	ERROR2( errStr );
	CLOSE();
}

bool getDataBuff( void *f, size_t(*_fread)(void *, size_t, size_t, void *), int &_DATA_BUFF, char **data, bool *bolStop = NULL )
{
	int TagSize = 0;
	char *fB = new char[10];
	int bread = 0;
	int MAX_ILE = 3;
	if ( !bolStop )
		MAX_ILE = 1;
	for ( int i = 0 ; i < MAX_ILE ; i++ )
	{
		bread = _fread( fB, 1, 10, f );
		if ( bread || ( bolStop && *bolStop ) )
			break;
	}
	if ( !( bolStop && *bolStop ) && bread == 10 && !strncmp( "ID3", fB, 3 ) )
		TagSize = ID3_getTagSize( fB );
	if ( ( bolStop && *bolStop ) || bread < 10 )
	{
		delete[] fB;
		return false;
	}
	_DATA_BUFF = DATA_BUFF + TagSize;
	if ( data )
	{
		*data = new char[ _DATA_BUFF ];
		memset( *data, 0, _DATA_BUFF );
		memcpy( *data, fB, 10 );
	}
	delete[] fB;
	return true;
}

void play( const char *fileE, int )
{
	if ( Type != 0 && Type != 2 )
		return ERROR2( "Wtyczka obsługuje tylko odczyt plików i strumienia internetowego!" );

	if ( Type == 2 )
	{
		QString tmp = loadCURL();
		if ( !CURLloaded )
			return ERROR2( "Nie można załadować biblioteki: "+QMPInternetf+libExt+"\n"+tmp );
	}

	if ( fileE != curF )
		clrPos();

	clrSet();

	QString BLAD;
	if ( Type == 0 )
		BLAD = "Błąd odczytu pliku!";
	else if ( Type == 2 )
		BLAD = "Nie można otworzyć strumienia internetowego!";

	musicfile = mpg123_new(NULL, NULL);
	if ( Type == 0 )
	{
		fd = qmp_open( fileE, O_RDONLY|O_BINARY );
		mpg123_open_fd( musicfile, fd );
	}
	if ( Type == 2 )
	{
		title = "Czekaj, trwa otwieranie...";

		mpg123_open_feed( musicfile );

		f = url_fopen(fileE,0,1);
		if ( !f )
			return ERROR(BLAD);

		if ( !getDataBuff( f, url_fread, _DATA_BUFF, &data, &bolStop ) )
			return ERROR(BLAD);

		url_fread(data+10, 1, _DATA_BUFF-10, f);

		if ( getNetInfo( f, FILE_SIZE ) > 0.0 )
			knownSize = true;
		mpg123_decode( musicfile, (const unsigned char*)data, _DATA_BUFF, 0,0,0 );
	}

	if ( !musicfile )
		return ERROR(BLAD);

	curF = fileE;

	if ( !MP3Update() )
		return ERROR(BLAD);

	if ( Type == 2 && title.isEmpty() )
		title = fileE;

	if ( Type == 2 || ( Type == 0 && fileE[0] == '/' && fileE[1] == '/' ) )
		QOut->useQMPBuffer();
	QOut->Init( AudioInfo( rate, 16, chn ), true, 0, fileE, /*title*/Title );

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR("Błąd zwraca wtyczka wyjściowa!");
	}

	IsPlaying = true;
	size_t bDecoded = 0;
	audio_buffer = new char[BUF_SIZE];
	TMPint = 0;
	int musErr = 0;
	for(;;)
	{
		if ( bolStop )
			break;
		if ( !IsPaused )
		{
			if ( !*QOut->mustReset )
			{
				if ( doSeek )
				{
					mpg123_seek( musicfile, doSeek, SEEK_SET );
					QOut->control( QOUT_NEXT_READ );
					doSeek = 0;
				}

				musErr = mpg123_read( musicfile, (unsigned char*)audio_buffer, BUF_SIZE, &bDecoded );
				if ( musErr == MPG123_DONE )
					break;
				if ( musErr == MPG123_ERR && !searchParts )
					break;
				QOut->Play( audio_buffer, bDecoded, pltime, false );
				MP3Update2( bDecoded );
				if ( musErr == MPG123_NEED_MORE && Type != 0 )
				{
					int bread = url_fread( data, 1, _DATA_BUFF, f );
					if ( ( !bread && !wait4Data ) || ( !bread && url_feof(f) ) )
						break;
					else if ( !bread )
						MYsleep( 25 );
					mpg123_decode( musicfile, (const unsigned char*)data, bread, NULL, 0, NULL );
				}
			}
			else
				QOut->Play(0,0,pltime,true);
		}
		else
			QOut->Play(0,0,pltime,true);
	}
	STOP();
}

QString getTitle()
{
	if ( Type != 2 )
		return "";
	URL_FILE *uFile = url_fopen(curF.toUtf8().data(),"");
	if (!uFile)
		return "";
	char *data = new char[_DATA_BUFF];
	url_fread(data,1,_DATA_BUFF,uFile);
	url_fclose(uFile);
	char *t = getICYTitle(data,_DATA_BUFF);
	QString t2 = t;
	delete[] t;
	delete[] data;
	return t2;
}

bool getMusInfo( mpg123_handle *mus, long *r, int *c, QString *_t, QString *T, QString *A, int type, const char *fileE )
{
	if ( mus )
	{
		int chn(0),e(0);
		long rate(0);
		mpg123_getformat(mus, &rate, &chn, &e);

		if ( rate == 0 || chn == 0 )
			return false;

		if ( type < 0 )
			return true;

		if ( r )
			*r = rate;
		if( c )
			*c = chn;
	}
	else if ( !type )
		return false;

	QString Title, Artist, t;

	if ( ( type == 0 || ( type == 2 && knownSize ) ) && ( _t || T || A ) )
	{
		if ( tag_editor && type == 0 )
		{
			QString data = tag_editor->getData( fileE, NULL );
			if ( !data.isEmpty() )
			{
				Title = getTagFromData( data, "Title" );
				Artist = getTagFromData( data, "Artist" );
			}
		}
		else //jeżeli biblioteka do ID3 nie została załadowana
		{
			mpg123_id3v1 *v1;
			mpg123_id3v2 *v2;
			mpg123_id3(mus, &v1, &v2);
			mpg123_id3(mus, &v1, &v2);

			if ( v2 != NULL )
			{
				if ( v2->title && v2->title->p )
					Title  = v2->title->p;
				if ( v2->artist && v2->artist->p )
					Artist = v2->artist->p;
			}
			if ( v1 != NULL )
			{
				if ( Artist.isEmpty() )
					Artist = v1->artist;
				if ( Title.isEmpty() )
					Title  = v1->title;
			}
		}

		if ( !Title.isEmpty() )
		{
			t = Title;
			if ( !Artist.isEmpty() )
				t = Artist + " - " + Title;
		}
	}
	if ( type == 2 && !knownSize )
	{
		Title = getTitle();
		if (mus)
		{
			char *a = getICYName( data, _DATA_BUFF );
			if (a)
				Artist = a;
			delete[] a;
		}
		else if (A)
			Artist = *A;

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

	return true;
}

QString getId3( int Type, QString file, QImage *pix )
{
	if ( Type != 0 || !tag_editor )
		return "";
	QString tmp = tag_editor->getData( file.toUtf8(), pix );
	if ( pix && !pix->isNull() )
		*pix = pix->scaledToWidth( 46, Qt::SmoothTransformation );
	return tmp;
}
bool MP3Update()
{
	if ( !getMusInfo( musicfile, &rate, &chn, &title, &Title, &Artist, Type, curF.toUtf8() ) )
		return false;

	id3Str = getId3(Type,curF,&pix);

	updateF = true;

	tmpPltime = 0;

	double lSec;
	if ( Type == 0 )
		mpg123_position(musicfile,0,0,0,0,0,&lSec);
	else
		lSec = -1;

	plMaxtime = lSec;
	if ( Type == 0 )
		NumPos = plMaxtime-1;
	else
		NumPos = -1;

	if (savsek != 0 )
	{
		seek(savsek);
		pltime = -1;
	}
	savsek = 0;

	if ( Type == 2 )
	{
		if ( knownSize )
		{
			if ( title.isEmpty() )
				title = plikbezsciezki( curF );
			int idx = title.indexOf( "QMPlay_title=" );
			if ( idx > -1 )
				title = title.mid( idx + 13, title.length() - ( idx + 13 ) );
			QLib->updateCurrPlistEntry( title );
		}
		else
			QLib->updateCurrPlistEntry( Artist );
	}

	return true;
}

void MP3Update2( long BUF_SIZE )
{
	double cSec;
	mpg123_position(musicfile,0,0,0,0,&cSec,0);

	if ( Type == 2 && !knownSize )
	{
		currBytes += BUF_SIZE;
		pltime = currBytes / (rate*chn*2);
	}
	else
		pltime = cSec;
	SongPos = pltime;

	mpg123_info(musicfile,&frameinfo);
	getBR = QString::number( frameinfo.bitrate ) + "kbps";

	if ( pltime != tmpPltime && Type == 2 && !knownSize )
	{
		TMPint++;
		tmpPltime = pltime;
	}
	if ( Type == 2 && TMPint == 10 && !knownSize )
	{
		TMPint = 0;
		if ( !titleThr.isRunning() )
			titleThr.start();
	}
}

void stop()
{
	bolStop = true;
}

void seek(int &i)
{
	uint64_t r = i * rate;
	i = -1;
	if ( NumPos < 1 || r > (uint64_t)( rate * NumPos ) )
		return;
	doSeek = r;

	pauseD = false;
	IsPaused = false;
}

void togglePause()
{
	if ( IsPaused )
		IsPaused = false;
	else
		IsPaused=true;
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
	mpg123_init();
	if ( type > -1 )
	{
		Type = type;
		canUpdateEntry = !type;
	}
}

void setFormInfo( int *siz )
{
	if ( siz )
		fo->resize( siz[0], siz[1] );
	else
		fo->close();
}

QWidget *Show( QWidget *w )
{
	if ( Type == 1 )
		return NULL;
	if ( fo->isVisible() )
		fo->closeEvent(NULL);
	fo->setParent(w);
	fo->Init();
	fo->show();
	return fo;
}

void clrSet()
{
	knownSize = false;
	currBytes = 0;
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	plMaxtime = 0;
	IsPaused = false;
	musicfile = NULL;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	endSong = false;
	curF.clear();
	getBR = "n/a";

	doSeek = 0;

	data = NULL;
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

	mpg123_exit();
}

const QString PlugInfoStr("MP3 (libmpg123) Input Plugin");
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
		if ( !title || !time )
			return;

		mpg123_handle *mus = NULL;
		mus = mpg123_new(NULL, NULL);
		int fd = qmp_open( fileE, O_RDONLY|O_BINARY );
		mpg123_open_fd( mus, fd );

		if ( !mus )
		{
			mpg123_close(mus);
			mpg123_delete(mus);
			if ( fd > -1 )
				close( fd );

			if ( title )
				*title = "";
			if ( time )
				*time = -2;

			return;
		}

		QString t;

		bool OK(0);
		if ( !notReadID3 )
			OK = getMusInfo( mus, NULL, NULL, &t, NULL, NULL, type, fileE );
		else
			OK = getMusInfo( mus, NULL, NULL, NULL, NULL, NULL, type, fileE );

		if ( !OK )
		{
			mpg123_close(mus);
			mpg123_delete(mus);
			if ( fd > -1 )
				close( fd );

			if ( title )
				*title = "";
			if ( time )
				*time = -2;

			return;
		}

		if ( !notReadID3 && title )
			*title = t;

		if ( time )
		{
			double lSec;
			mpg123_position(mus,0,0,0,0,0,&lSec);
			*time = lSec;
		}

		mpg123_close(mus);
		mpg123_delete(mus);
		if ( fd > -1 )
			close( fd );
	}
}

void infoWindow(QWidget *w, const char *fileE, int type)
{
	if ( type != 0 )
		return;
	if ( tag_editor )
		tag_editor->openWindow( fileE, w, false, false );
}

bool FileFormatSupport( const char *fileE )
{
	FILE *f = qmp_fopen( fileE, "rb" );
	if ( !f )
		return 0;

	int _DATA_BUFF;
	if ( !getDataBuff( f, (size_t(*)(void *, size_t, size_t, void *))fread, _DATA_BUFF, NULL ) )
	{
		fclose(f);
		return false;
	}
	int TagSize = _DATA_BUFF - DATA_BUFF;

	bool loaded(0);
	mpg123_handle *mus = mpg123_new(NULL, NULL);
	mpg123_open_feed( mus );
	fseek(f,TagSize,0);
	char *data = new char[DATA_BUFF];
	int bread = fread( data, 1, DATA_BUFF, f );
	fclose(f);
	mpg123_decode( mus, (const unsigned char*)data, bread, 0,0,0 );
	delete[] data;
	loaded = getMusInfo( mus, 0,0,0,0,0, -1, "" );
	mpg123_close(mus);
	mpg123_delete(mus);
	return loaded;
}

QString InternetFormatSupport( const char* address )
{
	loadCURL();
	if ( !CURLloaded )
		return "";
	mpg123_handle *mus = mpg123_new(NULL, NULL);
	mpg123_open_feed( mus );
	URL_FILE *f = url_fopen( address );
	if ( !f )
	{
		unloadCURL();
		return "";
	}

	char *data;
	int _DATA_BUFF;
	if ( !getDataBuff( f, url_fread, _DATA_BUFF, &data ) )
	{
		url_fclose(f);
		unloadCURL();
		return "";
	}

	int bread = url_fread(data+10, 1, _DATA_BUFF-10, f);
	mpg123_decode( mus, (const unsigned char*)data, bread, 0,0,0 );
	bool loaded = getMusInfo( mus, 0,0,0,0,0, -1, "" );
	mpg123_close(mus);
	mpg123_delete(mus);
	delete[] data;
	url_fclose(f);
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

QString getMusStr(const char *fileE, int type, QPixmap &pix)
{
	QString musStr;
	pix = NULL;
	if ( type == 0 && tag_editor )
	{
		bool ok = true;
		FILE *f = qmp_fopen( fileE, "rb" );
		if ( f )
		{
			char b3[3];
			fread( b3, 1, 3, f );
			fclose( f );
			if ( b3[0] == 0 && b3[1] == 0 && b3[2] == 0 )
				ok = false;
		}
		if ( ok )
		{
			QImage img;
			musStr = tag_editor->getData( fileE, &img );
			pix = QPixmap::fromImage( img );
			if ( !musStr.isEmpty() )
				musStr = "\n"+musStr;
		}
	}
	return musStr;
}
