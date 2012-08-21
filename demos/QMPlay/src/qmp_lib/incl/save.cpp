#include <QDebug>

void Save::odczytajopcje()
{
	searchAction->setCheckable( true );
	searchAction->setChecked( false );

	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	uint oldQMPVer = QMPset->value( "QMPset/lastAppVer" ).toInt() * 10 + QMPset->value( "QMPset/lastAppVer2" ).toInt();

	if ( !oldQMPVer )
		FirstTime = true; //dołącza pierwszą wizualizację do "okienka"


	f1Geo = QMPset->value( "WindowGeo/f1Geo" ).toRect();
	fpGeo = QMPset->value( "WindowGeo/fpGeo" ).toRect();
	fsGeo = QMPset->value( "WindowGeo/fsGeo" ).toRect();
	ffGeo = QMPset->value( "WindowGeo/ffGeo" ).toRect();
	faGeo = QMPset->value( "WindowGeo/faGeo" ).toRect();
	fprPos = QMPset->value( "WindowGeo/fprPos" ).toPoint();

	formInfo.posX = QMPset->value( "WindowPos/fIposX" ).toInt();
	formInfo.posY = QMPset->value( "WindowPos/fIposY" ).toInt();


	styl = QMPset->value( "QMPset/styl", Default_QMP_style ).toString();

	Func.getLanguage();
	language = QMPset->value( "QMPset/language", language ).toString();

	curP = QMPset->value( "QMPset/curP", QDir::homePath() ).toString();

	Bpmpp = QMPset->value( "QMPset/Bpmpp", true ).toBool();

	fs.ui.savposBox->setChecked( QMPset->value( "QMPset/ispl" ).toBool() );

	if ( fs.ui.savposBox->isChecked() )
		isPlaying = QMPset->value( "QMPset/isPlaying", false ).toBool();
	else
		ycPos = true;

	zipl = QMPset->value( "QMPset/zipl", false ).toBool();
	zvpl = QMPset->value( "QMPset/zvpl", false ).toBool();
	zplV = QMPset->value( "QMPset/zplV", true ).toBool();
	zdefB = QMPset->value( "QMPset/zdefB", true ).toBool();
	proce = QMPset->value( "QMPset/proce", 10 ).toInt();

	errnxt = QMPset->value( "QMPset/errnxt", false ).toBool();
	playnxt = QMPset->value( "QMPset/playnxt", true ).toBool();
	listplaylist = QMPset->value( "QMPset/listplaylist", true ).toBool();
	fp.listPlaylst();

	savplist = QMPset->value( "QMPset/savplist", true ).toBool();
	closeExportOnNxt = QMPset->value( "QMPset/closeExportOnNxt", false ).toBool();
	po = QMPset->value( "QMPset/po", 0 ).toInt();

	shwplaylist = QMPset->value( "Plist/shwplaylist", true ).toBool();
	fpnf1 = QMPset->value( "Plist/fpnf1", true ).toBool();
	fpzf1 = QMPset->value( "Plist/fpzf1", false ).toBool();

	fs.ui.pbLBox->setChecked( QMPset->value( "QMPset/pbL" ).toBool() );
	fs.ui.pbRBox->setChecked( QMPset->value( "QMPset/pbR" ).toBool() );

	nextXsV = QMPset->value( "QMPset/nextXsV", 10 ).toInt();
	inTray = QMPset->value( "QMPset/inTray", false ).toBool();
	if ( !QSystemTrayIcon::isSystemTrayAvailable() && inTray )
		inTray = false;
	kBB = QMPset->value( "QMPset/kBB", 512 ).toInt();
	bladinfoB = QMPset->value( "QMPset/bladinfoB", false ).toBool();
	uPLe = QMPset->value( "QMPset/uPLe", true ).toBool();
	uPLeL = QMPset->value( "QMPset/uPLeL", true ).toBool();
	mQmpVisible = QMPset->value( "QMPset/mQmpVisible", false ).toBool();

	fileStruct = QMPset->value( "QMPset/fileStruct", true ).toBool();
	unknownType = QMPset->value( "QMPset/unknownType", true ).toBool();
	if ( !QMPset->value( "QMPset/scB" ).toBool() )
	{
		fst.ui.ccB->setChecked( true );
		colorScheme = QMPset->value( "QMPset/colorScheme" ).toString();
		if ( colorScheme.isEmpty() )
			colorScheme = defColorScheme;
	}
	else
		fst.ui.scB->setChecked( true );

	inDockObjName = QMPset->value( "QMPset/dock" ).toString();
	fsMaximized = QMPset->value( "QMPset/isMaximized" ).toBool();
	fileFilter = QMPset->value( "QMPset/fileFilter", true ).toBool();
	chImgs = QMPset->value( "QMPset/chImgs", true ).toBool();
	searchAction->setChecked( QMPset->value( "QMPset/searchInAllLists" ).toBool() );
	seekTime = QMPset->value( "QMPset/seekTime", false ).toBool();
	eoplB = QMPset->value( "QMPset/eoplB", true ).toBool();
	svrAddress = QMPset->value( "QMPset/svrAddress", QMPlayUpdatesAddress ).toString();
	lastVer = QMPset->value( "QMPset/lastVer" ).toUInt();

	if ( QFile::exists( "noautoupdates" ) )
		autoUpdates = false;
	else
		autoUpdates = true;
	autoUpdates = QMPset->value( "QMPset/autoUpdates", autoUpdates ).toBool();

	//Lista playlist
	listPLst[0].clear();
	listPLst[1].clear();
	listPLst[0] += QMPset->value( "ListPlist/fname" ).toStringList();
	listPLst[1] += QMPset->value( "ListPlist/name" ).toStringList();
	fp.createLPList(); //tworzy listę playlist
	fp.ui.listPlaylst->setCurrentRow( QMPset->value( "ListPlist/row" ).toInt() );

	//Playlista
	if ( savplist )
	{
		playList[0].clear();
		playList[1].clear();
		playList[2].clear();
		playList[3].clear();
		playList[4].clear();

		playList[1] += QMPset->value("Plist/items_type").toStringList();
		playList[3] += QMPset->value("Plist/items_times").toStringList();
		playList[2] += QMPset->value("Plist/items").toStringList();
		playList[0] += QMPset->value("Plist/items_titlelist").toStringList();
		playList[4] += QMPset->value("Plist/selItems").toStringList();
		plistTime = QMPset->value("Plist/items_titlelist_timeI" ).toInt();

		fp.createList();

		int _curplay = QMPset->value("Plist/curplay").toInt();
		if ( _curplay < 0 )
			_curplay = 0;
		if ( _curplay > titlelist->count() - 1 )
			_curplay = 0;
		titlelist->setCurrentRow( _curplay );

		plistthr.plus = QMPset->value("Plist/items_titlelist_+" ).toChar();

		if ( plistthr.plus != '+' )
			plistthr.plus = 32;

		fp.ui.plistTime->setText( Func.timeFormat( plistTime, 0 ) + plistthr.plus );
	}

	QString fname = QMPset->value( "QMPset/updateFName" ).toString();
	if ( !fname.isEmpty() )
	{
		if ( oldQMPVer < 1535-1 )
			fname = qApp->applicationDirPath() + "/" + fname;
		if ( oldQMPVer < QMPVer && QFile::exists( fname ) )
			QFile::remove( fname );
	}
	QMPset->remove( "QMPset/updateFName" );

	if ( playList[0].size() < 1 )
		isPlaying = false;

	if ( svrAddress.isEmpty() )
		svrAddress = QMPlayUpdatesAddress;

	if ( kBB < 128 || kBB > 1024 )
		kBB = 512;

	if ( oldQMPVer > 0 )
	{
		if ( oldQMPVer < 1519 ) //1.51.10
		{
			fileStruct = true;
			unknownType = true;
		}
		if ( oldQMPVer < 1529-1 )
		{
			QMPset->remove( "QMPOut/BufQForce" );
			QMPset->setValue( "QMPOut/buffQIfNeaded", false );
			QMPset->setValue( "QMPOut/visEff", true );
			QMPset->setValue( "QMPOut/QBuf", QMPset->value( "QMPOut/QBuf" ) == 8 ? 16 : QMPset->value( "QMPOut/QBuf" ) );
		}
		if ( oldQMPVer < 1534-1 )
		{
			if ( svrAddress != QMPlayUpdatesAddress )
				svrAddress = QMPlayUpdatesAddress;
		}
		if ( oldQMPVer < 1538-1 )
			Func.getLanguage();
		if ( oldQMPVer < 1544-1 )
		{
			QMPset->remove( "SndfileSet" );
			QMPset->remove( "SND_GENSet" );
#ifdef Q_WS_WIN
			QMPset->remove( "FuncAssociate" );
#endif
			QMPset->remove( "AOset/AOset" );
			QMPset->remove( "QEff1/QEff1" );
			QMPset->remove( "VisFFT1/VisFFT1" );
			QMPset->remove( "FuncMusicBrowser/FuncMusicBrowser" );
			QMPset->remove( "RAWSet/RAWSet" );
			QMPset->remove( "QMPOut/QMPOut" );
			QMPset->remove( "PAset/PAset" );
			QMPset->remove( "Vis1/Vis1" );
			QMPset->remove( "MMset/MMset" );
			QMPset->remove( "AACSet/AACSet" );
			QMPset->remove( "QEQset/QEQset" );
			QMPset->remove( "MP3Set/MP3Set" );
			QMPset->remove( "MPset/MPset" );
			QMPset->remove( "VorbisSet/VorbisSet" );
			QMPset->remove( "OpenALset/OpenALset" );
			QMPset->remove( "PulseAudioSet/PulseAudioSet" );
			QMPset->remove( "FuncRecord/FuncRecord" );
			QMPset->remove( "QEffResample/QEffResample" );
			QMPset->remove( "VisXOS/VisXOS" );
			QMPset->remove( "QMPInternet/QMPInternet" );
			QMPset->remove( "QMPExport/QMPExport" );
		}
		if ( oldQMPVer < 1546-1 )
		{
			QMPset->remove( "MPset/Enabled" );
			QMPset->remove( "MPset/formatSupport" );
			QMPset->remove( "MMset" );
#ifdef Q_WS_WIN
			QMPset->remove( "FuncAssociate" );
#endif
		}
	}

	delete QMPset;

	if ( f1Geo.x() < 1 )
		f1Geo.setX( qdw.width()/2  - f1.width()/2 );
	if ( f1Geo.y() < 1 )
		f1Geo.setY( qdw.height()/2 - f1h/2 - fp.height()/2 );
	if ( f1Geo.width() < 1 )
		f1Geo.setWidth( f1.width() );
	if ( f1Geo.height() < 1 )
		f1Geo.setHeight( f1.height() );

	if ( fpGeo.x() < 1 )
		fpGeo.setX( qdw.width()/2  - fp.width()/2 );
	if ( fpGeo.y() < 1 )
		fpGeo.setY( qdw.height()/2 - fp.height()/2 );
	if ( fpGeo.width() < 1 )
		fpGeo.setWidth( f1.width() );
	if ( fpGeo.height() < 1 )
		fpGeo.setHeight( fp.height() );

	if ( fsGeo.x() < 1 )
		fsGeo.setX( qdw.width()/2  - fs.width()/2 );
	if ( fsGeo.y() < 1 )
		fsGeo.setY( qdw.height()/2 - fs.height()/2 );
	if ( fsGeo.width() < 1 )
		fsGeo.setWidth( fs.width() );
	if ( fsGeo.height() < 1 )
		fsGeo.setHeight( fs.height() );

	if ( ffGeo.x() < 1 )
		ffGeo.setX( qdw.width()/2  - ff.width()/2 );
	if ( ffGeo.y() < 1 )
		ffGeo.setY( qdw.height()/2 - ff.height()/2 );
	if ( ffGeo.width() < 1 )
		ffGeo.setWidth( ff.width() );
	if ( ffGeo.height() < 1 )
		ffGeo.setHeight( ff.height() );

	if ( faGeo.x() < 1 )
		faGeo.setX( qdw.width()/2  - fa.width()/2 );
	if ( faGeo.y() < 1 )
		faGeo.setY( qdw.height()/2 - fa.height()/2 );
	if ( faGeo.width() < 1 )
		faGeo.setWidth( fa.width() );
	if ( faGeo.height() < 1 )
		faGeo.setHeight( fa.height() );

	if ( fprPos.x() < 1 )
		fprPos.setX( qdw.width()/2 - fpr.width()/2 );
	if ( fprPos.y() < 1 )
		fprPos.setY( qdw.height()/2 - fpr.height()/2 );

	if ( formInfo.posX < 1 )
		formInfo.posX = qdw.width()/2 - formInfo.width()/2;
	if ( formInfo.posY < 1 )
		formInfo.posY = qdw.height()/2 - formInfo.height()/2;
}

void Save::zapiszopcje()
{
	if ( usunSets )
		return;

	QMPset = new QSettings( QMPConf, QSettings::IniFormat );

	QMPset->setValue( "QMPset/lastAppPath", qApp->applicationDirPath() );
	QMPset->setValue( "QMPset/lastQMPExec", Func.plikbezsciezki( qApp->applicationFilePath() ) );
	QMPset->setValue( "QMPset/lastAppVer", QMPVersionI );
	QMPset->setValue( "QMPset/lastAppVer2", QMPVer2 );

	if ( !isPlaying )
		nrplay = titlelist->currentRow();

	if ( !f1.isMaximized() )
		QMPset->setValue( "WindowGeo/f1Geo", f1Geo );
	QMPset->setValue( "WindowGeo/fpGeo", fpGeo );
	QMPset->setValue( "WindowGeo/fsGeo", fsGeo );
	QMPset->setValue( "WindowGeo/ffGeo", ffGeo );
	QMPset->setValue( "WindowGeo/faGeo", faGeo );
	QMPset->setValue( "WindowGeo/fprPos", fprPos );

	QMPset->setValue("WindowPos/fIposX",formInfo.posX);
	QMPset->setValue("WindowPos/fIposY",formInfo.posY);


	QMPset->setValue("QMPset/styl",styl);
	QMPset->setValue("QMPset/language",language);

	QMPset->setValue("QMPset/Bpmpp", Bpmpp);

	if ( fs.ui.savposBox->isChecked() )
	{
		QMPset->setValue("QMPset/ispl",true);
		QMPset->setValue("QMPset/isPlaying", isPlaying);
	}
	else
	{
		QMPset->setValue("QMPset/ispl",false);
		QMPset->setValue("QMPset/isPlaying", false);
	}

	QMPset->setValue("QMPset/zipl", zipl);
	QMPset->setValue("QMPset/zvpl", zvpl);
	QMPset->setValue("QMPset/zplV", zplV);
	QMPset->setValue("QMPset/zdefB", zdefB);
	QMPset->setValue("QMPset/proce",proce);

	QMPset->setValue("QMPset/errnxt", errnxt);
	QMPset->setValue("QMPset/playnxt", playnxt);
	QMPset->setValue("QMPset/listplaylist", listplaylist);
	QMPset->setValue("QMPset/savplist", savplist);
	QMPset->setValue("QMPset/closeExportOnNxt", closeExportOnNxt);
	QMPset->setValue("QMPset/po", po);

	if ( !bezzapisulisty && !plistthr.isRunning() )
		QMPset->remove("Plist");

	QMPset->setValue("Plist/shwplaylist", shwplaylist);
	QMPset->setValue("Plist/fpnf1", fpnf1);
	QMPset->setValue("Plist/fpzf1", fpzf1);

	if ( fs.ui.pbLBox->isChecked() )
		QMPset->setValue("QMPset/pbL",true);
	else
		QMPset->setValue("QMPset/pbL",false);
	if ( fs.ui.pbRBox->isChecked() )
		QMPset->setValue("QMPset/pbR",true);
	else
		QMPset->setValue("QMPset/pbR",false);

	QMPset->setValue("QMPset/nextXsV",nextXsV);
	QMPset->setValue("QMPset/inTray",inTray);
	QMPset->setValue("QMPset/kBB",kBB);;
	QMPset->setValue("QMPset/bladinfoB",bladinfoB);
	QMPset->setValue("QMPset/uPLe",uPLe); //odświeża wpis w playliście po rozpoczęciu odtwarzania
	QMPset->setValue("QMPset/uPLeL",uPLeL); //odczytuje z playlist m3u i pls tytuly i czas (szybkie ładowanie)
	QMPset->setValue("QMPset/fileStruct",fileStruct);
	QMPset->setValue("QMPset/unknownType",unknownType);
	QMPset->setValue("QMPset/scB",fst.ui.scB->isChecked());
	QMPset->setValue("QMPset/colorScheme",colorScheme);

	QMPset->setValue("QMPset/dock",inDockObjName);
	QMPset->setValue("QMPset/isMaximized",f1.isMaximized());
	QMPset->setValue("QMPset/fileFilter",fileFilter);
	QMPset->setValue("QMPset/chImgs",chImgs);
	QMPset->setValue("QMPset/searchInAllLists",searchAction->isChecked());
	QMPset->setValue("QMPset/mQmpVisible",mQmpVisible);
	QMPset->setValue("QMPset/seekTime",seekTime);
	QMPset->setValue("QMPset/eoplB",eoplB);
	QMPset->setValue("QMPset/autoUpdates",autoUpdates);
	QMPset->setValue("QMPset/svrAddress",svrAddress);
	QMPset->setValue("QMPset/lastVer",lastVer);

	if ( !bezzapisulisty )
	{
		//Lista playlist
		QMPset->setValue("ListPlist/fname",listPLst[0]);
		QMPset->setValue("ListPlist/name",listPLst[1]);
		QMPset->setValue("ListPlist/row",fp.ui.listPlaylst->currentRow());

		//Playlista
		if ( plistthr.isRunning() )
			plistthr.doExit();
		else if ( savplist )
		{
			QMPset->setValue("QMPset/curP", curP);

			QStringList plQSL;
			for ( int i = 0 ; i<playList[2].size() ; i++)
				plQSL += playList[2][i];
			QMPset->setValue("Plist/items", plQSL );
			QMPset->setValue("Plist/items_titlelist", playList[0] );
			QMPset->setValue("Plist/items_times", playList[3] );
			QMPset->setValue("Plist/items_type", playList[1] );
			QMPset->setValue("Plist/items_titlelist_timeI" , plistTime );

			QMPset->setValue("Plist/curplay", nrplay );

			QMPset->setValue("Plist/items_titlelist_+", plistthr.plus );

			QMPset->setValue("Plist/selItems", playList[4] );
		}
	}
	bezzapisulisty = false;

	QMPset->setValue( "QMPset/updateFName", fd.fname );

	QMPset->sync();
	delete QMPset;
}
