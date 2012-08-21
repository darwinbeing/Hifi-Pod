#include "ui_formFunc.h"
#include <QWidget>

struct FormFunc: public QWidget
{
	Q_OBJECT
	public:
		Ui::FormFunc ui;

		void Init();
		void searchAddress( bool );
		void abortAll();
		QString getMusAddr( QString );
		QString getXmlStrToReadMusAddr( QString );
		void clr1();
		void clr2();
		void breakThr();
		void setUiEnabled( bool b );
	protected:
		void resizeEvent( QResizeEvent* );
	public slots:
		void searchB();
		void nextB();
		void prevB();
		void clrB();
		void playB();
		void downloadB();
		void setPage();
		void abortB();
		void timeOut();
		void mnuTPopup();
		void mnuQPopup();
		void copyAddr();
		void delQueueEntry();
		void dwnPB();
		void copyAddr2();
		void chPage(bool);
		void queueB();
		void searchAddressAfterThr();
		void openInBrowser();

		void updateInfoL( QString );
		void infoL( QString s )
		{
			emit( infoLUpdated( s ) );
		}
	signals:
		void infoLUpdated( QString );
};
