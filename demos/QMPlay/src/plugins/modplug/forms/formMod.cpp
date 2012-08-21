void FormMod::timRefDo()
{
	QString instr, sample;

	if ( IsPlaying )
	{
		if ( module )
		{
			spd = ModPlug_GetCurrentSpeed(module);
			tmp = ModPlug_GetCurrentTempo(module);
			row = ModPlug_GetCurrentRow(module);
			typ = ModPlug_GetModuleType(module);
			chnmod = ModPlug_GetPlayingChannels(module);
			pat = ModPlug_GetCurrentOrder(module);

			_pat = ModPlug_GetCurrentPattern(module);

			inst = ModPlug_NumInstruments(module);
			smpl = ModPlug_NumSamples(module);
			numpat = ModPlug_NumPatterns(module);
			numchn = ModPlug_NumChannels(module);

			char *a = new char[1024];
			for ( int i = 0 ; i < smpl ; i++ )
			{
				ModPlug_SampleName(module, i, a);
				sample += QString::number( i+1 ) + ". ";
				sample += a;
				sample += "\n";
			}

			for ( int i = 0 ; i < inst ; i++ )
			{
				ModPlug_InstrumentName(module, i, a);
				instr += QString::number( i+1 ) + ". ";
				instr += a;
				instr += "\n";
			}
			delete[] a;

			mpn = ModPlug_GetPattern(module,_pat,&rowCount);

			if ( fm2.isVisible() )
				fm2.drawSong();

			oldPat = pat;
			oldRow = row;
		}
	}

	QString TYP;
	switch ( typ )
	{
		case 0x01:
			TYP = "ProTracker MOD"; break;
		case 0x02:
			TYP = "ScreamTracker S3M"; break;
		case 0x04:
			TYP = "FastTracker XM"; break;
		case 0x08:
			TYP = "OctaMED"; break;
		case 0x10:
			TYP = "Multitracker MTM"; break;
		case 0x20:
			TYP = "ImpulseTracker IT"; break;
		case 0x40:
			TYP = "UNIS Composer 669"; break;
		case 0x80:
			TYP = "UltraTracker ULT"; break;
		case 0x100:
			TYP = "ScreamTracker STM"; break;
		case 0x200:
			TYP = "Farandole Composer FAR"; break;
		case 0x800:
		case 0x200000:
			TYP = "Advanced Module File AMF"; break;
		case 0x1000:
			TYP = "Extreme Tracker Module AMS"; break;
		case 0x2000:
			TYP = "Digital Sound Module DSM"; break;
		case 0x4000:
			TYP = "DigiTrakker Module MDL"; break;
		case 0x8000:
			TYP = "Oktalyzer Module OKT"; break;
		case 0x20000:
			TYP = "Delusion Digital Music File DMF"; break;
		case 0x40000:
			TYP = "PolyTracker Module PTM"; break;
		case 0x80000:
			TYP = "DigiBooster Pro DBM"; break;
		case 0x100000:
			TYP = "MadTracker MT2"; break;
		case 0x400000:
			TYP = "Protracker Studio Module PSM"; break;
		case 0x800000:
			TYP = "Jazz Jackrabbit 2 Music J2B"; break;
	}
	ui.modformatLabel->setText( TYP );
	ui.titleLabel->setText( title );
	ui.patternLabel->setText( QString::number( pat+1 ) + " / " + QString::number( numpat ) );
	ui.chanLabel->setText( QString::number( chnmod ) + " / " + QString::number( numchn ) );
	ui.rowLabel->setText( QString::number( row+1 ) + " / " + QString::number( rowCount ) );
	ui.spdLabel->setText( QString::number( spd ) );
	ui.bpmLabel->setText( QString::number ( tmp ) );
	ui.sampleLabel->setText( QString::number( smpl ) );
	ui.instrLabel->setText( QString::number ( inst ) );

	ui.instrLabel->setToolTip( instr );
	ui.sampleLabel->setToolTip( sample );

	if (setMFInit)
	{
		oldPat = -1;
		oldRow = -1;
		setMFInit=false;
		fm2.Init();
	}

	if ( IsPlaying && !plSpec )
	{
		fm2.setParent(fm->ui.okno);
		fm2.move(0,0);
		fm2.resize(fm->ui.okno->width(),fm->ui.okno->height());
		fm2.show();
	}
}

void FormMod::Init()
{
	if ( ! timref.isActive() )
		timref.start(timRefValue);
	fm->move(0,0);
	fm->resize(fmsW,fmsH);
}

void FormMod::czyscfm()
{
	ui.modformatLabel->setText("Format MODa");
	ui.titleLabel->setText( "Brak odtwarzanej muzyki" );
	ui.patternLabel->setText("0 / 0");
	ui.chanLabel->setText("0 / 0");
	ui.rowLabel->setText("0 / 0");
	ui.spdLabel->setText("0");
	ui.bpmLabel->setText("0");
	ui.sampleLabel->setText("0");
	ui.instrLabel->setText("0");
	if ( !plSpec )
		fm2.close();
}

void FormMod::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
}

void FormMod::closeEvent(QCloseEvent*)
{
	fmsW = width();
	fmsH = height();
	if ( timref.isActive() && !plSpec )
		timref.stop();
	if ( !plSpec )
		fm2.close();
}

void FormMod::resizeEvent(QResizeEvent*)
{
	if ( !plSpec )
		fm2.resize( fm->ui.okno->width(), fm->ui.okno->height() );
}
