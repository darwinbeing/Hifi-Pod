#include "ui_musicInfo.h"

struct musicInfo: public QFrame
{
	Q_OBJECT
public:
	musicInfo( QWidget *parent = 0 );
	Ui::MusicInfo ui;
	int cRow;
	QString file;
};
