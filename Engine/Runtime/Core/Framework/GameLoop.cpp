#include "GameLoop.h"



void GameLoop::setRenderer(IRenderBase *pRenderer, RenderingType api)
{
	m_pRenderer = pRenderer;
	m_renderingApi = api;
}

void GameLoop::setWindow(MainWindowSDL *pWindow)
{
	m_pWindow = pWindow;
}

void GameLoop::initializeLoop()
{
	m_timer.start();
}

void GameLoop::runGameLoop()
{
	while (m_pWindow->isOpen())
	{
		m_pRenderer->clear();
		
		SDL_Event e;
		
		while (m_pWindow->pollEvent(e))
		{
			if (e.type == SDL_QUIT)
				m_pWindow->close();
		}
		
		if (m_renderingApi == API_OPENGL_4_5)
			SDL_GL_SwapWindow(m_pWindow->m_pWindow);
	}
}

void GameLoop::endGameLoop()
{
	//m_sceneManager.cleanAllScenes();
}
