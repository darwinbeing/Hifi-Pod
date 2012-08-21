#include "formPlaylist_2.cpp"

void FormPlaylist::Init()
{
	f1.getFrameSize();
	if ( fpzf1 )
		fp.move( f1.x(), f1.y() + f1.height() + titleBS );
	else if ( !fpnf1 )
		fp.move( fpGeo.x(), fpGeo.y() );
	if ( !fpnf1 )
		fp.resize( fpGeo.width(), fpGeo.height() );
	f1.ui.playlistButton->setChecked(true);
}

void FormPlaylist::showEvent(QShowEvent*)
{
	f1.ui.playlistButton->setChecked(true);
}

void FormPlaylist::closeEvent(QCloseEvent*)
{
	if ( !fpnf1 || !f1.isVisible() )
	{
		fpGeo.setX( x() );
		fpGeo.setY( y() );
		fpGeo.setWidth( width() );
	}
	fpGeo.setHeight( height() );
	f1.ui.playlistButton->setChecked(false);
}

void FormPlaylist::keyPressEvent(QKeyEvent *e)
{
	if ( ( e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter || e->key() == Qt::Key_Right ) && ui.listPlaylst->hasFocus() )
		loadPL();
	else if ( ( e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter || e->key() == Qt::Key_Right ) && titlelist->hasFocus() )
		f1.play();
	else if ( !fpnf1 )
	{
		if ( e->key() == Qt::Key_Escape )
			f1.showplaylist();
		if ( e->modifiers() & Qt::ControlModifier && titlelist->hasFocus() )
		{
			if ( e->key() == 'C' )
				kopiuj();
			else if ( e->key() == 'V' )
				wklej();
		}
	}
	else if ( ui.listPlaylst->hasFocus() )
	{
		if ( e->modifiers() & Qt::ControlModifier )
		{
			if ( e->key() == 'R' )
				renameList();
		}
		else if ( e->modifiers() & Qt::AltModifier )
			if ( e->key() == 'S' )
				savePL();
	}
}

void FormPlaylist::clrplist()
{
	if ( chkListIsLoading() )
		return;

	plistthr.plus = 32;
	plistTimeStr = "00:00";
	fp.ui.plistTime->setText(plistTimeStr);

	playList[0].clear();
	playList[1].clear();
	playList[2].clear();
	playList[3].clear();
	playList[4].clear();

	plistTime = 0;
	titlelist->clear();
	setListLoad();

	if ( !isPlaying )
		f1.clrFile();
}

void FormPlaylist::loadmus_File()
{
	QStringList selfiles;
	selfiles = Func.fileDialog( OPEN_FILES, &f1, "QMPlay - " + Texts[17] /**wybierz pliki*/, curP, Func.getExts( false ) );
	if ( !selfiles.isEmpty() )
	{
		fp.setTcr( Func.nr() );
		addToList(selfiles,-1);
	}
}

void FormPlaylist::loadmus_Dir()
{
	QString selfile = Func.fileDialog( OPEN_DIR, &f1, Texts[31] /**"QMPlay - wybierz katalogi"*/, curP )[0];
	if ( !selfile.isEmpty() && QFile::exists( selfile ) )
	{
		int ch = QMessageBox::No;
		if ( QDir( selfile ).entryList( QDir::AllDirs | QDir::NoDotAndDotDot ).size() )
			ch = QMessageBox::information( this, "QMPlay", Texts[62]/**Czy dodać podkatalogi*/, QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel );
		if ( ch == QMessageBox::No )
			addthr.scat = true;
		else if ( ch == QMessageBox::Yes )
			addthr.scat = false;
		else
			return;
		curP = selfile; //przypisuje się katalog
		addThrDo( (QStringList)selfile );
	}
}

void FormPlaylist::addThrDo( QStringList pths, QStringList DIRlist )
{
	if ( addthr.isRunning() )
		return;

	fp.ui.addingL->setText( Texts[80] /** "Zliczanie wpisów..." */ );
	addthr.pths.clear();
	addthr.pths = pths;
	addthr.DIRlist.clear();
	addthr.DIRlist = DIRlist;

	qApp->setOverrideCursor( QCursor( Qt::BusyCursor ) );
	addthr.start();
}
void FormPlaylist::addThrDo( QStringList DIRlist )
{
	QStringList null;
	addThrDo( null, DIRlist );
}

void FormPlaylist::addToList( QStringList pths, int where )
{
	bool plistthrRunning = plistthr.isRunning();
	if ( plistthrRunning && !plistthr.runTitles )
		return;

	if ( !addthr.added && fileFilter )
		Func.chkFileFormat( pths );

	if ( pths.size() == 0 )
	{
		setListLoad();
		chkPlOnStrt();
		return;
	}

	Func.CURP( pths[0] );

	int tmpC(0);
	if ( !plistthr.isRunning() )
	{
		if ( where <= playList[2].count() && where > -1 && !eoplB )
			plistthr.beginIndex = where;
		else
			plistthr.beginIndex = playList[2].count();

		plistthr.fileCount = pths.count();
		plistthr.currIndex = plistthr.beginIndex;
	}
	else
	{
		ignore_sig = true;
		plistthr.doExit();
		if ( !plistthr.fileCount ) //lista jest odświeżana
		{
			tmpC = playList[2].size() - plistthr.beginIndex;
			plistthr.fileCount = playList[2].size();
		}
		else
			tmpC = plistthr.fileCount;
		plistthr.fileCount += pths.count() - ( plistthr.currIndex - plistthr.beginIndex ); /* dodaje się ilość nowych plików i odejmuje: ilość przetworzonych plików i początkowy index */

	}

	fp.setTcr( Func.nr() );

	QStringList tmpList;
	for ( int i = 0 ; i < pths.count() ; i++ )
		tmpList += "";
	Func.addToList( playList[0], plistthr.beginIndex + tmpC, tmpList );
	Func.addToList( playList[1], plistthr.beginIndex + tmpC, tmpList );
	Func.addToList( playList[2], plistthr.beginIndex + tmpC, pths );
	Func.addToList( playList[3], plistthr.beginIndex + tmpC, tmpList );
	Func.addToList( playList[4], plistthr.beginIndex + tmpC, tmpList );
	tmpList.clear();

	createList();
	titlelist->setCurrentRow( plistthr.tcr );

	plistthr.beginIndex = plistthr.currIndex;

	qApp->setOverrideCursor( QCursor( Qt::BusyCursor ) );
	plistthr.start();
}

void FormPlaylist::stopLoading()
{
	if ( !plistthr.isRunning() && !addthr.isRunning() )
		return;
	if ( addthr.isRunning() )
		addthr.doExit();
	if ( plistthr.isRunning() )
		plistthr.doExit();
	setListLoad();
}

void FormPlaylist::listRef()
{
	if ( chkListIsLoading() )
		return;

	fp.setTcr( Func.nr() );

	playList[0].clear(); //tytuł
	playList[3].clear(); //czas
	for ( int i = 0 ; i < playList[1].size() ; i++ ) //typ
		if ( playList[1][i] != "separator" )
			playList[1][i].clear();

	createList();
	titlelist->setCurrentRow( plistthr.tcr );

	plistTime = 0;

	plistthr.beginIndex = plistthr.fileCount = 0;

	qApp->setOverrideCursor( QCursor( Qt::BusyCursor ) );
	plistthr.start();
}

bool FormPlaylist::listPLstChk( QString tmp2 )
{
	if ( Func.isPlayListExt( Func.getExt( tmp2 ) ) )
	{
		listPLst[0] += tmp2;
		listPLst[1] += fp.plistName(tmp2);
		if ( !addthr.isRunning() )
			createLPList();
		return true;
	}
	return false;
}

void FormPlaylist::createList() //czyści liste, zapisuje zaznaczone pozycje
{
	nrplay_update = 0;

	if ( itemsQueue.size() && playList[2].size() != titlelist->count() )
		itemsQueue.clear();

	QStringList tmpItms;
	for ( int i = 0 ; i < playList[2].size() ; i++ ) //dodawanie wpisów listy
	{
		//sprawdzanie czy wszystko OK
		if ( playList[0].size() <= i )
			playList[0] += playList[2][i] == "" ? "->?<-" : Func.plikbezsciezki( playList[2][i] );
		else if ( playList[0][i].isEmpty() )
			playList[0][i] = playList[2][i] == "" ? "->?<-" : Func.plikbezsciezki( playList[2][i] );

		if ( playList[1].size() <= i )
			playList[1] += "file";
		else if ( playList[1][i].isEmpty() )
			playList[1][i] = "file";

		if ( playList[3].size() <= i )
			playList[3] += "-1";
		else if ( playList[3][i].isEmpty() )
			playList[3][i] = "-1";

		if ( playList[4].size() <= i )
			playList[4] += "0";
		else if ( playList[4][i].isEmpty() )
			playList[4][i] = "0";

		if ( playList[2][i].contains( "separator://" ) )
			playList[1][i] = "separator";
		if ( playList[1][i] == "separator" )
		{
			if ( !playList[2][i].contains( "separator://" ) )
				playList[2][i] = "separator://" + playList[2][i];
			tmpItms << QString::number( i+1 ) + ".	--- " + playList[2][i].right( playList[2][i].length() - 12 ) + " ---";
		}
		else
			tmpItms << getEntryName( i );

		//sprawdzanie czy jest nazwa pliku
		if ( playList[2][i] == file && !nrplay_update )
		{
			nrplay_update = 1;
			nrplay = i;
		}
	}
	titlelist->clear();
	titlelist->addItems( tmpItms );
	tmpItms.clear();

	if ( isPlaying && nrplay_update )
		titlelist->item( nrplay )->setFont( _italic );

	for ( int i = 0 ; i < playList[4].size() ; i++ )
	{
		if ( playList[4][i].toInt() || playList[1][i] == "separator" )
		{
			if ( titlelist->item( i )->font().italic() )
				titlelist->item( i )->setFont( _bolditalic );
			else
				titlelist->item( i )->setFont( _bold );
		}
	}
}

void FormPlaylist::updatePlistEntryIfNeed( int X )
{
	if ( ( Iplug->canUpdateEntry && *Iplug->canUpdateEntry ) || !Iplug->canUpdateEntry )
		updatePlistEntry(X);
}

void FormPlaylist::updatePlistEntry( int X )
{
	if ( MusInfoOpened )
		return;

	if ( playList[1][X] == "separator" )
		return;

	//jeżeli wybrany plugin już nie istnieje (np. jest wylaczony) dla strumieni internetowych
	if ( playList[1][X].size() > 9 && playList[1][X].left(9) == "internet:" && !Func.getMusicFormat( playList[1][X], "" ) )
		playList[1][X] = "internet:";

	//jeżeli ostatni znak to ':' ( tzn. że nie wybrano plugina )
	if ( playList[1][X][ playList[1][X].length() - 1 ] == ':' )
		updateType(X);

	int TIME = -1; //nowy czas
	fp.getMusInfo( playList[2][X], playList[1][X], &TIME, &playList[0][X] );

	int timeToUpdate(0); //różnica czasu
	int oldTIME = playList[3][X].toInt(); //stary czas

	playList[3][X] = QString::number( TIME );

	if ( TIME != oldTIME ) //jeżeli czas jest różny od starego czasu
	{
		if ( TIME >= 0 ) //jezeli czas jest większy od -1
		{
			if ( oldTIME < 0 )
				timeToUpdate = TIME;
			else
				timeToUpdate = TIME - oldTIME; //oblicz różnicę czasów
		}
		else //jezeli czas jest mniejszy od 0
		{
			if ( oldTIME >= 0 ) //jeżeli stary czas jest większy od -1 to ...
				timeToUpdate = -oldTIME; //... czas będzie odjęty
		}
	}

	plistTime += timeToUpdate; //odświeża czas

	fp.updatePlistthrplus(); //uaktualnij czas i plusik na końcu

	updatePlistEntry2(X);
}

void FormPlaylist::updatePlistEntry2( int X )
{
	itemText( X , getEntryName( X ) );
}
QString FormPlaylist::getEntryName( int X )
{
	QString Time;
	if ( playList[3][X].toInt() != -1 )
		Time = " -> " + Func.timeFormat( playList[3][X].toInt(), 0 );
	QString str = QString::number( X+1 ) + ". " + playList[0][X] + Time;
	if ( itemsQueue.contains( X ) )
		str += " [ " + QString::number( itemsQueue.indexOf( X ) + 1 ) + " ] ";
	return str;
}

void FormPlaylist::setTcr( int tcr )
{
	plistthr.tcr = tcr;
	if ( plistthr.tcr < 0 )
		plistthr.tcr = 0;
}

void FormPlaylist::toDown()
{
	if ( plistthr.isRunning() )
		return;

	int w = Func.nr();

	if ( w < 0 || w > playList[2].size()-2 )
		return;

	playList[0].move(w,w+1);
	playList[1].move(w,w+1);
	playList[2].move(w,w+1);
	playList[3].move(w,w+1);
	playList[4].move(w,w+1);

	itemsQueue.clear();
	createList();
	titlelist->setCurrentRow( w+1 );
}

void FormPlaylist::toUp()
{
	if ( plistthr.isRunning() )
		return;

	int w = Func.nr();

	if ( w < 1 )
		return;

	playList[0].move(w,w-1);
	playList[1].move(w,w-1);
	playList[2].move(w,w-1);
	playList[3].move(w,w-1);
	playList[4].move(w,w-1);

	itemsQueue.clear();
	createList();
	titlelist->setCurrentRow( w-1 );
}

void FormPlaylist::delWpis()
{
	if ( chkListIsLoading() )
		return;
	int idx = Func.nr();
	int w = titlelist->selectedItems().size();
	int pt(0);
	int do_updatePlistthrplus(0);

	if ( w == 1 )
	{
		if ( playList[3].size() > idx )
			pt = playList[3][idx].toInt();

		if ( pt > 0 ) //czas
		{
			plistTime -= pt;
			plistTimeStr = Func.timeFormat( plistTime, 0 ) + plistthr.plus;
			fp.ui.plistTime->setText(plistTimeStr);
		}

		if ( playList[3][idx] == "-1" )
			do_updatePlistthrplus = 1;

		playList[0].removeAt( idx );
		playList[1].removeAt( idx );
		playList[2].removeAt( idx );
		playList[3].removeAt( idx );
		playList[4].removeAt( idx );
	}
	else // w != 1
	{
		int count = titlelist->count();
		int z(0);
		for ( int i = count-1 ; i > -1 ; i-- )
		{
			if ( titlelist->item( i )->isSelected() )
			{
				if ( playList[3].size() > i )
					pt = playList[3][i].toInt();

				if ( pt > 0 ) //czas
				{
					plistTime -= pt;
					plistTimeStr = Func.timeFormat( plistTime,0 ) + plistthr.plus;
					fp.ui.plistTime->setText(plistTimeStr);
				}

				if ( playList[3][i] == "-1" )
					do_updatePlistthrplus = 1;

				playList[0].removeAt(i);
				playList[1].removeAt(i);
				playList[2].removeAt(i);
				playList[3].removeAt(i);
				playList[4].removeAt(i);
				z++;
			}
			if ( z >= w )
				break;
		}
	}

	createList();
	if ( idx == 0 )
		titlelist->setCurrentRow( idx );
	else
		titlelist->setCurrentRow( idx-1 );

	if ( do_updatePlistthrplus )
		fp.updatePlistthrplus();

	setListLoad();

	lastPosChMusInfo = -2;
	chMusInfo();
}

void FormPlaylist::plistthrFinished()
{
	fp.ui.plistTime->setText(plistTimeStr);
	if ( !nrplay_update )
	{
		if ( titlelist->currentRow() < 0  )
			titlelist->setCurrentRow( 0 );
	}
	chkPlOnStrt();
	setListLoad();
	if ( piAdd ) //jeżeli dodawany jest adres internetowy do listy
	{
		piAdd = false;
		titlelist->setCurrentRow( titlelist->count() - 1 );
	}
	else
	{
		if ( !ignore_sig )
		{
			if ( signal_lastOnList )
			{
				titlelist->setCurrentRow( titlelist->count() - 1 );
				signal_lastOnList = false;
			}
			if ( signal_Play )
			{
				if ( !isPlaying )
					f1.play();
				signal_Play = false;
			}
		}
		else
			ignore_sig = false;
	}
	qApp->restoreOverrideCursor();
}
void FormPlaylist::titles()
{
	int Count(0);
	if ( !plistthr.fileCount ) //lista jest odświeżana
		Count = playList[2].size();
	else
		Count = plistthr.fileCount + plistthr.beginIndex;
	plistthr.stop = false;
	for ( plistthr.currIndex = plistthr.beginIndex ; plistthr.currIndex < Count ; plistthr.currIndex++ )
	{
		if (plistthr.stop)
		{
			plistthr.stop = false;
			break;
		}

		addingLText( Texts[10] /** "Ladowanie listy: " */ + QString::number(plistthr.currIndex+1-plistthr.beginIndex) + " / " + QString::number(Count-plistthr.beginIndex) );

		if ( playList[1][plistthr.currIndex] != "separator" )
		{
			if ( Func.chkProtocols( playList[2][plistthr.currIndex] ) || playList[2][plistthr.currIndex].left(9) == "plugin://" )
				updateType(plistthr.currIndex);
			else
				playList[1][plistthr.currIndex] = "file";
		}

		updatePlistEntry( plistthr.currIndex );
	}
	plistTimeStr = Func.timeFormat( plistTime, 0 ) + plistthr.plus;
}

void FormPlaylist::_listPlaylst()
{
	if ( fp.ui.listPlaylstBox->isChecked() )
		listplaylist=true;
	else
		listplaylist=false;
	listPlaylst();
}

void FormPlaylist::listPlaylst()
{
	if ( listplaylist )
	{
		fp.ui.listPlaylstBox->setChecked(true);
		fp.ui.listPlaylst->setVisible(true);
	}
	else
	{
		fp.ui.listPlaylstBox->setChecked(false);
		fp.ui.listPlaylst->setVisible(false);
	}
}

void FormPlaylist::focusSearchBarTim()
{
	qApp->setActiveWindow(this);
}
void FormPlaylist::focusSearchBar()
{
	ui.searchBarE->setFocus( Qt::TabFocusReason );
	if ( !fpnf1 )
		QTimer::singleShot( 10, this, SLOT( focusSearchBarTim() ) );
}
void FormPlaylist::searchMus()
{
	if ( chkListIsLoading() )
		return;
	bool _searchInAllLists = searchAction->isChecked();
	if ( ui.listPlaylst->count() <= 1 && _searchInAllLists )
		_searchInAllLists = false;

	if ( !uPLeL && _searchInAllLists )
	{
		QMessageBox::information( this, "QMPlay", Texts[12]/**uPLeL musi być włączone!*/ );
		return;
	}

	QString sName = ui.searchBarE->text();
	if ( sName.isEmpty() )
		return;

	if ( titlelist->count() <= 0 && !_searchInAllLists )
		return;
	else if ( titlelist->count() > 0 )
	{
		int w = Func.nr();

		if ( w < 0 || w == titlelist->count()-1 )
		{
			if ( !_searchInAllLists )
				w = 0;
			else
				w = -10;
		}
		else if ( w+1 < titlelist->count() )
			w++;
		int start = w;

		if ( w != -10 )
		{
			for ( ; w < playList[0].size() ; w++ )
			{
				if ( playList[0][w].contains( sName, Qt::CaseInsensitive ) )
				{
					titlelist->setCurrentRow( w );
					return;
				}
			}
		}
		if ( !_searchInAllLists )
		{
			for ( w = 0 ; w < start ; w++ )
			{
				if ( playList[0][w].contains( sName, Qt::CaseInsensitive ) )
				{
					titlelist->setCurrentRow( w );
					return;
				}
			}
		}
	}
	if ( _searchInAllLists )
	{
		if ( ui.listPlaylst->count() <= 0 )
			return;

		int start = 0;
		if ( ui.listPlaylst->currentRow() < 0 )
			ui.listPlaylst->setCurrentRow(0);
		else
			start = ui.listPlaylst->currentRow()+1;
		if ( start >= ui.listPlaylst->count() )
			start = 0;

		bool second(0);
		QStringList txt;
		for ( int i = start ; i < ui.listPlaylst->count() ; i++ )
		{
			odczytajTytuly( listPLst[0][i], &txt );
			for ( int j = 0 ; j < txt.count() ; j++ )
			{
				if ( txt[j].contains( sName, Qt::CaseInsensitive ) )
				{
					ui.listPlaylst->setCurrentRow( i );
					loadPL();
					while ( plistthr.isRunning() )
						MYsleep( 10 );
					titlelist->setCurrentRow( j );
					return;
				}
			}
			txt.clear();
			if ( i == ui.listPlaylst->count()-1 && !second )
			{
				second = true;
				i = -1;
			}
		}
	}

	QMessageBox::information( this, "QMPlay", Texts[14]/**Nic nie znaleziono!*/ );
}

void FormPlaylist::sel()
{
	int currIdx = titlelist->currentRow();
	int Count = titlelist->count();
	bool *sel = new bool[ Count ];
	for ( int i = 0 ; i < Count ; i++ )
	{
		sel[i] = titlelist->item( i )->isSelected();
		if ( sel[i] )
			playList[4][i] = "1";
	}
	createList();
	titlelist->setCurrentRow(currIdx);
	for ( int i = 0 ; i < Count ; i++ )
		if ( sel[i] )
			titlelist->item( i )->setSelected(true);
	delete[] sel;
}
void FormPlaylist::unsel()
{
	int currIdx = titlelist->currentRow();
	int Count = titlelist->count();
	bool *sel = new bool[ Count ];
	for ( int i = 0 ; i < Count ; i++ )
	{
		sel[i] = titlelist->item( i )->isSelected();
		if ( sel[i] )
			playList[4][i] = "0";
	}
	createList();
	titlelist->setCurrentRow(currIdx);
	for ( int i = 0 ; i < Count ; i++ )
		if ( sel[i] )
			titlelist->item( i )->setSelected(true);
	delete[] sel;
}

void FormPlaylist::sizeB()
{
	int count = titlelist->count();
	long long int fSize(0);
	int time(0);
	for ( int i = 0 ; i < count ; i++ )
	{
		if ( titlelist->item( i )->isSelected() )
		{
			long long int tmpFSize = QFile( playList[2][i] ).size();
			if ( tmpFSize )
				fSize += tmpFSize;
			int tmpTime = playList[3][i].toInt();
			if ( tmpTime > 0 )
				time += tmpTime;
		}
	}
	int Count = titlelist->selectedItems().size();
	QMessageBox::information( this, "QMPlay", Texts[85]+": "+QString::number(Count)+"\n"+Texts[86]+": "+Func.getFSize(fSize)+"\n"+Texts[129]+": "+Func.timeFormat(time,false) );
}

void FormPlaylist::opnWlasciwosci()
{
	if ( fpr.isVisible() )
	{
		fprPos = fpr.pos();
		fpr.Init();
	}
}

void FormPlaylist::wlasciwosci()
{
	int X = Func.nr();
	if ( X >= 0 && playList[1][X] == "separator" )
	{
		bool ok(0);
		QString separatorName = playList[2][X];
		separatorName.remove( "separator://" );
		QString aName = QInputDialog::getText( this, "QMPlay", Texts[13]/**Podaj nazwe separatora*/ , QLineEdit::Normal, separatorName, &ok );
		if ( !aName.isEmpty() && ok )
		{
			playList[2][X] = "separator://" + aName;
			createList();
			titlelist->setCurrentRow( X );
		}
		return;
	}

	if ( fpr.isVisible() )
	{
		opnWlasciwosci();
		return;
	}

	if ( Func.nr() < 0 )
		return;

	if ( !fpnf1 )
		fpr.setParent( &f1 );
	else
		fpr.setParent( f1.ui.plist );
	fpr.setWindowFlags( Qt::Dialog );
	fpr.Init();
	fpr.show();
}

void FormPlaylist::renameList()
{
	if ( ui.listPlaylst->currentRow() < 0 )
		return;
	bool ok;
	int w = ui.listPlaylst->currentRow();
	QString nname = QInputDialog::getText(this,"QMPlay",Texts[15] /** "Wprowadz nowa nazwe" */, QLineEdit::Normal, listPLst[1][w], &ok);
	if ( ok && !nname.isEmpty() )
	{
		listPLst[1][w] = nname;
		fp.ui.listPlaylst->clear();
		fp.ui.listPlaylst->addItems( listPLst[1] );
		fp.ui.listPlaylst->setCurrentRow(w);
	}
}

void FormPlaylist::savePL()
{
	if ( ui.listPlaylst->count() < 1 )
		return;
	int w = ui.listPlaylst->currentRow();
	if ( !listPLst[0][w].isEmpty() )
		fp.zapiszListe( listPLst[0][w], "*" + Func.getExt( listPLst[0][w] ), false );
}

void FormPlaylist::dellist()
{
	listPLst[0].removeAt( fp.ui.listPlaylst->currentRow() );
	listPLst[1].removeAt( fp.ui.listPlaylst->currentRow() );
	int w = fp.ui.listPlaylst->currentRow()-1;
	fp.ui.listPlaylst->clear();
	fp.ui.listPlaylst->addItems( listPLst[1] );
	fp.ui.listPlaylst->setCurrentRow(w);
}

void FormPlaylist::clrlist()
{
	listPLst[0].clear();
	listPLst[1].clear();
	fp.ui.listPlaylst->clear();
}

void FormPlaylist::prevPL()
{
	if ( ui.listPlaylst->count() < 1 || ui.listPlaylst->currentRow() <= 0 )
		return;
	ui.listPlaylst->setCurrentRow( ui.listPlaylst->currentRow() - 1 );
	loadPL();
}
void FormPlaylist::nextPL()
{
	if ( ui.listPlaylst->count() < 1 || ui.listPlaylst->currentRow() >= ui.listPlaylst->count() - 1 )
		return;
	ui.listPlaylst->setCurrentRow( ui.listPlaylst->currentRow() + 1 );
	loadPL();
}
void FormPlaylist::loadPL()
{
	if ( !listPLst[0].isEmpty() && fp.ui.listPlaylst->currentRow() >= 0 )
		odczytajListe( listPLst[0][ fp.ui.listPlaylst->currentRow() ] );
}

QString FormPlaylist::plistName( QString file )
{
	QString TMP, TMP2;
	int i;

	TMP  = Func.plikbezsciezki(file);
	TMP2 = Func.plikbezsciezki(file);

	for ( i = TMP.length() ; i > 0 ; i-- )
		if ( TMP[i] == '.' )
			break;

	TMP2 = TMP2.right( TMP2.length() - i );

	if ( !Func.isPlayListExt( TMP2.toLower() ) )
		return "?: "+TMP;

	TMP.truncate( i );

	return TMP;
}

void FormPlaylist::createLPList()
{
	int crow = fp.ui.listPlaylst->currentRow();
	if ( crow < 0 )
		crow = 0;
	fp.ui.listPlaylst->clear();
	fp.ui.listPlaylst->addItems( listPLst[1] );
	fp.ui.listPlaylst->setCurrentRow(crow);
}

void FormPlaylist::loadlist()
{
	QStringList selfiles;
	selfiles = Func.fileDialog( OPEN_FILES, &f1, "QMPlay - " + Texts[17]/**Wybierz pliki*/, curP, Func.getPlistExts() );
	if ( !selfiles.isEmpty() )
	{
		listPLst[0] += selfiles;
		for ( int w = 0 ; w < selfiles.size() ; w++ )
			listPLst[1] += fp.plistName(selfiles[w]);
		createLPList(); //laduje liste playlist
		Func.CURP(selfiles[0]);
	}
}

void FormPlaylist::chkPlOnStrt()
{
	if ( plOnstrt )
	{
		plOnstrt = false;
		f1.play();
	}
}

void FormPlaylist::thrListRef2()
{
	plistthr.stop = false;
	for ( int i = 0 ; i < playList[2].size() ; i++ )
	{
		if ( plistthr.stop )
		{
			plistthr.stop = false;
			break;
		}

		addingLText( Texts[10] /** "Ladowanie listy: " */ +QString::number(i+1)+" / " + QString::number(playList[2].size()) );

		if ( Func.chkProtocols( playList[2][i] ) || playList[2][i].left(9) == "plugin://" )
			updateType(i);
		else if ( playList[1][i] != "separator" )
			playList[1][i] = "file";

		titlesTime( playList[3][i].toInt() );
	}
	plistthr.runTitles = true;
	plistTimeStr = Func.timeFormat( plistTime,0 ) + plistthr.plus;
}

void FormPlaylist::listRef2() //tworzenie playlisty pls i m3u
{
	plistthr.runTitles = false;
	fp.setTcr( nrplay );
	createList();
	titlelist->setCurrentRow( plistthr.tcr );

	qApp->setOverrideCursor( QCursor( Qt::BusyCursor ) );
	plistthr.start();
}

void FormPlaylist::updateType(int i)
{
	//rozpoznaje który plugin obsługuje ten strumień i zwraca jego nazwę w postaci QString, w przeciwnym wypadku zwróci ""
	if ( Func.chkProtocols( playList[2][i] ) && playList[1][i].length() <= 9 && !piAdd )
		playList[1][i] = "internet:" + Func.checkInternetFormat( playList[2][i] );
	else if ( Func.chkProtocols( playList[2][i] ) && playList[1][i].length() <= 9 && piAdd )
		playList[1][i] = "internet:";
	else if ( playList[2][i].left(9) == "plugin://" )
		playList[1][i] = "plugin:" + playList[2][i].right( playList[2][i].size() - 9 );
}

void FormPlaylist::titlesTime(int tmpTime)
{
	if ( tmpTime < 0 )
	{
		if ( tmpTime == -1 )
			plistthr.plus='+';
		tmpTime = 0;
	}
	plistTime += tmpTime;
}

void FormPlaylist::updatePlistthrplus()
{
	plistthr.plus = 32;
	for ( int i = 0 ; i < playList[3].size() ; i++ )
	{
		if ( playList[3][i].toInt() == -1 && playList[1][i] != "separator" )
		{
			plistthr.plus = '+';
			break;
		}
	}
	plistTimeStr = Func.timeFormat( plistTime,0 ) + plistthr.plus;
	plistTimeText( plistTimeStr );
}

void FormPlaylist::odczytajB()
{
	QString selfile;
	selfile = Func.fileDialog( OPEN_FILE, &f1, "QMPlay - "+Texts[32] /**Wybierz playliste*/, curP, Func.getPlistExts() )[0];
	fp.odczytajListe(selfile);
}

void FormPlaylist::zapiszB()
{
	QString selfile,selfilter;
	selfile = Func.fileDialog( SAVE_FILE, &f1, "QMPlay - "+Texts[33] /**Zzapisz playliste*/, curP, Func.getPlistExts( false ), &selfilter )[0];
	if ( selfilter.isEmpty() )
		selfilter = "*"+Func.getExt(selfile);
	fp.zapiszListe(selfile,selfilter,true);
}

void FormPlaylist::setListLoad()
{
	ui.addingL->setText( Texts[6] /** "Lista zaladowana: " */ +QString::number(titlelist->count()));
	lastPosChMusInfo = -2;
	chMusInfo();
}

void FormPlaylist::chMusInfo() //daje podgląd obrazka muzyki
{
	if ( !pluginsLoaded )
		return;
	int X = Func.nr();
	if ( lastPosChMusInfo != X )
	{
		if ( lastPosChMusInfo != -1 )
		{
			if ( chImgs ) //jeżeli w opcjach włączono obsługę obrazków z wtyczek
			{
				timChImgs.stop();
				timChImgs.start(250);
			}
			else if ( !chImgsOnce )
			{
				ui.infoMB->setIcon( QMPIcon );
				if ( mQ.standardIcon )
					mQ.ui.okienko->setPixmap( QMPIconPix );
				chImgsOnce = true;
			}
		}
		lastPosChMusInfo = X;
	}
}
void FormPlaylist::chMusInfoTimer()
{
	timChImgs.stop();
	int X = Func.nr();

	InputPlugin *plugStruct = NULL;
	if ( Func.chkFNr( X ) )
		plugStruct = Func.getMusicFormat( playList[1][X], playList[2][X] );
	if ( !plugStruct )
	{
		ui.infoMB->setIcon( QMPIcon );
		if ( mQ.standardIcon )
			mQ.ui.okienko->setPixmap( QMPIconPix );
		return;
	}

	chImgsOnce = false;

	QPixmap pix;
	Func.getFromPlugInfo( playList[2][X], pix, plugStruct );

	ui.infoMB->setIcon( QIcon( pix ) );
	if ( mQ.standardIcon )
		mQ.ui.okienko->setPixmap( pix );
}

void FormPlaylist::addSeparator()
{
	bool ok(0);
	QString aName = QInputDialog::getText( this, "QMPlay", Texts[13]/**Podaj nazwe separatora*/ , QLineEdit::Normal, "", &ok );
	if ( !aName.isEmpty() && ok )
		addToList( QStringList( "separator://" + aName ), Func.nr() + 1 );
}
