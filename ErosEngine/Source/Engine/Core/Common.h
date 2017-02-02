#pragma once

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _MEMORY_
#include <memory>
#endif

enum Api
{
	Api_DIRECTX_09	= 1,
	Api_OPENGL_4_0	= 2,
	Api_DIRECTX_11	= 3,
	Api_VULKAN		= 4,
	Api_DIRECTX_12	= 5
};


typedef char		Sint8;
typedef short		Sint16;
typedef int			Sint32;
typedef long long	Sint64;

typedef unsigned char		Uint8;
typedef unsigned short		Uint16;
typedef unsigned int		Uint32;
typedef unsigned long long	Uint64;

typedef Uint8 Byte;

typedef float Real32;
typedef double Real64;

typedef void *Handle;
typedef Uint8 *Buffer;

template<typename T>
using PointerList = std::vector<std::shared_ptr<T>>;

#define BIT(x) (1 << x)

