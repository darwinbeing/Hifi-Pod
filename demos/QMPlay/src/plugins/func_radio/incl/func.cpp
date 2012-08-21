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
	pixmap = QPixmap( ":/radio.png" );
}

void Init()
{
	QMPConf = QLib->getFileName( QMP_CONF );
	ff.Init();
}

void closePlug()
{
	listaThr.doExit();
	ff.setParent(NULL);
	ff.close();
}

void about(QWidget *w)
{
	QMessageBox::information(w,"QMPlay","Radio Browser");
}

void setLang( QString langfile )
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QMPlay_radio_browser/" + QString::number(i) ).toString();

	ff.ui.createList->setText( QMPset->value( "QMPlay_radio_browser_Window/0" ).toString() );

	delete QMPset;
}
