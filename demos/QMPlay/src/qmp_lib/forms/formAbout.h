#include "ui_formAbout.h"
#include <QWidget>

struct FormAbout: public QWidget
{
	Q_OBJECT
	public:
		FormAbout( QWidget *parent = 0 );
		Ui::FormA ui;
		void add(QString);
		void closeEvent(QCloseEvent*);
		void Init();
		void clrLog();
	public slots:
		void cleanB();
		void ref();
};
