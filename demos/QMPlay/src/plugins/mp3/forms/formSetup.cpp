void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );
	ui.notReadID3->setChecked( notReadID3 );

	ui.searchPartsB->setChecked( searchParts );
	ui.wait4DataB->setChecked( wait4Data );
}

void FormSetup::ApplyB()
{
	if ( Enabled != ui.enabledB->isChecked() )
		mustReset = true;

	Enabled = ui.enabledB->isChecked();
	formatSupport = ui.extsB->text();
	notReadID3 = ui.notReadID3->isChecked();

	searchParts = ui.searchPartsB->isChecked();
	wait4Data = ui.wait4DataB->isChecked();

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
