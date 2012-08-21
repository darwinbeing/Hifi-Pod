#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect(&setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()));
}
