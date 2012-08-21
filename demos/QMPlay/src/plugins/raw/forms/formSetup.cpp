void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );

	if ( BITS == 8 && u8B )
		ui.u8B->setChecked(true);
	if ( BITS == 8 && !u8B )
		ui.s8B->setChecked(true);
	if ( BITS == 16 )
		ui.i16B->setChecked(true);
	if ( BITS == 24 )
		ui.i24B->setChecked(true);
	if ( BITS == 32 )
		ui.i32B->setChecked(true);
	if ( BITS == 33 )
		ui.f32B->setChecked(true);

	ui.chnB->setValue( chnB );
	ui.srateB->setValue( srateB );

	if ( be )
		ui.beB->setChecked(true);
	else
		ui.leB->setChecked(true);

	ui.skipB->setValue( skipB );
}

void FormSetup::ApplyB()
{
	bool BITSch(0);
	if ( BITS == 8 && !u8B && !ui.s8B ->isChecked() )
		BITSch = true;
	if ( BITS == 8 && u8B && !ui.u8B ->isChecked() )
		BITSch = true;
	if ( BITS == 16 && !ui.i16B->isChecked() )
		BITSch = true;
	if ( BITS == 24 && !ui.i24B->isChecked() )
		BITSch = true;
	if ( BITS == 32 && !ui.i32B->isChecked() )
		BITSch = true;
	if ( BITS == 33 && !ui.f32B->isChecked() )
		BITSch = true;

	if ( Enabled != fs.ui.enabledB->isChecked() || formatSupport != ui.extsB->text() || chnB != ui.chnB->value() || srateB != ui.srateB->value() || BITSch || ui.skipB->value() != skipB )
		mustReset = true;
	BITSch = false;

	Enabled = fs.ui.enabledB->isChecked();

	formatSupport = ui.extsB->text();

	u8B = ui.u8B->isChecked();

	if ( ui.u8B->isChecked() | ui.s8B->isChecked() )
		BITS = 8;
	if ( ui.i16B->isChecked() )
		BITS = 16;
	if ( ui.i16B->isChecked() )
		BITS = 16;
	if ( ui.i24B->isChecked() )
		BITS = 24;
	if ( ui.i32B->isChecked() )
		BITS = 32;
	if ( ui.f32B->isChecked() )
		BITS = 33;

	chnB = ui.chnB->value();
	srateB = ui.srateB->value();

	if ( ui.beB->isChecked() )
		be = true;
	else
		be = false;

	skipB = ui.skipB->value();

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
