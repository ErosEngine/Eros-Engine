#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QtCore/QElapsedTimer>
#include "Core/Platform.h"
#include "SceneManager.h"

// Renderers
#include "IRenderer.h"
#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#if defined(EROS_WINDOWS)
	#include "Engine/Runtime/D3D11/DX11Renderer.h"
#endif

// Window
#include "Engine/Runtime/Window/Window.h"


class Application
{
public:
	
	Application();
	~Application();

	// We are running off the assumption the renderer
	// is already set up
	void SetRenderer(IRenderer *pRenderer, Api api);
	void SetWindow(Window *pWindow);
	void SetVSyncEnabled(bool vsync);
	
	void InitializeLoop();
	void RunGameLoop(); // Update and render, play sound, etc.
	void EndGameLoop();
	void FireCloseEvent();

	static Application *GetInstance();

private:	
	IRenderer		*m_pRenderer;
	Window			*m_pWindow;
	SceneManager	m_SceneManager;
	Api				m_renderingApi;
	QElapsedTimer	m_timer;
	bool			m_isVsync = true;
	
};

#endif // GAMELOOP_H
