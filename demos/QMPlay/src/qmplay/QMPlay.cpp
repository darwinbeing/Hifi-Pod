#include <QLibrary>
#include <QMessageBox>
#include <QDir>
#include <QApplication>
#include <QSettings>
#include <QTextCodec>
#include <signal.h>
#ifdef Q_WS_WIN
	#include <windows.h>
#else
	#include <unistd.h>
#endif

QLibrary QMPLIB;
QString homeP = QDir::homePath();

const QString QsignalE = QDir::tempPath() + "/QMPlaySignal";
const QString QMPfiles = QDir::tempPath() + "/QMPlayFiles";

QString QMPVer;
int QMPVerI(0);

struct Qmp
{
	void (*main)( const QStringList &, Qmp*, QString, QString, QString );
	/* ... */
};

#ifdef Q_OS_MAC
	const QString libExt = ".dylib";
#endif
#ifdef Q_WS_WIN
	const QString libExt = ".dll";
#endif
#ifdef Q_WS_X11
	const QString libExt = ".so";
#endif

#ifdef Q_WS_WIN
	const QString QMPLib = "lib/qmp_lib";
#else
	const QString QMPLib = "lib/libqmp_lib";
#endif

QString QMPConf;

int setLang( const QString &lang )
{
	QSettings *QMPset = new QSettings( QMPConf , QSettings::IniFormat );

	QMPset->setValue( "QMPset/language", lang );

	QMPset->sync();
	delete QMPset;

	return 0;
}

int sendsig( char sig )
{
	QFile fsig( QsignalE );
	if ( !fsig.open( QFile::ReadOnly ) )
		return 1;
	fsig.close();
	if ( fsig.open( QFile::WriteOnly ) )
	{
		fsig.putChar( sig );
		fsig.close();
		return 0;
	}
	return 1;
}

int rmsets()
{
	if ( QFile::remove( QMPConf ) )
		printf( "File deleted\n" );
	else
		printf( "File not deleted\n" );

	return 0;
}

int sendsig( char sig, const QString &argv2 )
{
	QFile fsig( QsignalE );

	if ( !fsig.open( QFile::ReadOnly ) )
		return 1;
	fsig.close();

	int len = argv2.length();

	if ( sig == 7 && len > 1 )
	{
		QFile ffiles( QMPfiles );
		if ( !ffiles.open( QFile::Append ) )
			return 1;
		ffiles.write( argv2.toUtf8() + '\n' );
		ffiles.close();
	}

	if ( !fsig.open( QFile::WriteOnly ) )
		return 1;
	fsig.putChar( sig );
	if ( sig == 9 || sig == 16 )
	{
		if ( len > 1 )
			fsig.write( argv2.toUtf8() );
	}
	else if ( sig == 24 )
	{
		if ( len > 0 )
			fsig.write( argv2.toUtf8() );
	}
	fsig.close();

	return 0;
}

int help()
{
	QString hlpstr("QMPlay"+QMPVer+"\
 - The QT Music Player\n\n\
Uzycie:\n\
   qmplay              - uruchamia program\n\
   qmplay [sciezka]    - uruchamia program i otwiera wskazany plik\n\
   qmplay [parametr][] - przesyła wybrany parametr do uruchomionego programu\n\n\
Parametry:\n\
   --new    [name] -N  - uruchamia nowe okno programu, czyści listę i odtwarza plik\n\
   --help          -h  - wyswietla tę pomoc\n\
   --quit          -q  - zamyka program\n\
   --openquit      -oq - zamyka lub otwiera QMPlay (działa w tle w systemie Linux)\n\
   --play          -p  - odtwarza muzykę\n\
   --stop          -s  - zatrzymuje odtwarzaną myzykę\n\
   --pause         -pa - wstrzymuje odtwarzaną myzykę\n\
   --next          -n  - odtwarza nastepną muzykę\n\
   --prev          -pr - odtwarza poprzednią muzykę\n\
   --playpause     -t  - odtwarza i zatrzymuje muzykę\n\
   --noplay        -np - uruchamia program bez rozpoczęcia odtwarzania\n\
   --add    [name] -a  - dodaje plik do listy\n\
   --last          -l  - odtwarza ostatni plik na liście\n\
   --volup         -vu - zgłaśnia o 5\n\
   --voldown       -vd - przycisza o 5\n\
   --windowpos     -wp - minimalizacja / majsymalizacja\n\
   --seekP         -sp - przewija do przodu\n\
   --seekM         -sm - przewija do tylu\n\
   --export        -e  - eksportuje muzykę do pliku\n\
   --rmset         -rm - usuwa ustawienia QMPlay\n\
   --alast  [name] -al - dodaje plik do listy i odtwarza go\n\
   --llist         -ll - ładuje aktualnie zaznaczoną listę\n\
   --nlist         -nl - ładuje następną playlistę\n\
   --plist         -pl - ładuje poprzednią playlistę\n\
   --clrlist       -cl - czyści listę playlist\n\
   --clsplist      -cp - czyści playlistę\n\
   --setlang [lng] -sl - ustawia język\n\
   --miniqmp       -mq - włącza Mini QMPlay\n\
   --hideshow      -hs - ukrywa do traya lub przywraca okno\n\
   --sendkey [key] -sk - wysyła klawisz do aktywnego lub głównego okna\
");
#ifdef Q_WS_WIN
	hlpstr += "\n   --console           - pokazuje okienko konsoli cmd";
	QMessageBox::information( NULL, "QMPlay - help", hlpstr );
#else
	printf( "\n%s\n\n", hlpstr.toUtf8().data() );
#endif
	return 0;
}

bool getChar(char c)
{
	char sig = 0;

	QFile fsig( QsignalE );
	if ( fsig.open( QFile::ReadOnly ) )
	{
		fsig.getChar( &sig );
		fsig.close();
	}

	bool par = false;
	if ( sig == c )
		par = true;
	else
		par = false;
	return par;
}
bool programIsOpen()
{
	return getChar( 'Q' );
}
bool qmpExitSIGSEGVorABORT()
{
	return getChar( 'A' );
}

bool b = false;
bool QMPLIBload()
{
	if ( !b )
	{
		printf( "Loading QMPlay main library... " );
		fflush(stdout);
	}
	bool l = QMPLIB.load();
	if ( !b && l )
		printf( "OK\n" );
	else if ( !b && !l )
		printf( "FAILED\n" );
	b = true;
	return l;
}

void getQMPVer()
{
	if ( QMPLIBload() )
	{
		QMPVer = " " + *(QString*) QMPLIB.resolve("QMPVersion");
		QMPVerI = *(int*) QMPLIB.resolve("QMPVersionI") * 10 + *(uchar*) QMPLIB.resolve("QMPVer2");
	}
}

#ifdef Q_WS_WIN
	#include <process.h>
	bool consoleIsOpen = false;
	void openConsole()
	{
		AllocConsole();
		SetConsoleTitle( "QMPlay" );
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
		consoleIsOpen = true;
	}
#endif

void error(int sig)
{
	QFile fsig( QsignalE );
	if ( fsig.open( QFile::WriteOnly ) )
	{
		fsig.putChar( 'A' );
		fsig.close();
	}

#ifndef Q_WS_WIN
	const int SC = SIGKILL;
#else
	const int SC = SIGBREAK;
#endif

	const char sypnalsie[] = { "W QMPlay wystapil powazny blad.\nZostal zakonczony sygnalem: " };

	char SIGSTR[10];
	SIGSTR[0] = '\0';
	switch(sig)
	{
		case SIGSEGV:
			strcpy( SIGSTR, "SIGSEGV" );
			break;
		case SIGABRT:
			strcpy( SIGSTR, "SIGABRT" );
			break;
		case SIGFPE:
			strcpy( SIGSTR, "SIGFPE" );
			break;
#ifndef Q_WS_WIN
		case SIGTSTP:
			strcpy( SIGSTR, "SIGTSTP" );
			raise(SC);
			break;
#endif
	}
#ifdef Q_WS_WIN
	if ( !consoleIsOpen )
		openConsole();
#endif
	printf("\n%s%s\n",sypnalsie,SIGSTR);

#ifdef Q_WS_WIN
	getchar();
#endif

	raise(SC);
}

#ifdef Q_WS_WIN
	const QString QMPConfFile = "/QMPlay.conf";
#else
	const QString QMPConfFile = "/.QMPlay.conf";
#endif

int main( int _argc, char *_argv[] )
{
	QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
#ifdef Q_WS_X11
	bool useGUI = getenv( "DISPLAY" );
#else
	bool useGUI = true;
#endif
	new QApplication( _argc, _argv, useGUI );

	signal(SIGSEGV, error);
	signal(SIGABRT, error);
	signal(SIGFPE , error);
#ifndef Q_WS_WIN
	signal(SIGTSTP, error);
#endif

	qApp->setApplicationName( "QMPlay" );
	QDir::setCurrent( qApp->applicationDirPath() );

#ifndef Q_WS_WIN
	if ( homeP.length() <= 1 )
#else
	if ( homeP.length() <= 3 )
#endif
		homeP = qApp->applicationDirPath();

	QMPConf = homeP + QMPConfFile;
	QMPLIB.setFileName( QMPLib+libExt );

#ifdef Q_WS_WIN
	if ( strlen( _argv[ _argc - 1 ] ) == 9 && !strncmp( _argv[ _argc - 1 ], "--console", 9 ) )
		openConsole();
#endif

	bool removeQMPFiles = true;
	bool _programIsOpen = programIsOpen();
	const QStringList &argv = qApp->arguments();
	int argc = argv.size();
	QString opcja;
	if ( argc > 1 )
	{
		opcja = argv[1];

		if ( opcja == "--help" || opcja == "-h" )
		{
			if ( useGUI )
				getQMPVer();
			return help();
		}

		if ( ( opcja == "--openquit" || opcja == "-oq" ) && argc == 2 && _programIsOpen )
			return sendsig(0);

#ifndef Q_WS_WIN
		if ( opcja == "--openquit" || opcja == "-oq" )
		{
			int i = fork();
			if ( i < 0 )
				exit(1);
			if ( i > 0 )
				exit(0);
		}
#endif

		if ( ( opcja == "--setlang" || opcja == "-sl" ) && argc > 2 )
			return setLang( argv[2] );

		if ( opcja == "--quit" || opcja == "-q" )
			return sendsig(0);

		if ( opcja == "--play" || opcja == "-p" )
			return sendsig(1);

		if ( opcja == "--stop" || opcja == "-s" )
			return sendsig(2);

		if ( opcja == "--pause" || opcja == "-pa" )
			return sendsig(3);

		if ( opcja == "--next" || opcja == "-n" )
			return sendsig(4);

		if ( opcja == "--prev" || opcja == "-pr" )
			return sendsig(5);

		if ( opcja == "--playpause" || opcja == "-t" )
			return sendsig(6);

		if ( ( opcja == "--add" || opcja == "-a" ) && argc > 2 )
		{
			bool e = QFile::exists( QsignalE );
			if ( !e )
			{
				QFile fsig( QsignalE );
				if ( fsig.open( QFile::WriteOnly ) )
					fsig.close();
			}
			int ret = sendsig( 7, argv[2] );
			if ( e )
				return ret;
			removeQMPFiles = false;
		}

		if ( opcja == "--last" || opcja == "-l" )
			return sendsig(8);

		if ( opcja == "--volup" || opcja == "-vu" )
			return sendsig(10);

		if ( opcja == "--voldown" || opcja == "-vd" )
			return sendsig(11);

		if ( opcja == "--windowpos" || opcja == "-wp" )
			return sendsig(12);

		if ( opcja == "--seekM" || opcja == "-sm" )
			return sendsig(13);

		if ( opcja == "--seekP" || opcja == "-sp" )
			return sendsig(14);

		if ( opcja == "--export" || opcja == "-e" )
			return sendsig(15);

		if ( ( opcja == "--alast" || opcja == "-al" ) && argc > 2 )
		{
			if ( !_programIsOpen )
			{
				QFile fsig( QsignalE );
				if ( fsig.open( QFile::WriteOnly ) )
					fsig.close();
			}
			int ret = sendsig( 16, argv[2] );
			if ( _programIsOpen )
				return ret;
		}

		if ( opcja == "--llist" || opcja == "-ll" )
			return sendsig(17);
		if ( opcja == "--nlist" || opcja == "-nl" )
			return sendsig(18);
		if ( opcja == "--plist" || opcja == "-pl" )
			return sendsig(19);

		if ( opcja == "--clrlist" || opcja == "-cl" )
			return sendsig(20);
		if ( opcja == "--clrplist" || opcja == "-cp" )
			return sendsig(21);

		if ( opcja == "--miniqmplay" || opcja == "-mq" )
			return sendsig(22);
		if ( opcja == "--hideshow" || opcja == "-hs" )
			return sendsig(23);

		if ( opcja == "--rmset" || opcja == "-rm" )
			return rmsets();

		if ( opcja == "--sendkey" || opcja == "-sk" )
		{
			if ( argc > 2 )
				return sendsig(24,argv[2]);
			else
			{
				printf( "Nie podano klawisza...\n" );
				return 0;
			}
		}

		if ( _programIsOpen && opcja[0] != '-' )
			return sendsig(9,argv[1]);
		if ( _programIsOpen && ( opcja == "--openquit" || opcja == "-oq" ) && argc > 2 )
			return sendsig(9,argv[2]);
	}

	if ( removeQMPFiles )
		QFile::remove( QMPfiles );

	if ( !useGUI )
	{
		printf( "QMPlay: cannot connect to display!\n" );
		return 0;
	}

	bool load = QMPLIBload();

	getQMPVer();

	if ( !QFile::exists( QMPLib+libExt ) )
	{
		QMessageBox::warning(NULL,"Warning!","File not found: "+QMPLib+libExt);
		return 0;
	}
	if ( !load )
	{
		QMessageBox::warning(NULL,"Warning!","Cannot load file: "+QMPLib+libExt+"\n"+QMPLIB.errorString());
		return 0;
	}
	if ( QMPVerI < 1541-1 )
	{
		QMessageBox::warning(NULL,"Warning!","Your QMPlib version is too old!\n"+QMPVer);
		return 0;
	}

	Qmp *qmp = (Qmp*) QMPLIB.resolve("qmp");
	if (!qmp)
	{
		QMessageBox::warning(NULL,"Warning!","File: "+QMPLib+libExt+" is not correct library for QMPlay"+QMPVer+"!");
		return 0;
	}

	if ( ( opcja == "--new" || opcja == "-N" ) && argc > 2 )
	{
		qmp->main( qApp->arguments(), qmp, QMPConf, QsignalE, QMPfiles );
		return qApp->exec();
	}

	if ( qmpExitSIGSEGVorABORT() && argc < 2 )
	{
		qmp->main( QStringList() << qApp->arguments()[ 0 ] << "-np", qmp, QMPConf, QsignalE, QMPfiles );
		return qApp->exec();
	}

	qmp->main( qApp->arguments(), qmp, QMPConf, QsignalE, QMPfiles );
	return qApp->exec();
}
