#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Runtime/Window/Window.h"
#include "../Core/Framework/IRenderer.h"
#include "Runtime/Core/Entity/EntityManager.h"
#include "OGLShader.h"
#include <cassert>



class OpenGLRenderer : public IRenderer
{
public:
    
	OpenGLRenderer() { }
	
    virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) override;
    
	virtual void Clear() override;
	virtual void RenderScene() override;
	virtual void Swap(Sint32 vsync) override;
	virtual void Cleanup() override;
	virtual void ResizeTarget(Sint32 width, Sint32 height) override;
	
	virtual void SetScene(Scene *pScene) override;
	virtual void OnSceneUnload() override;

private:
	
	OGLShaderProgram m_GlobalShader;

#if defined(EROS_WINDOWS)
	
	HDC m_DeviceHandle;
	HGLRC m_OGLrenderContextHandle;
	
#elif defined(EROS_LINUX)
	
#endif

	struct OpenGLQueueObject
	{
		RenderableType type;
		Uint32 firstBuffer;
		Uint32 secondBuffer;
		Uint32 thirdBuffer;
		Uint32 fourthBuffer;
		glm::vec3 position;
	};

	struct OpenGLQueueEntity
	{
		// So that we can call back to the referred entity
		Uint64							entityRef;
		std::vector<OpenGLQueueObject>	objects;
	};
	
	struct OpenGLQueue
	{
		std::vector<OpenGLQueueEntity> entities;

		void AddItem(OpenGLQueueEntity &object)
		{
			entities.push_back(object);
		}

		// TODO: Maybe make this sort based on camera position;
		void SortObjects()
		{
			std::sort(entities.begin(), entities.end(), [](OpenGLQueueEntity &right, OpenGLQueueEntity &left)
			{
				EntityManager *pManager = EntityManager::GetInstance();

				const Entity *entity1 = pManager->GetEntityByID(right.entityRef);
				const Entity *entity2 = pManager->GetEntityByID(left.entityRef);

				float rLen = glm::length(entity1->transform.GetPosition());
				float lLen = glm::length(entity2->transform.GetPosition());
				return rLen > lLen;
			});
		}
	} m_OpenGLQueue;
	
};

#endif // OPENGLRENDERER_H
