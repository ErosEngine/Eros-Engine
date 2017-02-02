#include "DX12Renderer.h"

bool DX12Renderer::Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{
	IDXGIFactory4 *pFactory = nullptr;
	IDXGIAdapter  *pAdapter = nullptr;

	CreateDXGIFactory1(IID_PPV_ARGS(&pFactory));

	if (FAILED(pFactory->EnumAdapters(0, &pAdapter)))
	{
		return false;
	}

	if (FAILED(D3D12CreateDevice(
			pAdapter, D3D_FEATURE_LEVEL_12_0, 
			IID_PPV_ARGS(&m_pDevice))))
	{
		pAdapter->Release();

		// Here under normal circumstances I would throw some kind of error code
		// but I am going to finish directx 12 so we will use a warp driver here
		IDXGIAdapter *pWarpAdapter = nullptr;

		if (FAILED(pFactory->EnumWarpAdapter(IID_PPV_ARGS(&pWarpAdapter))))
		{
			return false;
		}

		if (FAILED(D3D12CreateDevice(
				pWarpAdapter, D3D_FEATURE_LEVEL_11_1, 
				IID_PPV_ARGS(&m_pDevice))))
		{
			return false;
		}
	}
	
	return true;
}

void DX12Renderer::Clear()
{
}

void DX12Renderer::RenderScene()
{
}

void DX12Renderer::Swap(Sint32 vsync)
{
}

void DX12Renderer::Cleanup()
{
}

void DX12Renderer::ResizeTarget(Sint32 width, Sint32 height)
{

}

void DX12Renderer::SetScene(Scene *pScene)
{
}

void DX12Renderer::OnSceneUnload()
{
}
