#include "formFunc.cpp"

Form1::Form1(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.recB, SIGNAL( clicked() ), this, SLOT( rec() ) );
	connect( ui.stopB, SIGNAL( clicked() ), this, SLOT( Stop() ) );
	connect( ui.pauseB, SIGNAL( clicked() ), this, SLOT( pauseB() ) );
	connect( ui.sndB, SIGNAL( clicked() ), this, SLOT( sndB() ) );
	connect( &timer, SIGNAL(timeout()), this, SLOT(timerF()) );
	connect( &timRef, SIGNAL(timeout()), this, SLOT(timRefF()) );
}
