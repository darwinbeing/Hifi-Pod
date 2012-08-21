#include "ui_formSL.h"
#include <QWidget>

struct FormSL: public QWidget
{
	Q_OBJECT
	public:
		FormSL( QWidget *parent = 0 );
		Ui::FormSLR ui;
		void clearVis();
		void setVis(int[2]);
		void SetColor( QColor );
};
