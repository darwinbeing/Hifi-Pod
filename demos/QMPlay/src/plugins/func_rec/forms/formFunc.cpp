void Form1::Init()
{
	text = "Zatrzymany";

	ui.txtL->setText( text );

	ui.chnB->setValue( chn );
	ui.rateB->setValue( rate );
	ui.bitsB->setValue( bits );
	ui.savB->setChecked( sav );
	if ( snd == 2 )
		ui.sndB->setChecked( false );
	else
		ui.sndB->setChecked( true );
}

void Form1::rec()
{
	if ( recthr.isRunning() )
	{
		if ( !Pause )
			trwa = 1;
		return;
	}

	if ( QOut->busy[0] || QOut->busy[1] )
	{
		text = "OutputPlugin jest zajęty!";
		return;
	}

	Pause=false;

	chn = ui.chnB->value();
	rate = ui.rateB->value();
	sav = ui.savB->isChecked();

	if ( ui.bitsB->value() != 8 && ui.bitsB->value() != 16 && ui.bitsB->value() != 32 )
	{
		text = "Akceptowana liczba bitow: 8, 16 lub 32!";
		return;
	}
	bits = ui.bitsB->value();

	if ( ui.sndB->isChecked() )
		snd = 0;
	else
		snd = 2;

	tim = 0;
	timer.start(1000);
	recthr.start();
}

void Form1::sndB()
{
	if ( ui.sndB->isChecked() )
		snd = 0;
	else
		snd = 2;
}

void Form1::pauseB()
{
	if ( !recthr.isRunning() )
		return;

	*QOut->pause2 = !*QOut->pause2;
}

void Form1::Stop()
{
	if ( !recthr.isRunning() )
		return;
	text = "Zatrzymywanie...";
	QOut->control( QOUT_MUST_STOP );
	recthr.doExit();
}

void Form1::timerF()
{
	if ( !Pause & timAdd )
	{
		timAdd = false;
		tim++;
	}
}

void Form1::timRefF()
{
	ui.txtL->setText( text );
	if ( problem )
	{
		problem = false;
		QMessageBox::warning( this,"QMPlay","W QRec prawdopodobnie wystąpił błąd!\nMoże to powodować niestabilność programu!\nQOut powinien zostać zamknięty, jeżeli tak się nie stało\nprzeładuj pluginy lub zrestartuj program." );
	}
}

void Form1::showEvent(QShowEvent*)
{
	timRef.start(timRefValue);
}

void Form1::hideEvent(QHideEvent*)
{
	timRef.stop();
}
