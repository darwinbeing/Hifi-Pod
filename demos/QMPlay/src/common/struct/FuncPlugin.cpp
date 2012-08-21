#include"PluginInfo.h"
struct Qmp;
struct FuncPlugin
{
	struct PluginInfo *pluginInfo;
	void (*opcje)(QWidget*);
	void (*closePlug)();
	void (*Init)();
	void (*show)(QWidget*);
	bool (*hOptions);
	bool (*hFuncWin);
	void (*setLang)(QString);
	void (*setSize)(QSize);
	void (*setQmpLib)(Qmp*);
};
