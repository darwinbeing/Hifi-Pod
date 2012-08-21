#include <Functions.cpp>

void opcje(QWidget *w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

void getQLib( Qmp *QLib )
{
	QMPConf = QLib->getFileName( QMP_CONF );
}

void Init(bool b, int rate2, int bits2, int chn2, int)
{
	mustReset = false;
	if (!b)
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
	PlErr=false;
	if ( b )
	{
		#ifdef Q_WS_WIN
			if ( isOpen )
			{
				isOpen=false;
				ao_close(AO_Device);
			}
		#endif
		if (!isOpen)
		{
			if ( bits2 == 24 )
			{
				errStr = "libao nie obsluguje 24bit!";
				PlErr=true;
				return;
			}

			drv = drvid;
			fmt.rate = rate2;
			fmt.bits = bits2;
			fmt.byte_format = AO_FMT_NATIVE;
			fmt.channels = chn2;

			AO_Device = ao_open_live(drv, &fmt, NULL);
			isOpen=true;
		}
	}
}

void closePlug(bool b)
{
	mustReset = false;
	if (isOpen)
	{
		ao_close(AO_Device);
		isOpen=false;
	}
	if (!b)
	{
		fs.setParent(NULL);
		fs.close();
	}
}

void play(char *audio_buffer, int buff, bool pauseD)
{
	if ( pauseD )
		return;

#ifdef Q_WS_WIN
	if ( fmt.bits == 8 )
		convert_Signed_Unsigned_PCM(audio_buffer, buff);
#endif

	if ( !ao_play(AO_Device,audio_buffer,buff) )
		PlErr = true;
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
	QMessageBox::information(w,"QMPlay","AO QMPlay OutputPlugin");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
