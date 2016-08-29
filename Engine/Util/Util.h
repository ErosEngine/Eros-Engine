#ifndef UTIL_H
#define UTIL_H

#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Window/MainWindow.h"
#include "Engine/Renderer/FontRenderer.h"
#include "Engine/Util/EDebugStream.h"

#define eDebug() (*Util::EDebug())
#define endl Util::freeData();

namespace Util
{
    inline EDebugStream *EDebug()
    {
        return EDebugStream::getInstance();
    }
    
    template<typename T>
    inline int eros_arraySize(T *arr) 
    {
        return sizeof(arr) / sizeof(T); 
    }
    
    inline const char *freeData() // End line and free data
    {
        EDebug()->freeData();
        return "\n";
    }
}

#endif // UTIL_H
