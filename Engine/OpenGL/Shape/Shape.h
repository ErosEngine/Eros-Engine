#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "Engine/Shaders/Shader.h"

class Shape
{
public:    
    
    Shape();
    
    SubShader vertShader;
    SubShader fragShader;
    
    Shader shader;
    
    Transform *transform();
    
    void bind();
    void sendToOpenGL();
    void draw();    
    
private:
    
    Transform m_transform;
};

#endif // SHAPE_H
