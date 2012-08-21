#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Form3 ui;
		void Init();
		void MODquest();
		void APPLY();
	protected:
		void hideEvent(QHideEvent*);
	public slots:
		void pseplabel();
		void revlabel();
		void vollabel();
		void ApplyB();
		void dExtB();
		void FsetupTimer();
};
