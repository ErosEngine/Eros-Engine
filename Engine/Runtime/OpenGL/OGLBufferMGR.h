#ifndef OGLVERTEXBUFFERMGR_H
#define OGLVERTEXBUFFERMGR_H

#include <GL/glew.h>
#include "Runtime/Core/Graphics/MeshComponent.h"
#include <QString>
#include <map>


// Stores the essential buffer information
struct OpenGLBuffer
{
	GLuint vertexArray; // from glGenVertexArrays()
	GLuint arrayBuffer; // GL_ARRAY_BUFFER
	GLuint indexBuffer; // GL_ELEMENT_ARRAY_BUFFER
};

class OGLBufferMGR
{
public:
	OGLBufferMGR();
	
	void RegisterMesh(const MeshComponent *mesh);
	void UnregisterMesh(const QString &meshName);
	OpenGLBuffer GetBuffer(const QString &meshName);
	
private:
	
	std::map<QString, OpenGLBuffer> m_bufferMap;
	
};

#endif // OGLVERTEXBUFFERMGR_H
