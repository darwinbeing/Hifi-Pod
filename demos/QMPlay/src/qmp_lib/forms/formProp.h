#include "ui_formProp.h"
#include <QWidget>

struct FormProp: public QWidget
{
	Q_OBJECT
	public:
		FormProp( QWidget *parent = 0 );
		Ui::FormP ui;
		void Init();
		void closeEvent(QCloseEvent*);
	public slots:
		void zamknij();
		void apply();
		void applyT();
};
