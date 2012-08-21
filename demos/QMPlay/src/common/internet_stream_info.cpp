char *getICYName( char *data, int size )
{
	if ( !data )
		return NULL;
	QByteArray Data;
	Data.append( data, size );
	int idx = Data.indexOf( "icy-name:" );
	if ( idx < 0 )
		return NULL;
	idx += 9;
	int to = Data.indexOf( '\n', idx ) - idx;
	if ( Data[ to+idx-1 ] == '\r' )
		to--;
	return strdup( Data.mid( idx, to ) );
}

char *getICYTitle( char *data, int size )
{
	if ( !data )
		return NULL;
	QByteArray Data;
	Data.append( data, size );
	int idx = Data.indexOf( "Current Song:" );
	if ( idx < 0 )
		return NULL;
	int idx2 = Data.indexOf( "<b>", idx );
	if ( idx2 < 0 )
		return NULL;
	idx2 += 3;
	int len = Data.indexOf( "</b>", idx2 ) - idx2;
	return strdup( Data.mid( idx2, len ) );
}
