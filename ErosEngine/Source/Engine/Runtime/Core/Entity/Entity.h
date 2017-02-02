#pragma once

#include <vector>
#include <memory>
#include "ComponentsBase.h"
#include "../Graphics/Transform.h"


class Entity
{
	friend class EntityManager;
	friend class WeakEntityRef;

	std::vector<IComponent *> m_Components;

	QString m_Name;

	// We will default initialize this to zero
	// This will let the manager know that it is available
	Uint64 m_Id = 0;
	Uint64 m_ParentID;
	Uint64 m_Children;

public:

	Transform transform;

	void AddComponent(IComponent *pComponent);
	void FreeComponents();
	Uint64 GetID();

	QString GetName() const;
	void SetName(const QString &name);

	void AttachChild(Uint64 id);
	void SetParent(Uint64 id);

	std::vector<IComponent *> &GetComponents();
	
};
