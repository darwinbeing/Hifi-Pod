#include"PluginInfo.h"
struct Qmp;
struct OutputPlugin
{
	struct PluginInfo *pluginInfo;
	void (*opcje)(QWidget*);
	void (*closePlug)(bool);
	void (*Init)(bool, int, int, int, int);
	void (*play)(char*,int,bool);
	bool (*PlErr);
	void (*setVol)(int,int);
	void (*getVol)(int*,int*);
	bool (*hOptions);
	bool (*isRec)();
	void (*initRec)();
	void (*rec)(char*,int,bool);
	bool (*mustReset);
	QString (*errStr);
	void (*setLang)(QString);
	void (*setQmpLib)(Qmp*);
};
