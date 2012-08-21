#include "ui_formFunc.h"
#include <QWidget>

struct Form1: public QWidget
{
	Q_OBJECT
	public:
		Form1(QWidget * parent = 0);
		Ui::Form_1 ui;
		void Init();
	public slots:
		void rec();
		void Stop();
		void pauseB();
		void sndB();
		void timerF();
		void timRefF();
	protected:
		void showEvent( QShowEvent* );
		void hideEvent( QHideEvent* );
};
