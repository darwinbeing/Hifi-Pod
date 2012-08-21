void listaThr::run()
{
	bolBr = false;
	bool err = false;

	loadCURL();
	if ( !CURLloaded )
	{
		err = true;
		return;
	}

	char data[ 4096 ];
	size_t bread;
	int ile = MAX_ILE;

	URL_FILE *uF = url_fopen( "http://zaps166.sourceforge.net/downloads/RadioList" );
	if ( !uF )
		err = true;
	else
	{
		while( !url_feof( uF ) )
		{
			if ( bolBr )
				break;

			bread = url_fread( data, 1, 4096, uF );

			if ( !bread && !url_feof( uF ) && !--ile )
			{
				err = true;
				break;
			}
			if ( bread )
				ile = MAX_ILE;

			for ( size_t i = 0 ; i < bread ; i++ )
				RadioList += data[ i ];
		}
		url_fclose( uF );
	}

	if ( err || bolBr )
	{
		unloadCURL();
		RadioList.clear();
		return;
	}
}
void listaThr::doExit()
{
	bolBr = true;
	wait( 2000 );
	if ( isRunning() )
	{
		terminate();
		wait( 1000 );
	}
}
