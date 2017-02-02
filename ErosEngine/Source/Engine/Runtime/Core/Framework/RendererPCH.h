#pragma once

#include "IRenderer.h"

#include "Engine/Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/Vulkan/VulkanRenderer.h"

#if defined(EROS_WINDOWS)
#include "Engine/Runtime/D3D9/DX9Renderer.h"
#include "Engine/Runtime/D3D11/DX11Renderer.h"
#include "Engine/Runtime/D3D12/DX12Renderer.h"
#endif