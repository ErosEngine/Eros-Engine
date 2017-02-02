#ifndef D3D11RENDERER_H
#define D3D11RENDERER_H

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcommon.h>
#include "Runtime/Core/Framework/IRenderer.h"



class DX11Renderer : public IRenderer
{
public:
	DX11Renderer();
	
	virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) override;
	virtual void Clear() override;
	virtual void RenderScene() override;
	virtual void Swap(Sint32 vsync) override;
	virtual void Cleanup() override;
	virtual void ResizeTarget(Sint32 width, Sint32 height) override;
	virtual void SetScene(Scene *pScene) override;
	virtual void OnSceneUnload() override;

private:
		
	ID3D11Device				* m_pDevice;
	ID3D11DeviceContext			* m_pDeviceContext;
	IDXGISwapChain				* m_pDxgiSwapChain;
	ID3D11RenderTargetView		* m_pRenderTargetView;
	ID3D11Texture2D				* m_pDepthStencilBuffer;
	ID3D11DepthStencilState		* m_pDepthStencilState;
	ID3D11DepthStencilView		* m_pDepthStencilView;
	ID3D11RasterizerState		* m_pRasterizerState;
	
	D3D_FEATURE_LEVEL			m_featureLevel;
	D3D_DRIVER_TYPE				m_driverType;
	D3D11_VIEWPORT				m_viewport;
	
};

#endif // D3D11RENDERER_H
