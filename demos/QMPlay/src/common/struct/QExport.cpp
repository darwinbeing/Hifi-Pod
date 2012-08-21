#include"PluginInfo.h"
struct Qmp;
struct QMP_Export
{
	struct PluginInfo *pluginInfo;
	QString (*mnu);
	void (*closePlug)(bool);
	void (*Init)(bool, int, int, int, QString);
	void (*play)(char*,int);
	bool (*PlErr);
	QString (*errStr);
	bool (*hOptions);
	void (*opcje)(QWidget*);
	void (*setLang)(QString);
	void (*setQmpLib)(Qmp*);
};
