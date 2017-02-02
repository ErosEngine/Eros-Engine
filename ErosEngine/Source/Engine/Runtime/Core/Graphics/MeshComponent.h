#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#include "Core/Math.h"
#include "Runtime/Core/Entity/ComponentsBase.h"
#include <vector>
#include <QtCore/QString>


struct Vertex
{
    EVector3 position;
    EVector3 normal;
    EVector2 texCoords;
};

class MeshComponent : public ILoadedComponent
{
	
public:
	std::vector<Vertex> vertexes;
    std::vector<ushort> indices;
	
	virtual void CreateFromOther(const IComponent *other) override;
	virtual bool LoadFromFile(const char *fileName) override;
	virtual void FreeResources() override;
	virtual QString ToString() const override;
	virtual ComponentType GetType() const override;
};



#endif // SHAPEDATA_H
