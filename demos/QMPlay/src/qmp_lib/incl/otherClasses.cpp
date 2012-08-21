struct FormInfo: public QWidget
{
	public:
		QWidget *infoW;
		QPushButton *button;
		FormInfo()
		{
			resetSize();

			cantResize = 0;

			unDocking = false;
			showAfterUnDock = true;

			infoW = new QWidget(this);

			button = new QPushButton(infoW);
			button->move(170-50-10,125-25-10);
			button->resize(50,25);

			connect( button, SIGNAL(clicked()), &f1, SLOT(musinfo()) );
		}
		void closeEvent(QCloseEvent*);
		void showEvent(QShowEvent*);
		void resizeEvent(QResizeEvent*);
		void resetWindow();
		void resetSize();
		int posX,posY;
		bool unDocking, showAfterUnDock;
		int cantResize;
};
FormInfo formInfo;
void formInfoUnDock()
{
	formInfo.unDocking  = true;
	formInfo.close();
	if ( !formInfo.showAfterUnDock )
	{
		formInfo.move( formInfo.posX, formInfo.posY );
		formInfo.showAfterUnDock = true;
		formInfo.unDocking = false;
		return;
	}
	f1.showInfoForm();
	formInfo.move( formInfo.posX, formInfo.posY );
	formInfo.show();
	formInfo.unDocking = false;
}

struct TRAY
{
	TRAY()
	{
		Act = NULL;
		clr();
	}
	QString title, msg;
	int icon, msec;
	bool showInTray;
	void (*Act)();
	void showTrayMessage( QString _title, QString _msg, int _icon, int _msec, bool _showOnlyIfWindowIsNotVisible, void (*act)() )
	{
		if ( tray.isVisible() )
		{
			if ( _showOnlyIfWindowIsNotVisible && f1.isVisible() )
				return;
			title = _title;
			msg = _msg;
			icon = _icon;
			if ( !_msec )
				msec = 2000;
			else if ( msec == -1 )
				msec = 0;
			else
				msec = _msec;
			Act = act;
			showInTray = true;
		}
	}
	void clr()
	{
		title.clear();
		msg.clear();
		icon = 0;
		msec = 0;
		showInTray = false;
	}
};
TRAY Tray;

QList<QUrl> getCopyData();
struct titleList : public QListWidget
{
	public:
		titleList( QWidget *w = NULL )
		{
			setParent( w );
			setMouseTracking(true);
			connect( &tim, SIGNAL( timeout() ), &fp, SLOT( infoListTimerDo() ) );
			cRow = -1;
			lRow = -2;
			Modifier = false;
		}
		QTimer tim;
		QPoint mPos;
		int lRow, cRow;
	private:
		bool Modifier;
		int cR;

		QString bezNr(QString s)
		{
			int idx = s.indexOf( ". " );
			if ( idx > -1 )
				s = s.right( s.size() - idx - 2 );
			return s;
		}
		void errList( int lastRow )
		{
			fp.createList();
			setCurrentRow( lastRow );
		}
		void dropEvent(QDropEvent *event)
		{
			int i(0);
			if ( currentRow() != cR )
				return errList(currentRow());
			for ( i = 0 ; i < count() ; i++ )
				if ( atoi( item(i)->text().toAscii() ) <= 0 )
					return errList(currentRow());

			if ( itemsQueue.size() )
			{
				itemsQueue.clear();
				int idx = currentRow();
				fp.createList();
				setCurrentRow( idx );
			}

			QListView::dropEvent(event);

			QList<int> iL;
			QStringList sL0, sL1, sL2, sL3, sL4;
			for ( i = 0 ; i < count() ; i++ )
				if ( !item(i)->isSelected() )
					iL += atoi( item(i)->text().toAscii() );

			for ( int i = 0 ; i < iL.count() ; i++ )
			{
				sL0 += playList[0][ iL[i]-1 ];
				sL1 += playList[1][ iL[i]-1 ];
				sL2 += playList[2][ iL[i]-1 ];
				sL3 += playList[3][ iL[i]-1 ];
				sL4 += playList[4][ iL[i]-1 ];
			}

			playList[0].clear();
			playList[1].clear();
			playList[2].clear();
			playList[3].clear();
			playList[4].clear();

			playList[0] = sL0;
			playList[1] = sL1;
			playList[2] = sL2;
			playList[3] = sL3;
			playList[4] = sL4;

			iL.clear();

			sL0.clear();
			sL1.clear();
			sL2.clear();
			sL3.clear();
			sL4.clear();


			QStringList selL;
			for ( i = 0 ; i < count() ; i++ )
				if ( item(i)->isSelected() )
					selL += bezNr(item(i)->text());

			fp.createList();
			if ( nrplay_update ) //jeżeli znalazł aktualnie odtwarzaną piosenkę
				setCurrentRow( nrplay ); //podświetl ją na liście
			else
				setCurrentRow( cR );

			for ( i = 0 ; i < count() ; i++ )
			{
				if ( selL.contains( bezNr( item(i)->text() ) ) )
				{
					selL.removeAll( bezNr( item(i)->text() ) );
					item( i )->setSelected( true );
				}
				else
					item( i )->setSelected( false );
			}
			selL.clear();
		}
		void mouseMoveEvent(QMouseEvent *event)
		{
			if ( ( ( event->buttons() & Qt::MidButton ) || ( ( event->buttons() & Qt::LeftButton ) && Modifier ) ) && count() > 0 )
			{
				QDrag *drag = new QDrag(this);
				QMimeData *mimeData = new QMimeData;

				QList<QUrl> urls = getCopyData();
				mimeData->setUrls( urls );
				urls.clear();
				drag->setMimeData(mimeData);
				drag->setPixmap( fp.ui.infoMB->icon().pixmap( 48, 48 ) );

				fp.setAcceptDrops(false);
				drag->start(Qt::CopyAction|Qt::MoveAction|Qt::LinkAction);
				fp.setAcceptDrops(true);
			}
			else if ( ( event->buttons() & Qt::LeftButton ) && !plistthr.isRunning() )
			{
				cR = currentRow();
				QListView::mouseMoveEvent(event);
			}
			else
			{
				QListWidgetItem *wI = itemAt( mapFromGlobal( QCursor::pos() ) );
				if ( wI )
				{
					cRow = row( wI );
					if ( lRow == cRow )
						return;

					mPos = QCursor::pos();

					if ( tim.isActive() )
						tim.stop();

					mI.close();
					tim.start( 1350 );
				}
				else
				{
					mI.close();
					mI.ui.pixmap->setPixmap( 0 );
					lRow = -2;
				}
			}
		}
		void mousePressEvent( QMouseEvent *e )
		{
			tim.stop();
			mI.close();
			mI.ui.pixmap->setPixmap( 0 );
			QListView::mousePressEvent(e);
		}
		void keyPressEvent( QKeyEvent *e )
		{
			if ( e->key() == 'Q' )
			{
				int X = Func.nr();
				if ( X > -1 && playList[1][X] != "separator" )
				{
					if ( itemsQueue.contains( X ) )
						itemsQueue.removeOne( X );
					else
						itemsQueue += X;
					int w = currentRow();
					fp.createList();
					setCurrentRow( w );
				}
			}
			else if ( e->key() != Qt::Key_Up && e->key() != Qt::Key_Down )
			{
				tim.stop();
				mI.close();
				mI.ui.pixmap->setPixmap( 0 );
			}
#ifdef Q_WS_X11
			Modifier = e->modifiers() == Qt::MetaModifier;
#else
			Modifier = e->modifiers() == Qt::AltModifier;
#endif
			QListWidget::keyPressEvent(e);
		}
		void keyReleaseEvent( QKeyEvent * )
		{
			Modifier = false;
		}
		void leaveEvent( QEvent* )
		{
			tim.stop();
			mI.close();
			mI.ui.pixmap->setPixmap( 0 );
			lRow = -2;
		}
};
titleList *titlelist;
void FormPlaylist::infoListTimerDo()
{
	titlelist->tim.stop();

	if ( QCursor::pos() == titlelist->mPos )
	{
		int cRow = titlelist->cRow;

		InputPlugin *plugStruct = NULL;
		if ( Func.chkFNr( cRow ) )
			plugStruct = Func.getMusicFormat( playList[1][cRow], playList[2][cRow] );
		if ( !plugStruct )
		{
			titlelist->lRow = -2;
			titlelist->cRow = -1;
			return;
		}

		QString title = playList[0][cRow];
		QString path = Func.plikbezsciezki( playList[2][cRow] );
		QString length = Func.timeFormat( playList[3][cRow].toInt(), true );

		QString plugTxt;
		QPixmap pix = NULL;

		plugTxt = Func.getFromPlugInfo( playList[2][cRow], pix, plugStruct );

		mI.ui.pixmap->setPixmap( pix );

		mI.ui.label->setText( Texts[128] + "	" + title + "\n" + Texts[129] + "	" + length + "\n" + Texts[130] + "	" + path + "\n" + Texts[131] + "	" + QString::number( cRow + 1 ) + plugTxt );

		mI.ui.plugName->setText( plugStruct->pluginInfo->Name );

		mI.setParent(this);
		mI.setWindowFlags(Qt::ToolTip);
		mI.move( QCursor::pos().x() + 3, QCursor::pos().y() + 3 );

		mI.file = playList[2][cRow];
		mI.cRow = cRow;

		mI.ui.musP->setMaximum( playList[3][cRow].toInt() );
		if ( isPlaying && cRow == nrplay && file == playList[2][cRow] )
		{
			mI.ui.musP->setValue( *Iplug->pltime );
			mI.ui.musP->show();
		}
		else
			mI.ui.musP->hide();

		mI.resize( 0, 0 );
		mI.show();
		mI.resize( 0, 0 );
		if ( mI.x() + mI.width() > qdw.width() ) //żeby nie wychodziło poza ekran
			mI.move( qdw.width() - mI.width(), mI.y() );

		titlelist->lRow = titlelist->cRow;
	}
	else
		titlelist->lRow = -2;
	titlelist->cRow = -1;
}

QList<QUrl> getCopyData()
{
	QList<QUrl> urls;
	QString URL;
	for ( int i = 0 ; i < titlelist->count() ; i++ )
	{
		if ( !titlelist->item(i)->isSelected() )
			continue;
		if ( i > playList[2].count()-1 )
		{
			urls.clear();
			return urls;
		}
		if ( QFile::exists( playList[2][i] ) )
#ifdef Q_WS_WIN
			urls += "file:///"+playList[2][i];
#else
			urls += "file://"+playList[2][i];
#endif
	}
	return urls;
}
