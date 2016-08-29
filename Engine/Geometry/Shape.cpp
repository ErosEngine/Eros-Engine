#include "Shape.h"

Shape::Shape()
{
    
}

Shape::Shape(GLfloat *arr)
{
    this->m_verts = arr;
}

Shape::~Shape()
{
    delete m_verts;
}
