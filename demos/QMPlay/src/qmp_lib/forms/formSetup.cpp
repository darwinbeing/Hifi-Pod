void FormSetup::Init()
{
	setGeometry( fsGeo );

	ui.NxterrBox->setChecked( errnxt );
	ui.PlaynxtBox->setChecked( playnxt );
	ui.savplistBox->setChecked( savplist );

	ui.procBox->setValue( proce );
	ui.pmppB->setChecked( Bpmpp );
	ui.closeExportOnNxtB->setChecked( closeExportOnNxt );
	ui.secBox->setValue( nextXsV );
	ui.bladinfoB->setChecked( bladinfoB );
	ui.uPLeLB->setChecked( uPLeL );
	ui.uPLeB->setChecked( uPLe );
	ui.fileStructB->setChecked( fileStruct );
	ui.unknownTypeB->setChecked( unknownType );
	ui.fileFilterB->setChecked( fileFilter );
	ui.chImgsB->setChecked( chImgs );
	ui.eoplB->setChecked( eoplB );
	ui.autoUpdatesB->setChecked( autoUpdates );
	ui.svrAddressE->setText( svrAddress );

	ui.sekB->setChecked( seekTime );
	ui.procB->setChecked( !seekTime );

	if ( !zplV )
	{
		zipl=false;
		zvpl=false;
		zdefB=false;
		fs.ui.naf1Box->setChecked(false);
		ui.naf1Frame->setEnabled(false);
	}
	else
	{
		if ( !zipl & !zvpl & !zdefB )
			zdefB=true;
		fs.ui.naf1Box->setChecked(true);
		fs.ui.zIpluginaB->setChecked( zipl );
		fs.ui.zVpluginaB->setChecked( zvpl );
		fs.ui.defB->setChecked( zdefB );
		ui.naf1Frame->setEnabled(true);
	}

	getSettings();
	proxyB();

	if ( ui.pluginsL->currentRow() < 0 )
		ui.pluginsL->setCurrentRow(0);
}

void FormSetup::zvplV()
{
	if ( zvpl )
	{
		bool showOkno = true;
		for (int i = 0 ; i < Vplugins.size() ; i++)
		{
			if ( Vplugins[i]->pluginInfo->swOnOff(0) )
			{
				if ( *Vplugins[i]->okno && showOkno )
				{
					Vplugins[i]->show(f1.ui.okno,true);
					showOkno = false;
				}
				else
					Vplugins[i]->show(NULL,false);
			}
		}
	}
	else
	{
		for (int i = 0 ; i < Vplugins.size() ; i++)
			if ( Vplugins[i]->pluginInfo->swOnOff(0) )
				Vplugins[i]->show(NULL,false);
	}
}

void FormSetup::APPLYQMP()
{
	bool pluginsReloaded = false;
	if ( reloadPlugins )
	{
		reloadPlugins = false;
		ui.loadPlugButton->click();
		pluginsReloaded = true;
	}
	else if ( chkList.count() == ui.pluginList->count() )
	{
		for ( int i = 0 ; i < chkList.count() ; i++ )
		{
			if ( chkList[i] != ui.pluginList->item(i)->checkState() )
			{
				ui.loadPlugButton->click();
				pluginsReloaded = true;
				break;
			}
		}
	}

	errnxt = ui.NxterrBox->isChecked();
	playnxt = ui.PlaynxtBox->isChecked();
	savplist = ui.savplistBox->isChecked();

	closeExportOnNxt = ui.closeExportOnNxtB->isChecked();
	proce = ui.procBox->value();
	Bpmpp = ui.pmppB->isChecked();
	nextXsV = ui.secBox->value();
	bladinfoB = ui.bladinfoB->isChecked();
	uPLeL = ui.uPLeLB->isChecked();
	uPLe = ui.uPLeB->isChecked();
	fileStruct = ui.fileStructB->isChecked();
	unknownType = ui.unknownTypeB->isChecked();
	fileFilter = ui.fileFilterB->isChecked();
	eoplB = ui.eoplB->isChecked();
	autoUpdates = ui.autoUpdatesB->isChecked();
	svrAddress = ui.svrAddressE->text();

	seekTime = ui.sekB->isChecked();

	if ( chImgs != ui.chImgsB->isChecked() )
	{
		lastPosChMusInfo = -2;
		fp.chMusInfo();
	}
	chImgs = ui.chImgsB->isChecked();

	f1.updatemenuItems();

	pbL();
	pbR();

	if ( zplV ) //jeżeli naf1Box jest zaznaczony
	{
		zvpl = fs.ui.zVpluginaB->isChecked();
		zipl = fs.ui.zIpluginaB->isChecked();
		zdefB = fs.ui.defB->isChecked();
		f1.ui.QMPB->setVisible(false);

		if ( mQ.dockVis && mQ.isVisible() )
			mQ.setQVisIcon();
	}
	else
	{
		zvpl=false;
		zipl=false;
		zdefB=false;
		f1.ui.QMPB->setVisible(true);

		if ( f1.ui.okno->parent() == mQ.ui.okienko )
			mQ.setStandardIcon();
	}

	if ( zxplC ) //jeżeli naf1Box był kliknięty lub jedna z trzech opcji
	{
		if ( Iplug->plugSpec )
		{
			if ( zipl ) //z input plugina
				Iplug->plugSpec(f1.ui.okno,true);
			else
				Iplug->plugSpec(f1.ui.okno,false);
		}
		if ( zdefB ) //domyślna z QMP
		{
			fsl.setParent( f1.ui.okno );
			fsl.move(0,0);
			fsl.resize(69,49);
			fsl.show();
		}
		else
		{
			fsl.setParent( NULL );
			fsl.close();
		}

		if ( !pluginsReloaded )
			zvplV(); //dokowanie w "okienku" pluginów wizualizacji

		f1.ui.okno->repaint();

		zxplC = false;
	}

	fdck.applyDock();

	setSettings();

	if ( !usunSets )
	{
		bezzapisulisty = 1;
		Save.zapiszopcje();
	}
}

void FormSetup::zxplCC()
{
	zxplC = true;
}

void FormSetup::naf1()
{
	zxplC = true;

	if ( !ui.naf1Box->isChecked() )
	{
		zplV=false;
		zipl=false;
		zvpl=false;
		ui.naf1Frame->setEnabled(false);
	}
	else
	{
		if ( !zipl && !zvpl && !zdefB )
			zdefB=true;
		zplV=true;
		ui.zIpluginaB->setChecked(zipl);
		ui.zVpluginaB->setChecked(zvpl);
		ui.defB->setChecked(zdefB);
		ui.naf1Frame->setEnabled(true);
	}
}

void FormSetup::getList()
{
	chkList.clear();
	for ( int i = 0 ; i < ui.pluginList->count() ; i++ )
		chkList += ui.pluginList->item(i)->checkState();
}

void FormSetup::lpB()
{
	Func.loadPlugins();
	getList();
}

void FormSetup::closeEvent(QCloseEvent*)
{
	fsGeo = geometry();

	f1.ui.opcjeButton->setChecked(false);

	chkList.clear();
}
void FormSetup::showEvent(QShowEvent*)
{
	f1.ui.opcjeButton->setChecked(true);
	getList();
}

void FormSetup::pbL()
{
	f1.ui.pbL->setVisible( ui.pbLBox->isChecked() );
}

void FormSetup::pbR()
{
	f1.ui.pbR->setVisible( ui.pbRBox->isChecked() );
}

void FormSetup::QMPButton()
{
	ui.tabWidget->setCurrentIndex(0);
}
void FormSetup::prevButton()
{
	switch ( ui.tabWidget->currentIndex() )
	{
		case 0: //główne ustawiania
			if ( ui.tabWidget_2->currentIndex() == 0 )
			{
				ui.pluginsL->setCurrentRow(4);
				ui.funcT->setCurrentIndex( ui.funcT->count()-1 );
				ui.tabWidget->setCurrentIndex(2);
			}
			else
				ui.tabWidget_2->setCurrentIndex( ui.tabWidget_2->currentIndex()-1 );
			break;
		case 1: //ustawiania z głównych bibliotek
			if ( ui.libsT->currentIndex() == 0 )
			{
				ui.tabWidget_2->setCurrentIndex( ui.tabWidget_2->count()-1 );
				ui.tabWidget->setCurrentIndex(0);
			}
			else
				ui.libsT->setCurrentIndex( ui.libsT->currentIndex()-1 );
			break;
		case 2: //ustawiania z wtyczek
			switch ( ui.pluginsL->currentRow() )
			{
				case 0:
					if ( ui.inputT->currentIndex() <= 0 )
					{
						ui.libsT->setCurrentIndex( ui.libsT->count()-1 );
						ui.tabWidget->setCurrentIndex(1);
					}
					else
						ui.inputT->setCurrentIndex( ui.inputT->currentIndex() - 1 );
					break;
				case 1:
					if ( ui.outputT->currentIndex() <= 0 )
					{
						ui.pluginsL->setCurrentRow(0);
						ui.inputT->setCurrentIndex( ui.inputT->count()-1 );
					}
					else
						ui.outputT->setCurrentIndex( ui.outputT->currentIndex() - 1 );
					break;
				case 2:
					if ( ui.effectT->currentIndex() <= 0 )
					{
						ui.pluginsL->setCurrentRow(1);
						ui.outputT->setCurrentIndex( ui.outputT->count()-1 );
					}
					else
						ui.effectT->setCurrentIndex( ui.effectT->currentIndex() - 1 );
					break;
				case 3:
					if ( ui.visT->currentIndex() <= 0 )
					{
						ui.pluginsL->setCurrentRow(2);
						ui.effectT->setCurrentIndex( ui.effectT->count()-1 );
					}
					else
						ui.visT->setCurrentIndex( ui.visT->currentIndex() - 1 );
					break;
				case 4:
					if ( ui.funcT->currentIndex() <= 0 )
					{
						ui.pluginsL->setCurrentRow(3);
						ui.visT->setCurrentIndex( ui.visT->count()-1 );
					}
					else
						ui.funcT->setCurrentIndex( ui.funcT->currentIndex() - 1 );
					break;
			}
			break;
	}
}
void FormSetup::nxtButton()
{
	switch ( ui.tabWidget->currentIndex() )
	{
		case 0: //główne ustawiania
			if ( ui.tabWidget_2->currentIndex() < ui.tabWidget_2->count()-1 )
				ui.tabWidget_2->setCurrentIndex( ui.tabWidget_2->currentIndex()+1 );
			else
			{
				ui.libsT->setCurrentIndex(0);
				ui.tabWidget->setCurrentIndex( ui.tabWidget->currentIndex()+1 );
			}
			break;
		case 1: //ustawiania z głównych bibliotek
			if ( ui.libsT->currentIndex() < ui.libsT->count()-1 )
				ui.libsT->setCurrentIndex( ui.libsT->currentIndex()+1 );
			else
			{
				ui.inputT->setCurrentIndex(0);
				ui.pluginsL->setCurrentRow(0);
				ui.tabWidget->setCurrentIndex( ui.tabWidget->currentIndex()+1 );
			}
			break;
		case 2: //ustawiania z wtyczek
			switch ( ui.pluginsL->currentRow() )
			{
				case 0:
					if ( ui.inputT->currentIndex() < ui.inputT->count()-1 )
						ui.inputT->setCurrentIndex( ui.inputT->currentIndex()+1 );
					else
					{
						ui.outputT->setCurrentIndex(0);
						ui.pluginsL->setCurrentRow(1);
					}
					break;
				case 1:
					if ( ui.outputT->currentIndex() < ui.outputT->count()-1 )
						ui.outputT->setCurrentIndex( ui.outputT->currentIndex()+1 );
					else
					{
						ui.effectT->setCurrentIndex(0);
						ui.pluginsL->setCurrentRow(2);
					}
					break;
				case 2:
					if ( ui.effectT->currentIndex() < ui.effectT->count()-1 )
						ui.effectT->setCurrentIndex( ui.effectT->currentIndex()+1 );
					else
					{
						ui.visT->setCurrentIndex(0);
						ui.pluginsL->setCurrentRow(3);
					}
					break;
				case 3:
					if ( ui.visT->currentIndex() < ui.visT->count()-1 )
						ui.visT->setCurrentIndex( ui.visT->currentIndex()+1 );
					else
					{
						ui.funcT->setCurrentIndex(0);
						ui.pluginsL->setCurrentRow(4);
					}
					break;
				case 4:
					if ( ui.funcT->currentIndex() < ui.funcT->count()-1 )
						ui.funcT->setCurrentIndex( ui.funcT->currentIndex()+1 );
					else
					{
						ui.tabWidget_2->setCurrentIndex(0);
						ui.tabWidget->setCurrentIndex(0);
					}
					break;
			}
			break;
	}
}

void FormSetup::pluginsChRow( int row )
{
	ui.inputT->hide();
	ui.outputT->hide();
	ui.effectT->hide();
	ui.visT->hide();
	ui.funcT->hide();
	switch(row)
	{
		case 0:
			ui.inputT->show();
			break;
		case 1:
			ui.outputT->show();
			break;
		case 2:
			ui.effectT->show();
			break;
		case 3:
			ui.visT->show();
			break;
		case 4:
			ui.funcT->show();
			break;
	}
}

void FormSetup::opcjePB()
{
	if ( ui.pluginList->currentRow() < 0 )
		return;

	QString TMP = ui.pluginList->item( ui.pluginList->currentRow() )->text();
	int w(0);

	for ( w = 0 ; w < ui.inputT->count() ; w++ )
	{
		if ( ui.inputT->tabText(w) == TMP )
		{
			ui.inputT->setCurrentIndex(w);
			ui.pluginsL->setCurrentRow(0);
			ui.tabWidget->setCurrentIndex(2);
			return;
		}
	}
	for ( w = 0 ; w < ui.outputT->count() ; w++ )
	{
		if ( ui.outputT->tabText(w) == TMP )
		{
			ui.outputT->setCurrentIndex(w);
			ui.pluginsL->setCurrentRow(1);
			ui.tabWidget->setCurrentIndex(2);
			return;
		}
	}
	for ( w = 0 ; w < ui.effectT->count() ; w++ )
	{
		if ( ui.effectT->tabText(w) == TMP )
		{
			ui.effectT->setCurrentIndex(w);
			ui.pluginsL->setCurrentRow(2);
			ui.tabWidget->setCurrentIndex(2);
			return;
		}
	}
	for ( w = 0 ; w < ui.visT->count() ; w++ )
	{
		if ( ui.visT->tabText(w) == TMP )
		{
			ui.visT->setCurrentIndex(w);
			ui.pluginsL->setCurrentRow(3);
			ui.tabWidget->setCurrentIndex(2);
			return;
		}
	}
	for ( w = 0 ; w < ui.funcT->count() ; w++ )
	{
		if ( ui.funcT->tabText(w) == TMP )
		{
			ui.funcT->setCurrentIndex(w);
			ui.pluginsL->setCurrentRow(4);
			ui.tabWidget->setCurrentIndex(2);
			return;
		}
	}
}
void FormSetup::toUp()
{
	int w = ui.pluginList->currentRow();

	if ( w <= 0 )
		return;

	reloadPlugins = true;

	pluginsList[0].move( w, w-1 );
	pluginsList[1].move( w, w-1 );
	pluginsList[2].move( w, w-1 );
	pluginsList[3].move( w, w-1 );

	createPluginList();
	ui.pluginList->setCurrentRow(w-1);
}
void FormSetup::toDown()
{
	int w = ui.pluginList->currentRow();

	if ( w < 0 || w > pluginsList[1].size()-2 )
		return;

	reloadPlugins = true;

	pluginsList[0].move( w, w+1 );
	pluginsList[1].move( w, w+1 );
	pluginsList[2].move( w, w+1 );
	pluginsList[3].move( w, w+1 );

	createPluginList();
	ui.pluginList->setCurrentRow(w+1);
}
void FormSetup::createPluginList()
{
	fs.ui.pluginList->clear();

	QMPset = new QSettings (QMPConf,QSettings::IniFormat);
	QMPset->remove("PluginSort");
	for (int w = 0 ; w < pluginsList[0].count() ; w++) //tworzenie listy chceckbox i ustawianie ich
	{
		QMPset->setValue( "PluginSort/"+pluginsList[0][w], w+1 );

		if ( pluginsList[2][w] == "Unknown" )
		{
			fs.ui.pluginList->addItem( "(Unknown) " + pluginsList[1][w] + " (Unknown)" );
			fs.ui.pluginList->item(w)->setCheckState( Qt::Unchecked );
			continue;
		}
		fs.ui.pluginList->addItem( pluginsList[1][w] );
		if ( pluginsList[3][w] == "n" )
			fs.ui.pluginList->item(w)->setCheckState( Qt::Unchecked );
		else
			fs.ui.pluginList->item(w)->setCheckState( Qt::Checked );
	}
	QMPset->sync();
	delete QMPset;

	QOut->setOPlug( Oplugins, QExport );
	QOut->setVis( Vplugins );
	QOut->setEffects( Eplugins, equalizer );

	ui.pluginList->setCurrentRow(0);
}

void FormSetup::setStyleB()
{
 	fst.setParent(this);
	fst.setWindowFlags(Qt::Dialog);
	fst.move( qdw.width()/2 - fst.width()/2, qdw.height()/2 - fst.height()/2 );
	fst.Init();
	fst.show();
}

void FormSetup::formDockChOpen()
{
	fdck.setParent(this);
	fdck.setWindowFlags(Qt::Dialog);
	fdck.move( qdw.width()/2 - fst.width()/2, qdw.height()/2 - fst.height()/2 );
	fdck.Init();
	fdck.show();
}

void FormSetup::delSetsB()
{
	if ( QMessageBox::information(this,"QMPlay",Texts[22],4,3) == 3 )
	{
		if ( QFile::remove( QMPConf ) )
		{
			QMessageBox::information(this,"QMPlay",Texts[23]);
			usunSets = true;
		}
		else
			QMessageBox::warning(this,"QMPlay",Texts[24]);
	}
}

void FormSetup::aboutPlug()
{
	if ( ui.pluginList->currentRow() < 0 )
		return;
	pluginInfoList[ ui.pluginList->currentRow() ]->About(this);
}

void FormSetup::OnOffOnList()
{
	if ( !ui.pluginList->currentItem()->checkState() )
		ui.pluginList->currentItem()->setCheckState( Qt::Checked );
	else
		ui.pluginList->currentItem()->setCheckState( Qt::Unchecked );
}

void FormSetup::OnOffPlug()
{
	if ( ui.pluginList->currentRow() < 0 )
		return;
	pluginInfoList[ ui.pluginList->currentRow() ]->swOnOff(1);
}
void FormSetup::pluglistMenu()
{
	plugLM.clear();

	if ( ui.pluginList->currentRow() < 0 )
		return;

	QString OnOff;

	if ( pluginsList[3][ ui.pluginList->currentRow() ] == "y" && pluginInfoList[ ui.pluginList->currentRow() ]->swOnOff )
	{
		if ( pluginInfoList[ ui.pluginList->currentRow() ]->swOnOff( 0 ) )
			OnOff = Texts[97] /** Wyłącz */;
		else
			OnOff = Texts[96] /** Włącz */;
		plugLM.addAction( OnOff , &fs , SLOT( OnOffPlug() ) );
		plugLM.addSeparator();
	}

	if ( !ui.pluginList->currentItem()->checkState() )
		OnOff = Texts[98];
	else
		OnOff = Texts[95];

	plugLM.addAction( OnOff ,&fs,SLOT(OnOffOnList()));
	plugLM.addSeparator();

	plugLM.addAction( Texts[25] /** "O wtyczce" */,&fs,SLOT(aboutPlug()));
	plugLM.addSeparator();
	plugLM.addAction( Texts[26] /** "Przeładuj pluginy" */,&fs,SLOT(lpB()));
	plugLM.addSeparator();

	if ( pluginsList[3][ ui.pluginList->currentRow() ] == "y" )
		plugLM.addAction( Texts[27] /** "Opcje" */,&fs,SLOT(opcjePB()));

	plugLM.popup( QCursor::pos() );
}

void FormSetup::langB()
{
	fl.setParent(this);
	fl.setWindowFlags(Qt::Dialog);
	fl.move( qdw.width()/2 - fl.width()/2, qdw.height()/2 - fl.height()/2 );
	fl.Init();
	fl.show();
}


void FormSetup::proxyB()
{
	ui.proxyE->setEnabled( ui.proxyB->isChecked() );
}

void FormSetup::getSettings()
{
	if ( !InternetProtocols.isEmpty() )
		return;
	QLibrary QInternet_lib;
	QInternet_lib.setFileName( QMPInternetf+libExt );
	if ( QInternet_lib.load() )
	{
		if ( chkQMPInternet( &QInternet_lib ) )
		{
			typedef const char *(*_getSettings)(bool&,int&,int&,int&);
			typedef void (*_setQMPConf)(QString);
			typedef QStringList (*_protocols);
			_getSettings getSettings;
			_setQMPConf setQMPConf;
			getSettings = (_getSettings) QInternet_lib.resolve( "getSettings" );
			setQMPConf = (_setQMPConf) QInternet_lib.resolve( "setQMPConf" );
			InternetProtocols = *(_protocols) QInternet_lib.resolve( "protocols" );
			if ( getSettings && setQMPConf )
			{
				setQMPConf( QMPConf );
				bool useProxy(0);
				int maxSpdDwn(0), maxSpdUpl(0), buffSize(0);
				ui.proxyE->setText( getSettings(useProxy, maxSpdDwn, maxSpdUpl, buffSize) );
				ui.proxyB->setChecked(useProxy);
				ui.maxSpdDwnB->setValue(maxSpdDwn);
				ui.maxSpdUplB->setValue(maxSpdUpl);
				ui.buffSizeB->setValue(buffSize);
			}
		}
		QInternet_lib.unload();
	}
	if ( InternetProtocols.isEmpty() )
		InternetProtocols += "http://";
}

void FormSetup::setSettings()
{
	QLibrary QInternet_lib;
	QInternet_lib.setFileName( QMPInternetf+libExt );
	if ( QInternet_lib.load() )
	{
		if ( chkQMPInternet( &QInternet_lib ) )
		{
			typedef void (*_setSettings)(const char *,bool,int,int,int);
			typedef void (*_setQMPConf)(QString);
			_setSettings setSettings;
			_setQMPConf setQMPConf;
			setSettings = (_setSettings) QInternet_lib.resolve( "setSettings" );
			setQMPConf = (_setQMPConf) QInternet_lib.resolve( "setQMPConf" );
			if ( setSettings && setQMPConf )
			{
				setQMPConf( QMPConf );
				setSettings( ui.proxyE->text().toAscii(), ui.proxyB->isChecked(), ui.maxSpdDwnB->value(), ui.maxSpdUplB->value(), ui.buffSizeB->value() );
			}
		}
		else if ( ui.tabWidget->currentIndex() == 0 && ui.tabWidget_2->currentIndex() == 2 )
			QMessageBox::warning( this, "QMPlay", Texts[108] /* Nie mozna zaladowac biblioteki */+ QMPInternetf+libExt + ", " + Texts[29] /**"plik nie jest poprawnym plikiem QMP!"*/);
		QInternet_lib.unload();
	}
	else if ( ui.tabWidget->currentIndex() == 0 && ui.tabWidget_2->currentIndex() == 2 )
		QMessageBox::warning( this, "QMPlay", Texts[108] /* Nie mozna zaladowac biblioteki */+ QMPInternetf+libExt + "\n" + QInternet_lib.errorString() );
}

void FormSetup::restoreAddress()
{
	ui.svrAddressE->setText( QMPlayUpdatesAddress );
}

void FormSetup::fileStructBClicked( int state )
{
	ui.unknownTypeB->setEnabled( state );
		ui.unknownTypeB->setChecked( state );
}
