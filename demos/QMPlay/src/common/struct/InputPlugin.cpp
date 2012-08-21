#include"PluginInfo.h"
struct Qmp;
struct InputPlugin
{
	struct PluginInfo *pluginInfo;
	QString (*formatSupport);
	void (*opcje)(QWidget*);
	void (*play)(const char*,int);
	void (*closePlug)(bool,bool);
	bool (*PlugErr);
	bool (*isEndSong);
	bool (*mustReset);
	bool (*pauseD);
	int  (*NumPos); //max na slider
	int  (*SongPos); //pozycja slidera
	void (*seek)(int&);
	void (*togglePause)();
	void (*Init)(bool,int);
	void (*plugSpec)(QWidget*, bool);
	int  (*pltime); //czas odtwarzania
	int  (*plMaxtime); //czas muzyki
	QWidget *(*Show)(QWidget*);
	void (*clrPos)();
	QString (*title);
	bool (*hOptions);
	QString (*getBR);
	void (*setFormInfo)(int*); //[0] - szer, [1] - wys ; jeżeli NULL to okno się zamknie
	void (*getMenu)(QAction**);
	void (*setLang)(QString);
	void (*setQmpLib)(Qmp*);
	void (*showOptions)();
	bool (*canUpdateEntry); /* from here, pointers can be NULL */
	QString (*InternetFormatSupport)( const char* );
	bool (*FileFormatSupport)( const char* );
	void (*getMusInfo)( const char *fileE, uint type, int *time, QString *title );
	void (*infoWindow)(QWidget *w, const char *fileE, int type);
	QString (*getMusStr)(const char*, int, QPixmap&);
};
