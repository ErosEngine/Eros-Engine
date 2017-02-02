#include "Application.h"
#include "Runtime/Core/Graphics/MeshComponent.h"


static Application *s_Application = nullptr;

Handle handle = nullptr;

Application::Application()
{
	s_Application = this;
}

Application::~Application()
{

}

void Application::SetRenderer(IRenderer *pRenderer, Api api)
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

Scene scene;
Uint64 id;

void Application::InitializeLoop()
{
	m_timer.start();

	EntityManager::GetInstance()->Initialize();

	MeshComponent *mesh = new MeshComponent();
	mesh->LoadFromFile("Source/Engine/Assets/_cube_.obj");
	
	Entity *entity = EntityManager::GetInstance()->CreateEntity();
	id = entity->GetID();
	entity->AddComponent(mesh);
	scene.Entities.push_back(entity);
}

void Application::RunGameLoop()
{
	m_pRenderer->SetScene(&scene);

	while (m_pWindow->IsOpen())
	{
		m_pRenderer->Clear();
		Event e;
		while (m_pWindow->PollEvent(e))
		{
			if (e.type == EVENT_CLOSE_EVENT)
			{
				m_pWindow->Close();
			}
			
		}

		m_pRenderer->RenderScene();
		m_pRenderer->Swap(m_isVsync);
	}

	EntityManager::GetInstance()->UnregisterEntity(id);
	EntityManager::GetInstance()->Destroy();
	m_pRenderer->Cleanup();
}

void Application::EndGameLoop()
{
}

void Application::FireCloseEvent()
{
}

Application *Application::GetInstance()
{
	// We don't care if this is valid, if an application hasn't been created
	// Why should we return a valid pointer
	return s_Application; 
}
