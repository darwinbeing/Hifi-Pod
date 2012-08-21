#include "formOgg.cpp"
#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
}

FormOgg::FormOgg(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(&timref, SIGNAL(timeout()), this, SLOT(timRefDo()));
	connect(ui.closeButton, SIGNAL(clicked()), this , SLOT(zamknij()));
	connect(ui.tagB, SIGNAL(clicked()), this , SLOT(editTag()));
}
