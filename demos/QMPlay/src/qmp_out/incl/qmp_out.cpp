#include "func.cpp"

#include <QMutexLocker>

QMutex sndQ_mutex;
QQueue< int * > sndQ;

inline int sndQ_size()
{
	QMutexLocker l( &sndQ_mutex );
	return sndQ.size();
}
inline int *sndQ_dequeue()
{
	QMutexLocker l( &sndQ_mutex );
	return sndQ.dequeue();
}
inline void sndQ_enqueue( int *T )
{
	QMutexLocker l( &sndQ_mutex );
	sndQ.enqueue( T );
}

struct plthr : public QThread
{
	bool br, flush, canPlay;
	plthr()
	{
		canPlay = br = flush = false;
	}
	void run();
	void stop()
	{
		br = true;
		if ( isRunning() )
		{
			wait(2500);
			terminate();
			if ( isRunning() )
				wait(1000);
		}
		while ( sndQ_size() )
			delete[] sndQ_dequeue();
		canPlay = flush = br = false;
	}
} plthr;


void (*DoExit)();
void setStopFunction( void (*_DoExit)() )
{
	DoExit = _DoExit;
}

void openOplug()
{
	if ( !closeD )
		return;
	for (int i = 0 ; i < Oplugins.size() ; i++)
	{
		PlErr=false;
		Oplug = Oplugins[i];
		if ( Oplug->pluginInfo->swOnOff(0) )
		{
			if ( REC && Oplug->initRec )
				Oplug->initRec();
			Oplug->Init(true,rate,bits,chn,FRAME_SIZE*(bits/8));
			if ( !*Oplug->PlErr )
			{
				logAdd( Texts[5] /** "Uzywany OutputPlugin" */ +": "+(QString)Oplug->pluginInfo->Name );
				if ( Oplug->isRec && Oplug->isRec() )
					logAdd( Texts[4] /** "Nagrywanie wlaczone" */ );
				if ( !useAppVol )
				{
					Oplug->setVol(aL,aR);
					Oplug->getVol(&aL,&aR);
				}
				break;
			}
			else
			{
				Oplug->closePlug(true);
				logAdd( Oplug->pluginInfo->Name + QString( " -> " ) + *Oplug->errStr );
				if ( i+1 == Oplugins.size() )
				{
					PlErr=true;
					Oplug = NULL;
					break;
				}
			}
		}
		else
		{
			if ( i+1 == Oplugins.size() )
			{
				PlErr=true;
				Oplug = NULL;
				break;
			}
		}
	}
	lastPlErr = PlErr;
}

void clrSet()
{
	doVolUp = false;

	mustReset = false;
	PlErr=false;

	mustStop = false;
	mustPause = false;

	delete globalBuff1;
	delete globalBuff2;
	globalBuff1 = globalBuff2 = NULL;

	pause2 = false;

	DoExit = NULL;

	plthr.stop();
}

void Init( AudioInfo audioInfo, bool b, int *ret_bufsize, QString _fname, QString _title )
{
	clrSet();

	fs.check4err();

	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
		closeD = true;
	}
	else
	{
		doDoVolUp = 1;

		int rate2 = audioInfo.srate;
		char bits2 = audioInfo.bits;
		char chn2 = audioInfo.chn;
		QString bitsStr = audioInfo.bitsStr;

		if ( !rate2 )
			rate2 = 44100;
		if ( !bits2 )
			bits2 = 16;
		if ( !chn2 )
			chn2 = 2;

		if ( ( !closeD && ( ( rate2 != rate && !userRate ) || bits2 != bits || chn2 != chn ) ) || lastPlErr )
		{
			bool busy0 = busy[0];
			bool busy1 = busy[1];
			bool _REC = REC;
			notCloseExportFile = true;
			closeOut();
			notCloseExportFile = false;
			busy[0] = busy0;
			busy[1] = busy1;
			lastPlErr = false;
			REC = _REC;
		}


		title = _title;
		fName = _fname;


		if ( bits2 == 33 )
		{
			bits2 = 32;
			bFloat = true;
		}
		else
			bFloat = false;

		realBits = bits2;
		realChn  = chn2;
		realRate = rate2;

		if ( userBits && !REC )
			bits = UserBits;
		else
			bits = realBits;
		if ( userChn && !REC )
			chn  = UserChn;
		else
			chn  = realChn;
		if ( userRate && !REC )
			rate = UserRate;
		else
			rate = realRate;

		if ( bitsStr.isEmpty() )
			bitsStr = QString::number( bits ) + "bit";

		if ( QBuf < 2 )
			QBuf = 2;
		if ( soundB < 1 )
			soundB = 1;

		_QBuf = QBuf;
		_BufQ = false;
		if ( !REC )
		{
			if ( buffQIfNeaded && BufQ )
			{
				if ( forceUseQMPBuffer )
					_BufQ = true;
			}
			else if ( !buffQIfNeaded && BufQ )
				_BufQ = true;
		}

		FRAME_SIZE = 1024 * chn * soundB;

		int MAX_BUF;
		if ( !_BufQ )
			MAX_BUF = FRAME_SIZE;
		else
			MAX_BUF = _QBuf * FRAME_SIZE;
		fs.bufferSize( QString::number( MAX_BUF * (bits/8) ), QString::number( FRAME_SIZE * (bits/8) ), _BufQ );

		if ( ret_bufsize )
			*ret_bufsize = FRAME_SIZE*(bits/8); //zwraca wielkość bufora


		globalBuff1 = new GlobalBuff( FRAME_SIZE );
		globalBuff2 = new GlobalBuff( FRAME_SIZE );

		if ( chn == 1 )
			musParam[0] = "Mono";
		if ( chn == 2 )
			musParam[0] = "Stereo";
		if ( chn > 2 )
			musParam[0] = QString::number( chn )+"chn";
		musParam[1] = bitsStr;
		musParam[2] = QString::number( rate )+"Hz";

		if ( toOplugS )
			toOplug = true;
		else
			toOplug = false;

		if ( setExport || WAVExport )
			startExport(1);

		if ( WAVExport && !toOplugEx )
			toOplug = false;

		if ( REC )
			toOplug = true;

		if ( toOplug )
			openOplug();

		closeD = false;
	}
}

bool mustStopFunc( bool lookForPause = true )
{
	if ( lookForPause )
		return mustReset || mustStop || nextRead || mustPause || closeD;
	else
		return mustReset || mustStop || nextRead || closeD;
}

void DoVol( int *audio_buffer, bool b )
{
	float DZConst = 6 / ( ( silenceTime / 1000. ) * rate * chn ) + 1.;
	for ( int i = 0 ; i < FRAME_SIZE ; i++ )
	{
		if ( !b )
		{
			dz *= DZConst;
			audio_buffer[i] /= dz;
		}
		else
		{
			dzUp /= DZConst;
			if ( dzUp > 1. )
				audio_buffer[i] /= dzUp;
		}
	}
}
void SilenceFunc( int *audio_buffer )
{
	if ( doSilence )
		DoVol( audio_buffer, 0 );
	else
	{
		dz = 1.0;
		if ( StP )
		{
			memset( audio_buffer, 0, FRAME_SIZE );
			StP = false;
		}
	}

	if ( doVolUp )
	{
		DoVol( audio_buffer, 1 );
		if ( timeVUp > silenceTime / 1000. )
			doVolUp = 0;
		timeVUp += (float)FRAME_SIZE / ( rate * chn * (bits/8.) );
	}
	if ( !doVolUp )
	{
		doVolUp = 0;
		dzUp = 1000.;
		timeVUp = 0.;
	}
}

void processData( int *_audio_buffer, int BUF_SIZE, GlobalBuff *globalBuff, void (*processDataPtr)(int **) )
{
	if ( !globalBuff || !processDataPtr || !_audio_buffer )
		return;

	int TMP_BUF = FRAME_SIZE;
	int i = 0;
	while ( !mustStopFunc( false ) )
	{
		if ( BUF_SIZE - i < FRAME_SIZE )
			TMP_BUF = BUF_SIZE - i;
		if ( TMP_BUF <= 0 )
			break;
		int *audio_buffer = _audio_buffer + i;


		int w = FRAME_SIZE - globalBuff->rest;
		if ( w > TMP_BUF )
			w = TMP_BUF;
		memcpy( globalBuff->audio_buffer + globalBuff->rest, audio_buffer, w * sizeof(int) );
		if ( TMP_BUF + globalBuff->rest < FRAME_SIZE )
		{
			globalBuff->rest += w;
			return;
		}
		globalBuff->rest = ( TMP_BUF + globalBuff->rest ) - FRAME_SIZE;
		int *tmpAB = new int[ FRAME_SIZE ];
		memcpy( tmpAB, globalBuff->audio_buffer, FRAME_SIZE * sizeof( int ) );
		processDataPtr( &tmpAB );
		delete[] tmpAB;
		memcpy( globalBuff->audio_buffer, audio_buffer + ( TMP_BUF - globalBuff->rest ), globalBuff->rest * sizeof(int) );


		i += TMP_BUF;
	}
}

void todoBeforeEff( int *audio_buffer )
{
	if ( !visEff )
	{
		getVol( audio_buffer );
		doVis( audio_buffer );
	}

	if ( !savEff )
		ExportMus( audio_buffer );

	if ( savEff || visEff || toOplug )
	{
		if ( zChnB )
			zChn( audio_buffer );

		if ( ( LV != 1. || RV != 1. ) && bEff )
			doVol( audio_buffer );

		if ( chChnB )
			toMono( audio_buffer );
		else if ( chChn2B )
			toStereo( audio_buffer );
	}
}
void todoAfterEff( int *audio_buffer )
{
	if ( ( LV != 1. || RV != 1. ) && !bEff )
		doVol( audio_buffer );

	if ( doVolUp ) //pokazuje na wizualizacji tylko zgłaśnianie
		SilenceFunc( audio_buffer );

	if ( visEff )
	{
		getVol( audio_buffer );
		doVis( audio_buffer );
	}

	if ( !doVolUp )
		SilenceFunc( audio_buffer );

	if ( savEff )
		ExportMus( audio_buffer );
}

void processDataOut( int **audio_buffer )
{
	bool playSound = toOplug && Oplug && playSoundNow;
	if ( playSound && _BufQ )
	{
		if ( !plthr.isRunning() )
			plthr.start();
		while ( sndQ_size() >= _QBuf && !plthr.br && !mustStopFunc() )
			MYsleep( 5 );
		sndQ_enqueue( (int *)memcpy( new int[ FRAME_SIZE ], *audio_buffer, FRAME_SIZE * sizeof(int) ) );
	}
	else
	{
		todoAfterEff( *audio_buffer );
		if ( playSound )
			PlaySound( *audio_buffer );
		else
		{
			doSilence = 0;
			dz = 1.0;
			doVolUp = 0;
			dzUp = 1000.;
			timeVUp = 0.;
		}
	}
}

void plthr::run()
{
	br = false;

	if ( musParam[3] == "2" && priority() != QThread::TimeCriticalPriority )
		setPriority( QThread::TimeCriticalPriority );
	else if ( musParam[3] == "1" && priority() != QThread::HighestPriority )
		setPriority( QThread::HighestPriority );
	else if ( musParam[3] == "0" && priority() != QThread::HighPriority )
		setPriority( QThread::HighPriority );

	if ( sndQ_size() >= _QBuf / 2 )
		canPlay = true;
	else if ( !sndQ_size() )
		canPlay = false;

	while ( ( canPlay || flush ) && !br && !mustStopFunc() && sndQ_size() )
	{
		int *audio_buffer = sndQ_dequeue();
		todoAfterEff( audio_buffer );
		PlaySound( audio_buffer );
		delete[] audio_buffer;
	}
}

void processDataEffects( int **audio_buffer ) //efekty, wizualizacje, eksport do pliku
{
	int BUF_SIZE = FRAME_SIZE;
	if ( savEff || visEff || toOplug )
	{
		if ( equalizer )
			doEqu( audio_buffer, BUF_SIZE );
		doEff( audio_buffer, BUF_SIZE );
	}
	processData( *audio_buffer, BUF_SIZE, globalBuff2, processDataOut );
}

void processDataPlay( int **_audio_buffer )
{
	todoBeforeEff( *_audio_buffer );
	processDataEffects( _audio_buffer );
}

void Play( void *_audio_buffer, int BUF_SIZE, int _sek, int pause )
{
	if ( _sek != 0 && doDoVolUp && silenceB )
		doVolUp = 1;
	doDoVolUp = 0;

	PlErr = ( toOplug && Oplug && *Oplug->PlErr ) || ( WAVExport && !( toOplug && Oplug ) && *wave->PlErr );

	if ( toOplug && Oplug && nextRead && _QBuf )
	{
		plthr.stop();
		Oplug->play( NULL, 0, true );
	}
	nextRead = false;

	if ( mustReset || mustStop )
	{
		if ( pause )
			MYsleep( 10 );
		return;
	}

	pltime = _sek;
	if ( BUF_SIZE < 0 )
		BUF_SIZE = 0;

	if ( toOplug && Oplug && *Oplug->mustReset )
	{
		mustReset = true;
		return;
	}

	if ( pause == 1 ) //jezeli pauza
	{
		doSilence = 0;
		if ( toOplug && Oplug && !*Oplug->PlErr && !plthr.isRunning() )
			Oplug->play( NULL, 0, true );
		MYsleep( 10 );
		if ( !plthr.isRunning() && mustPause )
			mustPause = false;
		return;
	}

	int *audio_buffer = ConvertDataBits( (char*)_audio_buffer, BUF_SIZE );
	ConvertDataChn ( &audio_buffer, BUF_SIZE );
	playSoundNow = pause != 2;
	processData( audio_buffer, BUF_SIZE, globalBuff1, processDataPlay );
	delete[] audio_buffer;

	if ( !plthr.isRunning() && mustPause )
		mustPause = false;

	if ( titleB && title != oldTitle && !title.isEmpty() )
	{
		if ( titleHB )
			QLib->showMessage( "Teraz gra", title, 1, 0, true );
		else
			QLib->showMessage( "Teraz gra", title, 1, 0, false );
	}
	oldTitle = title;
}

void control(QOutControl b)
{
	switch(b)
	{
		case QOUT_MUST_STOP:
			mustStop = true;
			break;
		case QOUT_STOP_AND_WAIT:
			mustStop = true;
			if ( DoExit )
			{
				DoExit();
				DoExit = NULL;
			}
			while( !closeD )
				MYsleep( 25 );
			break;
		case QOUT_MUST_PAUSE:
			mustPause = true;
			break;
		case QOUT_FLUSH:
		{
			if ( globalBuff1 && globalBuff2 && ( globalBuff1->rest || globalBuff2->rest ) )
			{
				//wypełnianie bufora ciszą - żeby odtworzył dźwięk po posłaniu jednego, bardzo małego bufora
				int *audio_buffer = new int[ FRAME_SIZE ];
				memset( audio_buffer, 0, FRAME_SIZE * sizeof( int ) );
				processData( audio_buffer, FRAME_SIZE, globalBuff1, processDataPlay );
				delete[] audio_buffer;
			}
			//jeżeli jest dodatkowy bufor
			if ( _BufQ )
			{
				plthr.flush = true;
				while ( plthr.isRunning() && sndQ_size() ) //czekać, aż skończy odtwarzać
					MYsleep( 5 );
			}
		} break;
		case QOUT_NEXT_READ:
			if ( sndQ_size() )
				nextRead = true;
			break;
		case QOUT_CLOSE_EXPORTFILE:
			closeExportFile();
			break;
		case QOUT_SILENCE:
			if ( mustStopFunc() || !silenceB )
				return;
			doVolUp = false;
			doSilence = true;
			StP = true;
			MYsleep( silenceTime );
			doSilence = false;
			doVolUp = true;
			break;
		case QOUT_PAUSE_OTHER:
			pause2 = !pause2;
			break;
	}
}

void setOPlug(QList<OutputPlugin*> OPL, QMP_Export *_QExport)
{
	wave = _QExport;
	Oplugins.clear();
	Oplugins = OPL;
}

void setEffects(QList<QMP_effects*> EFF, QMP_effects *_eq )
{
	equalizer = _eq;
	Eplugins.clear();
	Eplugins = EFF;
}

void setVis(QList<VisPlugin*> VIS)
{
	Vplugins.clear();
	Vplugins = VIS;
}

void setOPlugVolume()
{
	if ( sL == 100 )
		LV = 1;
	else
		if ( sL == 0 )
			LV = 0xFFFFFFFF;
	else
		LV = 128.0f / sL;

	if ( sR == 100 )
		RV = 1;
	else
		if ( sR == 0 )
			RV = 0xFFFFFFFF;
	else
		RV = 128.0f / sR;
}

void setVol(int L, int R)
{
	if ( !useAppVol )
	{
		aL  = L;
		aR  = R;
		if (Oplug)
			Oplug->setVol(aL,aR);
	}
	else
	{
		sL = L;
		sR = R;
		fs.ui.sL -> setValue ( sL );
		fs.ui.sR -> setValue ( sR );
		setOPlugVolume();
	}
}

void getVol(int *L, int *R)
{
	if ( !useAppVol )
	{
		if (Oplug)
			Oplug->getVol(&aL,&aR);
		*L = aL;
		*R = aR;
	}
	else
	{
		*L = sL;
		*R = sR;
	}
}

void clrEff2()
{
	forceUseQMPBuffer = false;
	clearVis();
	clearEff();
	if ( equalizer )
		equalizer->closeEff();
}

void clrEff()
{
	oldTitle.clear();

	clrEff2();

	if ( toOplug && Oplug && !*Oplug->PlErr )
	{
		if ( plthr.isRunning() )
			plthr.stop();
		Oplug->play( NULL, 0, true );
	}
}

struct closeOutThr : public QThread
{
	void run()
	{
		plthr.stop();

		pltime = 0;
		title = "";

		clrSet();

		busy[0] = false;
		busy[1] = false;

		if ( REC )
			logAdd( Texts[7] /** Nagrywanie wyłączone */ );
		REC = false;

		if (Oplug)
			Oplug->closePlug(true);
		Oplug = NULL;

		clrEff2();

		if ( !notCloseExportFile )
			closeExportFile();

		if ( !closeD )
			logAdd( Texts[2] /** "Zamknieto QMP Out" */ );

		Save.zapiszVol();

		fs.bufferSize( "", "", -1 );

		closeD = true;
	}
} closeOutThr;
bool closeOut()
{
	closeOutThr.start();
	closeOutThr.wait(4000);
	if ( closeOutThr.isRunning() )
	{
		closeOutThr.terminate();
		closeOutThr.wait(1000);
		return false;
	}
	return true;
}

bool startExport(bool b)
{
	if ( !b )
		return WAVExport;
	setExport = false;
	if ( wave )
	{
		WAVExport = true;
		logAdd( Texts[3] /** "Eksportowanie wlaczone" */ );
		QString fname = chkFName(fName,title);

		wave->Init(true,rate,bits,chn,fname);
		if ( *wave->PlErr )
		{
			logAdd( Texts[1] /** Blad exportu */ + ": " + *wave->errStr );
			wave->closePlug(true);
			WAVExport = false;
		}
	}
	else
		WAVExport = false;
	return WAVExport;
}

void opcje(QWidget *w)
{
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

void setLang(QString langfile)
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QOut/" + QString::number(i) ).toString();

	fs.ui.ApplyB->setText( QMPset->value( "QOutWindow/0" ).toString() );
	fs.ui.bB->setText( QMPset->value( "QOutWindow/1" ).toString() );
	fs.ui.label->setText( QMPset->value( "QOutWindow/2" ).toString() );
	fs.ui.volB->setText( QMPset->value( "QOutWindow/3" ).toString() );
	fs.ui.savEffB->setText( QMPset->value( "QOutWindow/4" ).toString() );
	fs.ui.visEffB->setText( QMPset->value( "QOutWindow/5" ).toString() );
	fs.ui.playSB->setText( QMPset->value( "QOutWindow/6" ).toString() );
	fs.ui.playSExB->setText( QMPset->value( "QOutWindow/7" ).toString() );
	fs.ui.chChnB->setText( QMPset->value( "QOutWindow/8" ).toString() );
	fs.ui.bEffB->setText( QMPset->value( "QOutWindow/9" ).toString() );
	fs.ui.zChnB->setText( QMPset->value( "QOutWindow/10" ).toString() );
	fs.ui.buffQB->setText( QMPset->value( "QOutWindow/11" ).toString() );
	fs.ui.chChn2B->setText( QMPset->value( "QOutWindow/12" ).toString() );
	fs.ui.chChnNotB->setText( QMPset->value( "QOutWindow/13" ).toString() );
	fs.ui.label_2->setText( QMPset->value( "QOutWindow/14" ).toString() );
	fs.ui.label_3->setText( QMPset->value( "QOutWindow/15" ).toString() );
	fs.ui.label_4->setText( QMPset->value( "QOutWindow/16" ).toString() );
	fs.ui.pSL->setToolTip( QMPset->value( "QOutWindow/17" ).toString() );
	fs.ui.titleEB->setText( QMPset->value( "QOutWindow/18" ).toString() );
	fs.ui.userRateB->setText( QMPset->value( "QOutWindow/19" ).toString() );
	fs.ui.userChnB->setText( QMPset->value( "QOutWindow/20" ).toString() );
	fs.ui.userBitsB->setText( QMPset->value( "QOutWindow/21" ).toString() );
	fs.ui.label_5->setText( QMPset->value( "QOutWindow/22" ).toString() );
	fs.ui.label_8->setText( QMPset->value( "QOutWindow/23" ).toString() );
	fs.ui.label_6->setText( QMPset->value( "QOutWindow/24" ).toString() );
	fs.ui.label_9->setText( QMPset->value( "QOutWindow/25" ).toString() );
	fs.ui.silenceB->setText( QMPset->value( "QOutWindow/26" ).toString() );
	fs.ui.titleB->setText( QMPset->value( "QOutWindow/27" ).toString() );
	fs.ui.titleHB->setText( QMPset->value( "QOutWindow/28" ).toString() );
	fs.ui.tabWidget->setTabText( 0, QMPset->value( "QOutWindow/29" ).toString() );
	fs.ui.tabWidget->setTabText( 1, QMPset->value( "QOutWindow/30" ).toString() );
	fs.ui.buffQIfNeadedB->setText( QMPset->value( "QOutWindow/31" ).toString() );
	fs.ui.label_10->setText( QMPset->value( "QOutWindow/32" ).toString() );

	delete QMPset;
}

bool isRec()
{
	if ( Oplug && Oplug->isRec )
		return Oplug->isRec();
	else
		return 0;
}

void initRec()
{
	REC = true;
}

void rec( char *audio_buffer, int BUF_SIZE, bool pause )
{
	if ( Oplug && Oplug->rec && !*Oplug->PlErr && !mustReset && !mustStop )
		Oplug->rec( audio_buffer, BUF_SIZE, pause );
}

void getQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
}

void useQMPBuffer()
{
	forceUseQMPBuffer = true;
}
