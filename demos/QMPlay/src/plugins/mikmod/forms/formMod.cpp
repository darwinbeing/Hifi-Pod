QString timeFormat()
{
	QString qTim,qSek,qMin;
	int sek,min;

	sek = pltime % 60;
	min = pltime / 60;

	if (min < 10)
		qMin = "0" + QString::number(min);
	else
		qMin = QString::number(min);

	if (sek < 10)
		qSek = "0" + QString::number(sek);
	else
		qSek = QString::number(sek);

	qTim = qMin + " : " + qSek ;

	return qTim;
}

void FormMod::timRefDo()
{
	if ( ( !IsPlaying ) && (fm->isVisible()) ) czyscfm();
	if ( IsPlaying )
	{
		if ( title != fm->ui.titleLabel->text() ) fm->ui.titleLabel->setText ( title );
		if ( fm->ui.modformatLabel->text() != module->modtype ) fm->ui.modformatLabel->setText ( module->modtype );
		if ( timeFormat() != ui.timeLabel->text() ) ui.timeLabel->setText( timeFormat() );
		fm->ui.musicPos->setMinimum( 0 );

		fm->ui.musicPos->setMaximum  ( NumPos  );
		fm->ui.musicPos->setValue    ( SongPos );
		fm->ui.patternLabel->setText ( QString::number(SongPos,10) +" / "+ QString::number(NumPos,10) );
		fm->ui.rowLabel->setText     ( QString::number(module->patpos,10) + " / " + QString::number(module->numrow,10) );
		fm->ui.sampleLabel->setText  ( QString::number(module->numsmp,10) );
		fm->ui.instrLabel->setText   ( getInstr() );
		fm->ui.chanLabel->setText    ( QString::number(module->realchn,10) + " / " + QString::number(module->numchn,10) );
		fm->ui.bpmLabel->setText     ( QString::number(module->bpm,10) );
		fm->ui.spdLabel->setText     ( QString::number(module->sngspd,10) );

		if ( fms.isVisible() )
		{
			fms.ui.S0->setValue(Voice_RealVolume(0));
			fms.ui.S1->setValue(Voice_RealVolume(1));
			fms.ui.S2->setValue(Voice_RealVolume(2));
			fms.ui.S3->setValue(Voice_RealVolume(3));
			fms.ui.S4->setValue(Voice_RealVolume(4));
			fms.ui.S5->setValue(Voice_RealVolume(5));
			fms.ui.S6->setValue(Voice_RealVolume(6));
			fms.ui.S7->setValue(Voice_RealVolume(7));
			fms.ui.S8->setValue(Voice_RealVolume(8));
			fms.ui.S9->setValue(Voice_RealVolume(9));
			fms.ui.S10->setValue(Voice_RealVolume(10));
			fms.ui.S11->setValue(Voice_RealVolume(11));
			fms.ui.S12->setValue(Voice_RealVolume(12));
			fms.ui.S13->setValue(Voice_RealVolume(13));
			fms.ui.S14->setValue(Voice_RealVolume(14));
			fms.ui.S15->setValue(Voice_RealVolume(15));
			fms.ui.S16->setValue(Voice_RealVolume(16));
			fms.ui.S17->setValue(Voice_RealVolume(17));
			fms.ui.S18->setValue(Voice_RealVolume(18));
			fms.ui.S19->setValue(Voice_RealVolume(19));
			fms.ui.S20->setValue(Voice_RealVolume(20));
			fms.ui.S21->setValue(Voice_RealVolume(21));
			fms.ui.S22->setValue(Voice_RealVolume(22));
			fms.ui.S23->setValue(Voice_RealVolume(23));
			fms.ui.S24->setValue(Voice_RealVolume(24));
			fms.ui.S25->setValue(Voice_RealVolume(25));
			fms.ui.S26->setValue(Voice_RealVolume(26));
			fms.ui.S27->setValue(Voice_RealVolume(27));
			fms.ui.S28->setValue(Voice_RealVolume(28));
			fms.ui.S29->setValue(Voice_RealVolume(29));
		}

		if (setMFInit)
		{
			setMFInit=false;
			fms.Init();
			bsb();
			if (fsi.isVisible())
			{
				fsi.closeEvent(NULL);
				fsi.Init();
			}
		}

		if ( IsPlaying && !plSpec )
		{
			fms.setParent(fm->ui.okno);
			fms.move(0,0);
			fms.resize(fm->ui.okno->width(),fm->ui.okno->height());
			fms.show();
		}
	}
}

void FormMod::bsb()
{
	if ( IsPlaying )
	{
		ui.bpmBox->setValue( module->bpm );
		ui.spdBox->setValue( module->sngspd );
	}
}

void FormMod::Init()
{
	if ( ! timref.isActive() )
		timref.start(timRefValue);
	fm->resize(fmsW,fmsH);
	fm->move(0,0);
	bsb();
}

void FormMod::czyscfm()
{
	ui.musicPos->setMinimum(0);
	ui.musicPos->setMaximum(0);
	ui.musicPos->setValue(0);
	ui.modformatLabel->setText("Format MODa");
	ui.titleLabel->setText( "Brak odtwarzanej muzyki" );
	ui.patternLabel->setText("0 / 0");
	ui.sampleLabel->setText("0");
	ui.instrLabel->setText("0");
	ui.chanLabel->setText("0 / 0");
	ui.rowLabel->setText("0 / 0");
	ui.timeLabel->setText("00 : 00");
	ui.spdLabel->setText("0");
	ui.bpmLabel->setText("0");
	ui.spdBox->setValue(1);
	ui.bpmBox->setValue(32);
	if ( !plSpec )
		fms.close();
}

void FormMod::bpmup()
{
	Player_SetTempo(ui.bpmBox->value());
}

void FormMod::spdup()
{
	Player_SetSpeed(ui.spdBox->value());
}

void FormMod::slR()
{
	if ( ! timref.isActive() )
		timref.start(timRefValue);
	int S = fm->ui.musicPos->value();
	seek( S );
}

void FormMod::slP()
{
	timref.stop();
}

void FormMod::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
}

void FormMod::shwsplins()
{
	if ( !fsi.isVisible() )
	{
		fsi.setParent(this);
		fsi.setWindowFlags(Qt::Dialog);
		fsi.Init();
		fsi.show();
	}
}

void FormMod::closeEvent(QCloseEvent*)
{
	fmsW = width();
	fmsH = height();
	if ( timref.isActive() &!plSpec )
		timref.stop();
	if ( !plSpec )
		fms.close();
}

void FormMod::resizeEvent(QResizeEvent*)
{
	if ( !plSpec )
		fms.resize(fm->ui.okno->width(),fm->ui.okno->height());
}
