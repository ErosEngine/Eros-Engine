#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <vector>
#include <QString>
#include "../OpenGL/Texture.h"
#include "../Core/IComponent.h"

#define ARRAY_SIZE(x) sizeof(x) / sizeof(typeof(x))


struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct MeshComponent : public IComponent
{
	std::vector<Vertex> vertexes;
    std::vector<GLushort> indices;
    std::vector<Texture> textures;
	
	virtual bool loadFromFile(const char *fileName) override;
	virtual void fromExisting(const IComponent *other) override;
};



#endif // SHAPEDATA_H
