void FormSndfile::updateEdits()
{
	ui.pthE->setText( curF );
	ui.imgL->setPixmap( QPixmap::fromImage( pix ) );
	ui.txtL->setText( sndfileInfoStr );
}

void FormSndfile::timRefDo()
{
	if ( IsPlaying && isVisible() )
	{
		if ( ui.tagB->isChecked() && !tagWindowOpened )
			ui.tagB->setChecked(false);
		else if ( !ui.tagB->isChecked() && tagWindowOpened )
			ui.tagB->setChecked(true);

		if ( updateF )
		{
			ui.formatL->setText( getFormatStr( sndInfo.format ) );
			ui.srateL->setText( QString::number( sndInfo.samplerate ) );

			QString CHN;
			if ( sndInfo.channels == 1 || sndInfo.channels == 2 )
			{
				if ( sndInfo.channels == 1 )
					CHN = "Mono";
				if ( sndInfo.channels == 2 )
					CHN = "Stereo";
			}
			else
				CHN = QString::number( sndInfo.channels );
			ui.chnL->setText( CHN );

			updateEdits();
			updateF = false;
		}
	}
}

void FormSndfile::Init()
{
	if ( !timref.isActive() )
		timref.start(timRefValue);
	fo->move(0,0);
	fo->resize(fosW,fosH);

	updateF = true;
	ui.pthE->clear();
	ui.imgL->setPixmap( NULL );
	ui.txtL->clear();
	ui.chnL->clear();
	ui.srateL->clear();
	ui.formatL->clear();
}

void FormSndfile::editTag()
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

void FormSndfile::closeEvent(QCloseEvent*)
{
	fosW = width();
	fosH = height();
	timref.stop();
}

void FormSndfile::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
}
