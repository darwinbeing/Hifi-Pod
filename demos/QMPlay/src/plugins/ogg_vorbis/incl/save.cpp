void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	fosW = QMPset->value( "VorbisSet/fosW", fo->width() ).toInt();
	fosH = QMPset->value( "VorbisSet/fosH", fo->height() ).toInt();

	curF = QMPset->value( "VorbisSet/curF" ).toString();

	savsek = QMPset->value( "VorbisSet/seek" ).toInt();
	Enabled = QMPset->value( "VorbisSet/Enabled", true ).toBool();

	formatSupport = QMPset->value( "VorbisSet/formatSupport", "ogg" ).toString();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "VorbisSet/fosW", fosW );
	QMPset->setValue( "VorbisSet/fosH", fosH );

	QMPset->setValue( "VorbisSet/curF",curF );

	QMPset->setValue( "VorbisSet/seek", savsek );

	QMPset->setValue( "VorbisSet/Enabled", Enabled );

	QMPset->setValue( "VorbisSet/formatSupport", formatSupport );

	QMPset->sync();
	delete QMPset;
}
