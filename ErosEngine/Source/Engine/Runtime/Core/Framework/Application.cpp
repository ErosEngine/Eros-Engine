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

void Application::SetVSyncEnabled(bool vsync)
{
	m_isVsync = vsync;
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
		
		Event e;
		while (m_pWindow->PollEvent(e))
		{
			if (e.type == EVENT_CLOSE_EVENT)
				m_pWindow->Close();
		}
		
		m_pRenderer->Swap(m_isVsync);
	}
}

void Application::EndGameLoop()
{
}
