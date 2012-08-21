void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "QEffResample/Enabled", true ).toBool();
	autoFactor = QMPset->value( "QEffResample/autoFactor", true ).toBool();
	factor = QMPset->value( "QEffResample/factor", 1. ).toDouble();
	HQ = QMPset->value( "QEffResample/HQ", false ).toBool();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QEffResample/Enabled", Enabled );
	QMPset->setValue( "QEffResample/autoFactor", autoFactor );
	QMPset->setValue( "QEffResample/factor", factor );
	QMPset->setValue( "QEffResample/HQ", HQ );

	QMPset->sync();
	delete QMPset;
}
