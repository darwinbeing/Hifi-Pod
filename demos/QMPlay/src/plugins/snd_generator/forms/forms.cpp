#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( ui.addB, SIGNAL( clicked() ), this, SLOT( addB() ) );
	connect( ui.hzB, SIGNAL( valueChanged(int) ), this, SLOT( hz_1() ) );
	connect( ui.hzB_2, SIGNAL( valueChanged(int) ), this, SLOT( hz_2() ) );
	connect( ui.hzB_3, SIGNAL( valueChanged(int) ), this, SLOT( hz_3() ) );
	connect( ui.hzB_4, SIGNAL( valueChanged(int) ), this, SLOT( hz_4() ) );
	connect( ui.hzB_5, SIGNAL( valueChanged(int) ), this, SLOT( hz_5() ) );
	connect( ui.hzB_6, SIGNAL( valueChanged(int) ), this, SLOT( hz_6() ) );
	connect( ui.hzB_7, SIGNAL( valueChanged(int) ), this, SLOT( hz_7() ) );
	connect( ui.hzB_8, SIGNAL( valueChanged(int) ), this, SLOT( hz_8() ) );
	connect( &setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()) );
}
