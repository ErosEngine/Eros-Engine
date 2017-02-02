#ifndef COMPONENTSBASE_H
#define COMPONENTSBASE_H

#include "Core/Platform.h"
#include <glm/glm.hpp>
#include <QtCore/QString>

enum ComponentType
{
	ComponentType_MESH = 1,
	ComponentType_MATERIAL = 2,
	ComponentType_CAMERA = 3,
	ComponentType_TRANSFORM = 4
};

class IComponent
{
public:
	
	IComponent() { }
	
	virtual ~IComponent() { }
	
	virtual void CreateFromOther(const IComponent *other) = 0;
	virtual void FreeResources() = 0;

	virtual QString ToString() const { return "Unnamed Component"; }
	virtual ComponentType GetType() const = 0;
};

class ILoadedComponent : public IComponent
{
public:

	ILoadedComponent() { }
	
	virtual ~ILoadedComponent() { }
	
	virtual bool LoadFromFile(const char *fileName) = 0;
	
	QString FileName;
};

enum CameraType
{
	CameraType_PERSPECTIVE,
	CameraType_ORTHOGRAPHIC
};

class ICameraComponent : public IComponent
{
public:

	virtual void Initialize(float width, float height, float zNear, float zFar, CameraType type) = 0;

	virtual glm::mat4 GetPerspective() const = 0;
	virtual glm::mat4 GetModelView() const = 0;

};

// TODO
class IScriptComponent : public IComponent
{
public:
	
	IScriptComponent() { } 
	
	virtual ~IScriptComponent() { }
	
};

// TODO
class IAudioComponent : public IComponent
{
public:
	
	IAudioComponent() { }
	
	virtual ~IAudioComponent() { }
	
};


#endif // COMPONENTSBASE_H
