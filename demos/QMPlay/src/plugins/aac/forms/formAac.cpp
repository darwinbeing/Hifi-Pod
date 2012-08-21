void FormAac::updateEdits()
{
	ui.id3L->setText( id3Str );
	ui.pthE->setText( curF );
}

void FormAac::timRefDo()
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
			ui.srateL->setText( QString::number( fil->rate ) );

			QString CHN;
			if ( fil->chn == 1 || fil->chn == 2 )
			{
				if ( fil->chn == 1 )
					CHN = "Mono";
				if ( fil->chn == 2 )
					CHN = "Stereo";
			}
			else
				CHN = QString::number( fil->chn );
			ui.chnL->setText( CHN );

			updateEdits();
			updateF = false;
		}
	}
}

void FormAac::Init()
{
	if ( !timref.isActive() )
		timref.start(timRefValue);
	fo->move(0,0);
	fo->resize(fosW,fosH);

	updateF = true;
	ui.pthE->clear();
	ui.id3L->clear();
	ui.chnL->clear();
	ui.srateL->clear();
	ui.aBitRateL->clear();
}

void FormAac::editId3()
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

bool nH(0);
void FormAac::closeEvent(QCloseEvent*)
{
	fosW=width();
	fosH=height();
	timref.stop();
}

void FormAac::hideEvent(QHideEvent*)
{
	if ( !nH )
		QLib->control(0xA,1); //zamyka okno  informacji
	nH = 0;
}

void FormAac::Close()
{
	nH = 1;
	close();
}

void FormAac::zamknij()
{
	QLib->control(0xA,1); //zamyka okno  informacji
	nH = 0;
}
