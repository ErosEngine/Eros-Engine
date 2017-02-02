#include "EditorWindow.h"


LRESULT CALLBACK WindowCallback(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT paintStruct = { };
	HDC device = NULL;

	switch (message)
	{
	case WM_CLOSE:
	case WM_QUIT:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		device = BeginPaint(window, &paintStruct);
		FillRect(device, &paintStruct.rcPaint, (HBRUSH)COLOR_WINDOW);
		EndPaint(window, &paintStruct);
		break;
	}
	return DefWindowProc(window, message, wparam, lparam);
}


EditorWindow::EditorWindow()
{
}

EditorWindow::~EditorWindow()
{
}

void EditorWindow::Create(const char *windowName, ERect geometry)
{
	m_Geometry = geometry;

	WNDCLASSA windowClass = { 0 };
	windowClass.lpszClassName = "__Eros__Window__";
	windowClass.lpfnWndProc = WindowCallback;
	windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassA(&windowClass);

	m_WindowHandle = CreateWindowA(
		"__Eros__Window__",
		windowName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		m_Geometry.x,		m_Geometry.y,
		m_Geometry.width,	m_Geometry.height,
		NULL, NULL, windowClass.hInstance, NULL
	);
}

void EditorWindow::AddWidget(Widget *widget)
{
	std::shared_ptr<Widget> tempWidget(widget);
	m_Widgets.push_back(tempWidget);
}

void EditorWindow::SetWindowTitle(const char *newName)
{
	m_WindowTitle = newName;
	SetWindowTextA(m_WindowHandle, m_WindowTitle);
}

void EditorWindow::SetGeometry(ERect geometry)
{
	m_Geometry = geometry;
}

void EditorWindow::Run()
{
	while (m_isRunning)
	{
		MSG message = { 0 };
		while (PeekMessageA(&message, m_WindowHandle, 0, 0, PM_REMOVE))
		{
			switch (message.message)
			{
			case WM_QUIT:
				m_isRunning = false;
				break;
			case WM_SIZE:
				RECT windowRect = { };
				ERect newGeometry;
				GetWindowRect(m_WindowHandle, &windowRect);
				newGeometry.x = windowRect.left;
				newGeometry.y = windowRect.bottom;
				newGeometry.width = windowRect.right;
				newGeometry.height = windowRect.top;
				break;
			}

			TranslateMessage(&message);
			DispatchMessageA(&message);
		}

		if (m_Widgets.size() > 0)
		{
			for (Uint32 i = 0; i < m_Widgets.size(); ++i)
			{
				if (!m_Widgets[i]._Expired())
					m_Widgets[i]->Update();
			}
		}
	}

	m_Widgets.clear();
}

HWND EditorWindow::GetWindowHandle()
{
	return m_WindowHandle;
}
