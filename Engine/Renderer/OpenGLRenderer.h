#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Geometry/Primitive.h"
#include <cassert>


// Just a skeleton renderer at the moment
struct OpenGLRenderer
{
    Primitive *p;
    OpenGLRenderer()
    {
        p = new Primitive();
    }
    
    void PreGameRender()
    {      
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glewExperimental = GL_TRUE;
        
        p->bind();
    }

    void DuringGameRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.3f, 0.1f, 0.4f, 1.0f);
        p->draw();
    }

    void PostGameRender()
    {
        delete p;
    }
};

#endif // OPENGLRENDERER_H
