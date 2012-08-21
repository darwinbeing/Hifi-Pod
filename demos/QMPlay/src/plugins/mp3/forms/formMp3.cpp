void FormMp3::updateEdits()
{
	ui.id3L->setText( id3Str );
	ui.imgL->setPixmap( QPixmap::fromImage( pix ) );
	ui.pthE->setText( curF );
}

void FormMp3::timRefDo()
{
	if ( IsPlaying && isVisible() )
	{
		ui.aBitRateL->setText( getBR );
		if ( ui.id3B->isChecked() && !tagWindowOpened )
			ui.id3B->setChecked(false);
		else if ( !ui.id3B->isChecked() && tagWindowOpened )
			ui.id3B->setChecked(true);
		if ( updateF )
		{
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

	if ( Type == 1 )
		close();
}

void FormMp3::Init()
{
	if ( !timref.isActive() )
		timref.start(timRefValue);
	fo->move(0,0);
	fo->resize(fosW,fosH);

	updateF = true;
	ui.id3L->clear();
	ui.imgL->setPixmap( NULL );
	ui.pthE->clear();
	ui.aBitRateL->clear();
	ui.srateL->clear();
	ui.chnL->clear();
}

void FormMp3::closeEvent(QCloseEvent*)
{
	fosW=width();
	fosH=height();
	if ( timref.isActive() )
		timref.stop();
}

void FormMp3::editId3()
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

void FormMp3::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
}
