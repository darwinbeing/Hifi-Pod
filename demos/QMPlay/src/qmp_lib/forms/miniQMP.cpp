void miniQmp::closeEvent(QCloseEvent*)
{
	closed = true;
}
void miniQmp::hideEvent(QHideEvent*)
{
	setStandardIcon();
	showSliderInF1();
	standardIcon = false;
}

void miniQmp::mousePressEvent(QMouseEvent *e)
{
	mPE = e->pos();
}

void miniQmp::mouseMoveEvent(QMouseEvent *e)
{
	if ( ui.titleL->underMouse() && e->buttons() == Qt::LeftButton )
		move( e->globalPos() - mPE );
}

void miniQmp::setStandardIcon()
{
	if ( f1.ui.okno->parent() == ui.okienko )
	{
		f1.ui.okno->setParent( f1.ui.frame_2 );
		f1.ui.okno->move(3,3);
		f1.ui.okno->show();
	}

	ui.okienko->setMinimumSize( 68, 68 );
	ui.okienko->setMaximumSize( 68, 68 );
	ui.okienko->resize( 68, 68 );

	standardIcon = true;

	ui.okienko->setPixmap( fp.ui.infoMB->icon().pixmap( 64, 64 ) );
}
void miniQmp::setQVisIcon()
{
	if ( fs.ui.naf1Box->isChecked() )
	{
		ui.okienko->setPixmap(0);
		ui.okienko->setMinimumSize( f1.ui.frame_2->size() );
		ui.okienko->setMaximumSize( f1.ui.frame_2->size() );
		ui.okienko->resize( f1.ui.frame_2->size() );

		f1.ui.okno->setParent( ui.okienko );
		f1.ui.okno->move(3,3);
		f1.ui.okno->show();

		standardIcon = false;
	}
}

void miniQmp::showSlider()
{
	f1.ui.musicPos->setParent( ui.mPS );
	f1.ui.musicPos->move(0,0);
	f1.ui.musicPos->show();
	resizeEvent(NULL);
}
void miniQmp::showSliderInF1()
{
	if ( f1.ui.musicPos->parentWidget() == ui.mPS )
	{
		f1.ui.musicPos->setParent( f1.ui.widget_4 );
		f1.ui.musicPos->move(80,40);
		f1.ui.musicPos->resize(365,25);
		f1.ui.musicPos->show();
	}
}

void miniQmp::resizeEvent(QResizeEvent*)
{
	if ( f1.ui.musicPos->parentWidget() == ui.mPS )
		f1.ui.musicPos->resize( Size );
}

#ifndef Q_OS_MAC
int miniQmp::getTrayPos()
{
	int l = 0;
	while ( tray.geometry().x() < 0 && tray.geometry().y() < 0 && l++ < 5 )
		MYsleep(100);
	if ( tray.geometry().x() <= 0 && tray.geometry().y() <= 0 )
		return None;
	else if ( qdw.availableGeometry().height() != qdw.height() && qdw.availableGeometry().width() == qdw.width() )
	{
		if ( tray.geometry().y() > qdw.height() / 2  )
			return Bottom;
		else if ( tray.geometry().y() < qdw.height() / 2  )
			return Top;
		else
			return None;
	}
	else if ( qdw.availableGeometry().height() == qdw.height() &&qdw.availableGeometry().width() != qdw.width() )
	{
		if ( tray.geometry().x() > qdw.width() / 2  )
			return Right;
		else if ( tray.geometry().x() < qdw.width() / 2  )
			return Left;
		else
			return None;
	}
	else
		return None;
}
#endif

void miniQmp::setPos( QPoint _pos )
{
	pos = _pos;
}
void miniQmp::setW( int _W )
{
	W = _W;
}

void miniQmp::Show( bool nearTray )
{
	if ( fs.ui.naf1Box->isChecked() && dockVis )
		setQVisIcon();
	else
		setStandardIcon();

	if ( nearTray )
		W = 0;

	setParent(NULL);

	setWindowFlags( Qt::ToolTip );
#ifdef Q_OS_MAC
	if ( nearTray )
		setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
#endif

	move( qdw.width(), qdw.height() );
	show();
	resize( W, 0 );

	Size = ui.mPS->size();
	if ( dockVis )
		showSlider();

	if ( nearTray )
	{
#ifndef Q_OS_MAC
		ObjectPos oPos = (ObjectPos)getTrayPos();
		if ( oPos == None )
			move( qdw.width() / 2 - width() / 2, qdw.height() / 2 - height() / 2 );
		else if ( oPos == Bottom )
			move( tray.geometry().x() - width() / 2, qdw.availableGeometry().height() - height() );
		else if ( oPos == Top )
			move( tray.geometry().x() - width() / 2, qdw.height() - qdw.availableGeometry().height() );
		else if ( oPos == Left )
			move( qdw.width() - qdw.availableGeometry().width(), tray.geometry().y() - height() / 2 );
		else if ( oPos == Right )
			move( qdw.availableGeometry().width() - width(), tray.geometry().y() - height() / 2 );
#else
		move( tray.geometry().x() - width() / 2, 22 );
#endif

		if ( x() < 0 )
			move( 0, y() );
		else if ( x() + width() > qdw.availableGeometry().width() )
			move( qdw.availableGeometry().width() - width(), y() );
	}
	else
		move( pos );
}

void miniQmp::plist()
{
	if ( !f1.isVisible() )
	{
		if ( fpnf1 )
			f1.resize(f1.width(),f1h);
		if ( fp.isVisible() )
			fp.close();
		else
		{
			fp.setParent( NULL );
			fp.setGeometry( fpGeo );
			fp.show();
		}
	}
	else
		f1.showplaylist();
}
