#ifndef PlugInfo_h
#define PlugInfo_h

#include <QPixmap>

struct PluginInfo
{
	const char *Name, *Type;
	uint QMPVer;
	float ver;
	void (*About)(QWidget*);
	bool (*swOnOff)(bool);
	QWidget *(*canDock)(bool);
	void (*unDock)();
	QPixmap (*pixmap);
};

#endif
