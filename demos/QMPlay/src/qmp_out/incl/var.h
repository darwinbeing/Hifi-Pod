#include <QSettings>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QFileDialog>
#include <QTime>
#include <QDate>
#include <QThread>
#include <QQueue>

#include <Functions.cpp>

QStringList Texts;
const int langCount = 10;

#include "QLib.cpp"
Qmp *QLib = NULL;

#include "OutputPlugin.cpp"
#include "EffectPlugin.cpp"
#include "VisPlugin.cpp"
#include "QExport.cpp"

QList< VisPlugin * > Vplugins;
QList< QMP_effects * > Eplugins;
QList< OutputPlugin * > Oplugins;

OutputPlugin* Oplug = NULL;

QMP_effects *equalizer = NULL;
QMP_Export *wave = NULL;

QSettings *QMPset = NULL;
QString QMPConf;

bool mustStop(0), nextRead(0), mustPause(0), StP(0), pause2(0), playSoundNow;

int _priority(1);

struct GlobalBuff
{
	GlobalBuff( int size )
	{
		audio_buffer = new int[ size ];
		rest = 0;
	}
	~GlobalBuff()
	{
		delete[] audio_buffer;
	}
	int *audio_buffer;
	int rest;
};
GlobalBuff *globalBuff1 = NULL, *globalBuff2 = NULL;

int silenceTime = 300;

bool setExport(0), notCloseExportFile(0);
QString title,fName,oldTitle;
bool titleB(0), titleHB(1);
int pltime, aL(100),aR(100);
bool REC(0), zChnB, mustReset(0);
bool PlErr, initLang(0), closeD(1);
bool busy[2];
int Volume[2];
bool bFloat(0);
int bits, chn, rate, FRAME_SIZE;
bool WAVExport;
float LV(1.0f);
float RV(1.0f);
int sL(100), sR(100);
bool bB;
bool useAppVol;
bool visEff, savEff;
bool toOplug, toOplugS, toOplugEx;
bool chChnB, bEff, chChn2B;
bool titleE(0);
QString musParam[4];

bool BufQ(true), _BufQ(true), buffQIfNeaded(false);
bool forceUseQMPBuffer(false);
int QBuf(4), soundB(1), _QBuf(4);
bool lastPlErr(0);
bool doSilence(0), silenceB(0), doVolUp(0), doDoVolUp(1);
float dz(1.), dzUp(50.), timeVUp(0.);

bool userBits, userRate, userChn;
int  realBits, realChn, realRate;
int  UserBits, UserChn, UserRate;
