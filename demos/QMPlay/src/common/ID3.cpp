int ID3_getTagSize( char *buffer )
{
	return ( (buffer[6]<<21) | (buffer[7]<<14) | (buffer[8]<<7) | buffer[9] ) + 10;
}

#include "QMPlay_tag_editor.cpp"
