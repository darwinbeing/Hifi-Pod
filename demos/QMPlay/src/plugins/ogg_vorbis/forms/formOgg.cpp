void FormOgg::updateEdits()
{
	ui.pthE->setText( curF );
	ui.txtL->setText( vorbisInfoStr );
}

void FormOgg::timRefDo()
{
	if ( IsPlaying && isVisible() )
	{
		int BR = ov_bitrate_instant(&musicfile)/1000;
		if ( BR > 0 )
			ui.aBitRateL->setText( QString::number( BR ) );

		if ( ui.tagB->isChecked() && !tagWindowOpened )
			ui.tagB->setChecked(false);
		else if ( !ui.tagB->isChecked() && tagWindowOpened )
			ui.tagB->setChecked(true);

		if ( updateF )
		{
			ui.bitRateL->setText ( QString::number( ov_bitrate(&musicfile,-1)/1000 ) );
			ui.srateL->setText( QString::number( rate ) );

			QString CHN;
			if ( chn == 1 || chn == 2 )
			{
				if ( chn == 1 )
					CHN = "Mono";
				if ( chn == 2 )
					CHN = "Stereo";
			}
			else
				CHN = QString::number( chn );
			ui.chnL->setText( CHN );

			updateEdits();
			updateF = false;
		}
	}
}

void FormOgg::Init()
{
	if ( !timref.isActive() )
		timref.start(timRefValue);
	fo->move(0,0);
	fo->resize(fosW,fosH);

	updateF = true;
	ui.pthE->clear();
	ui.txtL->clear();
	ui.chnL->clear();
	ui.aBitRateL->clear();
	ui.bitRateL->clear();
	ui.srateL->clear();
}

void FormOgg::editTag()
{
	if ( !tag_editor )
		return;
	if ( !tagWindowOpened )
		tagEditorWin = tag_editor->openWindow( curF.toUtf8(), this, false, &tagWindowOpened );
	else if ( tagEditorWin )
	{
		tagEditorWin->close();
		tagEditorWin = NULL;
	}
}

void FormOgg::closeEvent(QCloseEvent*)
{
	fosW = width();
	fosH = height();
	timref.stop();
}

void FormOgg::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
}
