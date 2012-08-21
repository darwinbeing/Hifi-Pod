#include "save.h"

bool MP3Update();
void Init();
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void MP3Update2(long);

#include "InputPlugin.cpp"

const char *plugName("MP3 (Input)");

#include "internet_stream_info.cpp"

bool getMusInfo( mpg123_handle *, long *, int *, QString *, QString *, QString *, int, const char * );

#include "mp3_pl.cpp"

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
	&canUpdateEntry,
	InternetFormatSupport,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	getMusStr
};
