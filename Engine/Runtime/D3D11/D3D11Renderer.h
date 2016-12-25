#ifndef D3D11RENDERER_H
#define D3D11RENDERER_H

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcommon.h>
#include <QWidget>
#include "Engine/Runtime/Window/MainWindow.h"
#include "../Core/Framework/IRenderBase.h"

#define IMMEDIATE_MODE 1
#define DIRECT_MODE 2  // TODO(kiecker): get the right name


class D3D11Renderer : public IRenderBase
{
public:
	D3D11Renderer();
	
	virtual void create(QWidget *pQtWindow) override;
	virtual void create(MainWindowSDL *pMainWindow) override;
	virtual void clear() override;
	virtual void renderArgs() override;
	virtual void cleanup() override;
	
	virtual void setRendererArgs(RendererArgs *pRendererArgs) override;
	virtual const RendererArgs *rendererArgs() const override;
	
	
private:
	
	/* --- From inherited object IRenderBase
	RendererArgs *i_pRendererArgs;
	   --- */
	
	void internalCreate(HWND windowHandle, int width, int height, int flags);
	
	ID3D11Device				* m_pDevice;
	ID3D11DeviceContext			* m_pDeviceContext;
	IDXGISwapChain				* m_pDxgiSwapChain;
	ID3D11RenderTargetView		* m_pRenderTargetView;
	ID3D11Texture2D				* m_pDepthStencil;
	ID3D11DepthStencilState		* m_pDepthStencilState;
	ID3D11DepthStencilView		* m_pDepthStencilView;
	ID3D11RasterizerState		* m_pRasterizerState;
	
	D3D_FEATURE_LEVEL			m_featureLevel;
	D3D_DRIVER_TYPE				m_driverType;
	D3D11_VIEWPORT				m_viewport;
	
};

#endif // D3D11RENDERER_H
