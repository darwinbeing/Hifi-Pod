/****************************************************************************
**

****************************************************************************/
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>


#include "MyMusicTest.h"

MyMusicTest::MyMusicTest(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("My Music Player");
     
    mStackedWidget = new QStackedWidget;
    setCentralWidget(mStackedWidget);

    mHttpWindow = new HttpWindow();
    mStackedWidget->addWidget(mHttpWindow);

    mMyPlayerView = new MyPlayerView;
    mStackedWidget->addWidget(mMyPlayerView);
        
    mStackedWidget->setCurrentIndex(0);
    
    mAboutAction = new QAction(tr("About"), this);
    mExitAction = new QAction(tr("Exit"), this);   
    mBackAction = new QAction(tr("Back"), this);   
    
    connect(mHttpWindow, SIGNAL(streamSelected(QString)), this, SLOT(playStream(QString)));
    connect(mMyPlayerView, SIGNAL(backButtonPressed()), this, SLOT(showHttpView()));
    
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(mAboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(mBackAction, SIGNAL(triggered()), this, SLOT(showHttpView()));
    
    createMenus(true);	
}
/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
MyMusicTest::~MyMusicTest()
{
    
}
/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
void MyMusicTest::createMenus(const bool httpView)
{
    QList<QAction*> actList = menuBar()->actions();
    for(int i=0; i < actList.count(); i++){     
        menuBar()->removeAction(actList.at(i));
    }
    
    if(httpView){
        menuBar()->addAction(mAboutAction);
        menuBar()->addAction(mExitAction);          
    }else{
        menuBar()->addAction(mBackAction);
    }
}
/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
void MyMusicTest::showHttpView()
{  
    mMyPlayerView->StopPlay();
    mStackedWidget->setCurrentIndex(0);
}
/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
void MyMusicTest::playStream(QString stream)
{    
    mStackedWidget->setCurrentIndex(1);
    createMenus(false);
    
    QUrl url(stream);
    
    mMyPlayerView->SetUrl(url);
    mMyPlayerView->playNow();
}

/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
void MyMusicTest::about()
{
    QMessageBox::information(this, tr("About stream example"),
        tr("This Music Player example shows how to use Phonon for streaming audio."
           "work in progress..."));
}

