#ifndef ENTITY_H
#define ENTITY_H

#include "../OpenGL/Shape.h"
#include <QString>

// It will inherit all the properties
// Drawing, etc
class Entity : public Shape
{
public:
    
    void setName(const QString &name);
    const QString &getName() const; // We want it to be a const reference for code footprint
    
private:
    
    QString m_name;
    
};

#endif // ENTITY_H
