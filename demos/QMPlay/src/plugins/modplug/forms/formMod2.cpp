void FormMod2::Init()
{
	ui.patW->clear();
}
/**code from umodplyer*/
const char *Notes[12] = {"C-", "C#", "D-", "D#", "E-", "F-", "F#", "G-", "G#", "A-", "A#", "B-"};

#define PUTSTR(strd,echar) strd[0]=strd[1]=strd[2]=(echar)
void NoteGetName(int note, char *string)
{
	int realnote, octave;

	if (note == 0)
		PUTSTR(string, '.');	/* no note  (...)  */
	else if (note == 254)
		PUTSTR(string, '^');	/* note cut (^^^)  */
	else if (note == 255)
		PUTSTR(string, '=');	/* note off (===)  */
	else if (note == 253)
		PUTSTR(string, '~');	/* note fade(~~~)  */
	else {			/* normal note */
		realnote = note - 1;
		octave = realnote / 12;
		realnote %= 12;

		strcpy(string, Notes[realnote]);	/* put note name */
		sprintf(&string[2], "%1d", octave);	/* put octave    */

	}
	string[3] = '\0';	/* finish string */
}
#undef PUTSTR
char noteName[8];
/**end of code from umodplyer*/


QStringList _PATTERN;

void FormMod2::drawSong()
{
	QString ROW,TMP;

	if (!mpn)
		return;

	if ( oldPat != pat )
	{
		ui.patW->clear();
		ui.patW->addItem( "-> Pattern: "+QString::number(pat+1)+" ("+QString::number(_pat+1)+") <-" );
		ui.patW->addItem( "" );

		ROW = "";
		_PATTERN.clear();
		int tmp(0),tmp2(0);
		for ( uint i = 0 ; i < rowCount*numchn ; i++ )
		{
			NoteGetName( (int)mpn[i].Note, noteName );
			ROW += noteName;
			ROW += "	";
			tmp++;
			if ( tmp == numchn )
			{
				tmp2++;
				TMP = "";
				if ( !plSpec )
					TMP = QString::number(tmp2)+".	";
				TMP += ROW;
				_PATTERN += TMP;
				ROW = "";
				tmp = 0;
			}
		}
		ui.patW->addItems( _PATTERN );
	}

	if ( oldRow != row )
		if ( !_PATTERN.isEmpty() )
			ui.patW->setCurrentRow(row);
}

void FormMod2::closeEvent(QCloseEvent*)
{
	setParent(NULL);
}
