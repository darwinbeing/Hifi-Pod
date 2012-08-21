#ifndef FUNC_H
#define FUNC_H

#include "save.h"

#include "FuncPlugin.cpp"

const char *plugName("Recording (Func)");
QPixmap pixmap;

#include "func.cpp"

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
	&pixmap
};

FuncPlugin Fplug =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	show,
	&hOptions,
	&hFuncWin,
	NULL,
	NULL,
	getOutLib
};

#endif
