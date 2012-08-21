void FormSetup::Init()
{
    ui.interpBox->setChecked(interp);
    ui.hqmixerBox->setChecked(hqmixer);
    ui.surroundBox->setChecked(surround);
    if (bits16)
    {
	    ui.bit8Button->setChecked (false);
	    ui.bit16Button->setChecked(true);
    }
    else
    {
	    ui.bit8Button->setChecked (true);
	    ui.bit16Button->setChecked(false);
    }
    ui.stereoBox->setChecked(stereo);
    ui.reverseBox->setChecked(reverse);
    ui.softmusicBox->setChecked(softmusic);
    ui.softsfxBox->setChecked(softsndfx);
    ui.loopBox->setChecked(loop);
    ui.fadeoutBox->setChecked(fadeout);

	ui.extEdit->setText( formatSupport );
	ui.enabledB->setChecked( Enabled );

    ui.chnBox->setValue(chnMAX);
    ui.trefBox->setValue(timRefValue);

    if ( mdmixfreq == 44100) ui.hz4Button->setChecked(true); else ui.hz4Button->setChecked(false);
    if ( mdmixfreq == 22050) ui.hz2Button->setChecked(true); else ui.hz4Button->setChecked(false);
    if ( mdmixfreq == 11025) ui.hz1Button->setChecked(true); else ui.hz4Button->setChecked(false);
    if ( mdmixfreq == 8000) ui.hz8Button->setChecked(true); else ui.hz4Button->setChecked(false);

    ui.panSlider->setValue(pansep);
    ui.revSlider->setValue(reverb);
    ui.volSlider->setValue(mdvolume);
}

void FormSetup::APPLY()
{
	if ( ui.interpBox->isChecked() ) interp = true; else interp = false;
	if ( ui.hqmixerBox->isChecked() ) hqmixer = true; else hqmixer = false;
	if ( ui.surroundBox->isChecked() ) surround = true; else surround = false;
	if ( ui.stereoBox->isChecked() ) stereo = true; else stereo = false;
	if ( ui.reverseBox->isChecked() ) reverse = true; else reverse = false;
	if ( ui.softmusicBox->isChecked() ) softmusic = true; else softmusic = false;
	if ( ui.softsfxBox->isChecked() ) softsndfx = true; else softsndfx = false;
	if ( ui.loopBox->isChecked() ) loop = true; else loop = false;
	if ( ui.fadeoutBox->isChecked() ) fadeout = true; else fadeout = false;

	if ( ui.hz4Button->isChecked() ) mdmixfreq = 44100;
	if ( ui.hz2Button->isChecked() ) mdmixfreq = 22050;
	if ( ui.hz1Button->isChecked() ) mdmixfreq = 11025;
	if ( ui.hz8Button->isChecked() ) mdmixfreq = 8000;

	formatSupport = ui.extEdit->text();
	Enabled = ui.enabledB->isChecked();

	pansep = ui.panSlider->value();
	reverb = ui.revSlider->value();
	mdvolume = ui.volSlider->value();

	chnMAX = ui.chnBox->value();
	timRefValue = ui.trefBox->value();

	if ( IsPlaying )
		MODquest();
	else
		setUp();
}

void FormSetup::ApplyB()
{
	APPLY();
	Save.zapiszopcje();
}

void FormSetup::pseplabel()
{
    ui.panLabel->setText( QString::number(ui.panSlider->value(),10) );
}

void FormSetup::revlabel()
{
    ui.revLabel->setText( QString::number(ui.revSlider->value(),10) );
}

void FormSetup::vollabel()
{
	ui.volLabel->setText( QString::number(ui.volSlider->value(),10) );
	md_volume = ui.volSlider->value();
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

void FormSetup::MODquest()
{
    int mb;
    mb = QMessageBox::question(this, "QMPlay","Czy chcesz zrestartowac MikMod?\nNiektore ustawienia wymagaja ponownego uruchomienia!", 3, 4);
	if ( ui.bit16Button->isChecked() )
		bits16 = true;
	else
		if ( ui.bit8Button->isChecked() )
			bits16 = false;
    if (mb==4)
		setUp();
    if (mb==3)
    {
		setUp();
		mustReset = true;
    }
}

void FormSetup::dExtB()
{
	formatSupport = "669;amf;dsm;far;gdm;imf;med;m15;mtm;okt;s3m;stm;stx;ult;uni;mod;it;xm";
	ui.extEdit->setText( formatSupport );
}
