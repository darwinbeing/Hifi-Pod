int searchP(QString txt)
{
	for ( int i = txt.count()-1 ; i >= 0 ; i-- )
		if ( txt[i].toAscii() == '_' )
			return i;
		return -1;
}
bool jestCyfra(const char c)
{
	if ( c < '0' || c > '9' )
		return false;
	else
		return true;
}
void odwroc(QString &txt)
{
	QString tmp = txt;
	for ( int i = 0 ; i < tmp.count() ; i++ )
		txt[i] = tmp[ tmp.count()-1-i ];
}
QString getFileName( QString fName, QString fPth, QString ext )
{
	b:
	if ( QFile::exists( fPth + fName + ext ) )
	{
		int p = searchP( fName );
		if ( p < 0 )
		{
			fName += '_';
			p = searchP( fName );
		}
		QString liczba;
		int i;
		for ( i = fName.length()-1 ; i > p ; i-- )
		{
			if ( jestCyfra( fName[i].toAscii() ) )
				liczba += fName[i];
			else
				break;
		}
		odwroc(liczba);
		liczba = QString::number( liczba.toInt()+1 );
		fName.truncate(p+1);
		fName += liczba;
		goto b;
	}
	return fName;
}

#ifndef Q_WS_WIN
	#include <unistd.h>
#endif

inline void MYsleep( int s )
{
#ifdef Q_WS_WIN
	_sleep(s);
#else
	usleep(s*1000);
#endif
}

void convert_Signed_Unsigned_PCM( char *const audio_buffer, const int buff_size )
{
	for ( int i = 0 ; i < buff_size ; i++ )
		audio_buffer[i] ^= 0x80;
}
