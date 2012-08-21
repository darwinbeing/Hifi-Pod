bool IsPowerOfTwo( unsigned x )
{
	if ( x < 2 )
		return false;
	if ( x & (x-1) )        // Thanks to 'byang' for this cute trick!
		return false;
	return true;
}

void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	isON = QMPset->value( "VisFFT1/isON", false ).toBool();
	Enabled = QMPset->value( "VisFFT1/Enabled", false ).toBool();
	okno = QMPset->value( "VisFFT1/okno", true ).toBool();
	fftP = QMPset->value( "VisFFT1/fftP", true ).toBool();
	fftL = QMPset->value( "VisFFT1/fftL", false ).toBool();
	fftsize = QMPset->value( "VisFFT1/fftsize", fftDef ).toInt();
	scale = QMPset->value( "VisFFT1/scale", 15 ).toInt();
	fullScope = QMPset->value( "VisFFT1/fullScope", false ).toBool();
	przesun = QMPset->value( "VisFFT1/przesun", 2 ).toInt();
	timRefValue = QMPset->value( "VisFFT1/timRefValue", 25 ).toInt();
	lpaski = QMPset->value( "VisFFT1/lpaski", 18 ).toInt();
	fftK = QMPset->value( "VisFFT1/fftK", 1 ).toBool();

	VisX = QMPset->value( "VisFFT1/X", -1 ).toInt();
	VisY = QMPset->value( "VisFFT1/Y", -1 ).toInt();
	VisW = QMPset->value( "VisFFT1/W", -1 ).toInt();
	VisH = QMPset->value( "VisFFT1/H", -1 ).toInt();

	if ( QMPset->value( "VisFFT1/inDock" ).toBool() )
		Enabled = false;

	delete QMPset;

	if ( !IsPowerOfTwo( fftsize ) )
		fftsize = fftDef;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "VisFFT1/Enabled", Enabled );
	QMPset->setValue( "VisFFT1/isON", isON );
	QMPset->setValue( "VisFFT1/okno", okno );
	QMPset->setValue( "VisFFT1/fftP", fftP );
	QMPset->setValue( "VisFFT1/fftL", fftL );
	QMPset->setValue( "VisFFT1/fftsize", fftsize );
	QMPset->setValue( "VisFFT1/scale", scale );
	QMPset->setValue( "VisFFT1/fullScope", fullScope );
	QMPset->setValue( "VisFFT1/przesun", przesun );
	QMPset->setValue( "VisFFT1/timRefValue", timRefValue );
	QMPset->setValue( "VisFFT1/lpaski", lpaski );
	QMPset->setValue( "VisFFT1/fftK", fftK );

	QMPset->setValue( "VisFFT1/X", VisX );
	QMPset->setValue( "VisFFT1/Y", VisY );
	QMPset->setValue( "VisFFT1/W", VisW );
	QMPset->setValue( "VisFFT1/H", VisH );

	QMPset->setValue( "VisFFT1/inDock", inDock );

	QMPset->sync();
	delete QMPset;
}
