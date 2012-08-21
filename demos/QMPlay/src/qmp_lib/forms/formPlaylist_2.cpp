void FormPlaylist::dragEnterEvent(QDragEnterEvent *event)
{
	if ( ( event->mimeData()->hasText() || event->mimeData()->hasUrls() ) )
		event->acceptProposedAction();
}
void FormPlaylist::dropEvent(QDropEvent *event)
{
	doMimeData( event->mimeData() );
}
void FormPlaylist::wklej()
{
	doMimeData( clipboard->mimeData() );
}
void FormPlaylist::doMimeData(const QMimeData *mimeData)
{
	QStringList pths, li, DIRlist;
	QString tmp, tmp2;
	QList<QUrl> urls;
	int len(0);
	QDir iDir;

	fp.setTcr( Func.nr() );

	if ( mimeData->hasUrls() )
	{
		urls = mimeData->urls();
		len = urls.size();
		for ( int i = 0 ; i < len ; i++ )
			li += urls[i].toString();
	}
	else if ( mimeData->hasText() )
	{
		li  = mimeData->text().split( QString(10), QString::SkipEmptyParts );
		len = li.count();
	}
	for ( int i = 0 ; i < len ; i++ )
	{
		tmp = li[i];
		if ( tmp.isEmpty() )
			continue;

	#ifdef Q_WS_WIN
		tmp.replace('\\','/');
	#endif

		tmp2 = tmp;
		tmp2.truncate(7);
		if ( tmp2 == "file://" )
		{
			tmp2.clear();
		#ifdef Q_WS_WIN
			if ( tmp[7] != '/' )
				for ( int l = 5 ; l < tmp.length() ; l++ )
					tmp2[l-5] = tmp[l];
			else
				for ( int l = 8 ; l < tmp.length() ; l++ )
					tmp2[l-8] = tmp[l];
		#else
			for ( int l = 7 ; l < tmp.length() ; l++ )
				tmp2[l-7] = tmp[l];
		#endif
		}
		else
			tmp2 = tmp;

		iDir = tmp2;
		if ( iDir.exists() )
		{
			DIRlist += tmp2;
			continue;
		}

		if ( !listPLstChk( tmp2 ) )
			pths += tmp2;
	}

	if ( DIRlist.size() > 0 )
	{
		int ch = QMessageBox::information( this, "QMPlay", Texts[62]/**Czy dodać podkatalogi*/, QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel );
		if ( ch != QMessageBox::Cancel )
		{
			if ( ch == QMessageBox::No )
				addthr.scat = true;
			else
				addthr.scat = false;
			addthr.fromDnD = true;
			addThrDo( pths, DIRlist );
			return;
		}
	}

	fp.addToList( pths, Func.nr()+1 );
}

void FormPlaylist::kopiuj()
{
	QMimeData *mimeData = new QMimeData;
	QList<QUrl> urls = getCopyData();
	mimeData->setUrls( urls );
	urls.clear();
	clipboard->setMimeData(mimeData);
}

void FormPlaylist::getMusInfo( QString file, QString type, int *time, QString *title )
{
	if ( ( !time && !title ) || MusInfoOpened )
		return;

	MusInfoOpened = true;

	if ( time )
		*time = -2;
	if ( title )
		title->clear();

	if ( type == "file" )
	{
		if ( !QFile::exists( file ) )
		{
			if ( title )
				*title = Func.plikbezsciezki(file);
			MusInfoOpened = false;
			return;
		}

		bool OK = false;
		bool isExtOK = Func.getExts( true ).contains( Func.getExt( file, true ) );
		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			if ( !fileStruct || ( fileStruct && unknownType && isExtOK ) )
			{
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && Func.checkFormat( *Iplugins[w]->formatSupport, file ) )
					OK = true;
			}
			else if ( !FileFormatSupportOpened ) //jeżeli rozpoznawanie po strukturze pliku
			{
				FileFormatSupportOpened = true;
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && Iplugins[w]->FileFormatSupport && Iplugins[w]->FileFormatSupport( file.toUtf8() ) )
					OK = true;
				FileFormatSupportOpened = false;
			}
			if ( OK )
			{
				if ( Iplugins[w]->getMusInfo )
					Iplugins[w]->getMusInfo( file.toUtf8(), 0, time, title );
				break;
			}
		}
		if ( title && title->isEmpty() )
			*title = Func.plikbezsciezki( file );
		MusInfoOpened = false;
		return;
	}

	if ( type.left( 7 ) == "plugin:" || type.left( 9 ) == "internet:" )
	{
		int Type(0);
		QString typTmp = type, TITLE;
		if ( type.left( 7 ) == "plugin:" )
		{
			TITLE = Func.getFNamePlugin( typTmp, 0 );
			typTmp = Func.getTypePlugin( typTmp );
			Type = 1;
		}
		if ( type.left( 9 ) == "internet:" )
		{
			typTmp = typTmp.right( typTmp.size() - 9 );
			Type = 2;
			TITLE = file;
		}

		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			if ( typTmp == (QString)Iplugins[w]->pluginInfo->Name )
			{
				if ( Iplugins[w]->pluginInfo->swOnOff(0) )
				{
					if ( Iplugins[w]->getMusInfo )
					{
						QString TMP = file;
						if ( TMP.left( 9 ) == "plugin://" )
							TMP = Func.getFNamePlugin( TMP, 1 );
						Iplugins[w]->getMusInfo( TMP.toUtf8(), Type, time, title );
					}
					if ( title && title->isEmpty() )
						*title = TITLE;
				}
				MusInfoOpened = false;
				return;
			}
		}

		if ( title )
			*title = TITLE;
	}
	MusInfoOpened = false;
}

void FormPlaylist::pluginOptions()
{
	InputPlugin *iplug = NULL;
	if ( Func.chkFNr( Func.nr() ) )
		iplug = Func.getMusicFormat( playList[1][Func.nr()], playList[2][Func.nr()] );
	if ( iplug && iplug->showOptions )
		iplug->showOptions();
}

void FormPlaylist::chFpnf1()
{
	bool y(0);
	if ( fp.isVisible() )
	{
		f1.showplaylist();
		y=true;
	}
	fpnf1 = !fpnf1;
	if ( fpnf1 )
		fpzf1 = false;
	if ( y )
		f1.showplaylist();
}
void FormPlaylist::chFpzf1()
{
	bool y(0);
	if ( fp.isVisible() )
	{
		f1.showplaylist();
		y=true;
	}
	fpzf1 = !fpzf1;
	if ( y )
		f1.showplaylist();
}
void FormPlaylist::_mnuPlistWindow()
{
	mnuPlistWindow.clear();

	QAction *act;

	act = mnuPlistWindow.addAction( Texts[116] /*Pokazuj w oknie glownym*/, this, SLOT( chFpnf1() ) );
	act->setCheckable( true );
	act->setChecked( fpnf1 );

	act = mnuPlistWindow.addAction( "   "+Texts[117] /*Przesuwaj razem*/, this, SLOT( chFpzf1() ) );
	act->setCheckable( true );
	act->setChecked( fpzf1 );
	if ( !fpnf1 )
		act->setEnabled( true );
	else
		act->setEnabled( false );

	mnuPlistWindow.popup( QCursor::pos() );
}

void FormPlaylist::titlelstMenu()
{
	tLMenu.clear();

	tLMenu.addAction( f1.ui.actionPlay );
	tLMenu.addSeparator();
	tLMenu.addAction( f1.ui.actionWyszukaj );
	tLMenu.addSeparator();
	tLMenu.addMenu( &menuPlistAct );
	tLMenu.addSeparator();

	QString selItms, wklejItms;
	if ( titlelist->selectedItems().count() )
		selItms = " -> " + QString::number( titlelist->selectedItems().count() ) + "	Ctrl+C";
	if ( clipboard->mimeData()->hasUrls() )
		wklejItms = " -> " + QString::number( clipboard->mimeData()->urls().count() ) + "	Ctrl+V";
	else if ( clipboard->mimeData()->hasText() )
		wklejItms = " -> " + QString::number( clipboard->mimeData()->text().count() ) + "	Ctrl+V";
	tLMenu.addAction( Texts[57] /* Kopiuj */ + selItms,&fp,SLOT(kopiuj()));
	tLMenu.addAction( Texts[60] /* Wklej */ + wklejItms,&fp,SLOT(wklej()));
	tLMenu.addSeparator();

	tLMenu.addAction( f1.ui.actionZaznacz );
	tLMenu.addAction( f1.ui.actionOdznacz );
	tLMenu.addSeparator();

	tLMenu.addMenu( &menuAdd );
	tLMenu.addAction( f1.ui.delWpisyA );
	tLMenu.addSeparator();

	tLMenu.addMenu( f1.ui.menuSortuj );
	tLMenu.addSeparator();

	tLMenu.addAction( f1.ui.actionClrplist );
	tLMenu.addSeparator();

	tLMenu.addAction( f1.ui.actionInformacje_2 );
	tLMenu.addSeparator();

	tLMenu.addAction( Texts[43] /** "Zapisz muzyke" */+ "	Ctrl+S" , &f1 , SLOT( savMus() ) );
	tLMenu.addAction( f1.ui.aWAV );
	tLMenu.addSeparator();

	tLMenu.addAction( Texts[45] /** "Zapisz playliste" */ + "	Ctrl+T", &fp , SLOT( zapiszB() ) );
	tLMenu.addAction( Texts[46] /** "Odczytaj playliste" */ + "	Ctrl+G", &fp , SLOT( odczytajB() ) );

	tLMenu.addSeparator();
	tLMenu.addAction( f1.ui.sizeA );
	tLMenu.addSeparator();

	InputPlugin *iplug = NULL;
	if ( Func.chkFNr( Func.nr() ) )
		iplug = Func.getMusicFormat( playList[1][Func.nr()], playList[2][Func.nr()] );
	if ( iplug && iplug->showOptions )
	{
		tLMenu.addAction( Texts[100] + ": " + (QString)iplug->pluginInfo->Name /*Plugin options*/ ,&fp,SLOT(pluginOptions()));
		tLMenu.addSeparator();
	}

	tLMenu.addAction( f1.ui.wlasciwosciA );

	tLMenu.popup( QCursor::pos() );
	fp.setTcr( Func.nr() );
}

void FormPlaylist::plistlstMenu()
{
	pLMenu.clear();

	pLMenu.addAction( f1.ui.NewPLAct );
	pLMenu.addSeparator();
	pLMenu.addAction( f1.ui.actionZa_aduj );
	pLMenu.addAction( f1.ui.actionZapisz );
	pLMenu.addSeparator();
	pLMenu.addAction( f1.ui.actionZmie_nazw );
	pLMenu.addSeparator();
	pLMenu.addAction( f1.ui.actionDodaj_list );
	pLMenu.addAction( f1.ui.actionUsu_list );
	pLMenu.addSeparator();
	pLMenu.addAction( f1.ui.actionCzy_listy );

	pLMenu.popup( QCursor::pos() );
}

void FormPlaylist::newPL()
{
	QString selfile, selfilter;
	selfile = Func.fileDialog( SAVE_FILE, &f1, "QMPlay - " + Texts[16] /**Utworz nowa playliste*/, curP, Func.getPlistExts( false ), &selfilter )[0];
	if ( selfile.isEmpty() )
		return;

	bool OK = false;

	if ( selfilter == "*.qplst" )
	{
		QString TMP = selfile.right( 6 ).toLower();
		if ( TMP != ".qplst" )
			selfile += ".qplst";

		QSettings* plists = new QSettings( selfile , QSettings::IniFormat );
		plists->setValue("Plist/isQMPPlist" , 1 );
		plists->setValue("Plist/items_titlelist_+", QChar(32) );
		delete plists;

		OK = true;
	}

	if ( !OK )
	{
		for ( int i = 0 ; i < Pplugins.size() ; i++ )
			if ( Pplugins[i]->create( selfile, selfilter ) )
			{
				OK = true;
				break;
			}
	}

	if ( OK )
	{
		listPLst[0] += selfile;
		listPLst[1] += fp.plistName( selfile );
		createLPList();

		Func.CURP( selfile );
	}
}

bool FormPlaylist::chkListIsLoading()
{
	if ( plistthr.isRunning() || addthr.isRunning() )
	{
		QMessageBox::information( this, "QMPlay", Texts[132] /*Lista jest teraz ładowana*/ );
		return true;
	}
	return false;
}

void FormPlaylist::odczytajTytuly( QString selfile, QStringList *tL )
{
	_odczytajListe( selfile, tL );
}

void FormPlaylist::odczytajListe( QString selfile )
{
	_odczytajListe( selfile, NULL );
}

void FormPlaylist::_odczytajListe( QString selfile, QStringList *tL )
{
	if ( chkListIsLoading() )
		return;
	if ( selfile.isEmpty() )
		return;
	if ( !QFile::exists( selfile ) )
		return;

	if ( selfile.right(6).toLower() == ".qplst" )
	{
		QSettings *plists = new QSettings( selfile, QSettings::IniFormat );

		if ( !plists->value("Plist/isQMPPlist").toBool() )
		{
			delete plists;
			return;
		}

		if ( tL )
		{
			*tL += plists->value("Plist/items_titlelist").toStringList();

			delete plists;
			return;
		}

		fp.clrplist();

		playList[1] += plists->value("Plist/items_type").toStringList();
		playList[3] += plists->value("Plist/items_times").toStringList();
		playList[2] += plists->value("Plist/items").toStringList();
		playList[0] += plists->value("Plist/items_titlelist").toStringList();
		playList[4] += plists->value("Plist/selItms").toStringList();
		plistTime = plists->value("Plist/items_titlelist_timeI" ).toInt();

		ycPos = true;

		createList();

		if ( !nrplay_update ) //jeżeli nie znalazł odtwarzanego pliku to zaznacza zapisany na playliście
		{
			int _curplay = plists->value("Plist/curplay").toInt();
			if ( _curplay < 0 )
				_curplay = 0;
			if ( _curplay > titlelist->count() - 1 )
				_curplay = 0;
			titlelist->setCurrentRow( _curplay );
		}
		else
			titlelist->setCurrentRow( nrplay );

		plistthr.plus = plists->value("Plist/items_titlelist_+" ).toChar();

		if ( plistthr.plus != '+' )
			plistthr.plus = 32;

		fp.ui.plistTime->setText( Func.timeFormat( plistTime, 0 ) + plistthr.plus );

		setListLoad();

		if ( isPlaying & nrplay_update )
		{
			if ( titlelist->item( nrplay )->font().bold() )
				titlelist->item( nrplay )->setFont( _bolditalic );
			else
				titlelist->item( nrplay )->setFont( _italic );
		}

		delete plists;

		chkPlOnStrt();

		return;
	}

	for ( int i = 0 ; i < Pplugins.size() ; i++ )
	{
		if ( Pplugins[i]->load( selfile, playList, tL, uPLeL ) )
		{
			if ( !tL )
			{
				ycPos = true;
				if ( uPLeL )
					fp.listRef2();
				else
					fp.listRef();
			}
			break;
		}
	}
}

void FormPlaylist::zapiszListe( QString selfile, QString selfilter, bool chPth )
{
	if ( selfile.isEmpty() )
		return;

	if ( selfilter == "*.qplst" )
	{
		QString TMP = selfile.right( 6 );
		if ( TMP != ".qplst" )
			selfile += ".qplst";
		QSettings* plists = new QSettings( selfile , QSettings::IniFormat );

		plists->remove("Plist");

		plists->setValue("Plist/isQMPPlist" , 1 );

		plists->setValue("Plist/items", playList[2] );
		plists->setValue("Plist/items_titlelist", playList[0] );
		plists->setValue("Plist/items_times", playList[3] );
		plists->setValue("Plist/items_type", playList[1] );
		plists->setValue("Plist/selItms", playList[4] );
		plists->setValue("Plist/items_titlelist_timeI" , plistTime );

		plists->setValue("Plist/curplay", Func.nr());

		plists->setValue("Plist/items_titlelist_+", plistthr.plus );

		if ( chPth )
			Func.CURP(selfile);

		delete plists;

		return;
	}

	for ( int i = 0 ; i < Pplugins.size() ; i++ )
	{
		if ( Pplugins[i]->save( selfile, selfilter, playList ) )
		{
			if ( chPth )
				Func.CURP( selfile );
			break;
		}
	}
}

void FormPlaylist::pu0()
{
	f1.ui.actionBrak->setChecked(true);
	f1.ui.actionLosowo->setChecked(false);
	f1.ui.actionPowtarzanie_utworu->setChecked(false);
	f1.ui.actionPowtarzanie_listy->setChecked(false);
	f1.ui.actionDo_ty_u->setChecked(false);
	po = 0;
}

void FormPlaylist::pu1()
{
	f1.ui.actionBrak->setChecked(false);
	f1.ui.actionLosowo->setChecked(true);
	f1.ui.actionPowtarzanie_utworu->setChecked(false);
	f1.ui.actionPowtarzanie_listy->setChecked(false);
	f1.ui.actionDo_ty_u->setChecked(false);
	po = 1;
}

void FormPlaylist::pu2()
{
	f1.ui.actionBrak->setChecked(false);
	f1.ui.actionLosowo->setChecked(false);
	f1.ui.actionPowtarzanie_utworu->setChecked(true);
	f1.ui.actionPowtarzanie_listy->setChecked(false);
	f1.ui.actionDo_ty_u->setChecked(false);
	po = 2;
}

void FormPlaylist::pu3()
{
	f1.ui.actionBrak->setChecked(false);
	f1.ui.actionLosowo->setChecked(false);
	f1.ui.actionPowtarzanie_utworu->setChecked(false);
	f1.ui.actionPowtarzanie_listy->setChecked(true);
	f1.ui.actionDo_ty_u->setChecked(false);
	po = 3;
}

void FormPlaylist::pu4()
{
	f1.ui.actionBrak->setChecked(false);
	f1.ui.actionLosowo->setChecked(false);
	f1.ui.actionPowtarzanie_utworu->setChecked(false);
	f1.ui.actionPowtarzanie_listy->setChecked(false);
	f1.ui.actionDo_ty_u->setChecked(true);
	po = 4;
}

void FormPlaylist::LOAD()
{
	titlelist = new titleList(ui.frame);
	titlelist->setObjectName("titlelist");
	titlelist->setContextMenuPolicy(Qt::CustomContextMenu);
	titlelist->setSelectionMode(QAbstractItemView::ExtendedSelection);
	titlelist->setDragDropMode(QAbstractItemView::DragDrop);

	ui.gridLayout_3->addWidget(titlelist, 0, 1, 1, 1);

	addAction( f1.ui.actionPlay );
	addAction( f1.ui.actionWyszukaj );
	addAction( f1.ui.actionZaznacz );
	addAction( f1.ui.actionOdznacz );
	addAction( f1.ui.delWpisyA );
	addAction( f1.ui.actionClrplist );
	addAction( f1.ui.actionInformacje_2 );
	addAction( f1.ui.a_savMus );
	addAction( f1.ui.aWAV );
	addAction( f1.ui.actionPlaylista_2 );
	addAction( f1.ui.actionPlaylista );
	addAction( f1.ui.sizeA );
	addAction( f1.ui.wlasciwosciA );

	addAction( f1.ui.NewPLAct );
	addAction( f1.ui.actionZa_aduj );
	addAction( f1.ui.actionZapisz );
	addAction( f1.ui.actionZmie_nazw );
	addAction( f1.ui.actionDodaj_list );
	addAction( f1.ui.actionUsu_list );
	addAction( f1.ui.actionCzy_listy );

	mnuSearch.addAction( searchAction );
}

void FormPlaylist::chPlistTimeText(QString plistTimeStr)
{
	fp.ui.plistTime->setText(plistTimeStr);
}
void FormPlaylist::chItemText(int X,QString s)
{
	titlelist->item(X)->setText( s );
}
void FormPlaylist::chAddingLText(QString s)
{
	ui.addingL->setText( s );
}

template < class T, class _NULLVALUE >
void FormPlaylist::sortDattebayo( T sList, _NULLVALUE NULLVALUE )
{
	qSort( sList[1].begin(), sList[1].end() );

	QStringList sL0, sL1, sL2, sL3, sL4;
	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		sL0 += "";
		sL1 += "";
		sL2 += "";
		sL3 += "";
		sL4 += "";
	}

	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		int idx = sList[1].indexOf( sList[0][i] );
		if ( idx >= 0 )
		{
			sL0[ idx ] = playList[0][i];
			sL1[ idx ] = playList[1][i];
			sL2[ idx ] = playList[2][i];
			sL3[ idx ] = playList[3][i];
			sL4[ idx ] = playList[4][i];
			sList[1][idx] = NULLVALUE; //czyszczenie
		}
	}

	playList[0].clear();
	playList[1].clear();
	playList[2].clear();
	playList[3].clear();
	playList[4].clear();

	playList[0] = sL0;
	playList[1] = sL1;
	playList[2] = sL2;
	playList[3] = sL3;
	playList[4] = sL4;

	sL0.clear();
	sL1.clear();
	sL2.clear();
	sL3.clear();
	sL4.clear();

	int cR = titlelist->currentRow();
	fp.createList();
	if ( nrplay_update )
		titlelist->setCurrentRow( nrplay );
	else
		titlelist->setCurrentRow( cR );
}
void FormPlaylist::sortMod()
{
	QList< quint64 > sList[2];
	quint64 tmp = 0;
	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		QFileInfo fInfo( playList[2][i] );
		tmp = fInfo.lastModified().toTime_t();
		if ( tmp == 4294967295LL )
			tmp = 4294967296LL;
		sList[0] += tmp;
		sList[1] += tmp;
	}
	sortDattebayo( sList, 4294967297LL );
}
void FormPlaylist::sortLength()
{
	QList< int > sList[2];
	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		sList[0] += playList[3][i].toInt();
		sList[1] += playList[3][i].toInt();
	}
	sortDattebayo( sList, -3 );
}
void FormPlaylist::sortTitle()
{
	QList< QString > sList[2];
	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		sList[0] += playList[0][i];
		sList[1] += playList[0][i];
	}
	sortDattebayo( sList, "" );
}
void FormPlaylist::sortRandom()
{
	QList< int > sList[2];
	int tmp;
	QList< int > tmpInt;
	for ( int i = 0 ; i < playList[2].count() ; i++ )
	{
		do
			tmp = rand()%playList[2].count();
		while ( tmpInt.contains( tmp ) );
		tmpInt += tmp;
		sList[0] += tmp;
		sList[1] += tmp;
	}
	sortDattebayo( sList, -1 );
	tmpInt.clear();
}
