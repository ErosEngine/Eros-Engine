#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/OpenGL/Primitive.h"
#include "ErosLib/Math.h"
#include "Engine/Runtime/OpenGL/Camera.h"
#include "../OpenGL/Shape.h"
#include "ShapeData.h"
#include <cassert>

struct InstancingInfo
{
    int numberTimes;
    Shape *shapePtr;
};

class OpenGLRenderer
{
    std::vector<Shape *>         m_shapeQueue;
    std::vector<InstancingInfo>  m_instancingListQueue;
    
public:
    
    Camera *camera;
    
    OpenGLRenderer()
    {
        camera = new Camera();
    }
    
    void prepareRenderer();
    void renderQueue();
    void cleanup();
    
    // Clean up your pointers, however don't delete them before
    // the renderer is done with them
    void addShapeInstanceInfo(Shape *pShape, int numTimes);
    void addShapeToQueue(Shape *pShape);
};

#endif // OPENGLRENDERER_H
