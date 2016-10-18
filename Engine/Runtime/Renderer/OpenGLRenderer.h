#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/OpenGL/Shape/Primitive.h"
#include "Engine/Runtime/OpenGL/Coordinates.h"
#include "Engine/Runtime/OpenGL/Camera.h"
#include "ShapeData.h"
#include <cassert>


// Just a skeleton renderer at the moment
struct OpenGLRenderer
{
    int windowWidth = 1000;
    int windowHeight = 600;
    
    Primitive *p;
    Camera *camera;
    Matrix4x4 perspective;
    glm::mat4 gPerspective;
        
    OpenGLRenderer()
    {
        p = new Primitive();
        camera = new Camera();
    }
    
    void PreGameRender()
    {
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glewExperimental = GL_TRUE;
        p->setup();
        camera->updatePerspective(60.0f, 4.0f, 3.0f, 0.1f, 100.0f, 1.33f);
        perspective = Perspective(60.0f, 1.33f, 0.1f, 100.0f);
        gPerspective = camera->getPerspective();
        camera->width = (float)windowWidth;
        camera->height = (float)windowHeight;
        p->mainShader.use();
        p->mainShader.setUniformM44("perspective", gPerspective);
    }
    
    void DuringGameRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        p->draw();
        p->mainShader.setUniformM44("modelView", camera->getViewMatrix());
    }
    
    void PostGameRender()
    {
        delete p;
        delete camera;
    }
};

#endif // OPENGLRENDERER_H