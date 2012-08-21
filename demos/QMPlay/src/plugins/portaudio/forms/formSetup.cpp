void FormSetup::detectB()
{
	fromBtn = true;
	detect();
}

int QMPlay_GetDefaultOutputDevice()
{
#ifdef Q_OS_LINUX
	int numDevices = Pa_GetDeviceCount();
	for ( int i = 0 ; i < numDevices ; i++ )
	{
		const PaDeviceInfo *devInfo = Pa_GetDeviceInfo( i );
		if ( devInfo && devInfo->maxOutputChannels > 0 && !strcmp( devInfo->name, "default" ) )
			return i;
	}
#endif
	return Pa_GetDefaultOutputDevice();
}
int QMPlay_GetDefaultInputDevice()
{
#ifdef Q_OS_LINUX
	int numDevices = Pa_GetDeviceCount();
	for ( int i = 0 ; i < numDevices ; i++ )
	{
		const PaDeviceInfo *devInfo = Pa_GetDeviceInfo( i );
		if ( devInfo && devInfo->maxInputChannels > 0 && !strcmp( devInfo->name, "default" ) )
			return i;
	}
#endif
	return Pa_GetDefaultInputDevice();
}

void FormSetup::detect()
{
	devices[0].clear();
	devices[1].clear();
	devicesN[0].clear();
	devicesN[1].clear();

	if ( Pa_Initialize() )
		return;

	const PaDeviceInfo *deviceInfo;
	const PaHostApiInfo *hostApiInfo;
	int numDevices = Pa_GetDeviceCount();
	for ( int i = 0 ; i < numDevices ; i++ )
	{
		deviceInfo = Pa_GetDeviceInfo( i );
		hostApiInfo = Pa_GetHostApiInfo( deviceInfo->hostApi );
		QString tmp = hostApiInfo->name;
		tmp += ": ";
		tmp += QString::fromLocal8Bit( deviceInfo->name );
		if ( deviceInfo->maxOutputChannels > 0 )
		{
			devices[0] += tmp;
			devices[1] += QString::number  ( i );
		}
		if ( deviceInfo->maxInputChannels > 0 )
		{
			devicesN[0] += tmp;
			devicesN[1] += QString::number  ( i );
		}
	}

	if ( zB )
	{
		for ( int i = 0 ; i < devices[0].size() ; i++ )
		{
			if ( devices[0][i] == dN )
			{
				devIndex = i;
				if ( devices[1].count() >= devIndex )
					devIndexPA = devices[1][ devIndex ].toInt();
				else
					devIndexPA = QMPlay_GetDefaultOutputDevice();
				break;
			}
		}

		for ( int i = 0 ; i < devicesN[0].size() ; i++ )
		{
			if ( devicesN[0][i] == dNN )
			{
				devIndexN = i;
				if ( devicesN[1].count() >= devIndexN )
					devIndexNPA = devicesN[1][ devIndexN ].toInt();
				else
					devIndexNPA = QMPlay_GetDefaultInputDevice();
				break;
			}
		}
	}
	if ( fromBtn )
	{
		ui.devB->clear();
		ui.devNB->clear();
		ui.devB->addItems ( devices[0]  );
		ui.devNB->addItems( devicesN[0] );
		ui.devB->setCurrentIndex ( devIndex );
		ui.devNB->setCurrentIndex( devIndexN );
		fromBtn = false;
	}
}

void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	ui.lB->setValue( lB );
	ui.lNB->setValue( lNB );
	ui.zB->setChecked( zB );
#ifdef Q_OS_LINUX
	ui.autoSurroundB->setChecked( autoSurround );
#endif
}

void FormSetup::ApplyDB()
{
	if ( ui.devB->currentIndex() < 0 || ui.devNB->currentIndex() < 0 )
		return;

	devIndex  = ui.devB->currentIndex();
	devIndexN = ui.devNB->currentIndex();

	if ( devIndex < 0 )
	{
		devIndex = 0;
		ui.devB->setCurrentIndex( devIndex );
	}

	if ( devIndexN < 0 )
	{
		devIndexN = 0;
		ui.devNB->setCurrentIndex( devIndexN );
	}

	if ( devices[1].count() >= devIndex )
		devIndexPA = devices[1][ devIndex ].toInt();
	else
		devIndexPA = 0;

	if ( devicesN[1].count() >= devIndexN )
		devIndexNPA = devicesN[1][ devIndexN ].toInt();
	else
		devIndexNPA = 0;

	dN  = ui.devB->currentText ();
	dNN = ui.devNB->currentText();

	Save.zapiszopcje();

	mustReset = true;
}

void FormSetup::ApplyB()
{
	zB = ui.zB->isChecked();
#ifdef Q_OS_LINUX
	autoSurround = ui.autoSurroundB->isChecked();
#endif

	if ( Enabled != ui.enabledB->isChecked() )
		mustReset = true;
	if ( lB != ui.lB->value() )
		mustReset = true;
	if ( lNB != ui.lNB->value() )
		mustReset = true;

	Enabled = ui.enabledB->isChecked();

	lB  = ui.lB ->value();
	lNB = ui.lNB->value();

	Save.zapiszopcje();
}

void FormSetup::defDev()
{
	bool zB2 = zB;
	zB = false;
	detect();
	zB = zB2;

	devIndex = 0;
	devIndexN = 0;

	if ( !Pa_Initialize() )
	{
		devIndexPA  = QMPlay_GetDefaultOutputDevice();
		devIndexNPA = QMPlay_GetDefaultInputDevice();
	}
	else
	{
		devIndexPA = -1;
		devIndexNPA = -1;
	}

	ui.devB->clear();
	ui.devNB->clear();
	ui.devB  -> addItems ( devices [0]  );
	ui.devNB -> addItems ( devicesN[0]  );

	for ( int i = 0 ; i < devices[1].size() ; i++ )
	{
		if ( devices[1][i].toInt() == devIndexPA )
		{
			devIndex = i;
			break;
		}
	}

	for ( int i = 0 ; i < devicesN[1].size() ; i++ )
	{
		if ( devicesN[1][i].toInt() == devIndexNPA )
		{
			devIndexN = i;
			break;
		}
	}

	ui.devB ->setCurrentIndex ( devIndex  );
	ui.devNB->setCurrentIndex ( devIndexN );

	dN  = ui.devB  -> currentText();
	dNN = ui.devNB -> currentText();

	Save.zapiszopcje();

	mustReset = true;
}
