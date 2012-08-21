void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "AOset/Enabled", true ).toBool();
	drvid = QMPset->value( "AOset/drvid", -2 ).toInt();

	delete QMPset;

	if ( drvid == -2 )
	{
		ao_initialize();
		drvid = ao_default_driver_id();
	}
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "AOset/Enabled", Enabled );
	QMPset->setValue( "AOset/drvid", drvid );

	QMPset->sync();
	delete QMPset;
}
