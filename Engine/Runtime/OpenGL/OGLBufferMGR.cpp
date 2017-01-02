#include "OGLBufferMGR.h"



OGLBufferMGR::OGLBufferMGR()
{
	
}

void OGLBufferMGR::RegisterMesh(const MeshComponent *mesh)
{
	OpenGLBuffer buffer;
	
	glGenVertexArrays(1, &buffer.vertexArray);
	glGenBuffers(1, &buffer.arrayBuffer);
	glGenBuffers(1, &buffer.indexBuffer);
	
	glBindVertexArray(buffer.vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, buffer.arrayBuffer);	
	glBufferData(GL_ARRAY_BUFFER, mesh->vertexes.size() * sizeof(Vertex), mesh->vertexes.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(ushort), mesh->indices.data(), GL_STATIC_DRAW);
}

void OGLBufferMGR::UnregisterMesh(const QString &meshName)
{
	glDeleteBuffers(1, &m_bufferMap[meshName].indexBuffer);
	glDeleteBuffers(1, &m_bufferMap[meshName].arrayBuffer);
	glDeleteVertexArrays(1, &m_bufferMap[meshName].vertexArray);
}

OpenGLBuffer OGLBufferMGR::GetBuffer(const QString &meshName)
{
	return m_bufferMap[meshName];
}
