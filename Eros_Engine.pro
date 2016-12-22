TEMPLATE = app
CONFIG += c++14
win32: CONFIG += windeployqt
CONFIG -= app_bundle console

QT += core gui widgets network opengl

win32: LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32 -llibfreetype-6 -lassimp
unix: LIBS += -lGLEW -lSDL2 -lfreetype -lassimp

INCLUDEPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/ExtLibs/include

SOURCES += main.cpp \
    Engine/Runtime/Window/MainWindow.cpp \
    Engine/Editor/MainWindow_Qt.cpp \
    Engine/Runtime/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Runtime/OpenGL/OpenGLRenderer.cpp \
    Engine/Runtime/Core/Texture.cpp \
    Engine/Runtime/OpenGL/FontRenderer.cpp \
    Engine/Runtime/OpenGL/Shape.cpp \
    ErosLib/BTextStream.cpp \
    ErosLib/EDebugStream.cpp \
    Engine/Runtime/OpenGL/Camera.cpp \
    Engine/Developer/Client/Input.cpp \
    Engine/Runtime/Core/Mesh.cpp \
    Engine/Runtime/Core/Transform.cpp \
    Engine/Developer/FileSystem/EFile.cpp \
    Engine/Developer/Util/Util.cpp \
    Engine/Editor/DebugLogger.cpp \
    Engine/Editor/LoggerMessage.cpp \
    Engine/Runtime/Core/Light.cpp \
    Engine/Runtime/Core/Material.cpp \
    Engine/Runtime/Core/Scene.cpp \
    Engine/Runtime/Core/Entity.cpp \
    Engine/Runtime/OpenGL/OpenGLFrameBuffer.cpp \
    Engine/Runtime/Vulkan/VulkanRenderer.cpp \
    Engine/Runtime/Shaders/OGLShader.cpp
    

HEADERS += \
    Engine/Runtime/Window/MainWindow.h \
    Engine/Runtime/OpenGL/OpenGLRenderer.h \
    Engine/Developer/Util/Util.h \
    Engine/Editor/MainWindow_Qt.h \
    Engine/Runtime/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/Developer/FileSystem/stb_image.h \
    Engine/Runtime/Core/Texture.h \
    Engine/Runtime/OpenGL/FontRenderer.h \
    Engine/Runtime/OpenGL/Shape.h \
    ErosLib/BTextStream.h \
    ErosLib/EDebugStream.h \
    Engine/Runtime/OpenGL/Camera.h \
    Engine/Developer/Client/Input.h \
    Engine/Runtime/Core/Mesh.h \
    Engine/Runtime/Core/Transform.h \
    ErosLib/ErosDefines.h \
    Engine/Developer/FileSystem/EFile.h \ 
    Engine/Editor/DebugLogger.h \
    Engine/Editor/LoggerMessage.h \
    ErosLib/Math.h \
    Engine/Runtime/Core/Light.h \
    Engine/Runtime/Core/Material.h \
    Engine/Runtime/Core/Scene.h \
    Engine/Runtime/Core/Entity.h \
    Engine/Runtime/Core/IRenderBase.h \
    Engine/Runtime/Core/IComponent.h \
    Engine/Runtime/OpenGL/OpenGLFrameBuffer.h \
    Engine/Runtime/Vulkan/VulkanRenderer.h \
    Engine/Runtime/Shaders/OGLShader.h

DISTFILES += \
    Engine/Runtime/Shaders/baseFrag.frag \
    Engine/Runtime/Shaders/baseVert.vert

FORMS += \
    Engine/Editor/MainWindow_Qt.ui \
    Engine/Runtime/Window/OpeningDialog.ui

RESOURCES += \
    Engine/Assets/PlayButton.qrc
