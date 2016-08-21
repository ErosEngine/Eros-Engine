#ifndef OPENGLVIEWPORT_H
#define OPENGLVIEWPORT_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QDebug>
#include "Engine/Renderer/OpenGLRenderer.h"


class OpenGLViewPort : public QOpenGLWidget
{
    Q_OBJECT
    
public:
    
    explicit OpenGLViewPort(QWidget *parent = 0);
    ~OpenGLViewPort();
    
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    
private:
    
    OpenGLRenderer *m_renderer;
};

#endif // OPENGLVIEWPORT_H
