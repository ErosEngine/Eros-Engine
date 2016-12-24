#ifndef IRENDERBASE_H
#define IRENDERBASE_H

#include "Scene.h"

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
	virtual void renderScene()	= 0;
	virtual void cleanup()		= 0;
	
	virtual void setScene(Scene *pScene) = 0;
	virtual const Scene *scene() const   = 0;
	
protected:
	
	Scene *i_pScene;
	
};


#endif // IRENDERBASE_H
