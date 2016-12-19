#ifndef OPENGLVIEWPORT_H
#define OPENGLVIEWPORT_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include "Engine/Runtime/OpenGL/OpenGLRenderer.h"


class OpenGLViewPort : public QOpenGLWidget
{
    Q_OBJECT
    
public:
    
    explicit OpenGLViewPort(QWidget *parent = 0);
    ~OpenGLViewPort();
    
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    
protected:
    
    void keyPressEvent(QKeyEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    
private:
    
    OpenGLRenderer *m_renderer;
	
	Shape *m_shape1;
    Shape *m_shape2;
    Shape *m_shape3;
	
    PointLight m_light;
};

#endif // OPENGLVIEWPORT_H
