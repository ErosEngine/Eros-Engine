#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/Window/MainWindow.h"
#include "../Core/Framework/IRenderBase.h"
#include <cassert>


class OpenGLRenderer : public IRenderBase
{
public:
    
	OpenGLRenderer() { } // Empty constructor
	    
    virtual void create(MainWindowSDL *pWindow) override;
	
	// TODO(kiecker): use our own custom widget for opengl context
	virtual void create(QWidget *pQtWindow) override;
    
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
