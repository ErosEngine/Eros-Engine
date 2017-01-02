#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QElapsedTimer>
#include "Core/Platform.h"
#include "SceneManager.h"

// Renderers
#include "IRenderBase.h"
#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#if defined(EROS_WINDOWS) && WINVER >= _WIN32_IE_WIN7
	#include "Engine/Runtime/D3D11/D3D11Renderer.h"
#endif

// Window
#include "Engine/Runtime/Window/Window.h"



class Application
{
public:
	
	// We are running off the assumption the renderer
	// is already set up
	void SetRenderer(IRenderBase *pRenderer, RenderingType api);
	void SetWindow(Window *pWindow);
	
	void InitializeLoop();
	void RunGameLoop(); // Update and render, play sound, etc.
	void EndGameLoop();

private:	
	IRenderBase		* m_pRenderer;
	Window			* m_pWindow;
	SceneManager	m_sceneManager;
	RenderingType	m_renderingApi;
	QElapsedTimer	m_timer;
	
};

#endif // GAMELOOP_H
