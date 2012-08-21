void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "PulseAudioSet/Enabled", true ).toBool();
	delay = QMPset->value( "PulseAudioSet/delay", 0.1 ).toDouble();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "PulseAudioSet/Enabled", Enabled );
	QMPset->setValue( "PulseAudioSet/delay", delay );

	QMPset->sync();
	delete QMPset;
}
