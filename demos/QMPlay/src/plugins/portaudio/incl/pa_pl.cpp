void opcje(QWidget *w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

void getQLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
}

void unPause()
{
	if ( pauseD )
	{
		Pa_StartStream( stream );
		pauseD = false;
	}
}
void play( char *audio_buffer, int buff, bool pause )
{
	if ( !isOpen )
		return;
	if ( pause )
	{
		if ( !pauseD )
		{
			Pa_AbortStream( stream );
			pauseD = true;
		}
		return;
	}
#ifdef Q_WS_WIN
	/* przy odtwarzaniu 24bit i 32bit w Windows trzeba troche przyciszyć dźwięk, bo słychać "clipping" -> myślę, że to błąd portaudio */
	if ( bits == 32 )
		for ( int i = 0 ; i < buff / 4 ; i++ )
			((int *)audio_buffer)[ i ] *= 0.99;
	else if ( bits == 24 )
		for ( int i = 0 ; i < buff ; i += 3 )
		{
			int s = ( audio_buffer[ i + 2 ] * 0x10000 + audio_buffer[ i + 1 ] * 0x100 + audio_buffer[ i + 0 ] ) * 0.99;
			audio_buffer[ i + 0 ] = ( ( char * )&s )[ 0 ];
			audio_buffer[ i + 1 ] = ( ( char * )&s )[ 1 ];
			audio_buffer[ i + 2 ] = ( ( char * )&s )[ 2 ];
		}
#endif
	unPause();

#ifndef Q_OS_MAC //na MacOSX 10.6 na VirtualBox nie działało, więc wyłączam
	int diff = Pa_GetStreamWriteAvailable( stream ) - Pa_GetStreamInfo( stream )->outputLatency * rate;
	if ( diff > 0 )
	{
		int newsize = diff * chn * (bits/8);
		char a[ newsize ];
		memset( a, 0, newsize );
		Pa_WriteStream( stream, a, diff );
	}
#endif

	if ( Pa_WriteStream( stream, audio_buffer, buff/chn/(bits/8) ) == paUnanticipatedHostError )
		PlErr = true;
}
void rec( char *audio_buffer, int buff, bool pause )
{
	if ( !REC || !isOpen || pause )
		return;
	unPause();

	Pa_ReadStream ( stream, audio_buffer, buff/chn/(bits/8) );
}

void Init(bool b, int rate2, int bits2, int chn2, int /*buff*/)
{
	mustReset = false;
	int err(0);
	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
	PlErr = false;
	if ( b && !isOpen )
	{
		int sFormat;

		bits = bits2;
		chn = chn2;
		rate = rate2;

		if ( bits == 8 )
			sFormat = paInt8;
		else if ( bits == 16 )
			sFormat = paInt16;
		else if ( bits == 24 )
			sFormat = paInt24;
		else if ( bits == 32 )
			sFormat = paInt32;
		else
		{
			errStr = "Nieobsługiwana ilość bitów na próbkę: " + QString::number( bits ) + "!";
			PlErr = true;
			return;
		}

		err = Pa_Initialize();
		if ( err )
		{
			errStr = "Błąd podczas inicjalizacji";
			PlErr = true;
			return;
		}

		if ( zB ) //zawsze używaj tych urządzeń
			fs.detect();

		stream = NULL;

#ifdef Q_OS_LINUX
		const PaDeviceInfo *devInfo = Pa_GetDeviceInfo( devIndexPA );
		if ( autoSurround && ( chn == 4 || chn == 6 || chn == 8 ) && !REC && devInfo && !strcmp( devInfo->name, "default" ) )
		{
			int numDevices = Pa_GetDeviceCount();
			const char *nameTxt = NULL;
			switch ( chn )
			{
				case 4:
					nameTxt = "surround40";
					break;
				case 6:
					nameTxt = "surround51";
					break;
				case 8:
					nameTxt = "surround71";
					break;
			}
			for ( int i = 0 ; i < numDevices ; i++ )
			{
				if ( nameTxt && !strcmp( Pa_GetDeviceInfo( i )->name, nameTxt ) )
				{
					outputParameters.device = i;
					break;
				}
			}
		}
		else
			outputParameters.device = devIndexPA;
#else
		outputParameters.device = devIndexPA;
#endif
		outputParameters.channelCount = chn2;
		outputParameters.sampleFormat = sFormat;
		outputParameters.suggestedLatency = lB;
		outputParameters.hostApiSpecificStreamInfo = NULL;

		if ( REC && devIndexNPA >= 0 )
		{
			inputParameters.device = devIndexNPA;
			inputParameters.channelCount = chn2;
			inputParameters.sampleFormat = sFormat;
			inputParameters.suggestedLatency = lNB;
			inputParameters.hostApiSpecificStreamInfo = NULL;

			err = Pa_OpenStream( &stream, &inputParameters, &outputParameters, rate2, 0, 0, NULL, NULL );
		}
		else
			err = Pa_OpenStream( &stream, NULL, &outputParameters, rate2, 0, 0, NULL, NULL );

#ifdef Q_OS_LINUX
		if ( err && outputParameters.device != devIndexPA )
		{
			outputParameters.device = devIndexPA;
			err = Pa_OpenStream( &stream, NULL, &outputParameters, rate2, 0, 0, NULL, NULL );
		}
#endif
		if ( err )
		{
			errStr = "Błąd podczas otwierania strumienia";
			PlErr = true;
			return;
		}

		err = Pa_StartStream( stream );
		if ( err )
		{
			errStr = "Błąd podczas startowania strumienia";
			PlErr = true;
			return;
		}
		Pa_AbortStream( stream );

		pauseD = isOpen = true;
	}
}

void closePlug(bool b)
{
	REC = false;
	if ( isOpen )
	{
		Pa_CloseStream( stream );
		isOpen = false;
		mustReset = false;
	}
	if (!b)
	{
		fs.setParent( NULL );
		fs.close();
	}
}

bool isRec()
{
	return REC;
}

void initRec()
{
	REC=true;
}

void setVol(int L, int R)
{
	Left = L;
	Right = R;
}

void getVol(int *L, int *R)
{
	*L = Left;
	*R = Right;
}

void about(QWidget* w)
{
	QMessageBox::information(w,"QMPlay","PortAudio OutputPlugin");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
