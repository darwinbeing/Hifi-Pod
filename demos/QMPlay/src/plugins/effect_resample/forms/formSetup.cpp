void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	if ( autoFactor )
		ui.autoFactorB->setChecked( true );
	else
		ui.manualFactorB->setChecked( true );
	ui.factorB->setValue( factor );
	ui.hqB->setChecked( HQ );
}

void FormSetup::chFactor()
{
	if ( canChFactor )
		factor = ui.factorB->value();
}

void FormSetup::ApplyB()
{
	fs.ui.enabledB->setChecked( fs.ui.enabledB->isChecked() );
	Enabled = fs.ui.enabledB->isChecked();
	autoFactor = ui.autoFactorB->isChecked();
	factor = ui.factorB->value();
	HQ = ui.hqB->isChecked();

	if ( !Enabled )
		closeEff();

	Save.zapiszopcje();
}
