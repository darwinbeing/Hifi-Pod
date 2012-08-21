void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );
}

void FormSetup::ApplyB()
{
	if ( Enabled != ui.enabledB->isChecked() )
		mustReset = true;
	Enabled = ui.enabledB->isChecked();
	formatSupport = ui.extsB->text();
	Save.zapiszopcje();
}
