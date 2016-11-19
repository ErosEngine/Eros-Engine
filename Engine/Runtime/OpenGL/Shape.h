#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Primitive.h"
#include "Texture.h"
#include "../Shaders/Shader.h"
#include "../Renderer/ShapeData.h"


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
    
    void Setup();
    void UnBind();
    void Bind();
    void Draw();
    
    GLuint &VboId();
    GLuint &EboId();
    GLuint &VaoId();
    
private:
    
    GLuint m_vboId, m_eboId, m_vaoId;
};



#endif // SHAPE_H
