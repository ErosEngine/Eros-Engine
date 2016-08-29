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
    Shape(GLfloat *arr);
   ~Shape();
    
    void draw();
    
    void setTexture(GLuint &texBuffer);
    void setTexture(Texture &texture);
    
    Vector3 getPosition();
    Vector3 getSize();
    Vector3 getScale();

    void setPosition(GLfloat x, GLfloat y, GLfloat z);
    void setPosition(Vector3 &position);
    void setSize(GLfloat x, GLfloat y, GLfloat z);
    void setSize(Vector3 &size);
    void setScale(GLfloat x, GLfloat y, GLfloat z);
    void setScale(Vector3 &scale);
    
private:
    
    Vector3 m_position;
    Vector3 m_size;
    Vector4 m_scale;
    
    GLfloat *m_verts;
    GLushort *m_indices;
    GLuint m_vboId, m_vaoId, m_eboId, m_texId;
    
    int m_numVerts;
    
};

#endif // SHAPE_H
