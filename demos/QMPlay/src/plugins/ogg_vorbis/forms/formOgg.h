#include "ui_formOgg.h"
#include <QWidget>

struct FormOgg: public QWidget
{
	Q_OBJECT
	public:
		FormOgg(QWidget * parent = 0);
		Ui::FormOGG ui;
		void Init();
		void updatef(QString,QString);
		void closeEvent(QCloseEvent*);
		void updateEdits();
	public slots:
		void zamknij();
		void timRefDo();
		void editTag();
};
