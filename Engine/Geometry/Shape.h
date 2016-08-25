#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <vector>
#include "Coordinates.h"
#include "Texture.h"



class Shape
{
public:
    Shape();
    Shape(GLfloat *arr, int size);
   ~Shape();
    
    void draw();
    
    void setTexture(GLuint &texBuffer);
    void setTexture(Texture &texture);
    
    Vector3 getPosition();
    Vector4 getScale();

private:
    
    GLfloat *m_verts;
    GLushort *m_indices;
    GLuint m_vboId, m_vaoId, m_eboId;
    
};

#endif // SHAPE_H
