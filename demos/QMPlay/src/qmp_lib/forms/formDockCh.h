#include "ui_formDockCh.h"
#include <QWidget>

struct FormDock: public QWidget
{
	Q_OBJECT
	public:
		FormDock( QWidget *parent = 0 );
		Ui::_FormDock ui;
		void Init();
		void applyDock();
	public slots:
		void OK();
};
