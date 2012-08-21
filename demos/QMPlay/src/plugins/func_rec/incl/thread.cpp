void recthr::run()
{
	if ( QOut->musParam[3] == "2" && priority() != QThread::TimeCriticalPriority )
		setPriority( QThread::TimeCriticalPriority );
	else if ( QOut->musParam[3] == "1" && priority() != QThread::HighestPriority )
		setPriority( QThread::HighestPriority );
	else if ( QOut->musParam[3] == "0" && priority() != QThread::HighPriority )
		setPriority( QThread::HighPriority );

	const QString Title( "Nagrywanie" );
	const QString Title2( "Nagrywanie zatrzymane" );
	QString title(Title);
	if ( !f1.ui.fnameE->text().isEmpty() )
		title += " - " + f1.ui.fnameE->text();
	doEnd = false;

	QOut->busy[1] = true;
	QOut->initRec();
	int BUF_SIZE(0);
	if ( sav )
		*QOut->setExport = true;
	QOut->Init( AudioInfo( rate, bits, chn ), 1, &BUF_SIZE, f1.ui.fnameE->text(), title );

	float fTrwa(0);
	if ( QOut->isRec() )
	{
		QOut->setStopFunction( DoExit );
		char *audio_buffer = new char[BUF_SIZE];
		while ( !doEnd )
		{
			if ( *QOut->PlErr || *QOut->mustReset || *QOut->mustStop )
				break;
			QOut->rec( audio_buffer, BUF_SIZE, Pause );
			if ( !Pause )
			{
				if ( trwa )
				{
					text = "Nagrywanie już trwa!";
					fTrwa -= ( chn * (bits/8.) * BUF_SIZE ) / (float)rate;
					if ( fTrwa <= 0. )
						trwa = 0;
				}
				else
				{
					fTrwa = 4.;
					text = "Nagrywanie...";
				}
				title = Title;
				QOut->Play(audio_buffer,BUF_SIZE, tim ,snd);
			}
			else
			{
				text = "Pauza...";
				title = Title2;
				QOut->Play( audio_buffer, BUF_SIZE, tim, Pause );
			}
			timAdd = true;

			Pause = *QOut->pause2;

			if ( !f1.ui.fnameE->text().isEmpty() )
				title += " - " + f1.ui.fnameE->text();
			*QOut->title = title;
		}
		delete[] audio_buffer;
	}
	else
	{
		QOut->close();
		text = "OutputPlugin nie pozwala na nagrywanie!";
		return;
	}

	QOut->close();
	text = "Zatrzymany";
	timer.stop();
}

void recthr::doExit()
{
	doEnd = true;
	wait(2000);
	if ( isRunning() )
	{
		problem = true;
		terminate();
		if ( isRunning() )
			wait(1000);
		if ( QOut && timer.isActive() && QOut->busy[1] )
			QOut->close();
		text = "Zatrzymany";
		timer.stop();
	}
}
