void Save::odczytajopcje()
{
#ifndef Q_OS_LINUX
	fs.ui.autoSurroundB->close();
#endif
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "PAset/Enabled", true ).toBool();

#ifdef Q_OS_MAC
	lB = lNB = 0.05;
#else
	if ( QLib->getCpuSpeed() < 500 )
		lB = lNB = 0.30;
	else
		lB = lNB = 0.15;
#endif
	lB = QMPset->value( "PAset/latency", lB ).toDouble();
	lNB = QMPset->value( "PAset/latencyN", lNB ).toDouble();

	devIndexPA = QMPset->value( "PAset/devIndexPA", -1 ).toInt();
	devIndexNPA = QMPset->value( "PAset/devIndexNPA", -1 ).toInt();
	devIndex = QMPset->value( "PAset/devIndex", -1 ).toInt();
	devIndexN = QMPset->value( "PAset/devIndexN", -1 ).toInt();
	dN  = QMPset->value( "PAset/dN" ).toString();
	dNN = QMPset->value( "PAset/dNN" ).toString();
	zB = QMPset->value( "PAset/zB", true ).toBool();
#ifdef Q_OS_LINUX
	autoSurround = QMPset->value( "PAset/autoSurround", true ).toBool();
#endif

	delete QMPset;

	if ( devIndexPA < 0 && devIndexNPA < 0 && Enabled )
		fs.defDev();

}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "PAset/Enabled", Enabled );
	QMPset->setValue( "PAset/devIndexPA", devIndexPA );
	QMPset->setValue( "PAset/latency", lB );
	QMPset->setValue( "PAset/devIndexNPA", devIndexNPA );
	QMPset->setValue( "PAset/latencyN", lNB );
	QMPset->setValue( "PAset/devIndex", devIndex );
	QMPset->setValue( "PAset/devIndexN", devIndexN );
	QMPset->setValue( "PAset/dN", dN );
	QMPset->setValue( "PAset/dNN", dNN );
	QMPset->setValue( "PAset/zB", zB );
#ifdef Q_OS_LINUX
	QMPset->setValue( "PAset/autoSurround", autoSurround );
#endif

	QMPset->sync();
	delete QMPset;
}
