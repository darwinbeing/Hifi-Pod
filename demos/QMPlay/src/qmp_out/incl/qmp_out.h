#include "QOut.cpp"

bool startExport(bool);
bool closeOut();
#include "qmp_out.cpp"

QMPOut QMPout =
{
	1516-1,
	opcje,
	Init,
	Play,
	&PlErr,
	setOPlug,
	setEffects,
	setVis,
	Volume,
	setVol,
	getVol,
	closeOut,
	startExport,
	&bothVolB,
	busy,
	&pltime,
	&title,
	setLang,
	musParam,
	isRec,
	initRec,
	rec,
	&mustReset,
	clrEff,
	control,
	&mustStop,
	getQmpLib,
	&pause2,
	&setExport,
	setStopFunction,
	useQMPBuffer
};
