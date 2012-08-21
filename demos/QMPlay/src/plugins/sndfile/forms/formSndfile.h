#include "ui_formSndfile.h"
#include <QWidget>

struct FormSndfile: public QWidget
{
	Q_OBJECT
	public:
		FormSndfile(QWidget * parent = 0);
		Ui::FormSNDFILE ui;
		void Init();
		void updatef(QString,QString);
		void closeEvent(QCloseEvent*);
		void updateEdits();
	public slots:
		void zamknij();
		void timRefDo();
		void editTag();
};
