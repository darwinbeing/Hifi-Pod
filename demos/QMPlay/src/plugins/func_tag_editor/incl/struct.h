#include <tag.h>
#include <fileref.h>

#include <id3v2tag.h>
#include <mpegfile.h>
#include <flacfile.h>
#include <attachedpictureframe.h>

struct QMPlay_Tag
{
	QMPlay_Tag( const char * );

	void clear();
	void save( bool clearID3 = false );

	bool isNull, isFLAC, canWriteID3, dontUse;
	QByteArray fileName;

	TagLib::String title, artist, album, comment, genre;
	uint year, track;
	TagLib::ByteVector picture; //only picture
};

#include <struct.cpp>
