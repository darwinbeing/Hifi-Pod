#include "QExport.cpp"

#include "func.cpp"
void closePlug(bool);
#include "wav_pl.cpp"

QString mnustr("wav / raw");

PluginInfo pluginInfo =
{
	"",
	"",
	1528-1,
	1.0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

QMP_Export Explug =
{
	&pluginInfo,
	&mnustr,
	closePlug,
	Init,
	play,
	&PlErr,
	&errStr,
	&hOptions,
	opcje,
	setLang,
	getQmpLib,
};
