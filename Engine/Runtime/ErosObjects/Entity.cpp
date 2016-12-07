#include "Entity.h"

Entity::Entity()
{
}

void Entity::setName(const QString &name)
{
    m_name = name;
}

const QString &Entity::getName() const
{
    return m_name;
}

