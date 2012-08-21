#include "QMPlay_tag_editor.h"

const char *plugName("QMPlay tag editor");
QPixmap pixmap = QPixmap( ":/id3.png" );

#include "func.cpp"

Tag_editor tag_editor =
{
	openWindow,
	getData,
	&pixmap
};

#include "FuncPlugin.cpp"

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
	setLang,
	NULL,
	getOutLib
};
