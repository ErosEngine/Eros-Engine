TEMPLATE = app
CONFIG += c++14
win32: CONFIG += windeployqt
CONFIG -= app_bundle console

QT += core gui widgets network opengl

win32: LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32 -ld3d11 -ldxgi -lkernel32 -lgdi32 -luser32 -llibfbxsdk -lvulkan-1
unix: LIBS += -lGLEW -lSDL2 

INCLUDEPATH += $$PWD/ExtLibs/include
INCLUDEPATH += $$PWD/Engine/
DEPENDPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/Engine/

SOURCES += main.cpp \
    Engine/Runtime/Window/Window.cpp \
    Engine/Editor/EditorWindow.cpp \
    Engine/Runtime/Window/OpeningDialog.cpp \
    Engine/Runtime/Core/Graphics/Texture.cpp \
    Engine/Runtime/Core/Graphics/Camera.cpp \
    Engine/Developer/Client/Input.cpp \
    Engine/Runtime/Core/Graphics/Transform.cpp \
    Engine/Developer/FileSystem/EFile.cpp \
    Engine/Developer/Util/Util.cpp \
    Engine/Editor/DebugLogger.cpp \
    Engine/Editor/LoggerMessage.cpp \
    Engine/Runtime/Core/Graphics/Light.cpp \
    Engine/Runtime/Core/Graphics/Material.cpp \
    Engine/Runtime/Core/Framework/Scene.cpp \
    Engine/Runtime/Vulkan/VulkanRenderer.cpp \
    Engine/Runtime/OpenGL/OGLShader.cpp \
    Engine/Runtime/D3D11/D3D11Renderer.cpp \
    Engine/Runtime/Core/Graphics/MeshComponent.cpp \
    Engine/Runtime/OpenGL/OGLFrameBuffer.cpp \
    Engine/Runtime/OpenGL/OGLRenderer.cpp \
    Engine/Runtime/Core/Framework/Application.cpp \
    Engine/Runtime/Core/Framework/SceneManager.cpp \
    Engine/Editor/Widgets/SceneViewport.cpp \
    Engine/Runtime/OpenGL/OGLBufferMGR.cpp 
    

HEADERS += \
    Engine/Runtime/Window/Window.h \
    Engine/Editor/EditorWindow.h \
    Engine/Runtime/Window/OpeningDialog.h \
    Engine/Developer/FileSystem/stb_image.h \
    Engine/Runtime/Core/Graphics/Texture.h \
    Engine/Runtime/Core/Graphics/Camera.h \
    Engine/Runtime/Core/Graphics/Transform.h \
    Engine/Editor/DebugLogger.h \
    Engine/Editor/LoggerMessage.h \
    Engine/Runtime/Core/Graphics/Light.h \
    Engine/Runtime/Core/Graphics/Material.h \
    Engine/Runtime/Core/Framework/Scene.h \
    Engine/Runtime/Core/Framework/IRenderBase.h \
    Engine/Runtime/Vulkan/VulkanRenderer.h \
    Engine/Runtime/OpenGL/OGLShader.h \
    Engine/Runtime/D3D11/D3D11Renderer.h \
    Engine/Runtime/Core/Framework/ComponentsBase.h \
    Engine/Runtime/Core/Graphics/MeshComponent.h \
    Engine/Runtime/OpenGL/OGLFrameBuffer.h \
    Engine/Runtime/OpenGL/OGLRenderer.h \
    Engine/Runtime/Core/Framework/Application.h \
    Engine/Runtime/Core/Framework/SceneManager.h \
    Engine/Core/Math.h \
    Engine/Core/Platform.h \
    Engine/Editor/Widgets/SceneViewport.h \ 
    Engine/Runtime/OpenGL/OGLBufferMGR.h 

DISTFILES += \
    Engine/Runtime/Shaders/baseFrag.frag \
    Engine/Runtime/Shaders/baseVert.vert \
    Engine/Runtime/Shaders/GlobalVertexShader.vsh \
    Engine/Runtime/Shaders/GlobalFragmentShader.fsh

FORMS += \
    Engine/Editor/EditorWindow.ui \
    Engine/Runtime/Window/OpeningDialog.ui

RESOURCES += \
    Engine/Assets/PlayButton.qrc
