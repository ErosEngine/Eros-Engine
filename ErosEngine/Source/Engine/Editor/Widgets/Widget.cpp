#include <QtCore/QDebug>
#include "Widget.h"
#include "Editor/EditorWindow.h"


LRESULT CALLBACK DefaultWindowCallBack(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(window, message, wparam, lparam);
}


Widget *Widget::GetParent()
{
	return m_ParentWindow;
}

HWND Widget::GetWindowHandle()
{
	return m_WindowHandle;
}

ERect Widget::GetGeometry()
{
	return m_Geometry;
}

void Widget::Create(Widget *parent, ERect geometry, const char *className)
{
	WNDCLASSA windowClass = { 0 };
	windowClass.lpszClassName = className;
	windowClass.lpfnWndProc = DefaultWindowCallBack;
	windowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	windowClass.hInstance = GetModuleHandle(NULL);

	RegisterClassA(&windowClass);

	m_Geometry = geometry;

	m_ClassName = className;

	DWORD flags = 0;

	HWND parentWindowHandle = NULL;
	if (parent)
	{
		m_ParentWindow = parent;
		m_WindowName = NULL; // No need for a name when there is a parent
		flags |= WS_CHILD | WS_VISIBLE;
		parentWindowHandle = m_ParentWindow->GetWindowHandle();
	}
	else
	{
		m_ParentWindow = nullptr;
		flags |= WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	}

	m_WindowHandle = CreateWindowA(
		m_ClassName,
		"Widget",
		flags,
		geometry.x, geometry.y,
		geometry.width, geometry.height,
		parentWindowHandle, NULL, 
		windowClass.hInstance, NULL);

	OnShow();
}

void Widget::Create(EditorWindow *pWindow, ERect geometry, const char *className)
{
	WNDCLASSA windowClass = { 0 };
	windowClass.lpszClassName = className;
	windowClass.lpfnWndProc = DefaultWindowCallBack;
	windowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	windowClass.hInstance = GetModuleHandle(NULL);

	RegisterClassA(&windowClass);

	m_ClassName = className;
	m_Geometry = geometry;

	HWND parentWindowHandle = pWindow->GetWindowHandle();
	
	m_WindowHandle = CreateWindowA(
		m_ClassName,
		"Widget",
		WS_CHILD | WS_VISIBLE,
		geometry.x, geometry.y,
		geometry.width, geometry.height,
		parentWindowHandle, NULL,
		windowClass.hInstance, NULL
	);

	OnShow();
}

void Widget::Close()
{
	OnClose();
	DestroyWindow(m_WindowHandle);
}

void Widget::SetWindowName(const char *name)
{
	m_WindowName = name;
	SetWindowText(m_WindowHandle, name);
}

void Widget::Update()
{
	MSG message = { };
	while (PeekMessageA(&message, m_WindowHandle, 0, 0, PM_REMOVE))
	{
		Event curEvent;
		switch (message.message)
		{
			case WM_CLOSE:
			case WM_DESTROY:
			case WM_QUIT:
			{
				curEvent.type = EVENT_CLOSE_EVENT;
				OnClose();
				Close();
				return;
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
				curEvent.button = message.wParam;
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
				OnPaint();
			} break;
		}
		OnEvent(curEvent);
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	OnUpdate();
}


