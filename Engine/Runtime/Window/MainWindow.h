#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <QDebug>

#include "../Core/Framework/Platform.h"

enum WindowFlags
{
	FULLSCREEN_WINDOW = SDL_WINDOW_FULLSCREEN,
	WINDOWED_WINDOW = SDL_WINDOW_SHOWN,
	WINDOWED_RESIZEABLE_WINDOW = WINDOWED_WINDOW | SDL_WINDOW_RESIZABLE
};

class MainWindowSDL
{
	friend class D3D11Renderer;
	friend class OpenGLRenderer;
	friend class VulkanRenderer;
	friend class GameLoop;
	
public:
    explicit MainWindowSDL();
    
    void create(const char *name, int width, int height, int windowFlags);
    
    int width() { return m_width; }
    int height() { return m_height; }
	bool isFullScreen() { return m_isFullScreen; }
	bool isOpen();
	bool pollEvent(SDL_Event &event);
	void close();
	
private:
    
    void destroy();
    
    SDL_Window  * m_pWindow;
    int           m_width, m_height;
	bool		  m_isFullScreen;
	bool		  m_isOpen = true;
    
};




#endif // MAINWINDOW_H
