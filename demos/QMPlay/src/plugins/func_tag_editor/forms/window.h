#include "ui_window.h"
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>

struct Window;
struct Id3Img;

struct Id3Img : public QLabel
{
	Window *s;
	void mousePressEvent( QMouseEvent * );
	void keyPressEvent( QKeyEvent * );
	void z166SetPixmap( QPixmap );
};

struct Window: public QWidget
{
	Q_OBJECT
	public:
		Window(bool _isMainWindow = false, QWidget *parent = NULL);
		~Window();
		Ui::Window ui;

		void clearWindow();
		void closeFile();

		struct QMPlay_Tag *tag;

		QString fName;
		Id3Img *img;
		bool isMainWindow, *isOpened, wasUpdated;
		int CURRITEMSEL;
	protected:
		void closeEvent(QCloseEvent*);
		void keyPressEvent(QKeyEvent*);
	public slots:
		void clr();
		void update();
		void imgMenu();
		void loadImg();
		void saveImg();
		void load();
		void openFile();
		void browseFile();
		void oocF();
};
