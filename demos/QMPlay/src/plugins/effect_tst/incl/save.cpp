void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "QEff1/Enabled", false ).toBool();
	effEcho = QMPset->value( "QEff1/effEcho", false ).toBool();
	effVoice = QMPset->value( "QEff1/effVoice", false ).toBool();
	effSkip = QMPset->value( "QEff1/effSkip", false ).toBool();
	effSzybko = QMPset->value( "QEff1/effSzybko", false ).toBool();
	effWolno = QMPset->value( "QEff1/effWolno", false).toBool();

	voice = QMPset->value( "QEff1/voice", true ).toBool();
	echoSurround = QMPset->value( "QEff1/echoSurround", false ).toBool();

	p1s = QMPset->value( "QEff1/p1s", 28 ).toInt();
	p2s = QMPset->value( "QEff1/p2s", 25 ).toInt();

	echo_delay = QMPset->value( "QEff1/echo_delay", 500 ).toInt();
	echo_feedback = QMPset->value( "QEff1/echo_feedback", 50 ).toInt();
	echo_volume = QMPset->value( "QEff1/echo_volume", 50 ).toInt();

	effInvert = QMPset->value( "QEff1/effInvert", false ).toInt();

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QEff1/Enabled", Enabled );
	QMPset->setValue( "QEff1/effEcho", effEcho );
	QMPset->setValue( "QEff1/effVoice", effVoice );
	QMPset->setValue( "QEff1/effSkip", effSkip );
	QMPset->setValue( "QEff1/effSzybko", effSzybko );
	QMPset->setValue( "QEff1/effWolno", effWolno );

	QMPset->setValue( "QEff1/voice", voice );
	QMPset->setValue( "QEff1/echoSurround", echoSurround );

	QMPset->setValue( "QEff1/p1s", p1s );
	QMPset->setValue( "QEff1/p2s", p2s );

	QMPset->setValue( "QEff1/echo_delay", echo_delay );
	QMPset->setValue( "QEff1/echo_feedback", echo_feedback );
	QMPset->setValue( "QEff1/echo_volume", echo_volume );

	QMPset->setValue( "QEff1/effInvert", effInvert );

	QMPset->sync();
	delete QMPset;
}
