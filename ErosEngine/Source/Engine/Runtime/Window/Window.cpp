#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/D3D11/D3D11Renderer.h"
#include "Window.h"
#include <cassert>


Window::Window()
{
}

void Window::Create(const char *name, Sint32 width, Sint32 height, Sint32 windowFlags)
{
}

bool Window::IsOpen()
{
	return m_isOpen;
}

bool Window::PollEvent(Event &event)
{
	return false;
}

void Window::Close()
{
}

GenericHandle Window::GetPlatformHandle()
{
	
#if defined(EROS_WINDOWS)
	
	
#elif defined(EROS_LINUX)
	
	
#endif
	
	return nullptr;
}

void Window::Destroy()
{
}
