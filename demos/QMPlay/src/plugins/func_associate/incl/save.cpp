void Save::odczytajopcje()
{
	QStringList extsL[2];
	f1.ui.extsList->clear();

	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	as = QMPset->value( "FuncAssociate/onRun" ).toBool();
	f1.ui.onRunB->setChecked( as );

	extsL[0] = QMPset->value( "FuncAssociate/extsTxt" ).toStringList();
	extsL[1] = QMPset->value( "FuncAssociate/extsSel" ).toStringList();

	if ( !extsL[0].count() || extsL[0].count() != extsL[1].count() )
		mustGetExts = true;
	else
	{
		f1.ui.extsList->addItems( extsL[0] );
		for ( int i = 0 ; i < f1.ui.extsList->count() ; i++ )
			f1.ui.extsList->item(i)->setCheckState( ( Qt::CheckState )extsL[1][i].toInt() );
	}

	if ( mustGetExts || as )
		timer.start( 500 );

	delete QMPset;
}

void Save::zapiszopcje()
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QStringList extsL[2];

	for ( int i = 0 ; i < f1.ui.extsList->count() ; i++ )
	{
		extsL[0] += f1.ui.extsList->item(i)->text();
		extsL[1] += QString::number( (int)f1.ui.extsList->item(i)->checkState() );
	}

	QMPset->setValue( "FuncAssociate/onRun", f1.ui.onRunB->isChecked() );
	QMPset->setValue( "FuncAssociate/extsTxt", extsL[0] );
	QMPset->setValue( "FuncAssociate/extsSel", extsL[1] );

	QMPset->sync();
	delete QMPset;
}

void Save::zapiszOnRun(bool b)
{
	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "FuncAssociate/onRun", b );

	QMPset->sync();
	delete QMPset;
}
