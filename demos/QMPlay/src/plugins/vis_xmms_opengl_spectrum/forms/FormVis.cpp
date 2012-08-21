void MyVis::resizeGL(int w, int h)
{
	glViewport( 0, 0, w, h );
}

void MyVis::initializeGL()
{
	Vis->setWindowTitle("OpenGL Spectrum analyzer");
	glFrustum(-1, 1, -1, 1, 1.5, 10);
	glEnable(GL_DEPTH_TEST);
}

void MyVis::keyPressEvent( QKeyEvent *k )
{
	#define Key_UP 16777235
	#define Key_DOWN 16777237
	#define Key_LEFT 16777234
	#define Key_RIGHT 16777236
	#define Key_W 87
	#define Key_Q 81
	#define Key_RETURN 16777220
	switch( k->key() )
	{
		case Key_UP:
			x_speed -= 0.1;
			if(x_speed < -6.0)
				x_speed = -6.0;
			break;
		case Key_DOWN:
			x_speed += 0.1;
			if(x_speed > 6.0)
				x_speed = 6.0;
			break;
		case Key_LEFT:
			y_speed -= 0.1;
			if(y_speed < -6.0)
				y_speed = -6.0;
			break;
		case Key_RIGHT:
			y_speed += 0.1;
			if(y_speed > 6.0)
				y_speed = 6.0;
			break;
		case Key_W:
			z_speed -= 0.1;
			if(z_speed < -6.0)
				z_speed = -6.0;
			break;
		case Key_Q:
			z_speed += 0.1;
			if(z_speed > 6.0)
				z_speed = 6.0;
			break;
		case Key_RETURN:
			x_speed = 0.0;
			y_speed = 0.5;
			z_speed = 0.0;
			x_angle = 20.0;
			y_angle = 45.0;
			z_angle = 0.0;
			break;

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
		case Qt::Key_Space:
			QLib->control( 0x23, 0 ); //toggle pause
			break;
		case Qt::Key_Escape:
			if ( isFullScreen() )
				fKey();
			break;
	}
}

void MyVis::paintGL()
{
	if ( clr )
	{
		int x, y;
		bool b = false;

		for(x = 0; x < 16; x++)
		{
			for(y = 0; y < 16; y++)
			{
				if ( heights[y][x] - 0.01 >= 0.0 )
				{
					heights[y][x] -= 0.01;
					b = true;
				}
			}
		}

		if ( !b )
			clr = false;
	}

	x_angle += x_speed;
	if(x_angle >= 360.0)
		x_angle -= 360.0;

	y_angle += y_speed;
	if(y_angle >= 360.0)
		y_angle -= 360.0;

	z_angle += z_speed;
	if(z_angle >= 360.0)
		z_angle -= 360.0;

	draw_bars();
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
	if ( ( x() > 0 && y() > 0 && width() != oS.width() && height() != oS.height() ) && ( !okienko ) )
	{
		QRect VisGeo = Vis->geometry();
		VisX = VisGeo.x();
		VisY = VisGeo.y();
		VisW = VisGeo.width();
		VisH = VisGeo.height();
	}
}
