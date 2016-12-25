#ifndef IRENDERBASE_H
#define IRENDERBASE_H

#include "ErosLib/ErosDefines.h"
#include "Scene.h"


enum RenderingApi
{
	API_OPENGL_4_5  = 1,
	API_DIRECTX_11  = 2,
	API_VULKAN		= 3,
	API_DIRECTX_12	= 4
};

class MainWindowSDL;
class QWidget;

/* ==============
 * The rendering interface
=============== */
class IRenderBase
{
public:
	
    virtual void create(MainWindowSDL *pWindow)		= 0;
	virtual void create(QWidget *pQtWindow)			= 0;
	
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
