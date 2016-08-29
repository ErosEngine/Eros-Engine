#ifndef UTIL_H
#define UTIL_H

#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Window/MainWindow.h"
#include "Engine/Renderer/FontRenderer.h"
#include "Engine/Util/EDebugStream.h"

#define eDebug() (*EDebug())
#define endL "\n"

inline EDebugStream *EDebug()
{
    return EDebugStream::getInstance();
}

template<typename T>
inline int eros_arraySize(T *arr) 
{ 
    return sizeof(arr / sizeof(T)); 
}

#endif // UTIL_H
