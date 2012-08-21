#include "save.h"

void WAVUpdate(SF_INFO);
void Init();
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void WAVUpdate2();

#include "InputPlugin.cpp"

#include "QMPlay_tag_editor.cpp"

#include "sndfile_pl.cpp"

const char *plugName("Sndfile (Input)");

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
	NULL,
	NULL,
	getQmpLib,
	showOptions,
	NULL,
	NULL,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	getMusStr
};
