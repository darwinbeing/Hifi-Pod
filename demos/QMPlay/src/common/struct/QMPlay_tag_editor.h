struct Tag_editor
{
	QWidget *(*openWindow)( const char *, QWidget*, bool, bool* );
	QString (*getData)( const char*, QImage * );
	QPixmap (*Icon);
};
