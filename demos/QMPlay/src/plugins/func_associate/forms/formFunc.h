#include "ui_formFunc.h"
#include <QDialog>

struct Form1: public QDialog
{
	Q_OBJECT
	public:
		Form1(QWidget * parent = 0):QDialog(parent){};
		Ui::Form_1 ui;
		void Init();
		void associate();
		void quest();
		void addToList(QString);
	public slots:
		void selAll();
		void revSel();
		void add();
		void del();
		void clr();
		void apply();
		void getExts();
		void chkExts();
};
