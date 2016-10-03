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



