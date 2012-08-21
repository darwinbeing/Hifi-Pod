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
	for ( int i = 0 ; i < lpaski ; i++ )
		F[i] = 0;
	y_1[0] = 0;
	x_1[0] = 0;
	bytes = 1;

	cleaning = true;
	if ( timRefValue < 30 && Vis )
		Vis->startTimer( 30 );
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

void Do( int *_data, int buff2, int bits2, int, int chn, QString, int, QString )
{
	if ( Vis && isOpen && Enabled )
	{
		if ( timRef.interval() != timRefValue || !timRef.isActive() )
			Vis->startTimer( timRefValue );

		if ( bits2 > 32 )
		{
			clear();
			return;
		}

		if ( !fftP & !fftK & !fftL )
			return;

		int dz = getDz(bits2);

		kiss_fft_cpx *in = ( kiss_fft_cpx * )malloc( sizeof( kiss_fft_cpx ) * buff2 );
		memset( in, 0, sizeof( kiss_fft_cpx ) * buff2 );

		int r(0);
		for ( int i = 0 ; i < buff2 ; i += chn )
		{
			int tmp(0);
			for ( int j = i ; j < i+chn ; j++ )
				tmp += _data[j]/2;
			in[r++].r = tmp/dz;
		}

		kiss_fft_stride( cfg, in, out, 1 );
// 		fft(fftsize,0,real,NULL,outreal,outimag);

		free( in );

		for ( int i = 0 ; i < fftsize2 ; i++)
			spec[i] = sqrt( out[i].r * out[i].r + out[i].i * out[i].i );

		if ( fftK || fftP )
		{
			for ( int i = 0 ; i < lpaski ; i++ )
				F[i] = spec[i+przesun]*64.0/(scale*sclDef);
		}


		if ( fftL )
		{
			bytes = fftsize2;

			for ( int i = 0 ; i < bytes ; i++ )
			{
				v[tm] = spec[i]*1.9/(scale*sclDef);

				if ( tm >= bytes )
					break;
				tm++;
			}

			tmp=0;
			if ( tm >= bytes )
			{
				tmp = -1.0;
				for ( int i = 0 ; i < tm ; i++ )
				{
					y_1[i] = v[i];
					x_1[i] = tmp;
					tmp += (2.0 / tm);
				}
				tm=0;
			}
		}
	}
}

void Init()
{
	Save.odczytajopcje();

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
		isOpen=false;
	}
	else
		inDock = false;
	if ( Vis )
		Vis->savWinGeometry();
	Save.zapiszopcje();
	fs.setParent(NULL);
	fs.close();
}

void getQLib( Qmp *_QLib )
{
	QLib = _QLib;
	QMPConf = QLib->getFileName( QMP_CONF );
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
	QMessageBox::information(w,"QMPlay","Widmo FFT");
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
