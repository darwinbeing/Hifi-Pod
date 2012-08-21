#include "save.h"

#include "VisPlugin.cpp"

#include "xmms_vis.cpp"
#include "vis.cpp"

const char *plugName("XMMS OpenGL Spectrum");

QWidget *canDock(bool b)
{
	if (b)
	{
		if ( Enabled )
		{
			if ( !okienko )
				Vis->savWinGeometry();
			else
			{
				Vis->odlacz();
				okienkoParent = NULL;
			}
		}
		else
		{
			fs.ui.enabledB->setChecked(true);
			dockEnable = true;
			fs.ApplyB();
			dockEnable = false;
		}
	}
	return Vis;
}
void unDock()
{
	Vis->setGeometry(VisX,VisY,VisW,VisH);
	if ( !noShow )
		Vis->show();
	noShow = false;
}

PluginInfo pluginInfo =
{
	plugName,
	"VisPlugin",
	1506-1,
	1.0,
	about,
	SwOnOff,
	canDock,
	unDock,
	NULL

};

VisPlugin Vplug =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	Do,
	clear,
	show,
	&okno,
	&hOptions,
	NULL,
	getQLib
};
