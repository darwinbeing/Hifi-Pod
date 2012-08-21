void opcje(QWidget* w)
{
	EqW = w;
	timEq.start(50);
}

int CLAMP( long long l, int l1, int l2 )
{
	if (l < l1)
		l =  l1;
	if (l > l2)
		l = l2;
	return l;
}

void DO( float *buffer )
{
	int i;

	for ( int i = 0 ; i < len ; i++ )
	{
		in[ i ].r = buffer[ i ];
		in[ i ].i = 0;
	}
	kiss_fft( cfg1, in, out );

	for ( i = 0 ; i < len2 ; i++ ) //stosowanie filtra
	{
		out[ i ].r *= filterFunc[ i ];
		out[ i ].i *= filterFunc[ i ];
		out[ len-1-i ].r *= filterFunc[ i ];
		out[ len-1-i ].i *= filterFunc[ i ];
	}

	if ( frq && mode > 0 )
	{
		kiss_fft_cpx *o = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * len );

		for ( i = 0 ; i < len ; i++ )
		{
			o[i].r = 0;
			o[i].i = 0;
		}

		if ( mode == 1 )
		{
			int a(2);
			for ( i = 2 ; i < len2 ; i++ )
			{
				o[i+0].r = out[i+a].r;
				o[i+0].i = out[i+a].i;
			}
		}
		if ( mode == 2 )
		{
			int a(4);
			for ( i = 2 ; i < len2 ; i++ )
			{
				o[i+0].r = out[i+a].r;
				o[i+0].i = out[i+a].i;
			}
		}
		if ( mode == 3 )
		{
			int a(2);
			for ( i = 0 ; i < len2 ; i++ )
			{
				o[i+a].r = out[i+0].r;
				o[i+a].i = out[i+0].i;
			}
		}
		if ( mode == 4 )
		{
			int a(8);
			for ( i = 4 ; i < len-a ; i++ )
			{
				o[i+0].r = out[i+a].r;
				o[i+0].i = out[i+a].i;
			}
		}
		if ( mode == 5 )
		{
			for ( i = 0 ; i < len2 ; i++ )
			{
				o[i+0].r = out[i*2].r;
				o[i+0].i = out[i*2].i;
			}
		}
		if ( mode == 6 )
		{
			int a(16);
			for ( i = a ; i < len ; i++ )
			{
				o[i+0].r = out[i-a].r;
				o[i+0].i = out[i-a].i;
			}
		}
		if ( mode == 7 )
		{
			int a(16);
			for ( i = 0 ; i < len2 ; i++ )
			{
				o[i+0].r = out[i+a].r;
				o[i+0].i = out[i+a].i;
			}
		}

		kiss_fft( invert ? cfg2 : cfg1, o, in );

		free( o );
	}
	else
		kiss_fft( invert ? cfg2 : cfg1, out, in );

	for ( i = 0; i < len; i++ ) //ładowanie spowrotem zmiennej do bufora
		buffer[ i ] = in[ i ].r * WinFunc[ i ] * mn;
}

void Filter( float *buf, int BUF_SIZE, float *_buff )
{
	int i,j, BUF_SIZE2 = BUF_SIZE*2;

	memcpy( _buff, _buff + BUF_SIZE, BUF_SIZE * sizeof(float) ); //kopiowanie końca bufora na początek
	memcpy( _buff + BUF_SIZE, buf, BUF_SIZE * sizeof(float) ); //dokładanie nowego bufora z muzyką na koniec
	memcpy( buffer, _buff, BUF_SIZE2 * sizeof(float) ); //przeładowywanie jednego bufora do drugiego

	for ( i = 0 ; i < BUF_SIZE2-len2 ; i += len2 ) //dzielenie bufora na kawałki po 'len/2' bajtów i stosowanie filtra
	{
		memcpy( thisWindow, buffer + i, len * sizeof(float) ); //ładowanie do zmiennej odpowiednich części bufora

		DO( thisWindow ); //Filter

		for ( j = 0 ; j < len2 ; j++ ) //ładowanie do bufora odpowiednich próbek i z overlap-add (żeby nie było trzasków na łączeniu buforów)
			buffer[j+i] = thisWindow[j] + lastWindow[j];

		memcpy( lastWindow, thisWindow + len2, len2 * sizeof(float) ); //poprzednie próbki są teraźniejszymi (overlap-add)
	}

	memcpy( buf, buffer + len2, BUF_SIZE * sizeof(float) ); //odkładanie do bufora wyfiltrowanych próbek
}

void wfb()
{
	if ( !WinFunc )
	{
		WinFunc = new float[ len ];
		for ( int i = 0; i < len ; i++ )
			WinFunc[i] = 0.50 - 0.50 * cos( 2 * M_PI * i / ( len - 1 ) ); //jakaś ważna poprawka dźwięku ( z kodu audacity )
	}
	if ( !in )
		in  = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * len );
	if ( !out )
		out = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * len );
	if ( !cfg1 )
		cfg1 = kiss_fft_alloc( len, false, 0, 0 );
	if ( !cfg2 )
		cfg2 = kiss_fft_alloc( len, true, 0, 0 );
	if ( !lastWindow )
		lastWindow = new float[ len2 ];
	if ( !thisWindow )
		thisWindow = new float[ len ];
}

void closeEff1()
{
	int i;

	for ( i = 0 ; i < buff.count() ; i++ )
		delete[] buff[i];
	buff.clear();

	for ( i = 0 ; i < buf.count() ; i++ )
		delete[] buf[i];
	buf.clear();

	delete[] buffer;
	buffer = NULL;
}
void closeEff2()
{
	mustClrEqBuff = 1;
	first = 1;
	if ( cfg1 )
		free( cfg1 );
	if ( cfg2 )
		free( cfg2 );
	cfg1 = NULL;
	cfg2 = NULL;
	kiss_fft_cleanup();
	if ( in )
		free( in );
	if ( out )
		free( out );
	in = NULL;
	out = NULL;
	delete[] WinFunc;
	WinFunc = NULL;
	delete[] lastWindow;
	lastWindow = NULL;
	delete[] thisWindow;
	thisWindow = NULL;
}
void closeEff()
{
	closeEff1();
	closeEff2();
}

void Do( int **_BUF, int &buf_size, int bits, int chn, int /*rate*/, int /*realrate*/ )
{
	doing = true;

	int *BUF = *_BUF;

	int BUF_SIZE = buf_size / chn;
	if ( BUF_SIZE < len )
		return;

	int i,r,j;

	if ( oldbufsize != buf_size || mustClrEqBuff || chn != oldchn || !buffer || !buff.count() || !buf.count() || bits != oldBits )
	{
		min = -pow( 2, bits-1 );
		max = pow( 2, bits-1 )-1;
		wfb();
		closeEff1();
		memset( lastWindow, 0, len2 * sizeof(float) );
		for ( i = 0 ; i < chn ; i++ )
		{
			buff += new float[buf_size*2];
			memset( buff[i], 0, buf_size*2*sizeof(float) );
		}
		buffer = new float[buf_size*2];
		for ( i = 0 ; i < chn ; i++ )
			buf += new float[BUF_SIZE]; //bufor, na którym wykonywane są opercje
	}
	oldbufsize = buf_size;
	oldchn = chn;
	oldBits = bits;
	mustClrEqBuff = 0;

	r = 0;
	for ( i = 0 ; i < buf_size ; i += chn )
	{
		for ( j = 0 ; j < chn ; j++ )
			buf[j][r] = BUF[i+j];
		r++;
	}

	//filter
	for ( i = 0 ; i < buff.count() ; i++ )
		Filter( buf[i], BUF_SIZE, buff[i] );
	if ( first )
		buf_size = 0;
	else
	{
		r = 0;
		for ( i = 0 ; i < buf_size ; i += chn )
		{
			for ( j = 0 ; j < chn ; j++ )
				BUF[i+j] = CLAMP( buf[j][r], min, max );
			r++;
		}
	}
	first = false;
	//end filter

	if ( !Enabled )
		closeEff();
	doing = false;
}

void getQmpLib(Qmp *_QLib)
{
	QLib = _QLib;
}

void Init()
{
	QMPConf = QLib->getFileName( QMP_CONF );

	Save.odczytajopcje();

	fs.Init();
}

void closePlug()
{
	if ( !inSW && !sw )
		eqgeo = fs.geometry();
	Save.zapiszopcje();
	if ( QLib->inDock() == &fs )
		QLib->dock(0,0,0);
	fs.setParent(NULL);
	fs.close();
}

void setLang( QString langfile )
{
	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	fs.ui.glW->setText( QMPset->value( "QMPEqualizer/0" ).toString() );
	fs.ui.label->setText( QMPset->value( "QMPEqualizer/1" ).toString() );
	fs.ui.label_2->setText( QMPset->value( "QMPEqualizer/2" ).toString() );
	fs.ui.swB->setText( QMPset->value( "QMPEqualizer/3" ).toString() );

	delete QMPset;
}
