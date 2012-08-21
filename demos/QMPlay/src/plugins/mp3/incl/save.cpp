void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	fosW = QMPset->value( "MP3Set/fosW" ).toInt();
	fosH = QMPset->value( "MP3Set/fosH" ).toInt();

	curF = QMPset->value( "MP3Set/curF" ).toString();

	savsek = QMPset->value( "MP3Set/seek" ).toInt();

	Enabled = QMPset->value( "MP3Set/Enabled", true ).toBool();

	notReadID3 = QMPset->value( "MP3Set/notReadID3", false ).toBool();

	formatSupport = QMPset->value( "MP3Set/formatSupport", "mp3;mp2" ).toString();

	searchParts = QMPset->value( "MP3Set/searchParts", true ).toBool();
	wait4Data = QMPset->value( "MP3Set/wait4Data", true ).toBool();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "MP3Set/fosW", fosW );
	QMPset->setValue( "MP3Set/fosH", fosH );

	QMPset->setValue( "MP3Set/curF", curF );

	QMPset->setValue( "MP3Set/Enabled", Enabled );

	QMPset->setValue( "MP3Set/notReadID3", notReadID3 );

	QMPset->setValue( "MP3Set/seek", savsek );

	QMPset->setValue( "MP3Set/formatSupport", formatSupport );

	QMPset->setValue( "MP3Set/searchParts", searchParts );
	QMPset->setValue( "MP3Set/wait4Data", wait4Data );

	QMPset->sync();
	delete QMPset;
}
