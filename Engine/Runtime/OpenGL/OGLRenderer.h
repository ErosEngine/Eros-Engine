#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/Window/Window.h"
#include "../Core/Framework/IRenderBase.h"
#include <QOpenGLContext>
#include <cassert>


class OpenGLRenderer : public IRenderBase
{
public:
    
	OpenGLRenderer() { } // Empty constructor
	
    virtual void Create(GenericHandle hWindow, int width, int height, int flags) override;
    
	virtual void Clear() override;
	virtual void Swap() override;
	virtual void Cleanup() override;
	
private:
	
#if defined(EROS_WINDOWS)
	
	HDC m_deviceHandle;
	HGLRC m_OGLrenderContextHandle;
	
#elif defined(EROS_LINUX)
	
#endif
	
	/* From IRenderBase
	 
	RendererArgs *i_pRendererArgs;
	 
	*/
	
	
};

#endif // OPENGLRENDERER_H
