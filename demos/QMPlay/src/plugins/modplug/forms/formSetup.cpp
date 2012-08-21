void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	ui.extsB->setText( formatSupport );

	if ( chn == 1 )
		ui.stereoB->setChecked( false );
	else
		ui.stereoB->setChecked( true );

	if ( bits == 16 )
		ui.bitsB->setChecked( true );
	else
		ui.bitsB->setChecked( false );

	ui.loopB->setChecked( loop );

	ui.bassB->setChecked( bass );
	ui.reverbB->setChecked( reverb );
	ui.surroundB->setChecked( surround );

	ui.osB->setChecked( Oversampling );
	ui.nrB->setChecked( NoiseR );

	switch ( rate )
	{
		case 8000 : ui.hz8 ->setChecked( true ); break;
		case 11025: ui.hz11->setChecked( true ); break;
		case 22050: ui.hz22->setChecked( true ); break;
		case 44100: ui.hz44->setChecked( true ); break;
	}

	switch ( Resampling )
	{
		case 0: ui.r1B->setChecked( true ); break;
		case 1: ui.r2B->setChecked( true ); break;
		case 2: ui.r3B->setChecked( true ); break;
		case 3: ui.r4B->setChecked( true ); break;
	}

	ui.bass1B->setValue( bass1 );
	ui.bass2B->setValue( bass2 );

	ui.reverb1B->setValue( reverb1 );
	ui.reverb2B->setValue( reverb2 );

	ui.surround1B->setValue( surround1 );
	ui.surround2B->setValue( surround2 );

	if ( showTime )
		ui.timeB->setChecked( true );
	else
		ui.patternB->setChecked( true );

	ui.volS->setValue( vol );

}

void FormSetup::ApplyB()
{
	if ( Enabled != fs.ui.enabledB->isChecked() )
		mustReset = true;
	Enabled = fs.ui.enabledB->isChecked();
	formatSupport = ui.extsB->text();

	int oldchn(chn),oldbits(bits),oldrate(rate);

	if ( !ui.stereoB->isChecked() )
		chn = 1;
	else
		chn = 2;

	if ( !ui.bitsB->isChecked() )
		bits = 8;
	else
		bits = 16;

	loop = ui.loopB->isChecked();

	bass = ui.bassB->isChecked();
	reverb = ui.reverbB->isChecked();
	surround = ui.surroundB->isChecked();

	Oversampling = ui.osB->isChecked();
	NoiseR = ui.nrB->isChecked();

	rate = 44100;
	if ( ui.hz8->isChecked() )
		rate = 8000;
	if ( ui.hz11->isChecked() )
		rate = 11025;
	if ( ui.hz22->isChecked() )
		rate = 22050;

	Resampling = 0;
	if ( ui.r2B->isChecked() )
		Resampling = 1;
	if ( ui.r3B->isChecked() )
		Resampling = 2;
	if ( ui.r4B->isChecked() )
		Resampling = 3;

	bass1 = ui.bass1B->value();
	bass2 = ui.bass1B->value();

	reverb1 = ui.reverb1B->value();
	reverb2 = ui.reverb2B->value();

	surround1 = ui.surround1B->value();
	surround2 = ui.surround2B->value();

	showTime = ui.timeB->isChecked();

	vol = ui.volS->value();

	Save.zapiszopcje();

	setUp();
	if ( oldchn != chn || oldbits != bits || oldrate != rate )
		mustReset = true;
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

void FormSetup::setVol()
{
	vol = ui.volS->value();
	if ( IsPlaying )
		if ( module )
			ModPlug_SetMasterVolume(module,vol);
}
