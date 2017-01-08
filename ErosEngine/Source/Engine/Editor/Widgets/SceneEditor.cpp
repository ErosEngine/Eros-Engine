#include "SceneEditor.h"


void SceneEditor::SetRenderer(IRenderBase *pRenderer)
{
	pRenderer->Create(m_WindowHandle, m_Geometry.width, m_Geometry.height, 0);
	m_pRenderer = pRenderer;
}

void SceneEditor::OnShow()
{
}

void SceneEditor::OnUpdate()
{
	m_pRenderer->Clear();
	m_pRenderer->Swap(true);
}

void SceneEditor::OnPaint()
{
}

void SceneEditor::OnEvent(const Event &event)
{
}

void SceneEditor::OnClose()
{
	m_pRenderer->Cleanup();
}
