void opcje(QWidget* w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(w);
	fs.move(0,0);
	fs.show();
}

void closeEff()
{
	for ( int i = 0 ; i < Handle.count() ; i++ )
	{
		resample_close( Handle[i] );
		delete[] dataI[i];
		delete[] dataO[i];
	}
	Handle.clear();
	dataI.clear();
	dataO.clear();
	oldchn = 0;
	oldfactor = 0;
}

void Do( int **_dat, int &BUF_SIZE, int bits, int chn, int rate, int realRate )
{
	int *dat = *_dat;

	if ( autoFactor )
		tmpfactor = (float)rate / (float)realRate;
	else
		tmpfactor = factor;

	if ( tmpfactor == 1.f )
	{
		if ( Handle.count() )
			closeEff();
		return;
	}

	if ( bits != oldBits )
		dz = pow( 2, bits-1 ) - 1.;
	oldBits = bits;
	int chnSize = BUF_SIZE / chn;
	int outBuffLen = (tmpfactor * chnSize) + 10;

	if ( tmpfactor != oldfactor || chn != oldchn || BUF_SIZE != oldBUFSIZE || HQ != oldHQ )
	{
		closeEff();
		for ( int i = 0 ; i < chn ; i++ )
		{
			Handle += resample_open( HQ, tmpfactor, tmpfactor );
			dataI += new float[ chnSize ];
			dataO += new float[ outBuffLen ];
		}
	}
	oldchn = chn;
	oldfactor = tmpfactor;
	oldBUFSIZE = BUF_SIZE;
	oldHQ = HQ;

	int r;
	for ( int i = 0 ; i < chn ; i++ )
	{
		r = 0;
		for ( int j = 0 ; j < BUF_SIZE ; j += chn )
			dataI[i][r++] = dat[i+j] / dz;
	}

	int inBuffUsed, outSize[chn];
	BUF_SIZE = 0;
	for ( int i = 0 ; i < chn ; i++ )
	{
		outSize[i] = resample_process( Handle[i], tmpfactor, dataI[i], chnSize, 0, &inBuffUsed, dataO[i], outBuffLen );
		if ( outSize[i] > BUF_SIZE )
			BUF_SIZE = outSize[i];
	}
	BUF_SIZE *= chn;

	delete[] dat;
	dat = new int[ BUF_SIZE ];
	*_dat = dat;

	for ( int i = 0 ; i < chn ; i++ )
	{
		r = 0;
		for ( int j = 0 ; j < BUF_SIZE ; j += chn )
		{
			if ( dataO[i][r] > 1.f )
				dataO[i][r] = 1.f;
			else if ( dataO[i][r] < -1.f )
				dataO[i][r] = -1.f;
			dat[i+j] = dataO[i][r++] * (dz-1.);
		}
	}
}

void Init()
{
	canChFactor = false;
	Save.odczytajopcje();
	fs.Init();
	fs.ApplyB();
	canChFactor = true;
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

void about(QWidget *w)
{
	QMessageBox::information(w,"QMPlay","Resample (zmiana częstotliwości próbkowania)");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
