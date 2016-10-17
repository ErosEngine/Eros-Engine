#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "Primitive.h"
#include "Engine/Runtime/Shaders/Shader.h"
#include <vector>


class Shape
{
    
public:    
    
    Shape();
    
    SubShader vertShader;
    SubShader fragShader;
    
    Shader shader;
    
    Transform transform;
    
    virtual void bind() { }
    virtual void draw() { }
    
    std::vector<glm::vec3> points;
    
    GLfloat *verts;
};



#endif // SHAPE_H
