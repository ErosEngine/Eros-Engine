#include "OpenGLViewPort.h"


#define PARENT (MainWindow_Qt *)parentWidget()


OpenGLViewPort::OpenGLViewPort(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenGLViewPort::~OpenGLViewPort()
{
	delete m_shape1;
	delete m_shape2;
	delete m_shape3;
	
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
        qDebug() << "OpenGL has initialized, Current version number " 
				 << QString((const char *)glGetString(GL_VERSION)) << endl;
    }
    m_renderer = new OpenGLRenderer();

    m_shape1 = new Shape();
	m_shape2 = new Shape();
	m_shape3 = new Shape();
	
    m_renderer->prepareRenderer();
    
	m_light.direction = glm::vec3(1.0f, 0.0f, 0.0f);
	m_light.ambientColor = glm::vec3(1.0f, 1.0f, 1.0f);
	m_light.diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f);
	m_light.specularColor = glm::vec3(1.0f, 1.0f, 1.0f);
    
	m_shape1->mesh.loadFromFile("Engine/Assets/_cube_.obj");
    m_shape1->material.shininess = 2.0f;
    m_shape1->material.diffuseTexture.loadFromFile("Engine/Assets/Suit/glass_dif.png");
    m_shape1->material.specularTexture.loadFromFile("Engine/Assets/Suit/arm_dif.png");
    m_shape1->setup();
    m_shape1->transform.translate(VEC3_BACK, 4.0f);
    
    m_shape2->mesh.loadFromFile("Engine/Assets/Suit/nanosuit.obj");
    m_shape2->material.diffuseTexture.loadFromFile("Engine/Assets/Suit/arm_dif.png");
    m_shape2->setup();
    m_shape2->material.shininess = 20.0f;
    m_shape2->transform.translate(VEC3_LEFT, 4.0f);
    m_shape2->transform.scale(0.3f, 0.3f, 0.3f);
    
	m_shape3->mesh.loadFromFile("Engine/Assets/cylinder.obj");
    m_shape3->material.diffuseTexture.loadFromFile("Engine/Assets/SpiderTex.jpg");
    m_shape3->setup();
    m_shape3->transform.translate(VEC3_BACK, 2.0f);
    m_shape3->transform.translate(VEC3_RIGHT, 4.0f);
    
    m_renderer->addShapeToQueue(m_shape1);
    m_renderer->addShapeToQueue(m_shape2);
//	m_renderer->addShapeToQueue(m_shape3);
//	m_renderer->addShapeInstanceInfo(&shape1, 1);
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
    }
    
    repaint();
}

void OpenGLViewPort::mouseMoveEvent(QMouseEvent *e)
{
    setFocus();
    m_renderer->camera->mouseUpdate(e->x(), e->y());
    repaint();
}
