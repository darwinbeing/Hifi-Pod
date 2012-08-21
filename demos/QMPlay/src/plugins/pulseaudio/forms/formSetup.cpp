void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	ui.delayB->setValue( delay );
}

void FormSetup::ApplyB()
{
	if ( Enabled != ui.enabledB->isChecked() || delay != ui.delayB->value() )
		mustReset = true;

	Enabled = ui.enabledB->isChecked();
	delay = ui.delayB->value();

	Save.zapiszopcje();
}
