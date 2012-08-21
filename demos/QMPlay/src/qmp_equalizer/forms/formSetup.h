#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Equalizer ui;
		void Init();
		void ApplyBands();
		void showOpcje();
		void closeEvent(QCloseEvent*);
		void keyPressEvent( QKeyEvent* );
	public slots:
		void swB();
		void sl0();
		void sl1();
		void sl2();
		void sl3();
		void sl4();
		void sl5();
		void sl6();
		void sl7();
		void sl8();
		void clrB();
		void upB();
		void dwnB();
		void enabledB();
		void _timEq();
		void _glW();
};
