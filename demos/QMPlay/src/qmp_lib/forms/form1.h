#include "ui_form1.h"
#include <QMainWindow>
#include <QSystemTrayIcon>

struct Form1: public QMainWindow
{
	Q_OBJECT
	public:
		Form1( QWidget *parent = 0 );
		Ui::MainWindow ui;
		void Init();
		void pause2();
		void opn();
		void seek(int);
		void czyscf1();
		void setVolSliders();
		void nxt();
		void next();
		void prev();
		void Tpause();
		void showProblem();
		void buildMenus();
		void setShortCutsandOthers();
		bool chkSel();
		void usunItalic();
		void ustawItalic(int);
		void showInfoForm();
		void volToolTip();
		void clrFile();
		void errNxt();
		void updatemenuItems();
		void Qsignals();
		void QVisTimer();
		void pause();
		void getFrameSize();
		void dockInF1(QWidget*,bool,void(*)());
		void MinMax();
		void musinfoClose();
		int getMusPosVal();
		bool chkSep();
	protected:
		void closeEvent(QCloseEvent*);
		void moveEvent(QMoveEvent*);
		void resizeEvent(QResizeEvent*);
		void wheelEvent(QWheelEvent*);
	public slots:
		void quit();
		void play();
		void musinfo();
		void stop();
		void slR();
		void slP();
		void opcje();
		void showplaylist();
		void timrefDo();
		void funkcje_opn();
		void info();
		void aWAV();
		void slAT(int);
		void setVol(int);
		void savMus();
		void nextB();
		void prevB();
		void AboutQMP();
		void NextXs();
		void volup();
		void voldown();
		void minimize();
		void seekP(bool);
		void setVolR(int*);
		void pwp();
		void pwl();
		void netA();
		void selA();
		void SoH();
		void mnuAct(QSystemTrayIcon::ActivationReason);
		void checkUpdatesButton();
		void checkUpdates();
		void updateQVis();
		void BTpause();
		void showEq();
		void volMnu();
		void setBothVolB();
		void TrayMessageClicked();
		void showMnuOpt();
		void miniQMP();
		void showTrayMnu();
		void setVolFromMiniQMP(int);
		void opisQMP();
		void resetInfoWindow();
		void miniVersion();
		void copyTitleA();
		void fileChanged();
	private:
		bool canChSignal;
		bool volFromMiniQMP, volSettings;
		bool cf1; //jeżeli true to przy czyscf1() czysci tytul
		int o[2], s[2];
};
