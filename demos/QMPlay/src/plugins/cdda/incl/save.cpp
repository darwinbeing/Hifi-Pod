bool getServer( QString p, QString &name, unsigned short &port )
{
	if ( p.length() < 3 )
		return false;
	QStringList pL = p.split(":", QString::SkipEmptyParts);
	if ( pL.count() != 2 )
		return false;
	name = pL[0];
	port = pL[1].toInt();
	return true;
}

void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	useProxy = QMPset->value( "QMPInternet/useProxy", false ).toBool();
	if ( useProxy )
		useProxy = getServer( QMPset->value( "QMPInternet/proxy" ).toString(), proxyAddr, proxyPort );

	fisW = QMPset->value( "CDAudio/fisW" ).toInt();
	fisH = QMPset->value( "CDAudio/fisH" ).toInt();

	fs.ui.canCloseTB->setChecked( QMPset->value( "CDAudio/canCloseTB", false ).toBool() );

	curF = QMPset->value( "CDAudio/curF" ).toString();

	savsek = QMPset->value( "CDAudio/seek" ).toInt();
	Enabled = QMPset->value( "CDAudio/Enabled", true ).toBool();
	speed = QMPset->value( "CDAudio/speed", 1 ).toInt();
	clrB = QMPset->value( "CDAudio/clrB", true ).toBool();

	currCD = QMPset->value( "CDAudio/currCD" ).toString();
	if ( currCD.isEmpty() )
		loadFirst = true;

	useDefaultCacheDir = QMPset->value( "CDAudio/useDefaultCacheDir", true ).toBool();
	useCDDB = QMPset->value( "CDAudio/useCDDB", true ).toBool();

	useUserDatabase = QMPset->value( "CDAudio/useUserDatabase", false ).toBool();
	useFDB = QMPset->value( "CDAudio/useFDB", true ).toBool();
	useCddbp = QMPset->value( "CDAudio/useCddbp", false).toBool();
	userDatabaseServer = QMPset->value( "CDAudio/userDatabaseServer" ).toString();

	readCDTXT = QMPset->value( "CDAudio/readCDTXT", true ).toBool();

	if ( !useUserDatabase && !useFDB )
		useFDB = true;

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "CDAudio/fisW", fisW );
	QMPset->setValue( "CDAudio/fisH", fisH );

	QMPset->setValue( "CDAudio/canCloseTB", fs.ui.canCloseTB->isChecked() );

	QMPset->setValue( "CDAudio/curF", curF );

	QMPset->setValue( "CDAudio/seek", savsek );
	QMPset->setValue( "CDAudio/Enabled", Enabled );
	QMPset->setValue( "CDAudio/speed", speed );
	QMPset->setValue( "CDAudio/clrB", clrB );

	QMPset->setValue( "CDAudio/currCD", currCD );

	QMPset->setValue( "CDAudio/useDefaultCacheDir", useDefaultCacheDir );
	QMPset->setValue( "CDAudio/useCDDB", useCDDB );

	QMPset->setValue( "CDAudio/useUserDatabase", useUserDatabase );
	QMPset->setValue( "CDAudio/useFDB", useFDB );
	QMPset->setValue( "CDAudio/useCddbp", useCddbp );
	QMPset->setValue( "CDAudio/userDatabaseServer", userDatabaseServer );

	QMPset->setValue( "CDAudio/readCDTXT", readCDTXT );

	delete QMPset;
}
