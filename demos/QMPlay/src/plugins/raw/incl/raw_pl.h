#include "save.h"

void WAVUpdate();
void Init();
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void WAVUpdate2();

#include "InputPlugin.cpp"

#include "raw_pl.cpp"

const char *plugName("RAW (Input)");

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
	&MUSerr,
	&endSong,
	&mustReset,
	&pauseD,
	&NumPos,
	&SongPos,
	seek,
	togglePause,
	Init,
	NULL,
	&pltime,
	&plMaxtime,
	NULL,
	clrPos,
	&title,
	&hOptions,
	&getBR,
	NULL,
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
