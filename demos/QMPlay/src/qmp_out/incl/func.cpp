int *Types( char *ab, int &BUF_SIZE );
char *TypesI( int *, int & );

void logAdd( QString a )
{
	QLib->addToLog(a);
}

QString plikbezsciezki( QString pth )
{
	if ( pth[ pth.length() - 1 ] == '/' )
		return pth;
	int i(0),y( pth.length() );
	bool OK(0);
	for ( i = y; i > 0; i-- )
	{
		if ( pth[i] == '/' )
		{
			OK = true;
			break;
		}
	}
	if ( OK )
		return pth.right(y-i-1);
	return pth;
}

QString chkFName( QString _fname, QString _title )
{
	QString fname;
	if ( !titleE || _title.isEmpty() ) //file name = song file name
	{
		if ( _fname.isEmpty() )
			fname = "QMP_export";
		else
		{
			fname = plikbezsciezki( _fname );
			if ( fname.isEmpty() )
				fname = _fname;
		}
	}
	else //file name = song title
		fname = _title;

	fname.truncate(200);

	fname.replace("/","_");
#ifdef Q_WS_WIN
	fname.replace("\\","_");
	fname.replace(":","_");
	fname.replace("*","_");
	fname.replace("?","_");
	fname.replace("\"","_");
	fname.replace("<","_");
	fname.replace(">","_");
	fname.replace("|","_");
#endif
	return fname;
}


int uo1( int toUo1 )
{
	if ( toUo1 < 0 )
		return toUo1 +1;
	else
		return toUo1;
}

int getDz(int bits2)
{
	if ( bits2 == 16 )
		return 256;
	else if ( bits2 == 24 )
		return 256*256;
	else if ( bits2 == 32 )
		return 256*256*256;
	else return 1;
}

void getVol( int *audio_buffer )
{
	char data[2];
	int dz = getDz(bits);

	data[0] = audio_buffer[0]/dz;
	data[1] = audio_buffer[1]/dz;

	if ( chn > 1 )
	{
		Volume[0] = abs(uo1(data[0]));
		Volume[1] = abs(uo1(data[1]));
	}
	else if ( chn == 1 )
		Volume[0] = Volume[1] = abs(uo1(data[0]));
}

void closeExportFile()
{
	setExport = false;
	if ( WAVExport )
	{
		WAVExport = false;
		wave->closePlug(true);
		logAdd( Texts[6] /** Eksportowanie wyłączone */ );
	}
}

void PlaySound( int *audio_buffer )
{
	if ( *Oplug->PlErr )
	{
// 		if ( !Oplug->errStr->isEmpty() )
// 			logAdd( "OutputPlugin Error: " + *Oplug->errStr );
// 		else
// 			logAdd( "OutputPlugin Error" );
		return;
	}
	int BUF_SIZE = FRAME_SIZE;
	char *data = TypesI( audio_buffer, BUF_SIZE );
	Oplug->play( data, BUF_SIZE, false );
	delete[] data;
}

void ExportMus( int *audio_buffer )
{
	if ( !WAVExport )
		return;
	if ( *wave->PlErr )
	{
		if ( !wave->errStr->isEmpty() )
			logAdd( Texts[1] /** Blad exportu */ + ": " + *wave->errStr );
		else
			logAdd( Texts[1] /** Blad exportu */ );
		if ( toOplug && Oplug )
			closeExportFile();
		return;
	}
	int BUF_SIZE = FRAME_SIZE;
	char *data = TypesI( audio_buffer, BUF_SIZE );
	wave->play( data, BUF_SIZE );
	delete[] data;
}

void doEqu( int **data, int &BUF_SIZE )
{
	if ( equalizer->pluginInfo->swOnOff(0) )
		equalizer->Do( data, BUF_SIZE, bits, chn, rate, realRate );
}

void doEff( int **data, int &BUF_SIZE )
{
	for (int i = 0 ; i < Eplugins.size() ; i++)
		if ( Eplugins[i]->pluginInfo->swOnOff(0) )
			Eplugins[i]->Do( data, BUF_SIZE, bits, chn, rate, realRate );
}

void doVis( int *audio_buffer )
{
	for (int i = 0 ; i < Vplugins.size() ; i++)
		if ( Vplugins[i]->pluginInfo->swOnOff(0) )
		{
			int *data = new int[FRAME_SIZE];
			memcpy( data, audio_buffer, sizeof(int)*FRAME_SIZE );
			Vplugins[i]->Do( data, FRAME_SIZE, bits, rate, chn, title, pltime, fName );
			delete[] data;
		}
}

void clearEff()
{
	Volume[0] = 0;
	Volume[1] = 0;
	for (int i = 0 ; i < Eplugins.size() ; i++)
		if ( Eplugins[i]->pluginInfo->swOnOff(0) )
			Eplugins[i]->closeEff();
}

void clearVis()
{
	for (int i = 0 ; i < Vplugins.size() ; i++)
		Vplugins[i]->clear();
}

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
int get32b( uchar a, uchar b, uchar c, uchar d )
#else
int get32b( uchar d, uchar c, uchar b, uchar a )
#endif
{
	return d * 0x1000000 + c * 0x10000 + b * 0x100 + a;
}

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
int get24b( uchar a, uchar b, uchar c )
#else
int get24b( uchar c, uchar b, uchar a )
#endif
{
	volatile int k = ( c * 0x10000 + b * 0x100 + a ) * 0x100;
	return k / 0x100;
}

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
int get16b( uchar a, uchar b )
#else
int get16b( uchar b, uchar a )
#endif
{
	return short( b * 0x100 + a );
}


#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
void put32b(int k, char &od, char &oc, char &ob, char &oa)
#else
void put32b(int k, char &oa, char &ob, char &oc, char &od)
#endif
{
	uchar d = k % 0x1000000;
	uchar c = ( (k - d) / 0x100 ) % 0x1000000;
	uchar b = ( ( k - ( c * 0x100 + d ) ) / 0x10000 ) % 0x1000000;
	uchar a = ( ( k - ( b * 0x10000 + c * 0x100 + d ) ) / 0x1000000 ) % 0x1000000;
	oa = a;
	ob = b;
	oc = c;
	od = d;
}

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
void put24b(int k, char &oc, char &ob, char &oa)
#else
void put24b(int k, char &oa, char &ob, char &oc)
#endif
{
	uchar c = k % 0x10000;
	uchar b = ( (k - c) / 0x100 ) % 0x10000;
	uchar a = ( ( k - ( b * 0x100 + c ) ) / 0x10000 ) % 0x10000;
	oa = a;
	ob = b;
	oc = c;
}

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
void put16b(int k, char &ob, char &oa)
#else
void put16b(int k, char &oa, char &ob)
#endif
{
	uchar b = k % 0x100;
	uchar a = ( (k - b) / 0x100 ) % 0x100;
	oa = a;
	ob = b;
}


int *Types( char *ab, int &BUF_SIZE )
{
	int r = 0;
	int *tmpAB;

	if ( bits == 32 )
	{
		tmpAB = new int[ BUF_SIZE/4 ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=4 )
			tmpAB[r++] = get32b( ab[i+0], ab[i+1], ab[i+2], ab[i+3] );
		BUF_SIZE /= 4;
		return tmpAB;
	}
	else if ( bits == 24 )
	{
		tmpAB = new int[ BUF_SIZE/3 ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=3 )
			tmpAB[r++] = get24b( ab[i+0], ab[i+1], ab[i+2] );
		BUF_SIZE /= 3;
		return tmpAB;
	}
	else if ( bits == 16 )
	{
		tmpAB = new int[ BUF_SIZE/2 ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=2 )
			tmpAB[r++] = get16b( ab[i+0], ab[i+1] );
		BUF_SIZE /= 2;
		return tmpAB;
	}

	/** if ( bits == 8 ) and others! */
	tmpAB = new int[ BUF_SIZE ];
	for ( int i = 0 ; i < BUF_SIZE ; i++ )
		tmpAB[i] = ab[i];
	return tmpAB;
}

char *TypesI( int *tmpAB, int &BUF_SIZE )
{
	int r = 0;

	if ( bits == 32 )
	{
		BUF_SIZE *= 4;
		char *ab = new char[ BUF_SIZE ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=4 )
			put32b( tmpAB[r++], ab[i+0], ab[i+1], ab[i+2], ab[i+3] );
		return ab;
	}
	else if ( bits == 24 )
	{
		BUF_SIZE *= 3;
		char *ab = new char[ BUF_SIZE ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=3 )
			put24b( tmpAB[r++], ab[i+0], ab[i+1], ab[i+2] );
		return ab;
	}
	else if ( bits == 16 )
	{
		BUF_SIZE *= 2;
		char *ab = new char[ BUF_SIZE ];
		for ( int i = 0 ; i < BUF_SIZE ; i+=2 )
			put16b( tmpAB[r++], ab[i+0], ab[i+1] );
		return ab;
	}

	/** if ( bits == 8 ) and other! */
	char *ab = new char[ BUF_SIZE ];
	for ( int i = 0 ; i < BUF_SIZE ; i++ )
		ab[i] = tmpAB[i];
	return ab;
}

void doVol( int *audio_buffer )
{
	for ( int i = 0 ; i < FRAME_SIZE ; i += chn )
		for ( int j = 0 ; j < chn ; j++ )
			audio_buffer[ i+j ] /= ( j % 2 ) == 0 ? LV : RV;
}

void toStereo( int *audio_buffer )
{
	int ch,ch2;

	if ( chn == 4 )
	{
		for ( int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch  = audio_buffer[i+0]/2 + audio_buffer[i+2]/2;
			ch2 = audio_buffer[i+1]/2 + audio_buffer[i+3]/2;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch2;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch2;
		}
	}

	if ( chn == 6 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch  = audio_buffer[i+0]/4 + audio_buffer[i+2]/4 + audio_buffer[i+3]/4 + audio_buffer[i+4]/4;
			ch2 = audio_buffer[i+1]/4 + audio_buffer[i+2]/4 + audio_buffer[i+3]/4 + audio_buffer[i+5]/4;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch2;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch2;
			audio_buffer[i+4] = ch;
			audio_buffer[i+5] = ch2;
		}
	}

	if ( chn == 8 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch  = audio_buffer[i+0]/5 + audio_buffer[i+2]/5 + audio_buffer[i+3]/5 + audio_buffer[i+4]/5 + audio_buffer[i+6]/5;
			ch2 = audio_buffer[i+1]/5 + audio_buffer[i+2]/5 + audio_buffer[i+3]/5 + audio_buffer[i+5]/5 + audio_buffer[i+7]/5;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch2;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch2;
			audio_buffer[i+4] = ch;
			audio_buffer[i+5] = ch2;
			audio_buffer[i+6] = ch;
			audio_buffer[i+7] = ch2;
		}
	}
}

void toMono( int *audio_buffer )
{
	int ch;

	if ( chn == 2 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch = audio_buffer[i+1]/2 + audio_buffer[i+0]/2;
			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch;
		}
	}

	if ( chn == 4 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch = audio_buffer[i+0]/4 + audio_buffer[i+1]/4 + audio_buffer[i+2]/4 + audio_buffer[i+3]/4;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch;
		}
	}

	if ( chn == 6 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch = audio_buffer[i+0]/6 + audio_buffer[i+1]/6 + audio_buffer[i+2]/6 + audio_buffer[i+3]/6 + audio_buffer[i+4]/6 + audio_buffer[i+5]/6;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch;
			audio_buffer[i+4] = ch;
			audio_buffer[i+5] = ch;
		}
	}

	if ( chn == 8 )
	{
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch = audio_buffer[i+0]/8 + audio_buffer[i+1]/8 + audio_buffer[i+2]/8 + audio_buffer[i+3]/8 + audio_buffer[i+4]/8 + audio_buffer[i+5]/8 + audio_buffer[i+6]/8 + audio_buffer[i+7]/8;

			audio_buffer[i+0] = ch;
			audio_buffer[i+1] = ch;
			audio_buffer[i+2] = ch;
			audio_buffer[i+3] = ch;
			audio_buffer[i+4] = ch;
			audio_buffer[i+5] = ch;
			audio_buffer[i+6] = ch;
			audio_buffer[i+7] = ch;
		}
	}
}

void zChn( int* audio_buffer )
{
	if ( chn >= 2 && chn % 2 == 0 )
	{
		int ch;
		for (int i = 0 ; i < FRAME_SIZE ; i+=chn)
		{
			ch = audio_buffer[i+0];
			audio_buffer[i+0] = audio_buffer[i+1];
			audio_buffer[i+1] = ch;
		}
	}
}



int *ConvertDataBits( char *_ab, int &BUF_SIZE )
{
	char *ab = new char[ BUF_SIZE ];
	memcpy( ab, _ab, BUF_SIZE );

	if ( realBits == 32 && bFloat )
	{
		for ( int i = 0 ; i < BUF_SIZE ; i+=4 )
		{
			float f = ((float*)ab)[i/4];
			if ( f >= 1.f )
				f = 0x7FFFFFFF;
			else if ( f <= -1.f )
				f = -0x7FFFFFFF;
			else
				f *= 0x7FFFFFFF;
			put32b( f, ab[i+0], ab[i+1], ab[i+2], ab[i+3] );
		}
	}

	if ( !userBits || bits == realBits )
	{
		int *audio_buffer = Types( ab, BUF_SIZE );
		delete[] ab;
		return audio_buffer;
	}

	int BUF_SIZE2 = ( BUF_SIZE / ( realBits / 8 ) ) * ( bits / 8 );
	char *audio_buffer = new char[ BUF_SIZE2 ];
	int r = 0;

	for ( int i = 0 ; i < BUF_SIZE ; i += realBits / 8 )
	{
		if ( realBits == 8 )
		{
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
			audio_buffer[r++] = ab[ i ];
#endif
			if ( bits >= 16 )
				audio_buffer[r++] = 0;
			if ( bits >= 24 )
				audio_buffer[r++] = 0;
			if ( bits >= 32 )
				audio_buffer[r++] = 0;
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
			audio_buffer[r++] = ab[ i ];
#endif
			continue;
		}
		if ( realBits == 16 )
		{
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			if ( bits == 24 )
			{
				audio_buffer[r++] = 0;
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
			if ( bits == 32 )
			{
				audio_buffer[r++] = 0;
				audio_buffer[r++] = 0;
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
#else
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i+0 ];
			if ( bits == 24 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
				audio_buffer[r++] = 0;
			}
			if ( bits == 32 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
				audio_buffer[r++] = 0;
				audio_buffer[r++] = 0;
			}
#endif
			continue;
		}
		if ( realBits == 24 )
		{
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			if ( bits == 16 )
			{
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
			if ( bits == 32 )
			{
				audio_buffer[r++] = 0;
				audio_buffer[r++] = ab[ i+(realBits/8)-3 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
#else
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i+0 ];
			if ( bits == 16 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
			}
			if ( bits == 32 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
				audio_buffer[r++] = ab[ i+2 ];
				audio_buffer[r++] = 0;
			}
#endif
			continue;
		}
		if ( realBits == 32 )
		{
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			if ( bits == 16 )
			{
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
			if ( bits == 24 )
			{
				audio_buffer[r++] = ab[ i+(realBits/8)-3 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-2 ];
				audio_buffer[r++] = ab[ i+(realBits/8)-1 ];
			}
#else
			if ( bits == 8 )
				audio_buffer[r++] = ab[ i ];
			if ( bits == 16 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
			}
			if ( bits == 24 )
			{
				audio_buffer[r++] = ab[ i+0 ];
				audio_buffer[r++] = ab[ i+1 ];
				audio_buffer[r++] = ab[ i+2 ];
			}
#endif
			continue;
		}
	}

	BUF_SIZE = BUF_SIZE2;
	delete[] ab;
	int *audio_buffer2 = Types( audio_buffer, BUF_SIZE );
	delete[] audio_buffer;
	return audio_buffer2;
}

void ConvertDataChn( int **ab, int &BUF_SIZE )
{
	if ( !userChn || chn == realChn )
	{
#ifdef Q_OS_LINUX
		if ( chn == 6 || chn == 8 )
		{
			int *audio_buffer = *ab;
			for ( int i = 0 ; i < BUF_SIZE ; i += chn )
			{
				int tmp = audio_buffer[i+2];
				audio_buffer[i+2] = audio_buffer[i+4];
				audio_buffer[i+4] = tmp;
				tmp = audio_buffer[i+3];
				audio_buffer[i+3] = audio_buffer[i+5];
				audio_buffer[i+5] = tmp;
			}
		}
#endif
		return;
	}
	int BUF_SIZE2 = ( BUF_SIZE / realChn ) * chn;

	int *audio_buffer = *ab;
	int *audio_buffer2 = new int[BUF_SIZE2];

	int r(0);
	int ch(0),ch2(0);
	for ( int i = 0 ; i < BUF_SIZE ; i += realChn )
	{
		if ( chn == 1 )
		{
			int tmp(0);
			for ( int j = i ; j < i+realChn ; j++ )
				tmp += audio_buffer[j]/realChn;
			audio_buffer2[r++] = tmp;
		}
		if ( chn == 2 )
		{
			if ( realChn == 1 )
			{
				ch = audio_buffer[i];
				ch2 = ch;
			}
			else if ( realChn == 4 )
			{
				ch  = audio_buffer[i+0]/2 + audio_buffer[i+2]/2;
				ch2 = audio_buffer[i+1]/2 + audio_buffer[i+3]/2;
			}
			else if ( realChn == 6 )
			{
				ch  = audio_buffer[i+0]/4 + audio_buffer[i+2]/4 + audio_buffer[i+3]/4 + audio_buffer[i+4]/4;
				ch2 = audio_buffer[i+1]/4 + audio_buffer[i+2]/4 + audio_buffer[i+3]/4 + audio_buffer[i+5]/4;
			}
			else if ( realChn == 8 )
			{
				ch  = audio_buffer[i+0]/5 + audio_buffer[i+2]/5 + audio_buffer[i+3]/5 + audio_buffer[i+4]/5 + audio_buffer[i+6]/5;
				ch2 = audio_buffer[i+1]/5 + audio_buffer[i+2]/5 + audio_buffer[i+3]/5 + audio_buffer[i+5]/5 + audio_buffer[i+7]/5;
			}
			else
			{
				ch = audio_buffer[i];
				ch2 = audio_buffer[i+1];
			}
			audio_buffer2[r++] = ch;
			audio_buffer2[r++] = ch2;
		}
	}

	delete[] audio_buffer;
	BUF_SIZE = BUF_SIZE2;
	*ab = audio_buffer2;
}


bool bothVolB(bool b)
{
	if (b)
	{
		fs.ui.bB->setChecked( !fs.ui.bB->isChecked() );
		fs.bBset();
	}
	return bB;
}
