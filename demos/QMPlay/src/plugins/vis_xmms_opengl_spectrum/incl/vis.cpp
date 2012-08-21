void opcje(QWidget *w)
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	oW = w;
	fs.setParent(oW);
	fs.move(0,0);
	fs.show();
}

void clear()
{
	if ( !Enabled )
		return;
	clr = true;
}

int getDz(int bits2)
{
	if ( bits2 == 16 )
		return 256;
	else if ( bits2 == 24 )
		return 256*256;
	else if ( bits2 == 32 )
		return 256*256*256;
	else return 1;
}

void Do( int *_data, int buff, int bits, int, int chn, QString, int, QString )
{
	if ( Vis && isOpen && Enabled )
	{
		if ( bits > 32 || buff/chn < 512 )
		{
			clear();
			return;
		}

		clr = false;

		int dz = getDz(bits);

		kiss_fft_cpx *in  = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * 512 );
		memset( in, 0, sizeof( kiss_fft_cpx ) * 512 );
		kiss_fft_cpx *out = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * 512 );
		spec = new short[256];

		int r = 0;
		for ( int i = 0 ; i < 512*chn ; i += chn )
		{
			int tmp(0);
			for ( int j = i ; j < i+chn ; j++ )
				tmp += _data[j]/2;
			in[r++].r = tmp/dz;
		}

		kiss_fft_stride( cfg, in, out , 1 );

		free( in );

		for ( int i = 0 ; i < 256 ; i++ )
			spec[i] = sqrt( out[i].r * out[i].r + out[i].i * out[i].i );

		free( out );

		oglspectrum_render_freq( spec );

		delete[] spec;
	}
}

void getQLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
}

void Init()
{
	Save.odczytajopcje();

	start_display();

	fs.connect( &setupTimer, SIGNAL(timeout()), &fs, SLOT( FsetupTimer() ) );

	fs.Init();
	fs.ApplyB();

	isOpen = true;

	closing = false;
}

void closePlug()
{
	closing = true;
	if ( isOpen )
	{
		setupTimer.stop();
		timRef.stop();

		if ( Vis )
		{
			inDock = QLib->inDock() == Vis;
			Vis->setParent(NULL);
			Vis->close();
			Vis->disconnect( &timRef, SIGNAL(timeout()), Vis, SLOT( updateGL() ) );
			Vis->disconnect( &cursorTim, SIGNAL(timeout()), Vis, SLOT( cursorTimDo() ) );
		}

		fs.disconnect( &setupTimer, SIGNAL(timeout()), &fs, SLOT( FsetupTimer() ) );
		fs.close();
		isOpen = false;
	}
	else
		inDock = false;
	if ( Vis )
		Vis->savWinGeometry();
	Save.zapiszopcje();
	fs.setParent(NULL);
	fs.close();
}

void show( QWidget *w, bool b )
{
	if ( Vis && Enabled )
	{
		if ( QLib->inDock() == Vis )
		{
			if ( !w )
				return;
			noShow = true;
			QLib->dock(0,0,0);
		}
		Vis->savWinGeometry();
		Vis->setParent(w);
		okienkoParent = w;
		if (b)
		{
			Vis->resize( QLib->getOkienkoSize() );
			Vis->move(0,0);
			okienko = true;
			Vis->removeAction(fsAct);
		}
		else
		{
			Vis->setGeometry(VisX,VisY,VisW,VisH);
			okienko = false;
			Vis->addAction(fsAct);
		}
		Vis->show();
	}
}

void about(QWidget* w)
{
	QMessageBox::information(w,"QMPlay","XMMS OpenGL Spectrum");
}

bool SwOnOff( bool b )
{
	if ( !b )
		return isON;
	if ( isON )
		Enabled = isON = false;
	else
		Enabled = isON = true;
	fs.Init();
	fs.ApplyB();
	return 0;
}
