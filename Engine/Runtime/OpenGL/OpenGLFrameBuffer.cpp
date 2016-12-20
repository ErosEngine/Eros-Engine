#include "OpenGLFrameBuffer.h"


OpenGLFrameBuffer::OpenGLFrameBuffer()
{
}

void OpenGLFrameBuffer::create(FrameBufferType type, int windowWidth, int windowHeight)
{
    m_frameBufferType = type;
    
    // First we generate the framebuffer that will be drawn to the window
    glGenFramebuffers(1, &m_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
    
    // Then we generate the texture, set to an empty texture
    glGenTextures(1, &m_renderedTexture);
    glBindTexture(GL_TEXTURE_2D, m_renderedTexture);
    glTexImage2D(
        GL_TEXTURE_2D, 
        0, GL_RGB, 
        windowWidth, 
        windowHeight, 
        0, GL_RGB, 
        GL_UNSIGNED_BYTE, 
        NULL
    );
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glGenRenderbuffers(1, &m_renderBuffer); 
    glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
    
    // We bind the generated texture to the frame buffer, 
    // and leave it to be written to by the frame buffer
    if (type == DEPTH_BUFFER)
    {
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, windowWidth, windowHeight);
        glFramebufferRenderbuffer(
                    GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, 
                    GL_RENDERBUFFER, m_renderBuffer);        
    }
    else if (type == STENCIL_BUFFER)
    {
        
    }
    
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_renderedTexture, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0); // Unbind the buffer
}

FrameBufferType OpenGLFrameBuffer::getBufferType()
{
    return m_frameBufferType;
}

GLuint OpenGLFrameBuffer::getBuffer()
{
    return m_frameBuffer;
}

void OpenGLFrameBuffer::bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
}

