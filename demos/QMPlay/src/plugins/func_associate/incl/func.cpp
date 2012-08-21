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
	f1.setGeometry(g);
}

void Show(QWidget *w)
{
	if(w)
	{
		w->setMinimumSize( f1.minimumSize() );
		w->setMaximumSize( f1.maximumSize() );
		tmpWidget = w;
	}
	f1.setParent(tmpWidget);
	f1.move(0,0);
	f1.show();
}

void getOutLib(Qmp *_QLib)
{
	QLib = _QLib;
}

void Init()
{
	QMPConf = QLib->getFileName( QMP_CONF );
	libExt = QLib->getFileName( OS_LIBEXT );
	f1.Init();
}

void closePlug()
{
	f1.setParent(NULL);
	f1.close();
}

void about(QWidget *w)
{
	QMessageBox::information(w,"QMPlay","Associate with QMP!");
}

void setLang( QString langfile )
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QAssociate/" + QString::number(i) ).toString();

	f1.ui.onRunB->setText( QMPset->value( "QAssociateWindow/0" ).toString() );
	f1.ui.selAllB->setText( QMPset->value( "QAssociateWindow/1" ).toString() );
	f1.ui.revSelB->setText( QMPset->value( "QAssociateWindow/2" ).toString() );
	f1.ui.addB->setText( QMPset->value( "QAssociateWindow/3" ).toString() );
	f1.ui.delB->setText( QMPset->value( "QAssociateWindow/4" ).toString() );
	f1.ui.getExtsB->setText( QMPset->value( "QAssociateWindow/5" ).toString() );
	f1.ui.clrB->setText( QMPset->value( "QAssociateWindow/6" ).toString() );
	f1.ui.applyB->setText( QMPset->value( "QAssociateWindow/7" ).toString() );
	f1.ui.extsList->setWhatsThis( QMPset->value( "QAssociateWindow/8" ).toString() );
	f1.ui.extsE->setToolTip( QMPset->value( "QAssociateWindow/9" ).toString() );

	delete QMPset;
}
