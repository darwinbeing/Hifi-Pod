void opcje(QWidget*w)
{
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

void Init(bool b, int rate, int bits, int chn, QString fName )
{
	if ( isOpen )
		closePlug(true);
	if ( b )
	{
		PlErr = false;

		if (!rate)
			rate=44100;
		if (!bits)
			bits=16;
		if (!chn)
			chn=2;

		bits2 = bits;

		if ( bits > 16 )
		{
			errStr = Texts[1];
			PlErr = true;
			return;
		}

		if ( !QFile::exists( fPth ) )
		{
			if ( !QDir().mkpath( fPth ) )
			{
				errStr = Texts[0];
				PlErr = true;
				return;
			}
		}

		if ( raw )
			ext = ".pcm";
		else
			ext = ".wav";

		fName = fPth + getFileName( fName, fPth, ext ) + ext;
#ifdef Q_WS_WIN
		if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) //old Windows
			file = fopen( fName.toLocal8Bit(), "wb" );
		else
			file = _wfopen( ( const wchar_t * )fName.utf16(), L"wb" );
#else
		file = fopen( fName.toUtf8(), "wb" );
#endif
		if ( !file )
		{
			errStr = Texts[0];
			PlErr = true;
			return;
		}

		if ( !raw )
		{
			char x[45];

			sprintf(x,"%s%c%c%c%c%s%s%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c",
			"RIFF",
			0,0,0,0, //fsize
			"WAVE",
			"fmt ",
			16,0,0,0,
			1,0,
			chn,0,
			0,0,0,0, //samplerate
			0,0,0,0, //samplerate*chn*bits/8
			(chn * bits / 8),0,
			bits,0,
			"data",
			0,0,0,0 //datasize
			);

			fwrite(x,sizeof(x),1,file);
			fseek(file,-1,1);

			write4b( rate,24 );
			write4b( (rate*chn*bits/8),28 );
		}
		fflush(file);

		isOpen=true;
	}
	else
	{
		Save.odczytajopcje();
		isOpen=false;
		fs.Init();
	}
}

void closePlug(bool b)
{
	if (isOpen)
	{
		if ( file )
		{
			if ( !raw )
			{
				write4b( getFLen(), 4 );
				write4b( getDLen(), 40 );
			}
			fclose(file);
		}
	}
	isOpen=false;
	if (!b)
	{
		fs.setParent(NULL);
		fs.close();
	}
}

void play(char *audio_buffer,int buff)
{
	if ( !file || !isOpen )
		return;

	if ( sch || bits2 != 8 )
	{
		fwrite(audio_buffer,1,buff,file);
		return;
	}

	if ( !sch && bits2 == 8 )
	{
		convert_Signed_Unsigned_PCM( audio_buffer, buff );
		fwrite(audio_buffer,1,buff,file);
	}
}

void setLang(QString langfile)
{
	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QExport/" + QString::number(i) ).toString();

	fs.ui.label->setText( QMPset->value( "QExportWindow/0" ).toString() );
	fs.ui.browseB->setText( QMPset->value( "QExportWindow/1" ).toString() );
	fs.ui.rawB->setText( QMPset->value( "QExportWindow/2" ).toString() );
	fs.ui.schB->setText( QMPset->value( "QExportWindow/3" ).toString() );
	fs.ui.ApplyB->setText( QMPset->value( "QExportWindow/4" ).toString() );

	delete QMPset;
}

void getQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
}
