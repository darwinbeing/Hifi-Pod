void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "OpenALset/Enabled", true ).toBool();
	NUM_BUFFERS = QMPset->value( "OpenALset/NUM_BUFFERS", 8 ).toInt();
	onlyMultiChn = QMPset->value( "OpenALset/onlyMultiChn", false ).toBool();
	devName = QMPset->value( "OpenALset/devName" ).toString();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "OpenALset/Enabled", Enabled );
	QMPset->setValue( "OpenALset/NUM_BUFFERS", NUM_BUFFERS );
	QMPset->setValue( "OpenALset/onlyMultiChn", onlyMultiChn );
	QMPset->setValue( "OpenALset/devName", devName );

	QMPset->sync();
	delete QMPset;
}
