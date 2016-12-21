#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "../Shaders/Shader.h"
#include "../Core/Mesh.h"
#include "Material.h"


class Shape
{
public:
    
    Shape();
   ~Shape();
    
    SubShader vertShader;
    SubShader fragShader;
    Shader shader;
    
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
