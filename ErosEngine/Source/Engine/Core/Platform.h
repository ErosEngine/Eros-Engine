#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32) || defined(_WIN64)
	#define EROS_WINDOWS
#elif defined(unix)
	#define EROS_LINUX
#endif

#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif


#include "Common.h"



#endif // PLATFORM_H
