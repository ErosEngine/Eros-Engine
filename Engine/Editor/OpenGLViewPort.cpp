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
    GLenum GlResult = glewInit();
    if (GlResult != GLEW_OK)
    {
    }
    else if (GlResult == GLEW_OK)
    {
        qDebug() << "OpenGL has initialized, Current version number " << QString((const char *)glGetString(GL_VERSION)) << endl;
    }
    m_renderer = new OpenGLRenderer();
    Shape shape1;
    Shape shape2;
    Shape shape3;
    
    m_renderer->prepareRenderer();
    
    m_light.ambientColor = glm::vec3(1.0f, 1.0f, 1.0f);
    m_light.diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f);
    m_light.specularColor = glm::vec3(1.0f, 1.0f, 1.0f);
    m_light.direction = glm::vec3(3.0f, 0.0f, 0.0f);
    
    shape1.setMesh(LoadMeshFromFile("Engine/Assets/_cube_.obj"));
    shape1.material.shininess = 2.0f;
    shape1.material.diffuseTexture.loadFromFile("Engine/Assets/Suit/glass_dif.png");
    shape1.material.specularTexture.loadFromFile("Engine/Assets/Suit/arm_dif.png");
    shape1.setup();
    shape1.transform.translate(VEC3_BACK, 4.0f);
    
    shape2.setMesh(LoadMeshFromFile("Engine/Assets/Suit/nanosuit.obj"));
    shape2.texture.loadFromFile("Engine/Assets/Suit/arm_dif.png");
    shape2.setup();
    shape2.material.shininess = 200.0f;
    shape2.transform.translate(VEC3_LEFT, 4.0f);
    shape2.transform.scale(0.3f, 0.3f, 0.3f);
    
    shape3.setMesh(LoadMeshFromFile("Engine/Assets/cylinder.obj"));
    shape3.texture.loadFromFile("Engine/Assets/SpiderTex.jpg");
    shape3.setup();
    shape3.transform.translate(VEC3_BACK, 2.0f);
    shape3.transform.translate(VEC3_RIGHT, 4.0f);
    
    
    m_renderer->addShapeToQueue(shape1);
    m_renderer->addShapeToQueue(shape2);
//    m_renderer->addShapeToQueue(shape3);
    m_renderer->addLightToQueue(m_light);
    m_renderer->renderQueue();
}

void OpenGLViewPort::paintGL()
{
    m_renderer->renderQueue();
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
        case (Qt::Key::Key_T):
            m_renderer->rotateLight(1.0f);
        break;
        case (Qt::Key::Key_G):
            m_renderer->rotateLight(-1.0f);
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
