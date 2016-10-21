#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <vector>
#include <QString>
#include "../OpenGL/Texture.h"

#define ARRAY_SIZE(x) sizeof(x) / sizeof(typeof(x))


struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct ShapeData
{    
    std::vector<Vertex> vertexes;
    std::vector<GLushort> indices;
    std::vector<Texture> textures;
};

struct Mesh : public ShapeData
{
    QString directory;
};

ShapeData CreateCube();
ShapeData CreatePlane();
ShapeData CreateQuad();
ShapeData CreatePyramid();
ShapeData CreateSphere();
Mesh *LoadShapeFromFile(const char *fileName);


#endif // SHAPEDATA_H
