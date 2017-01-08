#include "EditorWindow.h"


LRESULT CALLBACK WindowCallback(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_CLOSE:
	case WM_QUIT:
	case WM_DESTROY:
		PostQuitMessage(0);
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

	RegisterClassA(&windowClass);

	m_WindowHandle = CreateWindowA(
		"__Eros__Window__",
		"MainWindow",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		m_Geometry.x, m_Geometry.y,
		m_Geometry.width, m_Geometry.height,
		NULL, NULL, windowClass.hInstance, NULL
	);
}

void EditorWindow::AddWidget(Widget *widget)
{
	std::shared_ptr<Widget> tempWidget;
	tempWidget.reset(widget);
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
		if (m_Widgets.size() > 0)
		{
			for (Uint32 i = 0; i < m_Widgets.size(); ++i)
			{
				m_Widgets[i]->Update();
			}
		}

		MSG message = { 0 };
		while (PeekMessageA(&message, NULL, 0, 0, PM_REMOVE))
		{
			switch (message.message)
			{
			case WM_QUIT:
				m_isRunning = false;
				break;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	m_Widgets.clear();
}

HWND EditorWindow::GetWindowHandle()
{
	return m_WindowHandle;
}
