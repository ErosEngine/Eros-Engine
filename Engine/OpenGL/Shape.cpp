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


