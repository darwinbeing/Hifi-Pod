#include "QMPlay_tag_editor.h"

Tag_editor *tag_editor = NULL;

#include <QLibrary>

void Tag_editor_load_lib( Qmp *QLib )
{
	QString plugFName = QLib->getPlugFNameForName( "QMPlay tag editor" );
	if ( !plugFName.isEmpty() )
	{
		QLibrary libTag_editor( plugFName );
		if ( libTag_editor.load() )
			tag_editor = (Tag_editor*)libTag_editor.resolve( "tag_editor" );
	}
	else
		tag_editor = NULL;
}

QString getTagFromData( QString data, QString tag )
{
	QString Tag;
	QStringList tmp = data.split(10, QString::SkipEmptyParts);
	if ( tag == "Title" )
	{
		for ( int i = 0 ; i < tmp.size() ; i++ )
		{
			if ( tmp[i].left( 5 ) == "Title" )
			{
				Tag = tmp[i].right( tmp[i].length() - 6 );
				break;
			}
		}
	}
	else if ( tag == "Artist" )
	{
		for ( int i = 0 ; i < tmp.size() ; i++ )
		{
			if ( tmp[i].left( 6 ) == "Artist" )
			{
				Tag = tmp[i].right( tmp[i].length() - 7 );
				break;
			}
		}
	}
	return Tag;
}
