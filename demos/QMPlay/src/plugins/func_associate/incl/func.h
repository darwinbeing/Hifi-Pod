#ifndef FUNC_H
#define FUNC_H

#include "save.h"

#include "FuncPlugin.cpp"

#include "func.cpp"

const char *plugName("Associate (Func)");

PluginInfo pluginInfo =
{
	plugName,
	"FuncPlugin",
	1528-1,
	1.0,
	about,
	NULL,
	NULL,
	NULL,
	NULL
};

FuncPlugin Fplug =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	Show,
	&hOptions,
	&hFuncWin,
	setLang,
	setSize,
	getOutLib
};

#endif
