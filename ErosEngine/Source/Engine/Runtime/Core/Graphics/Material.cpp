#include "Material.h"


Material::Material()
{

}

Material::~Material()
{

}

void Material::CreateFromOther(const IComponent *other)
{
	if (other->GetType() != ComponentType_MATERIAL)
		return;


}

void Material::FreeResources()
{
	if (this)
		delete this;
}

QString Material::ToString() const
{
	return "Material";
}

ComponentType Material::GetType() const 
{
	return ComponentType_MATERIAL;
}