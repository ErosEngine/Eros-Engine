#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <QDebug>

#include "Core/Platform.h"

enum WindowFlags
{
	FULLSCREEN_WINDOW = SDL_WINDOW_FULLSCREEN,
	WINDOWED_WINDOW = SDL_WINDOW_SHOWN,
	WINDOWED_RESIZEABLE_WINDOW = WINDOWED_WINDOW | SDL_WINDOW_RESIZABLE
};

class Window
{
	friend class D3D11Renderer;
	friend class OpenGLRenderer;
	friend class VulkanRenderer;
	friend class Application;
	
public:
    explicit Window();
    
    void Create(const char *name, int width, int height, int windowFlags);
    
    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }
	bool IsFullScreen() { return m_isFullScreen; }
	bool IsOpen();
	bool PollEvent(SDL_Event &event);
	void Close();
	
	GenericHandle GetPlatformHandle();
	
private:
    
    void Destroy();
    
    SDL_Window  * m_pWindow;
    int           m_width, m_height;
	bool		  m_isFullScreen;
	bool		  m_isOpen = true;
    
};




#endif // MAINWINDOW_H
