#include "ui_formCp.h"
#include <QWidget>

struct FormCp: public QWidget
{
	Q_OBJECT
	public:
		FormCp( QWidget *parent = 0 );
		Ui::FormC ui;
		void Init();
		void closeEvent(QCloseEvent*);
	public slots:
		void zamknij();
		void timer();
};
