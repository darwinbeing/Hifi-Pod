#ifndef __THREAD_H__
#define __THREAD_H__

#include <QThread>

struct plthr : public QThread
{
	void run();
	bool doExit();
	void setType();
	void clr();
	QString path;
	int type;
} plthr;

struct plistthr : public QThread
{
	plistthr()
	{
		notRunning = true;
	}
	void run();
	void doExit();
	int fileCount, beginIndex, currIndex;
	bool stop, runTitles;
	int tcr;
	QChar plus;
	bool notRunning;
} plistthr;

struct cpthr : public QThread
{
	void run();
	void doExit();
	QString selfile,fName,fPth;
	bool c,br;
	int X,count,val,Count, serror;
} cpthr;

struct addthr : public QThread
{
	addthr()
	{
		fromDnD = false;
	}
	void run();
	void doExit();
	bool br,scat, added, fromDnD;
	QStringList pths, DIRlist;
} addthr;

struct downloadThr : public QThread
{
	private:
		bool bolBr;
	public:
		bool finished,error;
		int pC, dwn, spd;
		QString path, addr, errStr;
		void doExit();
		void run();
} downloadThr;

struct chkUpdatesThr : public QThread
{
	chkUpdatesThr()
	{
		checkVers = false;
		once = true;
		clr();
		connect( this, SIGNAL( finished() ), &f1, SLOT( checkUpdates() ) );
	}
	void clr();
	void run();

	bool once, checkVers;
	int updates;
	uint Ver;
	QStringList QMPlay_addr_and_file;
} chkUpdatesThr;

#include "thread.cpp"

#endif
