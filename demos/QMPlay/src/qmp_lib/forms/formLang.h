#include "ui_formLang.h"
#include <QWidget>

struct FormLang: public QWidget
{
	Q_OBJECT
	public:
		FormLang( QWidget * parent = 0 );
		Ui::FormL ui;

		void Init();
		void setLang();
		void setLangLibs();

		int firstIdx;
	public slots:
		void zamknij();
};
