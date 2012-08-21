#include "save.h"

void CDUpdate(int,int,char);
void seek(int&);
void clrSet();
void clrPos();
void CDUpdate2(int);

#include "InputPlugin.cpp"
const char *plugName("CDAudio (Input)");

CdIo_t *pcdio;

struct CDINFO
{
	CDINFO()
	{
		tracks = 0;
		lastdiscid = 0;
		discid = 0;
		track = NULL;
		year = 0;
	}
	QString artist, title, genere, from;
	int tracks;
	uint discid, lastdiscid, year;
	struct TRACK
	{
		TRACK()
		{
			isAudio = 0;
			chn = 0;
			frames = 0;
		}
		bool isAudio;
		char chn;
		uint frames;
		QString artist, title, T, from;
	};
	TRACK *track;
	struct CONTROL
	{
		void clear();
		void setDiskInfo( QString, QString, QString, uint, QString );
		void setDiskTracks( char );
		void editTrackParam( char, bool, char, uint );
		void editTrackInfo( char, QString, QString, QString );
	};
	CONTROL control;
};
CDINFO CDInfo;

void CDINFO::CONTROL::clear()
{
	CDInfo.artist.clear();
	CDInfo.title.clear();
	CDInfo.genere.clear();
	CDInfo.tracks = 0;
	delete[] CDInfo.track;
}

void CDINFO::CONTROL::setDiskTracks( char tracks )
{
	if ( tracks < 1 )
		return;
	CDInfo.control.clear();
	CDInfo.tracks = tracks;
	CDInfo.track = new CDINFO::TRACK[ tracks ];
}

void CDINFO::CONTROL::setDiskInfo( QString artist, QString title, QString genere, uint year, QString from )
{
	CDInfo.artist = artist;
	CDInfo.title = title;
	CDInfo.genere = genere;
	CDInfo.year = year;
	CDInfo.from = from;
}

void CDINFO::CONTROL::editTrackParam( char track, bool isAudio, char chn, uint frames )
{
	if ( track > CDInfo.tracks || track < 1 )
		return;
	track--;
	CDInfo.track[(int)track].isAudio = isAudio;
	CDInfo.track[(int)track].chn = chn;
	CDInfo.track[(int)track].frames = frames;
	CDInfo.track[(int)track].T = "Ścieżka: " + QString::number( track + 1 );
}

void CDINFO::CONTROL::editTrackInfo( char track, QString artist, QString title, QString from )
{
	if ( track > CDInfo.tracks || track < 1 )
		return;
	track--;
	CDInfo.track[(int)track].artist = artist;
	CDInfo.track[(int)track].title = title;
	CDInfo.track[(int)track].from = from;

	QString T;
	if ( !artist.isEmpty() )
		T += artist;
	if ( !title.isEmpty() && !artist.isEmpty() )
		T += " - "+title;
	if ( !title.isEmpty() && artist.isEmpty() )
		T += title;
	if ( !T.isEmpty() )
		CDInfo.track[(int)track].T = T;
}

QPixmap pixmap;

#include "cd_pl.cpp"

PluginInfo pluginInfo =
{
	plugName,
	"InputPlugin",
	1529-1,
	1.0,
	about,
	SwOnOff,
	NULL,
	NULL,
	&pixmap
};

bool canUpdateEntry(0);

InputPlugin Iplug =
{
	&pluginInfo,
	&formatSupport,
	opcje,
	play,
	closePlug,
	&MUSerr,
	&endSong,
	&mustReset,
	&pauseD,
	&NumPos,
	&SongPos,
	seek,
	togglePause,
	Init,
	NULL,
	&pltime,
	&plMaxtime,
	Show,
	clrPos,
	&title,
	&hOptions,
	&getBR,
	setFormInfo,
	getMenu,
	setLang,
	getQmpLib,
	showOptions,
	&canUpdateEntry,
	NULL,
	FileFormatSupport,
	getMusInfo,
	infoWindow,
	getMusStr
};
