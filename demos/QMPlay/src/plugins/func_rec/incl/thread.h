#ifndef __THREAD_H__
#define __THREAD_H__

#include <QThread>

struct recthr : public QThread
{
	virtual void run();
	virtual void doExit();
} recthr;

void DoExit()
{
	recthr.doExit();
}

#include "func.h"
#include "thread.cpp"

#endif
