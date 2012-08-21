#include "save.h"

void MMUpdate();
void Init(QString);
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void MMUpdate2();
QString getInstr();

#include "InputPlugin.cpp"
#include "mikmod_pl.cpp"

const char *plugName("MikMod (Input)");

PluginInfo pluginInfo =
{
	plugName,
 	"InputPlugin",
 	1529-1,
	1.0,
	about,
	SwOnOff,
	NULL,
	NULL,
	NULL
};

InputPlugin Iplug =
{
	&pluginInfo,
	&formatSupport,
	opcje,
	play,
	closePlug,
	&MODerr,
	&endSong,
	&mustReset,
	&pauseD,
	&NumPos,
	&SongPos,
	seek,
	togglePause,
	Init,
	plugSpec,
	&pltime,
	&plMaxtime,
	Show,
	clrPos,
	&title,
	&hOptions,
	&getBR,
	setFormInfo,
	NULL,
	NULL,
	getQmpLib,
	showOptions,
	NULL,
	NULL,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	NULL
};
