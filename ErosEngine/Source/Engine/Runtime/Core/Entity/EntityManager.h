#pragma once

#include "Entity.h"


class EntityManager
{
	std::vector<Entity> m_EntityRefs;

public:

	EntityManager();
	~EntityManager();

	static EntityManager *GetInstance();

	void Initialize();
	void Destroy();
	
	// Doesn't really create a new entity but rather just 
	// gets an existing entity that you can edit
	Entity *CreateEntity();
	void UnregisterEntity(Uint64 id);

	// --- Gets a readonly entity --- //
	const Entity *GetEntityByID(Uint64 id) const;


};
