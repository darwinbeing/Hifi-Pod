#include "ui_formMMSlider.h"
#include <QWidget>

struct FormMMSlider: public QWidget
{
	Q_OBJECT
	public:
		FormMMSlider(QWidget * parent = 0);
		Ui::FormMS ui;
		void Init();
	protected:
		void closeEvent(QCloseEvent*);

};
