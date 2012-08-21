void Save::odczytajopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	Enabled = QMPset->value( "QEQset/Enabled", false ).toBool();
	inSW = QMPset->value( "QEQset/inSW", true ).toBool();

	eqgeo = QMPset->value( "QEQset/eqgeo" ).toRect();

	glW = QMPset->value( "QEQset/glW", false ).toBool();

	for ( int i = 0 ; i < bands ; i++ )
	{
		valEq[i] = QMPset->value( "QEQset/sl" + QString::number(i), -1 ).toInt();
		if ( valEq[i] < 0 )
		{
			fs.clrB();
			break;
		}
	}

	delete QMPset;

	if ( eqgeo.y() < 1 || eqgeo.x() < 1 || eqgeo.width() < 1 || eqgeo.height() < 1 )
	{
		eqgeo.setX( qdw.width()/2 - fs.width()/2 );
		eqgeo.setY( qdw.height()/2 - fs.height()/2 );
		eqgeo.setSize( fs.minimumSize() );
		fs.setGeometry( eqgeo );
	}
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QEQset/Enabled", Enabled );
	QMPset->setValue( "QEQset/inSW", inSW );

	QMPset->setValue( "QEQset/eqgeo", eqgeo );

	QMPset->setValue( "QEQset/glW", glW );

	for ( int i = 0 ; i < bands ; i++ )
		QMPset->setValue( "QEQset/sl" + QString::number(i), valEq[i] );

	QMPset->sync();
	delete QMPset;
}
