#ifndef IRENDERBASE_H
#define IRENDERBASE_H

#include "Platform.h"
#include "Scene.h"


typedef void *GenericHandle;

/* ==============
 * The rendering interface
=============== */
class IRenderBase
{
public:
	
    virtual void create(GenericHandle hWindow, int width, int height, int flags) = 0;
	
	// The clear and draw functions that will
	// be abstracted to the rendering api's
	virtual void clear()		= 0;
	virtual void renderArgs()	= 0;
	virtual void cleanup()		= 0;
	
	virtual void setRendererArgs(RendererArgs *pRendererArgs) = 0;
	virtual const RendererArgs *rendererArgs() const   = 0;
	
protected:
	
	RendererArgs *i_pRendererArgs = nullptr;
	
};


#endif // IRENDERBASE_H
