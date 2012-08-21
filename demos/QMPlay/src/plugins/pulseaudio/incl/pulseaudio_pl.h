#include "save.h"

#include "OutputPlugin.cpp"

#include "pulseaudio_pl.cpp"

PluginInfo pluginInfo =
{
	"PulseAudio (output)",
	"OutputPlugin",
	1521-1,
	1.0,
	about,
	SwOnOff,
	NULL,
	NULL,
	NULL
};

OutputPlugin Oplug =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	play,
	&PlErr,
	setVol,
	getVol,
	&hOptions,
	isRec,
	initRec,
	rec,
	&mustReset,
	&errStr,
	NULL,
	getQLib,
};
