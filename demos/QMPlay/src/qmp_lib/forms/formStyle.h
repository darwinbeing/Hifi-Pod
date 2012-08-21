#include "ui_formStyle.h"
#include <QWidget>

struct FormStyle: public QWidget
{
	Q_OBJECT
	public:
		FormStyle( QWidget *parent = 0 );
		Ui::FormS ui;
		void Init();
		void SetColor();
		void applyAll();
		void setButtonsColor();
		void getSystemPalette();
		void SetCustomPalette();
		void SetStyle(bool);
		void _applyColors(bool);
		void _ReadOnly();
		bool chkName(QString);
		void resetTray();
		void miniApply();
	protected:
		void closeEvent(QCloseEvent *);
	public slots:
		void zamknij();
		void SetStyleConn();
		void GlobalColorButtonCliked();
		void applyColors();
		void newColor();
		void deleteColor();
		void SetEnabled();
		void ChIndex(int);
		void rename();
		void LoadColorList();
		void PictureButtonCliked();
		void mainWindowSetsEnabled(int);
		void resetColorMnu();
		void resetColor();
		void quickSetColor();
};
