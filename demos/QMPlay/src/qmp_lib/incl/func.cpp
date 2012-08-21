QString Func::timeFormat(int pltime, bool Space)
{
	QString space;
	if ( Space )
		space = " ";
	else
		space = "";
	if ( pltime < 0 )
		return "??"+space+":"+space+"??";
	QString qTim,qSek,qMin;
	int sek,min,hour;

	sek = pltime % 60;
	min = pltime / 60;

	if (min < 10)
		qMin = "0" + QString::number(min);
	else if (min < 60)
		qMin = QString::number(min);
	else if (min >= 60)
	{
		hour = min / 60;
		min = min % 60;

		if (min < 10)
			qMin = "0" + QString::number(min);
		else if (min < 60)
				qMin = QString::number(min);

		qMin = QString::number(hour) + space+":"+space + qMin;
	}

	if (sek < 10)
		qSek = "0" + QString::number(sek);
	else
		qSek = QString::number(sek);

	qTim = qMin + space+":"+space + qSek ;

	return qTim;
}

QString Func::sciezkadopliku( QString pth )
{
	if ( pth.isEmpty() )
		return pth;
	if ( pth[ pth.length() - 1 ] == '/' )
		return pth;
    int i(0);
    for ( i = pth.length() ; i > 0; i-- )
		if ( pth[i] == '/' )
			break;
    pth.truncate(i);
    return pth;
}

QString Func::plikbezsciezki( QString pth )
{
	if ( pth.isEmpty() )
		return pth;
	if ( pth[ pth.length() - 1 ] == '/' )
		return pth;
	int i= 0, y = pth.length();
	bool OK = false;
    for ( i = y; i >= 0; i-- )
	{
		if ( pth[i] == '/' )
		{
			OK = true;
			break;
		}
	}
	if ( OK )
    	return pth.right(y-i-1);
	return pth;
}

QString Func::getExt( QString pth, bool bezKropki )
{
	if ( !bezKropki )
		return getExt( pth );
	else
	{
		int i;
		for ( i = pth.length() ; i > 0 ; i-- )
			if ( pth[i] == '.' )
				break;
		return pth.right( pth.length()-i-1 ).toLower();
	}
}
QString Func::getExt( QString pth )
{
	int i;
	for ( i = pth.length() ; i > 0 ; i-- )
		if ( pth[i] == '.' )
			break;
	return pth.right( pth.length()-i ).toLower();
}

bool Func::checkFormat(QString exts, QString pth)
{
	QString ext;
	exts = exts.toLower();
	QStringList extsL = exts.split(";", QString::SkipEmptyParts);
	for ( int i = pth.length() ; i >= 0 ; i-- )
	{
		if ( pth[i].toAscii() == '.' )
		{
			ext = pth.right( pth.length() - i - 1 );
			break;
		}
	}
	ext = ext.toLower();
	for ( int i = 0 ; i < extsL.count() ; i++ )
		if ( extsL[i] == ext )
			return true;
	return false;
}

QString Func::getExts( bool b )
{
	QString Extensions;
	if ( !b ) //dialogWindow
	{
		Extensions = Texts[30]/**Wszystkie pliki*/+" (*)";
		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			QString ExtsTmp = QString( *Iplugins[w]->formatSupport ).toLower();
			if ( ExtsTmp.isEmpty() || ExtsTmp[0] == ' ' )
				continue;
			if ( ExtsTmp[0] != ';' )
				ExtsTmp.prepend( ";" );
			ExtsTmp.replace( ";", " *."  );
			ExtsTmp.remove( 0, 1 );
			QString plName = Iplugins[w]->pluginInfo->Name;
			plName.replace( '(', '[' );
			plName.replace( ')', ']' );
			Extensions += ";;" + plName + " (" + ExtsTmp + ")";
		}
	}
	else //return in QLib
	{
		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			Extensions += QString( *Iplugins[w]->formatSupport ).toLower();
			if ( Extensions[ Extensions.length()-1 ] != ';' )
				Extensions += ";";
		}
	}
	return Extensions;
}

InputPlugin *Func::getMusicFormat(QString plType, QString plFile)
{
	if ( plType == "file" )
	{
		if ( plFile.isEmpty() )
			return NULL;
		bool isExtOK = getExts( true ).contains( getExt( plFile, true ) );
		for ( int w = 0 ; w < Iplugins.size() ; w++ )
		{
			if ( !fileStruct || ( fileStruct && unknownType && isExtOK ) )
			{
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && checkFormat( *Iplugins[w]->formatSupport, plFile ) )
					return Iplugins[w];
			}
			else if ( !FileFormatSupportOpened )
			{
				FileFormatSupportOpened = true;
				if ( Iplugins[w]->pluginInfo->swOnOff(0) && Iplugins[w]->FileFormatSupport && Iplugins[w]->FileFormatSupport( plFile.toUtf8() ) )
				{
					FileFormatSupportOpened = false;
					return Iplugins[w];
				}
				FileFormatSupportOpened = false;
			}
		}
		return NULL;
	}

	if ( plType.left(7) == "plugin:" || plType.left(9) == "internet:" )
	{
		QString typTmp = plType;
		if ( plType.left(7) == "plugin:" )
			typTmp = getTypePlugin( typTmp );
		if ( plType.left(9) == "internet:" )
			typTmp = typTmp.right( typTmp.size() - 9 );

		for ( int w = 0 ; w < Iplugins.size() ; w++ )
			if ( Iplugins[w]->pluginInfo->swOnOff(0) && typTmp == (QString)Iplugins[w]->pluginInfo->Name )
				return Iplugins[w];

		return NULL;
	}
	return NULL;
}

bool Func::chkQMPlayVer( struct PluginInfo *pluginInfo, QString Type )
{
	if ( !pluginInfo )
		return false;

	if ( Type.isEmpty() )
		Type = pluginInfo->Type;

	uint Ver = pluginInfo->QMPVer;

	if ( Type == "OutputPlugin" && Ver == QMPlayOutputPluginVer )
		return true;
	else if ( Type == "InputPlugin" && Ver == QMPlayInputPluginVer )
		return true;
	else if ( Type == "VisPlugin" && Ver == QMPlayVisPluginVer )
		return true;
	else if ( Type == "EffectPlugin" && Ver == QMPlayEffectPluginVer )
		return true;
	else if ( Type == "FuncPlugin" && Ver == QMPlayFuncPluginVer )
		return true;
	else if ( Type == "PlaylistPlugin" && Ver == QMPlayPlaylistPluginVer )
		return true;
	else if ( Type == "QMPlayExport" && Ver == QMPlayExportVer )
		return true;
	else if ( Type == "QMPlayEqualizer" && Ver == QMPlayEqualizerVer )
		return true;
	else
		return false;
}

void Func::searchPlugins(bool b)
{
	struct PluginInfo *pluginInfo = NULL;
	QStringList plugList;
	bool OK(0), DUP(0);

	pluginsList[0].clear();
	pluginsList[1].clear();
	pluginsList[2].clear();
	pluginsList[3].clear();

	QStringList pL[4];
	QList<PluginInfo*> pIL;

	QDir qdir(qApp->applicationDirPath()+"/plugins");
	plugList = qdir.entryList( QStringList(ppN+"*"+libExt), QDir::Files, QDir::Name );

	pluginInfoList.clear();

	for ( int w = 0 ; w < plugList.count() ; w++ )
	{
		plugList[w] = "plugins/" + plugList[w];
		TmpLibrary.setFileName( plugList[w] );
		if(b)
			printf( "	Loading: \"%s\"...", plugList[w].toAscii().data() );
		if ( TmpLibrary.load() )
		{
			OK  = false;
			DUP = false;
			pluginInfo = (PluginInfo*)TmpLibrary.resolve("pluginInfo");
			if ( chkQMPlayVer( pluginInfo, "" ) )
			{
				if ( !pL[1].contains( pluginInfo->Name ) )
				{
					pL[0] += plugList[w];
					pL[1] += pluginInfo->Name;
					pL[2] += pluginInfo->Type;
					pL[3] += "";
					pIL += pluginInfo;
					if(b)
						printf(" OK\n");
					OK = true;
				}
				else
					DUP = true;
			}
			if ( !OK )
			{
				if ( !DUP )
				{
					if(b)
						printf(" FAILED\n");
					PlugLoadErr( plugList[w], Texts[29] /**"plik nie jest poprawnym plikiem QMP!"*/ );
				}
				else
				{
					if(b)
						printf(" DUPLICATE\n");
					PlugLoadErr( plugList[w], Texts[122] /**"duplikat"*/ );
				}
			}
		}
		else
		{
			if(b)
				printf(" FAILED\n");
			PlugLoadErr( TmpLibrary.errorString() );
		}
	}

	for ( int i = 0 ; i < pL[0].count() ; i++ )
	{
		pluginsList[0] += "";
		pluginsList[1] += "";
		pluginsList[2] += "";
		pluginsList[3] += "";
		pluginInfoList += NULL;
	}

	QMPset = new QSettings (QMPConf,QSettings::IniFormat);
	for ( int i = 0 ; i < pL[0].count() ; i++ )
	{
		int w = QMPset->value( "PluginSort/"+pL[0][i] ).toInt() - 1;
		if ( w >= 0 && w < pL[0].count() )
		{
			pluginsList[0][w] = pL[0][i];
			pluginsList[1][w] = pL[1][i];
			pluginsList[2][w] = pL[2][i];
			pluginsList[3][w] = pL[3][i];
			pluginInfoList[w] = pIL[i];
		}
		else
		{
			QMPset->remove( "PluginSort" );

			pluginsList[0].clear();
			pluginsList[1].clear();
			pluginsList[2].clear();
			pluginsList[3].clear();
			pluginInfoList.clear();

			pluginsList[0] += pL[0];
			pluginsList[1] += pL[1];
			pluginsList[2] += pL[2];
			pluginsList[3] += pL[3];
			pluginInfoList += pIL;

			break;
		}
	}

	pL[0].clear();
	pL[1].clear();
	pL[2].clear();
	pL[3].clear();
	pIL.clear();

	QMPset->sync();
	delete QMPset;
}

void Func::unloadPlugins( int q )
{
	switch (q)
	{
		case 0:
			for ( int z = 0 ; z < Vplugins.size() ; z++ )
				Vplugins[z]->closePlug();
			Vplugins.clear();
			break;
		case 1:
			for ( int z = 0 ; z < Eplugins.size() ; z++ )
				Eplugins[z]->closePlug();
			Eplugins.clear();
			break;
		case 2:
			for ( int z = 0 ; z < Oplugins.size() ; z++ )
				Oplugins[z]->closePlug(false);
			Oplugins.clear();
			break;
		case 3:
			if ( equalizer )
				equalizer->closePlug();
			break;
		case 4:
			for ( int z = 0 ; z < Fplugins.size() ; z++ )
				Fplugins[z]->closePlug();
			Fplugins.clear();
			break;
		case 5:
			if ( QExport )
				QExport->closePlug(false);
			break;
		case 6:
			for ( int z = 0 ; z < Iplugins.size() ; z++ )
				Iplugins[z]->closePlug(false,false);
			Iplugins.clear();
			break;
		case 7:
			Pplugins.clear();
			break;
	}
}

void Func::unloadAllPlugins()
{
	unloadPlugins(0);
	unloadPlugins(1);
	unloadPlugins(2);
	unloadPlugins(3);
	unloadPlugins(4);
	unloadPlugins(5);
	unloadPlugins(6);
	unloadPlugins(7);
}

QString PlugLoadErrStr;
void Func::PlugLoadErr( QString file )
{
	PlugLoadErr( file, "" );
}
void Func::PlugLoadErr( QString file, QString err )
{
	if ( PlugLoadErrStr.isEmpty() )
		PlugLoadErrStr = Texts[28] /** "Nie mozna zaladowac bibliotek" */;
	if ( !err.isEmpty() )
		err = ", " + err;
	PlugLoadErrStr += "\n   -> " + file + err;
}
void Func::showPlugLoadErr()
{
	if ( !PlugLoadErrStr.isEmpty() )
	{
		fa.add( PlugLoadErrStr );
		QMessageBox::warning( NULL, "QMPlay", PlugLoadErrStr );
		PlugLoadErrStr.clear();
	}
}

void Func::loadPlugins( bool b = 0 )
{
	pluginsLoaded = false;

	QString tmpInDockObjName = inDockObjName;

	PlugLoadErrStr.clear();

	if ( !QMPWait_n_close( QOut_STOP_AND_WAIT ) )
		QOut->close();

	if ( !b )
		f1.stop();

	unloadAllPlugins();

	QMPset = new QSettings (QMPConf,QSettings::IniFormat);
	for (int w = 0 ; w < fs.ui.pluginList->count() ; w++)
		//dopisuje checkstate - 1 ( zero dla niezaznaczonego daje -1 do pliku .QMP.conf )
		QMPset->setValue( "PluginCheck/"+pluginsList[1][w], fs.ui.pluginList->item(w)->checkState() - 1 );
	QMPset->sync();
	delete QMPset;

	fs.ui.pluginList->clear();

	int w(0);
	for ( w = 0 ; w < tabs.size() ; w++ )
		delete tabs[w];
	tabs.clear();
	for ( w = 0 ; w < scrolls.size() ; w++ )
		delete scrolls[w];
	scrolls.clear();
	for ( w = fs.ui.libsT->count() ; w >= 0 ; w-- )
		fs.ui.libsT->removeTab(w);
	for ( w = fs.ui.inputT->count() ; w >= 0 ; w-- )
		fs.ui.inputT->removeTab(w);
	for ( w = fs.ui.outputT->count() ; w >= 0 ; w-- )
		fs.ui.outputT->removeTab(w);
	for ( w = fs.ui.effectT->count() ; w >= 0 ; w-- )
		fs.ui.effectT->removeTab(w);
	for ( w = fs.ui.visT->count() ; w >= 0 ; w-- )
		fs.ui.visT->removeTab(w);
	for ( w = fs.ui.funcT->count() ; w >= 0 ; w-- )
		fs.ui.funcT->removeTab(w);
	for ( w = ff.ui.tabWidget->count() ; w >= 0 ; w-- )
		ff.ui.tabWidget->removeTab(w);

	menuFromPlugin.clear();
	menuAdd.clear();
	menuAdd.setTitle( Texts[39] /** "Dodaj"  */ );
	menuAdd.addAction( f1.ui.actionMuzyka );
	menuAdd.addAction( f1.ui.actionDir );
	menuAdd.addAction( f1.ui.netA );
	menuAdd.addSeparator();
	menuAdd.addAction( "Separator", &fp, SLOT( addSeparator() ) );
	menuAdd.addSeparator();

	searchPlugins(b);

	QOutWidget->setObjectName("QMPOutTab");
	QOut->opcje(QOutWidget);
	fs.ui.libsT->addTab( QOutWidget, QIcon( ":/icons/sound.png" ), "QMPlay Output" );

	if ( !equalizer && QFile::exists(QMPEqu+libExt) )
	{
		equalizer_lib.setFileName( QMPEqu+libExt );
		if ( equalizer_lib.load() )
		{
			struct PluginInfo *pluginInfo = (PluginInfo*)equalizer_lib.resolve( "pluginInfo" );
			if ( chkQMPlayVer( pluginInfo, "QMPlayEqualizer" ) )
				equalizer = (QMP_effects*) equalizer_lib.resolve("QMP_equalizer");
			if ( !equalizer )
				PlugLoadErr( QMPEqu+libExt, Texts[29] /** Equalizer */ );
		}
		else
			PlugLoadErr( equalizer_lib.errorString() );
	}
	if ( equalizer )
	{
		if ( equalizer->setQmpLib )
			equalizer->setQmpLib( QLib );

		equalizer->Init();

		if ( equalizer->setLang )
			equalizer->setLang( langFile );

		QEqWidget->setObjectName("EqualizerTab");
		equalizer->opcje(QEqWidget);

		QIcon plugIcon;
		if ( equalizer->pluginInfo->pixmap && !equalizer->pluginInfo->pixmap->isNull() )
			plugIcon = *equalizer->pluginInfo->pixmap;
		else
			plugIcon = QMPIcon;

		fs.ui.libsT->addTab( QEqWidget, plugIcon, "Equalizer" );

		f1.ui.eqB->setChecked( equalizer->showOptions(0) );
	}

	//Eksport
	f1.ui.aWAV->setText( Texts[44] );
	if ( !QExport && QFile::exists(QMPWav+libExt) )
	{
		WAVE.setFileName(QMPWav+libExt);
		if ( WAVE.load() )
		{
			struct PluginInfo *pluginInfo = (PluginInfo*)WAVE.resolve( "pluginInfo" );
			if ( chkQMPlayVer( pluginInfo, "QMPlayExport" ) )
				QExport = (QMP_Export*) WAVE.resolve("Explug");
			if ( !QExport )
				PlugLoadErr( QMPWav+libExt, Texts[29]/** Eksporter */);
		}
		else
			PlugLoadErr( WAVE.errorString() );
	}
	if ( QExport )
	{
		if ( QExport->setQmpLib )
			QExport->setQmpLib( QLib );

		QExport->Init(false,0,0,0,"");

		if ( QExport->setLang )
			QExport->setLang( langFile );

		f1.ui.aWAV->setText( Texts[78] + " " + *QExport->mnu);
		if ( QExport->pluginInfo->pixmap && !QExport->pluginInfo->pixmap->isNull() )
			f1.ui.aWAV->setIcon( QIcon(*QExport->pluginInfo->pixmap) );

		if ( *QExport->hOptions )
		{
			QExportWidget->setObjectName("QMPExportTab");
			QExport->opcje(QExportWidget);

			QIcon plugIcon;
			if ( QExport->pluginInfo->pixmap && !QExport->pluginInfo->pixmap->isNull() )
				plugIcon = *QExport->pluginInfo->pixmap;
			else
				plugIcon = QMPIcon;

			fs.ui.libsT->addTab( QExportWidget, plugIcon, "QMPlay Export" );
		}
	}

	QMPset = new QSettings (QMPConf,QSettings::IniFormat);
	//szukanie pluginow
	for ( int w = 0 ; w < pluginsList[0].count() ; w++ )
	{
		//jezeli z pliku .qmp.conf wartość do danego plugina wynosi "-1" to nie jest zaznaczony
		if ( QMPset->value( "PluginCheck/"+pluginsList[1][w] ).toInt() == -1 )
			pluginsList[3][w] = "n";
		else
			pluginsList[3][w] = "y";
	}
	for ( int w = 0 ; w < pluginsList[0].count() ; w++ )
	{
		if ( pluginsList[3][w] != "y" )
			continue;

		int W(0);

		if ( pluginsList[2][w] == "InputPlugin" )
		{
			TmpLibrary.setFileName(pluginsList[0][w]);
			if ( (InputPlugin*) TmpLibrary.resolve("Iplug") )
			{
				Iplugins += (InputPlugin*) TmpLibrary.resolve("Iplug");
				W = Iplugins.size()-1;

				Iplug = Iplugins[W];

				if ( Iplug->setQmpLib )
					Iplug->setQmpLib( QLib );

				Iplug->Init(false,-1);

				if ( Iplug->setLang )
					Iplug->setLang( langFile );

				QIcon plugIcon;
				if ( Iplug->pluginInfo->pixmap && !Iplug->pluginInfo->pixmap->isNull() )
					plugIcon = *Iplug->pluginInfo->pixmap;
				else
					plugIcon = QMPIcon;
				if ( *Iplug->hOptions )
					fs.ui.inputT->addTab(addScrollArea(Iplug->opcje,QString::number(W)),plugIcon,pluginsList[1][w]);

				if ( Iplug->getMenu )
				{
					QAction *act = 0;
					Iplug->getMenu( &act );
					if ( act )
					{
						menuFromPlugin.addAction( act );
						menuAdd.addAction( act );
					}
				}
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		if ( pluginsList[2][w] == "OutputPlugin" )
		{
			TmpLibrary.setFileName(pluginsList[0][w]);
			if ( (OutputPlugin*) TmpLibrary.resolve("Oplug") )
			{
				Oplugins += (OutputPlugin*) TmpLibrary.resolve("Oplug");
				W = Oplugins.size()-1;

				if ( Oplugins[W]->setQmpLib )
					Oplugins[W]->setQmpLib( QLib );

				Oplugins[W]->Init(false,0,0,0,0); //odczyt opcji

				if ( Oplugins[W]->setLang )
					Oplugins[W]->setLang( langFile );

				QIcon plugIcon;
				if ( Oplugins[W]->pluginInfo->pixmap && !Oplugins[W]->pluginInfo->pixmap->isNull() )
					plugIcon = *Oplugins[W]->pluginInfo->pixmap;
				else
					plugIcon = QMPIcon;
				if ( *Oplugins[W]->hOptions )
					fs.ui.outputT->addTab(addScrollArea(Oplugins[W]->opcje,QString::number(W)),plugIcon,pluginsList[1][w]);
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		if ( pluginsList[2][w] == "EffectPlugin" )
		{
			TmpLibrary.setFileName( pluginsList[0][w] );
			if ( (QMP_effects*) TmpLibrary.resolve("Eplug") )
			{
				Eplugins += (QMP_effects*) TmpLibrary.resolve("Eplug");
				W = Eplugins.size()-1;

				if ( Eplugins[W]->setQmpLib )
					Eplugins[W]->setQmpLib( QLib );

				Eplugins[W]->Init(); //odczyt opcji

				if ( Eplugins[W]->setLang )
					Eplugins[W]->setLang( langFile );

				QIcon plugIcon;
				if ( Eplugins[W]->pluginInfo->pixmap && !Eplugins[W]->pluginInfo->pixmap->isNull() )
					plugIcon = *Eplugins[W]->pluginInfo->pixmap;
				else
					plugIcon = QMPIcon;
				if ( *Eplugins[W]->hOptions )
					fs.ui.effectT->addTab(addScrollArea(Eplugins[W]->opcje,QString::number(W)),plugIcon,pluginsList[1][w]);
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		if ( pluginsList[2][w] == "VisPlugin" )
		{
			TmpLibrary.setFileName( pluginsList[0][w] );
			if ( (VisPlugin*) TmpLibrary.resolve("Vplug") )
			{
				Vplugins += (VisPlugin*) TmpLibrary.resolve("Vplug");
				W = Vplugins.size()-1;

				if ( Vplugins[W]->setQmpLib )
					Vplugins[W]->setQmpLib( QLib );

				Vplugins[W]->Init(); //odczyt opcji

				if ( Vplugins[W]->setLang )
					Vplugins[W]->setLang( langFile );

				if ( FirstTime && Vplugins[W]->pluginInfo->swOnOff(0) && *Vplugins[W]->okno )
				{
					FirstTime = false;
					zvpl = true;
					zdefB = false;
				}

				QIcon plugIcon;
				if ( Vplugins[W]->pluginInfo->pixmap && !Vplugins[W]->pluginInfo->pixmap->isNull() )
					plugIcon = *Vplugins[W]->pluginInfo->pixmap;
				else
					plugIcon = QMPIcon;
				if ( *Vplugins[W]->hOptions )
					fs.ui.visT->addTab(addScrollArea(Vplugins[W]->opcje,QString::number(W)),plugIcon,pluginsList[1][w]);
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		if ( pluginsList[2][w] == "FuncPlugin" )
		{
			TmpLibrary.setFileName(pluginsList[0][w]);
			if ( (FuncPlugin*) TmpLibrary.resolve("Fplug") )
			{
				Fplugins += (FuncPlugin*) TmpLibrary.resolve("Fplug");
				W = Fplugins.size()-1;

				if ( Fplugins[W]->setQmpLib )
					Fplugins[W]->setQmpLib( QLib );

				Fplugins[W]->Init(); //odczyt opcji

				if ( Fplugins[W]->setLang )
					Fplugins[W]->setLang( langFile );

				QIcon plugIcon;
				if ( Fplugins[W]->pluginInfo->pixmap && !Fplugins[W]->pluginInfo->pixmap->isNull() )
					plugIcon = *Fplugins[W]->pluginInfo->pixmap;
				else
					plugIcon = QMPIcon;
				if ( *Fplugins[W]->hOptions )
					fs.ui.funcT->addTab(addScrollArea(Fplugins[W]->opcje,QString::number(W)),plugIcon,pluginsList[1][w]);
				if ( *Fplugins[W]->hFuncWin )
					ff.ui.tabWidget->addTab(addScrollArea(Fplugins[W]->show,QString::number(W)),plugIcon,pluginsList[1][w]);
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		if ( pluginsList[2][w] == "PlaylistPlugin" )
		{
			TmpLibrary.setFileName( pluginsList[0][w] );
			if ( (PlaylistPlugin*) TmpLibrary.resolve( "Pplug" ) )
			{
				Pplugins += (PlaylistPlugin*) TmpLibrary.resolve("Pplug");
				W = Pplugins.size()-1;

				if ( Pplugins[W]->setQmpLib )
					Pplugins[W]->setQmpLib( QLib );
			}
			else
				PlugLoadErr(TmpLibrary.errorString());
		}

		putchar( '.' );
		fflush( stdout );
	} //zakonczenie petli
	putchar( '\n' );

	QMPset->sync();
	delete QMPset;

	Iplug = (InputPlugin*) &N0input;

	fs.createPluginList();

	if ( Vplugins.size() > 0 && secondLoad )
		fs.zvplV();

	fl.setLangLibs();

	ff.resize( ff.size() );

	if ( secondLoad )
	{
		inDockObjName = tmpInDockObjName;
		fdck.applyDock();
	}
	secondLoad = true;

	if ( !b )
		showPlugLoadErr();

	pluginsLoaded = true;
}

QWidget *Func::addScrollArea( void (*SHOW)(QWidget*), QString oName )
{
	tabs += new QWidget;
	int WT = tabs.size()-1;
	SHOW(tabs[WT]);

	scrolls += new QScrollArea;
	int W = scrolls.size()-1;
	scrolls[W]->setWidgetResizable(true);
	scrolls[W]->setFrameShape( QFrame::NoFrame );
	scrolls[W]->setWidget(tabs[WT]);
	scrolls[W]->setObjectName(oName);

	return scrolls[W];
}

void Func::CURP(QString _curP)
{
	curP = sciezkadopliku(_curP);
#ifdef Q_WS_WIN
	if ( curP.length() == 2 )
		curP += "/";
#else
	if ( curP.isEmpty() )
		curP = "/";
#endif
}

int Func::nr() //numer wybranego pliku z playlisty
{
	return titlelist->currentRow();
}

bool Func::chkFNr( int X )
{
	if ( X < 0 || X > playList[2].count() - 1 )
		return false;
	else
		return true;
}

void Func::getVol()
{
	int L(0),R(0);
	QOut->getVol( &L, &R );
	f1.ui.volLS->setValue(L);
	f1.ui.volRS->setValue(R);
}

QString Func::checkInternetFormat( QString adres )
{
	QString pName;
	for ( int w = 0 ; w < Iplugins.size() ; w++ )
	{
		if ( Iplugins[w]->pluginInfo->swOnOff(0) /* enabled */ && Iplugins[w]->InternetFormatSupport )
		{
			pName = Iplugins[w]->InternetFormatSupport( adres.toUtf8() );
			if ( !pName.isEmpty() )
				break;
		}
	}
	return pName;
}

bool Func::isPlayListExt( QString ext )
{
	if ( ext == ".qplst" )
		return true;
	for ( int i = 0 ; i < Pplugins.size() ; i++ )
	{
		foreach ( QString e, Pplugins[ i ]->getExts().toLower().split( ' ', QString::SkipEmptyParts ) )
		{
			if ( e == ext )
				return true;
		}
	}
	return false;
}

QString Func::getPlistExts( bool singleLine )
{
	QString exts;
	if ( singleLine )
	{
		exts = Texts[35]/**Playlisty*/ + " (*.qplst";
		for ( int i = 0 ; i < Pplugins.size() ; i++ )
			exts += " " + Pplugins[i]->getExts().replace( ".", "*." );
		exts += ")";
	}
	else
	{
		exts = "*.qplst (*.qplst)";
		for ( int i = 0 ; i < Pplugins.size() ; i++ )
		{
			QStringList pEL = Pplugins[i]->getExts().replace( ".", "*." ).split( ' ' );
			foreach( QString pE, pEL )
				exts += ";;" + pE + " (" + pE + ")";
		}
	}
	return exts;
}

QString Func::getFSize( long long fSize )
{
	QString strfSize;
	if ( fSize < 0 )
		strfSize = "?";
	else if ( fSize < 1024 && fSize >= 0 )
		strfSize = QString::number( fSize ) + "B";
	else if ( fSize >= 1024 && fSize < 1024.*1024. )
		strfSize = QString::number( fSize / 1024.,'f', 2 ) + "kB";
	else if ( fSize >= 1024*1024 && fSize < 1024.*1024.*1024. )
		strfSize = QString::number( fSize / ( 1024.*1024. ),'f', 2 ) + "MB";
	else if ( fSize >= 1024*1024*1024 )
		strfSize = QString::number( fSize / ( 1024.*1024.*1024. ),'f', 2 ) + "GB";
	return strfSize;
}

QString Func::getFNamePlugin( QString file, bool b )
{
	int j = file.indexOf( '.' );
	if ( j >= 0 )
	{
		file = file.left( j );
		file = file.right( file.length() - (b ? 9 : 7) );
	}
	else
		file.clear();
	return file;
}

QString Func::getTypePlugin( QString file )
{
	int j = file.indexOf( '.' );
	if ( j >= 0 )
		file = file.right( file.length() - 1 - j );
	else
		file = file.right( file.length() - 7 );
	return file;
}

void Func::addToList( QStringList &list, int where, QStringList list2 )
{
	if ( where > list.count() )
		return;
	QStringList tmpList = list;
	list.clear();
	for ( int i = 0 ; i < where ; i++ )
		list += tmpList[i];
	for ( int i = where ; i < where+list2.count() ; i++ )
		list += list2[i-where];
	for ( int i = where+list2.count() ; i < tmpList.count()+list2.count() ; i++ )
		list += tmpList[i-list2.count()];
}

QString Func::getFromPlugInfo( QString file, QPixmap &pix, InputPlugin *plugStruct )
{
	int X = nr();
	QString plugTxt;
	if ( plugStruct->getMusStr )
	{
		int Type(0);
		if ( playList[1][X].left( 7 ) == "plugin:" )
			Type = 1;
		else if ( playList[1][X].left( 9 ) == "internet:" )
			Type = 2;
		if ( Type != 0 || ( Type == 0 && QFile::exists( file ) ) )
		{
			QString TMP = file;
			if ( TMP.left( 9 ) == "plugin://" )
				TMP = getFNamePlugin( TMP, 1 );

			plugTxt = "\n" + plugStruct->getMusStr(TMP.toUtf8(),Type,pix);
			if ( !pix.isNull() )
				pix = pix.scaledToWidth( 64, Qt::SmoothTransformation );
		}
	}
	if ( pix.isNull() )
	{
		if ( plugStruct->pluginInfo->pixmap && !plugStruct->pluginInfo->pixmap->isNull() )
			pix = *plugStruct->pluginInfo->pixmap;
		else
			pix = QMPIconPix;
	}
	return plugTxt;
}

int Func::getCpuSpeed()
{
	int cpuSpd(-1);
#ifdef Q_WS_WIN
	int buf;
	DWORD dwBufSize = sizeof( int );
	if ( !SHGetValue( HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", L"~MHz", NULL, &buf, &dwBufSize ) )
		cpuSpd = buf;
#endif
#ifdef Q_OS_LINUX
	FILE *f = fopen( "/proc/cpuinfo", "rb" );
	if ( f )
	{
		QString cpuinfo;
		while ( !feof( f ) )
			cpuinfo += fgetc( f );
		fclose(f);
		cpuinfo.replace( '\n', ':' );
		cpuinfo.replace( '	', "" );
		cpuinfo.replace( ": ", ":" );
		QStringList cpuInfoList = cpuinfo.split( ':', QString::SkipEmptyParts );
		int idx = cpuInfoList.indexOf( "cpu MHz" ) + 1;
		if ( idx > 0 )
			cpuSpd = atoi( cpuInfoList[ idx ].toAscii() );
		else
		{
			idx = cpuInfoList.indexOf( "clock" ) + 1;
			if ( idx > 0 )
				cpuSpd = atoi( cpuInfoList[ idx ].toAscii() );
		}
	}
#endif
	return cpuSpd;
}

bool Func::open( QString file )
{
#ifdef Q_WS_WIN
	if ( !file.isEmpty() )
	{
		if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) //old Windows
			ShellExecuteA( NULL, "Open", file.toLocal8Bit(), NULL, NULL, SW_SHOWNORMAL );
		else
			ShellExecute( NULL, L"Open", ( const wchar_t * )file.utf16(), NULL, NULL, SW_SHOWNORMAL );
	}
	return true;
#else
	if ( !UnixOpenCommand.isEmpty() )
	{
		if ( !file.isEmpty() )
			system( QString( UnixOpenCommand + file + " &" ).toUtf8() );
		return true;
	}
	else
		return false;
#endif
}

QStringList Func::fileDialog( QMP_FILEDIALOG type, QWidget *parent, QString caption, QString dir, QString filter, QString *selectedFilter )
{
	QStringList ret;
	switch ( type )
	{
		case OPEN_FILE:
			ret = QStringList() << QFileDialog::getOpenFileName( parent, caption, dir, filter, selectedFilter );
			break;
		case OPEN_FILES:
			ret = QFileDialog::getOpenFileNames( parent, caption, dir, filter, selectedFilter );
			break;
		case SAVE_FILE:
			ret = QStringList() << QFileDialog::getSaveFileName( parent, caption, dir, filter, selectedFilter );
			break;
		case OPEN_DIR:
			ret = QStringList() << QFileDialog::getExistingDirectory( parent, caption, dir, QFileDialog::ShowDirsOnly );
			break;
	}
	if ( selectedFilter )
	{
		int idx = selectedFilter->indexOf( " (*" );
		if ( idx > -1 )
			selectedFilter->truncate( idx );
	}
	return ret;
}

void Func::chkFileFormat( QStringList &pths, bool *br = NULL )
{
	QStringList tmpPths = pths;
	pths.clear();
	for ( int i = 0 ; i < tmpPths.size() ; i++ )
	{
		if ( QFile::exists( tmpPths[i] ) )
		{
			if ( getMusicFormat( "file", tmpPths[i]) )
				pths += tmpPths[i];
		}
		else
			pths += tmpPths[i];
		if ( br && *br )
			break;
	}
	tmpPths.clear();
}

bool Func::chkProtocols( QString p )
{
	for ( int i = 0 ; i < InternetProtocols.size() ; i++ )
		if ( p.left( InternetProtocols[ i ].size() ) == InternetProtocols[ i ] )
			return true;
	return false;
}
void Func::getLanguage()
{
	language = QSystemLocale().fallbackLocale().name();
	int idx = language.indexOf( '_' );
	if ( idx > -1 )
		language.remove( idx, language.count() - idx );
}
