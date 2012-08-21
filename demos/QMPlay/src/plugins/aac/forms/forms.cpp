#include "formAac.cpp"
#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
}

FormAac::FormAac(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(&timref, SIGNAL(timeout()), this, SLOT(timRefDo()));
	connect(ui.closeButton, SIGNAL(clicked()), this , SLOT(zamknij()));
	connect(ui.id3B, SIGNAL(clicked()), this , SLOT(editId3()));
}
