#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/OpenGL/Primitive.h"
#include "Engine/Runtime/OpenGL/Coordinates.h"
#include "Engine/Runtime/OpenGL/Camera.h"
#include "../OpenGL/Shape.h"
#include "ShapeData.h"
#include <cassert>


// Just a skeleton renderer at the moment
struct OpenGLRenderer
{
    int windowWidth = 1000;
    int windowHeight = 600;
    
    Primitive *p;
    Shape *shape;
    Camera *camera;
    EMatrix4x4 perspective;
    glm::mat4 gPerspective;
        
    OpenGLRenderer()
    {
        camera = new Camera();
        shape = new Shape();
    }
    
    void PreGameRender()
    {
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glewExperimental = GL_TRUE;
        shape->Setup();
        camera->UpdatePerspective(60.0f, 4.0f, 3.0f, 0.1f, 100.0f, 1.33f);
        perspective = Perspective(60.0f, 1.33f, 0.1f, 100.0f);
        gPerspective = camera->GetPerspective();
        camera->width = (float)windowWidth;
        camera->height = (float)windowHeight;
        shape->shader.Use();
        shape->shader.SetUniform("perspective", gPerspective);
        shape->shader.SetUniform("translation", Translate(0.0f, 0.0f, -7.0f));
    }
    
    void DuringGameRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        shape->Draw();
        shape->shader.SetUniform("modelView", camera->GetViewMatrix());
    }
    
    void PostGameRender()
    {
        delete shape;
        delete camera;
    }
};

#endif // OPENGLRENDERER_H
