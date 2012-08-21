#include"PluginInfo.h"
struct PlaylistPlugin
{
	struct PluginInfo *pluginInfo;
	void (*setQmpLib)(Qmp *);
	bool (*load)( QString, QStringList *, QStringList *, bool );
	bool (*save)( QString, QString, const QStringList * );
	bool (*create)( QString &, QString );
	QString (*getExts)();
};
