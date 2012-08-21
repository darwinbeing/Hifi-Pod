void opcje(QWidget*)
{
}

void show(QWidget *w)
{
	w->setMinimumSize( f1.minimumSize() );
	w->setMaximumSize( f1.maximumSize() );
	f1.setParent(w);
	f1.move(0,0);
	f1.show();
}

void getOutLib( Qmp *QLib )
{
	QMPConf = QLib->getFileName( QMP_CONF );
	QOut = QLib->getOutLib();

	static bool once = false;
	if ( !once )
	{
		once = true;
		pixmap = QLib->getIcon( REC_ICON ).pixmap( 32, 32 );
		f1.ui.recB->setIcon( QLib->getIcon( REC_ICON ) );
		f1.ui.pauseB->setIcon( QLib->getIcon( PAUSE_ICON ) );
		f1.ui.stopB->setIcon( QLib->getIcon( STOP_ICON ) );
	}
}

void Init()
{
	Save.odczytajopcje();
	f1.Init();
}

#include "thread.h"

void closePlug()
{
	recthr.doExit();
	Save.zapiszopcje();
	f1.setParent(NULL);
	f1.close();
}

extern "C" void about(QWidget* w)
{
	QMessageBox::information(w,"QMPlay","Recording function");
}
