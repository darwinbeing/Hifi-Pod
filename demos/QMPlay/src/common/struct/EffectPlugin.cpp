#include"PluginInfo.h"
struct Qmp;
struct QMP_effects
{
	struct PluginInfo *pluginInfo;
	void (*opcje)(QWidget*);
	void (*closePlug)();
	void (*Init)();
	void (*Do)(int **,int&,int,int,int,int);
	void (*closeEff)();
	bool (*hOptions);
	void (*setLang)(QString);
	void (*setQmpLib)(Qmp*);
	bool (*showOptions)(bool);
};
