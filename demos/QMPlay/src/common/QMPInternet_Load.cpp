#include <QLibrary>

#include "libExt.h"

#ifdef Q_WS_WIN
	const QString QMPInternetf = "lib/qmp_internet_support";
#else
	const QString QMPInternetf = "lib/libqmp_internet_support";
#endif

typedef void URL_FILE;

enum QMPInternet_info
{
	CONNECT_TIME, FILE_SIZE, DOWNLOAD_SPEED, BYTES_DOWNLOADED, UPLOAD_SPEED, BYTES_UPLOADED
};

typedef URL_FILE* (*_url_fopen)(bool, const char *, const char *, bool, long);
typedef int (*_url_fclose)(URL_FILE *);
typedef size_t (*_url_fread)(void *, size_t, size_t, URL_FILE *);
typedef void (*_setQMPConf)(QString);
typedef bool (*_url_feof)(URL_FILE*);
typedef int (*_url_fseek)(URL_FILE*, long);
typedef double (*_getInfo)(URL_FILE*, QMPInternet_info);
typedef QString (*_getHeader)(URL_FILE *);

_url_fopen __url_fopen;
_url_fclose __url_fclose;
_url_fread __url_fread;
_setQMPConf __setQMPConf;
_url_feof __url_feof;
_url_fseek __url_fseek;
_getInfo __getInfo;
_getHeader __getHeader;

URL_FILE *url_fopen(const char *a)
{
	return __url_fopen(false,a,NULL,false,0);
}
URL_FILE *url_fopen(const char *a, const char *b)
{
	return __url_fopen(false,a,b,false,0);
}
URL_FILE *url_fopen(const char *a, bool b)
{
	return __url_fopen(false,a,NULL,b,0);
}
URL_FILE *url_fopen(const char *a, const char *b, bool c)
{
	return __url_fopen(false,a,b,c,0);
}
URL_FILE *url_fopen(const char *a, const char *b, bool c, long d)
{
	return __url_fopen(false,a,b,c,d);
}
URL_FILE *url_fopen(bool a,const char *b)
{
	return __url_fopen(a,b,NULL,false,0);
}
URL_FILE *url_fopen(bool a,const char *b, const char *c)
{
	return __url_fopen(a,b,c,false,0);
}
URL_FILE *url_fopen(bool a,const char *b, bool c)
{
	return __url_fopen(a,b,NULL,c,0);
}
URL_FILE *url_fopen(bool a,const char *b, const char *c, bool d)
{
	return __url_fopen(a,b,c,d,0);
}
URL_FILE *url_fopen(bool a, const char *b, const char *c, bool d, long e)
{
	return __url_fopen(a,b,c,d,e);
}

int url_fclose(URL_FILE *a)
{
	return __url_fclose(a);
}
size_t url_fread(void *a, size_t b, size_t c, URL_FILE *d)
{
	return __url_fread(a,b,c,d);
}
bool url_feof(URL_FILE *a)
{
	return __url_feof(a);
}
int url_fseek(URL_FILE *a, long b)
{
	return __url_fseek(a,b);
}
double getNetInfo(URL_FILE *a, QMPInternet_info b)
{
	return __getInfo(a,b);
}
QString getHeader(URL_FILE *a)
{
	return __getHeader(a);
}

bool chkQMPInternet( QLibrary *lib = NULL )
{
	if ( !lib )
		return false;

	const char **Type = (const char **)lib->resolve( "Type" );
	const uint *libVer = (const uint *)lib->resolve( "QMPVer" );

	if ( !Type || !libVer )
		return false;

	if ( 1536 == *libVer && !strcmp( *Type, "QMPInternet" ) )
		return true;
	return false;
}

QLibrary QInternet_lib;

uint CURLloaded(0);

void unloadCURL()
{
	if ( CURLloaded == 1 )
	{
		__url_fread = NULL;
		__url_fopen = NULL;
		__url_fclose = NULL;
		__url_feof = NULL;
		__getInfo = NULL;
		__setQMPConf = NULL;
		__getHeader = NULL;
		QInternet_lib.unload();
	}
	if ( CURLloaded )
		CURLloaded--;
}

QString loadCURL()
{
	if ( CURLloaded )
	{
		CURLloaded++;
		return "";
	}
	QInternet_lib.setFileName( QMPInternetf+libExt );
	if ( QInternet_lib.load() && chkQMPInternet( &QInternet_lib ) )
	{
		__setQMPConf = (_setQMPConf) QInternet_lib.resolve ( "setQMPConf" );
		__url_fopen  = (_url_fopen)  QInternet_lib.resolve ( "url_fopen"  );
		__url_fclose = (_url_fclose) QInternet_lib.resolve ( "url_fclose" );
		__url_fread  = (_url_fread)  QInternet_lib.resolve ( "url_fread"  );
		__url_feof   = (_url_feof)   QInternet_lib.resolve ( "url_feof"   );
		__url_fseek  = (_url_fseek)  QInternet_lib.resolve ( "url_fseek"  );
		__getInfo    = (_getInfo)    QInternet_lib.resolve ( "getInfo"    );
		__getHeader  = (_getHeader)  QInternet_lib.resolve ( "getHeader"  );
		if ( __url_fopen && __url_fclose && __url_fread && __setQMPConf && __url_feof && __getInfo && __url_fseek && __getHeader )
		{
			__setQMPConf(QMPConf);
			CURLloaded++;
		}
		else
		{
			unloadCURL();
			return "Nie można załadować symboli!";
		}
		return "";
	}
	else
		return QInternet_lib.errorString();
}
