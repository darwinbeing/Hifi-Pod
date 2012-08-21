#ifdef Q_WS_WIN
	QString plikbezsciezki( QString pth )
	{
		return QLib->stringOperations( PLIK_BEZ_SCIEZKI, pth );
	}
#endif

void getCDDB(CdIo_t *pcdio, char tracks)
{
	cddb_conn_t *pcddb_conn = NULL;
	cddb_disc_t *pcddb_disc = NULL;
	cddb_track_t *pcddb_track = NULL;
	lba_t lba;

	if ( useCDDB )
	{
#ifdef Q_WS_WIN
		QString homeP = QDir::homePath();
		if ( homeP.length() <= 3 )
			homeP = qApp->applicationDirPath();
		putenv( QString( "HOME=" + homeP ).toLocal8Bit().data() );
#endif
		pcddb_conn = cddb_new();

		cddb_set_charset( pcddb_conn, "UTF-8" );

		if ( !useDefaultCacheDir )
		{
			QString cacheDir;
			cacheDir = qApp->applicationDirPath() + "/cddb";
			cddb_cache_set_dir( pcddb_conn, cacheDir.toLocal8Bit() );
		}
		if ( useProxy )
		{
			cddb_http_proxy_enable( pcddb_conn );
			cddb_set_http_proxy_server_name( pcddb_conn, proxyAddr.toAscii() );
			cddb_set_http_proxy_server_port( pcddb_conn, proxyPort );
		}

		if ( !useCddbp || useFDB )
			cddb_http_enable( pcddb_conn );
		if ( useFDB )
		{
			cddb_set_server_name(pcddb_conn, "freedb.org");
			cddb_set_server_port(pcddb_conn, 80);
		}
		else if ( useUserDatabase )
		{
			QString svr;
			unsigned short port(0);
			bool b = getServer( userDatabaseServer, svr, port );
			if (b)
			{
				cddb_set_server_name(pcddb_conn, svr.toAscii());
				cddb_set_server_port(pcddb_conn, port);
			}
		}
	}

	pcddb_disc = cddb_disc_new();

	lba = cdio_get_track_lba(pcdio, CDIO_CDROM_LEADOUT_TRACK);
	cddb_disc_set_length(pcddb_disc, FRAMES_TO_SECONDS(lba));

	for (int trackno = 1; trackno <= tracks; trackno++)
	{
		pcddb_track = cddb_track_new();
		cddb_track_set_frame_offset( pcddb_track, cdio_get_track_lba( pcdio, trackno ) );
		cddb_disc_add_track( pcddb_disc, pcddb_track );
	}

	cddb_disc_calc_discid( pcddb_disc );
	CDInfo.discid = cddb_disc_get_discid( pcddb_disc );

	if ( CDInfo.discid != CDInfo.lastdiscid )
	{
		CDInfo.control.setDiskTracks( tracks );
		for (char trackno = 1; trackno <= tracks; trackno++)
		{
			CDInfo.control.editTrackParam
			(
				trackno,
				cdio_get_track_format(pcdio, trackno) == TRACK_FORMAT_AUDIO,
				cdio_get_track_channels( pcdio, trackno ),
				cdio_get_track_sec_count( pcdio, trackno )
			);
		}

		bool hasDiscCDTXT(0), hasTrackCDTXT(0);
		bool *trackArray = new bool[tracks];
		for ( int i = 0 ; i < tracks ; i++ )
			trackArray[i] = false;
		if ( readCDTXT )
		{
			cdtext_t *txt = cdio_get_cdtext( pcdio, 0 );
			if ( txt && cdtext_get_const( CDTEXT_TITLE, txt ) )
			{
				CDInfo.control.setDiskInfo
				(
					cdtext_get_const( CDTEXT_PERFORMER, txt ),
					cdtext_get_const( CDTEXT_TITLE, txt ),
					cdtext_get_const( CDTEXT_GENRE, txt ),
					0,
					"CD-TEXT"
				);
				hasDiscCDTXT = true;
			}

			hasTrackCDTXT = true;
			for (char trackno = 1; trackno <= tracks; trackno++)
			{
				cdtext_t *txt = cdio_get_cdtext( pcdio, trackno );
				if ( txt && cdtext_get_const( CDTEXT_TITLE, txt ) )
				{
					trackArray[trackno-1] = true;

					CDInfo.control.editTrackInfo
					(
						trackno,
						cdtext_get_const( CDTEXT_PERFORMER, txt ),
						cdtext_get_const( CDTEXT_TITLE, txt ),
						"CD-TEXT"
					);
				}
				else
					hasTrackCDTXT = false;
			}
		}

		//jeżeli jest CDText na płycie i na każdej ścieżce, w opcjach włączono CDDB i znaleziono CD w bazie
		if ( !( hasDiscCDTXT && hasTrackCDTXT ) && useCDDB && cddb_query(pcddb_conn, pcddb_disc) )
		{
			cddb_read(pcddb_conn, pcddb_disc);

			if ( !hasDiscCDTXT )
			{
				CDInfo.control.setDiskInfo
				(
					cddb_disc_get_artist(pcddb_disc),
					cddb_disc_get_title(pcddb_disc),
					cddb_disc_get_genre(pcddb_disc),
					cddb_disc_get_year( pcddb_disc ),
					"CDDB"
				);
			}

			if ( !hasTrackCDTXT )
			{
				for (char trackno = 1; trackno <= tracks; trackno++)
				{
					if ( !trackArray[trackno-1] )
					{
						cddb_track_t *pcddb_track = cddb_disc_get_track(pcddb_disc, trackno - 1);
						CDInfo.control.editTrackInfo
						(
							trackno,
							cddb_track_get_artist(pcddb_track),
							cddb_track_get_title(pcddb_track),
							"CDDB"
						);
					}
				}
			}
		}
		delete[] trackArray;
	}
	CDInfo.lastdiscid = CDInfo.discid;
	if ( useCDDB )
		cddb_destroy(pcddb_conn);
	cddb_disc_destroy(pcddb_disc);
}

void CLOSE()
{
	cdio_destroy(pcdio);
	IsPlaying = false;
}

void ERROR2( QString errStr )
{
	fi->close();
	MUSerr = true;
	title = errStr;
}

void _ERROR( QString errStr )
{
	clrPos();
	ERROR2(errStr);
	CLOSE();
}

void STOP(bool err)
{
	QOut->control( QOUT_FLUSH );
	CLOSE();
	if(err)
	{
		QString BLAD = Texts[0] /*"Błąd odczytu płyty!"*/;
		ERROR2(BLAD);
		QLib->showMessage( Texts[1]/*"Błąd"*/, BLAD, 2, 0, true );
	}
	else
		endSong=true;
	fi->fCD.clear();
}

int calcTime( int beginSector, int endSector, int chn )
{
	int sectors = endSector - beginSector;
	int bytes = sectors * BYTES_PER_SECTOR;
	return bytes / (44100*2*chn);
}

int calcTimePlaying( int BUF_SIZE )
{
	currBytes += BUF_SIZE;
	return currBytes / (44100*2*chn);
}

char playTrack(-1);

void play( const char *fileE, int type )
{
	if ( type == 2 )
		return ERROR2( Texts[2]/*"Wtyczka nie obsługuje strumieni internetowych!"*/ );

	title = Texts[3]/*"Odczytywanie płyty..."*/;

	if ( fileE != curF )
		clrPos();

	clrSet();

	curF = fileE;

	QString currCD_2 = currCD;
	char track(0);
	if ( type == 1 )
		track = atoi( fileE );
#ifdef Q_WS_WIN
	else if ( type == 0 )
	{
		QString fName = plikbezsciezki( fileE );
		track = atoi( fName.right( fName.length() - 5 ).toAscii() );
		currCD_2 = "\\\\.\\";
		currCD_2 += fileE[0];
		currCD_2 += ":";
	}
#endif
	fi->fCD = currCD_2;

	fs.closeTray();
	pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
	cdio_set_speed( pcdio, speed );
	char tracks = cdio_get_num_tracks(pcdio);

	fi->clr();

	if ( tracks < 1 )
		return _ERROR( Texts[4]/*"Nie znaleziono płyty!"*/ );

	if ( tracks < track || track < 1 )
		return _ERROR( Texts[5]/*"Zły numer ścieżki!"*/ );

	getCDDB(pcdio,tracks);

	if ( !CDInfo.track[ track-1 ].isAudio )
		return _ERROR( Texts[6]/*"Błąd: ścieżka"*/ + " " + QString::number(track) + " " + Texts[7]/*"zawiera dane!"*/ );

	int b = cdio_get_track_lsn     ( pcdio, track );
	int e = cdio_get_track_last_lsn( pcdio, track );

	CDUpdate( b, e, track );

	QOut->useQMPBuffer();
	QOut->Init( AudioInfo( 44100, 16, chn ), true, 0, title ,title );

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return _ERROR( Texts[8]/*"Błąd zwraca wtyczka wyjściowa!"*/ );
	}

	if ( QLib )
		QLib->updateCurrPlistEntry( title );

	IsPlaying = true;

	playTrack = track;
	char audio_buffer[ BYTES_PER_SECTOR ];
	bool err(0);
	for( int i = b ; i < e ; i++ )
	{
		if ( bolStop )
			break;
		if ( !IsPaused && !*QOut->mustReset )
		{
			if ( seeked )
			{
				i = b + sectorsToSeek;
				currBytes = sectorsToSeek * BYTES_PER_SECTOR;
				seeked = false;
			}
			if ( cdio_read_audio_sector( pcdio, audio_buffer, i ) != DRIVER_OP_SUCCESS )
			{
				err = 1;
				break;
			}
			QOut->Play( audio_buffer, BYTES_PER_SECTOR, pltime, false );
			CDUpdate2( BYTES_PER_SECTOR );
		}
		else
		{
			QOut->Play( 0,0,pltime,true );
			i--;
		}
	}
	playTrack = -1;
	if ( err )
	{
		CdIo *pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
		char tracks = cdio_get_num_tracks(pcdio);
		cdio_destroy(pcdio);
		if (tracks < 1)
		{
			MUSerr = true;
			QString BLAD = Texts[9]/*"Płyta została wysunięta"*/;
			QLib->showMessage( Texts[1]/*"Błąd"*/, BLAD, 2, 2000, true );
			title = BLAD;
			err = 0;
			fi->close();
		}
	}
	STOP(err);
}

void CDUpdate( int b, int e, char track )
{
	title = CDInfo.track[ track-1 ].T;
	chn = CDInfo.track[ track-1 ].chn;

	plMaxtime = calcTime( b, e, chn );
	NumPos = plMaxtime-1;

	if ( savsek )
	{
		pltime = -1;
		seek( savsek );
		savsek = 0;
	}

	fi->trackFrom = CDInfo.track[ track-1 ].from;
	fi->fTitle = CDInfo.track[ track-1 ].title;
	fi->fArtist = CDInfo.track[ track-1 ].artist;
	fi->fTrack = track;
	fi->fChn = chn;

	updateEdits = true;
	updateEditsDrive = true;
}

void stop()
{
	bolStop=true;
}

void seek(int &i)
{
	if ( !seeked && i > 0 )
	{
		sectorsToSeek = ( i * 44100 * chn * 2 ) / BYTES_PER_SECTOR;
		seeked = true;
	}
	else
		i = -1;
}

void togglePause()
{
	IsPaused = !IsPaused;
}

void getQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
	QOut = QLib->getOutLib();
}

void Init( bool b, int )
{
	BS = mustReset = false;
	if ( !b )
	{
		if ( pixmap.isNull() )
			pixmap = QPixmap( ":/cd.png" );
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
}

void setFormInfo( int *siz )
{
	if ( siz )
		fi->resize( siz[0], siz[1] );
	else if ( fi->parent() != NULL )
		fi->close();
}

QWidget *Show(QWidget *w)
{
	if ( fi->isVisible() )
		return NULL;


	QString currCD_2 = currCD;
	char track(playTrack);

	CdIo_t *pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
	char tracks = cdio_get_num_tracks(pcdio);
	if ( tracks < 1 )
	{
		cdio_destroy(pcdio);
		return NULL;
	}
	getCDDB( pcdio, tracks );
	cdio_destroy(pcdio);
	fi->fTrack = track;
	if ( track >= 1  && track <= CDInfo.tracks )
	{
		fi->trackFrom = CDInfo.track[ track-1 ].from;
		fi->fTitle = CDInfo.track[ track - 1 ].title;
		fi->fArtist = CDInfo.track[ track - 1 ].artist;
		fi->ui.cdL->setText( currCD_2 );
		fi->fChn = CDInfo.track[ track-1 ].chn;
		updateEdits = true;
	}
	else if ( fi->isVisible() )
	{
		fi->clr();
		return NULL;
	}


	fi->setParent(w);
	fi->move(0,0);
	updateEditsDrive = true;
	fi->openFromMusInfo = true;
	fi->Init();
	fi->show();
	return fi;
}

void CDUpdate2( int BUF_SIZE )
{
	pltime = calcTimePlaying( BUF_SIZE );
	SongPos = pltime;
}

void clrSet()
{
	getBR = "n/a";
	SongPos = 0;
	NumPos = 0;
	pltime = 0;
	plMaxtime = 0;
	IsPaused = false;
	if ( !BS )
		bolStop = false;
	else
		BS = false;
	endSong = false;
	curF="";
	currBytes = 0;
	seeked = 0;
}

void clrPos()
{
	savsek = 0;
}

void savPos()
{
	savsek = SongPos;
}


void closePlug(bool x,bool z)
{
	mustReset = false;
	if ( !x && !z )
	{
		fs.setParent(NULL);
		fs.close();
		return;
	}
	if (x)
		savPos();
	Save.zapiszopcje();
	BS = true;
	stop();
	if ( fi->isVisible() )
	{
		if ( !( !fi->parent() && !x && z ) )
			fi->close();
	}
}

void showOptions()
{
	QWidget *qW = QLib->getParent(QMP_MAIN_OR_PLIST);
	fs.setParent( NULL );
	fs.move( qW->x() + qW->width()/2 - fs.width()/2 , qW->y() + qW->height()/2 - fs.height()/2 );
	fs.show();
}

void opcje(QWidget *w)
{
	if (w)
	{
		w->setMinimumSize( fs.minimumSize() );
		w->setMaximumSize( fs.maximumSize() );
		tmpWidget = w;
	}
	fs.setParent(tmpWidget);
	fs.move(0,0);
	fs.show();
}

const QString PlugInfoStr("CDAudio Input Plugin");
void about(QWidget* w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr,0,0);
}

void getMusInfo( const char *fileE, uint type, int *time, QString *title )
{
	if ( type == 2 )
		return;
	char track(-1);
	QString currCD_2 = currCD;
	if ( type == 1 )
		track = atoi(fileE);
#ifdef Q_WS_WIN
	else if ( type == 0 )
	{
		QString fName = plikbezsciezki( fileE );
		track = atoi( fName.right( fName.length() - 5 ).toAscii() );
		currCD_2 = "\\\\.\\";
		currCD_2 += fileE[0];
		currCD_2 += ":";
	}
#endif
	if ( track > 0 )
	{
		if ( title || time )
		{
			bool b(0);
			CdIo_t *pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
			char tracks = cdio_get_num_tracks(pcdio);
			if ( tracks > 0 && tracks >= track )
			{
				getCDDB(pcdio,tracks);
				b = 1;
			}
			cdio_destroy(pcdio);

			if (title)
			{
				if ( !b )
					*title = Texts[10]/*"Ścieżka"*/ + " " + QString::number( track );
				else
					*title = CDInfo.track[ track-1 ].T;
			}
			if ( time )
			{
				if (b)
					*time = calcTime( 0, CDInfo.track[ track-1 ].frames, CDInfo.track[ track-1 ].chn );
				else
					*time = -2;
			}
		}
	}
}


bool FileFormatSupport( const char *fileE )
{
#ifndef Q_WS_WIN
	Q_UNUSED( fileE );
	return false;
#else
	QString fName = plikbezsciezki( fileE );
	if ( fName.right( 4 ) != ".cda" )
		return false;
	char track = atoi( fName.right( fName.length() - 5 ).toAscii() );
	if ( track > 0 )
		return true;
	else
		return false;
#endif
}

QString getMusStr(const char *fileE, int type, QPixmap &pix)
{
	pix = NULL;
	QString currCD_2 = currCD;
	char track(0);

	if ( type == 1 )
		track = atoi(fileE);
#ifdef Q_WS_WIN
	else if ( type == 0 )
	{
		QString fName = plikbezsciezki( fileE );
		track = atoi( fName.right( fName.length() - 5 ).toAscii() );
		currCD_2 = "\\\\.\\";
		currCD_2 += fileE[0];
		currCD_2 += ":";
	}
#endif

	fs.closeTray();
	CdIo_t *pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
	char tracks = cdio_get_num_tracks(pcdio);
	if ( tracks < 1 )
	{
		cdio_destroy(pcdio);
		return "";
	}
	getCDDB( pcdio, tracks );
	cdio_destroy(pcdio);
	fi->fTrack = track;
	if ( track >= 1  && track <= CDInfo.tracks )
	{
		QString tmpStr, year;
		year = CDInfo.year == 0 ? "" : QString::number(CDInfo.year);
		tmpStr = "\nTrack	" + QString::number(track) + "\nTitle	" + CDInfo.track[ track - 1 ].title + "\nArtist	" + CDInfo.track[ track - 1 ].artist + "\nCD Year	" + year + "\nCD Genere	" + CDInfo.genere;
		return tmpStr;
	}
	else return "";
}

void infoWindow(QWidget *w, const char *fileE, int type)
{
	QString currCD_2 = currCD;
	char track(0);

	if ( type == 1 )
		track = atoi( fileE );
#ifdef Q_WS_WIN
	else if ( type == 0 )
	{
		QString fName = plikbezsciezki( fileE );
		track = atoi( fName.right( fName.length() - 5 ).toAscii() );
		currCD_2 = "\\\\.\\";
		currCD_2 += fileE[0];
		currCD_2 += ":";
	}
#endif

	fs.closeTray();
	CdIo_t *pcdio = cdio_open( currCD_2.toAscii(), DRIVER_UNKNOWN );
	char tracks = cdio_get_num_tracks(pcdio);
	if ( tracks < 1 )
	{
		cdio_destroy(pcdio);
		return;
	}
	getCDDB( pcdio, tracks );
	cdio_destroy(pcdio);
	fi->fTrack = track;
	if ( track >= 1  && track <= CDInfo.tracks )
	{
		if ( !fi->isVisible() )
		{
			fi->openFromMusInfo = false;
			fi->setParent(NULL);
			fi->move( w->x() + w->width()/2 - fi->width()/2 , w->y() + w->height()/2 - fi->height()/2 );
			fi->Init();
			fi->show();
		}
		fi->trackFrom = CDInfo.track[ track-1 ].from;
		fi->fTitle = CDInfo.track[ track - 1 ].title;
		fi->fArtist = CDInfo.track[ track - 1 ].artist;
		fi->ui.cdL->setText( currCD_2 );
		fi->fChn = CDInfo.track[ track-1 ].chn;
		updateEdits = true;
	}
	else if ( fi->isVisible() )
	{
		fi->clr();
		fi->fTitle = Texts[11]/*"Ścieżka nie istnieje"*/;
	}
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}

void FormSetup::addCD()
{
	if ( !Enabled )
		return;

	qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );

	ApplyB();

	if ( fs.ui.driveB->count() < 2 )
		fs.showEvent(NULL);

	fs.closeTray();
	CdIo_t *pcdio = cdio_open( currCD.toAscii(), DRIVER_UNKNOWN );

	char tracks = cdio_get_num_tracks(pcdio);
	if ( tracks < 1 )
	{
		cdio_destroy(pcdio);
		qApp->restoreOverrideCursor();
		if ( fs.ui.driveB->count() > 2 && !fs.isVisible() )
		{
			if ( QMessageBox::information( this, "QMPlay", Texts[4] + "\n" + Texts[12]/*"Czy chcesz zmienić napęd CD w opcjach wtyczki?"*/, 3, 4 ) == 3 )
				showOptions();
		}
		else
			QMessageBox::information( this, "QMPlay", Texts[4]/*"Nie znaleziono płyty!"*/ );
		return;
	}

	Save.odczytajopcje();
	CDInfo.lastdiscid = 0;

	if ( clrB )
		QLib->control(9,0); //pause

	getCDDB( pcdio, tracks );
	cdio_destroy(pcdio);

	qApp->restoreOverrideCursor();

	if(clrB)
	{
		QLib->control(1,0); //stop
		QLib->control(0x17,0); //czyści listę
	}
	QStringList Tracks;
	for ( int i = 1 ; i <= tracks ; i++ )
		Tracks += "plugin://"+QString::number(i)+"."+plugName;
	QLib->addToPlayList( Tracks, -1 );
	Tracks.clear();
	if(clrB)
		QLib->control(0,0); //play
}
void getMenu(QAction** act)
{
	mnu.clear();
	if ( act )
		*act = mnu.addAction( "Audio CD",&fs,SLOT( addCD() ) );
}

void setLang( QString langfile )
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QMPlay_CDAudio/" + QString::number(i) ).toString();

	fs.ui.enabledB->setText( QMPset->value( "QMPlay_CDAudio_Window/0" ).toString() );
	fs.ui.ejectB->setText( QMPset->value( "QMPlay_CDAudio_Window/1" ).toString() );
	fs.ui.closeTB->setText( QMPset->value( "QMPlay_CDAudio_Window/2" ).toString() );
	fs.ui.readCDTXTB->setText( QMPset->value( "QMPlay_CDAudio_Window/3" ).toString() );
	fs.ui.trackB->setText( QMPset->value( "QMPlay_CDAudio_Window/4" ).toString() );
	fs.ui.clrB->setText( QMPset->value( "QMPlay_CDAudio_Window/5" ).toString() );
	fs.ui.canCloseTB->setText( QMPset->value( "QMPlay_CDAudio_Window/6" ).toString() );
	fs.ui.useCDDBB->setText( QMPset->value( "QMPlay_CDAudio_Window/7" ).toString() );
	fs.ui.defCacheB->setText( QMPset->value( "QMPlay_CDAudio_Window/8" ).toString() );
	fs.ui.qmpCacheB->setText( QMPset->value( "QMPlay_CDAudio_Window/9" ).toString() );
	fs.ui.groupBox->setTitle( QMPset->value( "QMPlay_CDAudio_Window/10" ).toString() );
	fs.ui.useFDBB->setText( QMPset->value( "QMPlay_CDAudio_Window/11" ).toString() + " freedb.org" );
	fs.ui.useUserDatabaseB->setText( QMPset->value( "QMPlay_CDAudio_Window/12" ).toString() );
	fs.ui.useCddbpB->setText( QMPset->value( "QMPlay_CDAudio_Window/13" ).toString() );
	fs.ui.ApplyB->setText( QMPset->value( "QMPlay_CDAudio_Window/14" ).toString() );

	fs.ui.useCDDBB->setToolTip( QMPset->value( "QMPlay_CDAudio_Window/15" ).toString() );
	fs.ui.readCDTXTB->setToolTip( QMPset->value( "QMPlay_CDAudio_Window/16" ).toString() );
	fs.ui.useCddbpB->setToolTip( QMPset->value( "QMPlay_CDAudio_Window/17" ).toString() );
	fs.ui.userDatabaseServerB->setToolTip( QMPset->value( "QMPlay_CDAudio_Window/18" ).toString() );

	delete QMPset;
}
