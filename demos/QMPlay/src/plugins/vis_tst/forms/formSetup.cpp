void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );
	fs.ui.oknoB->setChecked( okno );
	fs.ui.msB->setValue( tims );
	fs.ui.lpB->setChecked( lpB );
	fs.ui.sB->setChecked( sB );
	fs.ui.sngTB->setChecked( sngTB );
	fs.ui.refB->setValue( timRefValue );
	fs.ui.pB->setChecked( paski );
	fs.ui.kB->setChecked( kreski );
	fs.ui.kolor2B->setChecked( kolor2 );
}

void FormSetup::ApplyB()
{
	Enabled = fs.ui.enabledB->isChecked();
	okno = fs.ui.oknoB->isChecked();
	tims = fs.ui.msB->value();
	lpB = fs.ui.lpB->isChecked();
	sB = fs.ui.sB->isChecked();
	sngTB = fs.ui.sngTB->isChecked();
	timRefValue = fs.ui.refB->value();
	kolor2 = fs.ui.kolor2B->isChecked();
	kreski = fs.ui.kB->isChecked();
	paski = fs.ui.pB->isChecked();

	Vis->setAutoFillBackground( ui.autoFillBackgroundB->isChecked() );

	if ( Enabled && isOpen )
	{
		if ( !Vis->isVisible() )
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
	else if ( Vis->isVisible() )
	{
		if ( Vis->isFullScreen() )
			Vis->showNormal();
		Vis->setParent(NULL);
		Vis->close();
	}

	if ( Vis && Vis->isVisible() && okienko && !okno )
		Vis->odlacz();
	else
	{
		if ( okienko )
			Vis->removeAction(fsAct);
		else if ( !okienko )
			Vis->addAction(fsAct);
	}

	Save.zapiszopcje();

	if ( !Enabled )
	{
		timRef.stop();
		clr();
		l = r = sl2 = sr2 = sl = sr = 0;
	}
}

void FormSetup::hideEvent (QHideEvent*)
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
