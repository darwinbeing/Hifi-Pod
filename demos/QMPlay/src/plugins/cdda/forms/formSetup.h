#include "ui_formSetup.h"
#include <QWidget>

struct FormSetup: public QWidget
{
	Q_OBJECT
	public:
		FormSetup(QWidget * parent = 0);
		Ui::Form3 ui;
		void Init();
		void closeTray();
	protected:
		void hideEvent(QHideEvent*);
		void showEvent(QShowEvent*);
		void keyPressEvent(QKeyEvent*);
	public slots:
		void ApplyB();
		void addCD();
		void FsetupTimer();
		void eject();
		void closeTB();
		void setDrive();
		void CHKENABLED();
		void driveE( QString );
};
