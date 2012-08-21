#include "formMMSlider.cpp"
#include "formSplIns.cpp"
#include "formSetup.cpp"
#include "formMod.cpp"

FormMod::FormMod(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.closeButton, SIGNAL(clicked()), this , SLOT(zamknij()));
	connect(ui.musicPos, SIGNAL(sliderReleased()), this, SLOT(slR()));
	connect(ui.musicPos, SIGNAL(sliderPressed()), this, SLOT(slP()));
	connect(ui.bpmBox, SIGNAL(valueChanged(int)), this, SLOT(bpmup()));
	connect(ui.spdBox, SIGNAL(valueChanged(int)), this, SLOT(spdup()));
	connect(ui.sampleButton, SIGNAL(clicked()), this, SLOT(shwsplins()));
	connect(&timref, SIGNAL(timeout()), this, SLOT(timRefDo()));
}

FormSplIns::FormSplIns(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(zamknij()));
}

FormMMSlider::FormMMSlider(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
}

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.ApplyButton, SIGNAL(clicked()), this, SLOT(ApplyB()));
	connect(ui.panSlider, SIGNAL(valueChanged(int)), this, SLOT(pseplabel()));
	connect(ui.revSlider, SIGNAL(valueChanged(int)), this, SLOT(revlabel()));
	connect(ui.volSlider, SIGNAL(valueChanged(int)), this, SLOT(vollabel()));
	connect(ui.dExtB, SIGNAL(clicked()), this, SLOT(dExtB()));
	connect(&setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()));
}
