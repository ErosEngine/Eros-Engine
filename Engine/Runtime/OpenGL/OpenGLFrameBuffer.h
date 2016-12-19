#ifndef OPENGLFRAMEBUFFER_H
#define OPENGLFRAMEBUFFER_H

#include <GL/glew.h>


enum FrameBufferType
{
	DEPTH_BUFFER = 1,
	STENCIL_BUFFER = 2 // TODO(kiecker): Add more buffer types
};

class OpenGLFrameBuffer
{
	friend class OpenGLRenderer;
	
	GLuint				m_frameBuffer;
	FrameBufferType		m_frameBufferType;
	
public:
	OpenGLFrameBuffer();
	
	void createFrameBuffer(FrameBufferType type);
	FrameBufferType getBufferType();
	
	GLuint getFrameBuffer();
	
	void bind();
};

#endif // OPENGLFRAMEBUFFER_H
