void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	curF = QMPset->value( "SndfileSet/curF" ).toString();

	savsek = QMPset->value( "SndfileSet/seek" ).toInt();
	Enabled = QMPset->value( "SndfileSet/Enabled", true ).toBool();

	formatSupport = QMPset->value( "SndfileSet/formatSupport", "wav;aif;aiff;flac" ).toString();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "SndfileSet/curF", curF );

	QMPset->setValue( "SndfileSet/seek", savsek);
	QMPset->setValue( "SndfileSet/Enabled", Enabled);

	QMPset->setValue( "SndfileSet/formatSupport", formatSupport );

	QMPset->sync();
	delete QMPset;
}
