void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	pth = QMPset->value( "FuncMusicBrowser/pth", QDir::homePath() ).toString();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "FuncMusicBrowser/pth", pth );
	QMPset->remove( "FuncMusicBrowser/page" );

	QMPset->sync();
	delete QMPset;
}
