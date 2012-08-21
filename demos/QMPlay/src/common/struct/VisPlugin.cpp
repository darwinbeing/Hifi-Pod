#include"PluginInfo.h"
struct Qmp;
struct VisPlugin
{
	struct PluginInfo *pluginInfo;
	void (*opcje)(QWidget *);
	void (*closePlug)();
	void (*Init)();
	void (*Do)(int *,int,int,int,int,QString,int,QString);
	void (*clear)();
	void (*show)(QWidget *,bool);
	bool (*okno);
	bool (*hOptions);
	void (*setLang)(QString);
	void (*setQmpLib)(Qmp *);
};
