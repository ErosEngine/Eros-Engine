#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "../Shaders/Shader.h"
#include "ShapeData.h"
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
    
    const Model *getMesh() const;
    void setMesh(Model *value);
    
    void setup();
    void unbind();
    void bind();
    void draw();
    
    GLuint &vboId();
    GLuint &eboId();
    GLuint &vaoId();
private:
    
    Model *m_mesh;
    GLuint m_vboId, m_eboId, m_vaoId;
};



#endif // SHAPE_H
