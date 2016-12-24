#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Engine/Runtime/Window/MainWindow.h"
#include "../Core/Framework/IRenderBase.h"
#include <cassert>


class OpenGLRenderer : public IRenderBase
{
	bool		  m_isSDLWindow;
	SDL_Window	* m_pWindow;
	
	/* From IRenderBase
	 
	Scene *i_pScene;
	 
	*/
	
public:
    
	OpenGLRenderer() { } // Empty constructor
	    
    virtual void create(MainWindowSDL *pWindow) override;
	
	// TODO(kiecker): use our own custom widget for opengl context
	virtual void create(QWidget *pQtWindow) override;
    
	virtual void clear() override;
	virtual void renderScene() override;
	virtual void cleanup() override;
	
	virtual void setScene(Scene *pScene) override;
	virtual const Scene *scene() const override;
};

#endif // OPENGLRENDERER_H
