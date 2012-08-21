#include "ui_formAac.h"
#include <QWidget>

struct FormAac: public QWidget
{
	Q_OBJECT
	public:
		FormAac(QWidget * parent = 0);
		Ui::FormAAC ui;
		void Init();
		void updatef(QString,QString);
		void hideEvent(QHideEvent*);
		void closeEvent(QCloseEvent*);
		void updateEdits();
		void Close();
	public slots:
		void zamknij();
		void timRefDo();
		void editId3();
};
