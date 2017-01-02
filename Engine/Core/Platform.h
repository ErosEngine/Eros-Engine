#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(WIN32) || defined(WIN64)
	#define EROS_WINDOWS
#elif defined(unix)
	#define EROS_LINUX
#endif

enum RenderingType
{
	API_OPENGL_4_5	= 1,
	API_DIRECTX_11	= 2,
	API_VULKAN		= 3,
	API_DIRECTX_12	= 4
};

typedef void *GenericHandle;


#endif // PLATFORM_H
