#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Form3 ui;
		void Init();
		void APPLY();
		void check4err();
	public slots:
		void ApplyB();
		void playSB();
		void setVol(int);
		void bBset();
		void userRateB();
		void userBitsB();
		void userChnB();
		void _buffQB();
		void _titleHB();

		void updateBufferSize(QString,QString,int);
		void bufferSize(QString s1,QString s2,int s3)
		{
			emit ( bufferSizeUpdated( s1, s2, s3 ) );
		}
	signals:
		void bufferSizeUpdated(QString,QString,int);
};
