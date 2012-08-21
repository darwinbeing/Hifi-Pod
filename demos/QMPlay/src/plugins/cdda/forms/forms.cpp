#include "formInfo.cpp"
#include "formSetup.cpp"

FormInfo::FormInfo(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.closeButton, SIGNAL( clicked() ), this, SLOT( zamknij() ) );
	connect( &timRef, SIGNAL( timeout() ), this, SLOT( timRefDo() ) );
}

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.trackB, SIGNAL( clicked() ), this, SLOT( addCD() ) );
	connect(&setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()));
	connect( ui.ejectB, SIGNAL( clicked() ), this, SLOT( eject() ) );
	connect( ui.closeTB, SIGNAL( clicked() ), this, SLOT( closeTB() ) );
	connect( ui.driveB, SIGNAL( currentIndexChanged(int) ), this, SLOT( setDrive() ) );
	connect( ui.useCDDBB, SIGNAL( clicked() ), this, SLOT( CHKENABLED() ) );
	connect( ui.useUserDatabaseB, SIGNAL( clicked() ), this, SLOT( CHKENABLED() ) );
	connect( ui.useFDBB, SIGNAL( clicked() ), this, SLOT( CHKENABLED() ) );
	connect( ui.driveE, SIGNAL( textEdited( QString ) ), this, SLOT( driveE( QString ) ) );
}
