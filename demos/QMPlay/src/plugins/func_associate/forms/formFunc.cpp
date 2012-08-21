void Form1::Init()
{
	if ( !once )
	{
		once = true;
		ui.setupUi(this);
		connect( ui.selAllB, SIGNAL( clicked() ), this, SLOT( selAll() ) );
		connect( ui.revSelB, SIGNAL( clicked() ), this, SLOT( revSel() ) );
		connect( ui.addB, SIGNAL( clicked() ), this, SLOT( add() ) );
		connect( ui.delB, SIGNAL( clicked() ), this, SLOT( del() ) );
		connect( ui.clrB, SIGNAL( clicked() ), this, SLOT( clr() ) );
		connect( ui.applyB, SIGNAL( clicked() ), this, SLOT( apply() ) );
		connect( ui.getExtsB, SIGNAL( clicked() ), this, SLOT( getExts() ) );
		connect( &timer, SIGNAL( timeout() ), this, SLOT( chkExts() ) );
	}
	Save.odczytajopcje();
}

void Form1::addToList( QString txt )
{
	ui.extsList->addItem( txt );
	ui.extsList->item( ui.extsList->count()-1 )->setCheckState( Qt::Checked );
}

void Form1::chkExts()
{
	if ( !QLib->chkLoad( QMP_PLUGINS_LOADED ) )
		return;
	timer.stop();
	if ( mustGetExts )
	{
		mustGetExts = false;
		getExts();
		quest();
	}
	else if ( as )
		associate();
}

void Form1::selAll()
{
	for ( int i = 0 ; i < ui.extsList->count() ; i++ )
		ui.extsList->item(i)->setCheckState( Qt::Checked );
}

void Form1::revSel()
{
	for ( int i = 0 ; i < ui.extsList->count() ; i++ )
		if ( ui.extsList->item(i)->checkState() ==  Qt::Checked )
			ui.extsList->item(i)->setCheckState( Qt::Unchecked );
		else if ( ui.extsList->item(i)->checkState() ==  Qt::Unchecked )
			ui.extsList->item(i)->setCheckState( Qt::Checked );
}

void Form1::del()
{
	if ( ui.extsList->currentRow() < 0 )
	{
		QMessageBox::warning( this, "QMPlay associate plugin", Texts[4] /*Nie wybrano wpisu*/ );
		return;
	}
	int currRow = ui.extsList->currentRow();
	QStringList tmp[2];
	for ( int i = 0 ; i < ui.extsList->count() ; i++ )
	{
		if ( i == currRow )
			continue;
		tmp[0] += ui.extsList->item(i)->text();
		tmp[1] += QString::number(ui.extsList->item(i)->checkState());
	}
	ui.extsList->clear();
	ui.extsList->addItems( tmp[0] );
	for ( int i = 0 ; i < ui.extsList->count() ; i++ )
		ui.extsList->item(i)->setCheckState( (Qt::CheckState) tmp[1][i].toInt()  );
	tmp[0].clear();
	tmp[1].clear();
	if ( currRow - 1 >= 0 )
		ui.extsList->setCurrentRow( currRow-1 );
	else
		ui.extsList->setCurrentRow( 0 );
}

void Form1::add()
{
	if ( !ui.extsE->text().isEmpty() && ui.extsE->text()[0].toAscii() != 32 )
		addToList( ui.extsE->text() );
	else
		QMessageBox::warning( this, "QMPlay associate plugin", Texts[3] /*Nie wpisano rozszerzenia*/ );
	ui.extsE->clear();
}

void Form1::clr()
{
	ui.extsList->clear();
}

void Form1::apply()
{
	Save.zapiszopcje();
	associate();
	if ( notInFunc )
		close();
}

void Form1::getExts()
{
	QString exts = QLib->getSupportedExts();
	ui.extsList->clear();
	ui.extsList->addItems(exts.split(";", QString::SkipEmptyParts));
	for ( int i = 0 ; i < ui.extsList->count() ; i++ )
		ui.extsList->item(i)->setCheckState( Qt::Checked );
	addToList( "m3u" );
	addToList( "pls" );
	addToList( "qplst" );
	addToList( "_Catalog" );
	addToList( "_Drive" );
}

void Form1::quest()
{
	int q = QMessageBox::question( NULL, "QMPlay associate plugin", Texts[0], 3, 4 );
	Save.zapiszopcje();
	if ( q == 3 )
	{
		QWidget *qW = QLib->getParent( QMP_MAIN );
		f1.setParent( NULL );
		f1.move( qW->x() + qW->width()/2 - f1.width()/2 , qW->y() + qW->height()/2 - f1.height()/2 );
		notInFunc = true;
		f1.exec();
		notInFunc = false;
		Show( NULL );
	}
}

#include "associate.cpp"

void Form1::associate()
{
	char **extsAdd(0);
	uint extsAddCount(0);
	char **extsDel(0);
	uint extsDelCount(0);

	extsAdd = new char*[ f1.ui.extsList->count() ];
	extsDel = new char*[ f1.ui.extsList->count() ];

	for ( int i = 0 ; i < f1.ui.extsList->count() ; i++ )
	{
		if ( f1.ui.extsList->item(i)->checkState() == 2 )
		{
			extsAdd[extsAddCount] = new char[ f1.ui.extsList->item(i)->text().length() + 2 ];
			strcpy( extsAdd[extsAddCount], "." );
			strcat( extsAdd[extsAddCount], f1.ui.extsList->item(i)->text().toAscii() );
			extsAddCount++;
		}
		else
		{
			extsDel[extsDelCount] = new char[ f1.ui.extsList->item(i)->text().length() + 2 ];
			strcpy( extsDel[extsDelCount], "." );
			strcat( extsDel[extsDelCount], f1.ui.extsList->item(i)->text().toAscii() );
			extsDelCount++;
		}
	}

	QString appExec = qApp->applicationFilePath();
	appExec.replace( "/", "\\" );
	Save.zapiszOnRun(0);
	QByteArray result = doAssociate( extsAdd, extsAddCount, extsDel, extsDelCount, appExec.toLocal8Bit(), as );
	Save.zapiszOnRun( ui.onRunB->isChecked() );
	if ( !result.isEmpty() )
		QMessageBox::information( this, "QMPlay associate plugin", result );

	for ( uint i = 0 ; i < extsAddCount ; i++ )
		delete[] extsAdd[i];
	for ( uint i = 0 ; i < extsDelCount ; i++ )
		delete[] extsDel[i];

	delete[] extsAdd;
	delete[] extsDel;

	as = 0;
}
