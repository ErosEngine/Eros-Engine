#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <GL/glew.h>
#include "Engine/Runtime/Shaders/Shader.h"


class Primitive
{
public:
    Primitive();
    
    void bind();
    void draw();
    
    SubShader vertShader = loadShaderFromFile("Engine/Runtime/Shaders/baseVert.vert", EROS_VERTEX_SHADER);
    SubShader fragShader = loadShaderFromFile("Engine/Runtime/Shaders/baseFrag.frag", EROS_FRAG_SHADER);
    Shader mainShader; 
    
    glm::vec3 position;
    
private:
    
    GLfloat m_verts[12] = {
        -0.1f, -0.1f, 0.0f, // Bottom left
         0.1f, -0.1f, 0.0f, // bottom right
         0.1f,  0.1f, 0.0f, // top right
        -0.1f,  0.1f, 0.0f  // top left
    };
    
    GLushort m_indices[6] = {
        0, 1, 2, // Bottom left, bottom right, top right
        3, 2, 0  // top left, top right, bottom left
    };
    
    GLuint m_vboId, m_eboId, m_vaoId;
    float m_time;    
};

#endif // PRIMITIVE_H
