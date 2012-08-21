#include "ui_formInfo.h"
#include <QWidget>

struct FormInfo: public QWidget
{
	Q_OBJECT
	public:
		FormInfo(QWidget * parent = 0);
		Ui::FormINFO ui;
		void Init();
		void clr();
		void clr2();
		void closeEvent(QCloseEvent*);
		QString fTitle, fArtist, fCD, trackFrom;
		char fTrack, fChn;
		bool openFromMusInfo;
	public slots:
		void zamknij();
		void timRefDo();
};
