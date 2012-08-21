#include <pulse/simple.h>

#include <Functions.cpp>

pa_simple *pulse, *pulseREC;
pa_buffer_attr attr;
pa_sample_spec ss;

typedef pa_simple *(*_qmplay_pa_simple_new)(
	const char *,
	const char *,
	pa_stream_direction_t,
	const char *,
	const char *,
	const pa_sample_spec *,
	const pa_channel_map *,
	const pa_buffer_attr *,
	int *
	);
_qmplay_pa_simple_new qmplay_pa_simple_new;

typedef void (*_qmplay_pa_simple_free)( pa_simple * );
_qmplay_pa_simple_free qmplay_pa_simple_free;

typedef int (*_qmplay_pa_simple_write)( pa_simple *, void *, size_t, int * );
_qmplay_pa_simple_write qmplay_pa_simple_write;

typedef int (*_qmplay_pa_simple_read)( pa_simple *, void *, size_t, int * );
_qmplay_pa_simple_read qmplay_pa_simple_read;

typedef int (*_qmplay_pa_simple_flush)( pa_simple *, int * );
_qmplay_pa_simple_flush qmplay_pa_simple_flush;

#include <QLibrary>
QLibrary pa_lib;

#include <libExt.h>

/**/

void opcje( QWidget *w )
{
	w->setMinimumSize( fs.minimumSize() );
	w->setMaximumSize( fs.maximumSize() );
	fs.setParent( w );
	fs.move( 0, 0 );
	fs.show();
}

void getQLib( Qmp *QLib )
{
	QMPConf = QLib->getFileName( QMP_CONF );
}

void Init( bool b, int rate2, int bits2, int chn2, int /*buff*/ )
{
	mustReset = false;
	if ( !b )
	{
		Save.odczytajopcje();
		fs.Init();
		fs.ApplyB();
	}
	PlErr = false;
	if ( b )
	{
		if ( !isOpen )
		{
			if ( !pa_lib.isLoaded() )
			{
				QString libName = "libpulse-simple" + libExt;
#ifdef Q_WS_X11
				libName += ".0";
#endif
				pa_lib.setFileName( libName );
				if ( !pa_lib.load() )
				{
					errStr = pa_lib.errorString();
					PlErr = true;
					return;
				}
				qmplay_pa_simple_new   = ( _qmplay_pa_simple_new )pa_lib.resolve( "pa_simple_new" );
				qmplay_pa_simple_free  = ( _qmplay_pa_simple_free )pa_lib.resolve( "pa_simple_free" );
				qmplay_pa_simple_write = ( _qmplay_pa_simple_write )pa_lib.resolve( "pa_simple_write" );
				qmplay_pa_simple_read  = ( _qmplay_pa_simple_read )pa_lib.resolve( "pa_simple_read" );
				qmplay_pa_simple_flush = ( _qmplay_pa_simple_flush )pa_lib.resolve( "pa_simple_flush" );
				if ( !qmplay_pa_simple_new || !qmplay_pa_simple_free || !qmplay_pa_simple_write || !qmplay_pa_simple_read || !qmplay_pa_simple_flush )
				{
					pa_lib.unload();
					errStr = "błąd podczas pobierania funkcji z biblioteki: " + libName;
					PlErr = true;
					return;
				}
			}

			switch ( bits2 )
			{
				case 8:
					ss.format = PA_SAMPLE_U8;
					break;
				case 16:
					ss.format = PA_SAMPLE_S16NE;
					break;
				case 24:
					ss.format = PA_SAMPLE_S24NE;
					break;
				case 32:
					ss.format = PA_SAMPLE_S32NE;
					break;
			}
			ss.channels = chn2;
			ss.rate = rate2;

			attr.maxlength = ( uint32_t ) -1;
			attr.tlength = delay * ( rate2 * ( bits2/8 ) * chn2 );
			attr.prebuf = ( uint32_t ) -1;
			attr.minreq = ( uint32_t ) -1;
			attr.fragsize = attr.tlength;

			pa_channel_map *chn_map = NULL;
			if ( chn2 > 2 && chn2 <= 8 )
			{
				chn_map = new pa_channel_map;
				chn_map->channels = chn2;
				chn_map->map[ 0 ] = PA_CHANNEL_POSITION_FRONT_LEFT;
				chn_map->map[ 1 ] = PA_CHANNEL_POSITION_FRONT_RIGHT;
				chn_map->map[ 2 ] = PA_CHANNEL_POSITION_FRONT_CENTER;
				chn_map->map[ 3 ] = PA_CHANNEL_POSITION_LFE;
				chn_map->map[ 4 ] = PA_CHANNEL_POSITION_REAR_LEFT;
				chn_map->map[ 5 ] = PA_CHANNEL_POSITION_REAR_RIGHT;
				chn_map->map[ 6 ] = PA_CHANNEL_POSITION_SIDE_LEFT;
				chn_map->map[ 7 ] = PA_CHANNEL_POSITION_SIDE_RIGHT;
			}
			pulse = qmplay_pa_simple_new( NULL, "QMPlay", PA_STREAM_PLAYBACK, NULL, "Output", &ss, chn_map, &attr, NULL );
			delete chn_map;

			if ( !pulse )
			{
				pa_lib.unload();
				errStr = "błąd podczas otwierania wyjścia PulseAudio";
				PlErr = true;
				return;
			}

			if ( REC )
			{
				pulseREC = qmplay_pa_simple_new( NULL, "QMPlay", PA_STREAM_RECORD, NULL, "Input", &ss, chn_map, &attr, NULL );
				if ( !pulseREC )
				{
					qmplay_pa_simple_free( pulse );
					pa_lib.unload();
					errStr = "błąd podczas otwierania wejścia PulseAudio";
					PlErr = true;
					return;
				}
			}

			isOpen = true;
		}
	}
}

void closePlug(bool b)
{
	if ( isOpen )
	{
		qmplay_pa_simple_free( pulse );
		if ( REC )
			qmplay_pa_simple_free( pulseREC );
		pa_lib.unload();
		isOpen = false;
		mustReset = false;
	}
	REC = false;
	if ( !b )
	{
		fs.setParent( NULL );
		fs.close();
	}
}

bool isRec()
{
	return REC;
}

void initRec()
{
	REC = true;
}

void play( char *audio_buffer, int buff, bool pause )
{
	if ( !isOpen )
		return;
	if ( pause )
	{
		if ( !pauseD )
		{
			qmplay_pa_simple_flush( pulse, NULL );
			pauseD = true;
		}
		return;
	}
	pauseD = false;
	if ( ss.format == PA_SAMPLE_U8 )
		convert_Signed_Unsigned_PCM( audio_buffer, buff );
	if ( qmplay_pa_simple_write( pulse, audio_buffer, buff, NULL ) < 0 )
		PlErr = true;
}
void rec( char *audio_buffer, int buff, bool pause )
{
	if ( !REC || !isOpen || pause )
		return;
	if ( qmplay_pa_simple_read( pulseREC, audio_buffer, buff, NULL ) < 0 )
		PlErr = true;
	if ( ss.format == PA_SAMPLE_U8 )
		convert_Signed_Unsigned_PCM( audio_buffer, buff );
}

void setVol( int L, int R )
{
	Left = L;
	Right = R;
}

void getVol( int *L, int *R )
{
	*L = Left;
	*R = Right;
}

void about( QWidget *w )
{
	QMessageBox::information( w, "QMPlay", "PulseAudio QMPlay OutputPlugin" );
}

bool SwOnOff( bool b )
{
	if ( !b )
		return Enabled;
	fs.ui.enabledB->setChecked( !Enabled );
	fs.ApplyB();
	return 0;
}
