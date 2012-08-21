QString ozw = "Odczyt z wtyczki Sound Generator";

double rad( double deg )
{
	return (M_PI/ 180.0) * deg;
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

void CLOSE()
{
	IsPlaying = false;
}
void STOP()
{
	QOut->control( QOUT_FLUSH );
	CLOSE();
	endSong = true;
}
void ERROR2( QString errStr )
{
	MUSerr = true;
	title = errStr;
	QLib->showMessage( "Błąd", errStr, 2, 0, true );
}
void ERROR( QString errStr )
{
	ERROR2( errStr );
	CLOSE();
}

void play( const char *, int type )
{
	if ( type != 1 )
		return ERROR2( "Sound Generator obsługuje tylko odczyt z wtyczki!" );

	clrSet();
	title = ozw;

	double t = 0.;
	unsigned long long oldI = 0;
	int i = 0, i2;
	int chn = _chn;
	int srate = _srate;
	int BS = srate/2 * chn;

	QOut->Init( AudioInfo( srate, 16, chn ), true, 0, "Tone", ozw);

	if ( *QOut->PlErr )
	{
		*QOut->PlErr = false;
		return ERROR( "Błąd zwraca wtyczka wyjściowa!" );
	}

	IsPlaying = true;
	short a[ BS ];
	while ( !bolStop )
	{
		title = ozw + " - " + QString::number(Hz) + "Hz for first chn.";
		*QOut->title = title;
		if ( IsPaused || *QOut->mustReset )
		{
			QOut->Play(0,0,t,true);
			continue;
		}
		i2 = 0;
		for ( i = 0 ; i < BS / chn ; i++ )
		{
			a[ i2+0 ] = sin( rad ( oldI*(360./srate)*Hz ) ) * 0x7FFF;
			if ( chn > 1 )
				a[ i2+1 ] = sin( rad ( oldI*(360./srate)*Hz2 ) ) * 0x7FFF;
			if ( chn > 2 )
				a[ i2+2 ] = sin( rad ( oldI*(360./srate)*Hz3 ) ) * 0x7FFF;
			if ( chn > 3 )
				a[ i2+3 ] = sin( rad ( oldI*(360./srate)*Hz4 ) ) * 0x7FFF;
			if ( chn > 4 )
				a[ i2+4 ] = sin( rad ( oldI*(360./srate)*Hz5 ) ) * 0x7FFF;
			if ( chn > 5 )
				a[ i2+5 ] = sin( rad ( oldI*(360./srate)*Hz6 ) ) * 0x7FFF;
			if ( chn > 6 )
				a[ i2+6 ] = sin( rad ( oldI*(360./srate)*Hz7 ) ) * 0x7FFF;
			if ( chn > 7 )
				a[ i2+7 ] = sin( rad ( oldI*(360./srate)*Hz8 ) ) * 0x7FFF;
			i2 += chn;
			oldI++;
		}
		QOut->Play( a, BS * sizeof( *a ), t, false );
		t += .5;
		pltime = t;
	}
	STOP();
}

void stop()
{
	bolStop = true;
}

void seek(int &)
{
}

void togglePause()
{
	if ( IsPaused )
		IsPaused = false;
	else
		IsPaused = true;
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
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
}

void setFormInfo( int * )
{
}

QWidget *Show( QWidget * )
{
	return NULL;
}

void clrSet()
{
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
}

void clrPos()
{
}

void savPos()
{
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
	BS = true;
	stop();
}

const QString PlugInfoStr("Sound Generator Input Plugin");
void about(QWidget* w)
{
	QMessageBox::information(w,PlugInfoStr,PlugInfoStr);
}

void getMusInfo( const char *, uint, int *time, QString *title )
{
	if ( title )
		*title = ozw;
	if ( time )
		*time = -1;
	return;
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}

void getMenu(QAction **act)
{
	mnu.clear();
	if ( act )
		*act = mnu.addAction( "Tone generator",&fs,SLOT( addB() ) );
}
