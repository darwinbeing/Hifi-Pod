enum getPar
{
	QMP_MAIN, QMP_PLAYLIST, QMP_SETUP, QMP_FUNC, QMP_ABOUT, QMP_MAIN_OR_PLIST, QMP_MINI
};
enum ChkLoad
{
	QMP_LOADED, QMP_PLUGINS_LOADED
};
enum FileName
{
	QMP_CONF, OS_LIBEXT, OS_PPN, QMP_INTERNET
};
enum ChkState
{
	IS_PLAYING
};
enum QMP_INFO
{
	QMP_NRPLAY, QMP_CURRITEMSEL
};
enum QMP_FILEDIALOG
{
	OPEN_FILE, OPEN_FILES, SAVE_FILE, OPEN_DIR
};
enum QMP_GETICON
{
	PLAY_ICON, STOP_ICON, NXT_ICON, PREV_ICON, PAUSE_ICON, REC_ICON
};
enum QMP_STRINGOPERATIONS
{
	PLIK_BEZ_SCIEZKI, SCIEZKA_DO_PLIKU
};

struct VisPlugin;
struct QMPOut;
struct Qmp
{
	void    (*main)(const QStringList &,Qmp*,QString,QString,QString);
	void    (*control)(char,int);
	void    (*getVol)(int*);
	void    (*setVol)(int*);
	void    (*getWindowFrame)(int*,int*);
	void    (*addToPlayList)(QStringList,int);
	void    (*lastOnList)();
	void    (*getPlistEntry)(QStringList*);
	QString (*getSupportedExts)();
	void    (*showMessage)(QString,QString,int,int,bool);
	void    (*updateCurrPlistEntry)(QString);
	QWidget*(*getParent)( getPar );
	bool    (*chkLoad)( ChkLoad );
	QString (*getFileName)( FileName );
	void    (*addToLog)( QString );
	bool    (*chkState)(ChkState);
	QSize   (*getOkienkoSize)();
	void    (*showMessageAct)(QString,QString,int,int,bool,void(*)());
	QMPOut *(*getOutLib)();
	void    (*dock)(QWidget*,bool,void(*)());
	QWidget*(*inDock)();
	void    (*MiniQmp)(bool,QPoint,int);
	uint    QMPVer;
	QString (*currPath)(QString*);
	QString (*getPlugFNameForName)(const char *);
	int     (*getInfo)(QMP_INFO);
	int     (*getCpuSpeed)();
	QList<VisPlugin*> (*getVPluginsList)();
	bool    (*open)(QString);
	QStringList (*fileDialog)(QMP_FILEDIALOG, QWidget *, QString, QString, QString, QString *);
	QIcon   (*getIcon)(QMP_GETICON);
	QString (*getFSize)( long long );
	QString (*stringOperations)( QMP_STRINGOPERATIONS, QString );
};
