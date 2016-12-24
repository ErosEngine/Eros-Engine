#include "OGLModel.h"


bool OGLModel::loadFromFile(const char *fileName)
{
	return i_mesh.loadFromFile(fileName);
}

void OGLModel::generateBuffers()
{	
	glGenVertexArrays(1, &m_buffer.vertexArray);
	glGenBuffers(1, &m_buffer.arrayBuffer);
	glGenBuffers(1, &m_buffer.indexBuffer);
	
	glBindVertexArray(m_buffer.vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer.arrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, i_mesh.vertexes.size() * sizeof(Vertex), 
				 &i_mesh.vertexes[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, i_mesh.indices.size() * sizeof(GLushort),
				 &i_mesh.indices[0], GL_STATIC_DRAW);
	
	// Note(kiecker): Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
	
	// Note(kiecker): Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, normal));
	
	// Note(kiecker): Texture Coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, texCoords));
}

void OGLModel::draw()
{
	
}

void OGLModel::cleanup()
{
	glDeleteBuffers(1, &m_buffer.arrayBuffer);
	glDeleteBuffers(1, &m_buffer.indexBuffer);
	glDeleteVertexArrays(1, &m_buffer.vertexArray);
}

void *OGLModel::getBuffer()
{
	return (void *)&m_buffer;
}


