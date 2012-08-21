#include "ui_formMod2.h"
#include <QWidget>

struct FormMod2: public QWidget
{
	Q_OBJECT
	public:
		FormMod2(QWidget * parent = 0);
		Ui::FormMS ui;
		void Init();
		void drawSong();
	protected:
		void closeEvent(QCloseEvent*);
};
