#include "ui_formMod.h"
#include <QWidget>

struct FormMod: public QWidget
{
	Q_OBJECT
	public:
		FormMod(QWidget * parent = 0);
		Ui::Form2 ui;
		void Init();
		void czyscfm();
		void closeEvent(QCloseEvent*);
		void resizeEvent(QResizeEvent*);
		void bsb();
	public slots:
		void zamknij();
		void spdup();
		void bpmup();
		void slR();
		void slP();
		void shwsplins();
		void timRefDo();
};
