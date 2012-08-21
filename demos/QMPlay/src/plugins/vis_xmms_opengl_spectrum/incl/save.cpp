void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "VisXOS/Enabled", false ).toBool();
	isON = QMPset->value( "VisXOS/isON", false ).toBool();
	okno = QMPset->value( "VisXOS/okno", true ).toBool();
	timRefValue = QMPset->value( "VisXOS/timRefValue", 15 ).toInt();

	VisX = QMPset->value( "VisXOS/X", -1 ).toInt();
	VisY = QMPset->value( "VisXOS/Y", -1 ).toInt();
	VisW = QMPset->value( "VisXOS/W", 400 ).toInt();
	VisH = QMPset->value( "VisXOS/H", 300 ).toInt();

	if ( QMPset->value( "VisXOS/inDock" ).toBool() )
		Enabled = false;

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "VisXOS/Enabled", Enabled );
	QMPset->setValue( "VisXOS/isON", isON );
	QMPset->setValue( "VisXOS/okno", okno );
	QMPset->setValue( "VisXOS/timRefValue", timRefValue );

	QMPset->setValue( "VisXOS/X", VisX );
	QMPset->setValue( "VisXOS/Y", VisY );
	QMPset->setValue( "VisXOS/W", VisW );
	QMPset->setValue( "VisXOS/H", VisH );

	QMPset->setValue( "VisXOS/inDock", inDock );

	QMPset->sync();
	delete QMPset;
}
