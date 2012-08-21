#include <QThread>

struct dwnThr : public QThread
{
	URL_FILE *uF;
	char *data;
	uint bread;
	bool bolBr, abortAll;
	int pC, spd, rem, siz, dwn;

	protected:
		void run();
		void blad( QString );
} dwnThr;
