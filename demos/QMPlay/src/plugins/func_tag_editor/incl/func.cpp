QWidget *openWindow( const char *fName, QWidget *par, bool b, bool *_isOpened )
{
	if ( !QFile::exists( fName ) )
		return NULL;

	Window *window = new Window;

	window->ui.fileE->setText( fName );
	window->openFile();

	window->setParent( par );
	if ( !b )
	{
		if ( par )
			window->setWindowFlags( Qt::Window );
		window->move( QCursor::pos().x() - window->width()/2, QCursor::pos().y() - window->height()/2 );
	}
	window->show();

	window->isOpened = _isOpened;
	if ( window->isOpened )
		*window->isOpened = true;

	return window;
}

QString getData( const char *fName, QImage *pix )
{
	QMPlay_Tag tag( fName );

	if ( tag.isNull )
		return "";

	if ( tag.picture.size() && pix )
		*pix = QImage::fromData( (const uchar *)tag.picture.data(), tag.picture.size() );

	QString toRet;
	if ( !tag.title.isEmpty() )
		toRet += "Title	" + QString( tag.title.toCString( true ) ) + "\n";
	if ( !tag.artist.isEmpty() )
		toRet += "Artist	" + QString( tag.artist.toCString( true ) ) + "\n";
	if ( !tag.album.isEmpty() )
		toRet += "Album	" + QString( tag.album.toCString( true ) ) + "\n";
	if ( !tag.comment.isEmpty() )
		toRet += "Comment	" + QString( tag.comment.toCString( true ) ) + "\n";
	if ( !tag.genre.isEmpty() )
		toRet += "Genre	" + QString( tag.genre.toCString( true ) ) + "\n";
	if ( tag.year )
		toRet += "Year	" + QString::number( tag.year ) + "\n";
	if ( tag.track )
		toRet += "Track	" + QString::number( tag.track ) + "\n";
	toRet.truncate( toRet.length() - 1 );

	return toRet;
}


void opcje(QWidget*)
{

}

void show(QWidget *w)
{
	w->setMinimumSize( f1.minimumSize() );
	w->setMaximumSize( f1.maximumSize() );
	f1.setParent(w);
	f1.move(0,0);
	f1.show();
}

void getOutLib( Qmp *_QLib )
{
	QLib = _QLib;
}

void Init()
{
}

void closePlug()
{
	f1.setParent(NULL);
	f1.close();
}

void setLangWindow( Window *w )
{
	w->ui.browseB->setText( QMPset->value( "QMPlay_tag_editor_window/0" ).toString() );
	w->ui.clrB->setText( QMPset->value( "QMPlay_tag_editor_window/1" ).toString() );
	w->ui.updateB->setText( QMPset->value( "QMPlay_tag_editor_window/2" ).toString() );
	w->img->setToolTip( QMPset->value( "QMPlay_tag_editor_window/3" ).toString() );
	w->ui.titleE->setToolTip( QMPset->value( "QMPlay_tag_editor_window/4" ).toString() );
	w->ui.artistE->setToolTip( QMPset->value( "QMPlay_tag_editor_window/5" ).toString() );
	w->ui.albumE->setToolTip( QMPset->value( "QMPlay_tag_editor_window/6" ).toString() );
	w->ui.commentE->setToolTip( QMPset->value( "QMPlay_tag_editor_window/7" ).toString() );
	w->ui.genreE->setToolTip( QMPset->value( "QMPlay_tag_editor_window/8" ).toString() );
	w->ui.yearB->setToolTip( QMPset->value( "QMPlay_tag_editor_window/9" ).toString() );
	w->ui.trackB->setToolTip( QMPset->value( "QMPlay_tag_editor_window/10" ).toString() );

	f1.ui.oocFB->setText( Texts[0] );
}

void setLang( QString _langfile )
{
	langfile = _langfile;

	Texts.clear();

	QMPset = new QSettings( langfile , QSettings::IniFormat );
	QMPset->setIniCodec( "UTF-8" );

	for ( int i = 0 ; i < langCount ; i++ )
		Texts += QMPset->value( "QMPlay_tag_editor/" + QString::number(i) ).toString();

	setLangWindow( &f1 );

	delete QMPset;
}

extern "C" void about(QWidget* w)
{
	QMessageBox::information( w, "QMPlay", "QMPlay tag editor");
}
