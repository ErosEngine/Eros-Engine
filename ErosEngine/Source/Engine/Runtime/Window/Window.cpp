#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/D3D11/DX11Renderer.h"
#include "Window.h"
#include <cassert>


static Uint32	screenWidth = 0;
static Uint32	screenHeight = 0;
static Byte		keys[256];
 
LRESULT CALLBACK _WindowCallback(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	
	switch (message)
	{
	case WM_CLOSE:
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	}
	

	return DefWindowProc(window, message, wparam, lparam);
}

Window::Window()
{
}

void Window::Create(const char *name, Uint32 width, Uint32 height, Uint32 xPos, Uint32 yPos, Uint32 windowFlags)
{
	m_Instance = GetModuleHandle(NULL);

	WNDCLASSA windowClass = { 0 };
	windowClass.lpszClassName = "__Eros_Game_window__";
	windowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	windowClass.lpfnWndProc = _WindowCallback;
	windowClass.hInstance = m_Instance;

	if (!RegisterClassA(&windowClass))
		return;

	m_WindowHandle = CreateWindowA(
		"__Eros_Game_window__",
		name,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		xPos, yPos, width, height, NULL,
		NULL, m_Instance, NULL
	);

	if (!m_WindowHandle)
		return;

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

void Window::SetMouseLocked(bool value)
{
	m_isMouseLocked = value;
}

bool Window::IsOpen()
{
	return m_isOpen;
}

bool Window::PollEvent(Event &curEvent)
{
	MSG message = { };
	bool hasMessage = PeekMessageA(&message, NULL, 0, 0, PM_REMOVE);
	switch (message.message)
	{
		case WM_CLOSE:
		case WM_QUIT:
		{
			curEvent.type = EVENT_CLOSE_EVENT;
		} break;
		case WM_MOUSEMOVE:
		{
			curEvent.type = EVENT_MOUSE_EVENT;
			short *mousePositions = (short *)&message.lParam;
			curEvent.mouseX = mousePositions[0];
			curEvent.mouseY = mousePositions[1];
		} break;
		case WM_KEYDOWN:
		{
			curEvent.type = EVENT_KEY_EVENT;
			GetKeyboardState(keys);
		} break;
		case WM_SIZE:
		{
			curEvent.type = EVENT_RESIZE_EVENT;
			short *resizeSizes = (short *)&message.lParam;
			curEvent.resizeX = resizeSizes[0];
			curEvent.resizeY = resizeSizes[1];
		} break;
		case WM_PAINT:
		{
		} break;
	}
	TranslateMessage(&message);
	DispatchMessage(&message);

	if (m_isMouseLocked)
	{
		SetCursorPos(screenWidth / 2, screenHeight / 2);
		ShowCursor(false);
	}
	else
	{
		ShowCursor(true);
	}

	return hasMessage;
}

bool Window::IsKeyDown(Uint32 key)
{
	return keys[key] & 0x80;
}

bool Window::IsKeyUp(Uint32 key)
{
	return !IsKeyDown(key);
}

void Window::Close()
{
	m_isOpen = false;
	UnregisterClassA("__Eros_Game_window__", m_Instance);
	DestroyWindow(m_WindowHandle);
}

Handle Window::GetPlatformHandle()
{
	
#if defined(EROS_WINDOWS)
	
	return m_WindowHandle;
	
#elif defined(EROS_LINUX)
	
	
#endif
	
	return nullptr;
}
