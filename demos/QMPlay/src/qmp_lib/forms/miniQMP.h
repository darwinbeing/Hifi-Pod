#include "ui_miniQMP.h"
#include <QMouseEvent>

struct miniQmp: public QFrame
{
	Q_OBJECT
	public:
		miniQmp( QWidget *parent = 0 );
		Ui::miniQMP ui;

		void Show(bool);
		void setQVisIcon();
		void setStandardIcon();
		void showSlider();
		void showSliderInF1();
#ifndef Q_OS_MAC
		int getTrayPos();
#endif
		void setPos(QPoint);
		void setW(int);

		QPoint mPE;
		QSize Size;
		QPoint pos;
		int W;
		bool standardIcon, dockVis, closed;
	protected:
		void closeEvent(QCloseEvent*);
		void hideEvent(QHideEvent*);
		void mousePressEvent(QMouseEvent*);
		void mouseMoveEvent(QMouseEvent*);
		void resizeEvent(QResizeEvent*);
	public slots:
		void plist();
};
