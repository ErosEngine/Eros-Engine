#pragma once

#include "Runtime/Core/Framework/IRenderer.h"
#include <d3d9.h>


class DX9Renderer : public IRenderer
{
public:

	virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) override;

	// The clear and draw functions that will
	// be abstracted to the rendering api's
	virtual void Clear() override;
	virtual void RenderScene() override;
	virtual void Swap(Sint32 vsync) override;
	virtual void Cleanup() override;

	virtual void ResizeTarget(Sint32 width, Sint32 height) override;
	
	virtual void SetScene(Scene *pScene) override;
	virtual void OnSceneUnload() override;

private:

	IDirect3D9 *m_pD3D9;
	IDirect3DDevice9 *m_pDevice;

};
