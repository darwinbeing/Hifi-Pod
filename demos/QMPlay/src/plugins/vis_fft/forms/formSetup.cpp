void FormSetup::Init()
{
	ui.isONB->setChecked( isON );
	ui.enabledB->setChecked( Enabled );
	ui.oknoB->setChecked( okno );
	ui.paskiB->setChecked( fftP );
	ui.linieB->setChecked( fftL );
	ui.fftsizeB->setValue( fftsize );
	ui.scaleB->setValue( scale );
	ui.fullScopeB->setChecked( fullScope );
	ui.pB->setValue( przesun );
	ui.refB->setValue( timRefValue );
	ui.lpaskiB->setValue( lpaski );
	ui.kreskiB->setChecked( fftK );
}

void FormSetup::ApplyB()
{
	isON = ui.isONB->isChecked();
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
		if ( VisX < 0 )
			VisX = qdw.width()/2 - Vis->width()/2;
		if ( VisY < 0 )
			VisY = qdw.height()/2 - Vis->height()/2;
		Vis->setGeometry(VisX,VisY,VisW,VisH);
		Vis->connect( &timRef, SIGNAL(timeout()), Vis, SLOT( updateGL() ) );
		Vis->connect( &cursorTim, SIGNAL(timeout()), Vis, SLOT( cursorTimDo() ) );
	}

	fftP = ui.paskiB->isChecked();
	fftL = ui.linieB->isChecked();
	fftsize = ui.fftsizeB->value();
	scale = ui.scaleB->value();
	fullScope = ui.fullScopeB->isChecked();
	przesun = ui.pB->value();
	lpaski = ui.lpaskiB->value();
	fftK = ui.kreskiB->isChecked();

	if ( !IsPowerOfTwo(fftsize) )
	{
		fftsize = fftDef;
		ui.fftsizeB->setValue( fftsize );
	}

	if ( !fullScope )
		fftsize2 = fftsize/2;
	else
		fftsize2 = fftsize;

	if ( lpaski > fftsize2 )
	{
		lpaski = fftsize2;
		ui.lpaskiB->setValue( lpaski );
	}

	kiss_fft_cleanup();
	delete[] f;
	delete[] f2;
	delete[] F;
	f = NULL;
	f2 = NULL;
	F = NULL;
	if ( cfg )
		free( cfg );
	if ( out )
		free( out );
	delete[] spec;
	cfg = NULL;
	out = NULL;
	spec = NULL;

	if ( Enabled )
	{
		f  = new float [lpaski];
		f2 = new float [lpaski];
		F  = new int [lpaski];
		memset( f, 0, sizeof( float ) * lpaski );
		memset( f2, 0, sizeof( float ) * lpaski );
		memset( F, 0, sizeof( int ) * lpaski );

		cfg = kiss_fft_alloc( fftsize, false, 0, 0 );
		out = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * fftsize );
		spec = new float [fftsize];
	}

	if ( przesun > fftsize2 - lpaski )
	{
		przesun = fftsize2 - lpaski;
		ui.pB->setValue( przesun );
	}

	timRefValue = ui.refB->value();

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
	else if ( Vis && Vis->isVisible() )
	{
		if ( Vis->isFullScreen() )
			Vis->showNormal();
		Vis->setParent(NULL);
		Vis->close();
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

	if ( !Enabled )
		timRef.stop();
}

void FormSetup::hideEvent(QHideEvent*)
{
	if ( parent() == NULL )
		setupTimer.start(10);
}

void FormSetup::FsetupTimer()
{
	setupTimer.stop();
	setParent( oW );
	move(0,0);
	show();
}
