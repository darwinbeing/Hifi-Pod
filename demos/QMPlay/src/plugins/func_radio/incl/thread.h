#include <QThread>

struct listaThr : public QThread
{
	QByteArray RadioList;

	void doExit();
	private:
		void run();

		bool bolBr;
} listaThr;
