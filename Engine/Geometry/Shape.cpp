#include "Shape.h"
#include "Engine/Util/Util.h"

Shape::Shape()
{
    
}

Shape::Shape(GLfloat *arr)
{
    this->setCoordArray(arr);
}

Shape::~Shape()
{
    delete m_verts;
}

void Shape::bind()
{
    
}

void Shape::draw()
{
    
}

void Shape::setTexture(GLuint &texBuffer)
{
    
}

void Shape::setTexture(Texture &texture)
{
    
}

void Shape::setCoordArray(GLfloat *arr)
{
    this->m_verts = arr;
    this->m_numVerts = eros_arraySize<GLfloat>(arr);
}

/* ---- Getters and Setters ---- */

Vector3 Shape::getPosition() { return m_position;   }
Vector4 Shape::getScale()    { return m_scale;      }
Vector3 Shape::getSize()     { return m_size;       }
void Shape::setPosition(Vector3 &position)                      { this->m_position = position;        }
void Shape::setPosition(GLfloat x, GLfloat y, GLfloat z)        { this->m_position = Vector3(x, y, z);} 
void Shape::setScale(Vector4 &scale)                            { this->m_scale = scale;              }
void Shape::setScale(GLfloat x, GLfloat y, GLfloat z, GLfloat w){ this->m_scale = Vector4(x, y, z, w);}
void Shape::setSize(Vector3 &size)                              { this->m_size = size;                }
void Shape::setSize(GLfloat x, GLfloat y, GLfloat z)            { this->m_size = Vector3(x, y, z);    }

