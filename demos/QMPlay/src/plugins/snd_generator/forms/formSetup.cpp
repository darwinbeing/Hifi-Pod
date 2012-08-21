void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );

	ui.hzB->setValue( Hz );
	ui.hzB_2->setValue( Hz2 );
	ui.hzB_3->setValue( Hz3 );
	ui.hzB_4->setValue( Hz4 );
	ui.hzB_5->setValue( Hz5 );
	ui.hzB_6->setValue( Hz6 );
	ui.hzB_7->setValue( Hz7 );
	ui.hzB_8->setValue( Hz8 );

	ui.srateB->setValue( _srate );

	if ( _chn != 1 && _chn != 2 && _chn != 4 && _chn != 6 && _chn != 8 )
		_chn = 1;

	if ( _chn == 1 )
		ui.monoB->setChecked(true);
	if ( _chn == 2 )
		ui.stereoB->setChecked(true);
	if ( _chn == 4 )
		ui.fourB->setChecked(true);
	if ( _chn == 6 )
		ui.sixB->setChecked(true);
	if ( _chn == 8 )
		ui.eightB->setChecked(true);
}

void FormSetup::ApplyB()
{
	if ( Enabled != fs.ui.enabledB->isChecked() || _srate != ui.srateB->value() )
		mustReset = true;

	Enabled = fs.ui.enabledB->isChecked();

	_srate = ui.srateB->value();

	Hz = ui.hzB->value();
	Hz2 = ui.hzB_2->value();
	Hz3 = ui.hzB_3->value();
	Hz4 = ui.hzB_4->value();
	Hz5 = ui.hzB_5->value();
	Hz6 = ui.hzB_6->value();
	Hz7 = ui.hzB_7->value();
	Hz8 = ui.hzB_8->value();

	int tmpchn(1);

	if ( ui.monoB->isChecked() )
		tmpchn = 1;
	if ( ui.stereoB->isChecked() )
		tmpchn = 2;
	if ( ui.fourB->isChecked() )
		tmpchn = 4;
	if ( ui.sixB->isChecked() )
		tmpchn = 6;
	if ( ui.eightB->isChecked() )
		tmpchn = 8;

	if ( tmpchn != _chn )
		mustReset = true;

	_chn = tmpchn;

	Save.zapiszopcje();
}

void FormSetup::hz_1()
{
	Hz = ui.hzB->value();
}
void FormSetup::hz_2()
{
	Hz2 = ui.hzB_2->value();
}
void FormSetup::hz_3()
{
	Hz3 = ui.hzB_3->value();
}
void FormSetup::hz_4()
{
	Hz4 = ui.hzB_4->value();
}
void FormSetup::hz_5()
{
	Hz5 = ui.hzB_5->value();
}
void FormSetup::hz_6()
{
	Hz6 = ui.hzB_6->value();
}
void FormSetup::hz_7()
{
	Hz7 = ui.hzB_7->value();
}
void FormSetup::hz_8()
{
	Hz8 = ui.hzB_8->value();
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

void FormSetup::addB()
{
	if ( QLib )
	{
		QLib->control(1,0);
		QLib->addToPlayList( (QStringList)("plugin://"+(QString)plugName),-1 );
		QLib->lastOnList();
		QLib->control(0,0);
		QLib->showMessage("QMPlay","Dodano wpis: plugin://"+(QString)plugName,1,0,false);
	}
}
