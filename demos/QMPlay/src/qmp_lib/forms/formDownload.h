#include "ui_formDownload.h"
#include <QTimer>
#include <QWidget>

struct FormDownload: public QWidget
{
	Q_OBJECT
	public:
		FormDownload( QWidget *parent = 0 );
		Ui::Form_Download ui;
		void Init(QWidget*);
		void doFinish(QString);

		QString fname;
	public slots:
		void zamknij();
		void timDwnDo();
		void install();
	private:
		QTimer timDwn;
};
