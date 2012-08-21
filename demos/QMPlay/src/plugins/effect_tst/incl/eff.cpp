void opcje(QWidget* w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

int CLAMP(long long l, int l1, int l2)
{
	if (l < l1)
		l =  l1;
	if (l > l2)
		l = l2;
	return l;
}

int uo1( int toUo1 )
{
	if ( toUo1 < 0 )
		return toUo1 +1;
	else
		return toUo1;
}

int state = 0;
int state2 = 0;

int q,q2,left,right;

int BUFFER_SHORTS(0), BUFFER_BYTES(0);
int *buffer = NULL;
int w_ofs, min, max, oldBits = -1;
double divV;

#include <cmath>

void Do( int **_dat, int &BUF_SIZE, int bits, int chn, int rate, int /*realRate*/ )
{
	int *dat = *_dat;

	if ( bits != oldBits )
	{
		min = -pow( 2, bits-1 );
		max = pow( 2, bits-1 )-1;
	}

	if ( effInvert > 0 && chn == 2 )
	{
		for (int i = 0 ; i < BUF_SIZE ; i+=2)
		{
			if ( effInvert == 1 )
				dat[i+0] = -uo1(dat[i+0]);
			if ( effInvert == 2 )
				dat[i+1] = -uo1(dat[i+1]);
			if ( effInvert == 3 )
			{
				dat[i+0] = -uo1(dat[i+0]);
				dat[i+1] = -uo1(dat[i+1]);
			}
		}
	}

	if ( effVoice && chn == 2 )
	{
		for (int i = 0 ; i < BUF_SIZE ; i+=2)
		{
			q  = dat[i];
			q2 = dat[i+1];

			if ( voice )
				divV = 1.;
			else
				divV = 1.5;

			left = CLAMP( q - q2/divV, min, max );
			right = CLAMP( q2 - q/divV, min, max );

			dat[i] = left;
			dat[i+1] = right;
		}
	}

	if ( effEcho && chn <= 2 )
	{
		int data1;
		long long in, out, buf, r_ofs, fb_div;

		if (!buffer)
		{
			BUFFER_SHORTS = rate * chn;
			BUFFER_BYTES = BUFFER_SHORTS * 4;

			buffer = (int*)malloc(BUFFER_BYTES);
			memset(buffer, 0, BUFFER_BYTES);

			w_ofs = 0;
		}

		if (echoSurround && chn == 2)
			fb_div = 200;
		else
			fb_div = 100;

		r_ofs = w_ofs - (rate * echo_delay / 1000) * chn;
		if (r_ofs < 0)
			r_ofs += BUFFER_SHORTS;

		for ( int i = 0 ; i < BUF_SIZE ; i++ )
		{
			data1 = dat[i];

			in = data1;
			buf = buffer[r_ofs];
			if (echoSurround && chn == 2)
			{
				if (i & 1)
					buf -= buffer[r_ofs - 1];
				else
					buf -= buffer[r_ofs + 1];
			}
			out = in + buf * echo_volume / 100;
			buf = in + buf * echo_feedback / fb_div;

			out = CLAMP(out, min, max);
			buf = CLAMP(buf, min, max);

			buffer[w_ofs] = buf;
			data1 = out;
			if (++r_ofs >= BUFFER_SHORTS)
				r_ofs -= BUFFER_SHORTS;
			if (++w_ofs >= BUFFER_SHORTS)
				w_ofs -= BUFFER_SHORTS;

			dat[i] = data1;
		}
	}

	if ( effSkip )
	{
		if ( state == p1s )
		{
			if ( state2 == p2s )
			{
				state = 0;
				state2 = 0;
				return;
			}
			BUF_SIZE = 0;
			state2++;
			return;
		}
		else
		{
			state++;
			return;
		}
	}
	else
	{
		state = 0;
		state2 = 0;
	}

	if ( effSzybko && !effWolno )
	{
		int r(0);
		for ( int i = 0 ; i < BUF_SIZE/2 ; i+=chn )
			for ( int j = 0 ; j < chn ; j++ )
				dat[r++] = dat[ i*2+j ];
		BUF_SIZE /= 2;
	}

	if ( effWolno && !effSzybko )
	{
		int *DAT = new int[BUF_SIZE*2];
		int r(0);
		for ( int i = 0 ; i < BUF_SIZE ; i+=chn )
		{
			for ( int j = 0 ; j < chn ; j++ )
				DAT[r++] = dat[i+j];
			for ( int j = 0 ; j < chn ; j++ )
				DAT[r++] = dat[i+j];
		}
		BUF_SIZE *= 2;
		delete[] dat;
		*_dat = DAT;
	}
}

void Init()
{
	canChEchoVal = false;
	Save.odczytajopcje();
	fs.Init();
	fs.ApplyB();
	canChEchoVal = true;
}

void getQLib( Qmp *QLib )
{
	QMPConf = QLib->getFileName( QMP_CONF );
}

void closePlug()
{
	fs.setParent(NULL);
	fs.close();
}

void closeEff()
{
	free(buffer);
	buffer = NULL;
}

void about(QWidget* w)
{
	QMessageBox::information(w,"QMPlay","podstawowe efekty\nEfekt echa z kodu zrodlowego XMMS 1.2");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
