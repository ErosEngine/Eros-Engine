#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>

#define ARRAY_SIZE(x) sizeof(x) / sizeof(typeof(x))


typedef unsigned int uint;

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
};


struct ShapeData
{
    GLfloat *verticies;
    GLushort *indices;
    uint numIndices;
    GLuint buffer;
};


#endif // SHAPEDATA_H
