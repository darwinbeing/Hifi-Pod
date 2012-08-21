#include "ui_formPlaylist.h"
#include <QWidget>

struct FormPlaylist: public QWidget
{
	Q_OBJECT
	public:
		FormPlaylist( QWidget *parent = 0 );
		Ui::Form4 ui;
		void Init();
		void closeEvent(QCloseEvent*);
		void keyPressEvent(QKeyEvent*);
		void titles();
		void dragEnterEvent(QDragEnterEvent *event);
		void dropEvent(QDropEvent *event);
		void odczytajListe(QString);
		QString plistName(QString);
		void createList();
		void zapiszListe(QString,QString,bool);
		void addToList(QStringList,int);
		void opnWlasciwosci();
		bool listPLstChk(QString);
		void updatePlistthrplus();
		void updatePlistEntry(int);
		void updatePlistEntry2(int);
		QString getEntryName(int);
		void listRef2();
		void setListLoad();
		void updateType(int);
		void titlesTime(int);
		void chkPlOnStrt();
		void getMusInfo( QString, QString, int *, QString * );
		void thrListRef2();
		void LOAD();
		void updatePlistEntryIfNeed(int);
		void setTcr(int);
		void doMimeData(const QMimeData*);
		void addThrDo( QStringList, QStringList );
		void addThrDo( QStringList );
		void showEvent(QShowEvent*);
		bool chkListIsLoading();
		void _odczytajListe(QString,QStringList*);
		void odczytajTytuly(QString,QStringList*);
		template < class T, class _NULLVALUE >
		void sortDattebayo( T, _NULLVALUE );
	public slots:
		void clrplist();
		void listRef();
		void delWpis();
		void plistthrFinished();
		void listPlaylst();
		void _listPlaylst();
		void toDown();
		void toUp();
		void titlelstMenu();
		void plistlstMenu();
		void odczytajB();
		void zapiszB();
		void pu0();
		void pu1();
		void pu2();
		void pu3();
		void pu4();
		void loadlist();
		void loadPL();
		void clrlist();
		void dellist();
		void renameList();
		void savePL();
		void newPL();
		void sel();
		void unsel();
		void wlasciwosci();
		void createLPList();
		void sizeB();
		void nextPL();
		void prevPL();
		void loadmus_File();
		void pluginOptions();
		void stopLoading();
		void chFpnf1();
		void chFpzf1();
		void _mnuPlistWindow();
		void loadmus_Dir();
		void wklej();
		void kopiuj();
		void chMusInfo();
		void chMusInfoTimer();
		void focusSearchBar();
		void searchMus();
		void focusSearchBarTim();
		void addSeparator();

		void chPlistTimeText(QString);
		void chItemText(int,QString);
		void chAddingLText(QString);
		void plistTimeText(QString s)
		{
			emit( plistTimeTextChanged(s) );
		}
		void itemText(int X,QString s)
		{
			emit( itemTextChanged(X,s) );
		}
		void addingLText(QString s)
		{
			emit( addingLTextChanged(s) );
		}

		void infoListTimerDo();
		void sortMod();
		void sortLength();
		void sortTitle();
		void sortRandom();

	signals:
		void plistTimeTextChanged(QString);
		void itemTextChanged(int,QString);
		void addingLTextChanged(QString);
};
