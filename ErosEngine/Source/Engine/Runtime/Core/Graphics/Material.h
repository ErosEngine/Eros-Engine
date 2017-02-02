#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
#include "Runtime/Core/Entity/ComponentsBase.h"
#include "Texture.h"


class Material : public IComponent
{
public:
	
	Material();
	~Material();

	virtual void CreateFromOther(const IComponent *other) override;
	virtual void FreeResources() override;
	virtual QString ToString() const override;
	virtual ComponentType GetType() const override;

    float shininess;
    Texture diffuseTexture;
    Texture specularTexture;
	Texture bumpMaptexture;
};

#endif // MATERIAL_H
