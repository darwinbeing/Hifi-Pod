void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	curF = QMPset->value( "RAWSet/curF" ).toString();

	savsek = QMPset->value( "RAWSet/seek" ).toInt();
	Enabled = QMPset->value( "RAWSet/Enabled", true ).toBool();

	srateB = QMPset->value( "RAWSet/srateB", 44100 ).toInt();
	chnB = QMPset->value( "RAWSet/chnB", 2 ).toInt();
	u8B = QMPset->value( "RAWSet/u8B", false ).toBool();
	BITS = QMPset->value( "RAWSet/BITS", 16 ).toInt();
	be = QMPset->value( "RAWSet/be", false ).toBool();
	skipB = QMPset->value( "RAWSet/skipB", false ).toInt();

	formatSupport = QMPset->value( "RAWSet/formatSupport", "pcm;raw" ).toString();

	delete QMPset;

	if ( BITS < 8 || BITS > 33 )
		BITS = 16;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "RAWSet/curF", curF );

	QMPset->setValue( "RAWSet/seek", savsek );
	QMPset->setValue( "RAWSet/Enabled", Enabled );

	QMPset->setValue( "RAWSet/srateB", srateB );
	QMPset->setValue( "RAWSet/chnB", chnB );
	QMPset->setValue( "RAWSet/u8B", u8B );
	QMPset->setValue( "RAWSet/BITS", BITS );
	QMPset->setValue( "RAWSet/be", be );

	QMPset->setValue( "RAWSet/skipB", skipB);

	QMPset->setValue( "RAWSet/formatSupport", formatSupport );

	QMPset->sync();
	delete QMPset;
}
