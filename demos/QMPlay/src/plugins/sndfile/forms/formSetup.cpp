void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );
}

void FormSetup::ApplyB()
{
	if ( Enabled != fs.ui.enabledB->isChecked() || formatSupport != ui.extsB->text() )
		mustReset = true;

	Enabled = fs.ui.enabledB->isChecked();

	formatSupport = ui.extsB->text();

	Save.zapiszopcje();
}

void FormSetup::hideEvent(QHideEvent*)
{
	if ( parent() == NULL )
		setupTimer.start(10);
}

void FormSetup::FsetupTimer()
{
	setupTimer.stop();
	opcje(NULL);
}
