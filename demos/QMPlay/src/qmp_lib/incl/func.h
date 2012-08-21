#ifndef FUNC_H
#define FUNC_H

struct Func
{
	QString timeFormat1();
	void loadmus();
	InputPlugin *getMusicFormat(QString, QString);
	QString plikbezsciezki(QString);
	QString sciezkadopliku(QString);
	void loadPlugins(bool);
	void searchPlugins(bool);
	bool checkFormat(QString,QString);
	QString timeFormat(int,bool);
	QString getExt(QString);
	QString getExt(QString,bool);
	void CURP(QString);
	int nr();
	void getVol();
	void unloadPlugins(int);
	QString checkInternetFormat( QString );
	QString getFSize( long long );
	bool isPlayListExt(QString);
	QString getPlistExts( bool singleLine = true );
	QString getFNamePlugin( QString file, bool );
	QString getTypePlugin( QString );
	QString getExts(bool);
	void showPlugLoadErr();
	void PlugLoadErr( QString, QString );
	void PlugLoadErr( QString );
	QWidget *addScrollArea( void (*)(QWidget*), QString );
	void addToList( QStringList &, int, QStringList );
	void unloadAllPlugins();
	bool chkFNr( int X );
	QString getFromPlugInfo( QString, QPixmap &, InputPlugin * );
	int getCpuSpeed();
	bool chkQMPlayVer( struct PluginInfo *, QString );
	bool open( QString );
	QStringList fileDialog( QMP_FILEDIALOG, QWidget *, QString, QString, QString filter = QString(), QString *selectedFilter = NULL );
	void chkFileFormat( QStringList &, bool * );
	bool chkProtocols( QString );
	void getLanguage();
} Func;

#include "otherClasses.cpp"

#include "func.cpp"

#endif
