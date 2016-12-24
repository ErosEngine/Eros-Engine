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
	
	GLuint				m_renderBuffer, m_frameBuffer;
    GLuint              m_renderedTexture;
	FrameBufferType		m_frameBufferType;
	
public:
	OpenGLFrameBuffer();
	
	void create(FrameBufferType type, int windowWidth, int windowHeight);
	FrameBufferType getBufferType();
	
	GLuint getBuffer();
	
	void bind();
};

#endif // OPENGLFRAMEBUFFER_H
