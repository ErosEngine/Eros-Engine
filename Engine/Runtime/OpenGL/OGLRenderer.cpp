#include "OGLRenderer.h"
#include <QDebug.h>
#include "Core/Platform.h"
#if defined(EROS_WINDOWS)
	#include <GL/wglew.h>
	#include <wingdi.h>
	#include <WinUser.h>
#elif defined(EROS_LINUX)

#endif
#include <GL/glew.h>


void OpenGLRenderer::Create(GenericHandle hWindow, int width, int height, int flags)
{
#if defined(EROS_WINDOWS)
	
	HWND windowHandle = (HWND)hWindow;
	
	m_deviceHandle = GetDC(windowHandle);
	
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
	int indexPixelFormat = ChoosePixelFormat(m_deviceHandle, &pixelFormatDescriptor);
	
	DescribePixelFormat(m_deviceHandle, indexPixelFormat,
		sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor);
	
	// set the device handle to have the pixel format
	SetPixelFormat(m_deviceHandle, indexPixelFormat, &pixelFormatDescriptor);
	
	// Create the render context
	HGLRC openglRenderContextHandle = wglCreateContext(m_deviceHandle);
	
	wglMakeCurrent(NULL, NULL);
	
	// make the context current
	if (!wglMakeCurrent(m_deviceHandle, openglRenderContextHandle))
	{
		return;
	}

	assert(glewInit() == GLEW_OK);
	
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB 
			= (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	
	m_OGLrenderContextHandle = wglCreateContextAttribsARB(m_deviceHandle, openglRenderContextHandle, NULL);
		
	if (m_OGLrenderContextHandle)
	{
		if (!wglMakeCurrent(m_deviceHandle, m_OGLrenderContextHandle))
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

void OpenGLRenderer::Swap()
{
#if defined(EROS_WINDOWS)
	SwapBuffers(m_deviceHandle);
#elif defined(EROS_LINUX)
	
#endif
}

void OpenGLRenderer::Cleanup()
{
#if defined(EROS_WINDOWS)
	wglMakeCurrent(NULL, NULL);
	DeleteDC(m_deviceHandle);
#endif
}

