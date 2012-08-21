const int langCount = 132+1;
QStringList lnglist[3];

void FormLang::Init()
{
	firstIdx = -1;
	lnglist[0].clear();
	lnglist[1].clear();
	lnglist[2].clear();

	QStringList files = QDir( qApp->applicationDirPath() + "/lang" ).entryList( QStringList( "*.qmplang" ), QDir::Files );

	for ( int i = 0 ; i < files.size() ; i++ )
	{
		QMPset = new QSettings( "lang/"+files[i], QSettings::IniFormat );

		if ( !QMPset->value("QMPLng/QMPLng").toBool() || QMPset->value("QMPLng/QMPVer").toUInt() != QMPlayLangVer )
		{
			delete QMPset;
			continue;
		}

		lnglist[0] += QMPset->value("QMPLng/Lang").toString();
		lnglist[1] += "lang/"+files[i];
		lnglist[2] += QMPset->value("QMPLng/Name").toString();
		if ( QMPset->value("QMPLng/First").toBool() && firstIdx < 0 )
			firstIdx = lnglist[ 2 ].count() - 1;

		delete QMPset;
	}
	if ( firstIdx < 0 )
		firstIdx = 0;

	ui.langCB->clear();
	ui.langCB->addItems( lnglist[0] );

	int idx = lnglist[2].indexOf( language );
	if ( idx < 0 )
		idx = firstIdx;
	ui.langCB->setCurrentIndex( idx );
}

void FormLang::zamknij()
{
	setLang();
	setLangLibs();

	close();
}

void FormLang::setLang()
{
	QMPset = new QSettings( lnglist[1][ui.langCB->currentIndex()] , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	Texts.clear();

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QMP/" + QString::number(i) ).toString();

	Texts[7]  += " "+QMPVersion;
	Texts[29] += " "+QMPVersion;

	formInfo.setObjectName( Texts[125] /* Informacje o muzyce */ );

	f1.ui.actionZakoncz->setText( QMPset->value( "MainWindow/0" ).toString() );
	f1.ui.actionInformacje_2->setText( QMPset->value( "MainWindow/1" ).toString() );
	f1.ui.dodatkiB->setText( QMPset->value( "MainWindow/2" ).toString() );
	f1.ui.act_funkcje->setText( QMPset->value( "MainWindow/2" ).toString() );
	f1.ui.actionAB->setText( QMPset->value( "MainWindow/3" ).toString() );
	f1.ui.actionOpcje->setText( QMPset->value( "MainWindow/4" ).toString() );
	f1.ui.opcjeButton->setText( QMPset->value( "MainWindow/4" ).toString() );
	f1.ui.actionInformacje->setText( QMPset->value( "MainWindow/5" ).toString() );
	f1.ui.actionSHPlist->setText( QMPset->value( "MainWindow/6" ).toString() );
	f1.ui.NewPLAct->setText( QMPset->value( "MainWindow/7" ).toString() );
	f1.ui.menuAkcja->setTitle( QMPset->value( "MainWindow/8" ).toString() );
	f1.ui.actionClrplist->setText( QMPset->value( "MainWindow/9" ).toString() );
	f1.ui.actionWyszukaj->setText( QMPset->value( "MainWindow/10" ).toString() );
	f1.ui.wlasciwosciA->setText( QMPset->value( "MainWindow/11" ).toString() );
	f1.ui.selMusA->setText( QMPset->value( "MainWindow/12" ).toString() );
	f1.ui.ukryjA->setText( QMPset->value( "MainWindow/13" ).toString() );
	f1.ui.actionPlaylista->setText( QMPset->value( "MainWindow/14" ).toString() );
	f1.ui.actionPlaylista_2->setText( QMPset->value( "MainWindow/14" ).toString() );
	f1.ui.a_savMus->setText( QMPset->value( "MainWindow/15" ).toString() );
	f1.ui.actionMuzyka->setText( QMPset->value( "MainWindow/15" ).toString() );
	f1.ui.netA->setText( QMPset->value( "MainWindow/16" ).toString() );
	f1.ui.vup_a->setText( QMPset->value( "MainWindow/17" ).toString() );
	f1.ui.vdwn_a->setText( QMPset->value( "MainWindow/18" ).toString() );
	f1.ui.pwp_a->setText( QMPset->value( "MainWindow/19" ).toString() );
	f1.ui.pwl_a->setText( QMPset->value( "MainWindow/20" ).toString() );
	f1.ui.actionBrak->setText( QMPset->value( "MainWindow/21" ).toString() );
	f1.ui.actionLosowo->setText( QMPset->value( "MainWindow/22" ).toString() );
	f1.ui.actionPowtarzanie_utworu->setText( QMPset->value( "MainWindow/23").toString() );
	f1.ui.actionPowtarzanie_listy->setText( QMPset->value( "MainWindow/24").toString() );
	f1.ui.actionDo_ty_u->setText( QMPset->value( "MainWindow/25" ).toString() );
	f1.ui.playlistButton->setText( QMPset->value( "MainWindow/26" ).toString() );
	f1.ui.playButton->setText( QMPset->value( "MainWindow/27" ).toString() );
	f1.ui.pauseButton->setText( QMPset->value( "MainWindow/28" ).toString() );
	f1.ui.stopButton->setText( QMPset->value( "MainWindow/29" ).toString() );
	f1.ui.prevButton->setText( QMPset->value( "MainWindow/30" ).toString() );
	f1.ui.nextButton->setText( QMPset->value( "MainWindow/31" ).toString() );
	f1.ui.actionPlay->setText( QMPset->value( "MainWindow/27" ).toString()+"	(X)" );
	f1.ui.actionPause->setText( QMPset->value( "MainWindow/28" ).toString()+"	(C)" );
	f1.ui.actionStop->setText( QMPset->value( "MainWindow/29" ).toString()+"	(V)" );
	f1.ui.actionPrevious->setText(QMPset->value( "MainWindow/52").toString()+"	(Z)" );
	f1.ui.actionNext->setText( QMPset->value( "MainWindow/53" ).toString()+"	(B)" );
	f1.ui.menuPomoc->setTitle( QMPset->value( "MainWindow/32" ).toString() );
	f1.ui.menuInne->setTitle( QMPset->value( "MainWindow/33" ).toString() );
	f1.ui.menuPlaylista->setTitle( QMPset->value( "MainWindow/34" ).toString() );
	f1.ui.menuOdtwarzacz->setTitle( QMPset->value( "MainWindow/35" ).toString() );
	f1.ui.menuPlik->setTitle( QMPset->value( "MainWindow/36" ).toString() );
	f1.ui.menuOtw_rz->setTitle( QMPset->value( "MainWindow/37" ).toString() );
	f1.ui.menuZapisz->setTitle( QMPset->value( "MainWindow/38" ).toString() );
	f1.ui.menuOperacje->setTitle( QMPset->value( "MainWindow/39" ).toString() );
	f1.ui.menuPowtarzanie_utworu->setTitle( QMPset->value( "MainWindow/40").toString() );
	f1.ui.delWpisyA->setText( QMPset->value( "MainWindow/41" ).toString() );
	f1.ui.actionWklej->setText( QMPset->value( "MainWindow/42" ).toString() + "	Ctrl+V" );
	f1.ui.actionZa_aduj->setText( QMPset->value( "MainWindow/43" ).toString() + "	Enter" );
	f1.ui.actionZapisz->setText( QMPset->value( "MainWindow/44" ).toString() + "	Alt+S" );
	f1.ui.actionZmie_nazw->setText( QMPset->value( "MainWindow/45" ).toString() + "	Ctrl+R" );
	f1.ui.actionDodaj_list->setText( QMPset->value( "MainWindow/46" ).toString() );
	f1.ui.actionUsu_list->setText( QMPset->value( "MainWindow/47" ).toString() );
	f1.ui.actionCzy_listy->setText( QMPset->value( "MainWindow/48" ).toString() );
	f1.ui.menuLista_playlist->setTitle( QMPset->value( "MainWindow/49" ).toString() );
	f1.ui.sizeA->setText( QMPset->value( "MainWindow/50" ).toString() );
	f1.ui.updatesA->setText( QMPset->value( "MainWindow/51" ).toString() );
	f1.ui.plistA->setText( QMPset->value( "MainWindow/52" ).toString() );
	f1.ui.nlistA->setText( QMPset->value( "MainWindow/53" ).toString() );
	f1.ui.eqB->setText( QMPset->value( "MainWindow/54" ).toString() );
	f1.ui.actionOd_wie->setText( QMPset->value( "MainWindow/55" ).toString() );
	f1.ui.actionZatrzymaj->setText( QMPset->value( "MainWindow/56" ).toString() );
	f1.ui.actionDir->setText( QMPset->value( "MainWindow/57" ).toString() );
	f1.ui.infoB->setText( QMPset->value( "MainWindow/58" ).toString() );
	f1.ui.actionZaznacz->setText( QMPset->value( "MainWindow/59" ).toString() );
	f1.ui.actionOdznacz->setText( QMPset->value( "MainWindow/60" ).toString() );
	f1.ui.actionKopiuj->setText( QMPset->value( "MainWindow/61" ).toString() + "	Ctrl+C" );
	f1.ui.miniVersionB->setToolTip( QMPset->value( "MainWindow/62" ).toString() );
	f1.ui.menuSortuj->setTitle( QMPset->value( "MainWindow/63" ).toString() );
	f1.ui.actionSortMod->setText( QMPset->value( "MainWindow/64" ).toString() );
	f1.ui.actionSortTitle->setText( QMPset->value( "MainWindow/65" ).toString() );
	f1.ui.actionSortLength->setText( QMPset->value( "MainWindow/66" ).toString() );
	f1.ui.copyTitleA->setText( QMPset->value( "MainWindow/67" ).toString() );
	f1.ui.actionSortRandom->setText( QMPset->value( "MainWindow/68" ).toString() );

	fs.ui.applyButton->setText( QMPset->value( "SetupWindow/0" ).toString() );
	fs.ui.langB->setText( QMPset->value( "SetupWindow/1" ).toString() );
	fs.ui.OKButton->setText( QMPset->value( "SetupWindow/2" ).toString() );
	fs.ui.loadPlugButton->setText( QMPset->value( "SetupWindow/3" ).toString() );
	fs.ui.abPB->setText( QMPset->value( "SetupWindow/4" ).toString() );
	fs.ui.opcjePB->setText( QMPset->value( "SetupWindow/5" ).toString() );
	fs.ui.setStyleB->setText( QMPset->value( "SetupWindow/6" ).toString() );
	fs.ui.delSetsButton->setText( QMPset->value( "SetupWindow/7" ).toString() );
	fs.ui.tabWidget_2->setTabText( 2, QMPset->value( "SetupWindow/8" ).toString() );
	fs.ui.updB->setText( QMPset->value( "SetupWindow/9" ).toString() );
	fs.ui.fileStructB->setText( QMPset->value( "SetupWindow/10" ).toString() );
	fs.ui.label_f->setText( QMPset->value( "SetupWindow/11" ).toString() );
	fs.ui.naf1Box->setText( QMPset->value( "SetupWindow/12" ).toString() );
	fs.ui.zVpluginaB->setText( QMPset->value( "SetupWindow/13" ).toString() );
	fs.ui.zIpluginaB->setText( QMPset->value( "SetupWindow/14" ).toString() );
	fs.ui.defB->setText( QMPset->value( "SetupWindow/15" ).toString() );
	fs.ui.label_o->setText( QMPset->value( "SetupWindow/16" ).toString() );
	fs.ui.NxterrBox->setText( QMPset->value( "SetupWindow/17" ).toString() );
	fs.ui.PlaynxtBox->setText( QMPset->value( "SetupWindow/18" ).toString() );
	fs.ui.savplistBox->setText( QMPset->value( "SetupWindow/19" ).toString() );
	fs.ui.pbLBox->setText( QMPset->value( "SetupWindow/20" ).toString() );
	fs.ui.pbRBox->setText( QMPset->value( "SetupWindow/21" ).toString() );
	fs.ui.savposBox->setText( QMPset->value( "SetupWindow/22" ).toString() );
	fs.ui.closeExportOnNxtB->setText( QMPset->value( "SetupWindow/23" ).toString() );
	fs.ui.pmppB->setText( QMPset->value( "SetupWindow/24" ).toString() );
	fs.ui.label->setText( QMPset->value( "SetupWindow/25" ).toString() );
	fs.ui.bladinfoB->setText( QMPset->value( "SetupWindow/26" ).toString() );
	fs.ui.tabWidget->setTabText( 0, QMPset->value( "SetupWindow/27" ).toString() );
	fs.ui.uPLeLB->setText( QMPset->value( "SetupWindow/28" ).toString() );
	fs.ui.uPLeB->setText( QMPset->value( "SetupWindow/29" ).toString() );
	fs.ui.QMPButton->setText( QMPset->value( "SetupWindow/30" ).toString() );
	fs.ui.tabWidget->setTabText( 1, QMPset->value( "SetupWindow/31" ).toString() );
	fs.ui.tabWidget->setTabText( 2, QMPset->value( "SetupWindow/32" ).toString() );
	fs.ui.tabWidget_2->setTabText( 0, QMPset->value( "SetupWindow/33" ).toString() );
	fs.ui.tabWidget_2->setTabText( 1, QMPset->value( "SetupWindow/34" ).toString() );
	fs.ui.dockB->setText( QMPset->value( "SetupWindow/35" ).toString() );
	fs.ui.label_2->setText( QMPset->value( "SetupWindow/36" ).toString() );
	fs.ui.label_3->setText( QMPset->value( "SetupWindow/37" ).toString() );
	fs.ui.label_7->setText( QMPset->value( "SetupWindow/38" ).toString() );
	fs.ui.proxyB->setText( QMPset->value( "SetupWindow/39" ).toString() );
	fs.ui.fileFilterB->setText( QMPset->value( "SetupWindow/40" ).toString() );
	fs.ui.chImgsB->setText( QMPset->value( "SetupWindow/41" ).toString() );
	fs.ui.eoplB->setText( QMPset->value( "SetupWindow/42" ).toString() );
	fs.ui.autoUpdatesB->setText( QMPset->value( "SetupWindow/43" ).toString() );
	fs.ui.svrAddressRestoreB->setText( QMPset->value( "SetupWindow/44" ).toString() );
	fs.ui.unknownTypeB->setText( QMPset->value( "SetupWindow/45" ).toString() );

	fdck.setWindowTitle( QMPset->value( "SetupWindow/35" ).toString() );

	fa.ui.label_6->setText( QMPset->value( "AboutWindow/0" ).toString() );
	fa.ui.label_5->setText( QMPset->value( "AboutWindow/1" ).toString() );
	fa.ui.label_3->setText( QMPset->value( "AboutWindow/2" ).toString() );
	fa.ui.cleanB->setText( QMPset->value( "AboutWindow/3" ).toString() );
	fa.ui.refB->setText( QMPset->value( "AboutWindow/4" ).toString() );
	fa.ui.OKB->setText( QMPset->value( "AboutWindow/5" ).toString() );

	ff.ui.closeB->setText( QMPset->value( "FunctionWindow/0" ).toString() );

	fcp.ui.brB->setText( QMPset->value( "CopyWindow/0" ).toString() );

	fp.ui.addButton->setText( QMPset->value( "PlayListWindow/0" ).toString() );
	fp.ui.actButton->setText( QMPset->value( "PlayListWindow/1" ).toString() );
	fp.ui.odczytajB->setText( QMPset->value( "PlayListWindow/2" ).toString() );
	fp.ui.delButton->setText( QMPset->value( "PlayListWindow/3" ).toString() );
	fp.ui.clrButton->setText( QMPset->value( "PlayListWindow/4" ).toString() );
	fp.ui.zapiszB->setText( QMPset->value( "PlayListWindow/5" ).toString() );
	fp.ui.listPlaylstBox->setText( QMPset->value( "PlayListWindow/6" ).toString() );
	fp.ui.infoMB->setText( QMPset->value( "MainWindow/58" ).toString() );

	fpr.ui.label_4->setText( QMPset->value( "PropWindow/0" ).toString() );
	fpr.ui.label_3->setText( QMPset->value( "PropWindow/1" ).toString() );
	fpr.ui.label->setText( QMPset->value( "PropWindow/2" ).toString() );
	fpr.ui.label_6->setText( QMPset->value( "PropWindow/3" ).toString() );
	fpr.ui.label_2->setText( QMPset->value( "PropWindow/4" ).toString() );
	fpr.ui.label_5->setText( QMPset->value( "PropWindow/5" ).toString() );
	fpr.ui.applyTB->setText( QMPset->value( "PropWindow/6" ).toString() );
	fpr.ui.applyB->setText( QMPset->value( "PropWindow/6" ).toString() );
	fpr.ui.OKB->setText( QMPset->value( "PropWindow/7" ).toString() );
	fpr.ui.fileB->setText( QMPset->value( "PropWindow/8" ).toString() );
	fpr.ui.pluginB->setText( QMPset->value( "PropWindow/9" ).toString() );
	fpr.ui.adresB->setText( QMPset->value( "PropWindow/10" ).toString() );
	fpr.ui.groupBox->setTitle( QMPset->value( "PropWindow/11" ).toString() );

	fl.setWindowTitle( QMPset->value( "SetupWindow/1" ).toString() );

	fst.setWindowTitle( QMPset->value( "SetupWindow/6" ).toString() );
	fst.ui.label->setText( QMPset->value( "StyleWindow/0" ).toString() );
	fst.ui.scB->setText( QMPset->value( "StyleWindow/1" ).toString() );
	fst.ui.ccB->setText( QMPset->value( "StyleWindow/2" ).toString() );
	fst.ui.label_2->setText( QMPset->value( "StyleWindow/3" ).toString() );
	fst.ui.addB->setText( QMPset->value( "StyleWindow/4" ).toString() );
	fst.ui.delB->setText( QMPset->value( "StyleWindow/5" ).toString() );
	fst.ui.label_3->setText( QMPset->value( "StyleWindow/6" ).toString() );
	fst.ui.chNameB->setText( QMPset->value( "StyleWindow/7" ).toString() );
	fst.ui.applyColorsB->setText( QMPset->value( "StyleWindow/8" ).toString() );
	fst.ui.label_4->setText( QMPset->value( "StyleWindow/9" ).toString() );
	fst.ui.label_5->setText( QMPset->value( "StyleWindow/10" ).toString() );
	fst.ui.label_6->setText( QMPset->value( "StyleWindow/11" ).toString() );
	fst.ui.label_7->setText( QMPset->value( "StyleWindow/12" ).toString() );
	fst.ui.label_8->setText( QMPset->value( "StyleWindow/13" ).toString() );
	fst.ui.label_14->setText( QMPset->value( "StyleWindow/14" ).toString() );
	fst.ui.label_16->setText( QMPset->value( "StyleWindow/15" ).toString() );
	fst.ui.use2->setText( QMPset->value( "StyleWindow/16" ).toString() );
	fst.ui.label_9->setText( QMPset->value( "StyleWindow/17" ).toString() );
	fst.ui.label_10->setText( QMPset->value( "StyleWindow/18" ).toString() );
	fst.ui.bHt2->setText( QMPset->value( "StyleWindow/19" ).toString() );
	fst.ui.bSt2->setText( QMPset->value( "StyleWindow/20" ).toString() );
	fst.ui.tabWidget->setTabText( 0, QMPset->value( "StyleWindow/21" ).toString() );
	fst.ui.tabWidget->setTabText( 1, QMPset->value( "StyleWindow/22" ).toString() );
	fst.ui.label_17->setText( QMPset->value( "StyleWindow/23" ).toString() );

	formInfo.button->setText( Texts[66]/**Zamknij*/ );

	searchAction->setText( Texts[11]/**Wyszukuj we wszystkich playlistach*/ );

	language = lnglist[2][ui.langCB->currentIndex()];
	langFile = lnglist[1][ui.langCB->currentIndex()];

	delete QMPset;

	if ( pluginsLoaded )
		f1.setShortCutsandOthers();
}

void FormLang::setLangLibs()
{
	QOut->setLang( langFile );
	if ( equalizer && equalizer->setLang )
		equalizer->setLang( langFile );
	if ( QExport && QExport->setLang )
			QExport->setLang( langFile );
	int w;
	for ( w = 0 ; w < Iplugins.size() ; w++ )
		if ( Iplugins[w]->setLang )
			Iplugins[w]->setLang( langFile );
	for ( w = 0 ; w < Oplugins.size() ; w++ )
		if ( Oplugins[w]->setLang )
			Oplugins[w]->setLang( langFile );
	for ( w = 0 ; w < Eplugins.size() ; w++ )
		if ( Eplugins[w]->setLang )
			Eplugins[w]->setLang( langFile );
	for ( w = 0 ; w < Vplugins.size() ; w++ )
		if ( Vplugins[w]->setLang )
			Vplugins[w]->setLang( langFile );
	for ( w = 0 ; w < Fplugins.size() ; w++ )
		if ( Fplugins[w]->setLang )
			Fplugins[w]->setLang( langFile );
}
