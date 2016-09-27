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
        qDebug() << "OpenGL has initialized, Current version number " << QString((const char *)glGetString(GL_VERSION)) << endl;
    }
    m_renderer = new OpenGLRenderer();
    
    m_renderer->PreGameRender();
    m_renderer->DuringGameRender();
}

void OpenGLViewPort::paintGL()
{
    glPushMatrix();
    m_renderer->DuringGameRender();
    glPopMatrix();
}

void OpenGLViewPort::resizeGL(int w, int h)
{
    repaint();
}

void OpenGLViewPort::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case (Qt::Key::Key_W):
            m_renderer->camera->moveForward();
        break;
        case (Qt::Key::Key_A):
            m_renderer->camera->strafeLeft();
        break;
        case (Qt::Key::Key_S):
            m_renderer->camera->moveBack();
        break;
        case (Qt::Key::Key_D):
            m_renderer->camera->strafeRight();
        break;
        case (Qt::Key::Key_E):
            m_renderer->camera->moveUp();
        break;
        case (Qt::Key::Key_Q):
            m_renderer->camera->moveDownward();
        break;
    }
    repaint();
}

void OpenGLViewPort::mouseMoveEvent(QMouseEvent *e)
{
    setFocus();
    m_renderer->camera->mouseUpdate(e->x(), e->y());
    repaint();
}
