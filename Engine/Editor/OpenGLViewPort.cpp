#include "OpenGLViewPort.h"


#define PARENT (MainWindow_Qt *)parentWidget()


OpenGLViewPort::OpenGLViewPort(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenGLViewPort::~OpenGLViewPort()
{
    m_renderer->cleanup();
    delete m_renderer;
}

void OpenGLViewPort::initializeGL()
{
    m_renderer = new OpenGLRenderer();

	m_renderer->create((void *)this, width(), height(), 0);
    
	m_renderer->clear();
    //m_renderer->renderScene();
}

void OpenGLViewPort::paintGL()
{
    //m_renderer->renderScene();
}

void OpenGLViewPort::resizeGL(int w, int h)
{
    glViewport(w, h, width(), height());
    repaint();
}

void OpenGLViewPort::keyPressEvent(QKeyEvent *e)
{
    this->setFocus();
    switch (e->key())
    {
        case (Qt::Key::Key_W):
		break;
        case (Qt::Key::Key_A):
        break;
        case (Qt::Key::Key_S):
        break;
        case (Qt::Key::Key_D):
        break;
        case (Qt::Key::Key_E):
        break;
        case (Qt::Key::Key_Q):
        break;
    }
    
    repaint();
}

void OpenGLViewPort::mouseMoveEvent(QMouseEvent *e)
{
    setFocus();
    repaint();
}
