#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/OpenGL/Primitive.h"
#include "Engine/OpenGL/Coordinates.h"
#include "Engine/OpenGL/Camera.h"
#include <cassert>


// Just a skeleton renderer at the moment
struct OpenGLRenderer
{
    Primitive *p;
    Camera *camera;
    Matrix4x4 perspective;
    
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
        camera->position = Vector3(1.0f, 3.0f, -1.0f);
        camera->target = Vector3(0.0f, 0.0f, 0.0f);
        camera->up = Vector3(0.0f, 1.0f, 0.0f);
        p->bind();
        perspective = Perspective(60.0f, 1.33f, 0.1f, 100.0f);
    }
    
    void DuringGameRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.3f, 0.1f, 0.4f, 1.0f);
        glMatrixMode(GL_PROJECTION);        
        p->draw();
        p->mainShader.setUniformM44("perspective", perspective);
        p->mainShader.setUniformM44("modelView", camera->getWorldToViewMatrixGLM());
    }
    
    void PostGameRender()
    {
        delete p;
        delete camera;
    }
};

#endif // OPENGLRENDERER_H
