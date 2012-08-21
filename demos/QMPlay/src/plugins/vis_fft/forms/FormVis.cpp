void MyVis::resizeGL(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
}

void MyVis::initializeGL()
{
	setWindowTitle("Widmo FFT");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

float m3;
float m2;
void MyVis::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if ( fftP || fftK )
	{
		float op = 1.0 / lpaski;
		float fl = -1.0 + op;

		for ( int i = 0 ; i < lpaski ; i++ )
		{
			m3 = sqrt(f[i])/2.;
			if ( fftP )
			{
				if ( F[i] >= f[i] )
					f[i] += F[i] - f[i];
				else
					f[i] -= m3;
				if (f[i] < 0)
					f[i] = 0;

				if ( f[i] > 128.0 )
					f[i] = 128.0;

				glTranslatef( fl, -1.0, 0.0 );
				glBegin(GL_QUADS);
					glColor3f( 0.8, 0.7, 0.3 );
					glVertex3f( -op, -op, 0.0 );
					glColor3f( 0.7, 0.8, 0.4 );
					glVertex3f( op, -op, 0.0 );
					glColor3f( 0.8, 0.4, 0.7 );
					glVertex3f( op, f[i] / 64.0, 0.0 );
					glColor3f( 0.6, 0.4, 0.8 );
					glVertex3f( -op, f[i] / 64.0, 0.0 );
				glEnd();
				glTranslatef( -fl, 1.0, 0.0 );
			}

			if ( fftK )
			{
				m2 = sqrt(f2[i])/6.;
				if ( F[i] >= f2[i] )
					f2[i] += F[i] - f2[i];
				else
					f2[i] -= m2;
				if (f2[i] < 0)
					f2[i] = 0;

				if ( f2[i] > 128.0 )
					f2[i] = 128.0;

				glColor3f( 0.5, 0.6, 0.8 );
				glTranslatef( fl, -1.0, 0.0 );
				glBegin(GL_LINES);
					glVertex3f( op, f2[i] / 64.0, 0.0 );
					glVertex3f( -op, f2[i] / 64.0, 0.0 );
				glEnd();
				glTranslatef( -fl, 1.0, 0.0 );
			}

			fl += op * 2.0;
		}
	}

	if ( fftL )
	{
		glColor3f( 0.4, 0.7, 0.4 );
		glBegin(GL_LINES);
		for ( int s = 0 ; s < bytes-1 ; s++ )
		{
			glVertex3f( x_1[s], y_1[s]-0.95, 0.0 );
			glVertex3f( x_1[s+1], y_1[s+1]-0.95, 0.0 );
		}
		glEnd();

		glColor3f( 0.4, 0.2, 0.5 );
		glBegin(GL_LINES);
			glVertex3f( 1.00,  -0.95, 0.0 );
			glVertex3f(-1.00,  -0.95, 0.0 );
		glEnd();
	}

	if ( cleaning )
	{
		bool b = false;
		if ( fftK || fftP )
		{
			for ( int i = 0 ; i < lpaski ; i++ )
			{
				float f0 = 0.;
				if ( fftK )
					f0 = f2[i];
				else if ( fftP )
					f0 = f[i];
				if ( f0 > 0.0 )
				{
					b = true;
					break;
				}
			}
		}
		if ( !b )
		{
			cleaning = false;
			timRef.stop();
		}
	}
}

void MyVis::turnOff()
{
	if ( isFullScreen() )
		toggleFullScreen();
	fs.ui.isONB->setChecked(false);
	fs.ApplyB();
}
void MyVis::closeWin()
{
	if ( isFullScreen() )
		toggleFullScreen();
	fs.ui.enabledB->setChecked(false);
	fs.ApplyB();
}

void MyVis::closeEvent(QCloseEvent*)
{
	if ( !okienko && Enabled && isOpen && !closing )
		turnOff();
	if ( QLib->inDock() == this )
	{
		noShow = true;
		QLib->dock(0,0,0);
	}
}

void MyVis::keyPressEvent(QKeyEvent *e)
{
	switch( e->key() )
	{
		case 'Z':
			QLib->control( 0x3, 0 ); //prev
			break;
		case 'X':
			QLib->control( 0x0, 0 ); //play
			break;
		case 'C':
			QLib->control( 0x9, 0 ); //pause
			break;
		case 'V':
			QLib->control( 0x1, 0 ); //stop
			break;
		case 'B':
			QLib->control( 0x2, 0 ); //next
			break;
		case Qt::Key_Left:
			QLib->control( 0x5, 0 );
			break;
		case Qt::Key_Right:
			QLib->control( 0x5, 1 );
			break;
		case Qt::Key_Up:
			QLib->control( 0x21, 0 );
			break;
		case Qt::Key_Down:;
			QLib->control( 0x22, 0 );
			break;
		case Qt::Key_Space:
			QLib->control( 0x23, 0 ); //toggle pause
			break;
		case Qt::Key_Escape:
			if ( isFullScreen() )
				fKey();
			break;
	}
}

void MyVis::cursorTimDo()
{
	if ( isFullScreen() )
		setCursor( Qt::BlankCursor );
	cursorTim.stop();
}
void MyVis::mouseMoveEvent(QMouseEvent *e)
{
	if ( cursorTim.isActive() )
		cursorTim.stop();

	setCursor( Qt::ArrowCursor );

	if ( isFullScreen() )
	{
		if ( e->y() > height() - 70 && e->y() < height() - 5 )
			showControls();
		else
			hideControls();

		if ( isFullScreen() )
			cursorTim.start( 1500 );
	}
}

void MyVis::fKey()
{
	if ( !okienko )
		toggleFullScreen();
}
void MyVis::toggleFullScreen()
{
	static bool showMainWindow = false;
	static bool showMiniQMPlay = false;
	if ( isFullScreen() )
	{
		if ( !QLib->getParent( QMP_MAIN )->isVisible() && showMainWindow )
			QLib->control( 0xE, 0 );
		showMainWindow = false;
		if ( QLib->getParent( QMP_MINI )->isVisible() )
			QLib->control( 0xD, 0 ); //chowanie miniqmp
			if ( showMiniQMPlay )
			{
				QLib->control( 0xD, 0 ); //pokazywanie miniqmp
				showMiniQMPlay = false;
			}
			if ( QLib->inDock() == NULL && wasInDock )
				QLib->dock(this,true,unDock);
			else
			{
				showNormal();
				hide();
				show();
			}
	}
	else
	{
		if ( QLib->inDock() == this )
		{
			QLib->dock(NULL,false,NULL);
			wasInDock = true;
		}
		else
			wasInDock = false;
		if ( QLib->getParent( QMP_MAIN )->isVisible() )
		{
			QLib->control( 0xE, 0 ); //chowanie okna głównego
			showMainWindow = true;
		}
		if ( QLib->getParent( QMP_MINI )->isVisible() )
		{
			QLib->control( 0xD, 0 ); //chowanie miniqmp
			showMiniQMPlay = true;
		}
		showFullScreen();
		cursorTim.start( 1500 );
	}
}
void MyVis::showControls()
{
	QWidget *mQ = QLib->getParent( QMP_MINI );
	if ( !mQ->isVisible() )
	{
		QSize s;
		do
		{
			s = mQ->geometry().size();
			QLib->MiniQmp( true, QPoint( qdw.width()/2 - s.width()/2, qdw.height() - s.height() ), qApp->desktop()->width()/2 );
		} while ( s != mQ->geometry().size() );
	}
}
void MyVis::hideControls()
{
	QWidget *mQ = QLib->getParent( QMP_MINI );
	if ( mQ->isVisible() )
		QLib->MiniQmp( false, QPoint(0,0), 0 );
}

void MyVis::odlacz()
{
	setParent(NULL);
	setGeometry(VisX,VisY,VisW,VisH);
	okienko = false;
	show();
	addAction(fsAct);
}

void MyVis::podlacz()
{
	if ( okienkoParent == NULL || !okno )
		return;
	if ( QLib->inDock() == this )
	{
		noShow = true;
		QLib->dock(0,0,0);
	}
	savWinGeometry();
	setParent(okienkoParent);
	resize( QLib->getOkienkoSize() );
	move(0,0);
	okienko = true;
	show();
	removeAction(fsAct);
}

void MyVis::_opcje()
{
	QWidget *qW = QLib->getParent( QMP_MAIN );
	fs.setParent( NULL );
	if ( parent() != NULL )
		fs.move( qW->x() + qW->width()/2 - fs.width()/2 , qW->y() );
	else
		fs.move( x() + width()/2 - fs.width()/2, y() + height()/2 - fs.height()/2 );
	fs.show();
}

void MyVis::popupMenu()
{
	p.clear();
	p.addAction( "Zamknij",this,SLOT(closeWin()));
	p.addAction( "Wyłącz",this,SLOT(turnOff()));
	p.addSeparator();
	if ( !okienko )
	{
		fsAct->setChecked( isFullScreen() );
		p.addAction( fsAct );
		p.addSeparator();
	}
	if ( okienko )
	{
		p.addAction( "Odłącz od QMPlay",this,SLOT(odlacz()));
		p.addSeparator();
	}
	else if ( okienkoParent != NULL && okno )
	{
		p.addAction( "Podłącz do QMPlay",this,SLOT(podlacz()));
		p.addSeparator();
	}
	p.addAction( "Opcje",this,SLOT(_opcje()));
	p.popup( QCursor::pos() );
}

void MyVis::mouseDoubleClickEvent(QMouseEvent*)
{
	if ( okienko )
		odlacz();
	else if ( okienkoParent != NULL && okno && !isFullScreen() )
		podlacz();
	else
		toggleFullScreen();
}

void MyVis::savWinGeometry()
{
	QSize oS = QLib->getOkienkoSize();
	if ( ( x() > 0 && y() > 0 && width() != oS.width() && height() != oS.height() ) && !okienko )
	{
		QRect VisGeo = geometry();
		VisX = VisGeo.x();
		VisY = VisGeo.y();
		VisW = VisGeo.width();
		VisH = VisGeo.height();
	}
}

void MyVis::startTimerSlot( int timVal )
{
	timRef.stop();
	timRef.start( timVal );
}
