#include "D3D11Renderer.h"
#include <SDL.h>
#include <SDL_syswm.h>



D3D11Renderer::D3D11Renderer()
{
	
}

void D3D11Renderer::create(QWidget *pQtWindow)
{
	internalCreate((HWND)pQtWindow->winId(), pQtWindow->width(), pQtWindow->height(), IMMEDIATE_MODE);
}

void D3D11Renderer::create(MainWindowSDL *pMainWindow)
{
	SDL_SysWMinfo sysInfo;
	SDL_VERSION(&sysInfo.version);
	SDL_GetWindowWMInfo(pMainWindow->m_pWindow, &sysInfo);
	int mode = pMainWindow->isFullScreen() ?  DIRECT_MODE : IMMEDIATE_MODE;
	internalCreate(sysInfo.info.win.window, pMainWindow->width(), pMainWindow->height(), mode);
}

void D3D11Renderer::internalCreate(HWND windowHandle, int width, int height, int flags)
{
	// TODO(kiecker): actually process the flags
	UINT deviceCreateFlags = 0;
    #ifdef _DEBUG
    
    deviceCreateFlags |= D3D11_CREATE_DEVICE_DEBUG;
    
    #endif
    
    D3D_DRIVER_TYPE driverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };
    
    UINT numberDriverTypes = 3;
    
    D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_1
    };
    
    UINT numFeatures = 5;
    
    DXGI_SWAP_CHAIN_DESC swapDesc = {};
    ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
    swapDesc.BufferCount = 1;
    swapDesc.BufferDesc.Width = width;
    swapDesc.BufferDesc.Height = height;
    swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapDesc.BufferDesc.RefreshRate.Numerator = 60;
    swapDesc.BufferDesc.RefreshRate.Denominator = 1;
    swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapDesc.OutputWindow = windowHandle;
    swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    swapDesc.Windowed = true;
    swapDesc.SampleDesc.Count = 1;
    swapDesc.SampleDesc.Quality = 0;
    swapDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    
    HRESULT swapChainCreateRes;
    for (int i = 0; i < numberDriverTypes; ++i)
    {
        swapChainCreateRes = D3D11CreateDeviceAndSwapChain
        (
            NULL, driverTypes[i], NULL, deviceCreateFlags,
            featureLevels, numFeatures, D3D11_SDK_VERSION, &swapDesc,
            &m_pDxgiSwapChain, &m_pDevice, &m_featureLevel, &m_pDeviceContext
        );
    
        if (SUCCEEDED(swapChainCreateRes))
        {
            m_driverType = driverTypes[i];
            break;
        }
    }
    
    if (FAILED(swapChainCreateRes))
    {
        return;
    }
    
    // Creates render target
    ID3D11Texture2D *pBackBufferTexture = NULL;
    
    m_pDxgiSwapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D),
        reinterpret_cast<void **>(&pBackBufferTexture));
    
    m_pDevice->CreateRenderTargetView(pBackBufferTexture, nullptr, &m_pRenderTargetView);
    
    // Sets render target
    m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);
    
    // Create viewport
    m_viewport.Width = (float)width;
    m_viewport.Height = (float)height;
    m_viewport.TopLeftX = -1.0f;
    m_viewport.TopLeftY = 1.0f;
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 100.0f;
    
    m_pDeviceContext->RSSetViewports(1, &m_viewport);
}

static const float clearColor[4] = { 1.0f, 0.3f, 0.3f, 1.0f };

void D3D11Renderer::clear()
{
	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);
	m_pDxgiSwapChain->Present(0, 0);
}

void D3D11Renderer::renderArgs()
{
	
}

void D3D11Renderer::cleanup()
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

void D3D11Renderer::setRendererArgs(RendererArgs *pRendererArgs)
{
	
}

const RendererArgs *D3D11Renderer::rendererArgs() const
{
	return i_pRendererArgs;
}


