void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	sL = QMPset->value( "QMPOut/sL", 100 ).toInt();
	sR = QMPset->value( "QMPOut/sR", 100 ).toInt();

	aL = QMPset->value( "QMPOut/aL" ).toInt();
	aR = QMPset->value( "QMPOut/aR" ).toInt();

	setOPlugVolume();

	bB = QMPset->value( "QMPOut/bB", true ).toBool();
	useAppVol = QMPset->value( "QMPOut/useAppVol", true ).toBool();
	visEff = QMPset->value( "QMPOut/visEff", true ).toBool();
	savEff = QMPset->value( "QMPOut/savEff", false ).toBool();
	toOplugS = QMPset->value( "QMPOut/toOplugS", true ).toBool();
	toOplugEx = QMPset->value( "QMPOut/toOplugEx", false ).toBool();
	chChnB = QMPset->value( "QMPOut/chChnB", false ).toBool();
	bEff = QMPset->value( "QMPOut/bEff", false ).toBool();
	zChnB = QMPset->value( "QMPOut/zChnB", false ).toBool();
	chChn2B = QMPset->value( "QMPOut/chChn2B", false ).toBool();
	titleE = QMPset->value( "QMPOut/titleE", true ).toBool();

	userBits = QMPset->value( "QMPOut/userBits", true ).toBool();
	userRate = QMPset->value( "QMPOut/userRate", false ).toBool();
	userChn = QMPset->value( "QMPOut/userChn", false ).toBool();
	UserBits = QMPset->value( "QMPOut/_UserBits", 16 ).toInt();
	UserRate = QMPset->value( "QMPOut/_UserRate", 44100 ).toInt();
	UserChn = QMPset->value( "QMPOut/_UserChn", 2 ).toInt();

	silenceB = QMPset->value( "QMPOut/silenceB", true ).toBool();

	BufQ = QMPset->value( "QMPOut/BufQ", true ).toBool();
	QBuf = QMPset->value( "QMPOut/QBuf", 16 ).toInt();
	soundB = QMPset->value( "QMPOut/soundB", true ).toInt();

	buffQIfNeaded = QMPset->value( "QMPOut/buffQIfNeaded", false ).toBool();

	_priority = QMPset->value( "QMPOut/_priority", 2 ).toInt();

	titleB = QMPset->value( "QMPOut/titleB", false ).toBool();
	titleHB = QMPset->value( "QMPOut/titleHB", true ).toBool();

	delete QMPset;
}

void Save::zapiszVol()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QMPOut/sL", sL );
	QMPset->setValue( "QMPOut/sR", sR );

	QMPset->setValue( "QMPOut/aL", aL );
	QMPset->setValue( "QMPOut/aR", aR );

	QMPset->setValue( "QMPOut/bB", bB );

	QMPset->sync();
	delete QMPset;
}

void Save::zapiszBb()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QMPOut/bEff", bEff );

	QMPset->sync();
	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QMPOut/bEff", bEff );

	QMPset->setValue( "QMPOut/sL", sL );
	QMPset->setValue( "QMPOut/sR", sR );

	QMPset->setValue( "QMPOut/aL", aL );
	QMPset->setValue( "QMPOut/aR", aR );

	QMPset->setValue( "QMPOut/useAppVol", useAppVol );
	QMPset->setValue( "QMPOut/visEff", visEff );
	QMPset->setValue( "QMPOut/savEff", savEff );
	QMPset->setValue( "QMPOut/toOplugS", toOplugS );
	QMPset->setValue( "QMPOut/toOplugEx", toOplugEx );
	QMPset->setValue( "QMPOut/chChnB", chChnB );
	QMPset->setValue( "QMPOut/bEff", bEff );
	QMPset->setValue( "QMPOut/zChnB", zChnB );
	QMPset->setValue( "QMPOut/chChn2B", chChn2B );
	QMPset->setValue( "QMPOut/titleE", titleE );

	QMPset->setValue( "QMPOut/_priority", _priority );

	QMPset->setValue( "QMPOut/userBits", userBits );
	QMPset->setValue( "QMPOut/userRate", userRate );
	QMPset->setValue( "QMPOut/userChn", userChn );
	QMPset->setValue( "QMPOut/_UserBits", UserBits );
	QMPset->setValue( "QMPOut/_UserRate", UserRate );
	QMPset->setValue( "QMPOut/_UserChn", UserChn );

	QMPset->setValue( "QMPOut/silenceB", silenceB );

	QMPset->setValue( "QMPOut/BufQ", BufQ );
	QMPset->setValue( "QMPOut/QBuf", QBuf );
	QMPset->setValue( "QMPOut/soundB", soundB );
	QMPset->setValue( "QMPOut/buffQIfNeaded", buffQIfNeaded );

	QMPset->setValue( "QMPOut/titleB", titleB );
	QMPset->setValue( "QMPOut/titleHB", titleHB );

	QMPset->sync();
	delete QMPset;
}
