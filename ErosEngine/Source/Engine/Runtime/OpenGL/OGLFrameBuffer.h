#ifndef OPENGLFRAMEBUFFER_H
#define OPENGLFRAMEBUFFER_H

#include <GL/glew.h>
#include "Core/Common.h"


enum FrameBufferType
{
	DEPTH_BUFFER = 1,
	STENCIL_BUFFER = 2 // TODO: Add more buffer types
};

class OpenGLFrameBuffer
{
	friend class OpenGLRenderer;
	
	Uint32				m_RenderBuffer, m_FrameBuffer;
    Uint32              m_RenderedTexture;
	FrameBufferType		m_FrameBufferType;
	
public:
	OpenGLFrameBuffer();
	
	void Create(FrameBufferType type, Sint32 windowWidth, Sint32 windowHeight);
	FrameBufferType GetType();
	
	Uint32 GetBuffer();
	
	void Bind();
};

#endif // OPENGLFRAMEBUFFER_H
