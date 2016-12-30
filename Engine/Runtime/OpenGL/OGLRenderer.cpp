#include "OGLRenderer.h"
#include "OGLModel.h"
#include <SDL.h>
#include <QDebug.h>


void OpenGLRenderer::create(GenericHandle hWindow, int width, int height, int flags)
{
	MainWindowSDL *pWindow = (MainWindowSDL *)hWindow;
    SDL_GLContext context = SDL_GL_CreateContext(pWindow->m_pWindow);

    // Force application failure if no context
    assert(context != 0);
    assert(SDL_GL_MakeCurrent(pWindow->m_pWindow, context) == 0);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	assert(glewInit() == GLEW_OK);
	
	qDebug() << "OpenGL has initialized, Current version: " 
			 << ((const char *)glGetString(GL_VERSION));
	
	m_isSDLWindow = true;
	m_pWindow = pWindow->m_pWindow;
	
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
}

void OpenGLRenderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
}

// TODO(kiecker): Add some logic to optimize this
void OpenGLRenderer::renderArgs()
{
	for (uint i = 0; i < i_pRendererArgs->meshes.size(); ++i)
	{
		OGLModel *pComponent = (OGLModel *)i_pRendererArgs->meshes[i];
		OpenGLBuffer *pCurrentBuf = (OpenGLBuffer *)pComponent->getBuffer();
		
		glBindVertexArray(pCurrentBuf->vertexArray);
		
		glDrawElements(GL_TRIANGLES, pComponent->mesh()->indices.size(), GL_UNSIGNED_SHORT, NULL);
		
		glBindVertexArray(0);
	}
	
	if (m_isSDLWindow)
		SDL_GL_SwapWindow(m_pWindow);
	
	clear();
}

void OpenGLRenderer::cleanup()
{
	
}

void OpenGLRenderer::setRendererArgs(RendererArgs *pRendererArgs)
{
	if (i_pRendererArgs)
	{
		for (uint i = 0; i < i_pRendererArgs->meshes.size(); ++i)
		{
			OGLModel *pComponent = (OGLModel *)i_pRendererArgs->meshes[i];
			pComponent->cleanup();
		}
	}
	
	i_pRendererArgs = pRendererArgs;
	
	for (uint i = 0; i < i_pRendererArgs->meshes.size(); ++i)
	{
		OGLModel *pComponent = (OGLModel *)i_pRendererArgs->meshes[i];
		pComponent->generateBuffers();
	}
}

const RendererArgs *OpenGLRenderer::rendererArgs() const
{
	return this->i_pRendererArgs;
}

