#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QElapsedTimer>
#include "ErosLib/ErosDefines.h"
#include "SceneManager.h"

// Renderers
#include "IRenderBase.h"
#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#if defined(EROS_WINDOWS) && WINVER >= _WIN32_IE_WIN7
	#include "Engine/Runtime/D3D11/D3D11Renderer.h"
#endif

// Window
#include "Engine/Runtime/Window/MainWindow.h"



class GameLoop
{
public:
	
	// We are running off the assumption the renderer
	// is already set up
	void setRenderer(IRenderBase *pRenderer, RenderingApi api);
	void setWindow(MainWindowSDL *pWindow);
	
	void initializeLoop();
	void runGameLoop(); // Update and render, play sound, etc.
	void endGameLoop();

private:	
	IRenderBase		* m_pRenderer;
	MainWindowSDL	* m_pWindow;
	SceneManager	m_sceneManager;
	RenderingApi	m_renderingApi;
	QElapsedTimer	m_timer;
	
};

#endif // GAMELOOP_H
