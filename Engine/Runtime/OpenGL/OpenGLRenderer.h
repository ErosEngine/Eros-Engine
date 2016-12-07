#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "ErosLib/Math.h"
#include "Engine/Runtime/OpenGL/Camera.h"
#include "Light.h"
#include "Shape.h"
#include "ShapeData.h"
#include <cassert>

struct InstancingInfo
{
    int numberTimes;
    Shape *shapePtr;
};

class OpenGLRenderer
{
    std::vector<Shape>              m_shapeQueue;
    std::vector<InstancingInfo>     m_instancingListQueue;
    std::vector<PointLight>         m_pointLights;
    std::vector<DirectionalLight>   m_directionalLights;
    std::vector<Spotlight>          m_spotLights;
    
public:
    
    Camera *camera;
    
    OpenGLRenderer()
    {
        camera = new Camera();
    }
    
    void prepareRenderer();
    void renderQueue();
    void cleanup();
    
    inline void rotateLight(float val)
    {
        m_directionalLights[0].direction.x += val;
    }
    
    void updateLights();
    
    // Clean up your pointers, however don't delete them before
    // the renderer is done with them
    void addShapeInstanceInfo(Shape *pShape, int numTimes);
    void addShapeToQueue(Shape shape);
    void addLightToQueue(PointLight light);
    void addLightToQueue(DirectionalLight light);
    void addLightToQueue(Spotlight light);
};

#endif // OPENGLRENDERER_H
