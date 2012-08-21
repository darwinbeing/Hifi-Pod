#include <QKeyEvent>

void FormFunc::Init()
{
	if ( !once )
	{
		ui.setupUi(this);
		ui.progress->close();
		connect( &listaThr, SIGNAL( finished() ), this, SLOT( thrFinished() ) );
		connect( ui.lista, SIGNAL( itemDoubleClicked( QListWidgetItem * ) ), this, SLOT( openLink( QListWidgetItem * ) ) );
		connect( ui.createList, SIGNAL( clicked() ), this, SLOT( createList() ) );
	}
	once = true;
}

void FormFunc::showEvent( QShowEvent *e )
{
	if ( !onceShow )
	{
		onceShow = true;
		ui.infoL->setText( Texts[ 3 ] /* Pobieranie listy, czekaj...*/ );
		ui.lista->clear();
		ui.progress->show();
		listaThr.start();
	}
	QWidget::showEvent( e );
}
void FormFunc::keyPressEvent( QKeyEvent *e )
{
	if ( e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter )
		openLink( ui.lista->currentItem() );
}

void FormFunc::openLink( QListWidgetItem *i )
{
	if ( !i )
		return;
	QString url = i->data( Qt::UserRole ).toString();
	if ( !url.isEmpty() )
	{
		QLib->control(1,0);
		QLib->addToPlayList( (QStringList)(url),-1 );
		QLib->lastOnList();
		QLib->control(0,0);
		QLib->showMessage( "QMPlay", Texts[ 2 ] + ": " + i->data( Qt::DisplayRole ).toString(), 1, 0, true );
	}
}

void FormFunc::thrFinished()
{
	ui.progress->close();

	if ( listaThr.RadioList.left( 4 ) != "NXRL" )
	{
		ui.infoL->setText( Texts[ 1 ] /* Blad podczas pobierania listy */ );
		listaThr.RadioList.clear();
		onceShow = false;
		return;
	}

	int separators = 0;

	QListWidgetItem *lwi;
	QString GroupName;
	while ( listaThr.RadioList.size() )
	{
		if ( listaThr.RadioList.left( 4 ) == "NXRL" )
		{
			listaThr.RadioList.remove( 0, 4 );
			GroupName = listaThr.RadioList;
			listaThr.RadioList.remove( 0, GroupName.toUtf8().length() + 1 );

			lwi = new QListWidgetItem;
			lwi->setData( Qt::DisplayRole, "\n" + GroupName + "\n" );
			QFont font;
			font.setBold( true );
			font.setPointSize( font.pointSize() + 2 );
			lwi->setData( Qt::FontRole, font );
			lwi->setData( Qt::TextAlignmentRole, Qt::AlignRight );
			lwi->setData( Qt::DecorationRole, pixmap );
			ui.lista->addItem( lwi );

			separators++;
		}

		QString nazwa = listaThr.RadioList;
		listaThr.RadioList.remove( 0, nazwa.toUtf8().length() + 1 );
		QString URL = listaThr.RadioList;
		listaThr.RadioList.remove( 0, URL.toUtf8().length() + 1 );
		int imgSize = *( int * )listaThr.RadioList.data();
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
		for ( int i = 0 ; i < sizeof( int ) / 2 ; i++ )
		{
			char tmp = ( ( char * )&imgSize )[ i ];
			( ( char * )&imgSize )[ i ] = ( ( char * )&imgSize )[ sizeof( int ) - i - 1 ];
			( ( char * )&imgSize )[ sizeof( int ) - i - 1 ] = tmp;
		}
#endif
		listaThr.RadioList.remove( 0, sizeof( int ) );
		QByteArray img = listaThr.RadioList.mid( 0, imgSize );
		listaThr.RadioList.remove( 0, imgSize );

		lwi = new QListWidgetItem;
		lwi->setData( Qt::DisplayRole, nazwa );
		lwi->setData( Qt::UserRole, URL );
		lwi->setData( Qt::ToolTipRole, GroupName );
		if ( img.size() )
		{
			QPixmap pix;
			pix.loadFromData( img );
			lwi->setData( Qt::DecorationRole, pix );
		}
		else
			lwi->setIcon( QLib->getIcon( PLAY_ICON ) );
		ui.lista->addItem( lwi );
	}

	listaThr.RadioList.clear();
	ui.infoL->setText( Texts[ 0 ] /* Liczba stacji radiowych */ + ": " + QString::number( ui.lista->count() - separators ) );
}
void FormFunc::createList()
{
	int count = ui.lista->count();
	if ( !count )
		return;

	QStringList URLs;
	for ( int i = 0 ; i < count ; i++ )
	{
		QString addr = ui.lista->item( i )->data( Qt::UserRole ).toString();
		if ( addr.isEmpty() )
		{
			URLs += "separator://" + ui.lista->item( i )->data( Qt::DisplayRole ).toString();
			continue;
		}
		URLs += addr;
	}

	QLib->addToPlayList( URLs, -1 );
}
