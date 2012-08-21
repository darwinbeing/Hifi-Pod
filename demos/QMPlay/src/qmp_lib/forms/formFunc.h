#include "ui_formFunc.h"
#include <QWidget>

struct FormFunc: public QWidget
{
	Q_OBJECT
	public:
		FormFunc( QWidget *parent = 0 );
		Ui::FFunc ui;
		void Init();
		void setGeo();
	protected:
		void closeEvent(QCloseEvent*);
		void resizeEvent(QResizeEvent*);
		void showEvent(QShowEvent*);
	public slots:
		void tabCH( int );

};
