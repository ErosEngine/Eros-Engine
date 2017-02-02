#include "VulkanRenderer.h"

VulkanRenderer::VulkanRenderer()
{
	
}

bool VulkanRenderer::Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{
	VkApplicationInfo applicationInfo = { };
	applicationInfo.apiVersion = VK_API_VERSION_1_0;
	applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	applicationInfo.pApplicationName = "Vulkan application";
	applicationInfo.pEngineName = "Eros Engine";
	applicationInfo.pNext = nullptr;
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

	VkInstanceCreateInfo instance = { };
	instance.pNext = nullptr;
	instance.pApplicationInfo = &applicationInfo;
	instance.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

	VkResult res = vkCreateInstance(&instance, nullptr, &m_Instance);

	if (!res)
	{
		return false;
	}

	return true;
	
}

void VulkanRenderer::Clear()
{
}

void VulkanRenderer::RenderScene()
{
}

void VulkanRenderer::Swap(Sint32 vsync)
{
}

void VulkanRenderer::Cleanup()
{
}

void VulkanRenderer::ResizeTarget(Sint32 width, Sint32 height)
{

}

void VulkanRenderer::SetScene(Scene *pScene)
{
}

void VulkanRenderer::OnSceneUnload()
{
}
