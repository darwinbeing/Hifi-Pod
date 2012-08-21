#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.playSB, SIGNAL( clicked() ), this, SLOT( playSB() ) );
	connect( ui.sL, SIGNAL( valueChanged(int) ), this, SLOT( setVol(int) ) );
	connect( ui.sR, SIGNAL( valueChanged(int) ), this, SLOT( setVol(int) ) );
	connect( ui.bB, SIGNAL( clicked() ), this, SLOT( bBset() ) );
	//strona druga
	connect( ui.userRateB, SIGNAL( clicked() ), this, SLOT( userRateB() ) );
	connect( ui.userBitsB, SIGNAL( clicked() ), this, SLOT( userBitsB() ) );
	connect( ui.userChnB, SIGNAL( clicked() ), this, SLOT( userChnB() ) );
	connect( ui.buffQB, SIGNAL( clicked() ), this, SLOT( _buffQB() ) );
	connect( ui.titleB, SIGNAL( clicked() ), this, SLOT( _titleHB() ) );
	connect( this, SIGNAL( bufferSizeUpdated(QString,QString,int) ), this, SLOT( updateBufferSize(QString,QString,int) ) );
}
