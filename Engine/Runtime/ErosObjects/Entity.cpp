#include "Entity.h"


void Entity::setName(const QString &name)
{
    m_name = name;
}

const QString &Entity::name() const
{
    return m_name;
}

