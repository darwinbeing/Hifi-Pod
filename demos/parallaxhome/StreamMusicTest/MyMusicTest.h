/****************************************************************************

****************************************************************************/

#ifndef MYMUSICTEST_H
#define MYMUSICTEST_H

#include <QtGui/QMainWindow>
#include <QStackedWidget>

#include <QAction>
#include <QMenuBar>

#include "MyPlayer.h"
 #include "HTTP_window.h"


class MyMusicTest : public QMainWindow
{
    Q_OBJECT

public:
	MyMusicTest(QWidget *parent = 0);
    ~MyMusicTest();
private slots:
    void about();
    void playStream(QString);   
    void showHttpView();
private:
    void createMenus(const bool httpView);
private:
    QStackedWidget* 	mStackedWidget;
    MyPlayerView*   	mMyPlayerView;
    HttpWindow*   		mHttpWindow;
    QAction*        	mAboutAction;
    QAction*        	mExitAction; 
    QAction*            mBackAction;
};

#endif // MYMUSICTEST_H
