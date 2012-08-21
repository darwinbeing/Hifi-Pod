#ifndef FUNC_H
#define FUNC_H

#include "FuncPlugin.cpp"

const char *plugName("Radio Browser (Func)");
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
	Show,
	&hOptions,
	&hFuncWin,
	setLang,
	setSize,
	getOutLib
};

#endif
