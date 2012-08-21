enum QOutControl
{
	QOUT_MUST_STOP, QOUT_STOP_AND_WAIT, QOUT_MUST_PAUSE, QOUT_FLUSH, QOUT_NEXT_READ, QOUT_CLOSE_EXPORTFILE, QOUT_SILENCE, QOUT_PAUSE_OTHER
};

struct OutputPlugin;
struct VisPlugin;
struct QMP_effects;
struct QMP_Export;
struct QMP_effects;
struct Qmp;

struct AudioInfo
{
	AudioInfo( int a, char b, char c, QString d = "" )
	{
		srate = a;
		bits = b;
		chn = c;
		bitsStr = d;
	}
	int srate;
	char bits;
	char chn;
	QString bitsStr;
};

struct QMPOut
{
	uint QMPVer;
	void (*opcje)(QWidget*);
	void (*Init)( AudioInfo, bool, int *, QString, QString );
	void (*Play)( void *, int, int, int );
	bool (*PlErr);
	void (*setOPlug)(QList<OutputPlugin*>,QMP_Export*);
	void (*setEffects)(QList<QMP_effects*>,QMP_effects*);
	void (*setVis)(QList<VisPlugin*>);
	int  (*getVolume);
	void (*setVol)(int,int);
	void (*getVol)(int*,int*);
	bool (*close)();
	bool (*startExport)(bool);
	bool (*bothVolB)(bool);
	bool (*busy);
	int  (*pltime); //czas odtwarzania
	QString (*title);
	void (*setLang)(QString);
	QString (*musParam);
	bool (*isRec)();
	void (*initRec)();
	void (*rec)(char*,int,bool);
	bool (*mustReset);
	void (*clrEff)();
	void (*control)(QOutControl);
	bool (*mustStop);
	void (*setQmpLib)(Qmp*);
	bool (*pause2);
	bool (*setExport);
	void (*setStopFunction)( void(*)() );
	void (*useQMPBuffer)();
};
