#include "save.h"

void clrSet();

#include "InputPlugin.cpp"

const char *plugName("Sound Generator (Input)");

#include "gen_pl.cpp"

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
	Show,
	clrPos,
	&title,
	&hOptions,
	&getBR,
	setFormInfo,
	getMenu,
	NULL,
	getQmpLib,
	showOptions,
	&canUpdateEntry,
	NULL,
	NULL,
	getMusInfo,
	NULL,
	NULL
};
