#include "DX9Renderer.h"

IDirect3DPixelShader9 *pixelShader;

bool DX9Renderer::Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{
	HWND windowHandle = (HWND)hWindow;

	m_pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	
	D3DPRESENT_PARAMETERS ps = { 0 };
	ps.Windowed = true;
	ps.SwapEffect = D3DSWAPEFFECT_DISCARD;
	ps.hDeviceWindow = windowHandle;
	ps.BackBufferCount = 2;

	if (FAILED(m_pD3D9->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, windowHandle,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&ps, &m_pDevice)))
	{
		return false;
	}
	return true;
}

void DX9Renderer::Clear()
{
}

void DX9Renderer::RenderScene()
{
	m_pDevice->BeginScene();

	m_pDevice->EndScene();
}

void DX9Renderer::Swap(Sint32 vsync)
{
}

void DX9Renderer::Cleanup()
{
}

void DX9Renderer::ResizeTarget(Sint32 width, Sint32 height)
{

}

void DX9Renderer::SetScene(Scene *pScene)
{

}

void DX9Renderer::OnSceneUnload()
{

}

