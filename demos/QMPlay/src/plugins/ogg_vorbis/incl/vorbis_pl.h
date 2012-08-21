#include "save.h"

void OGGUpdate();
void Init();
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void OGGUpdate2(long);

QPixmap pm;

#include "InputPlugin.cpp"

const char *plugName("OGG Vorbis (Input)");

#include "internet_stream_info.cpp"

#include "QMPlay_tag_editor.cpp"

#include "vorbis_pl.cpp"

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
	&pm
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
	getQLib,
	NULL,
	&canUpdateEntry,
	InternetFormatSupport,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	getMusStr
};
