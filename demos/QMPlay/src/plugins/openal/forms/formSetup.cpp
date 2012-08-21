void FormSetup::loadList()
{
	ui.drvlistB->clear();

	QString defaultDev = alcGetString( NULL, ALC_DEFAULT_DEVICE_SPECIFIER );
	const ALCchar *devs = alcGetString( NULL, ALC_DEVICE_SPECIFIER );
	QStringList devList;
	QString dev;
	int i = 0;
	for(;;)
	{
		char ch = devs[i++];
		if ( ch == 0 )
		{
			devList += dev;
			dev.clear();
			ch = devs[i++];
			if ( ch == 0 )
				break;
		}
		dev += ch;
	}

	ui.drvlistB->addItems( devList );

	if ( !devList.contains( devName ) )
		devName = defaultDev;

	ui.drvlistB->setCurrentIndex( devList.indexOf( devName ) );
}

void FormSetup::Init()
{
	ui.enabledB->setChecked( Enabled );
	ui.buffsB->setValue( NUM_BUFFERS );
	ui.onlyMultiChnB->setChecked( onlyMultiChn );

	loadList();
}

void FormSetup::ApplyB()
{
	QString oldDevName = devName;

	devName = ui.drvlistB->currentText();

	if ( Enabled != fs.ui.enabledB->isChecked() || NUM_BUFFERS != fs.ui.buffsB->value() || devName != oldDevName || onlyMultiChn != ui.onlyMultiChnB->isChecked() )
		mustReset = true;

	Enabled = fs.ui.enabledB->isChecked();
	NUM_BUFFERS = fs.ui.buffsB->value();
	onlyMultiChn = ui.onlyMultiChnB->isChecked();

	delete[] Buffers;
	Buffers = new ALuint[ NUM_BUFFERS ];

	Save.zapiszopcje();
}
