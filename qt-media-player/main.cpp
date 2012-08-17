#include "main.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setOrganizationName("Qt");
    QApplication::setApplicationName("MediaPlayer");
#ifdef USE_FTP
    FtpEngineHandler ftp;
#endif
    Player player; player.show(); return a.exec();
}

Player::Player() : dialog(0) {
    setWindowTitle("Media Player"); setWindowIcon(QIcon::fromTheme("applications-multimedia"));

/// Media
    file = new AVFile();
    connect(file, SIGNAL(finished()), this, SLOT(next()));
    connect(file, SIGNAL(positionChanged()), this, SLOT(positionChanged()));

    audio = new AlsaOutput();
    file->addAudioOutput( audio );
    connect(audio,SIGNAL(audioReady()),file,SLOT(update()));
#ifdef USE_VIDEO
    video = new VideoWidget();
    file->addVideoOutput( video );
    connect(video,SIGNAL(toggleFullScreen()),this, SLOT(toggleFullScreen()));
#endif
#ifdef USE_RUBBERBAND
    audioStretcher = new AudioStretcher();
    audioStretcher->addAudioOutput( audio );
    videoStretcher = new VideoStretcher();
    videoStretcher->addVideoOutput( video );
#endif
#ifdef USE_FFTW
    pitchEstimator = new PitchEstimator();
    file->addAudioOutput( pitchEstimator );
#endif

/// UI
    addToolBar(&toolBar);
    toolBar.setMovable(false);
    toolBar.toggleViewAction()->setVisible(false);

    openAction = toolBar.addAction(QIcon::fromTheme("document-open"),"Open");
    openAction->setCheckable(true);
    connect( openAction, SIGNAL(triggered(bool)), this, SLOT(toggleOpen(bool)));

    playAction = toolBar.addAction(QIcon::fromTheme("media-playback-start"),"Play");
    playAction->setCheckable(true);
    playAction->setShortcut(QKeySequence("Space"));
    connect( playAction, SIGNAL(triggered(bool)), this, SLOT(togglePlay(bool)));

    QAction* nextAction = toolBar.addAction(QIcon::fromTheme("media-skip-forward"),"Next",this,SLOT(next()));

#ifdef USE_HOTKEY
    connect(new Hotkey("XF86AudioPlay",this), SIGNAL(activated()),
            playAction, SLOT(trigger()));
    connect(new Hotkey("Meta+Right",this), SIGNAL(activated()),
            nextAction, SLOT(trigger()));
#endif
#ifdef USE_MARK
    markAction = toolBar.addAction(QIcon::fromTheme("bookmark-new"),"Mark");
    markAction->setCheckable(true);
    connect( markAction, SIGNAL(triggered(bool)), this, SLOT(toggleMark(bool)));
#endif
#ifdef USE_RUBBERBAND
    QAction* slow = toolBar.addAction(QIcon::fromTheme("player-time"),"Slow");
    slow->setCheckable(true);
    connect( slow, SIGNAL(triggered(bool)), this, SLOT(toggleSlow(bool)));
#endif

    toolBar.addWidget( &elapsed );
    toolBar.addWidget( &slider );
    slider.setOrientation(Qt::Horizontal);
    connect(&slider, SIGNAL(sliderPressed()), this, SLOT(stop()));
    connect(&slider, SIGNAL(sliderMoved(int)), file, SLOT(seek(int)));
    connect(&slider, SIGNAL(sliderReleased()), this, SLOT(start()));
    toolBar.addWidget( &remaining );

    playlist.setSelectionMode(QAbstractItemView::ExtendedSelection);
    playlist.setDefaultDropAction(Qt::MoveAction);
    playlist.setDragDropMode(QAbstractItemView::DragDrop);
    playlist.setDragEnabled(true);
    playlist.setHeaderHidden(true);
    playlist.setColumnCount(2);
    connect(&playlist,SIGNAL(itemActivated(QTreeWidgetItem*,int)), this,SLOT(play(QTreeWidgetItem*)) );
    restoreGeometry(QSettings().value("geometry").toByteArray());

    QStringList args = QApplication::arguments(); args.removeFirst();
    if(args.length()) foreach(QString media, args) append(media);
    else foreach(QString media, QSettings().value("playlist").toStringList()) append(media);
    QTimer::singleShot(0,this,SLOT(loadMetadata()));
    QTimer::singleShot(0,this,SLOT(next()));
}

Player::~Player() {
	QSettings().setValue("geometry", saveGeometry());
    QList<QString> urls;
    foreach(QTreeWidgetItem* item, playlist.findItems("",Qt::MatchContains))
        urls << item->toolTip(0);
    if(playlist.currentItem()) {
        int index = playlist.currentIndex().row();
        if(!playAction->isChecked()) index++;
        QSettings().setValue("playlist",QVariant(urls.mid(index)));
    }
}

void Player::toggleOpen(bool open) {
    if(open) {
#ifdef USE_KDE
        dialog = new KFileDialog(KUrl("~/Music"),
                                 "*.mp3 *.aac *.ogg *.flac *.wav *.mp4 *.avi *.mov *.mkv|Media Files",this);
        dialog->setCaption("Open"); dialog->setMode( KFile::Files | KFile::Directory );
#else
#ifdef USE_DIALOG
        dialog = new FileDialog(this,"Open",QDir::homePath()+"/Music/",
                                "Media Files (*.mp3 *.aac *.ogg *.flac *.wav *.mp4 *.avi *.mov *.mkv)");
#else
        dialog = new QFileDialog(this,"Open",QDir::homePath()+"/Music/",
                                 "Media Files (*.mp3 *.aac *.ogg *.flac *.wav *.mp4 *.avi *.mov *.mkv)");
        dialog->setFileMode( QFileDialog::ExistingFiles );
#endif
#endif
        connect(dialog,SIGNAL(accepted()),this,SLOT(open()));
        connect(dialog,SIGNAL(finished(int)),dialog,SLOT(deleteLater()));
        connect(dialog,SIGNAL(finished(int)),openAction,SLOT(toggle()));
        dialog->show();
    } else { dialog->close(); delete dialog; dialog=0; openAction->toggle(); }
}

/// append files to playlist
void Player::open() {
#ifdef USE_KDE
    foreach( KUrl url, dialog->selectedUrls() ) append( url.path() );
#else
    foreach( QString path, dialog->selectedFiles() ) { append( path ); }
#endif
    if(!dialog->selectedFiles().isEmpty()) {
        if(playlist.topLevelItemCount()>64) {
            playlist.model()->removeRows(0,playlist.currentIndex().row());
            playlist.reset();
        }
        fitWindow();
        if(!playAction->isChecked()) next();
        QTimer::singleShot(0,this,SLOT(loadMetadata()));
    }
}

void Player::append( QString path ) {
    if( QFileInfo( path ).isDir() ) {
        foreach( QString entry, QDir(path).entryList(QDir::AllEntries|QDir::NoDotAndDotDot,QDir::Name) )
            append( path+"/"+entry );
    } else if( QFileInfo( path ).isFile() ) {
        if( QString("mp3 aac ogg flac wav mp4 avi mkv").contains( QFileInfo( path ).suffix(), Qt::CaseInsensitive ) ) {
            QTreeWidgetItem* item = new QTreeWidgetItem(&playlist);
            item->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
            item->setToolTip(0,path);
            item->setText(0,QFileInfo(path).completeBaseName());
            item->setTextAlignment(1,Qt::AlignCenter);
            metadataQueue << item;
        }
    }
}

void Player::loadMetadata() {
    if(metadataQueue.isEmpty()) { fitWindow(); return; }
    QTreeWidgetItem* item = metadataQueue.takeFirst();
    QString path = item->toolTip(0);
#ifdef USE_TAGLIB
    TagLib::FileRef file(path.toAscii());
    QString title= file.tag()?QString::fromUtf8( file.tag()->title().toCString(true) ):"";
    if(file.audioProperties()) item->setText(1,QTime().addSecs( file.audioProperties()->length() ).toString("m:ss"));
#else
    AVFile file;
    file.open( path );
    QString title = file.metadata("title");
    item->setText(1,QTime().addMSecs( file.duration() ).toString("m:ss"));
    file.close();
#endif
    if(!title.isEmpty()) item->setText(0,title);
    QTimer::singleShot(0,this,SLOT(loadMetadata()));
}

void Player::fitWindow() {
    if(centralWidget()!=&playlist) return;
    playlist.resizeColumnToContents(0); playlist.resizeColumnToContents(1);
    /*resize(playlist.columnWidth(0)+playlist.columnWidth(1),
           toolBar.height()+playlist.sizeHintForRow(0)*playlist.topLevelItemCount());*/
}

#ifdef USE_VIDEO
void Player::toggleFullScreen() {
    if(video->isFullScreen()) { setCentralWidget(video); video->show(); }
    else { video->setParent(0); video->showFullScreen(); }
}
#endif

void Player::positionChanged() {
    slider.setValue( file->position() );
    elapsed.setText( QTime().addSecs( file->position()/1000 ).toString("m:ss") );
    remaining.setText( QTime().addSecs( file->duration()/1000-file->position()/1000 ).toString("m:ss") );
}

void Player::next() {
    playlist.clearSelection();
    play(playlist.topLevelItem(playlist.indexOfTopLevelItem(playlist.currentItem())+1));
}
void Player::play( QTreeWidgetItem* item ) {
    if(!item || playlist.selectedItems().count()>1) return;
    playlist.setCurrentItem(item);
    setWindowTitle(item->text(0));
    file->open( item->toolTip(0) );
    if( !file->isOpen() ) return;
#ifdef USE_VIDEO
    if( file->hasVideo() ) setCentralWidget(video); else
#endif
    setCentralWidget(&playlist);
    slider.setMaximum( file->duration() );
#ifdef USE_MARK
    mark=-1; markAction->setChecked(false);
#endif
    QTimer::singleShot(0,this,SLOT(start()));
}
void Player::start() { playAction->setChecked(true); file->start(); }
void Player::stop() { playAction->setChecked(false); file->stop(); }
void Player::togglePlay( bool play ) {
    if(play) {
#ifdef USE_MARK
        if(mark>=0) file->seek( mark );
#endif
        start();
    } else file->stop();
}

#ifdef USE_MARK
void Player::toggleMark( bool mark ) { if( !mark ) { mark=-1; } else if(file) mark=file->position(); }
#endif

#ifdef USE_RUBBERBAND
void Player::toggleSlow( bool slow ) {
    stop();
    if(slow) {
        audioStretcher->setTimeRatio(2.0); videoStretcher->setTimeRatio(2.0);
        file->clearOutputs();
        file->addAudioOutput( audioStretcher );
        file->addVideoOutput( videoStretcher );
    } else {
        file->clearOutputs();
        file->addAudioOutput( audio );
        file->addVideoOutput( video );
    }
    start();
}
#endif

#ifdef USE_FFTW
void Player::pitchChanged( double pitch ) { this->pitch.setText( QString("%1").arg(pitch) ); }
void Player::togglePitch( bool pitch ) {
    if( !pitch ) { mediaPitch=-1; inputPitch=-1; }
    else if( mediaPitch<0 ) { mediaPitch=pitchEstimator->estimatedFrequency; tuneAction->setChecked(false); }
    else { inputPitch=pitchEstimator->estimatedFrequency;
        if( inputPitch > 0 && mediaPitch > 0 ) audioStretcher->setPitchScale( inputPitch/mediaPitch );
    }
}
#endif
