#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/Window/MainWindow.h"
#include "../Core/Framework/IRenderBase.h"
#include <cassert>


class OpenGLRenderer : public IRenderBase
{
public:
    
	OpenGLRenderer() { } // Empty constructor
	
    virtual void create(GenericHandle hWindow, int width, int height, int flags) override;
    
	virtual void clear() override;
	virtual void renderArgs() override;
	virtual void cleanup() override;
	
	virtual void setRendererArgs(RendererArgs *pRendererArgs) override;
	virtual const RendererArgs *rendererArgs() const override;
	
private:
	
	bool		  m_isSDLWindow = false;
	SDL_Window	* m_pWindow;
	
	/* From IRenderBase
	 
	RendererArgs *i_pRendererArgs;
	 
	*/
	
	
};

#endif // OPENGLRENDERER_H
