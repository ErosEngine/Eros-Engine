#include "OGLFrameBuffer.h"


OpenGLFrameBuffer::OpenGLFrameBuffer()
{
}

void OpenGLFrameBuffer::Create(FrameBufferType type, Sint32 windowWidth, Sint32 windowHeight)
{
    m_FrameBufferType = type;
    
    // First we generate the framebuffer that will be drawn to the window
    glGenFramebuffers(1, &m_FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
    
    // Then we generate the texture, set to an empty texture
    glGenTextures(1, &m_RenderedTexture);
    glBindTexture(GL_TEXTURE_2D, m_RenderedTexture);
    glTexImage2D(
		GL_TEXTURE_2D, 
		0, GL_RGB, 
		windowWidth, 
		windowHeight, 
		0, GL_RGB, 
		GL_UNSIGNED_BYTE, 
		nullptr
    );
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glGenRenderbuffers(1, &m_RenderBuffer); 
    glBindRenderbuffer(GL_RENDERBUFFER, m_RenderBuffer);
    
    // We bind the generated texture to the frame buffer, 
    // and leave it to be written to by the frame buffer
    if (type == DEPTH_BUFFER)
    {
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, windowWidth, windowHeight);
        glFramebufferRenderbuffer(
                    GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, 
                    GL_RENDERBUFFER, m_RenderBuffer);        
    }
    else if (type == STENCIL_BUFFER)
    {
	//	glRenderbufferStorage(GL_RENDERBUFFER, )
    }
    
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_RenderedTexture, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0); // Unbind the buffer
}

FrameBufferType OpenGLFrameBuffer::GetType()
{
    return m_FrameBufferType;
}

Uint32 OpenGLFrameBuffer::GetBuffer()
{
    return m_FrameBuffer;
}

void OpenGLFrameBuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
}

