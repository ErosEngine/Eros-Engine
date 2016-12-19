#ifndef ENTITY_H
#define ENTITY_H

#include "IComponent.h"
#include <QString>


class Entity
{
public:
    
    void setName(const QString &name);
    const QString &name() const; // We want it to be a const reference for code footprint
    
	void attachComponent(IComponent *component);
	
private:
    
    QString m_name;
    
};

#endif // ENTITY_H
