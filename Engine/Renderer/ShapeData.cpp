#include "ShapeData.h"


void ShapeData::convertVertsToVertex()
{
}

void ShapeData::convertVertexToVerts()
{
}


ShapeData CreateCube(glm::vec3 pos, glm::vec3 size, bool useTexture)
{
    ShapeData shape;
    //shape.vertexes = new Vertex[8];
    
    return shape;
}

ShapeData CreatePlane(glm::vec3 pos, unsigned int numFaces, int scale, bool useTexture)
{
    return ShapeData();
}

ShapeData CreateQuad(glm::vec3 pos, glm::vec3 size, bool useTexture)
{
    return ShapeData();
}

ShapeData CreatePyramid(glm::vec3 pos, glm::vec3 size, bool useTexture)
{
    return ShapeData();
}

ShapeData CreateSphere(glm::vec3 pos, glm::vec3 size, bool useTexture)
{
    return ShapeData();
}
