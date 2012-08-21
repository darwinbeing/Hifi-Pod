#include "save.h"

void AACUpdate();
void Init();
void seek(int&);
void clrSet();
void clrPos();
void savPos();
void AACUpdate2(long);

#include "InputPlugin.cpp"

const char *plugName("AAC (Input)");

#include "ID3.cpp"
#include "internet_stream_info.cpp"
#include "AAC.cpp"

AACFile *fil = NULL;

void getMusInfo( AACFile *, QString *, QString *, QString * );

#include "aac_pl.cpp"

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
	NULL,
	&canUpdateEntry,
	InternetFormatSupport,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	getMusStr
};
