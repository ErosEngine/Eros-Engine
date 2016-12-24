#include "OGLRenderer.h"
#include <SDL.h>
#include <QDebug.h>


void OpenGLRenderer::create(MainWindowSDL *pWindow)
{
    SDL_GLContext context = SDL_GL_CreateContext(pWindow->m_pWindow);

    // Force application failure if no context
    assert(context != 0);
    assert(SDL_GL_MakeCurrent(pWindow->m_pWindow, context) != 0);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	assert(glewInit() == GLEW_OK);
	
	qDebug() << "OpenGL has initialized, Current version: " 
			 << ((const char *)glGetString(GL_VERSION));
	
	m_isSDLWindow = true;
	m_pWindow = pWindow->m_pWindow;
	
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
}

void OpenGLRenderer::create(QWidget *pQtWindow)
{
	
}

void OpenGLRenderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// TODO(kiecker): Add some logic to optimize this
void OpenGLRenderer::renderScene()
{
    glPushMatrix();
	
	
	
	if (m_isSDLWindow)
		SDL_GL_SwapWindow(m_pWindow);
	
	glPopMatrix();
}

void OpenGLRenderer::cleanup()
{
	
}

void OpenGLRenderer::setScene(Scene *pScene)
{
	
}

const Scene *OpenGLRenderer::scene() const
{
	return this->i_pScene;
}

