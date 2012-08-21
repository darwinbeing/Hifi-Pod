Window::Window(bool _isMainWindow, QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);

	isMainWindow = _isMainWindow;

	connect( ui.clrB, SIGNAL( clicked() ), this, SLOT( clr() ) );
	connect( ui.updateB, SIGNAL( clicked() ), this, SLOT( update() ) );
	connect( ui.browseB, SIGNAL( clicked() ), this, SLOT( browseFile() ) );
	if ( isMainWindow )
		connect( ui.fileE, SIGNAL( returnPressed() ), this, SLOT( openFile() ) );
	connect( ui.oocFB, SIGNAL( clicked() ), this, SLOT( oocF() ) );

	img = new Id3Img;
	img->s = this;
	img->setGeometry( 0, 20, ui.pictureGroupBox->width(), ui.pictureGroupBox->height() - 20 );
	img->setCursor( Qt::PointingHandCursor );
	img->setFocusPolicy( Qt::StrongFocus );
	img->setContextMenuPolicy( Qt::CustomContextMenu );
	img->setFrameShape( QFrame::StyledPanel );
	img->setFrameShadow( QFrame::Raised );
	img->setParent( ui.pictureGroupBox );
	img->setAlignment( Qt::AlignCenter );
	connect( img, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( imgMenu() ));

	tag = NULL;

	ui.widget->setEnabled( false );

	if ( !isMainWindow )
	{
		ui.fileE->setReadOnly(true);
		ui.browseB->setVisible(false);
		ui.oocFB->setVisible(false);

		QMPset = new QSettings( langfile , QSettings::IniFormat );
		QMPset->setIniCodec( "UTF-8" );
		setLangWindow( this );
		delete QMPset;

		CURRITEMSEL = QLib->getInfo( QMP_CURRITEMSEL );
	}

	wasUpdated = false;
}

Window::~Window()
{
	disconnect( ui.clrB, SIGNAL( clicked() ), this, SLOT( clr() ) );
	disconnect( ui.updateB, SIGNAL( clicked() ), this, SLOT( update() ) );
	disconnect( ui.browseB, SIGNAL( clicked() ), this, SLOT( browseFile() ) );
	if ( isMainWindow )
		disconnect( ui.fileE, SIGNAL( returnPressed() ), this, SLOT( openFile() ) );
	disconnect( ui.oocFB, SIGNAL( clicked() ), this, SLOT( oocF() ) );
	disconnect( img, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( imgMenu() ));

	img->setPixmap( NULL );

	if ( isOpened )
		*isOpened = false;

	delete img;
}


void Id3Img::mousePressEvent( QMouseEvent *e )
{
	if ( e->button() == Qt::LeftButton )
		s->loadImg();
}
void Id3Img::keyPressEvent( QKeyEvent *e )
{
	if ( e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter || e->key() == Qt::Key_Space )
		s->loadImg();
}
void Id3Img::z166SetPixmap( QPixmap pix )
{
	if ( !pix.isNull() )
		pix = pix.scaled( size(), Qt::KeepAspectRatio, Qt::SmoothTransformation );
	setPixmap( pix );
}


void Window::keyPressEvent( QKeyEvent *e )
{
	if ( !isMainWindow && e->key() == Qt::Key_Escape )
		close();
}
void Window::imgMenu()
{
	QMenu *mnu = new QMenu;
	mnu->setAttribute( Qt::WA_DeleteOnClose );

	mnu->addAction( Texts[2] /* load */, this, SLOT( loadImg() ) );
	if ( !img->pixmap()->isNull() )
		mnu->addAction( Texts[3] /* save */, this, SLOT( saveImg() ) );

	mnu->popup( QCursor::pos() );
}
void Window::loadImg()
{
	QString pth = QLib->currPath( NULL );
	QString imgFile = QLib->fileDialog( OPEN_FILE, this, plugName, pth, "", NULL )[0];
	QFile f( imgFile );
	if ( f.open( QIODevice::ReadOnly ) )
	{
		QLib->currPath( &imgFile );
		tag->picture.setData( f.readAll().data(), f.size() );
		img->z166SetPixmap( QPixmap::fromImage( QImage::fromData( (const uchar *)tag->picture.data(), tag->picture.size() ) ) );
		f.close();
	}
}
void Window::saveImg()
{
	QString pth = QLib->currPath( NULL );
	QString format = "." + QImageReader( QDataStream( QByteArray( tag->picture.data(), tag->picture.size() ) ).device() ).format();
	QString imgFile = QLib->fileDialog( SAVE_FILE, this, plugName, pth, "", NULL )[0];
	if ( imgFile.isEmpty() )
		return;
	if ( !imgFile.contains( format ) )
		imgFile += format;
	QFile f( imgFile );
	if ( f.open( QIODevice::WriteOnly ) )
	{
		QLib->currPath( &imgFile );
		f.write( tag->picture.data(), tag->picture.size() );
		f.close();
	}
}

void Window::clr()
{
	tag->clear();
	load();
	wasUpdated = true;
}

void Window::update()
{
	if ( ui.tagGroupBox->isChecked() )
	{
		using namespace TagLib;

		tag->title = String( ui.titleE->text().toUtf8().data(), String::UTF8 );
		tag->artist = String( ui.artistE->text().toUtf8().data(), String::UTF8 );
		tag->album = String( ui.albumE->text().toUtf8().data(), String::UTF8 );
		tag->comment = String( ui.commentE->toPlainText ().toUtf8().data(), String::UTF8 );
		tag->genre = String( ui.genreE->text().toUtf8().data(), String::UTF8 );
		tag->year = ui.yearB->value();
		tag->track = ui.trackB->value();
	}
	else
	{
		tag->title = "";
		tag->artist = "";
		tag->album = "";
		tag->comment = "";
		tag->genre = "";
		tag->year = 0;
		tag->track = 0;
	}

	if ( !ui.pictureGroupBox->isChecked() )
		tag->picture.clear();

	tag->save();
	load();
	wasUpdated = true;
}

void Window::load()
{
	clearWindow();

	tag = new QMPlay_Tag( fName.toUtf8() );
	if ( !tag->isNull )
	{
		ui.titleE->setText( tag->title.toCString( true ) );
		ui.artistE->setText( tag->artist.toCString( true ) );
		ui.albumE->setText( tag->album.toCString( true ) );
		ui.commentE->setText( tag->comment.toCString( true ) );
		ui.genreE->setText( tag->genre.toCString( true ) );
		ui.yearB->setValue( tag->year );
		ui.trackB->setValue( tag->track );

		if ( !tag->title.isEmpty() || !tag->artist.isEmpty() || !tag->album.isEmpty() || !tag->comment.isEmpty() || !tag->genre.isEmpty() || tag->year || tag->track )
			ui.tagGroupBox->setChecked( true );

		if ( tag->picture.size() )
		{
			img->z166SetPixmap( QPixmap::fromImage( QImage::fromData( (const uchar *)tag->picture.data(), tag->picture.size() ) ) );
			ui.pictureGroupBox->setChecked( true );
		}
	}

	ui.widget->setEnabled( true );
	ui.oocFB->setText( Texts[1] );
}

void Window::browseFile()
{
	QString pth = QLib->currPath( NULL );
	QString _fName = QLib->fileDialog( OPEN_FILE, this, plugName, pth, "", NULL )[0];
	if ( QFile::exists( _fName ) )
	{
		QLib->currPath( &_fName );
		ui.fileE->setText( _fName );
		openFile();
	}
}

void Window::oocF()
{
	if ( ui.oocFB->text() == Texts[1] )
		closeFile();
	else
		openFile();
}

void Window::closeFile()
{
	fName.clear();
	clearWindow();
	ui.widget->setEnabled( false );
	ui.oocFB->setText( Texts[0] );

	delete tag;
	tag = NULL;
}
void Window::openFile()
{
	closeFile();
	fName = ui.fileE->text();
	if ( QFile::exists( fName ) )
		load();
	else
		fName.clear();
}

void Window::clearWindow()
{
	ui.titleE->setText( "" );
	ui.artistE->setText( "" );
	ui.albumE->setText( "" );
	ui.commentE->setText( "" );
	ui.genreE->setText( "" );
	ui.yearB->setValue( 0 );
	ui.trackB->setValue( 0 );

	img->setPixmap( NULL );

	ui.tagGroupBox->setChecked( false );
	ui.pictureGroupBox->setChecked( false );
}

void Window::closeEvent(QCloseEvent*)
{
	closeFile();
	if ( !isMainWindow )
	{
		if ( CURRITEMSEL == QLib->getInfo( QMP_CURRITEMSEL ) && wasUpdated )
		{
			QLib->control( 0x20, 0 );
			QLib->control( 0x19, 0 );
		}
		delete this;
	}
}
