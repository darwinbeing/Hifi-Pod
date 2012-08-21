#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.e1s, SIGNAL( valueChanged(int) ), this, SLOT( slidersEcho() ) );
	connect( ui.e2s, SIGNAL( valueChanged(int) ), this, SLOT( slidersEcho() ) );
	connect( ui.e3s, SIGNAL( valueChanged(int) ), this, SLOT( slidersEcho() ) );
}
