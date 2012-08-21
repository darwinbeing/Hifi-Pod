uint32_t f_read(void *user_data, void *buffer, uint32_t length)
{
	return fread( buffer, 1, length, (FILE *)user_data );
}
uint32_t f_seek(void *user_data, uint64_t position)
{
	return fseek( (FILE *)user_data, position, 0 );
}

struct AACFile
{
	private:
		NeAACDecHandle hDecoder;
		FILE *file;
		URL_FILE *uFile;
		uint bufferconsumed, bread, ileBR, tmpBR;
		uchar *Data;
		uint DataSize;
		NeAACDecFrameInfo frameInfo;
		size_t aacProbe( unsigned char*, int );

		mp4ff_callback_t cb;
		mp4ff_t *mp4;
		int track, sample;

	public:
		void aacInit(bool,bool);
		void aacInit(bool);
		void aacDecode();
		void getTitle();
		void aacClose();
		void setUrl(const char*);
		bool Internet;
		char *url, *audio_buffer;
		bool loaded;
		uchar chn;
		ulong rate, samples;
		int length;
		char *title, *artist;
};

void AACFile::setUrl( const char *Url )
{
	url = new char[strlen(Url)+1];
	strcpy( url, Url );
}

size_t AACFile::aacProbe(unsigned char *buffer, int len)
{
	int i = 0;
	while ( i <= len-2 )
	{
		if ( ( buffer[i] == 0xff && ( buffer[i+1] & 0xf6 ) == 0xf0  ) )
			return i;
		i++;
	}
	return 0;
}

void AACFile::aacInit(bool b)
{
	aacInit(b,1);
}

void AACFile::aacInit(bool b, bool b2)
{
	bread = ileBR = tmpBR = bufferconsumed = 0;
	loaded = false;
	Internet = b;
	hDecoder = NeAACDecOpen();
	mp4 = NULL;
	title = NULL;
	artist = NULL;
	Data = NULL;
	length = -1;

	if ( !Internet )
	{
#ifdef Q_WS_WIN
		if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) //old Windows
			file = fopen( QString( url ).toLocal8Bit(), "rb" );
		else
			file = _wfopen( ( const wchar_t * )QString( url ).utf16(), L"rb" );
#else
		file = fopen( url, "rb" );
#endif
		if ( !file )
			return;

		memset( &cb, 0, sizeof( cb ) );
		cb.read = f_read;
		cb.seek = f_seek;
		cb.user_data = file;
		mp4 = mp4ff_open_read( &cb );
		if ( mp4 )
		{
			sample = 0;
			int tracks = mp4ff_total_tracks( mp4 );
			track = -1;
			for ( int i = 0 ; i < tracks ; i++ )
			{
				mp4ff_get_decoder_config( mp4, i, &Data, &DataSize );
				if ( DataSize )
				{
					track = i;
					if ( Data )
					{
						free( Data );
						Data = NULL;
					}
					bread = DataSize;
					break;
				}
			}
		}
		if ( track < 0 )
		{
			if ( mp4 )
			{
				mp4ff_close( mp4 );
				mp4 = NULL;
			}

			DataSize = FAAD_MIN_STREAMSIZE;
			Data = (uchar *)malloc( DataSize );

			fseek( file, 0, 0 );
			char ID3[10];
			fread( ID3, 1, 10, file );
			if ( !strncmp( ID3, "ID3", 3 ) )
				fseek( file, ID3_getTagSize( ID3 ), 0 );
			else
				fseek( file, 0, 0 );

			bread = fread( Data, 1, DataSize, file );
			int seek = aacProbe( Data, bread );
			if ( seek != ftell( file ) || seek == 0 )
			{
				fseek( file, seek, 0 );
				bread = fread( Data, 1, DataSize, file );
			}
		}

		if ( b2 && tag_editor )
		{
			id3Str = tag_editor->getData( url, NULL );
			title  = strdup( getTagFromData( id3Str, "Title" ).toUtf8() );
			artist = strdup( getTagFromData( id3Str, "Artist" ).toUtf8() );
		}
	}
	else
	{
		uFile = url_fopen( url );
		if ( !uFile )
			return;

		DataSize = FAAD_MIN_STREAMSIZE;
		Data = (uchar *)malloc( DataSize );

		if ( url_fread( Data, 1, DataSize, uFile ) != DataSize )
			return;

		artist = getICYName( (char *)Data, DataSize );

		size_t seek = aacProbe( Data, DataSize );

		memcpy( Data, Data + seek, DataSize - seek );

		if ( url_fread( Data + DataSize - seek, 1, seek, uFile ) != seek )
			return;

		bread = DataSize;
	}

	if ( !bread )
		return;

	NeAACDecInit( hDecoder, Data, bread, &rate, &chn );
	if ( !rate || !chn )
		return;
	if ( mp4 )
	{
		rate = mp4ff_get_sample_rate( mp4, track );
		chn = mp4ff_get_channel_count( mp4, track );
		getBR = QString::number( mp4ff_get_avg_bitrate( mp4, track ) / 1000 ) + "kbps";
		int64_t len = mp4ff_get_track_duration( mp4, track );
		if ( len > -1 )
			length = len / rate;
		loaded = true;
	}
	else
	{
		loaded = NeAACDecDecode( hDecoder, &frameInfo, Data, bread );
		if ( b2 )
			NeAACDecDecode( hDecoder, &frameInfo, Data, bread );
	}
}

void AACFile::aacDecode()
{
	if ( mp4 )
	{
		if ( sample >= mp4ff_num_samples( mp4, track ) )
		{
			audio_buffer = NULL;
			return;
		}
		mp4ff_read_sample( mp4, track, sample++, &Data, &DataSize );
		if ( !Data )
		{
			audio_buffer = NULL;
			return;
		}
		audio_buffer = (char*)NeAACDecDecode( hDecoder, &frameInfo, Data, DataSize );
		bufferconsumed = DataSize;
		free( Data );
		Data = NULL;
	}
	else
	{
		if ( bufferconsumed > 0 )
		{
			memcpy( Data, Data + bufferconsumed, bread - bufferconsumed );
			bread -= bufferconsumed;
			if ( !Internet )
				bread += fread( Data + bread, 1, DataSize - bread, file );
			else
				bread += url_fread( Data + bread, 1, DataSize - bread, uFile );
			bufferconsumed = 0;
		}
		audio_buffer = (char*)NeAACDecDecode( hDecoder, &frameInfo, Data, bread );
		bufferconsumed += frameInfo.bytesconsumed;
	}

	samples = frameInfo.samples << 1;

	if ( !mp4 && samples )
	{
		tmpBR += bufferconsumed;
		if ( ileBR++ >= ( rate * chn * 2 ) / samples + 1 )
		{
			getBR = QString::number( ( tmpBR / 1024 ) * 8 ) + "kbps";
			ileBR = tmpBR = 0;
		}
	}
}

void AACFile::getTitle()
{
	if ( !Internet )
		return;
	URL_FILE *uFile = url_fopen(url,"");
	if (!uFile)
		return;
	char *data = new char[8192];
	url_fread(data,1,8192,uFile);
	url_fclose(uFile);
	delete[] title;
	title = getICYTitle(data,8192);
	delete[] data;
}

void AACFile::aacClose()
{
	if ( mp4 )
		mp4ff_close( mp4 );
	if ( Data )
		free( Data );
	NeAACDecClose(hDecoder);
	delete[] url;
	delete[] artist;
	delete[] title;
	if ( Internet && uFile )
		url_fclose(uFile);
	if ( !Internet && file )
		fclose(file);
}
