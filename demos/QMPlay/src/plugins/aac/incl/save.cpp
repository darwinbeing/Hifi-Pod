void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	fosW = QMPset->value( "AACSet/fosW", fo->width() ).toInt();
	fosH = QMPset->value( "AACSet/fosH", fo->height() ).toInt();

	curF = QMPset->value( "AACSet/curF" ).toString();

	savsek = QMPset->value( "AACSet/seek" ).toInt();
	Enabled = QMPset->value( "AACSet/Enabled", true ).toBool();

	formatSupport = QMPset->value( "AACSet/formatSupport", "aac" ).toString();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "AACSet/fosW", fosW );
	QMPset->setValue( "AACSet/fosH", fosH );

	QMPset->setValue( "AACSet/curF", curF );

	QMPset->setValue( "AACSet/seek", savsek );

	QMPset->setValue( "AACSet/Enabled", Enabled );

	QMPset->setValue( "AACSet/formatSupport", formatSupport );

	QMPset->sync();
	delete QMPset;
}
