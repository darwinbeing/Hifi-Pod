void FormFunc::Init()
{
	if ( !once )
	{
		ui.setupUi(this);
		ui.currPageB->setVisible( false );
		ui.dwnW->setVisible( false );
		connect( ui.searchB, SIGNAL( clicked() ), this, SLOT( searchB() ) );
		connect( ui.titleE, SIGNAL( returnPressed() ), this, SLOT( searchB() ) );
		connect( ui.prevB, SIGNAL( clicked() ), this, SLOT( prevB() ) );
		connect( ui.nextB, SIGNAL( clicked() ), this, SLOT( nextB() ) );
		connect( ui.clrB, SIGNAL( clicked() ), this, SLOT( clrB() ) );
		connect( ui.titlesW, SIGNAL( cellDoubleClicked(int,int) ), this, SLOT( playB() ) );
		connect( ui.playB, SIGNAL( clicked() ), this, SLOT( playB() ) );
		connect( ui.downloadB, SIGNAL( clicked() ), this, SLOT( downloadB() ) );
		connect( ui.currPageB, SIGNAL( editingFinished() ), this, SLOT( setPage() ) );
		connect( ui.abortB, SIGNAL( clicked() ), this, SLOT( abortB() ) );
		connect( &timRef, SIGNAL( timeout() ), this, SLOT( timeOut() ) );
		connect( ui.titlesW, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( mnuTPopup() ) );
		connect( ui.queueW, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( mnuQPopup() ) );
		connect( ui.dwnPB, SIGNAL( clicked() ), this, SLOT( dwnPB() ) );
		connect( this, SIGNAL( infoLUpdated( QString ) ), this, SLOT( updateInfoL( QString ) ) );
	}
	Save.odczytajopcje();
	once = true;
}

void FormFunc::updateInfoL( QString s )
{
	ui.infoL->setText( s );
}

void FormFunc::chPage(bool b)
{
	if ( !b )
		return;
	Save.zapiszopcje();
	clrB();
}

void FormFunc::dwnPB()
{
	QString pth2 = QLib->fileDialog( OPEN_DIR, this, Texts[0] /* "Wyierz sciezke do zapisu" */, pth, "", NULL )[0];
	if ( !pth2.isEmpty() && QFile::exists( pth2 ) )
	{
		pth = pth2;
		Save.zapiszopcje();
	}
}

void FormFunc::resizeEvent( QResizeEvent * )
{
	int W = ui.titlesW->width();
	int hW = ui.titlesW->verticalHeader()->sizeHint().width() + 22;
	int titleW = 0.55 * (double)W;
	int othW = 0.15 * (double)W;
	ui.titlesW->setColumnWidth( 0, titleW );
	ui.titlesW->setColumnWidth( 1, othW - hW/2 );
	ui.titlesW->setColumnWidth( 2, othW - hW/2 );
	ui.titlesW->setColumnWidth( 3, othW );
}

#include "readers.h"

const int LISTA_MAX = 6;
QStringList lista[ LISTA_MAX ];
int currPage, maxPages, lastMaxPages;
QString address;

struct searchThr : public QThread
{
	searchThr()
	{
		connect( this, SIGNAL( finished() ), &ff, SLOT( searchAddressAfterThr() ) );
	}
	void run()
	{
		breakThr = false;

		QString tmpAddr;
		if ( firstPage )
			currPage = 1;
		tmpAddr = address + QString::number( currPage );
		ff.clr2();

		QByteArray xmlStr;
		URL_FILE *f = url_fopen( tmpAddr.toAscii() );
		if ( f )
		{
			char *data = new char[ 4096 ];
			int ile = MAX_ILE;
			uint bread(0);
			error = false;
			while ( !url_feof( f ) )
			{
				if ( breakThr )
				{
					delete[] data;
					url_fclose( f );
					ff.clr2();
					return;
				}
				bread = url_fread( data, 1, 4096, f );

				if ( !bread && !url_feof( f ) && !--ile )
				{
					error = true;
					break;
				}
				if ( bread )
					ile = MAX_ILE;

				for ( uint i = 0 ; i < bread ; i++ )
					xmlStr += data[i];
			}
			delete[] data;
			url_fclose( f );

			QStringList ( *Split )( QString ) = NULL;
			QString ( *getData )( QString, DataType ) = NULL;

			Split = _WrzutaReader::Split;
			getData = _WrzutaReader::getData;

			QStringList list = Split( xmlStr );
			xmlStr.clear();
			maxPages = list[0].toInt();
			for ( int i = 1 ; i < list.count() ; i++ )
			{
				if ( breakThr )
				{
					list.clear();
					ff.clr2();
					return;
				}

				lista[NAME] += getData( list[i], NAME );
				lista[FSIZE] += getData( list[i], FSIZE );
				ff.infoL( Texts[20] + " " + QString::number( i ) + " / " + QString::number( list.count()-1 ) );
				lista[FURL] += getData( list[i], FURL );
				lista[USERNAME] += getData( list[i], USERNAME );
				lista[LENGTH] += getData( list[i], LENGTH );
				lista[PURL] += getData( list[i], PURL );
			}
			list.clear();
		}
		else
			error = true;
	}
	bool error, breakThr, firstPage;
} searchThr;

void FormFunc::breakThr()
{
	if ( searchThr.isRunning() )
	{
		searchThr.breakThr = true;
		searchThr.wait( 2000 );
		if ( searchThr.isRunning() )
		{
			searchThr.terminate();
			searchThr.wait( 1000 );
		}
	}
}

void FormFunc::searchAddressAfterThr()
{
	unloadCURL();

	clr1();
	setUiEnabled( true );

	if ( searchThr.breakThr )
		return;

	if ( searchThr.error )
	{
		ui.infoL->setText( Texts[1] /* "Connection error!" */ );
		return;
	}

	if ( lista[NAME].count() < 1 && !maxPages )
	{
		ui.infoL->setText( Texts[2] /* "Nic nie znaleziono" */ );
		address.clear();
		return;
	}

	ui.currPageB->setVisible( true );
	ui.currPageB->setValue( currPage );

	if ( maxPages == 0 )
		maxPages = lastMaxPages;
	if ( maxPages != -1 )
	{
		ui.pagesL->setText( " / " + QString::number( maxPages ) );
		ui.currPageB->setMaximum( maxPages );
	}
	else
		ui.currPageB->setMaximum( 100 );
	ui.currPageB->setMinimum( 1 );

	ui.titlesW->setRowCount( lista[NAME].count() );
	QTableWidgetItem *tmpItem;
	for ( int i = 0 ; i < ui.titlesW->rowCount() ; i++ )
	{
		tmpItem = new QTableWidgetItem( lista[NAME][i] );
		ui.titlesW->setItem( i, 0, tmpItem );

		tmpItem = new QTableWidgetItem( lista[LENGTH][i] );
		ui.titlesW->setItem( i, 1, tmpItem );

		tmpItem = new QTableWidgetItem( lista[FSIZE][i] );
		ui.titlesW->setItem( i, 2, tmpItem );

		tmpItem = new QTableWidgetItem( lista[USERNAME][i] );
		ui.titlesW->setItem( i, 3, tmpItem );
	}

	resizeEvent( NULL );

	ui.infoL->setText( Texts[3] /* "Zaladowano!" */ );
}
void FormFunc::searchAddress( bool firstPage )
{
	ui.infoL->setText( "" );
	loadCURL();
	if ( !CURLloaded )
		return;
	ui.infoL->setText( Texts[20] /*Wyszukiwanie*/ );
	setUiEnabled( false );
	searchThr.firstPage = firstPage;
	searchThr.start();
}

void FormFunc::setUiEnabled( bool b )
{
	if ( !b )
		ui.searchB->setText( Texts[ 21 ] /*Zatrzymaj*/ );
	else
		ui.searchB->setText( Texts[ 22 ] /*Szukaj*/ );

	ui.titleE->setEnabled( b );
	ui.titlesW->setEnabled( b );
	ui.prevB->setEnabled( b );
	ui.nextB->setEnabled( b );
	ui.currPageB->setEnabled( b );
	ui.dwnPB->setEnabled( b );
	ui.clrB->setEnabled( b );
	ui.downloadB->setEnabled( b );
	ui.playB->setEnabled( b );
}

void FormFunc::searchB()
{
	if ( searchThr.isRunning() )
	{
		breakThr();
		return;
	}

	lastMaxPages = 0;
	if ( ui.titleE->text().isEmpty() )
	{
		ui.infoL->setText( Texts[4] /* "Puste" */ );
		return;
	}

	QString txt = ui.titleE->text();
	txt.replace( ' ', '+' );
	txt = QUrl::toPercentEncoding( txt );
	address = "http://www.wrzuta.pl/szukaj/audio/" + txt + "/";

	searchAddress( true );
}

void FormFunc::prevB()
{
	if ( currPage > 1 && !address.isEmpty() )
	{
		currPage--;
		searchAddress( false );
	}
}
void FormFunc::nextB()
{
	if ( ( ( currPage < maxPages && maxPages != -1 ) || maxPages == -1 ) && !address.isEmpty() )
	{
		currPage++;
		searchAddress( false );
	}
}
void FormFunc::setPage()
{
	if ( ui.currPageB->isVisible() && ui.currPageB->hasFocus() )
	{
		currPage = ui.currPageB->value();
		searchAddress( false );
	}
}

void FormFunc::clrB()
{
	if ( ui.clrB->hasFocus() )
		address.clear();
	clr1();
	clr2();
}
void FormFunc::clr1()
{
	for ( int i = 0 ; i < ui.titlesW->rowCount() ; i++ )
	{
		delete ui.titlesW->item( i, 0 );
		delete ui.titlesW->item( i, 1 );
		delete ui.titlesW->item( i, 2 );
		delete ui.titlesW->item( i, 3 );
	}
	ui.titlesW->setRowCount( 0 );
	ui.pagesL->setText( "" );
	ui.infoL->setText( "" );
	ui.currPageB->setVisible( false );
}
void FormFunc::clr2()
{
	lastMaxPages = maxPages;
	maxPages = -1;
	for ( int i = 0 ; i < LISTA_MAX ; i++ )
		lista[i].clear();
}

void FormFunc::downloadB()
{
	if ( ui.titlesW->currentRow() < 0 )
		return;
	qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );
	QString ext, Addr = getMusAddr( lista[FURL][ ui.titlesW->currentRow() ] );
	ext = ".mp3";

	if ( ui.titlesW->currentRow() > -1 && ui.titlesW->rowCount() > 0 )
		ui.queueW->addItem( lista[NAME][ ui.titlesW->currentRow() ] + ext + " -> " + Addr );

	if ( !dwnThr.isRunning() && ui.queueW->count() > 0 )
	{
		dwnThr.start();
		timRef.start( 250 );
		ui.dwnW->setVisible( true );
	}
	qApp->restoreOverrideCursor();
}

QString timeFormat( int pltime )
{
	if ( pltime < 0 )
		return "??:??";
	QString qTim,qSek,qMin;
	int sek,min,hour;

	sek = pltime % 60;
	min = pltime / 60;

	if (min < 10)
		qMin = "0" + QString::number(min);
	else if (min < 60)
		qMin = QString::number(min);
	else if (min >= 60)
	{
		hour = min / 60;
		min = min % 60;

		if (min < 10)
			qMin = "0" + QString::number(min);
		else if (min < 60)
			qMin = QString::number(min);

		qMin = QString::number(hour) + " : " + qMin;
	}

	if (sek < 10)
		qSek = "0" + QString::number(sek);
	else
		qSek = QString::number(sek);

	qTim = qMin + " : " + qSek ;

	return qTim;
}

void FormFunc::timeOut()
{
	if ( ui.queueW->count() < 1 )
	{
		timRef.stop();
		ui.dwnW->setVisible( false );
		dwnThr.pC  = dwnThr.spd = dwnThr.rem = dwnThr.siz = dwnThr.dwn = 0;
		ui.dwnInfoL->setText("");
		ui.dwnTitleL->setText("");
		ui.progressB->setRange( 0, 100 );
		ui.progressB->setValue( 0 );
		if ( dwnThr.isRunning() )
		{
			dwnThr.wait(1000);
			dwnThr.terminate();
		}
		return;
	}

	QString dwnInfo = Texts[7] /* "Speed: " */ + QString::number( dwnThr.spd / 1024 ) + "kB/s";
	if ( dwnThr.spd )
	{
		dwnInfo += " ; ";
		if ( dwnThr.siz ) /* Pozostalo */
			dwnInfo += Texts[14] + ": " + QString::number( dwnThr.rem / 1024 ) + "kB" + " ( " + timeFormat( dwnThr.rem / dwnThr.spd ) + " )";
		else /* Pobrano */
		{
			ui.progressB->setRange( 0, 0 );
			dwnInfo += Texts[24] + ": " + QString::number( -dwnThr.rem / 1024 ) + "kB";
		}
	}
	ui.progressB->setValue( dwnThr.pC );
	ui.dwnInfoL->setText( dwnInfo );
	ui.dwnTitleL->setText( Texts[8] /* "Downloading: " */ + ui.queueW->item(0)->text() );
}

void FormFunc::abortB()
{
	dwnThr.bolBr = true;
}
void FormFunc::abortAll()
{
	dwnThr.bolBr = dwnThr.abortAll = true;
	dwnThr.wait(2000);
	if ( dwnThr.isRunning() )
	{
		dwnThr.terminate();
		dwnThr.wait(1000);
	}
}

void FormFunc::playB()
{
	qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );
	QString addr = getMusAddr( "" );
	qApp->restoreOverrideCursor();
	if ( addr.isEmpty() )
	{
		ui.infoL->setText( Texts[6] /* "Blad odczytu pliku!" */ );
		return;
	}
	else if ( addr == "-" )
		return;
	if ( QLib )
	{
		QLib->control(1,0);
		QLib->addToPlayList( (QStringList)( addr ),-1 );
		QLib->lastOnList();
		QLib->control(0,0);
		ui.infoL->setText( Texts[5] /* "Dodano wpis: " */ + addr );
	}
}
void FormFunc::queueB()
{
	qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );
	QString addr = getMusAddr( "" );
	qApp->restoreOverrideCursor();
	if ( addr.isEmpty() )
	{
		ui.infoL->setText( Texts[6] /* "Blad odczytu pliku!" */ );
		return;
	}
	else if ( addr == "-" )
		return;
	if ( QLib )
	{
		QLib->addToPlayList( (QStringList)( addr ),-1 );
		ui.infoL->setText( Texts[5] /* "Dodano wpis: " */ + addr );
	}
}

QString FormFunc::getXmlStrToReadMusAddr( QString a )
{
	if ( ( ui.titlesW->currentRow() > -1 && ui.titlesW->rowCount() > 0 ) || !a.isEmpty() )
	{
		QString URL;
		if ( a.isEmpty() )
			URL = lista[FURL][ ui.titlesW->currentRow() ];
		else
			URL = a;

		loadCURL();
		if ( !CURLloaded )
			return "";
		bool error = false;
		QByteArray xmlStr;
		URL_FILE *f = url_fopen( URL.toAscii() );
		if (f)
		{
			char *data = new char[ 4096 ];
			int ile = MAX_ILE;
			uint bread(0);
			while ( !url_feof(f) )
			{
				bread = url_fread( data, 1, 4096, f );

				if ( !bread && !url_feof( f ) && !--ile )
				{
					error = true;
					break;
				}
				if ( bread )
					ile = MAX_ILE;

				for ( uint i = 0 ; i < bread ; i++ )
					xmlStr += data[i];
			}
			delete[] data;
			url_fclose( f );
		}
		else
			error = true;
		unloadCURL();

		if ( error )
			return "";
		else
			return xmlStr;
	}
	return "-";
}

QString FormFunc::getMusAddr( QString a )
{
	QString xmlStr = getXmlStrToReadMusAddr( a );
	if ( xmlStr.count() < 2 )
		return xmlStr;

	QString ( *getFileURL )( QString ) = NULL;
	getFileURL = _WrzutaReader::getFileURL;

	QString fName = /*QUrl::fromPercentEncoding(*/ getFileURL( xmlStr )/*.toAscii() )*/;
	if ( fName.isEmpty() )
		return "";

	QString w_title;
	w_title = "&QMPlay_title=Wrzuta: " + lista[NAME][ ui.titlesW->currentRow() ];

	return fName + w_title;
}

void FormFunc::copyAddr()
{
	if ( ui.titlesW->currentRow() > -1 && ui.titlesW->rowCount() > 0 )
		qApp->clipboard()->setText( getMusAddr( "" ) );
}

void FormFunc::delQueueEntry()
{
	if ( ui.queueW->currentRow() > -1 && ui.queueW->count() > 0 )
	{
		if ( ui.queueW->currentRow() == 0 )
			dwnThr.bolBr = true;
		else
			ui.queueW->removeItemWidget( ui.queueW->takeItem( ui.queueW->currentRow() ) );
	}
}

void FormFunc::openInBrowser()
{
	QLib->open( lista[PURL][ ui.titlesW->currentRow() ] );
}

void FormFunc::mnuTPopup()
{
	mnuT.clear();

	bool show = false;

	if ( ui.titlesW->currentRow() > -1 && ui.titlesW->rowCount() > 0 )
	{
		mnuT.addAction( Texts[10] /*"Odtwarzaj"*/, this, SLOT( playB() ) );
		mnuT.addAction( Texts[16] /*"Kolejkuj"*/, this, SLOT( queueB() ) );
		mnuT.addSeparator();
		mnuT.addAction( Texts[11] /*"Pobierz"*/, this, SLOT( downloadB() ) );
		mnuT.addSeparator();
		mnuT.addAction( Texts[12] /*"Skopiuj adres"*/, this, SLOT( copyAddr() ) );
		mnuT.addSeparator();
		if ( QLib->open( "" ) )
		{
			mnuT.addAction( Texts[23] /*"Otwórz w przeglądarce"*/, this, SLOT( openInBrowser() ) );
			mnuT.addSeparator();
		}

		show = true;
	}

	if ( show )
		mnuT.popup( QCursor::pos() );
}
void FormFunc::mnuQPopup()
{
	mnuQ.clear();
	if ( ui.queueW->currentRow() > -1 && ui.queueW->count() > 0 )
	{
		mnuQ.addAction( Texts[12] /*"Skopiuj adres"*/, this, SLOT( copyAddr2() ) );
		mnuQ.addSeparator();
		mnuQ.addAction( Texts[9] /* "Usun wpis" */, this, SLOT( delQueueEntry() ) );
		mnuQ.popup( QCursor::pos() );
	}
}

void FormFunc::copyAddr2()
{
	if ( ui.queueW->currentRow() > -1 && ui.queueW->count() > 0 )
		qApp->clipboard()->setText( ui.queueW->item( ui.queueW->currentRow() )->text().split( " -> " )[1] );
}
