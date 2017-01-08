#ifndef SHAPEDATA_H
#define SHAPEDATA_H

#include "Core/Math.h"
#include "Runtime/Core/Framework/ComponentsBase.h"
#include <vector>
#include <QtCore/QString>


struct Vertex
{
    EVector3 position;
    EVector3 normal;
    EVector2 texCoords;
};

class MeshComponent : public IComponent
{
public:
	std::vector<Vertex> vertexes;
    std::vector<ushort> indices;
	
	QString fileName;
	
	
	virtual bool LoadFromFile(const char *fileName) override;
	virtual void Clear() override;
	virtual QString ToString() override;
};



#endif // SHAPEDATA_H
