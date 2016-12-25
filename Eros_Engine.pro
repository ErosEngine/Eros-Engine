TEMPLATE = app
CONFIG += c++14
win32: CONFIG += windeployqt
CONFIG -= app_bundle console

QT += core gui widgets network opengl

win32: LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32 -llibfreetype-6 -lassimp -ld3d11 -ldxgi -lkernel32 -lgdi32 
unix: LIBS += -lGLEW -lSDL2 -lfreetype -lassimp

INCLUDEPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/ExtLibs/include

SOURCES += main.cpp \
    Engine/Runtime/Window/MainWindow.cpp \
    Engine/Editor/MainWindow_Qt.cpp \
    Engine/Runtime/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Runtime/Core/Graphics/Texture.cpp \
    Engine/Runtime/OpenGL/FontRenderer.cpp \
    ErosLib/BTextStream.cpp \
    ErosLib/EDebugStream.cpp \
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
    Engine/Runtime/OpenGL/OGLModel.cpp \
    Engine/Runtime/OpenGL/OGLFrameBuffer.cpp \
    Engine/Runtime/OpenGL/OGLRenderer.cpp \
    Engine/Runtime/Core/Framework/GameLoop.cpp \
    Engine/Runtime/Core/Framework/SceneManager.cpp
    

HEADERS += \
    Engine/Runtime/Window/MainWindow.h \
    Engine/Developer/Util/Util.h \
    Engine/Editor/MainWindow_Qt.h \
    Engine/Runtime/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/Developer/FileSystem/stb_image.h \
    Engine/Runtime/Core/Graphics/Texture.h \
    Engine/Runtime/OpenGL/FontRenderer.h \
    ErosLib/BTextStream.h \
    ErosLib/EDebugStream.h \
    Engine/Runtime/Core/Graphics/Camera.h \
    Engine/Developer/Client/Input.h \
    Engine/Runtime/Core/Graphics/Transform.h \
    ErosLib/ErosDefines.h \
    Engine/Developer/FileSystem/EFile.h \ 
    Engine/Editor/DebugLogger.h \
    Engine/Editor/LoggerMessage.h \
    ErosLib/Math.h \
    Engine/Runtime/Core/Graphics/Light.h \
    Engine/Runtime/Core/Graphics/Material.h \
    Engine/Runtime/Core/Framework/Scene.h \
    Engine/Runtime/Core/Framework/IRenderBase.h \
    Engine/Runtime/Vulkan/VulkanRenderer.h \
    Engine/Runtime/OpenGL/OGLShader.h \
    Engine/Runtime/D3D11/D3D11Renderer.h \
    Engine/Runtime/Core/Framework/ComponentsBase.h \
    Engine/Runtime/Core/Graphics/MeshComponent.h \
    Engine/Runtime/OpenGL/OGLModel.h \
    Engine/Runtime/OpenGL/OGLFrameBuffer.h \
    Engine/Runtime/OpenGL/OGLRenderer.h \
    Engine/Runtime/Core/Framework/GameLoop.h \
    Engine/Runtime/Core/Framework/SceneManager.h

DISTFILES += \
    Engine/Runtime/Shaders/baseFrag.frag \
    Engine/Runtime/Shaders/baseVert.vert \
    Engine/Runtime/Shaders/GlobalVertexShader.vsh \
    Engine/Runtime/Shaders/GlobalFragmentShader.fsh

FORMS += \
    Engine/Editor/MainWindow_Qt.ui \
    Engine/Runtime/Window/OpeningDialog.ui

RESOURCES += \
    Engine/Assets/PlayButton.qrc
