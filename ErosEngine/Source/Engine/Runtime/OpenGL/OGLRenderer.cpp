#include "OGLRenderer.h"
#include <QtCore/QDebug>
#include "Core/Platform.h"
#if defined(EROS_WINDOWS)
	#include <GL/wglew.h>
	#include <wingdi.h>
	#include <WinUser.h>
#elif defined(EROS_LINUX)

#endif
#include <GL/glew.h>


void OpenGLRenderer::Create(GenericHandle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{
#if defined(EROS_WINDOWS)
	
	HWND windowHandle = (HWND)hWindow;
	
	m_DeviceHandle = GetDC(windowHandle);
	
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // useless parameters
		16,
		0, 0, 0, 0, 0, 0, 0
	};
	
	// Get the pixel format
	Sint32 indexPixelFormat = ChoosePixelFormat(m_DeviceHandle, &pixelFormatDescriptor);
	
	DescribePixelFormat(m_DeviceHandle, indexPixelFormat,
		sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor);
	
	// set the device handle to have the pixel format
	SetPixelFormat(m_DeviceHandle, indexPixelFormat, &pixelFormatDescriptor);
	
	// Create the render context
	HGLRC openglRenderContextHandle = wglCreateContext(m_DeviceHandle);
	
	wglMakeCurrent(NULL, NULL);
	
	// make the context current
	if (!wglMakeCurrent(m_DeviceHandle, openglRenderContextHandle))
	{
		return;
	}

	assert(glewInit() == GLEW_OK);
	
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB 
			= (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	
	m_OGLrenderContextHandle = wglCreateContextAttribsARB(m_DeviceHandle, openglRenderContextHandle, NULL);
		
	if (m_OGLrenderContextHandle)
	{
		if (!wglMakeCurrent(m_DeviceHandle, m_OGLrenderContextHandle))
		{
			return;
		}
	}

	
#elif defined(EROS_LINUX)
	
#endif
	
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
	
	qDebug() << (const char *)glGetString(GL_VERSION);
}

void OpenGLRenderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
}

void OpenGLRenderer::Swap(Sint32 vsync)
{
#if defined(EROS_WINDOWS)
	
	SwapBuffers(m_DeviceHandle);
	wglSwapIntervalEXT(vsync);
	
#elif defined(EROS_LINUX)
	
#endif
}

void OpenGLRenderer::Cleanup()
{
#if defined(EROS_WINDOWS)
	wglMakeCurrent(NULL, NULL);
	DeleteDC(m_DeviceHandle);
#endif
}

