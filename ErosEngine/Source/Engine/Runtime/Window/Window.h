#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <Core/Platform.h>
#include <QtCore/QDebug>
#include "Events.h"


enum WindowFlags
{
	WINDOW_RESIZEABLE = 1,
	WINDOW_FULLSCREEN = 2,
};

class Window
{
	friend class DX11Renderer;
	friend class OpenGLRenderer;
	friend class VulkanRenderer;
	friend class Application;
	
public:
    explicit Window();
    
    void Create(const char *name, Uint32 width, Uint32 height, Uint32 xPos, Uint32 yPos, Uint32 windowFlags);
    
    Uint32 GetWidth() { return m_Width; }
    Uint32 GetHeight() { return m_Height; }
	bool IsFullScreen() { return m_isFullScreen; }
	bool IsMouseLocked() { return m_isMouseLocked; }
	void SetMouseLocked(bool value);
	bool IsOpen();
	bool PollEvent(Event &event);
	bool IsKeyDown(Uint32 key);
	bool IsKeyUp(Uint32 key);
	void Close();
	
	Handle GetPlatformHandle();
	
private:
    
    HWND		m_WindowHandle;
	HINSTANCE	m_Instance;
    Uint32		m_Width, m_Height;
	bool		m_isFullScreen;
	bool		m_isOpen = true;
	bool		m_isMouseLocked = false;
};




#endif // MAINWINDOW_H
