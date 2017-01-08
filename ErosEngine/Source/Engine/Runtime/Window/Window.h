#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <Core/Platform.h>
#include <QtCore/QDebug>
#include "Events.h"


enum WindowFlags
{
	FULLSCREEN_WINDOW = 11,
	WINDOWED_WINDOW = 14,
	WINDOWED_RESIZEABLE_WINDOW = 12
};

class Window
{
	friend class D3D11Renderer;
	friend class OpenGLRenderer;
	friend class VulkanRenderer;
	friend class Application;
	
public:
    explicit Window();
    
    void Create(const char *name, Sint32 width, Sint32 height, Sint32 windowFlags);
    
    Sint32 GetWidth() { return m_Width; }
    Sint32 GetHeight() { return m_Height; }
	bool IsFullScreen() { return m_isFullScreen; }
	bool IsOpen();
	bool PollEvent(Event &event);
	void Close();
	
	GenericHandle GetPlatformHandle();
	
private:
    
    void Destroy();
    
    HWND		m_WindowHandle;
    Uint32		m_Width, m_Height;
	bool		m_isFullScreen;
	bool		m_isOpen = true;
    
};




#endif // MAINWINDOW_H
