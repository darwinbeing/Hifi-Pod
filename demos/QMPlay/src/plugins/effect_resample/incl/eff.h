#include "save.h"

#include "QLib.cpp"
#include "EffectPlugin.cpp"

#include "eff.cpp"

const char *plugName("Resample plugin (Effect)");

PluginInfo pluginInfo =
{
	plugName,
	"EffectPlugin",
	1516-1,
	1.0,
	about,
	SwOnOff,
	NULL,
	NULL,
	NULL
};

QMP_effects Eplug =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	Do,
	closeEff,
	&hOptions,
	NULL,
	getQLib,
	NULL
};
