#ifndef COMPONENTSBASE_H
#define COMPONENTSBASE_H

#include "ErosLib/ErosDefines.h"
#include "../Graphics/MeshComponent.h"

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
	
	virtual bool loadFromFile(const char *fileName) = 0;
	
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


class IDrawableComponent : public IComponent
{
public:
	
	virtual ~IDrawableComponent() { }
	
	// The individual buffer information
	// will fill a different structure based 
	// on the api
	virtual void generateBuffers()  = 0;
	virtual void setupBuffers()		= 0;
	
	// The actual Drawing code for the renderer
	virtual void draw()		= 0;
	virtual void cleanup()	= 0;
	
	// Because we won't know the exact buffer 
	// structure we will just return some anonymous memory
	virtual void *getBuffer()	= 0;
	
	inline void loadNewMesh(const char *fileName)
	{
		i_mesh.clearMesh();
		if (!i_mesh.loadFromFile(fileName))
		{
			qDebug() << "Failed to load new mesh!";
		}
	}

	inline const MeshComponent *mesh() const
	{
		return &i_mesh;
	}
	
protected:
	
	MeshComponent i_mesh;
	
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
