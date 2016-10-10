#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>

#define ARRAY_SIZE(x) sizeof(x) / sizeof(typeof(x))

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
};


struct ShapeData
{
private:
    typedef unsigned int uint;
    
public:
    
    // Convert vertexes to vertices
    // and if needed vertices to vertexes
    void convertVertsToVertex();
    void convertVertexToVerts();
    
    Vertex *vertexes;
    GLfloat *vertices;
    GLushort *indices;
    GLushort *texCoords;
    uint numIndices;
    GLuint buffer;
};

ShapeData CreateCube(glm::vec3 pos, glm::vec3 size, bool useTexture = false);
ShapeData CreatePlane(glm::vec3 pos, unsigned int numFaces, int scale, bool useTexture = false);
ShapeData CreateQuad(glm::vec3 pos, glm::vec3 size, bool useTexture = false);
ShapeData CreatePyramid(glm::vec3 pos, glm::vec3 size, bool useTexture = false);
ShapeData CreateSphere(glm::vec3 pos, glm::vec3 size, bool useTexture = false);



#endif // SHAPEDATA_H
