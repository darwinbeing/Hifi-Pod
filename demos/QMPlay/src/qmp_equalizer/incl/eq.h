#include "save.h"

#include "EffectPlugin.cpp"

#include "eq.cpp"

bool _swB( bool b )
{
	if (b)
	{
		fs.ui.swB->setChecked( !fs.ui.swB->isChecked() );
		fs.swB();
	}
	return fs.ui.swB->isChecked();
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	Enabled = !Enabled;
	fs.ui.enabledB->setChecked(Enabled);
	fs.enabledB();
	return 0;
}

QWidget *canDock(bool b)
{
	if (b)
	{
		if ( !inSW && !sw )
			eqgeo = fs.geometry();
		inSW = false;
		fs.ui.swB->setShortcut( QKeySequence() );
		fs.ui.swB->setChecked(true);
	}
	return &fs;
}
void unDock()
{
	if ( !noShow )
		fs.showOpcje();
	noShow = false;
}

PluginInfo pluginInfo =
{
	"",
	"",
	1516-1,
	1.0,
	NULL,
	SwOnOff,
	canDock,
	unDock,
	NULL
};

QMP_effects QMP_equalizer =
{
	&pluginInfo,
	opcje,
	closePlug,
	Init,
	Do,
	closeEff,
	&hOptions,
	setLang,
	getQmpLib,
	_swB
};
