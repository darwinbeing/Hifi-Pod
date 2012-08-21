#ifndef SAVE_H
#define SAVE_H

struct Save
{
	void zapiszopcje();
	void odczytajopcje();
	void resetWindows();
} Save;

#include "thread.h"
#include "func.h"

#include "save.cpp"

#endif
