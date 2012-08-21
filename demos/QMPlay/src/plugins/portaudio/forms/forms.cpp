#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.ApplyDB, SIGNAL( clicked() ), this, SLOT( ApplyDB() ) );
	connect( ui.detectB, SIGNAL( clicked() ), this, SLOT( detectB() ) );
	connect( ui.defDevB, SIGNAL( clicked() ), this, SLOT( defDev() ) );
}
