#ifdef Q_WS_WIN
#define Load_FileRef \
	FileRef *f; \
	if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) \
		f = new FileRef( fileName.data(), false ); \
	else \
		f = new FileRef( ( const wchar_t * )QString( fileName ).utf16(), false );
#else
#define Load_FileRef \
	FileRef *f = new FileRef( fileName.data(), false );
#endif

#ifdef Q_WS_WIN
#define Load_MPEG_File \
	MPEG::File *f; \
	if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) \
		f = new MPEG::File( fileName.data(), false ); \
	else \
		f = new MPEG::File( ( const wchar_t * )QString( fileName ).utf16(), false );
#else
#define Load_MPEG_File \
	MPEG::File *f = new MPEG::File( fileName.data(), false );
#endif

#ifdef Q_WS_WIN
#define Load_FLAC_File \
	FLAC::File *f; \
	if ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) \
		f = new FLAC::File( fileName.data(), false ); \
	else \
		f = new FLAC::File( ( const wchar_t * )QString( fileName ).utf16(), false );
#else
#define Load_FLAC_File \
	FLAC::File *f = new FLAC::File( fileName.data(), false );
#endif


QMPlay_Tag::QMPlay_Tag( const char *_fileName )
{
	using namespace TagLib;

	fileName = _fileName;
	isNull = true;
	canWriteID3 = false;
	dontUse = false;

	isFLAC = fileName.right( 5 ) == ".flac";
	if ( !isFLAC )
	{
		QByteArray r4 = fileName.right( 4 );
		if ( r4 == ".wav" )
		{
			dontUse = true;
			return;
		}
		if ( r4 == ".mp3" )
			canWriteID3 = true;
	}

	//General tags
	{
		Load_FileRef
		if ( !f->isNull() && f->tag() )
		{
			Tag *tag = f->tag();

			title = tag->title();
			artist = tag->artist();
			album = tag->album();
			comment = tag->comment();
			genre = tag->genre();
			year = tag->year();
			track = tag->track();

			isNull = false;
		}
		delete f;
	}

	//ID3v2 picture
	if ( canWriteID3 )
	{
		Load_MPEG_File
		ID3v2::Tag *id3v2 = f->ID3v2Tag();
		if ( id3v2 && !id3v2->isEmpty() )
		{
			ID3v2::FrameList pict = id3v2->frameList( "APIC" );
			if ( !pict.isEmpty() )
			{
				picture = ID3v2::AttachedPictureFrame( pict.front()->render() ).picture();
				isNull = false;
			}
		}
		delete f;
	}

	//FLAC picture
	if ( isFLAC )
	{
		Load_FLAC_File
		if ( f->pictureList().size() )
		{
			FLAC::Picture *p = f->pictureList().front();
			if ( p )
			{
				picture = p->data();
				isNull = false;
			}
		}
		delete f;
	}
}

void QMPlay_Tag::clear()
{
	title = "";
	artist = "";
	album = "";
	comment = "";
	genre = "";
	year = track = 0;
	picture.clear();

	save( true );
}

void QMPlay_Tag::save( bool clearID3 )
{
	if ( dontUse )
		return;

	using namespace TagLib;

	//ID3v2
	{
		Load_MPEG_File
		if ( !canWriteID3 || clearID3 )
			f->save( MPEG::File::NoTags );
		else
		{
			ID3v2::Tag *id3v2 = f->ID3v2Tag();
			if ( id3v2 )
			{
				ID3v2::FrameList pict = id3v2->frameList( "APIC" );
				while ( pict.size() )
					id3v2->removeFrame( pict[ 0 ] );
				if ( !picture.isEmpty() )
				{
					ID3v2::AttachedPictureFrame *pictFrame = new ID3v2::AttachedPictureFrame;
					pictFrame->setPicture( picture );
					QString mimeType = "image/" + QImageReader( QDataStream( QByteArray( picture.data(), picture.size() ) ).device() ).format();
					pictFrame->setMimeType( mimeType.toAscii().data() );
					id3v2->addFrame( pictFrame );
				}
				f->save();
			}
		}
		delete f;
	}

	if ( isFLAC )
	{
		Load_FLAC_File
		if ( f->pictureList().size() )
			f->removePictures();
		if ( !picture.isEmpty() )
		{
			FLAC::Picture *pict = new FLAC::Picture;
			pict->setData( picture );
			QString mimeType = "image/" + QImageReader( QDataStream( QByteArray( picture.data(), picture.size() ) ).device() ).format();
			pict->setMimeType( mimeType.toAscii().data() );
			f->addPicture( pict );
		}
		f->save();
		delete f;
	}

	//General tag
	{
		Load_FileRef
		if ( !f->isNull() && f->tag() )
		{
			Tag *tag = f->tag();

			tag->setTitle( title );
			tag->setArtist( artist );
			tag->setAlbum( album );
			tag->setComment( comment );
			tag->setGenre( genre );
			tag->setYear( year );
			tag->setTrack( track );

			f->save();
		}
		delete f;
	}
}
