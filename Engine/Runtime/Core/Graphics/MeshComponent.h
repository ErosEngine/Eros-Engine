#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#include "../Framework/Math.h"
#include <vector>
#include <QString>
#include "Texture.h"

#define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)


struct Vertex
{
    EVector3 position;
    EVector3 normal;
    EVector2 texCoords;
};

struct MeshComponent
{
	std::vector<Vertex> vertexes;
    std::vector<ushort> indices;
    std::vector<Texture> textures;
	
	QString fileName;
	
	bool loadFromFile(const char *fileName);
	void clearMesh();
	
};



#endif // SHAPEDATA_H
