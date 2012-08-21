#include <QtOpenGL>
#include <QGLWidget>

struct MyVis : public QGLWidget
{
	Q_OBJECT
	public:
		MyVis(QWidget *parent = 0);
		~MyVis();
		void savWinGeometry();
	public slots:
		void popupMenu();
		void turnOff();
		void closeWin();
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
	signals:
		void startTimerSignal( int );

	protected:
		void paintGL();
		void initializeGL();
		void resizeGL(int,int);
		void mouseDoubleClickEvent(QMouseEvent*);
		void closeEvent(QCloseEvent*);
		void mouseMoveEvent(QMouseEvent*);
		void keyPressEvent(QKeyEvent*);
};
