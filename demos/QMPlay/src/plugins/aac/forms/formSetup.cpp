void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );
}

void FormSetup::ApplyB()
{
	if ( Enabled != fs.ui.enabledB->isChecked() )
		mustReset = true;
	Enabled = fs.ui.enabledB->isChecked();
	formatSupport = ui.extsB->text();
	Save.zapiszopcje();
}
