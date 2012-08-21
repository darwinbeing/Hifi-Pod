void write4b(long flen, int sek2)
{
	int sek = ftell(file);
	fseek(file,sek2,0);

	fwrite( &flen, 4, 1, file );

	fseek(file,sek,0);
}

int getFLen()
{
	int sek = ftell(file);
	fseek(file,0,2);
	int ret = ftell(file);
	fseek(file,sek,0);
	return ret-8;
}

int getDLen()
{
	int sek = ftell(file);
	fseek(file,0,2);
	int ret = ftell(file);
	fseek(file,sek,0);
	return ret-44;
}

#include <Functions.cpp>
