#pragma once

#include "..\Core\Framework\IRenderer.h"
#include <dxgi1_4.h>
#include <d3d12.h>



class DX12Renderer : public IRenderer
{
	virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) override;

	virtual void Clear() override;
	virtual void RenderScene() override;
	virtual void Swap(Sint32 vsync) override;
	virtual void Cleanup() override;
	virtual void ResizeTarget(Sint32 width, Sint32 height) override;

	virtual void SetScene(Scene *pScene) override;
	virtual void OnSceneUnload() override;

private:

	ID3D12Device			*m_pDevice;
	ID3D12CommandAllocator	*m_pAllocator;
	IDXGISwapChain2			*m_pSwapChain;
	ID3D12PipelineState		*m_pPipelineState;
	ID3D12CommandQueue		*m_pCommandQueue;

};
