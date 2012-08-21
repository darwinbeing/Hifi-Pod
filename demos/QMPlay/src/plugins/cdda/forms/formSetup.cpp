bool notSetDrive(0);
bool once(0);

void FormSetup::showEvent(QShowEvent *)
{
	if ( once )
		return;

	char **devs = NULL;
#ifdef Q_WS_WIN
	if ( !( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) )
#endif
		devs = cdio_get_devices( DRIVER_DEVICE );

	QStringList DevsList;

	if ( devs )
	{
		int j(-1);
		for(;;)
		{
			if ( !devs[++j] )
				break;
			else
				DevsList += devs[j];
		}
		cdio_free_device_list( devs );
	}

	notSetDrive = 1;
	ui.driveB->clear();
	if ( DevsList.contains( ui.driveE->text() ) )
		ui.driveB->addItem( "" );
	else
		ui.driveB->addItem( ui.driveE->text() );
	ui.driveB->setCurrentIndex( 0 );
	ui.driveB->addItems( DevsList );
	for ( int i = 0 ; i < DevsList.count() ; i++ )
	{
		if ( DevsList[i] == currCD )
		{
			ui.driveB->setCurrentIndex(i+1);
			break;
		}
	}
	notSetDrive = 0;

	DevsList.clear();

	once = true;
}

void FormSetup::driveE( QString p )
{
	if ( ui.driveB->count() > 0 )
		ui.driveB->setItemText( 0, p );
}

void FormSetup::Init()
{
	QFileInfo currCDInfo = currCD;
	if ( currCDInfo.isDir() )
		loadFirst = true;
	if ( loadFirst )
	{
		loadFirst = false;
		showEvent(NULL);
		if ( ui.driveB->count() > 1 )
		{
			ui.driveB->setCurrentIndex( 1 );
			ui.driveE->setText( ui.driveB->currentText() );
		}
		currCD = ui.driveE->text();
	}
	ui.driveE->setText( currCD );

	ui.enabledB->setChecked( Enabled );
	ui.speedB->setValue( speed );
	ui.clrB->setChecked(clrB);

	if ( useDefaultCacheDir )
		ui.defCacheB->setChecked(true);
	else
		ui.qmpCacheB->setChecked(true);
	ui.useCDDBB->setChecked( useCDDB );

	ui.useUserDatabaseB->setChecked( useUserDatabase );
	ui.useFDBB->setChecked( useFDB );
	ui.useCddbpB->setChecked( useCddbp );
	ui.userDatabaseServerB->setText( userDatabaseServer );

	ui.readCDTXTB->setChecked( readCDTXT );

	CHKENABLED();
}

void FormSetup::CHKENABLED()
{
	if ( ui.useCDDBB->isChecked() )
		ui.frame->setEnabled(true);
	else
		ui.frame->setEnabled(false);
	if ( ui.useUserDatabaseB->isChecked() )
	{
		ui.useCddbpB->setEnabled(true);
		ui.userDatabaseServerB->setEnabled(true);
	}
	else
	{
		ui.useCddbpB->setEnabled(false);
		ui.userDatabaseServerB->setEnabled(false);
	}
}

void FormSetup::setDrive()
{
	if ( notSetDrive )
		return;
	currCD = ui.driveB->currentText();
	ui.driveE->setText( currCD );
}

void FormSetup::eject()
{
	cdio_eject_media_drive( currCD.toAscii() );
}

void FormSetup::closeTB()
{
	cdio_close_tray( currCD.toAscii(), NULL );
}

void FormSetup::closeTray()
{
	if ( ui.canCloseTB->isChecked() )
		closeTB();
}

void FormSetup::ApplyB()
{
	currCD = ui.driveE->text();

	Enabled = fs.ui.enabledB->isChecked();
	speed = ui.speedB->value();
	clrB = ui.clrB->isChecked();

	useDefaultCacheDir = ui.defCacheB->isChecked();
	useCDDB = ui.useCDDBB->isChecked();

	useUserDatabase = ui.useUserDatabaseB->isChecked();
	useFDB = ui.useFDBB->isChecked();
	useCddbp = ui.useCddbpB->isChecked();
	userDatabaseServer = ui.userDatabaseServerB->text();

	readCDTXT = ui.readCDTXTB->isChecked();

	Save.zapiszopcje();
	Init();
}

void FormSetup::hideEvent(QHideEvent *)
{
	if ( parent() == NULL )
		setupTimer.start(10);
}

void FormSetup::FsetupTimer()
{
	setupTimer.stop();
	opcje(NULL);
}

void FormSetup::keyPressEvent(QKeyEvent *k)
{
	if ( k->key() == Qt::Key_Escape )
		close();
}
