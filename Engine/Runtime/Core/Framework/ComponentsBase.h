#ifndef COMPONENTSBASE_H
#define COMPONENTSBASE_H

#include "Core/Platform.h"
#include "../Graphics/MeshComponent.h"
#include "../Graphics/Transform.h"
#include <QDebug>

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#if defined(EROS_WINDOWS) && !defined(__d3d11_h__)
#include <d3d11.h>
#endif


class IComponent
{
public:
	
	virtual ~IComponent() { }
	
	virtual bool LoadFromFile(const char *fileName) = 0;
	virtual void Clear() = 0;
	virtual QString ToString() = 0;
};


struct OpenGLBuffer
{
	GLuint vertexArray; // from glGenVertexArrays()
	GLuint arrayBuffer; // GL_ARRAY_BUFFER
	GLuint indexBuffer; // GL_ELEMENT_ARRAY_BUFFER
};

#if defined(EROS_WINDOWS) && WINVER >= _WIN32_WINNT_WIN7

// TODO(kiecker): Reaserch into DirectX 11
struct D3D11Buffer
{
};

#endif


class IDrawable : public IComponent
{
public:
	
	virtual ~IDrawable() { }
	
};

// TODO
class IScriptComponent : public IComponent
{
public:
	
	virtual ~IScriptComponent() { }
	
};

// TODO
class IAudioComponent : public IComponent
{
public:
	
	virtual ~IAudioComponent() { }
	
};


#endif // COMPONENTSBASE_H
