#include "ui_formFunc.h"
#include <QWidget>

struct FormFunc: public QWidget
{
	Q_OBJECT
	public:
		Ui::FormFunc ui;

		void Init();
	private:
		void showEvent( QShowEvent * );
		void keyPressEvent( QKeyEvent * );
	private slots:
		void openLink( QListWidgetItem * );
		void thrFinished();
		void createList();
};
