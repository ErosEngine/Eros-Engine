#include "OpenGLViewPort.h"
#include "Engine/Window/Util.h"


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
        debugLog("OpenGL failed to initialize");
    }
    else if (GlResult == GLEW_OK)
    {
        qDebug() << "OpenGL has initialized, Current version number " << glGetString(GL_VERSION);
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
