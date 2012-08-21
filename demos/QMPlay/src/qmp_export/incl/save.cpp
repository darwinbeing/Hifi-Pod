void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	raw = QMPset->value( "QMPExport/raw", false ).toBool();
	sch = QMPset->value( "QMPExport/sch", false ).toBool();
	fPth = QMPset->value( "QMPExport/fPth", QDir::homePath() ).toString();

	delete QMPset;

	if ( fPth.right( 1 ) != "/" )
		fPth += "/";
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QMPExport/raw", raw );
	QMPset->setValue( "QMPExport/sch", sch );
	QMPset->setValue( "QMPExport/fPth", fPth );

	QMPset->sync();
	delete QMPset;
}
