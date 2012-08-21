#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Form3 ui;
		void Init();
	protected:
		void hideEvent(QHideEvent*);
	public slots:
		void ApplyB();
		void addB();
		void hz_1();
		void hz_2();
		void hz_3();
		void hz_4();
		void hz_5();
		void hz_6();
		void hz_7();
		void hz_8();
		void FsetupTimer();
};
