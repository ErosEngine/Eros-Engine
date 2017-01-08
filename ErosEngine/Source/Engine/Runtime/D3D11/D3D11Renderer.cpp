#include "D3D11Renderer.h"
#include <QtCore/QDebug>


D3D11Renderer::D3D11Renderer()
{
	
}

void D3D11Renderer::Create(GenericHandle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{
	HWND windowHandle = (HWND)hWindow;
	
	// -- Kiecker
	// TODO: actually process the flags
	
	UINT deviceCreateFlags = 0;
#ifdef _DEBUG

	deviceCreateFlags |= D3D11_CREATE_DEVICE_DEBUG;

#endif

	D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_1
	};

	UINT numFeatures = 4;

	IDXGIFactory *pDxgiFactory;
	IDXGIAdapter *pAdapter;
	IDXGIOutput  *pDxgiOutput;
	DXGI_MODE_DESC  *displayModeList;
	ID3D11Texture2D *pBackBufferTexture;

	//m_vSync = pWindow->m_vSync;
	UINT numModes;

	if (FAILED(CreateDXGIFactory(__uuidof(IDXGIFactory), (void **)&pDxgiFactory)))
	{
		qDebug() << ("Failed to create the dxgi factory");
		return;
	}
	if (FAILED(pDxgiFactory->EnumAdapters(0, &pAdapter)))
	{
		qDebug() << ("Failed to find a compatible adapter");
		return;
	}
	if (FAILED(pAdapter->EnumOutputs(0, &pDxgiOutput)))
	{
		qDebug() << ("Failed to find a compatible monitor");
		return;
	}
	if (FAILED(pDxgiOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL)))
	{
		qDebug() << ("Failed to get the display mode list");
		return;
	}

	displayModeList = new DXGI_MODE_DESC[numModes];
	if (FAILED(pDxgiOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList)))
	{
		qDebug() << ("Failed to get the display mode list");
		return;
	}

	// TODO: Get the actual refresh rate of the client
	Uint32 numerator, denominator;
	numerator = 40;
	denominator = 1;

	DXGI_ADAPTER_DESC videoCardDesc;

	if (FAILED(pAdapter->GetDesc(&videoCardDesc)))
	{
		qDebug() << ("Failed to get the video card description");
		return;
	}

	delete[] displayModeList;
	pDxgiOutput->Release();
	pDxgiOutput = nullptr;

	pAdapter->Release();
	pAdapter = nullptr;

	pDxgiFactory->Release();
	pDxgiFactory = nullptr;

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = (float)width;
	swapChainDesc.BufferDesc.Height = (float)height;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	
	swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = windowHandle;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = true;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;

	if (FAILED(
		D3D11CreateDeviceAndSwapChain(NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL, deviceCreateFlags, featureLevels, numFeatures,
			D3D11_SDK_VERSION, &swapChainDesc,
			&m_pDxgiSwapChain, &m_pDevice,
			&m_featureLevel, &m_pDeviceContext)))
	{
		qDebug() << ("Failed to create the device and swap chain");
		return;
	}
	if (FAILED(m_pDxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void **)&pBackBufferTexture)))
	{
		qDebug() << ("Failed to create the back buffer");
		return;
	}
	if (FAILED(m_pDevice->CreateRenderTargetView(pBackBufferTexture, NULL, &m_pRenderTargetView)))
	{
		qDebug() << ("Failed to set the back buffer");
		return;
	}
	pBackBufferTexture->Release();
	pBackBufferTexture = nullptr;

	D3D11_TEXTURE2D_DESC backBufferDesc;
	ZeroMemory(&backBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));
	backBufferDesc.Width = width;
	backBufferDesc.Height = height;
	backBufferDesc.MipLevels = 1;
	backBufferDesc.ArraySize = 1;
	backBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	backBufferDesc.SampleDesc.Count = 1;
	backBufferDesc.SampleDesc.Quality = 0;
	backBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	backBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	backBufferDesc.CPUAccessFlags = 0;
	backBufferDesc.MiscFlags = 0;

	if (FAILED(m_pDevice->CreateTexture2D(&backBufferDesc, NULL, &m_pDepthStencilBuffer)))
	{
		qDebug() << ("Failed to create the depth stencil buffer texture");
		return;
	}

	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));
	depthStencilDesc.DepthEnable = TRUE;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthStencilDesc.StencilEnable = FALSE;

	if (FAILED(m_pDevice->CreateDepthStencilState(&depthStencilDesc, &m_pDepthStencilState)))
	{
		qDebug() << ("Failed to create the depth stencil state");
		return;
	}

	m_pDeviceContext->OMSetDepthStencilState(m_pDepthStencilState, 0);

	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	ZeroMemory(&depthStencilViewDesc, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	if (FAILED(m_pDevice->CreateDepthStencilView(m_pDepthStencilBuffer,
		&depthStencilViewDesc, &m_pDepthStencilView)))
	{
		qDebug() << ("Failed to create the depth stencil view");
		return;
	}

	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	D3D11_RASTERIZER_DESC rasterizerDesc;
	ZeroMemory(&rasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));
	rasterizerDesc.AntialiasedLineEnable = false;
	rasterizerDesc.CullMode = D3D11_CULL_NONE;
	rasterizerDesc.DepthBias = 0;
	rasterizerDesc.DepthBiasClamp = 0.0f;
	rasterizerDesc.DepthClipEnable = false;
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.FrontCounterClockwise = false;
	rasterizerDesc.MultisampleEnable = false;
	rasterizerDesc.ScissorEnable = false;
	rasterizerDesc.SlopeScaledDepthBias = 0.0f;

	if (FAILED(m_pDevice->CreateRasterizerState(&rasterizerDesc, &m_pRasterizerState)))
	{
		return;
	}

	m_pDeviceContext->RSSetState(m_pRasterizerState);

	m_viewport.Width = width;
	m_viewport.Height = height;
	m_viewport.MinDepth = 0.0f;
	m_viewport.MaxDepth = 1.0f;
	m_viewport.TopLeftX = 0.0f;
	m_viewport.TopLeftY = 0.0f;

	m_pDeviceContext->RSSetViewports(1, &m_viewport);

	return;
}

static const float clearColor[4] = { 0.9f, 0.3f, 0.3f, 1.0f };

void D3D11Renderer::Clear()
{
	m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);
	m_pDeviceContext->RSSetState(m_pRasterizerState);
	m_pDeviceContext->RSSetViewports(1, &m_viewport);
}

void D3D11Renderer::Swap(Sint32 vsync)
{
	m_pDxgiSwapChain->Present(vsync, 0);
}

void D3D11Renderer::Cleanup()
{
    m_pDeviceContext->ClearState();
	m_pRenderTargetView->Release();
	m_pDxgiSwapChain->Release();
	m_pDeviceContext->Release();
    m_pDevice->Release();
	
	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pRenderTargetView	= nullptr;
	m_pDxgiSwapChain	= nullptr;
}


