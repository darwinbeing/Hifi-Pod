#include <curl/curl.h>

extern const unsigned int QMPVer( 1536 );
const char *Type = { "QMPInternet" };

#include <QStringList>
#include <QSettings>
#include <QFile>

QString QMPConf;

#include <string.h>
#include <stdlib.h>

#include <Functions.cpp>

bool useProxy = 0;
char *proxy = 0;
curl_off_t maxSpdDwn = 0;
curl_off_t maxSpdUpl = 0;
uint BUF_SIZE = 0;

enum QMPInternet_info
{
	CONNECT_TIME, FILE_SIZE, DOWNLOAD_SPEED, BYTES_DOWNLOADED, UPLOAD_SPEED, BYTES_UPLOADED
};

struct URL_FILE
{
	URL_FILE()
	{
		POSTdata = NULL;
		buffer = NULL;
		clear();
	}
	~URL_FILE()
	{
		if ( POSTdata )
			free( POSTdata );
		clear();
	}
	void clear()
	{
		if ( buffer )
		{
			free( buffer );
			buffer = NULL;
		}
		handle = NULL;
		multi_handle = NULL;
		dltotal = 0;
		buffer_len = buffer_pos = still_running = 0;
		header = QString();
	}

	CURL *handle;
	CURLM *multi_handle;
	char *buffer;               /* buffer to store cached data*/
	int buffer_len;             /* currently allocated buffers length */
	int buffer_pos;             /* end of data in buffer*/
	int still_running;          /* Is background url fetch still in progress */
	size_t dltotal;

	QString header, url, useragent;
	char *POSTdata;
	bool useProgress, follow;
};

extern "C" URL_FILE *url_fopen(bool,const char *,const char*,bool,long);
extern "C" int url_fclose(URL_FILE *);
extern "C" size_t url_fread(void *, size_t , size_t , URL_FILE *);
extern "C" bool url_feof(URL_FILE *);
extern "C" int url_fseek(URL_FILE *, long);
extern "C" double getInfo(URL_FILE *, QMPInternet_info);
extern "C" const char *getSettings( bool&, int&, int&, int& );
extern "C" void setSettings( const char*, bool, int, int, int );
extern "C" void setQMPConf(QString _QMPConf);
extern "C" QString getHeader(URL_FILE *);

QStringList protocols( QString( "http://;rtsp://;" ).split( ";", QString::SkipEmptyParts ) );

size_t write_callback( char *buffer, size_t size, size_t nitems, void *userp )
{
	char *newbuff;
	int rembuff;

	URL_FILE *url = (URL_FILE *)userp;
	size *= nitems;

	rembuff = url->buffer_len - url->buffer_pos;

	if ( size > rembuff )
	{
		newbuff = (char*)realloc( url->buffer, url->buffer_len + ( size - rembuff ) );
		if ( !newbuff )
			size = rembuff;
		else
		{
			url->buffer_len += size - rembuff;
			url->buffer = newbuff;
		}
	}

	memcpy( &url->buffer[ url->buffer_pos ], buffer, size );
	url->buffer_pos += size;

	return size;
}

double getInfo( URL_FILE *file, QMPInternet_info info )
{
	double d(0.0);
	switch ( info )
	{
		case CONNECT_TIME:
			curl_easy_getinfo(file->handle, CURLINFO_TOTAL_TIME, &d );
			break;
		case FILE_SIZE:
			d = file->dltotal;
			break;
		case DOWNLOAD_SPEED:
			curl_easy_getinfo(file->handle, CURLINFO_SPEED_DOWNLOAD, &d );
			break;
		case BYTES_DOWNLOADED:
			curl_easy_getinfo(file->handle, CURLINFO_SIZE_DOWNLOAD, &d );
			break;
		case UPLOAD_SPEED:
			curl_easy_getinfo(file->handle, CURLINFO_SPEED_UPLOAD, &d );
			break;
		case BYTES_UPLOADED:
			curl_easy_getinfo(file->handle, CURLINFO_SIZE_UPLOAD, &d );
			break;
	}
	return d;
}

bool fill_buffer( URL_FILE *file, int want )
{
	if ( !file->still_running || file->buffer_pos > want )
		return false;

	uint ile = 0;
	do
	{
		while ( curl_multi_perform( file->multi_handle, &file->still_running ) == CURLM_CALL_MULTI_PERFORM );

		if ( file->still_running && file->buffer_pos < want )
			MYsleep( 20 );
		if ( ++ile == 200 )
			return false;

	} while( file->still_running && file->buffer_pos < want );
	return true;
}

bool url_feof( URL_FILE *file )
{
	if ( file->buffer_pos == 0 && !file->still_running )
		return true;
	else
		return false;
}

int progress( URL_FILE *file, double dltotal, double /*dlnow*/, double /*ultotal*/, double /*ulnow*/ )
{
	if ( file )
		file->dltotal = dltotal;
	return 0;
}

size_t HeaderFunction( void *ptr, size_t size, size_t nmemb, void *stream )
{
	( *(QString *)stream ) += (char *)ptr;
	return size * nmemb;
}

bool url_fopen( URL_FILE *file, long from )
{
	file->handle = curl_easy_init();

	curl_easy_setopt( file->handle, CURLOPT_URL, file->url.toAscii().data() );

	if ( file->POSTdata )
	{
		curl_easy_setopt( file->handle, CURLOPT_POST, true );
		curl_easy_setopt( file->handle, CURLOPT_POSTFIELDS, file->POSTdata );
	}

	if ( proxy && useProxy && *proxy )
		curl_easy_setopt( file->handle, CURLOPT_PROXY, proxy );
	curl_easy_setopt(file->handle, CURLOPT_FOLLOWLOCATION, file->follow);

	curl_easy_setopt(file->handle, CURLOPT_WRITEHEADER, &file->header);
	curl_easy_setopt(file->handle, CURLOPT_HEADERFUNCTION, HeaderFunction);

	curl_easy_setopt(file->handle, CURLOPT_WRITEDATA, file);
	curl_easy_setopt(file->handle, CURLOPT_VERBOSE, false);
	curl_easy_setopt(file->handle, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(file->handle, CURLOPT_BUFFERSIZE, BUF_SIZE);

	if ( maxSpdDwn > 0 )
		curl_easy_setopt(file->handle, CURLOPT_MAX_RECV_SPEED_LARGE, maxSpdDwn*1024);
	if ( maxSpdUpl > 0 )
		curl_easy_setopt(file->handle, CURLOPT_MAX_SEND_SPEED_LARGE, maxSpdUpl*1024);

	if ( !file->useragent.isNull() )
	{
		if ( file->useragent.isEmpty() )
			curl_easy_setopt(file->handle, CURLOPT_USERAGENT, "Mozilla");
		else
			curl_easy_setopt(file->handle, CURLOPT_USERAGENT, file->useragent.toAscii().data());
	}

	if ( file->useProgress )
	{
		curl_easy_setopt(file->handle, CURLOPT_NOPROGRESS, 0);
		curl_easy_setopt(file->handle, CURLOPT_PROGRESSDATA, file);
		curl_easy_setopt(file->handle, CURLOPT_PROGRESSFUNCTION, progress);
	}
	curl_easy_setopt( file->handle, CURLOPT_RESUME_FROM, from );

	file->multi_handle = curl_multi_init();

	curl_multi_add_handle( file->multi_handle, file->handle );

	while ( curl_multi_perform( file->multi_handle, &file->still_running ) == CURLM_CALL_MULTI_PERFORM );

	if ( file->buffer_pos == 0 && !file->still_running )
	{
		curl_multi_remove_handle( file->multi_handle, file->handle );
		curl_easy_cleanup( file->handle );
		return false;
	}
	return true;
}

int url_fclose( URL_FILE *file, bool Free )
{
	curl_multi_remove_handle( file->multi_handle, file->handle );
	curl_multi_cleanup( file->multi_handle );
	curl_easy_cleanup( file->handle );

	if ( Free )
		delete file;
	else
		file->clear();

	return 0;
}

int url_fseek(URL_FILE *file, long pos)
{
	url_fclose( file, false );
	return url_fopen( file, pos );
}

void use_buffer( URL_FILE *file, int want )
{
	if ( file->buffer_pos - want <= 0 )
	{
		if ( file->buffer )
			free( file->buffer );

		file->buffer = NULL;
		file->buffer_pos = 0;
		file->buffer_len = 0;
	}
	else
	{
		memmove( file->buffer, &file->buffer[want], file->buffer_pos - want );
		file->buffer_pos -= want;
	}
}

#include <QMutexLocker>
QMutex mutex;

void readSave()
{
	QMutexLocker locker( &mutex );
	if (QFile::exists( QMPConf ))
	{
		QSettings *QMPset = new QSettings (QMPConf,QSettings::IniFormat);
		if ( QMPset->value("QMPInternet/QMPInternet").toBool() )
		{
			useProxy = QMPset->value("QMPInternet/useProxy").toBool();
			maxSpdDwn = QMPset->value("QMPInternet/maxSpdDwn").toInt();
			maxSpdUpl = QMPset->value("QMPInternet/maxSpdUpl").toInt();
			BUF_SIZE = QMPset->value("QMPInternet/BUF_SIZE").toInt();
			if ( BUF_SIZE < 256 )
				BUF_SIZE = 16384;
			QString tmpP;
			tmpP = QMPset->value("QMPInternet/proxy").toString();
			delete[] proxy;
			proxy = new char[ tmpP.length() + 1 ];
			strcpy( proxy, tmpP.toAscii() );
			tmpP.clear();

			delete QMPset;
		}
		else
			delete QMPset;
	}
}

URL_FILE *url_fopen(bool follow, const char *url, const char *useragent, bool useProgress, long from)
{
	URL_FILE *file = new URL_FILE;

	readSave();

	if ( useragent )
		file->useragent = useragent;

	if ( url )
	{
		QStringList urlL = QString( url ).split( '\n' );
		if ( urlL.count() >= 1 )
			file->url = urlL[ 0 ];
		if ( urlL.count() >= 2 )
			file->POSTdata = strdup( urlL[ 1 ].toAscii().data() );
	}

	file->useProgress = useProgress;
	file->follow = follow;

	bool b = url_fopen( file, from );
	if ( b )
		return file;
	else
	{
		delete file;
		return NULL;
	}
}

int url_fclose( URL_FILE *file )
{
	return url_fclose( file, true );
}

size_t url_fread(void *ptr, size_t size, size_t nmemb, URL_FILE *file)
{
	size_t want = nmemb * size;

	fill_buffer( file, want );

	if ( !file->buffer_pos )
		return 0;

	if( file->buffer_pos < want )
		want = file->buffer_pos;

	memcpy( ptr, file->buffer, want );

	use_buffer( file, want );

	want /= size;

	return want;
}

const char *getSettings( bool &_useProxy, int &_maxSpdDwn, int &_maxSpdUpl, int &_BUF_SIZE )
{
	readSave();
	_useProxy = useProxy;
	_maxSpdDwn = maxSpdDwn;
	_maxSpdUpl = maxSpdUpl;
	_BUF_SIZE = BUF_SIZE;
	if ( _BUF_SIZE < 256 )
		_BUF_SIZE = 16384;
	else
		_BUF_SIZE = BUF_SIZE;
	return (const char *)proxy;
}

void setSettings( const char* proxy, bool useProxy, int maxSpdDwn = 0, int maxSpdUpl = 0, int BUF_SIZE = 0 )
{
	QSettings *QMPset = new QSettings (QMPConf,QSettings::IniFormat);

	QMPset->setValue("QMPInternet/QMPInternet",true);

	QMPset->setValue("QMPInternet/useProxy",useProxy);
	QMPset->setValue("QMPInternet/proxy",proxy);
	QMPset->setValue("QMPInternet/maxSpdDwn",maxSpdDwn);
	QMPset->setValue("QMPInternet/maxSpdUpl",maxSpdUpl);
	QMPset->setValue("QMPInternet/BUF_SIZE",BUF_SIZE);

	delete QMPset;
}

void setQMPConf(QString _QMPConf)
{
	QMPConf = _QMPConf;
}

QString getHeader( URL_FILE *file )
{
	if ( file )
		return file->header;
	else
		return QString();
}
