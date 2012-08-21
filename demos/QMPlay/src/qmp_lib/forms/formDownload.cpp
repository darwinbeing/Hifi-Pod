void FormDownload::Init( QWidget *qW )
{
	move( qW->x() + qW->width()/2 - width()/2 , qW->y() + qW->height()/2 - height()/2 );

	ui.label->setText( Texts[109]/* "Pobieranie aktualizacji" */ );
	ui.label->setToolTip( "" );
	ui.brB->setText(Texts[68]/*"Przerwij"*/);
	ui.instB->setVisible(false);

	timDwn.start(125);
}

void FormDownload::doFinish( QString str )
{
	timDwn.stop();

	unloadCURL();

	ui.label->setText( str );
	ui.label->setToolTip( str );
	ui.brB->setText(Texts[66]/*"Zamknij"*/);
}

void FormDownload::zamknij()
{
	if ( downloadThr.isRunning() )
	{
		downloadThr.doExit();
		doFinish("");
		remove( downloadThr.path.toAscii() );
	}
	ui.dwnB->setValue(0);
	close();
}

void FormDownload::timDwnDo()
{
	ui.dwnB->setValue(downloadThr.pC);
	ui.spdL->setText(QString::number(downloadThr.spd / 1000., 'f', 2)+"kB/s");
	ui.dwnL->setText(QString::number(downloadThr.dwn / 1000., 'f', 2)+"kB");
	if ( downloadThr.error )
	{
		doFinish(downloadThr.errStr);
		return;
	}
	if ( downloadThr.finished )
	{
		doFinish(Texts[110]/*"Pobrano aktualizacje"*/);
		ui.instB->setVisible( Func.open( "" ) );
		return;
	}
}

void FormDownload::install()
{
	if ( QFile::exists( downloadThr.path ) )
	{
		fname = downloadThr.path;
		Func.open( downloadThr.path );
		f1.close();
	}
}
