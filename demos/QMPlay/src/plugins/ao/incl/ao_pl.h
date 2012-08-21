#include "save.h"

#include "OutputPlugin.cpp"

#include "ao_pl.cpp"

PluginInfo pluginInfo =
{
	"AO (output)",
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
	NULL,
	NULL,
	NULL,
	&mustReset,
	&errStr,
	NULL,
	getQLib,
};
