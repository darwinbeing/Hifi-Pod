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

#include <QThread>
struct alThr : public QThread
{
	bool finished, breakThr, mustPlay;
	int recBuff;
	void waitForOpen()
	{
		finished = false;
		start();
		while ( !finished )
			MYsleep( 10 );
	}
	void waitForALFinnishWrite()
	{
		for (;;)
		{
			alGetSourcei(Source, AL_SOURCE_STATE, &state);
			if ( alGetError() != AL_NO_ERROR || state != AL_PLAYING )
				break;
			else
				MYsleep( 10 );
		}
		alSourceStop( Source );
	}
	void run()
	{
		pDevice = alcOpenDevice( devName.toAscii() );
		if ( !pDevice )
		{
			errStr = "Nie można otworzyć urządzenie dźwiękowego!";
			PlErr = 1;
			finished = true;
			return;
		}
		pContext = alcCreateContext(pDevice, NULL);
		if (!pContext)
		{
			alcCloseDevice(pDevice);
			errStr = "Nie można wykonać: alcCreateContext()!";
			PlErr = 1;
			finished = true;
			return;
		}
		alcMakeContextCurrent(pContext);

		ALenum eBufferFormat = 0;
		switch (chn)
		{
			case 1:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_MONO16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_MONO8");
				break;
			case 2:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_STEREO16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_STEREO8");
				break;
			case 4:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_QUAD16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_QUAD8");
				break;
			case 6:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_51CHN16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_51CHN8");
				break;
			case 7:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_61CHN16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_61CHN8");
				break;
			case 8:
				if ( bits != 8 )
					eBufferFormat = alGetEnumValue("AL_FORMAT_71CHN16");
				else
					eBufferFormat = alGetEnumValue("AL_FORMAT_71CHN8");
				break;
		}
		if ( !eBufferFormat )
		{
			errStr = "QMPlay OpenAL nie wspiera odtwarzania: " + QString::number(chn) + " kanałów!";
			PlErr = 1;
			return;
		}
		format = eBufferFormat;

		if ( REC )
		{
			captureDevice = NULL;
			if ( bits <= 16 )
				captureDevice = alcCaptureOpenDevice( NULL, srate, format, recBuff );
			if ( !captureDevice )
			{
				REC = false;
				alcDestroyContext(pContext);
				alcCloseDevice(pDevice);
				if ( bits <= 16 )
					errStr = "Nie można otworzyć urządzenia nagrywającego!";
				else
					errStr = "QMPlay OpenAL obsługuje nagrywanie w formatach: 8 i 16bit!";
				PlErr = 1;
				finished = true;
				return;
			}
		}

		alGenSources(1, &Source);
		alGenBuffers(NUM_BUFFERS, Buffers);

		finished = isOpen = true;
		mustPlay = breakThr = false;
		while ( !breakThr )
		{
			if ( mustPlay )
			{
				alSourcePlay(Source);
				mustPlay = false;
			}
			MYsleep( 10 );
		}

		waitForALFinnishWrite();

		if ( captureDevice )
		{
// 			alcCaptureStop( captureDevice );
			alcCaptureCloseDevice( captureDevice );
		}

		alSourceStop( Source );

		alDeleteSources(1, &Source);
		alDeleteBuffers(NUM_BUFFERS, Buffers);

		alcDestroyContext(pContext);
		alcCloseDevice(pDevice);

		pContext = NULL;
		pDevice = NULL;
		captureDevice = NULL;
	}
} alThr;

void Init( bool b, int rate, int bits2, int chn2, int buff )
{
	mustReset = false;

	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}

	PlErr = false;

	if ( b )
	{
		if ( onlyMultiChn && chn2 <= 2 )
		{
			PlErr = true;
			errStr = "Włączono tryb tylko wielokanałowy!";
			return;
		}
		if ( !isOpen )
		{
			bits = bits2;
			srate = rate;
			chn = chn2;

			tmpBC = 0;

			alThr.recBuff = buff;

			alThr.waitForOpen();
		}
	}
}

void closePlug(bool b)
{
	REC = false;
	mustReset = false;
	if (isOpen)
	{
		alThr.breakThr = true;
		alThr.wait();

		isOpen = false;
	}
	if ( !b )
	{
		delete[] Buffers;
		Buffers = NULL;
		fs.setParent(NULL);
		fs.close();
	}
}

bool isRec()
{
	return REC;
}
void initRec()
{
	REC = true;
}

char *convertBits( int &size, char *audio_buffer )
{
	int size2 = 0, i2 = 0;
	if ( bits == 32 )
		size2 = size / 2;
	else if ( bits == 24 )
		size2 = size / 1.5;
	char *data = new char[ size2 ];
	for ( int i = 0 ; i < size2 ; i += 2 )
	{
		data[i+0] = audio_buffer[i2+(bits/8-2)];
		data[i+1] = audio_buffer[i2+(bits/8-1)];
		i2 += bits/8;
	}
	size = size2;
	return data;
}

void rec( char *audio_buffer, int buff, bool pause )
{
	if ( !REC || !isOpen || pause )
		return;

	int bytesCaptured = 0;
	int NULL_VAL = 0;
	if ( bits == 8 )
		NULL_VAL = 0x80;

	for ( int i = 0 ; i < buff ; i++ )
		audio_buffer[i] = NULL_VAL;

	alcGetIntegerv( captureDevice, ALC_CAPTURE_SAMPLES, 1, &bytesCaptured );
	if ( bytesCaptured <= 0 )
	{
		alcCaptureStart( captureDevice );
		if ( bits == 8 )
			convert_Signed_Unsigned_PCM( audio_buffer, buff );
		return;
	}

	alcCaptureSamples( captureDevice, audio_buffer, buff/chn/(bits/8) );
	if ( bits == 8 )
		convert_Signed_Unsigned_PCM( audio_buffer, buff );
}

void play(char *audio_buffer, int buff, bool pauseD)
{
	char *data = NULL;

	if ( pauseD )
	{
		alThr.waitForALFinnishWrite();
		alSourceUnqueueBuffers( Source, tmpBC, Buffers );
		tmpBC = 0;
		return;
	}

	if ( bits != 16 && bits != 8 )
		data = convertBits( buff, audio_buffer );
	else
		data = audio_buffer;
	if ( bits == 8 )
		convert_Signed_Unsigned_PCM( data, buff );

	if ( tmpBC < NUM_BUFFERS )
	{
		alBufferData( Buffers[ tmpBC ], format, data, buff, srate );
		alSourceQueueBuffers( Source, 1, &Buffers[ tmpBC ] );
		tmpBC++;
		if ( bits != 16 && bits != 8 )
			delete[] data;
		return;
	}

	alGetSourcei(Source, AL_SOURCE_STATE, &state);
	alGetSourcei(Source, AL_BUFFERS_PROCESSED, &processed);
	if ( state != AL_PLAYING && !processed )
	{
		alThr.mustPlay = true;
		while ( alThr.mustPlay )
			MYsleep( 10 );
	}

	for (;;)
	{
		alGetSourcei(Source, AL_BUFFERS_PROCESSED, &processed);
		alGetSourcei(Source, AL_SOURCE_STATE, &state);
		if ( processed || state != AL_PLAYING )
			break;
		else
			MYsleep( 10 );
	}

	ALuint buf = 0;
	alSourceUnqueueBuffers(Source, 1, &buf);
	if ( buf )
	{
		alBufferData(buf, format, data, buff, srate);
		alSourceQueueBuffers(Source, 1, &buf);
	}

	if ( bits != 16 && bits != 8 )
		delete[] data;
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

void about(QWidget *w)
{
	QMessageBox::information(w,"QMPlay","OpenAL QMPlay OutputPlugin");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
