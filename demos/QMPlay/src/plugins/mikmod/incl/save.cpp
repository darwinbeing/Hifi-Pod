void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	fmsW = QMPset->value( "MMset/fmsW", fm->width() ).toInt();
	fmsH = QMPset->value( "MMset/fmsH", fm->height() ).toInt();

	fsiposX = QMPset->value( "MMset/fsiposX", -1 ).toInt();
	fsiposY = QMPset->value( "MMset/fsiposY", -1 ).toInt();
	fsisW = QMPset->value( "MMset/fsisW", fsi.width() ).toInt();
	fsisH = QMPset->value( "MMset/fsisH", fsi.height() ).toInt();

	mdmixfreq = QMPset->value( "MMset/mdmixfreq", 44100 ).toInt();
	interp = QMPset->value( "MMset/interp", true ).toBool();
	hqmixer = QMPset->value( "MMset/hqmixer", true ).toBool();
	surround = QMPset->value( "MMset/surround", true ).toBool();
	bits16 = QMPset->value( "MMset/bits16", true ).toBool();
	stereo = QMPset->value( "MMset/stereo" ).toBool();
	reverse = QMPset->value( "MMset/reverse" ).toBool();
	softmusic = QMPset->value( "MMset/softmusic" ).toBool();
	softsndfx = QMPset->value( "MMset/softsndfx" ).toBool();
	fadeout = QMPset->value( "MMset/fadeout" ).toBool();
	loop = QMPset->value( "MMset/loop" ).toBool();
	pansep = QMPset->value( "MMset/pansep", 128 ).toInt();
	reverb = QMPset->value( "MMset/reverb" ).toInt();
	mdvolume = QMPset->value( "MMset/mdvolume", 128 ).toInt();
	chnMAX = QMPset->value( "MMset/chnMAX", 64 ).toInt();

	curF = QMPset->value( "MMset/curF" ).toString();

	timRefValue = QMPset->value( "MMset/timRefValue", 30 ).toInt();

	savsek = QMPset->value( "MMset/seek" ).toInt();
	savbpm = QMPset->value( "MMset/bpm" ).toInt();
	savspd = QMPset->value( "MMset/spd" ).toInt();

	formatSupport = QMPset->value( "MMset/formatSupport", "669;amf;dsm;far;gdm;imf;med;m15;mtm;okt;s3m;stm;stx;ult;uni;mod;it;xm" ).toString();
	Enabled = QMPset->value( "MMset/Enabled", true ).toBool();

	delete QMPset;

	if ( timRefValue < 5 || timRefValue > 999 )
		timRefValue = 30;

	if ( fsiposX < 0 )
		fsiposX = qdw.width()/2 - fsi.width()/2;
	if ( fsiposY < 0 )
		fsiposY = qdw.height()/2 - fsi.height()/2;
	if ( fsisW < 1 )
		fsisW = fsi.width();
	if ( fsisH < 1 )
		fsisH =  fsi.height();

	if ( mdmixfreq < 8000 )
		mdmixfreq = 44100;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "MMset/fmsW", fmsW );
	QMPset->setValue( "MMset/fmsH", fmsH );

	QMPset->setValue( "MMset/fsiposX", fsiposX );
	QMPset->setValue( "MMset/fsiposY", fsiposY );
	QMPset->setValue( "MMset/fsisW", fsisW );
	QMPset->setValue( "MMset/fsisH", fsisH );

	QMPset->setValue( "MMset/mdmixfreq", mdmixfreq );
	QMPset->setValue( "MMset/pansep", pansep );
	QMPset->setValue( "MMset/interp", interp );
	QMPset->setValue( "MMset/hqmixer", hqmixer );
	QMPset->setValue( "MMset/surround", surround );
	QMPset->setValue( "MMset/bits16", bits16 );
	QMPset->setValue( "MMset/stereo", stereo );
	QMPset->setValue( "MMset/reverse", reverse );
	QMPset->setValue( "MMset/softmusic", softmusic );
	QMPset->setValue( "MMset/softsndfx", softsndfx );
	QMPset->setValue( "MMset/fadeout", fadeout );
	QMPset->setValue( "MMset/loop", loop );
	QMPset->setValue( "MMset/pansep", pansep );
	QMPset->setValue( "MMset/reverb", reverb );
	QMPset->setValue( "MMset/mdvolume", mdvolume );
	QMPset->setValue( "MMset/chnMAX", chnMAX );

	QMPset->setValue( "MMset/curF", curF );

	QMPset->setValue( "MMset/seek", savsek );
	QMPset->setValue( "MMset/bpm", savbpm );
	QMPset->setValue( "MMset/spd", savspd );
	QMPset->setValue( "MMset/timRefValue", timRefValue );

	QMPset->setValue( "MMset/formatSupport", formatSupport );
	QMPset->setValue( "MMset/Enabled", Enabled );

	QMPset->sync();
	delete QMPset;
}
