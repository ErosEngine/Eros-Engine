#pragma once

#include "Runtime/Window/Events.h"
#include "Core/Platform.h"
#include "Core/Math.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class EditorWindow;

class Widget
{
	friend class EditorWindow;

public:

	Widget() { }
	virtual ~Widget() { }

	Widget *GetParent();
	HWND GetWindowHandle();
	ERect GetGeometry();

	void Create(Widget *parent, ERect geometry, const char *className);
	void Create(EditorWindow *pWindow, ERect geometry, const char *className);
	void Close();

	void SetWindowName(const char *name);

	// These functions are meant to be overridden
	virtual void OnShow() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnPaint() = 0;
	virtual void OnEvent(const Event &event) = 0;
	virtual void OnClose() = 0;

private:

	void Update();

protected:

	Widget *m_ParentWindow;
	HWND m_WindowHandle;
	ERect m_Geometry;
	
	const char *m_WindowName;
	const char *m_ClassName;
};
