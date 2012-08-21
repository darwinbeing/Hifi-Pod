#include "ui_formMp3.h"
#include <QWidget>

struct FormMp3: public QWidget
{
	Q_OBJECT
	public:
		FormMp3(QWidget * parent = 0);
		Ui::FormMP3 ui;
		void Init();
		void closeEvent(QCloseEvent*);
		void updateEdits();
	public slots:
		void zamknij();
		void timRefDo();
		void editId3();
};
