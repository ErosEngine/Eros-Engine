#include "SceneEditor.h"
#include "Runtime/Core/Graphics/MeshComponent.h"
#include "Runtime/OpenGL/OGLRenderer.h"


void SceneEditor::SetRenderer(IRenderer *pRenderer)
{
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
