void FormInfo::Init()
{
	resize(fisW,fisH);

	if(!timRef.isActive())
		timRef.start(250);
}

void FormInfo::clr2()
{
	ui.cdartistE->setToolTip("");
	ui.cdtitleE->setToolTip("");
	ui.cdgenereE->setToolTip("");
	ui.cdyearE->setToolTip("");
	ui.artistE->setToolTip("");
	ui.titleE->setToolTip("");
	ui.cdL->setToolTip("");
}

void FormInfo::clr()
{
	fTitle.clear();
	fArtist.clear();
	fChn = 0;

	clr2();

	updateEdits = true;
}

void FormInfo::timRefDo()
{
	if ( !isVisible() )
		timRef.stop();

	if ( updateEdits )
	{
		if ( fChn )
			ui.chnL->setText( "Channels: " + QString::number(fChn) );
		else
			ui.chnL->setText("");

		ui.cdartistE->setText( CDInfo.artist );
		ui.cdtitleE->setText( CDInfo.title );
		ui.cdgenereE->setText( CDInfo.genere );
		if (CDInfo.year)
			ui.cdyearE->setText( QString::number(CDInfo.year) );
		else
			ui.cdyearE->setText("");

		ui.artistE->setText( fTitle );
		ui.titleE->setText( fArtist );

		ui.tL->setText( QString::number( fTrack ) );

		clr2();
		if ( !ui.cdartistE->text().isEmpty() )
			ui.cdartistE->setToolTip( CDInfo.from );
		if ( !ui.cdtitleE->text().isEmpty() )
			ui.cdtitleE->setToolTip( CDInfo.from );
		if ( !ui.cdgenereE->text().isEmpty() )
			ui.cdgenereE->setToolTip( CDInfo.from );
		if ( !ui.cdyearE->text().isEmpty() )
			ui.cdyearE->setToolTip( CDInfo.from );
		if ( !ui.artistE->text().isEmpty() )
			ui.artistE->setToolTip( trackFrom );
		if ( !ui.titleE->text().isEmpty() )
			ui.titleE->setToolTip( trackFrom );
		if ( CDInfo.discid && CDInfo.from == "CDDB" )
			ui.cdL->setToolTip( "Dics ID: " + QString::number( CDInfo.discid ) );

		updateEdits = false;
	}
	if ( updateEditsDrive )
	{
		ui.cdL->setText( fCD );

		updateEditsDrive = false;
	}
}

void FormInfo::closeEvent(QCloseEvent*)
{
	if ( timRef.isActive() )
		timRef.stop();
	fisW = width();
	fisH = height();
}

void FormInfo::zamknij()
{
	if ( fi->openFromMusInfo )
		QLib->control(0xA,1); //zamyka okno  informacji
	else
		close();
}
