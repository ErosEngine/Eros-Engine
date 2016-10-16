#include "Shape.h"


Shape::Shape(): p_pointsAreConverted(false)
{
}

void Shape::convertPointsToGLFloatPointer()
{
    if (!p_pointsAreConverted)
    {
        if (!verts)
        {
            verts = new GLfloat[points.size() * 3];
        }
        
        for (int i = 0; i < points.size() * 3; i += 3)
        {
            verts[i - 3] = points[i / 3].x;
            verts[i - 2] = points[i / 3].y;
            verts[i - 1] = points[i / 3].z;
        }
        
        p_pointsAreConverted = true;        
    }
}
