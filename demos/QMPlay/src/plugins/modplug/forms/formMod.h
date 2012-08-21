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
	public slots:
		void zamknij();
		void timRefDo();
};
