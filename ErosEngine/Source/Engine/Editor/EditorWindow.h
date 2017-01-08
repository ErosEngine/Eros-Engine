#pragma once

#include "Widgets/Widget.h"
#include <memory>
#include <vector>


class EditorWindow
{
public:
	EditorWindow();
	~EditorWindow();

	void Create(const char *windowName, ERect geometry);
	void AddWidget(Widget *widget);
	void SetWindowTitle(const char *newName);
	void SetGeometry(ERect geometry);
	void Run();

	HWND GetWindowHandle();

private:
	typedef std::vector<std::shared_ptr<Widget>> WidgetsList;

	WidgetsList m_Widgets;
	HWND		m_WindowHandle;
	ERect		m_Geometry;
	const char *m_WindowTitle;
	bool		m_isRunning = true;
};

