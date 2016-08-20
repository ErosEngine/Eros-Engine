#include "OpenGLViewPort.h"

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
        std::cout << "OpenGL failed to initialize\n";
    }
    else if (GlResult == GLEW_OK)
    {
        std::cout << "OpenGL has initialized, Current version number " << glGetString(GL_VERSION) << "\n";
    }
    m_renderer = new OpenGLRenderer();
    
    m_renderer->PreGameRender();
}

void OpenGLViewPort::paintGL()
{
    glPushMatrix();
    glClearColor(0.1f, 0.5f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    m_renderer->DuringGameRender();
    
    glPopMatrix();
}

void OpenGLViewPort::resizeGL(int w, int h)
{
    
}
