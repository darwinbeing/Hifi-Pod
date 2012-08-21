#include "formMp3.cpp"
#include "formSetup.cpp"

FormMp3::FormMp3(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect(&timref, SIGNAL(timeout()), this, SLOT(timRefDo()));
	connect(ui.closeButton, SIGNAL(clicked()), this , SLOT(zamknij()));
	connect(ui.id3B, SIGNAL(clicked()), this , SLOT(editId3()));
}

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
	connect( &setupTimer, SIGNAL(timeout()), this, SLOT(FsetupTimer()) );
}
