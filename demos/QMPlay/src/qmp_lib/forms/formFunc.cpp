void FormFunc::Init()
{
	f1.ui.dodatkiB->setChecked( true );
	ff.setGeometry( ffGeo );
}

void FormFunc::closeEvent(QCloseEvent*)
{
	f1.ui.dodatkiB->setChecked( false );
	ffGeo = geometry();
}

void FormFunc::setGeo()
{
	if ( ui.tabWidget->currentIndex() < 0 )
		return;
	int W = ui.tabWidget->widget( ui.tabWidget->currentIndex() )->objectName().toInt();
	if ( W < 0 || W > Fplugins.count()-1 )
		return;
	if ( Fplugins[W]->setSize )
	{
		QSize s;
		s.setWidth ( ui.tabWidget->widget( ui.tabWidget->currentIndex() )->geometry().width()  );
		s.setHeight( ui.tabWidget->widget( ui.tabWidget->currentIndex() )->geometry().height() );
		Fplugins[W]->setSize( s );
	}
}

void FormFunc::tabCH( int )
{
	setGeo();
}

void FormFunc::showEvent( QShowEvent* )
{
	setGeo();
}

void FormFunc::resizeEvent( QResizeEvent* )
{
	setGeo();
}
