#include "OpenGLViewPort.h"

#define PARENT (MainWindow_Qt *)parentWidget()


OpenGLViewPort::OpenGLViewPort(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenGLViewPort::~OpenGLViewPort()
{
    m_renderer->cleanup();
    
    if (shape1)
    {
        qDebug() << "Shape1 wasn't deleted";
        delete shape1;
    }
    if (shape2)
    {
        qDebug() << "Shape2 wasn't deleted";
        delete shape2;
    }
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
    shape1 = new Shape();
    shape2 = new Shape();
    
    m_renderer->prepareRenderer();
    glm::mat4 perspective = m_renderer->camera->getPerspective();
    
    shape1->setMesh(LoadMeshFromFile("Engine/Assets/_cube.obj"));
    shape1->texture.loadFromFile("Engine/Assets/Suit/glass_dif.png");
    shape1->setup();
    shape1->bind();
    shape1->shader.use();
    shape1->transform.translate(VEC3_BACK, 4.0f);
    shape1->shader.setUniform("perspective", perspective);
    shape1->shader.setUniform("lightPos", glm::vec3(0, 1, -2));
    shape1->shader.setUniform("objectColor", glm::vec3(0.5, 0.7, 1.0f));
    shape1->shader.setUniform("ambientStrength", 0.5f);
    shape1->shader.setUniform("lightColor", glm::vec3(0.8f, 0.8f, 0.8f));
    shape1->shader.setUniform("specularStrength", 0.7f);
    shape1->unbind();
    glUseProgram(0);
    
    // Very Bad and I do plan to change this
    shape2->setMesh(LoadMeshFromFile("Engine/Assets/Suit/nanosuit.obj"));
    shape2->texture.loadFromFile("Engine/Assets/Suit/arm_dif.png");
    shape2->setup();
    shape2->bind();
    shape2->shader.use();
    shape2->transform.translate(VEC3_LEFT, 4.0f);
    shape2->shader.setUniform("perspective", perspective);
    shape2->shader.setUniform("perspective", perspective);
    shape2->shader.setUniform("lightPos", glm::vec3(0, 1, -2));
    shape2->shader.setUniform("objectColor", glm::vec3(0.5, 0.7, 1.0f));
    shape2->shader.setUniform("ambientStrength", 0.5f);
    shape2->shader.setUniform("lightColor", glm::vec3(0.8f, 0.8f, 0.8f));
    shape2->shader.setUniform("specularStrength", 0.7f);
    shape2->unbind();
    glUseProgram(0);
    
    m_renderer->addShapeToQueue(shape1);
    m_renderer->addShapeToQueue(shape2);
    m_renderer->renderQueue();
}

void OpenGLViewPort::paintGL()
{
    m_renderer->renderQueue();
}

void OpenGLViewPort::resizeGL(int w, int h)
{
    glViewport(w, h, 1.0f, 1.0f);
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
