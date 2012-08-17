#pragma once
#include <QGLWidget>
#include <QSemaphore>
#include "media.h"

class VideoWidget : public QGLWidget, public VideoOutput {
    Q_OBJECT
public:
    QSize sizeHint() const;
    void start( VideoFormat& format );
    void stop();
    void write( VideoFrame* frame );
    bool display();
signals:
    void frameReady();
    void toggleFullScreen();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mouseDoubleClickEvent(QMouseEvent *);
private:
    VideoFormat format;
    QList<GLuint> frames;
};
