#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Form3 ui;
		void Init();
		void detect();
	public slots:
		void ApplyB();
		void ApplyDB();
		void detectB();
		void defDev();
};
