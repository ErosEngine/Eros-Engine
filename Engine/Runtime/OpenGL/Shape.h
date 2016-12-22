#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "../Shaders/OGLShader.h"
#include "../Core/Mesh.h"
#include "../Core/Material.h"


class Shape
{
public:
    
    Shape();
   ~Shape();
    
    OGLShader vertShader;
    OGLShader fragShader;
    OGLShaderProgram shader;
    
    Material material;
    Texture texture;
    Transform transform;
    
    MeshComponent mesh;
    
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
