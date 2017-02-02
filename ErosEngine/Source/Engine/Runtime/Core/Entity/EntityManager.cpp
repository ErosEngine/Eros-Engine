#include "EntityManager.h"

static EntityManager *s_EntityManager = nullptr;


EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

EntityManager *EntityManager::GetInstance()
{
	if (!s_EntityManager)
		s_EntityManager = new EntityManager();
	return s_EntityManager;
}

void EntityManager::Initialize()
{
	// TODO: Maybe fix this but I feel like this would be the 
	// fastest option for nows
	m_EntityRefs.resize(100);
}

void EntityManager::Destroy()
{
	delete s_EntityManager;
}

Entity *EntityManager::CreateEntity()
{
	for (Uint32 i = 0; i < 100; ++i)
	{
		if (m_EntityRefs[i].GetID() == 0)
		{
			m_EntityRefs[i].m_Id = i;
			return &m_EntityRefs[i];
		}
	}
	return nullptr; // Handle this, something went very wrong
}

void EntityManager::UnregisterEntity(Uint64 id)
{
	m_EntityRefs[id].m_Children = 0;
	m_EntityRefs[id].m_ParentID = 0;
	m_EntityRefs[id].m_Id = 0; // Free it up so we can reuse it
	m_EntityRefs[id].FreeComponents();
	m_EntityRefs[id].m_Name = QString();
}

const Entity *EntityManager::GetEntityByID(Uint64 id) const
{
	assert(id != 0);
	return &m_EntityRefs.at(id);
}
