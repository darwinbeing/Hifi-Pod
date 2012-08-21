void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	rate = QMPset->value( "FuncRecord/rate", 48000 ).toInt();
	bits = QMPset->value( "FuncRecord/bits", 16 ).toInt();
	chn = QMPset->value( "FuncRecord/chn", true ).toInt();
	snd = QMPset->value( "FuncRecord/snd", true ).toInt();
	sav = QMPset->value( "FuncRecord/sav", false ).toBool();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "FuncRecord/rate", rate );
	QMPset->setValue( "FuncRecord/bits", bits );
	QMPset->setValue( "FuncRecord/chn", chn );
	QMPset->setValue( "FuncRecord/snd", snd );
	QMPset->setValue( "FuncRecord/sav", sav );

	QMPset->sync();
	delete QMPset;
}
