void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	fs.ui.echoB->setChecked( effEcho );
	fs.ui.voiceB->setChecked( effVoice );
	fs.ui.skipB->setChecked( effSkip );
	fs.ui.szybkoB->setChecked( effSzybko );
	fs.ui.wolnoB->setChecked( effWolno );

	fs.ui.surroundB->setChecked( echoSurround );

	fs.ui.e1s->setValue( echo_delay );
	fs.ui.e2s->setValue( echo_feedback );
	fs.ui.e3s->setValue( echo_volume );

	fs.ui.p1s->setValue( p1s );
	fs.ui.p2s->setValue( p2s );

	if ( voice )
	{
		fs.ui.mniejB->setChecked( false );
		fs.ui.wiecejB->setChecked( true );
	}
	else
	{
		fs.ui.mniejB->setChecked( true );
		fs.ui.wiecejB->setChecked( false );
	}

	switch(effInvert)
	{
		case 0: ui.i0->setChecked(true); break;
		case 1: ui.i1->setChecked(true); break;
		case 2: ui.i2->setChecked(true); break;
		case 3: ui.i3->setChecked(true); break;
	}
}

void FormSetup::slidersEcho()
{
	if ( !canChEchoVal )
		return;

	echoSurround = fs.ui.surroundB->isChecked();

	echo_delay = fs.ui.e1s->value();
	echo_feedback = fs.ui.e2s->value();
	echo_volume = fs.ui.e3s->value();
}

void FormSetup::ApplyB()
{
	Enabled = fs.ui.enabledB->isChecked();
	effEcho = fs.ui.echoB->isChecked();
	effVoice = fs.ui.voiceB->isChecked();
	effSkip = fs.ui.skipB->isChecked();
	effSzybko = fs.ui.szybkoB->isChecked();
	effWolno = fs.ui.wolnoB->isChecked();

	echoSurround = fs.ui.surroundB->isChecked();

	echo_delay = fs.ui.e1s->value();
	echo_feedback = fs.ui.e2s->value();
	echo_volume = fs.ui.e3s->value();

	p1s = fs.ui.p1s->value();
	p2s = fs.ui.p2s->value();

	state = 0;
	state2 = 0;

	if ( fs.ui.mniejB->isChecked() )
		voice = false;
	else
		voice = true;

	if ( ui.i0->isChecked() )
		effInvert = 0;
	if ( ui.i1->isChecked() )
		effInvert = 1;
	if ( ui.i2->isChecked() )
		effInvert = 2;
	if ( ui.i3->isChecked() )
		effInvert = 3;

	if ( !Enabled )
		closeEff();

	Save.zapiszopcje();
}
