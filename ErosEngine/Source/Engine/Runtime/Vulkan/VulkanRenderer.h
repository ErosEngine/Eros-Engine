#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vulkan.hpp>
#include "Runtime/Core/Framework/IRenderer.h"

class VulkanRenderer : public IRenderer
{
public:

    VulkanRenderer();
	
	virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) override;

	virtual void Clear() override;
	virtual void RenderScene() override;
	virtual void Swap(Sint32 vsync) override;
	virtual void Cleanup() override;
	virtual void ResizeTarget(Sint32 width, Sint32 height) override;

	virtual void SetScene(Scene *pScene) override;
	virtual void OnSceneUnload() override;
	
private:
	
	VkInstance m_Instance;
	
};
