#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup( QWidget *parent = 0 );
		Ui::Form3 ui;
		void Init();
		void loadList();
	public slots:
		void ApplyB();
};
