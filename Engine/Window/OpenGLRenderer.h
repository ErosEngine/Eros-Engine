#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Geometry/Primitive.h"
#include <cassert>

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
        p->draw();
    }

    void PostGameRender()
    {
        delete p;
    }
};

#endif // OPENGLRENDERER_H
