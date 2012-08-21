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
	protected:
		void paintGL();
		void initializeGL();
		void resizeGL(int,int);
		void mouseDoubleClickEvent(QMouseEvent*);
		void closeEvent(QCloseEvent*);
		void keyPressEvent(QKeyEvent*);
		void mouseMoveEvent(QMouseEvent*);
};
