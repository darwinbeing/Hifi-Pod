#include <QPen>
#include <QPainter>
#include <QKeyEvent>

QLinearGradient linearGrad;

void MyVis::resizeEvent( QResizeEvent * )
{
	linearGrad.setStart( 0, height() );
	linearGrad.setFinalStop( 0, 0 );
}
void MyVis::setColor( QPainter *painter, float r, float g, float b )
{
	painter->setPen( ( QColor( r * 255, g * 255, b * 255 ) ) );
}
void MyVis::drawLine( QPainter *painter, float x1, float y1, float x2, float y2 )
{
	painter->drawLine
	(
		+( x1 + 1 ) * width()  / 2,
		-( y1 - 1 ) * height() / 2,
		+( x2 + 1 ) * width()  / 2,
		-( y2 - 1 ) * height() / 2
	 );
}
void MyVis::fillRect( QPainter *painter, float x1, float y1, float x2, float y2 )
{
	int x = +( x1 + 1 ) * width()   / 2;
	int y = -( y1 - 1 ) * height()  / 2;
	int w = +( x2 + 1 ) * width()   / 2 - x;
	int h = -( y2 - 1 ) * height()  / 2 - y;

	if ( kolor2 )
		painter->fillRect( x, y, w, h, linearGrad );
	else
		painter->fillRect( x, y, w, h, Qt::green );
}

float m25;
void MyVis::paintEvent( QPaintEvent * )
{
	QPainter painter(this);

	if ( sB )
	{
		int c, chn;
		if ( y_1.count() )
			chn = y_1.count();
		else
			chn = lastChn;
		if ( chn )
		{
			setColor( &painter, 0.4, 0.2, 0.5 );
			for ( c = 0 ; c < chn ; c++ )
				drawLine( &painter, 0.75, f[c], -0.75, f[c] );

			setColor( &painter, 0.4, 0.7, 0.4 );
			for ( int s = 0 ; s < bytes-1 ; s++ )
				for ( c = 0 ; c < chn ; c++ )
					drawLine( &painter, x_1[s], y_1[c][s], x_1[s+1], y_1[c][s+1] );
		}
	}

	if ( lpB )
	{
		//kanał lewy
		//kreski
		m25 = sqrt(sl)/2.;
		if ( l >= sl )
			sl += l - sl;
		else
			sl -= m25;
		if (sl < 0)
			sl = 0;
		//paski
		m25 = sqrt(sl2)/6.;
		if ( l >= sl2 )
			sl2 += l - sl2;
		else
			sl2 -= m25;
		if (sl2 < 0)
			sl2 = 0;

		//kanał prawy
		//kreski
		m25 = sqrt(sr)/2.;
		if ( r >= sr )
			sr += r - sr;
		else
			sr -= m25;
		if (sr < 0)
			sr = 0;
		//paski
		m25 = sqrt(sr2)/6.;
		if ( r >= sr2 )
			sr2 += r - sr2;
		else
			sr2 -= m25;
		if (sr2 < 0)
			sr2 = 0;

		if ( sl > 128 )
			sl = 128;
		if ( sr > 128 )
			sr = 128;

		if ( paski )
		{
			fillRect( &painter, -0.95, sl / 64.0 - 1, -0.85, -1 );
			fillRect( &painter, 0.85, sr / 64.0 - 1, 0.95, -1 );
		}
		if ( kreski )
		{
			if ( !kolor2 )
				setColor( &painter, 0.0, 1.0, 0.0 );

			if ( kolor2 )
			{
				float c = sl2 / 128.;
				if ( c > 0.0 && c <= 0.1 )
					setColor( &painter, 0.0, 0.0, 1.0 );
				else if ( c > 0.1 && c <= 0.5 )
					setColor( &painter, 0.0, 1.0, 0.0 );
				else if ( c > 0.5 && c <= 0.8 )
					setColor( &painter, 1.0, 1.0, 0.0 );
				else if ( c > 0.8 )
					setColor( &painter, 1.0, 0.0, 0.0 );
			}
			drawLine( &painter, -0.95, sl2 / 64.0 - 1., -0.85, sl2 / 64.0 - 1 );

			if ( kolor2 )
			{
				float c = sr2 / 128.;
				if ( c > 0.0 && c <= 0.1 )
					setColor( &painter, 0.0, 0.0, 1.0 );
				else if ( c > 0.1 && c <= 0.5 )
					setColor( &painter, 0.0, 1.0, 0.0 );
				else if ( c > 0.5 && c <= 0.8 )
					setColor( &painter, 1.0, 1.0, 0.0 );
				else if ( c > 0.8 )
					setColor( &painter, 1.0, 0.0, 0.0 );
			}
			drawLine( &painter, 0.85, sr2 / 64.0 - 1., 0.95, sr2 / 64.0 - 1 );
		}
	}

	if ( sngTB )
	{
		if ( !qwe.isEmpty() )
		{
			QFont font;
			font.setPointSize( width() / 25 );
			painter.setFont( font );
			setColor( &painter, 0.8, 1.0, 0.5 );
			painter.drawText( 0, 0, width(), height(), Qt::AlignHCenter | Qt::AlignBottom, qwe );
		}
	}

	if ( cleaning && !sl2 && !sr2 )
	{
		cleaning = false;
		timRef.stop();
	}
}

void MyVis::turnOff()
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

void MyVis::startTimerSlot( int timVal )
{
	timRef.stop();
	timRef.start( timVal );
}
