#ifndef IRENDERBASE_H
#define IRENDERBASE_H

#include "Core/Platform.h"
#include "Scene.h"
#include <vector>
#include <algorithm>
#include <list>
#include <xfunctional>
#include <memory>
#include "Engine/Runtime/Core/Graphics/Material.h"
#include "Engine/Runtime/Core/Graphics/CameraComponent.h"
#include "Engine/Runtime/Core/Graphics/MeshComponent.h"


enum RenderableType
{
	RenderableType_MESH = 1,
	RenderableType_MATERIAL = 2,
	RenderableType_CAMERA = 3
};


/* ==============
 * The rendering interface
=============== */
class IRenderer
{
public:
	
    virtual bool Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags) = 0;
	
	// The clear and draw functions that will
	// be abstracted to the rendering api's
	virtual void Clear()			= 0;
	virtual void RenderScene()		= 0;
	virtual void Swap(Sint32 vsync)	= 0;
	virtual void Cleanup()			= 0;
	virtual void ResizeTarget(Sint32 width, Sint32 height) = 0;

	// Scene handling - will be looking for a camera component in all the scenes
	// otherwise what is the point of rendering it
	virtual void SetScene(Scene *pScene)	= 0;
	virtual void OnSceneUnload()			= 0;
	
protected:
	
	Scene *m_pCurrentScene = nullptr;

};


#endif // IRENDERBASE_H
