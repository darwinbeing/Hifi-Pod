#include <QStringList>
#include <QMessageBox>
#include <QFile>

#include "QLib.cpp"

Qmp *QLib = NULL;

QString getFilePathFromPlist( QString fPath, QString playlistPath )
{
	QString TMP = fPath;

	if ( fPath[0] != '/' && fPath[1] != ':' && fPath[1] != '\\' && !fPath.contains( "://" ) && QFile::exists( playlistPath + "/" + fPath ) )
		TMP = playlistPath + "/" + fPath;
	else if
	(
		( fPath[0] == '/' || fPath[1] == ':' ) &&
		!fPath.contains( "://" ) && !QFile::exists( fPath ) && QFile::exists( playlistPath + "/" + QLib->stringOperations( PLIK_BEZ_SCIEZKI, TMP ) )
	)
		TMP = playlistPath + "/" + QLib->stringOperations( PLIK_BEZ_SCIEZKI, TMP );

#ifdef Q_WS_WIN
	if ( !fPath.contains( "://" ) )
		TMP.replace( '\\' , '/' );
#endif

	return TMP;
}

void prepareList( QStringList *playList, int idx )
{
	if ( !playList )
		return;
	for ( int j = 0 ; j <= 2 ; j++ )
	{
		QStringList &list = playList[ j ];
		if ( idx > list.size() - 1 )
		{
			for ( int i = list.size() ; i <= idx ; i++ )
				list += QString();
		}
	}
}

QString readLine( QFile &f )
{
	QString line = f.readLine();
	line.remove( '\n' );
	line.remove( '\r' );
	return line;
}

/**/

void setQmpLib( Qmp *_QLib )
{
	QLib = _QLib;
}

bool load( QString selfile, QStringList *playList, QStringList *tL, bool uPLeL )
{
	QFile f( selfile );
	if ( f.open( QFile::ReadOnly ) )
	{
		QString playlistPath = QLib->stringOperations( SCIEZKA_DO_PLIKU, selfile );

		if ( !tL )
			QLib->control( 0x17 /*clrplist*/, 0 );

		QString line;
		bool noReadLine = false;

		if ( selfile.right( 4 ).toLower() == ".m3u" )
		{
			while ( !f.atEnd() )
			{
				QStringList splitLine;
				if ( !noReadLine )
					line = readLine( f );
				else
					noReadLine = false;
				if ( line.isEmpty() )
					continue;

				if ( line.left( 8 ) == "#EXTINF:" )
				{
					line.remove( 0, 8 );
					int idx = line.indexOf( ',' );
					if ( idx < 0 )
						continue;
					splitLine += line.left( idx );
					line.remove( 0, idx+1 );
					splitLine += line;
					line = readLine( f );
					if ( line.isEmpty() )
						continue;
					if ( line.left( 8 ) == "#EXTINF:" )
					{
						noReadLine = true;
						continue;
					}

					if ( tL )
					{
						if ( !splitLine[ 1 ].isEmpty() )
							*tL += splitLine[ 1 ];
						else
							*tL += getFilePathFromPlist( line, playlistPath );
					}
					else
					{
						if ( uPLeL )
						{
							playList[0] += splitLine[ 1 ]; //tytuł
							playList[3] += splitLine[ 0 ]; //czas
						}
						playList[2] += getFilePathFromPlist( line, playlistPath );
					}
				}
			}
		}
		else if ( selfile.right( 4 ).toLower() == ".pls" )
		{
			QStringList list[ 3 ];
			while ( !f.atEnd() )
			{
				QStringList splitLine;
				if ( !noReadLine )
					line = readLine( f );
				else
					noReadLine = false;
				if ( line.isEmpty() )
					continue;

				int idx = line.indexOf( '=' );
				if ( idx < 0 )
					continue;
				splitLine += line.left( idx );
				line.remove( 0, idx+1 );
				splitLine += line;
				if ( splitLine[0].left( 4 ) == "File" )
				{
					splitLine[0].remove( 0, 4 );
					int idx = splitLine[0].toInt() - 1;
					prepareList( list, idx );
					if ( idx < 0 || idx > list[ 0 ].size() - 1 )
						continue;
					list[ 0 ][ idx ] = getFilePathFromPlist( splitLine[1], playlistPath );
				}
				else if ( uPLeL && splitLine[0].left( 5 ) == "Title" )
				{
					splitLine[0].remove( 0, 5 );
					int idx = splitLine[0].toInt() - 1;
					prepareList( list, idx );
					if ( idx < 0 || idx > list[ 1 ].size() - 1 )
						continue;
					list[ 1 ][ idx ] = splitLine[1];
				}
				else if ( uPLeL && splitLine[0].left( 6 ) == "Length" )
				{
					splitLine[0].remove( 0, 6 );
					int idx = splitLine[0].toInt() - 1;
					prepareList( list, idx );
					if ( idx < 0 || idx > list[ 2 ].size() - 1 )
						continue;
					list[ 2 ][ idx ] = splitLine[1];
				}
			}

			if ( tL )
			{
				for ( int i = 0 ; i < list[ 1 ].size() ; i++ )
				{
					if ( list[ 1 ][ i ].isEmpty() )
						*tL += list[ 0 ][ i ];
					else
						*tL += list[ 1 ][ i ];
				}
			}
			else
			{
				if ( uPLeL )
				{
					playList[0] = list[ 1 ]; //tytuł
					playList[3] = list[ 2 ]; //czas
				}
				playList[2] += list[ 0 ];
			}
		}
		f.close();
		return true;
	}
	return false;
}

bool save( QString selfile, QString selfilter, const QStringList *playList )
{
	if ( selfilter == "*.m3u" && selfile.right( 4 ).toLower() != ".m3u" )
		selfile += ".m3u";
	else if ( selfilter == "*.pls" && selfile.right( 4 ).toLower() != ".pls" )
		selfile += ".pls";
	QFile f( selfile );
	if ( f.open( QFile::WriteOnly ) )
	{
		if ( selfilter == "*.m3u" )
		{
			f.write( "#EXTM3U\r\n" );
			for ( int i = 0 ; i < playList[ 2 ].size() ; i++ )
			{
				f.write( "#EXTINF:" + playList[3][i].toAscii()/*czas*/ + "," + playList[0][i].toUtf8()/*tytuł*/ + "\r\n" );
				QString pth = playList[2][i];
			#ifdef Q_WS_WIN
				if ( !pth.contains( "://" ) )
					pth.replace( '/' , '\\' );
			#endif
				f.write( pth.toUtf8() + "\r\n" );
			}
		}
		else if ( selfilter == "*.pls" )
		{
			f.write( "[playlist]\r\n" );
			f.write( "NumberOfEntries=" + QString::number( playList[2].size() ).toAscii() + "\r\n" );
			for ( int i = 0 ; i < playList[2].size() ; i++)
			{
				QString pth = playList[2][i];
			#ifdef Q_WS_WIN
				if ( !pth.contains( "://" ) )
					pth.replace( '/' , '\\' );
			#endif
				QByteArray idx = QString::number( i+1 ).toAscii();
				f.write( "File" + idx + "=" + pth.toUtf8() + "\r\n" );
				f.write( "Title" + idx + "=" + playList[0][i].toUtf8() + "\r\n" );
				f.write( "Length" + idx + "=" + playList[3][i].toAscii() + "\r\n" );
			}
		}
		f.close();
		return true;
	}
	return false;
}

bool create( QString &selfile, QString selfilter )
{
	if ( selfilter == "*.m3u" && selfile.right( 4 ).toLower() != ".m3u" )
		selfile += ".m3u";
	else if ( selfilter == "*.pls" && selfile.right( 4 ).toLower() != ".pls" )
		selfile += ".pls";
	QFile f( selfile );
	if ( f.open( QFile::WriteOnly ) )
	{
		if ( selfilter == "*.m3u" )
			f.write( "#EXTM3U\r\n" );
		else if ( selfilter == "*.pls" )
			f.write( "[playlist]\r\nNumberOfEntries=0" );
		f.close();
		return true;
	}
	return false;
}

QString getExts()
{
	QString exts( ".m3u .pls" );
	return exts;
}

void about( QWidget *w )
{
	QMessageBox::information( w, "M3U & PLS loader", "Odczyt playlist pls i m3u" );
}

#include "PlaylistPlugin.cpp"

PluginInfo pluginInfo =
{
	"M3U & PLS loader (Playlist)",
	"PlaylistPlugin",
	1529-1,
	1.0,
	about,
	NULL,
	NULL,
	NULL,
	NULL
};

PlaylistPlugin Pplug =
{
	&pluginInfo,
	setQmpLib,
	load,
	save,
	create,
	getExts
};
