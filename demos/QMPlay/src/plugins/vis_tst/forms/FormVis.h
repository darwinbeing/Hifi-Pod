#include <QWidget>

struct MyVis : public QWidget
{
	Q_OBJECT
	public:
		MyVis(QWidget *parent = 0);
		void savWinGeometry();
	public slots:
		void popupMenu();
		void turnOff();
		void odlacz();
		void _opcje();
		void podlacz();
		void toggleFullScreen();
		void showControls();
		void hideControls();
		void cursorTimDo();
		void fKey();

		void startTimerSlot( int );
		void startTimer( int i )
		{
			emit( startTimerSignal( i ) );
		}

		void drawLine( QPainter *, float, float, float, float );
		void fillRect( QPainter *, float, float, float, float );
		void setColor( QPainter *, float, float, float );
	signals:
		void startTimerSignal( int );

	protected:
		void mouseDoubleClickEvent(QMouseEvent*);
		void closeEvent(QCloseEvent*);
		void mouseMoveEvent(QMouseEvent*);
		void keyPressEvent(QKeyEvent*);
		void paintEvent( QPaintEvent * );
		void resizeEvent( QResizeEvent * );
};
