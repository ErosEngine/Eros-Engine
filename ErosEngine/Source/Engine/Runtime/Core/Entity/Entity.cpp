#include "Entity.h"
#include "EntityManager.h"



void Entity::AddComponent(IComponent *pComponent)
{
	m_Components.push_back(pComponent);
}

void Entity::FreeComponents()
{
	for (Uint32 i = 0; i < m_Components.size(); ++i)
	{
		m_Components[i]->FreeResources();
	}
	m_Components.clear();
}

Uint64 Entity::GetID()
{
	return m_Id;
}

QString Entity::GetName() const
{
	return m_Name;
}

void Entity::SetName(const QString &name)
{
	m_Name = name;
}

void Entity::AttachChild(Uint64 id)
{
}

void Entity::SetParent(Uint64 id)
{
}

std::vector<IComponent *> &Entity::GetComponents()
{
	return m_Components;
}
