#include "ShapeData.h"
#include <QDebug>
#include <QFile>



Mesh CreateCube()
{
    Mesh shape;
    
    // Note(kiecker): Hackey right now, but I will fix it later
    // This is for reference
    /* position              normals                
     * -0.5f,  0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f,  0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f, -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f, -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  0.0f
     */
    
    return shape;
}

Mesh CreatePlane()
{
    return Mesh();
}

Mesh CreateQuad()
{
    return Mesh();
}

Mesh CreatePyramid()
{
    return Mesh();
}

Mesh CreateSphere()
{
    return Mesh();
}


typedef QList<QByteArray> ByteArrayList;

// Gets all lines and stores them in a QVector
// For the obj loader more than anything
const ByteArrayList &getAllLines(const QByteArray &original)
{
    QByteArray ret;
    ret = original.split("\n");
    return ret;
}

void processVertices(const ByteArrayList &objVerts, )


// Core model loading function
bool Model::loadMeshFromFile(const char *fileName)
{    
    QFile file(fileName);
    
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return false;
    }
    
    QByteArray text = file.readAll();
    
    
}
