#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup( QWidget *parent = 0 );
		Ui::Form3 ui;
		void Init();
		void closeEvent(QCloseEvent*);
		void showEvent(QShowEvent*);
		void pbL();
		void pbR();
		void zvplV();
		void createPluginList();
		void setSettings();
		void getSettings();
		void getList();

		QList< Qt::CheckState > chkList;
		bool reloadPlugins;
	public slots:
		void APPLYQMP();
		void naf1();
		void lpB();
		void aboutPlug();
		void QMPButton();
		void prevButton();
		void nxtButton();
		void setStyleB();
		void zxplCC();
		void opcjePB();
		void pluglistMenu();
		void delSetsB();
		void langB();
		void toUp();
		void toDown();
		void OnOffPlug();
		void OnOffOnList();
		void proxyB();
		void pluginsChRow(int);
		void formDockChOpen();
		void restoreAddress();
		void fileStructBClicked(int);
};
