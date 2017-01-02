#include <SDL.h>
#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/D3D11/D3D11Renderer.h"
#include "MainWindow.h"
#include "Engine/Developer/Util/Util.h"
#include "Engine/Developer/Client/Input.h"
#include <cassert>


Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Window::Create(const char *name, int width, int height, int windowFlags)
{
    m_pWindow = SDL_CreateWindow
    (
        name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_OPENGL | windowFlags
    );
	
    // Force application failure if window is null
    assert(m_pWindow != nullptr);
    
	m_width = width;
	m_height = height;
	
	if (windowFlags == FULLSCREEN_WINDOW)
	{
		m_isFullScreen = true;
	}
	else
	{
		m_isFullScreen = false;
	}
}

bool Window::IsOpen()
{
	return m_isOpen;
}

bool Window::PollEvent(SDL_Event &event)
{
	return SDL_PollEvent(&event);
}

void Window::Close()
{
	m_isOpen = false;
}

void Window::Destroy()
{
    SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

