#include <Functions.cpp>

void opcje(QWidget*)
{
}

void setSize( QSize s )
{
	QRect g;
	g.setX(0);
	g.setY(0);
	g.setHeight(s.height());
	g.setWidth(s.width());
	ff.setGeometry(g);
}

void Show(QWidget *w)
{
	if(w)
	{
		w->setMinimumSize( ff.minimumSize() );
		w->setMaximumSize( ff.maximumSize() );
		tmpWidget = w;
	}
	ff.setParent(tmpWidget);
	ff.move(0,0);
	ff.show();
}

void getOutLib(Qmp *_QLib)
{
	QLib = _QLib;
}

void Init()
{
	QMPConf = QLib->getFileName( QMP_CONF );
	ff.Init();
}

void closePlug()
{
	ff.breakThr();
	ff.abortAll();
	ff.clrB();
	ff.setParent(NULL);
	ff.close();
}

void about(QWidget *w)
{
	QMessageBox::information(w,"QMPlay","Music Browser");
}

void setLang( QString langfile )
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QMusicBrowserFunc/" + QString::number(i) ).toString();

	ff.ui.searchB->setText( Texts[ 22 ] /*Szukaj*/ );

	ff.ui.dwnPB->setText( QMPset->value( "QMusicBrowserFuncWindow/1" ).toString() );
	ff.ui.clrB->setText( QMPset->value( "QMusicBrowserFuncWindow/2" ).toString() );
	ff.ui.playB->setText( QMPset->value( "QMusicBrowserFuncWindow/3" ).toString() );
	ff.ui.downloadB->setText( QMPset->value( "QMusicBrowserFuncWindow/4" ).toString() );
	ff.ui.titlesW->horizontalHeaderItem(0)->setText( QMPset->value( "QMusicBrowserFuncWindow/5" ).toString() );
	ff.ui.titlesW->horizontalHeaderItem(1)->setText( QMPset->value( "QMusicBrowserFuncWindow/6" ).toString() );
	ff.ui.titlesW->horizontalHeaderItem(2)->setText( QMPset->value( "QMusicBrowserFuncWindow/7" ).toString() );
	ff.ui.titlesW->horizontalHeaderItem(3)->setText( QMPset->value( "QMusicBrowserFuncWindow/8" ).toString() );

	delete QMPset;
}
