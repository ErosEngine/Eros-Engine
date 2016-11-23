#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Primitive.h"
#include "Texture.h"
#include "../Shaders/Shader.h"
#include "ShapeData.h"


class Shape
{
public:
    
    Shape();
   ~Shape();
    
    SubShader vertShader;
    SubShader fragShader;
    Shader shader;
    
    Texture texture;
    Transform transform;
    Model *mesh;
    
    void setup();
    void unbind();
    void bind();
    void draw();
    
    GLuint &vboId();
    GLuint &eboId();
    GLuint &vaoId();
    
private:
    
    GLuint m_vboId, m_eboId, m_vaoId;
};



#endif // SHAPE_H
