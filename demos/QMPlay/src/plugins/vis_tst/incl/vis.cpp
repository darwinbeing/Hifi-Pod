void opcje(QWidget *w)
{
	oW = w;
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent(oW);
	fs.move(0,0);
	fs.show();
}

int uo1( int toUo1 )
{
	if ( toUo1 < 0 )
		return toUo1 +1;
	else
		return toUo1;
}

void clr()
{
	if ( y_1.count() )
		lastChn = y_1.count();

	for ( int i = 0 ; i < y_1.count() ; i++ )
		delete[] y_1[i];
	y_1.clear();

	for ( int i = 0 ; i < v.count() ; i++ )
		delete[] v[i];
	v.clear();

	qwe.clear();
	l = 0;
	r = 0;
	for ( int i = 0 ; i < maxSmpl ; i++ )
		x_1[i] = 0;
	bytes = 1;
}
void clear()
{
	if ( !Enabled )
		return;

	clr();

	cleaning = true;
	if ( timRefValue < 30 )
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

void Do( int *_data, int buff2, int bits2, int rate2, int chn2, QString /*title*/, int sek, QString fName )
{
	if ( isOpen )
	{
		if ( timRef.interval() != timRefValue || !timRef.isActive() )
			Vis->startTimer( timRefValue );

		if ( bits2 > 32 )
		{
			clear();
			return;
		}
		if ( sngTB )
		{
			textFile = fName.toUtf8() + ".txt";
			QFile fil( textFile );
			if ( fil.open( QFile::ReadOnly ) )
			{
				QString str = fil.readLine().simplified();
				if ( str == "QMPlay_VIS_TXT" )
				{
					if ( sek != (int)tmpSek )
						tmpSek = sek;
					else
						tmpSek += float(buff2) / ( float(rate2) * float(chn2) );

					while ( !fil.atEnd() )
					{
						str = fil.readLine().simplified();
						int idx = str.indexOf( ' ' );
						int sekStr = (int)( str.left( idx ).toFloat() * 10. );
						if ( sekStr == (int)( tmpSek * 10. ) && sekStr > 0 )
						{
							qwe = str.right( str.length() - 1 - idx );
							break;
						}
					}
				}
				fil.close();
			}
			else
				qwe.clear();
		}

		signed char *data = new signed char[ buff2 ];
		int dz = getDz(bits2);

		for ( int i = 0 ; i < buff2 ; i++ )
			data[i] = _data[i]/dz;

		chn = chn2;
		if ( chn > maxChn )
			chn = maxChn;

		if ( v.count() != chn || y_1.count() != chn )
		{
			clr();
			float il = 2./(float)chn;
			int c = 0;
			for ( float f2 = il/2.-1. ; f2 < 2. ; f2 += il )
			{
				if ( c >= chn )
					break;
				f[c] = f2;
				c++;
			}
			for ( c = 0 ; c < chn ; c++ )
			{
				v += new float[maxSmpl];
				y_1 += new float[maxSmpl];
			}
		}

		bytes = rate2*tims/1000; //ilosc probek

		if ( sB && bytes <= maxSmpl )
		{
			for ( int i = 0 ; i < buff2 ; i += chn )
			{
				for ( int c = 0 ; c < chn ; c++ )
					v[c][tm] = data[i+c] / 128. / (float)chn - f[c]; //kopiowanie kanalow i stosowanie apmplitudy

				if ( tm >= bytes ) //jezeli tm jest rowne lub wieksze od ilosci probek to przerwij
					break;
				tm++; //zmienna ta okresla ilosc probek wzg. osi X
			}

			float tmp = 0; //zerowanie zmiennej
			if ( tm >= bytes ) //jezeli tm wieksze lub rowne od ilosci probek
			{
				tmp = -0.75; //poczatek wykresu w miejscu -0.75
				for ( int i = 0 ; i < tm ; i++ )  //odczyt probek
				{
					for ( int c = 0 ; c < chn ; c++ )
						y_1[c][i] = v[c][i]; //przesuniecie wzgl. osi Y dla kanalow
					x_1[i] = tmp; //przesuniecie wzgl. osi X
					tmp += (1.5 / tm); //przesuwanie w prawo tak aby wykres sie zmiescil z okr. liczba probek
				}
				tm = 0; //zerowanie zmiennej
			}
		}

		if ( lpB )
		{
			l = abs( uo1( data[0] ) );
			if ( chn >= 2 )
				r = abs( uo1( data[1] ) );
			else
				r = l;
		}

		delete[] data;
	}
}

void Init()
{
	if ( !Vis )
		Vis = new MyVis;

	Save.odczytajopcje();

	Vis->connect( &timRef, SIGNAL(timeout()), Vis, SLOT( repaint() ) );
	fs.connect( &setupTimer, SIGNAL(timeout()), &fs, SLOT( FsetupTimer() ) );
	Vis->connect( &cursorTim, SIGNAL(timeout()), Vis, SLOT( cursorTimDo() ) );

	fs.Init();
	fs.ApplyB();

	isOpen=true;

	closing = false;
}

void closePlug()
{
	closing = true;
	if (isOpen)
	{
		setupTimer.stop();
		timRef.stop();
		inDock = QLib->inDock() == Vis;
		Vis->setParent(NULL);
		Vis->close();
		Vis->disconnect( &timRef, SIGNAL(timeout()), Vis, SLOT( repaint() ) );
		fs.disconnect( &setupTimer, SIGNAL(timeout()), &fs, SLOT( FsetupTimer() ) );
		Vis->disconnect( &cursorTim, SIGNAL(timeout()), Vis, SLOT( cursorTimDo() ) );
		fs.close();
		isOpen=false;
	}
	else
		inDock = false;
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
	if ( Enabled )
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
	QMessageBox::information(w,"QMPlay","Prosta wizualizacja");
}

bool SwOnOff( bool b )
{
	if (!b)
		return Enabled;
	Enabled = !Enabled;
	fs.Init();
	fs.ApplyB();
	return 0;
}
