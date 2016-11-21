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
    
    void preGameRender();
    void duringGameRender();
    void postGameRender();
    void drawShapeMulti(Shape *shape, int numTimes);
};

#endif // OPENGLRENDERER_H
