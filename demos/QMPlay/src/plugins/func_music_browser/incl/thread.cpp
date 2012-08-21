QString chkFName( QString fname )
{
	fname.truncate(200);

	fname.replace("/","_");
#ifdef Q_WS_WIN
	fname.replace("\\","_");
	fname.replace(":","_");
	fname.replace("*","_");
	fname.replace("?","_");
	fname.replace("\"","_");
	fname.replace("<","_");
	fname.replace(">","_");
	fname.replace("|","_");
#endif
	return fname;
}

void dwnThr::blad( QString addr )
{
	QLib->showMessage("QMPlay",Texts[13] + addr,1,0,false);
	QLib->addToLog( Texts[13] + addr );
}

void dwnThr::run()
{
	loadCURL();
	if ( !CURLloaded )
		return;

	data = new char[4096];

	bool err = false;
	abortAll = false;

	while ( ff.ui.queueW->count() )
	{
		err = false;
		QStringList addrLst = ff.ui.queueW->item(0)->text().split( " -> " );
		QString addr = addrLst[1];
		if ( !addr.isEmpty() && addr != "-" )
		{
			bolBr = false;

			QString fileName = chkFName( addrLst[0] );
			int kropkaPos = fileName.lastIndexOf( '.' );
			if ( kropkaPos > -1 )
			{
				if ( kropkaPos + 1 == fileName.length() )
					fileName.truncate( fileName.length() - 1 );
				else
				{
					QString name = fileName, ext = fileName;
					ext.remove( 0, kropkaPos );
					name.remove( ext );
					fileName = getFileName( name, pth + "/", ext ) + ext;
				}
			}
			QFile f( pth + "/" + fileName );
			if ( !f.open( QIODevice::WriteOnly ) )
			{
				ff.ui.queueW->removeItemWidget( ff.ui.queueW->takeItem( 0 ) );
				blad( addr );
				err = true;
				continue;
			}

			uF = url_fopen( addr.toAscii().data(), NULL, true );
			if ( !uF )
			{
				f.close();
				ff.ui.queueW->removeItemWidget( ff.ui.queueW->takeItem( 0 ) );
				blad( addr );
				err = true;
				continue;
			}
			QLib->addToLog( Texts[8] + addr );
			int ile = MAX_ILE*2;
			while( !url_feof( uF ) )
			{
				bread = url_fread( data, 1, 4096, uF );

				if ( !bread && !url_feof( uF ) && !--ile )
				{
					blad( addr );
					err = true;
					break;
				}
				if ( bread )
					ile = MAX_ILE;

				f.write( data, bread );

				spd = getNetInfo(uF,DOWNLOAD_SPEED);
				siz = getNetInfo(uF,FILE_SIZE);
				rem = siz - getNetInfo(uF,BYTES_DOWNLOADED);
				dwn = getNetInfo(uF,BYTES_DOWNLOADED);
				if ( siz )
					pC  = ( (double)dwn / (double)siz ) * 100.;
				else
					pC = 0;

				if ( bolBr )
					break;
			}
			f.close();
			url_fclose( uF );

			if ( !f.size() && !err )
			{
				blad( addr );
				err = true;
			}
		}

		if ( abortAll )
			ff.ui.queueW->clear();
		else
			ff.ui.queueW->removeItemWidget( ff.ui.queueW->takeItem( 0 ) );
	}

	unloadCURL();

	delete[] data;

	if ( !err && !bolBr )
		QLib->showMessage("QMPlay",Texts[15] /* Pobieranie zakonczone */,1,0,false);
}
