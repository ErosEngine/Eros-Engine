#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "Texture.h"


class Shape
{
public:
    Shape();
    Shape(GLfloat *arr);
   ~Shape();
    
    void bind();
    void draw();
    
    void setTexture(GLuint &texBuffer);
    void setTexture(Texture &texture);
    void setCoordArray(GLfloat *arr);
    
    
    glm::vec3 position;
    glm::vec3 size;
    glm::vec4 scale;
    
private:
    
    GLfloat *m_verts;
    GLushort *m_indices;
    GLuint m_vboId, m_vaoId, m_eboId, m_texId;
    
    int m_numVerts;
    
};

#endif // SHAPE_H
