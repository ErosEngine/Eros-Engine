#include "OpenGLViewPort.h"
#include "Engine/Util/Util.h"

#define PARENT (MainWindow_Qt *)parentWidget()


OpenGLViewPort::OpenGLViewPort(QWidget *parent) : QOpenGLWidget(parent)
{
    
}

OpenGLViewPort::~OpenGLViewPort()
{
    m_renderer->PostGameRender();
    delete m_renderer;
}

void OpenGLViewPort::initializeGL()
{
    GLenum GlResult = glewInit();
    if (GlResult != GLEW_OK)
    {
    }
    else if (GlResult == GLEW_OK)
    {
        eDebug() << "OpenGL has initialized, Current version number " << glGetString(GL_VERSION) << endl;
    }
    m_renderer = new OpenGLRenderer();
    
    m_renderer->PreGameRender();
}

void OpenGLViewPort::paintGL()
{
    glPushMatrix();
    m_renderer->DuringGameRender();
    glPopMatrix();
}

void OpenGLViewPort::resizeGL(int w, int h)
{
    
}
