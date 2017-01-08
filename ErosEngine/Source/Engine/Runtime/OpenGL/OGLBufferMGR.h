#ifndef OGLVERTEXBUFFERMGR_H
#define OGLVERTEXBUFFERMGR_H

#include <GL/glew.h>
#include "Runtime/Core/Graphics/MeshComponent.h"
#include <QtCore/QString>
#include <map>


// Stores the essential buffer information
struct OpenGLBuffer
{
	Uint32 vertexArray; // from glGenVertexArrays()
	Uint32 arrayBuffer; // GL_ARRAY_BUFFER
	Uint32 indexBuffer; // GL_ELEMENT_ARRAY_BUFFER
};

class OGLBufferMGR
{
public:
	OGLBufferMGR();
	
	void RegisterMesh(const MeshComponent *mesh);
	void UnregisterMesh(const QString &meshName);
	OpenGLBuffer GetBuffer(const QString &meshName);
	
private:
	
	std::map<QString, OpenGLBuffer> m_BufferMap;
	
};

#endif // OGLVERTEXBUFFERMGR_H
