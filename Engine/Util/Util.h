#ifndef UTIL_H
#define UTIL_H

#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Window/MainWindow.h"
#include "Engine/Renderer/FontRenderer.h"
#include "Engine/Util/EDebugStream.h"

#define eDebug() (*EDebug())

namespace Priv 
{ 
    static bool isEditor;
    static EDebugStream *stream;
}

inline static EDebugStream *EDebug()
{
    if (!Priv::stream) // if the stream hasn't initialized yet
        Priv::stream = new EDebugStream(Priv::isEditor); // Alloc some memory
    return Priv::stream;
}


#endif // UTIL_H
