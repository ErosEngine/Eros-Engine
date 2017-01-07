#ifndef IRENDERBASE_H
#define IRENDERBASE_H

#include "Core/Platform.h"
#include "Scene.h"


typedef void *GenericHandle;

/* ==============
 * The rendering interface
=============== */
class IRenderBase
{
public:
	
    virtual void Create(GenericHandle hWindow, int width, int height, int flags) = 0;
	
	// The clear and draw functions that will
	// be abstracted to the rendering api's
	virtual void Clear()		= 0;
	virtual void Swap(int vsync)= 0;
	virtual void Cleanup()		= 0;
	
protected:
	
};


#endif // IRENDERBASE_H
