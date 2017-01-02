#include "Application.h"



void Application::SetRenderer(IRenderBase *pRenderer, RenderingType api)
{
	m_pRenderer = pRenderer;
	m_renderingApi = api;
}

void Application::SetWindow(Window *pWindow)
{
	m_pWindow = pWindow;
}

void Application::InitializeLoop()
{
	m_timer.start();
}

void Application::RunGameLoop()
{
	while (m_pWindow->IsOpen())
	{
		m_pRenderer->Clear();
		
		SDL_Event e;
		
		while (m_pWindow->PollEvent(e))
		{
			if (e.type == SDL_QUIT)
				m_pWindow->Close();
		}
		
		m_pRenderer->Swap();
	}
}

void Application::EndGameLoop()
{
}
