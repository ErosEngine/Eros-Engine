#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

typedef void * GenericHandle;

/* =====================================
 * The component interface object
 * ===================================== */
class IComponent
{
public:
	
	QString fileName;
	
	// Load a component from file
	virtual bool loadFromFile(const char *fileName) = 0;
	
	// From an existing component, use a 
	// pointer so that you can load from a copy
	virtual void fromExisting(const IComponent *other) = 0;
	
};

#endif // COMPONENT_H
