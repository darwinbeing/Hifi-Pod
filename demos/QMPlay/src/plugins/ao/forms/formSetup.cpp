void FormSetup::loadList()
{
	ui.drvlistB->clear();

	ao_initialize();

	aoinfo = ao_driver_info_list(&drvcount);

	if ( drvid < 0 || drvid > drvcount )
		drvid  = ao_default_driver_id();

	for ( int i = 0 ; i < drvcount ; i++ )
	{
		if ( aoinfo[i]->type == 1 )
			ui.drvlistB->addItem( aoinfo[i]->short_name );
	}

	for ( int i = 0 ; i < ui.drvlistB->count() ; i++ )
	{
		if ( ao_driver_info( drvid )->short_name == ui.drvlistB->itemText(i) )
		{
			ui.drvlistB->setCurrentIndex(i);
			break;
		}
	}
}

void FormSetup::Init()
{
	fs.ui.enabledB->setChecked( Enabled );

	if ( Enabled )
	{
		loadList();
		drvid = ao_driver_id( ui.drvlistB->currentText().toAscii() );
	}
}

void FormSetup::ApplyB()
{
	if ( Enabled != fs.ui.enabledB->isChecked() )
	{
		if ( fs.ui.enabledB->isChecked() )
			loadList();
		mustReset = true;
	}
	Enabled = fs.ui.enabledB->isChecked();

	int olddrvid = drvid;

	if ( Enabled )
	{
		ao_initialize();
		drvid = ao_driver_id( ui.drvlistB->currentText().toAscii() );
	}

	if ( drvid != olddrvid )
		mustReset = true;

	Save.zapiszopcje();
}
