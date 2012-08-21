void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "SND_GENSet/Enabled", true ).toBool();

	Hz = QMPset->value( "SND_GENSet/Hz", 440 ).toInt();
	Hz2 = QMPset->value( "SND_GENSet/Hz2", 440 ).toInt();
	Hz3 = QMPset->value( "SND_GENSet/Hz3", 440 ).toInt();
	Hz4 = QMPset->value( "SND_GENSet/Hz4", 440 ).toInt();
	Hz5 = QMPset->value( "SND_GENSet/Hz5", 440 ).toInt();
	Hz6 = QMPset->value( "SND_GENSet/Hz6", 440 ).toInt();
	Hz7 = QMPset->value( "SND_GENSet/Hz7", 440 ).toInt();
	Hz8 = QMPset->value( "SND_GENSet/Hz8", 440 ).toInt();

	_chn = QMPset->value( "SND_GENSet/chn", 1 ).toInt();
	_srate = QMPset->value( "SND_GENSet/srate", 44100 ).toInt();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "SND_GENSet/Enabled", Enabled );

	QMPset->setValue( "SND_GENSet/Hz", Hz );
	QMPset->setValue( "SND_GENSet/Hz2", Hz2 );
	QMPset->setValue( "SND_GENSet/Hz3", Hz3 );
	QMPset->setValue( "SND_GENSet/Hz4", Hz4 );
	QMPset->setValue( "SND_GENSet/Hz5", Hz5 );
	QMPset->setValue( "SND_GENSet/Hz6", Hz6 );
	QMPset->setValue( "SND_GENSet/Hz7", Hz7 );
	QMPset->setValue( "SND_GENSet/Hz8", Hz8 );

	QMPset->setValue( "SND_GENSet/chn", _chn );
	QMPset->setValue( "SND_GENSet/srate", _srate );

	QMPset->sync();
	delete QMPset;
}
