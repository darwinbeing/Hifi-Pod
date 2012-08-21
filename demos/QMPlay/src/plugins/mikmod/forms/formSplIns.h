#include "ui_formSplIns.h"
#include <QWidget>

struct FormSplIns: public QWidget
{
	Q_OBJECT
	public:
		FormSplIns(QWidget * parent = 0);
		Ui::Form5 ui;
		void Init();
		void closeEvent(QCloseEvent*);
	public slots:
		void zamknij();
};
