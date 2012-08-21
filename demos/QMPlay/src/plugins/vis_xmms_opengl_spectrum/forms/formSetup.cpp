void FormSetup::Init()
{
	fs.ui.isONB->setChecked( isON );
	fs.ui.enabledB->setChecked( Enabled );
	fs.ui.oknoB->setChecked( okno );
	fs.ui.refB->setValue( timRefValue );
}

void FormSetup::ApplyB()
{
	isON = fs.ui.isONB->isChecked();
	if ( !isON )
		ui.enabledB->setChecked( false );
	Enabled = ui.enabledB->isChecked();
	okno = ui.oknoB->isChecked();

	if ( isON && !Vis )
	{
		Vis = new MyVis;
		Vis->setMinimumSize(10,10);
		if ( VisW < 1 )
			VisW = 400;
		if ( VisH < 1 )
			VisH = 300;
		if (VisX < 0 )
			VisX = qdw.width()/2 - Vis->width()/2;
		if (VisY < 0 )
			VisY = qdw.height()/2 - Vis->height()/2;
		Vis->setGeometry(VisX,VisY,VisW,VisH);
		Vis->connect( &timRef, SIGNAL(timeout()), Vis, SLOT( updateGL() ) );
		Vis->connect( &cursorTim, SIGNAL(timeout()), Vis, SLOT( cursorTimDo() ) );
	}

	timRefValue = fs.ui.refB->value();

	timRef.stop();
	if ( Enabled )
	{
		if ( !cfg )
			cfg = kiss_fft_alloc( 512, false, 0, 0 );
		timRef.start( timRefValue );
	}
	else
	{
		kiss_fft_cleanup();
		if ( cfg )
		{
			free( cfg );
			cfg = NULL;
		}
	}

	if ( Enabled && isOpen )
	{
		if ( Vis && !Vis->isVisible() )
		{
			okienkoParent = NULL;
			if ( Vis->x() <= 0 && Vis->y() <= 0 )
				Vis->setGeometry(VisX,VisY,VisW,VisH);
			Vis->setParent(NULL);
			okienko = false;
			if ( !dockEnable )
				Vis->show();
		}
	}
	else
	{
		if ( Vis && Vis->isVisible() )
		{
			if ( Vis->isFullScreen() )
				Vis->showNormal();
			Vis->setParent(NULL);
			Vis->close();
		}
	}

	if ( Vis )
	{
		if ( Vis->isVisible() && okienko && !okno )
			Vis->odlacz();
		else
		{
			if ( okienko )
				Vis->removeAction(fsAct);
			else if ( !okienko )
				Vis->addAction(fsAct);
		}
	}

	Save.zapiszopcje();

	if ( !isON && Vis )
	{
		delete Vis;
		Vis = NULL;
	}
}

void FormSetup::hideEvent(QHideEvent*)
{
	if ( parent() == NULL )
		setupTimer.start(10);
}

void FormSetup::FsetupTimer()
{
	setupTimer.stop();
	fs.setParent( oW );
	fs.move(0,0);
	fs.show();
}
