#include "video.h"

extern"C" {
    void glGenBuffers(GLsizei n, GLuint* buffers);
    void glDeleteBuffers(GLsizei n, const GLuint* buffers);
    void glBindBuffer(GLenum, GLuint);
    void glBufferData(GLenum, GLsizeiptr, const GLvoid *, GLenum);
    GLvoid* glMapBuffer(GLenum, GLenum);
    GLboolean glUnmapBuffer (GLenum);
    GLuint glCreateProgram();
    GLuint glCreateShader(GLenum);
    void glShaderSource(GLuint, GLsizei, const GLchar* *, const GLint *);
    void glCompileShader(GLuint);
    void glAttachShader(GLuint, GLuint);
    void glLinkProgram(GLuint);
    void glUseProgram(GLuint);
    GLint glGetUniformLocation(GLuint, const GLchar *);
    void glUniform1i(GLint, GLint);
    void glXSwapIntervalSGI(int);
}

QSize VideoWidget::sizeHint() const { return QSize( format.width, format.height ); }

const char* yuv2rgb=
  "uniform sampler2DRect Ytex,Utex,Vtex;\n"
  "void main(void) {\n"
  "  float nx,ny,r,g,b,y,u,v;\n"
  "  vec4 txl,ux,vx;"
  "  nx=gl_TexCoord[0].x;\n"
  "  ny=gl_TexCoord[0].y;\n"
  "  y=texture2DRect(Ytex,vec2(nx,ny)).r;\n"
  "  u=texture2DRect(Utex,vec2(nx/2.0,ny/2.0)).r;\n"
  "  v=texture2DRect(Vtex,vec2(nx/2.0,ny/2.0)).r;\n"
  "  y=1.1643*(y-0.0625);\n"
  "  u=u-0.5;\n"
  "  v=v-0.5;\n"
  "  r=y+1.5958*v;\n"
  "  g=y-0.39173*u-0.81290*v;\n"
  "  b=y+2.017*u;\n"
  "  gl_FragColor=vec4(r,g,b,1.0);\n"
  "}\n";

void VideoWidget::initializeGL() {
    int prog = glCreateProgram();
    int frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag,1,&yuv2rgb,0);
    glCompileShader(frag);
    glAttachShader(prog,frag);
    glLinkProgram(prog);
    glUseProgram(prog);
    glUniform1i(glGetUniformLocation(prog,"Ytex"),0);
    glUniform1i(glGetUniformLocation(prog,"Utex"),1);
    glUniform1i(glGetUniformLocation(prog,"Vtex"),2);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glXSwapIntervalSGI(1);
}
void VideoWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,0,h,-1,1);
}
void VideoWidget::paintGL() {
    int w=format.width,h=format.height;
    int W,H; if( w*height() > width()*h ) { W=width(); H=W*h/w; } else { H=height(); W=H*w/h; }
    int X=(width()-W)/2, Y=(height()-H)/2;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2i(0,0); glVertex2i(X,Y+H);
    glTexCoord2i(w,0); glVertex2i(X+W,Y+H);
    glTexCoord2i(w,h); glVertex2i(X+W,Y);
    glTexCoord2i(0,h); glVertex2i(X,Y);
    glEnd();
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent *) { emit toggleFullScreen(); }

void VideoWidget::start( VideoFormat& format ) {
    this->format=format;
    setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    updateGeometry();
    glEnable(GL_TEXTURE_RECTANGLE);
    glBindTexture(GL_TEXTURE_RECTANGLE,1);
    glTexImage2D(GL_TEXTURE_RECTANGLE,0,1,format.width,format.height,0,GL_RED,GL_UNSIGNED_BYTE,0);
    glBindTexture(GL_TEXTURE_RECTANGLE,2);
    glTexImage2D(GL_TEXTURE_RECTANGLE,0,1,format.width/2,format.height/2,0,GL_RED,GL_UNSIGNED_BYTE,0);
    glBindTexture(GL_TEXTURE_RECTANGLE,3);
    glTexImage2D(GL_TEXTURE_RECTANGLE,0,1,format.width/2,format.height/2,0,GL_RED,GL_UNSIGNED_BYTE,0);
}

void VideoWidget::stop() {
    foreach(GLuint pbo,frames) glDeleteBuffers(1,&pbo);
    frames.clear();
}

void VideoWidget::write( VideoFrame* frame ) {
    int w=format.width,h=format.height;
    //makeCurrent();
    GLuint pbo; glGenBuffers(1,&pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo );
    glBufferData(GL_PIXEL_UNPACK_BUFFER,format.width*format.height*3/2,0,GL_STREAM_DRAW);
    uint8_t* dst = (uint8_t*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_WRITE_ONLY);
    uint8_t* src = frame->data[0];
    for(int y=0;y<h;y++) {
        memcpy(dst,src,w);
        dst+=w; src+=frame->linesize[0];
    }
    src=frame->data[1];
    for(int y=0;y<h/2;y++) {
        memcpy(dst,src,w/2);
        dst+=w/2; src+=frame->linesize[1];
    }
    src=frame->data[2];
    for(int y=0;y<h/2;y++) {
        memcpy(dst,src,w/2);
        dst+=w/2; src+=frame->linesize[2];
    }
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    frames << pbo;
    frame->free();
}

bool VideoWidget::display() {
    if(frames.isEmpty()) return true;
    makeCurrent();
    GLuint pbo = frames.takeFirst();
    size_t w=format.width,h=format.height;
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo );
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_RECTANGLE,1);
    glTexSubImage2D(GL_TEXTURE_RECTANGLE,0,0,0,w,h,GL_RED,GL_UNSIGNED_BYTE,0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_RECTANGLE,2);
    glTexSubImage2D(GL_TEXTURE_RECTANGLE,0,0,0,w/2,h/2,GL_RED,GL_UNSIGNED_BYTE,(void*)(w*h));
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_RECTANGLE,3);
    glTexSubImage2D(GL_TEXTURE_RECTANGLE,0,0,0,w/2,h/2,GL_RED,GL_UNSIGNED_BYTE,(void*)(w*h*5/4));
    glDeleteBuffers(1,&pbo);
    repaint();
    return frames.isEmpty();
}
