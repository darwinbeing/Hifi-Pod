void Save::odczytajopcje()
{
	Vis->setMinimumSize( 10, 10 );

	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "Vis1/Enabled", true ).toBool();
	okno = QMPset->value( "Vis1/okno", true ).toBool();
	tims = QMPset->value( "Vis1/tims", 10 ).toInt();
	timRefValue = QMPset->value( "Vis1/timRefValue", 25 ).toInt();

	lpB = QMPset->value( "Vis1/lpB", true ).toBool();
	sB = QMPset->value( "Vis1/sB", true ).toBool();
	sngTB = QMPset->value( "Vis1/sngTB", false ).toBool();

	kreski = QMPset->value( "Vis1/kreski", true ).toBool();
	paski = QMPset->value( "Vis1/paski", true ).toBool();
	kolor2 = QMPset->value( "Vis1/kolor2", true ).toBool();

	VisX = QMPset->value( "Vis1/X", -1 ).toInt();
	VisY = QMPset->value( "Vis1/Y", -1 ).toInt();
	VisW = QMPset->value( "Vis1/W", -1 ).toInt();
	VisH = QMPset->value( "Vis1/H", -1 ).toInt();

	fs.ui.autoFillBackgroundB->setChecked( QMPset->value( "Vis1/autoFillBackgroundB", true ).toBool() );

	if ( QMPset->value( "Vis1/inDock" ).toBool() )
		Enabled = false;

	delete QMPset;

	if ( VisW < 1 )
		VisW = 400;
	if ( VisH < 1 )
		VisH = 300;
	if ( VisX < 0 )
		VisX = qdw.width()/2 - Vis->width()/2;
	if ( VisY < 0 )
		VisY = qdw.height()/2 - Vis->height()/2;

	Vis->setGeometry(VisX,VisY,VisW,VisH);
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "Vis1/Enabled", Enabled );
	QMPset->setValue( "Vis1/okno", okno );
	QMPset->setValue( "Vis1/tims",  tims );
	QMPset->setValue( "Vis1/timRefValue",  timRefValue );

	QMPset->setValue( "Vis1/lpB", lpB );
	QMPset->setValue( "Vis1/sB", sB );
	QMPset->setValue( "Vis1/sngTB", sngTB );

	QMPset->setValue( "Vis1/kreski", kreski );
	QMPset->setValue( "Vis1/paski", paski );
	QMPset->setValue( "Vis1/kolor2", kolor2 );

	QMPset->setValue( "Vis1/X", VisX );
	QMPset->setValue( "Vis1/Y", VisY );
	QMPset->setValue( "Vis1/W", VisW );
	QMPset->setValue( "Vis1/H", VisH );

	QMPset->setValue( "Vis1/autoFillBackgroundB", fs.ui.autoFillBackgroundB->isChecked() );

	QMPset->setValue( "Vis1/inDock", inDock );

	QMPset->sync( );
	delete QMPset;
}
