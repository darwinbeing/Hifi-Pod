enum DataType
{
	NAME, FSIZE, FURL, PURL, USERNAME, LENGTH, IMAGE
};

void chkName( QString &name )
{
	name = QTextDocumentFragment::fromHtml( name ).toPlainText();
}

namespace _WrzutaReader
{
	QString getData( QString page, DataType type )
	{
		QString str1;
		QString str2;
		QString str3;
		switch ( type )
		{
			case FSIZE:
				str1 = "<span class=\"size\">";
				str3 = "</span>";
				break;
			case NAME:
				str1 = "<a class=\"title\"";
				str2 = ">";
				str3 = "</a>";
				break;
			case FURL: case PURL:
				str1 = "<a href=\"";
				str3 = "\"";
				break;
			case USERNAME:
				str1 = "<a class=\"user\"";
				str2 = ">";
				str3 = "</a>";
				break;
			case LENGTH:
				str1 = "<span class=\"duration\">";
				str3 = "</span>";
				break;
			case IMAGE:
				return "";
		};
		int pos = page.indexOf( str1 );
		if ( pos < 0 )
			return "";
		pos += str1.length();
		if ( !str2.isEmpty() )
		{
			pos = page.indexOf( str2, pos );
			if ( pos < 0 )
				return "";
			pos += str2.length();
		}
		int len = page.indexOf( str3, pos ) - pos;
		QString ret = page.mid( pos, len );
		if ( type == FURL )
		{
			ret.truncate( ret.lastIndexOf( "/" ) );
			ret.replace( "/audio/", "/xml/plik/" );
			ret += "/wrzuta.pl/pl/1";
		}
		else if ( type == NAME )
			chkName( ret );
		return ret;
	}
	QString getFileURL( QString page )
	{
		int pos = page.indexOf( "<fileId>" );
		if ( pos < 0 )
			return "";
		pos = page.indexOf( "http://", pos );
		if ( pos < 0 )
			return "";
		page.remove( 0, pos );
		pos = page.indexOf( "]" );
		if ( pos < 0 )
			return "";
		page.remove( pos, page.size() - pos );
		return page;
	}
	QStringList Split( QString page )
	{
		QStringList list = page.split( "class=\"file audio\"" );
		list[0].clear();

		QString str = "<li id=\"last\">";
		int pos = page.indexOf( str );
		if ( pos > -1 )
		{
			QString str2 = "<a href=\"";
			pos += str.length();
			pos = page.indexOf( str2, pos );
			pos += str2.length();
			int len = page.indexOf( "\"", pos ) - pos;
			QStringList lst = page.mid( pos, len ).split( '/' );
			list[0] = lst[ lst.count() - 1 ];
			lst.clear();
		}
		else if ( list.count() > 1 )
			list[0] = "1";
		return list;
	}
};
