#include "formSetup.cpp"
#include "formMod2.cpp"
#include "formMod.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.volS, SIGNAL( valueChanged(int) ), this, SLOT( setVol() ) );
	connect(&setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()));
}

FormMod::FormMod(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.closeButton, SIGNAL(clicked()), this , SLOT(zamknij()));
	connect(&timref, SIGNAL(timeout()), this, SLOT(timRefDo()));
}

FormMod2::FormMod2(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
}
