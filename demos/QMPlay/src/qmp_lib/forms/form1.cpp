void Form1::wheelEvent(QWheelEvent *e)
{
	if ( ui.musicPos->hasFocus() )
	{
		if ( e->delta() > 0 )
			pwp();
		else if ( e->delta() < 0 )
			pwl();
	}
}

void LoadQOut()
{
	if ( !QFile::exists( QMPOutf+libExt ) )
	{
		printf("FAILED\n");
		QMessageBox::warning(NULL,"QMPlay",Texts[4] /** Nie mozna odnalezc pliku: */ +QMPOutf+libExt);
		fa.add(Texts[4]);
		exit(0);
	}
	QOut_lib.setFileName(QMPOutf+libExt);
	if ( QOut_lib.load() )
	{
		QOut = (QMPOut*) QOut_lib.resolve("QMPout");
		if ( !QOut || ( QOut && QOut->QMPVer != QMPlayOutVer ) )
		{
			printf("FAILED\n");
			QMessageBox::warning(NULL,"QMPlay", Texts[7] /** "QOUT nie poprawny dla QMPlay" */);
			fa.add(Texts[5]);
			exit(0);
		}
	}
	else
	{
		printf("FAILED\n");
		QMessageBox::warning(NULL,"QMPlay", Texts[5] /** "Nie mozna zaladowac pliku: " */+QMPOutf+libExt+"\n"+QOut_lib.errorString());
		fa.add(Texts[5]);
		exit(0);
	}
	if ( QOut->setQmpLib )
		QOut->setQmpLib( QLib );
	QOut->Init( AudioInfo( 0, 0, 0 ), false, 0, "", "" );
}

#ifdef Q_OS_MAC
#include <ApplicationServices/ApplicationServices.h>
OSStatus appleEventProcessor( const AppleEvent *ae, AppleEvent *, long )
{
	OSType aeID = typeWildCard;
	OSType aeClass = typeWildCard;

	AEGetAttributePtr(ae, keyEventClassAttr, typeType, 0, &aeClass, sizeof(aeClass), 0);
	AEGetAttributePtr(ae, keyEventIDAttr, typeType, 0, &aeID, sizeof(aeID), 0);

	if ( aeClass == kCoreEventClass && aeID == kAEReopenApplication )
	{
		if ( !f1.isVisible() )
		{
			if ( mQ.isVisible() )
				f1.miniQMP();
			f1.SoH();
		}
	}
	else if ( aeClass == kCoreEventClass && aeID == kAEOpenDocuments )
	{
		AEDescList docs;
		if ( AEGetParamDesc( ae, keyDirectObject, typeAEList, &docs ) == noErr )
		{
			long n = 0;
			AECountItems( &docs, &n );
			UInt8 strbuffer[ PATH_MAX ];
			QStringList QpathList;
			for ( long i = 0; i < n; i++ )
			{
				FSRef ref;
				if ( AEGetNthPtr ( &docs, i + 1, typeFSRef, 0, 0, &ref, sizeof( ref ), 0) != noErr )
					continue;
				if ( FSRefMakePath ( &ref, strbuffer, 256 ) == noErr )
					QpathList += (char *)strbuffer;
			}

			if ( QpathList.count() > 1 )
			{
				fp.setTcr( Func.nr() );
				QFileInfo fInfo( QpathList[0] );
				if ( QpathList.count() == 1 && fInfo.isDir() )
				{
					addthr.scat = false; /*true*/
					fp.addThrDo( QpathList );
				}
				else
					fp.addToList( QpathList,-1 );
			}
			else if ( QpathList.count() == 1 )
			{
				if ( !Func.isPlayListExt( Func.getExt( QpathList[0] ) ) )
				{
					ycPos = true;
					plOnstrt = true;
					fp.clrplist();
					fp.addToList( QpathList, -1 );
				}
				else
				{
					ycPos = true;
					f1.stop();
					if ( !isPlaying )
						plOnstrt = true; //rozpoczęcie odtwarzania po załadowaniu
					fp.odczytajListe( QpathList[0] );
				}
			}
		}
	}
	return noErr;
}
#endif

void Form1::Init()
{
#ifdef Q_OS_MAC
	AEInstallEventHandler( kCoreEventClass, kAEOpenDocuments, AEEventHandlerUPP( appleEventProcessor ), 0, false );
	AEInstallEventHandler( kCoreEventClass, kAEReopenApplication, AEEventHandlerUPP( appleEventProcessor ), 0, false );
#endif

	_bold.setBold(true);
	_italic.setItalic(true);
	_bolditalic.setBold(true);
	_bolditalic.setItalic(true);

	plistthr.runTitles = true;

	f1.setWindowFlags(Qt::Window);

	bool BLAD = false;
	QFile fsig ( QsignalE );
	if ( fsig.open( QFile::ReadOnly ) )
	{
		char c = 0;
		fsig.getChar( &c );
		fsig.close();
		if ( c == 'A' )
			BLAD = true;
	}

	int cpuSpd = Func.getCpuSpeed();
	if ( cpuSpd > 0 )
		printf( "CPU speed: %iMHz\n", cpuSpd );

	f1h = f1.minimumSize().height();
	f1w = f1.minimumSize().width();

	printf("Reading settings... ");
	fflush(stdout);
	Save.odczytajopcje();
	printf("OK\n");

	printf("Applying language... ");
	fflush(stdout);
	fl.Init();
	if ( lnglist[0].count() < 1 )
	{
		printf("FAILED\n");
		QMessageBox::warning( this, "QMPlay", "Nie znaleziono pliku językowego!\nProgram kończy pracę..." );
		exit(0);
	}
	fl.setLang();
	printf("OK\n");

	printf("Loading QMPOut... ");
	fflush(stdout);
	LoadQOut();
	printf("OK\n");

	fp.setListLoad();

	setGeometry( f1Geo );

	printf("Loading plugins:\n");
	Func.loadPlugins(1);
	FirstTime = false;

	printf("Applying appearance..");
	fflush(stdout);
	fst.getSystemPalette();
	printf(". ");
	fflush(stdout);
#ifdef Q_OS_MAC
	fst.applyAll();
#else
	if ( fst.ui.ccB->isChecked() )
		fst.applyAll();
	else
		fst.miniApply();
#endif
	printf("OK\n");

	Func.showPlugLoadErr();

	printf("Loading QMPlay Window... ");

	formInfo.resetWindow();
	ui.dockA->setVisible(false);

	fp.ui.toupButton->setText(UP_ARROW);
	fp.ui.todownButton->setText(DOWN_ARROW);
	fs.ui.toUpB->setText(UP_ARROW);
	fs.ui.toDownB->setText(DOWN_ARROW);

	zxplC = true; //visplugin zostanie przeladowany jezeli true
	fs.Init();
	fs.APPLYQMP();
	czyscf1();

	f1.setShortCutsandOthers();

	fp.chMusInfo();

	if ( !inTray && !mQmpVisible )
	{
		if ( fsMaximized )
			f1.showMaximized();
		else
			f1.show();
	}

	f1.ui.menuOtw_rz->addMenu( &menuFromPlugin );

	fs.ui.tabWidget->setTabIcon( 2, QIcon( ":/icons/plug.png" ) );
	for ( int i = 0 ; i < fs.ui.pluginsL->count() ; i++ )
		fs.ui.pluginsL->item(i)->setIcon( QIcon( ":/icons/plug.png" ) );

	fp.setAcceptDrops(true);

	if ( inTray || mQmpVisible )
	{
		f1.hide();
		wasShow = false;
	}
	else
	{
		if ( shwplaylist )
			showplaylist();

		wasShow = true;
	}

	fsMaximized = false;

	printf("OK\nQMPlay was loaded!\n");

	if ( !QFile::exists( opcja ) )
	{
		if ( opcja == "--noplay" || opcja == "-np" )
		{
			ycPos = true; //czysc pozycje w inputplugin na poczatku odtwarzania
			isPlaying = false; //czy muzyka odtwarzana?
		}

		if ( isPlaying )
		{
			stop();
			play();
		}
		else
			stop();
	}
	else
	{
		ycPos = true;
		stop();

		#ifdef Q_WS_WIN
			opcja.replace('\\','/');
		#endif

		QFileInfo fInfo( opcja );
		if ( !fInfo.isDir() ) //jeżeli nie jest katalogiem
		{
			if ( Func.isPlayListExt( Func.getExt( opcja ) ) )
			{
				plOnstrt = true; //odtwarzaj po starcie programu
				fp.odczytajListe( opcja );
			}
			else
			{
				fp.clrplist();
				plOnstrt = true;
				fp.addToList( ( QStringList )opcja, -1 );
			}
		}
		else
		{
			fp.clrplist();
			curP = opcja;
			addthr.scat = false; /*true*/
			fp.addThrDo( ( QStringList )opcja );
			plOnstrt = true;
		}
	}

	if ( BLAD && !bladinfoB )
		QMessageBox::warning(this,"QMPlay",Texts[59]/**Poważny blad*/);
	BLAD = 0;

	if ( QFile::exists( "QMPlay_opis.pdf" ) && Func.open( "" ) )
	{
		ui.menuPomoc->addSeparator();
		QAction *act = ui.menuPomoc->addAction( "Otwórz opis QMPlay", this, SLOT( opisQMP() ) );
		act->setShortcut( Qt::Key_F6 );
	}

	fa.clrLog();

	timref.start(200);
#ifdef Q_WS_WIN
	SetFileAttributes( ( WCHAR * )QMPConf.utf16(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_ARCHIVE );
	if ( !isOldWindows )
#endif
		connect( &sysW, SIGNAL( fileChanged( QString ) ), this, SLOT( fileChanged() ) );
}

void Form1::opisQMP()
{
	Func.open( "QMPlay_opis.pdf" );
}

bool Form1::chkSel()
{
	for ( int i = 0 ; i < titlelist->count()-1 ; i++ )
		if ( titlelist->item( i )->font().bold() )
			return 1;
	return 0;
}
bool Form1::chkSep()
{
	for ( int i = 0 ; i < playList[1].count()-1 ; i++ )
		if ( playList[1][i] == "separator" )
			return 1;
		return 0;
}

void Form1::ustawItalic( int i )
{
	if ( titlelist->item(i)->font().bold() ) //jeżeli jest pogrubienie
		titlelist->item(i)->setFont( _bolditalic ); //daje kursywę i pogrubienie
	else
		titlelist->item(i)->setFont( _italic ); //a jak nie to daje tylko kursywę
}

void Form1::usunItalic()
{
	if ( nrplay < 0 )
		return;

	if ( titlelist->count() <= nrplay )
		return;

	if ( titlelist->item( nrplay )->font().bold() ) //jeżeli jest pogrubienie
		titlelist->item( nrplay )->setFont( _bold ); //daje tylko pogrubienie
	else
		titlelist->item( nrplay )->setFont( _normal ); //a jak nie to daje normalne formatowanie
}

void Form1::errNxt()
{
	if ( Func.nr() == titlelist->count()-1 )
	{
		stop();
		return;
	}

	if ( npSng )
	{
		prevB();
		npSng=false;
	}
	else
		nextB();

	if ( !playnxt )
		play();
}

void Form1::play()
{
	int X = Func.nr();
	if ( X < 0 )
	{
		stop();
		return;
	}

	if ( ( selMus && !titlelist->item( X )->font().bold() ) || playList[1][X] == "separator" ) //odczyt tylko zaznaczonych
	{
		if ( X == titlelist->count()-1 )
		{
			if ( po != 3 )
			{
				stop();
				return;
			}
			else
			{
				if ( ( selMus && !titlelist->item( X )->font().bold() && !chkSel() ) || ( playList[1][X] == "separator" && !chkSep()) )
				{
					stop();
					return;
				}
			}
		}

		if ( isPlaying )
			nrplay = Func.nr();

		if ( npSng )
		{
			prevB();
			npSng=false;
		}
		else
			nextB();

		return;
	}
	else if ( !selMus && itemsQueue.contains( X ) )
	{
		itemsQueue.removeOne( X );
		fp.createList();
		titlelist->setCurrentRow( X );
	}

	fp.opnWlasciwosci();

	if ( QOut->busy[1] )
		stop();

	fp.setTcr( Func.nr() );

	if (!isPlaying)
	{
		if ( !plthr.isRunning() )
		{
			opn();

			if ( playList[1][X] == "file" ) //normalFile
			{
				if ( !QFile::exists( file ) )
				{
					if ( uPLe ) //odświeża wpis na liście jezeli jest tak ustawione w opcjach
						fp.updatePlistEntry(X);

					*Iplug->title = Texts[2]; /** "Nie mozna odnalezc pliku!" */;
					fa.add(Texts[2]);
					na = true;
					if ( !errnxt )
						stop();
					else
						errNxt();
					return;
				}
			}
			//next:
			bool b = false;
			//odświeża wpis na liście jezeli jest tak ustawione w opcjach, jeżeli nieznany typ lub wybrany plugin nie istnieje
			if ( uPLe && ( ( Func.chkProtocols( playList[2][X] ) && playList[1][X].length() <= 9 ) || !Func.getMusicFormat( playList[1][X], "" ) ) )
			{
				fp.updatePlistEntry(X);
				b = true;
				if ( playList[1][X] != "file" ) //jeżeli np. strumień internetowy nie był przypisany do inputplugina
				{
					lastPosChMusInfo = -2;
					fp.chMusInfo();
				}
			}
			if ( Func.chkFNr(X) )
				Iplug = Func.getMusicFormat(playList[1][X],playList[2][X]);
			else
				Iplug = NULL;
			if ( Iplug )
			{
				plthr.setType();
				fa.add( Texts[123] /*Używany IPlug*/ + ": " + (QString)Iplug->pluginInfo->Name );
				Iplug->Init( true, plthr.type );
				if ( ycPos )
				{
					ycPos = false;
					Iplug->clrPos(); //czysci pozycje muzyki
				}
				usunItalic();

				plthr.start();  //zaczyna watek - odtwarzanie
				ustawItalic( X );
				if ( playList[1][X] == "file" )
					fa.add( "Playing: " + Func.plikbezsciezki(file) );
				else
					fa.add( "Playing: " + file );
				if ( zipl && Iplug->plugSpec )
					Iplug->plugSpec(f1.ui.okno,true);

				if ( uPLe && !b ) //odświeża wpis na liście jezeli jest tak ustawione w opcjach i wpis nie był odświeżony
					fp.updatePlistEntryIfNeed(X);

				if ( formInfo.isVisible() )
					showInfoForm();

				if ( mI.isVisible() && !mI.ui.musP->isVisible() && X == mI.cRow && file == mI.file )
				{
					mI.ui.musP->setValue( *Iplug->pltime );
					mI.ui.musP->show();
				}
			}
			else
			{
				Iplug = (InputPlugin*) &N0input;

				if ( uPLe && !b ) //odświeża wpis na liście jezeli jest tak ustawione w opcjach
					fp.updatePlistEntry(X);

				*Iplug->title = Texts[1]; /** "Nieznany format pliku" */
				na=true;
				fa.add(Texts[1]);
				if ( !errnxt )
					stop();
				else
					errNxt();
				return;
			}
		}
		*Iplug->pauseD=false;
		return;
	}
	else //if isPlaying
	{
		if ( *Iplug->pauseD && playList[2][X] == file )
			pause2();
		else
		{
			na=true;
			na3=true;
			na4=true;
			stop();
			play();
		}
	}
}

void Form1::stop()
{
	if ( !isPlaying && plthr.isRunning() )
		return;

	usunItalic();
	isPlaying = false;

	if ( mI.isVisible() && mI.ui.musP->isVisible() )
	{
		mI.ui.musP->hide();
		mI.resize( 0,0 );
	}

	bool tmpProblem = false, tmpProblem2 = false, tmpProblem3 = false, tmpProblem4 = false;

	if ( plthr.isRunning() )
		tmpProblem = plthr.doExit();

	if ( !QMPWait_n_close( QOut_STOP_AND_WAIT ) ) //if ( QOut->busy[1] )
	tmpProblem2 = !QOut->close();

	if ( !na3 && QOut->busy[0] && !QOut->busy[1] ) //jeżeli stop
	{
		tmpProblem3 = !QOut->close();
		formInfo.resetWindow();
	}

	if (!na)
	{
		if (!*Iplug->PlugErr)
			*Iplug->title = Texts[0]; /** "Brak odtwarzanej muzyki" */
		*Iplug->pltime=0;
	}
	na=false;

	if ( QOut->busy[0] && !QOut->busy[1] && na3 ) //jeżeli next albo prev albo play
	{
		if ( closeExportOnNxt )
		{
			bool exporting = QOut->startExport(false);
			QOut->control( QOUT_CLOSE_EXPORTFILE );
			if ( exporting )
				tmpProblem4 = !QOut->close();
			else
				QMPWait_n_close( QOut->clrEff );
		}
		else
			QMPWait_n_close( QOut->clrEff );
	}

	na3 = false;

	if ( !na4 )
		f1.czyscf1();
	na4 = false;

	*Iplug->PlugErr = false;
	Iplug = (InputPlugin*) &N0input;

	f1.clrFile();

	problem = tmpProblem || tmpProblem2 || tmpProblem3 || tmpProblem4;

	if ( !problem )
		qApp->restoreOverrideCursor();
}

void Form1::clrFile()
{
	file.clear();
}

void Form1::showProblem()
{
	if ( problem )
	{
		problem = false;
		qApp->restoreOverrideCursor();
		QMessageBox::warning( this,"QMPlay",Texts[61]/**Program działa niestabilnie...*/ );
	}
}

void Form1::QVisTimer()
{
	if ( ( fsl.isVisible() || ui.pbL->isVisible() || ui.pbR->isVisible() ) && ( isPlaying || QOut->busy[1] )&& !timQVis.isActive() )
		timQVis.start(32);
	else if ( ( ( !fsl.isVisible() && !ui.pbL->isVisible() && !ui.pbR->isVisible() ) || ( !QOut->busy[1] && !isPlaying ) ) && timQVis.isActive() )
		timQVis.stop();
}

void Form1::updateQVis()
{
	int tl = sqrt( s[0] + 1 ) / 2.5 + 1;
	int tr = sqrt( s[1] + 1 ) / 2.5 + 1;
	o[0] = QOut->getVolume[0];
	o[1] = QOut->getVolume[1];

	if ( o[0] >= s[0] )
		s[0] += o[0] - s[0];
	else
		s[0] -= tl;
	if (s[0] < 0)
		s[0] = 0;

	if ( o[1] >= s[1] )
		s[1] += o[1] - s[1];
	else
		s[1] -= tr;
	if (s[1] < 0)
		s[1] = 0;

	if ( fsl.isVisible() )
		fsl.setVis( s );

	if ( ui.pbL->isVisible() )
	{
		ui.pbL->setValue( s[0]-1 );
		if ( !*Iplug->pauseD )
			ui.pbL->repaint();
	}
	if ( ui.pbR->isVisible() )
	{
		ui.pbR->setValue( s[1]-1 );
		if ( !*Iplug->pauseD )
			ui.pbR->repaint();
	}
}

void Form1::getFrameSize()
{
	frameS   = ( f1.frameGeometry().width() - f1.geometry().width() ) / 2;
	titleBS  = ( f1.frameGeometry().height() - f1.geometry().height() );
	titleBS2 = ( f1.frameGeometry().height() - f1.geometry().height() ) - frameS;
}

void Form1::timrefDo()
{
	if ( QDir::current() != qApp->applicationDirPath() )
		QDir::setCurrent( qApp->applicationDirPath() );

	if ( !titleBS ) //jeżeli nie ma pobranej grubości belki okna
	{
		getFrameSize();
		if ( fpzf1 && titleBS > 0 )
			fp.move( f1.x(), f1.y() + f1.height() + titleBS );
	}

	if ( equalizer && equalizer->showOptions )
	{
		bool b = equalizer->showOptions(0);
		if ( b != ui.eqB->isChecked() )
			ui.eqB->setChecked( b );
	}
	else if ( ui.eqB->isChecked() )
		ui.eqB->setChecked(false);

	if ( mQmpVisible )
	{
		miniQMP();
		mQmpVisible = false;
	}

	showProblem();

	if ( addthr.added )
	{
		qApp->restoreOverrideCursor();
		if ( addthr.fromDnD )
			fp.addToList( addthr.pths, Func.nr()+1 );
		else
			fp.addToList( addthr.pths, -1 );
		addthr.fromDnD = false;
		addthr.added = false;
		addthr.pths.clear();
		fp.createLPList();
	}

	if ( isPlaying && ( *QOut->mustReset || *QOut->PlErr ) )
	{
		bool pl;
		if ( *QOut->PlErr )
			pl = false;
		else
			pl = true;
		stop();
		if ( pl )
			play();
		return;
	}

	if ( *Iplug->mustReset )
	{
		stop();
		*Iplug->mustReset = false;
		play();
		return;
	}
	if ( *Iplug->PlugErr )
	{
		fa.add( *Iplug->title );
		if (!errnxt)
			stop();
		else
		{
			*Iplug->PlugErr=false;
			next();
		}
		return;
	}

	if ( Tray.showInTray )
	{
		tray.showMessage(Tray.title,Tray.msg,(QSystemTrayIcon::MessageIcon)Tray.icon,Tray.msec);
		Tray.clr();
		Tray.showInTray = false;
	}

	QVisTimer();
	if ( isPlaying )
	{
		if ( nrplay < 0 )
			nrplay = 0;

		if ( mI.isVisible() && mI.ui.musP->isVisible() )
			mI.ui.musP->setValue( *Iplug->pltime );

		if ( nextXs && *Iplug->pltime >= nextXsV )
			nextB();

		if ( Func.nr() > -1 && *Iplug->title == "" )
			*Iplug->title = Func.plikbezsciezki( playList[2][Func.nr()] );

		if ( QOut->startExport(0) )
			exportTitle = Texts[113]+" - ";
		else
			exportTitle.clear();
		if ( oldExportTitle != exportTitle )
			Tray.showTrayMessage( "QMPlay", exportTitle.isEmpty() ? Texts[113]+" "+Texts[115] : Texts[113]+" "+Texts[114], 1, 2000, true, NULL );
		oldExportTitle = exportTitle;

		title = QString::number(nrplay+1) + ". " + exportTitle + *Iplug->title;
		if ( title != f1.ui.titleLabel->text() )
		{
			f1.ui.titleLabel->setText(title); //title label
			f1.ui.titleLabel->setToolTip(title); //title toolTip
			mQ.ui.titleL->setText( title );
			ui.titleLabel->repaint();
		}
		if ( "QMPlay - " + title != f1.windowTitle() )
			f1.setWindowTitle("QMPlay - "+ title); //title bar

		if ( *Iplug->plMaxtime - *Iplug->pltime >= 0 )
		{
			tray.setToolTip( f1.windowTitle() + "\n" + Texts[89] + ": " + Func.timeFormat( *Iplug->plMaxtime - *Iplug->pltime, 1 ) );
			mQ.ui.timeL->setText( "- " + Func.timeFormat( *Iplug->plMaxtime - *Iplug->pltime, 1 ) );
		}
		else
		{
			tray.setToolTip( f1.windowTitle() + "\n" + Texts[87] + ": " + Func.timeFormat( *Iplug->pltime, 1 ) );
			mQ.ui.timeL->setText( Func.timeFormat( *Iplug->pltime, 1 ) );
		}

		f1.ui.timemaxLabel->setText( Func.timeFormat( *Iplug->plMaxtime, 1 ) );
		f1.ui.timepozostLabel->setText( Func.timeFormat( *Iplug->plMaxtime - *Iplug->pltime, 1 ) );

		ui.chnL->setText( QOut->musParam[0] );
		ui.formatL->setText( QOut->musParam[1] );
		ui.rateL->setText( QOut->musParam[2] );
		if ( ui.brL->text() != *Iplug->getBR )
		{
			ui.brL->setText( *Iplug->getBR );
			ui.brL->repaint();
		}

		if ( !slPressed )
		{
			f1.ui.timeLabel->setText( Func.timeFormat( *Iplug->pltime, 1 ) );

			if ( f1.ui.musicPos->minimum() != 0 )
				f1.ui.musicPos->setMinimum ( 0 );
			if ( f1.ui.musicPos->maximum() != *Iplug->NumPos )
				f1.ui.musicPos->setMaximum ( *Iplug->NumPos );

			f1.ui.musicPos->setValue   ( *Iplug->SongPos );
			MusicPosVal = f1.ui.musicPos->value();
		}

		if ( *Iplug->isEndSong )
		{
			*Iplug->isEndSong=false;
			if ( Iplug->Show )
				Iplug->setFormInfo( NULL );
			f1.next();
		}

		int val = getMusPosVal();
		if ( ui.musicPos->underMouse() && val > 0 )
			ui.musicPos->setToolTip( Func.timeFormat( val, true ) );
	}
	else
	{
		if ( ui.musicPos->toolTip() != "" )
			ui.musicPos->setToolTip("");
		if ( QOut->busy[1] ) //jezeli qmpout uzywa inny plugin
		{
			title = *QOut->title;
			if ( title != f1.ui.titleLabel->text() )
			{
				f1.ui.titleLabel->setText(title);
				f1.ui.titleLabel->setToolTip(title);
				mQ.ui.titleL->setText( title );
			}
			if ( "QMPlay - " + title != f1.windowTitle() )
				f1.setWindowTitle("QMPlay - "+ title); //title bar

			f1.ui.timeLabel->setText( Func.timeFormat( *QOut->pltime, 1 ) );

			ui.chnL->setText( QOut->musParam[0] );
			ui.formatL->setText( QOut->musParam[1] );
			ui.rateL->setText( QOut->musParam[2] );

			if ( !cf1 )
				cf1 = true;
		}
		else //jeżeli nie
		{
			if ( cf1 ) //zdarzenie wykonywane tylko raz
			{
				czyscf1(); //czyści okno główne
				cf1 = false;
			}
		}
	}

#ifdef Q_WS_WIN
	if ( !isOldWindows )
	{
#endif
		if ( !sysW.files().contains( QsignalE ) && QFile::exists( QsignalE ) )
			sysW.addPath( QsignalE );
		if ( !canChSignal )
		{
			Qsignals();
			canChSignal = true;
		}
#ifdef Q_WS_WIN
	}
	else
		Qsignals();
#endif

	if ( autoUpdates )
	{
		if ( chkUpdatesThr.once )
		{
			chkUpdatesThr.once = false;
			chkUpdatesThr.checkVers = true;
			chkUpdatesThr.start();
		}
	}
}

void Form1::opcje()
{
	if ( !fs.isVisible() )
	{
		fs.setWindowFlags(Qt::Window);
		fs.Init();
		fs.show();
	}
	else
  fs.close();
}

void Form1::slR()
{
	slPressed = false;
	if ( !Bpmpp )
		seek(ui.musicPos->value());
}

void Form1::slP()
{
	slPressed = true;
}

void Form1::volMnu()
{
	menuVol.clear();
	QAction *act = menuVol.addAction( Texts[102] /** Przesuwaj razem */, &f1, SLOT( setBothVolB() ) );
	act->setCheckable( true );
	act->setChecked( QOut->bothVolB(0) );
	menuVol.popup( QCursor::pos() );
}

void Form1::setBothVolB()
{
	QOut->bothVolB(1);
}

int Form1::getMusPosVal()
{
	const int o = ui.musicPos->style()->pixelMetric( QStyle::PM_SliderLength ) - 1;
	int mouseX = ui.musicPos->mapFromGlobal( QCursor::pos() ).x();
	return QStyle::sliderValueFromPosition( ui.musicPos->minimum(), ui.musicPos->maximum(), mouseX - o/2, ui.musicPos->width() - o, false );
}

void Form1::slAT(int i)
{
	if ( i == 3 || i == 4 )
		seek( getMusPosVal() );
	switch (i)
	{
		case 1:
			seek(ui.musicPos->value() + 1);
			break;
		case 2:
			seek(ui.musicPos->value() - 1);
			break;
		case 7:
			int Val = ui.musicPos->value();
			if ( Bpmpp )
			{
				if ( Val > MusicPosVal )
				{
					ui.timeLabel->setText( Func.timeFormat( Val + 1, 1 ) );
					seek( Val + 1 );
				}
				else if ( Val < MusicPosVal )
				{
					ui.timeLabel->setText( Func.timeFormat( Val - 1, 1 ) );
					seek( Val - 1 );
				}
			}
			else
				ui.timeLabel->setText( Func.timeFormat( Val, 1 ) );
			break;
	}
}

void Form1::prevB()
{
	if ( !isPlaying )
		nrplay = Func.nr();

	if (po==1)
		next();
	else
	{
		if ( nrplay - 1 < 0 )
		{
			titlelist->setCurrentRow( titlelist->count() - 1 );
			if ( ( playnxt && !isPlaying ) || isPlaying )
				play();
		}
		else
			prev();
	}
}

void Form1::nextB()
{
	if ( !isPlaying )
		nrplay = Func.nr();

	if (po==1)
		next();
	else
	{
		if ( nrplay + 1 == titlelist->count() )
		{
			titlelist->setCurrentRow( 0 );
			if ( ( playnxt & !isPlaying ) || isPlaying )
				play();
		}
		else
			nxt();
	}
}

void Form1::next()
{
	if ( itemsQueue.size() )
	{
		nxt();
		return;
	}

	if ( po == 0 )
		nxt();
	else if ( po == 1 )
	{
		if ( titlelist->count() > 1 )
		{
			unsigned char isAnySel(0);
			int r;
			for ( r = 0 ; r < titlelist->count() ; r++ )
			{
				if ( titlelist->item( r )->font().bold() )
				{
					isAnySel++;
					if ( isAnySel > 1 )
						break;
				}
			}
			random:
			r = rand()%titlelist->count();
			if ( ( selMus && ( ( r == nrplay && isAnySel >= 2 ) || ( !titlelist->item( r )->font().bold() && isAnySel > 0 ) ) ) || ( !selMus && ( r == nrplay && titlelist->count() >= 2 ) ) )
				goto random;
			titlelist->setCurrentRow( r );
			play();
		}
		else
			stop();
	}
	else if ( po == 2 )
		play();
	else if ( po == 3 )
	{
		if ( titlelist->count() > 0 )
		{
			if ( nrplay + 1 == titlelist->count() )
			{
				titlelist->setCurrentRow( 0 );
				play();
			}
			else
				nxt();
		}
	}
	else if ( po == 4 )
		prev();
}

void Form1::nxt()
{
	npSng = false;

	titlelist->clearSelection();

	if ( plistthr.isRunning() )
	{
		if ( playList[0].size() > plistthr.tcr )
		{
			titlelist->setCurrentRow(plistthr.tcr);
			plistthr.tcr++;
		}
		else
			return;
	}

	if ( !selMus && itemsQueue.size() && ( playnxt || ( !playnxt && isPlaying ) ) ) //odtwarzanie kolejkowanych utworów
	{
		int pl = -1;
		while ( itemsQueue.size() )
		{
			pl = itemsQueue.takeFirst();
			if ( pl > -1 && pl < titlelist->count() )
			{
				fp.createList();
				titlelist->setCurrentRow( pl );
				play();
				return;
			}
		}
	}

	if ( isPlaying )
	{
		if ( nrplay + 1 == titlelist->count() )
		{
			titlelist->setCurrentRow( nrplay );
			stop();
		}
		else
		{
			titlelist->setCurrentRow( nrplay + 1 );
			play();
		}
	}
	else
	{
		if ( !playnxt )
		{
			if ( nrplay + 1 < titlelist->count() )
				titlelist->setCurrentRow( nrplay + 1 );
		}
		else
		{
			if ( nrplay + 1 == titlelist->count() )
			{
				titlelist->setCurrentRow( nrplay );
				stop();
			}
			else
			{
				titlelist->setCurrentRow( nrplay + 1 );
				play();
			}
		}
	}
}

void Form1::prev()
{
	npSng = true;

	titlelist->clearSelection();

	if ( plistthr.isRunning() )
	{
		if ( playList[0].size() > plistthr.tcr )
		{
			titlelist->setCurrentRow(plistthr.tcr);
			plistthr.tcr--;
		}
		else
			return;
	}

	if (isPlaying)
	{
		if ( nrplay -1 < 0 )
		{
			titlelist->setCurrentRow( nrplay );
			stop();
		}
		else
		{
			titlelist->setCurrentRow( nrplay - 1 );
			play();
		}
	}
	else
	{
		if ( !playnxt )
		{
			if ( !nrplay -1 < 0 )
				titlelist->setCurrentRow( nrplay - 1 );
		}
		else
		{
			if ( nrplay -1 < 0 )
			{
				titlelist->setCurrentRow( nrplay );
				stop();
			}
			else
			{
				titlelist->setCurrentRow( nrplay - 1 );
				play();
			}
		}
	}
}

void Form1::seek( int i )
{
	if ( isPlaying )
	{
		if ( i < 0 )
			i = 0;
		Iplug->seek( i );
		if ( i >= 0 )
			QOut->control( QOUT_NEXT_READ );
	}
}

void Form1::resetInfoWindow()
{
	formInfo.resetWindow();
}

void FormInfo::resetWindow()
{
	infoW->show();
	setWindowTitle( Texts[125] /* Informacje o muzyce */ );
	setMaximumSize( 16777215, 16777215 );
	setMinimumSize( 0, 0 );
	resetSize();

	if ( inDock != this )
		button->setShortcut( QKeySequence("ESC") );
	else
		button->setShortcut( QKeySequence() );
}
void FormInfo::resetSize()
{
	resize( 170, 125 );
}
void FormInfo::resizeEvent( QResizeEvent* )
{
	if ( cantResize > 0 )
	{
		cantResize--;
		return;
	}
	if ( unDocking )
		return;
	if ( !Iplug->Show )
		return;
	int a[2];
	a[0] = width();
	a[1] = height();
	Iplug->setFormInfo( a );
}
void FormInfo::closeEvent( QCloseEvent* )
{
	if ( Iplug->Show )
		Iplug->setFormInfo( NULL );
	if ( unDocking )
	{
		f1.ui.infoB->setChecked( false );
		resetWindow();
		return;
	}
	if ( inDock == this )
		f1.dockInF1(NULL,0,NULL);
	else
	{
		posX = x();
		posY = y();
	}
	f1.ui.infoB->setChecked( false );
	QTimer::singleShot( 0, &f1, SLOT( resetInfoWindow() ) );
}
void FormInfo::showEvent( QShowEvent* )
{
	f1.ui.infoB->setChecked( true );
}
void Form1::showInfoForm()
{
	if ( Iplug->Show )
	{
		formInfo.cantResize = 2;
		formInfo.infoW->close();
		QWidget *tmpW = Iplug->Show(&formInfo);
		if ( tmpW )
		{
			formInfo.setWindowTitle( tmpW->windowTitle() );
			formInfo.setMaximumSize( tmpW->maximumSize() );
			formInfo.setMinimumSize( tmpW->minimumSize() );
			formInfo.resize( tmpW->size() );
			return;
		}
	}
	formInfo.resetWindow();
}
void Form1::musinfoClose()
{
	if ( inDock != &formInfo )
		formInfo.close();
	else
	{
		formInfo.showAfterUnDock = false;
		f1.dockInF1(NULL,0,NULL);
	}
}
void Form1::musinfo()
{
	if ( formInfo.isVisible() )
		musinfoClose();
	else
	{
		showInfoForm();
		formInfo.move( formInfo.posX, formInfo.posY );
		formInfo.show();
	}
}

void Form1::info()
{
	if (Func.nr() < 0)
		return;
	int X = Func.nr();

	QString file = playList[2][X];

	if ( playList[1][X] == "file" ) //normalFile
	{
		if ( !QFile::exists( file ) )
			return;

		bool OK(0);
		bool isExtOK = Func.getExts( true ).contains( Func.getExt( file, true ) );
		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			//jezeli pasuje rozszerzenie i wtyczka wlaczona to pokazuje info
			if ( !fileStruct || ( fileStruct && unknownType && isExtOK ) )
			{
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && Func.checkFormat( *Iplugins[w]->formatSupport, file ) )
					OK = true;
			}
			else if ( !FileFormatSupportOpened )
			{
				FileFormatSupportOpened = true;
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && Iplugins[w]->FileFormatSupport && Iplugins[w]->FileFormatSupport( file.toUtf8() ) )
					OK = true;
				FileFormatSupportOpened = false;
			}
			if ( OK )
			{
				if ( Iplugins[w]->infoWindow )
				{
					if ( f1.isActiveWindow() || fpnf1 )
						Iplugins[w]->infoWindow( this, file.toUtf8(), 0 );
					else
						Iplugins[w]->infoWindow( &fp, file.toUtf8(), 0 );
				}
				return;
			}
		}
		return;
	}

	if ( playList[1][X].left( 7 ) == "plugin:" || playList[1][X].left( 9 ) == "internet:" )
	{
		int Type(0);
		QString typTmp = playList[1][X];
		if ( playList[1][X].left( 7 ) == "plugin:" )
		{
			typTmp = Func.getTypePlugin( typTmp );
			Type = 1;
		}
		if ( playList[1][X].left( 9 ) == "internet:" )
		{
			typTmp = typTmp.right( typTmp.size() - 9 );
			Type = 2;
		}

		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			if ( typTmp == (QString)Iplugins[w]->pluginInfo->Name )
			{
				if ( Iplugins[w]->pluginInfo->swOnOff(0) )
				{
					if ( Iplugins[w]->infoWindow )
					{
						QString TMP = file;
						if ( TMP.left( 9 ) == "plugin://" )
							TMP = Func.getFNamePlugin( TMP, 1 );

						if ( f1.isActiveWindow() || fpnf1 )
							Iplugins[w]->infoWindow( this, TMP.toUtf8(), Type );
						else
							Iplugins[w]->infoWindow( &fp, TMP.toUtf8(), Type );
					}
				}
				return;
			}
		}
	}
}

void Form1::opn()
{
	int X = Func.nr();
	if ( X >= 0 )
		file = playList[2][X];
	else
		clrFile();
}

void Form1::pause()
{
	if ( !*Iplug->pauseD && !QOut->busy[1] )
	{
		QOut->control( QOUT_SILENCE );
		QOut->control( QOUT_MUST_PAUSE );
		pause2();
	}
	if ( QOut->busy[1] )
		QOut->control( QOUT_PAUSE_OTHER );
}

void Form1::pause2()
{
	if ( isPlaying )
	{
		*Iplug->pauseD = !*Iplug->pauseD;
		Iplug->togglePause();
	}
}

void Form1::czyscf1()
{
	ui.musicPos->setMinimum(0);
	ui.musicPos->setMaximum(0);
	ui.musicPos->setValue(0);
	if ( cf1 )
	{
		ui.titleLabel->setText( Texts[0] /** "Brak odtwarzanej muzyki" */ );
		ui.titleLabel->setToolTip("");
		mQ.ui.titleL->setText( "QMPlay" );
	}
	else
	{
		ui.titleLabel->setText( *Iplug->title );
		if ( *Iplug->title == Texts[0] )
		{
			ui.titleLabel->setToolTip("");
			mQ.ui.titleL->setText( "QMPlay" );
		}
		else
		{
			ui.titleLabel->setToolTip( *Iplug->title );
			mQ.ui.titleL->setText( *Iplug->title );
		}
	}
	ui.titleLabel->repaint();

	f1.setWindowTitle("QMPlay");
	tray.setToolTip( "QMPlay" );
	mQ.ui.timeL->setText( "00 : 00" );
	ui.timeLabel->setText("00 : 00");
	ui.timemaxLabel->setText("00 : 00");
	ui.timepozostLabel->setText("00 : 00");

	ui.chnL->setText( Texts[18] /** "Kanaly" */);
	ui.formatL->setText( Texts[19] /** "Format" */);
	ui.rateL->setText( Texts[20] /** "Probkowanie" */);
	ui.brL->setText( Texts[21] /** "Bitrate" */);

	//czyszczenie zmiennych w QOut ( srate, channels and bits )
	QOut->musParam[0] = Texts[18];
	QOut->musParam[1] = Texts[19];
	QOut->musParam[2] = Texts[20];

	fsl.clearVis();
	ui.pbL->setValue(-1);
	ui.pbR->setValue(-1);
	s[0] = -1;
	s[1] = -1;

	volToolTip();

	Func.getVol();

	if (po==0)
		fp.pu0();
	else if (po==1)
		fp.pu1();
	else if (po==2)
		fp.pu2();
	else if (po==3)
		fp.pu3();
	else if (po==4)
		fp.pu4();
}

void Form1::showplaylist()
{
	if ( !fp.isVisible() )
	{
		if ( !fpnf1 )
		{
			fp.setParent(NULL);
			fp.setWindowFlags(Qt::Window);
		}
		else
		{
			fp.setParent(f1.ui.plist);
			fp.setWindowFlags(Qt::Widget);
			fp.move(0,0);
			if ( !fsMaximized )
			{
				f1.resize( f1.width(), fpGeo.height() + f1h );
				f1.resize( f1.width(), fpGeo.height() + f1h - ( f1.ui.plist->height() - fpGeo.height() ) );
			}
			fp.resize( f1.ui.plist->width(), fpGeo.height() );
		}
		fp.Init();
		fp.show();
	}
	else
	{
		fp.close();
		if (fpnf1)
			f1.resize(f1.width(),f1h);
	}
}

void Form1::moveEvent(QMoveEvent*)
{
	if ( fp.isVisible() && fpzf1 && !fpnf1 )
	{
		getFrameSize();
		fp.move( f1.x(), f1.y() + f1.height() + titleBS );
	}
}

void Form1::quit()
{
	static bool closed = false;
	if ( closed )
		return;
	closed = true;

	timref.stop();

	if ( wasShow ) //jezeli okienko bylo otwarte podczas sesji
	{
		f1Geo = geometry();
		shwplaylist = ui.playlistButton->isChecked();
	}

	if ( !f1.isVisible() )
		inTray = true;
	else
		inTray = false;

	if (mQ.isVisible())
		mQ.close();

	if ( !f1.isVisible() && mQ.closed )
		mQmpVisible = true;
	else
		mQmpVisible = false;

	if (fd.isVisible())
		fd.zamknij();
	if (fsl.isVisible())
		fsl.close();
	if (fst.isVisible())
		fst.close();
	if (fp.isVisible())
		fp.close();
	if (fs.isVisible())
		fs.close();
	if (ff.isVisible())
		ff.close();
	if (fa.isVisible())
		fa.close();
	if (fpr.isVisible())
		fpr.close();
	if (fdck.isVisible())
		fdck.close();

	if ( !usunSets && pluginsLoaded )
		Save.zapiszopcje();

	hide();

	QMPWait_n_close( QOut_STOP_AND_WAIT );

	bool tmpProblem = plthr.doExit();
	Iplug = (InputPlugin*) &N0input;

	bool tmpProblem2 = !QOut->close();

	problem = tmpProblem || tmpProblem2;

	plistthr.doExit();
	cpthr.doExit();
	addthr.doExit();

	showProblem();

	if (formInfo.isVisible())
		formInfo.close();

	Func.unloadAllPlugins();

	QFile::remove( QsignalE );
	QFile::remove( QMPfiles );

	if ( usunSets )
		QFile::remove( QMPConf );

	if ( chkUpdatesThr.isRunning() )
	{
		chkUpdatesThr.terminate();
		chkUpdatesThr.wait( 1000 );
	}

	qApp->quit();
}

void Form1::closeEvent(QCloseEvent *)
{
	quit();
}

void Form1::resizeEvent(QResizeEvent*)
{
	if ( fst.ui.use2->isChecked() )
		fst.quickSetColor();
	if ( fp.isVisible() && fpnf1 && !fpzf1 )
		fp.resize( f1.ui.plist->width() , f1.ui.plist->height() );
}

void Form1::funkcje_opn()
{
	if ( ff.isVisible() )
	{
		ff.close();
		return;
	}
	ff.setWindowFlags(Qt::Window);
	ff.Init();
	ff.show();
}

void Form1::aWAV()
{
	if ( QExport )
	{
		if ( QOut->busy[1] )
			stop();
		if (!isPlaying)
		{
			*QOut->setExport = true;
			play();
		}
		else
		{
			if ( QOut->startExport(0) )
				QOut->control(QOUT_CLOSE_EXPORTFILE);
			else
				QOut->startExport(1);
		}
	}
}

void Form1::setVol(int w)
{
	if ( volSettings )
		return;
	volSettings = true;
	if ( QOut->bothVolB(0) )
	{
		ui.volRS->setValue( w );
		ui.volLS->setValue( w );
	}

	mQ.ui.volS->setValue( w );

	volToolTip();

	volSettings = false;

	QOut->setVol( f1.ui.volLS->value(), f1.ui.volRS->value() );
}

void Form1::setVolFromMiniQMP(int w)
{
	if ( volSettings )
		return;
	bool r(0);
	if ( !QOut->bothVolB(0) )
	{
		QOut->bothVolB(1);
		r = true;
	}
	setVol( w );
	if ( r && QOut->bothVolB(0) )
		QOut->bothVolB(1);
}

void Form1::volToolTip()
{
	f1.ui.volLS->setToolTip( Texts[90] + ": " + QString::number( f1.ui.volLS->value() ) );
	f1.ui.volRS->setToolTip( Texts[91] + ": " + QString::number( f1.ui.volRS->value() ) );

	mQ.ui.volS->setToolTip( QString::number( f1.ui.volLS->value() ) );
}

void Form1::savMus()
{
	if ( Func.nr() < 0 )
		return;

	if ( cpthr.isRunning() )
	{
		QMessageBox::information( this, "QMPlay", Texts[63] /**"Pliki są już kopiowane"*/, 0, 0 );
		return;
	}

	if ( titlelist->selectedItems().size() <= 1 )
	{
		cpthr.X = Func.nr();
		QString TMP = curP;
		if ( TMP[ TMP.length() - 1 ] == '/' )
			TMP += Func.plikbezsciezki( playList[2][cpthr.X] );
		else
			TMP += "/" + Func.plikbezsciezki( playList[2][cpthr.X] );
		cpthr.selfile = Func.fileDialog( SAVE_FILE, this, "QMPlay - " + Texts[8]/**zapisz muzyke*/, TMP )[ 0 ];
		if ( !cpthr.selfile.isEmpty() && playList[2][cpthr.X] != cpthr.selfile )
		{
			Func.CURP( cpthr.selfile );
			cpthr.c = 0;
			cpthr.start();
			fcp.Init();
			fcp.show();
		}
	}
	else
	{
		QMessageBox::information( this, "QMPlay", Texts[64] /**"Pliki zostaną nadpisane"*/ );
		cpthr.selfile = Func.fileDialog( OPEN_DIR, this, "QMPlay - "+Texts[8]/**zapisz muzyke*/, curP )[0];
		if ( !cpthr.selfile.isEmpty() )
		{
			if ( cpthr.selfile[ cpthr.selfile.length() - 1 ] != '/' )
				cpthr.selfile += "/";

			Func.CURP( cpthr.selfile );
			cpthr.c = 1;
			cpthr.start();
			fcp.Init();
			fcp.show();
		}
	}
}

void Form1::AboutQMP()
{
	fa.setParent(this);
	fa.setWindowFlags(Qt::Window);
	fa.Init();
	fa.show();
}

void Form1::BTpause()
{
	if ( *Iplug->pauseD )
		play();
	else
		pause();
}

void Form1::Tpause()
{
	if ( !isPlaying )
	{
		play();
		return;
	}

	if ( *Iplug->pauseD )
		play();
	else
		pause();
}

void Form1::Qsignals()
{
	bool mustWriteQ = true;
	QByteArray fsigData;
	QFile fsig( QsignalE );
	if ( fsig.size() <= 1024*1024 && fsig.open( QFile::ReadOnly ) )
	{
		fsigData = fsig.readAll();
		fsig.close();
		if ( fsigData.size() == 1 && fsigData[ 0 ] == 'Q' )
			mustWriteQ = false;
	}
	if ( mustWriteQ )
	{
		if ( fsig.open( QFile::WriteOnly ) )
		{
			fsig.putChar( 'Q' );
			fsig.close();
		}
		if ( !fsigData.isEmpty() )
		{
			signed char sig = fsigData[ 0 ];
			fsigData.remove( 0, 1 );
			switch( sig )
			{
				case 0: quit  ();break;
				case 1: play  (); break;
				case 2: stop  (); break;
				case 3: pause (); break;
				case 4: nextB (); break;
				case 5: prevB (); break;
				case 6: Tpause(); break;
				case 7: //opcja "-a"
				{
					QFile f( QMPfiles );
					if ( f.size() <= 1024*1024 && f.open( QFile::ReadOnly ) )
					{
						QList< QByteArray > filelist = f.readAll().split( '\n' );
						f.close();
						if ( f.open( QFile::WriteOnly ) ) //czyszczenie
							f.close();

						QStringList QpathList;

						foreach( QByteArray pth, filelist )
						{
							if ( pth.isEmpty() )
								continue;
						#ifdef Q_WS_WIN
							pth.replace( '\\','/' );
						#endif
							if ( !fp.listPLstChk( pth ) )
								QpathList += pth;
						}

						fp.setTcr( Func.nr() );
						if ( QpathList.count() > 0 )
						{
							QFileInfo fInfo( QpathList[0] );
							if ( QpathList.count() == 1 && fInfo.isDir() )
							{
								addthr.scat = false; /*true*/
								fp.addThrDo( QpathList );
							}
							else
								fp.addToList( QpathList, -1 );
						}
					}
				} break;
				case 8:
					if ( titlelist->count() > 0 )
					{
						titlelist->setCurrentRow( titlelist->count() -1 );
						play();
					}
					break;
				case 9:
				{
				#ifdef Q_WS_WIN
					fsigData.replace( '\\','/' );
				#endif
					QFileInfo fInfo( fsigData );
					if ( !fInfo.isDir() )
					{
						if ( !Func.isPlayListExt( Func.getExt( fsigData ) ) )
						{
							ycPos = true;
							plOnstrt = true;
							fp.clrplist();
							fp.addToList( ( QStringList )fsigData, -1 );
						}
						else
						{
							if ( !isPlaying )
								plOnstrt = true; //rozpoczęcie odtwarzania po załadowaniu
							fp.odczytajListe( fsigData );
						}
					}
					else
					{
						ycPos = true;
						plOnstrt = true;
						fp.clrplist();
						curP = fsigData; //przypisuje się katalog
						addthr.scat = false; /*true*/
						fp.addThrDo( ( QStringList )fsigData );
					}
				} break;
				case 10: volup  (); break;
				case 11: voldown(); break;
				case 12: MinMax (); break;
				case 13: seekP (0); break;
				case 14: seekP (1); break;
				case 15: aWAV   (); break;
				case 16: //7 i 8, opcja: "-al"
				{
				#ifdef Q_WS_WIN
					fsigData.replace( '\\','/' );
				#endif
					QFileInfo fInfo( fsigData );
					if ( !fInfo.isDir() )
					{
						if ( !Func.isPlayListExt( Func.getExt( fsigData ) ) )
						{
							fp.setTcr( Func.nr() );
							fp.addToList( ( QStringList )fsigData, -1 );
							if ( titlelist->count() >= 0 )
							{
								if ( plistthr.isRunning() )
								{
									stop();
									signal_lastOnList = true;
									signal_Play = true;
								}
								else
								{
									titlelist->setCurrentRow( titlelist->count() - 1 );
									play();
								}
							}
						}
						else
						{
							if ( !isPlaying )
								plOnstrt = true;
							fp.odczytajListe( fsigData );
						}
					}
					else //only add, not play
					{
// 						stop();
// 						signal_lastOnList = true;
// 						signal_Play = true;
						addthr.scat = false; /*true*/
						fp.addThrDo( ( QStringList )fsigData );
					}
				} break;
				case 17: fp.loadPL  (); break;
				case 18: fp.nextPL  (); break;
				case 19: fp.prevPL  (); break;
				case 20: fp.clrlist (); break;
				case 21: fp.clrplist(); break;
				case 22: miniQMP    (); break;
				case 23: SoH        (); break;
				case 24:
					if ( fsigData.size() )
					{
						QWidget *par = qApp->activeWindow();
						bool b = false;
						if ( !par )
						{
							QWidgetList allWidgets = qApp->allWidgets();
							for ( int i = 0 ; i < allWidgets.count() ; i++ )
							{
								if ( allWidgets[i]->isFullScreen() )
								{
									par = allWidgets[i];
									break;
								}
							}
							if ( !par )
							{
								par = this;
								if ( !par->isVisible() )
								{
									par->showMinimized();
									b = true;
								}
							}
							qApp->setActiveWindow(par);
						}
						QKeyEvent kE( QEvent::KeyPress, fsigData[0], Qt::NoModifier );
						qApp->sendEvent( par, &kE );
						if ( b )
							par->hide();
					}
					break;
				default:
					fa.add( Texts[9] + ": " + QString::number( sig ) );
			}
		}
	}
}

void Form1::NextXs()
{
	nextXs = f1.ui.nextXs->isChecked();
}

void Form1::volup()
{
	ui.volLS->setValue( ui.volLS->value() + 5 );
	ui.volRS->setValue( ui.volRS->value() + 5 );

	volToolTip();

	QOut->setVol( f1.ui.volLS->value(), f1.ui.volRS->value() );
}

void Form1::voldown()
{
	ui.volLS->setValue( ui.volLS->value() - 5 );
	ui.volRS->setValue( ui.volRS->value() - 5 );

	volToolTip();

	QOut->setVol( f1.ui.volLS->value(), f1.ui.volRS->value() );
}

void Form1::minimize()
{
	if ( f1.windowState() != Qt::WindowMinimized )
	{
		f1.setWindowState( Qt::WindowMinimized );
		return;
	}

	if ( f1.windowState() == Qt::WindowMinimized  )
	{
		f1.setWindowState( Qt::WindowNoState );
		f1.setWindowState( Qt::WindowActive );
	}
}

void Form1::seekP( bool sk )
{
	if ( !sk )
	{
		if ( seekTime )
			seek( ui.musicPos->value() - proce );
		else
			seek( ui.musicPos->value() - ( (proce*ui.musicPos->maximum())/100 ) );
	}
	else
	{
		if ( seekTime )
			seek( ui.musicPos->value() + proce );
		else
			seek( ui.musicPos->value() + ( (proce*ui.musicPos->maximum())/100 ) );
	}
}

void Form1::setVolR(int* C)
{
	ui.volLS->setValue( C[0] );
	ui.volRS->setValue( C[1] );

	volToolTip();

	QOut->setVol( f1.ui.volLS->value(), f1.ui.volRS->value() );
}

void Form1::pwp()
{
	seekP( true );
}

void Form1::pwl()
{
	seekP( false );
}

void Form1::netA()
{
	bool ok(0);
	QString aName = QInputDialog::getText(this,"QMPlay", Texts[126]/*"Address:"*/ ,QLineEdit::Normal,InternetProtocols[0],&ok);
	if ( !aName.isEmpty() && ok )
	{
		plistthr.tcr = Func.nr();
		if ( plistthr.tcr < 0 )
			plistthr.tcr = 0;
		piAdd = true;
#ifdef Q_WS_WIN
		aName.replace('\\','/');
#endif
		fp.addToList( (QStringList)aName,-1 );
	}
}

void Form1::selA()
{
	selMus = ui.selMusA->isChecked();
}

void Form1::showEq()
{
	if ( equalizer && equalizer->showOptions )
		ui.eqB->setChecked( equalizer->showOptions(1) );
}

void Form1::SoH()
{
	if ( f1.isVisible() )
	{
		if ( fp.isVisible() && fp.parent() != NULL && fpnf1 )
			canShowPlaylist = 1;
		else
			canShowPlaylist = 0;

		if ( QSystemTrayIcon::isSystemTrayAvailable() )
			f1.hide();
		else
			f1.minimize();
		if ( mQ.isVisible() )
		{
			mQ.setQVisIcon();
			mQ.showSlider();
		}
	}
	else
	{
		if ( ui.okno->parent() == mQ.ui.okienko )
			mQ.setStandardIcon();
		mQ.showSliderInF1();
		showNormal();
		if ( fpnf1 && fp.parent() == NULL && ( canShowPlaylist || fp.isVisible() ) )
		{
			fp.close();
			showplaylist();
		}
		if ( !wasShow )
		{
			if ( shwplaylist && !fp.isVisible() )
				showplaylist();
			wasShow = true;
		}
	}
	mQ.dockVis = !isVisible();
}

#ifndef Q_OS_MAC
void Form1::mnuAct( QSystemTrayIcon::ActivationReason x )
{
#ifdef Q_WS_WIN
	if ( x == QSystemTrayIcon::Trigger )
#else
	if ( x == QSystemTrayIcon::Trigger || x == QSystemTrayIcon::DoubleClick )
#endif
		SoH();
	else if ( x == QSystemTrayIcon::MiddleClick )
		miniQMP();
}
#else
void Form1::mnuAct( QSystemTrayIcon::ActivationReason )
{
	if ( isMinimized() )
		SoH();
	if ( mQ.isVisible() && isVisible() )
	{
		miniQMP();
		SoH();
	}
	else if ( isVisible() )
		SoH();
	else
		miniQMP();
}
#endif

void Form1::miniQMP()
{
	if ( !mQ.isVisible() )
	{
		mQ.dockVis = !isVisible();
		mQ.Show(true);
	}
	else
		mQ.hide();
}

void Form1::buildMenus()
{
	trayMnu.clear();
	trayMnu.addAction( Texts[73] /**"Pokaz / schowaj okno"*/, &f1, SLOT( SoH() ) );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.actionInformacje );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.actionAB );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.actionPlay );
	trayMnu.addAction( ui.actionPause );
	trayMnu.addAction( ui.actionStop );
	trayMnu.addAction( ui.actionNext );
	trayMnu.addAction( ui.actionPrevious );
	trayMnu.addSeparator();
	if ( QExport )
	{
		trayMnu.addAction( ui.aWAV );
		trayMnu.addSeparator();
	}
	trayMnu.addAction( ui.vdwn_a );
	trayMnu.addAction( ui.vup_a );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.pwp_a );
	trayMnu.addAction( ui.pwl_a );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.act_funkcje );
	trayMnu.addSeparator();
	trayMnu.addMenu( &menuAdd );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.actionOpcje );
	trayMnu.addSeparator();
	trayMnu.addAction( "Mini QMPlay", &f1, SLOT( miniQMP() ) );
	trayMnu.addSeparator();
	trayMnu.addAction( ui.actionZakoncz );

	menuPlistAct.clear();
	menuPlistAct.setTitle( ui.menuAkcja->title() );
	menuPlistAct.addAction( ui.actionOd_wie );
	menuPlistAct.addAction( ui.actionZatrzymaj );
}
void Form1::showTrayMnu()
{
	trayMnu.popup( QCursor::pos() );
}

void Form1::updatemenuItems()
{
	f1.ui.nextXs->setText( Texts[55] + " " + QString::number( nextXsV ) + Texts[56] ); //czas dla odtwarzaj tylko X sek.
	menuFromPlugin.setTitle( Texts[99] /** Z wtyczek */ );
}

void Form1::setShortCutsandOthers()
{
	f1.buildMenus();

	f1.ui.playButton->setShortcut( QKeySequence("X") );
	f1.ui.pauseButton->setShortcut( QKeySequence("C") );
	f1.ui.stopButton->setShortcut( QKeySequence("V") );
	f1.ui.prevButton->setShortcut( QKeySequence("Z") );
	f1.ui.nextButton->setShortcut( QKeySequence("B") );

	ff.ui.closeB->setShortcut( QKeySequence("ESC") );

	fpr.ui.OKB->setShortcut( QKeySequence("ESC") );

	fa.ui.OKB->setShortcut( QKeySequence("ESC") );

	fcp.ui.brB->setShortcut( QKeySequence("ESC") );

	fl.ui.OKB->setShortcut( QKeySequence("ESC") );

	fst.ui.OKB->setShortcut( QKeySequence("ESC") );

	fs.ui.OKButton->setShortcut( QKeySequence("ESC") );

	ui.timeLabel->setToolTip( Texts[87] );
	ui.timemaxLabel->setToolTip( Texts[88] );
	ui.timepozostLabel->setToolTip( Texts[89] );

	volToolTip();

	updatemenuItems();
}

void Form1::checkUpdatesButton()
{
	if ( chkUpdatesThr.isRunning() )
		return;
	chkUpdatesThr.start();
}
void Form1::checkUpdates()
{
	if ( chkUpdatesThr.checkVers )
	{
		chkUpdatesThr.checkVers = false;
		if ( chkUpdatesThr.Ver == lastVer || chkUpdatesThr.Ver <= QMPVer )
		{
			chkUpdatesThr.clr();
			return;
		}
		lastVer = chkUpdatesThr.Ver;
	}

	QWidget *_parent = qApp->activeWindow();
	if ( !_parent )
		_parent = this;

	if ( chkUpdatesThr.updates == -1 )
		QMessageBox::warning( _parent, "QMPlay", Texts[107] /*Nie mozna pobrac aktualizacji*/ );
	if ( chkUpdatesThr.updates == 0 )
		QMessageBox::information( _parent, "QMPlay",Texts[92]+"!" ); /** "Nie znaleziono aktualizacji" */
	if ( chkUpdatesThr.updates == 1 ) /** "Akualizacje są dostępne" */
	{
		QString ver = QString::number( (float)chkUpdatesThr.Ver / 1000.,'f', 3 );
		QString ver2 = QString::number( QString( ver[ ver.length() - 1 ] ).toInt() + 1 );
		ver[ ver.length() - 1 ] = '.';
		ver += ver2.length() == 1 ? "0" + ver2 : ver2;
		int w = QMessageBox::information( _parent, "QMPlay",Texts[93]+": v"+ver+"!"+"\n"+Texts[105]/**Czy uaktualnić?*/, 3, 4 );
		if ( w == 3 ) //użytkownik chce pobrać program
		{
			loadCURL();
			if ( !CURLloaded )
				return;

			downloadThr.path = QDir::tempPath() + "/" + chkUpdatesThr.QMPlay_addr_and_file[ 1 ];
			downloadThr.addr = chkUpdatesThr.QMPlay_addr_and_file[ 0 ];
			downloadThr.start();

			fd.setParent(_parent);
			fd.setWindowFlags(Qt::Dialog);
			fd.Init(_parent);
			fd.show();
		}
	}
	if ( chkUpdatesThr.updates == 2 ) /** "Program jest aktualny" */
		QMessageBox::information( _parent, "QMPlay",Texts[94]+"!" );
	chkUpdatesThr.clr();
}

void Form1::TrayMessageClicked()
{
	if ( Tray.Act )
	{
		Tray.Act();
		Tray.Act = NULL;
	}
}

void (*unDock)();
void Form1::dockInF1( QWidget *w, bool frame, void(*_unDock)() )
{
	inDockObjName.clear();
	ui.dockA->takeWidget();
	if ( inDock )
	{
		inDock->setParent(NULL);
		if ( unDock )
			unDock();
		else
			inDock->show();
	}
	inDock = NULL;
	unDock = NULL;
	if( !w )
	{
		ui.dockA->setVisible(false);
		setMinimumSize( f1w, minimumSize().height() );
		if ( timref.isActive() )
			resize( f1w, height() );
	}
	else
	{
		ui.dockA->setWidget( w );
		w->move(0,0);
		inDock = w;
		inDockObjName = w->objectName();
		unDock = _unDock;
		if ( frame )
			ui.dockA->setFrameShape( QFrame::StyledPanel );
		else
			ui.dockA->setFrameShape( QFrame::NoFrame );
		ui.dockA->setVisible(true);
		int tmpS;
		if ( w->minimumSize().width() > ui.dockA->minimumSize().width() )
			tmpS = w->minimumSize().width();
		else
			tmpS = ui.dockA->minimumSize().width();
		setMinimumSize( f1w + tmpS, minimumSize().height() );
	}
}

void Form1::showMnuOpt()
{
	mnuDock.clear();
	mnuDock.addAction( fs.ui.dockB->text(), &fs, SLOT(formDockChOpen()) );
	mnuDock.addAction( fs.ui.setStyleB->text(), &fs, SLOT(setStyleB()) );
	mnuDock.addAction( fs.ui.langB->text(), &fs, SLOT(langB()) );
	mnuDock.addSeparator();
	mnuDock.addAction( fs.ui.updB->text(), &f1, SLOT(checkUpdates()) );
	mnuDock.addSeparator();
	mnuDock.addAction( ui.opcjeButton->text(), &f1, SLOT(opcje()) );
	mnuDock.addSeparator();
	mnuDock.addAction("Mini QMPlay", &f1, SLOT( miniQMP() ) );
	mnuDock.popup( QCursor::pos() );
}

void Form1::MinMax()
{
	if ( !f1.isVisible() )
		f1.showNormal();
	else
		f1.minimize();
}

void Form1::miniVersion()
{
	SoH();
	if ( !mQ.isVisible() )
		miniQMP();
}

void Form1::copyTitleA()
{
	QString t = ui.titleLabel->text();
	if ( t.indexOf( '.' ) > -1 && nrplay == Func.nr() && isPlaying )
		clipboard->setText( t.right( t.length() - t.indexOf( ' ' ) - 1 ) );
	else if ( Func.nr() > -1 )
		clipboard->setText( playList[ 0 ][ Func.nr() ] );
}

void Form1::fileChanged()
{
	if ( canChSignal )
	{
		canChSignal = false;
		Qsignals();
	}
}
