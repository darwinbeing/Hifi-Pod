void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	curF = QMPset->value( "MPSet/curF" ).toString();

	savsek = QMPset->value( "MPset/seek" ).toInt();

	Enabled = QMPset->value( "MPset/Enabled", true ).toBool();

	formatSupport = QMPset->value( "MPset/formatSupport", "669;amf;ams;dbm;dmf;dsm;far;it;j2b;mdl;med;mod;mt2;mtm;okt;psm;ptm;s3m;stm;ult;umx;xm" ).toString();

	vol = QMPset->value( "MPset/vol", 255 ).toInt();
	chn = QMPset->value( "MPset/chn", 2 ).toInt();
	rate = QMPset->value( "MPset/rate", 44100 ).toInt();
	bits = QMPset->value( "MPset/bits", 16 ).toInt();
	loop = QMPset->value( "MPset/loop", false ).toBool();
	Oversampling = QMPset->value( "MPset/Oversampling", true ).toBool();
	NoiseR = QMPset->value( "MPset/NoiseR", false ).toBool();
	Resampling = QMPset->value( "MPset/Resampling", true ).toInt();

	showTime = QMPset->value( "MPset/showTime" ).toBool();
	bass = QMPset->value( "MPset/bass" ).toBool();
	reverb = QMPset->value( "MPset/reverb" ).toBool();
	surround = QMPset->value( "MPset/surround" ).toBool();

	bass1 = QMPset->value( "MPset/bass1", 50 ).toInt();
	bass2 = QMPset->value( "MPset/bass2", 50 ).toInt();
	reverb1 = QMPset->value( "MPset/reverb1", 50 ).toInt();
	reverb2 = QMPset->value( "MPset/reverb2", 100 ).toInt();
	surround1 = QMPset->value( "MPset/surround1", 50 ).toInt();
	surround2 = QMPset->value( "MPset/surround2", 30 ).toInt();

	fmsW = QMPset->value( "MPset/fmsW", fm->width() ).toInt();
	fmsH = QMPset->value( "MPset/fmsH", fm->height() ).toInt();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "MPset/curF", curF );

	QMPset->setValue( "MPset/seek", savsek );

	QMPset->setValue( "MPset/Enabled", Enabled );

	QMPset->setValue( "MPset/formatSupport", formatSupport );

	QMPset->setValue( "MPset/vol", vol );
	QMPset->setValue( "MPset/chn", chn );
	QMPset->setValue( "MPset/rate", rate );
	QMPset->setValue( "MPset/bits", bits );
	QMPset->setValue( "MPset/loop", loop );
	QMPset->setValue( "MPset/Oversampling", Oversampling );
	QMPset->setValue( "MPset/NoiseR", NoiseR );
	QMPset->setValue( "MPset/Resampling", Resampling );

	QMPset->setValue( "MPset/showTime", showTime );
	QMPset->setValue( "MPset/bass", bass );
	QMPset->setValue( "MPset/reverb", reverb );
	QMPset->setValue( "MPset/surround", surround );

	QMPset->setValue( "MPset/bass1", bass1 );
	QMPset->setValue( "MPset/bass2", bass2 );
	QMPset->setValue( "MPset/reverb1", reverb1 );
	QMPset->setValue( "MPset/reverb2", reverb2 );
	QMPset->setValue( "MPset/surround1", surround1 );
	QMPset->setValue( "MPset/surround2", surround2 );

	QMPset->setValue( "MPset/fmsW", fmsW );
	QMPset->setValue( "MPset/fmsH", fmsH );

	QMPset->sync();
	delete QMPset;
}
