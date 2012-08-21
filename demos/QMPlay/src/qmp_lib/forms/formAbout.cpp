void FormAbout::cleanB()
{
	QFile::remove( LogFile );
	ui.logE->clear();
	ref();
}

void FormAbout::Init()
{
	ui.label_ver->setText( QMPVersion );
	fa.setGeometry( faGeo );
	ui.kBB->setValue( kBB );
	ref();

	QFile f( "ChangeLog_QMPlay.txt" );
	if ( f.open( QFile::ReadOnly ) )
	{
		ui.changeLogE->setText( f.readAll() );
		f.close();
	}
}

void FormAbout::add( QString a )
{
	QFile flog( LogFile );
	if ( !flog.open( QFile::Append ) )
		return;
	a.prepend( "[" + QDate::currentDate().toString( "dd.MM.yyyy" ) + " " + QTime::currentTime().toString( "hh:mm:ss" ) + "] " );
	flog.write( a.toUtf8() + "\r\n" );
	flog.close();
}

void FormAbout::closeEvent(QCloseEvent*)
{
	ui.logE->clear();
	ui.changeLogE->clear();

	faGeo = geometry();

	kBB = ui.kBB->value();
}

void FormAbout::ref()
{
	QFile flog( LogFile );
	if ( !flog.open( QFile::ReadOnly ) )
	{
		ui.kBL->setText( "0kB" );
		return;
	}
	int size = flog.size();
	ui.logE->clear();
	ui.logE->append( flog.readAll() );
	flog.close();
	ui.kBL->setText( QString::number( size / 1024 ) + "kB" );
}

void FormAbout::clrLog()
{
	if ( QFile( LogFile ).size() > kBB*1024 )
		QFile::remove( LogFile );
}
