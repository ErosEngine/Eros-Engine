#ifndef UTIL_H
#define UTIL_H

#ifndef MAINWINDOW_QT_H
#include "Engine/Editor/MainWindow_Qt.h"
#endif
#ifndef MAINWINDOW_H
#include "Engine/Window/MainWindow.h"
#endif
#include "Engine/Renderer/FontRenderer.h"
#include "Engine/Util/EDebugStream.h"
#include "Engine/FileSystem/Resource.h"

#define eDebug() (*EDebug())
#define endl EDebug()->freeData();

inline EDebugStream *EDebug()
{
    
    return EDebugStream::getInstance();
}

template<typename T>
inline int eros_arraySize(T *arr) 
{
    return sizeof(arr) / sizeof(T);
}

inline QString eros_toQString(double val)        { return QString::fromStdString(std::to_string(val)); }    
inline QString eros_toQString(float val)         { return QString::fromStdString(std::to_string(val)); }    
inline QString eros_toQString(int val)           { return QString::fromStdString(std::to_string(val)); }    
inline QString eros_toQString(short val)         { return QString::fromStdString(std::to_string(val)); }    
inline QString eros_toQString(unsigned int val)  { return QString::fromStdString(std::to_string(val)); }    
inline QString eros_toQString(unsigned short val){ return QString::fromStdString(std::to_string(val)); }




#endif // UTIL_H
