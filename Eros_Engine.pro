TEMPLATE = app
CONFIG += c++14 windeployqt 
CONFIG -= app_bundle console

QT += core gui widgets network opengl

LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32 -llibfreetype-6

INCLUDEPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/ExtLibs/include

SOURCES += main.cpp \
    Engine/Window/MainWindow.cpp \
    Engine/Shaders/Shader.cpp \
    Engine/FileSystem/Resource.cpp \
    Engine/OpenGL/Primitive.cpp \
    Engine/Editor/MainWindow_Qt.cpp \
    Engine/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Renderer/OpenGLRenderer.cpp \
    Engine/OpenGL/Texture.cpp \
    Engine/Renderer/FontRenderer.cpp \
    Engine/OpenGL/Shape.cpp \
    Engine/Util/BTextStream.cpp \
    Engine/Util/EDebugStream.cpp \
    Engine/OpenGL/Camera.cpp
    

HEADERS += \
    Engine/Window/MainWindow.h \
    Engine/Shaders/Shader.h \
    Engine/OpenGL/Coordinates.h \
    Engine/FileSystem/Resource.h \
    Engine/OpenGL/Primitive.h \
    Engine/Renderer/OpenGLRenderer.h \
    Engine/Util/Util.h \
    Engine/Editor/MainWindow_Qt.h \
    Engine/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/FileSystem/stb_image.h \
    Engine/OpenGL/Texture.h \
    Engine/Window/Input.h \
    Engine/Renderer/FontRenderer.h \
    Engine/OpenGL/Shape.h \
    Engine/Util/BTextStream.h \
    Engine/Util/EDebugStream.h \
    Engine/OpenGL/Camera.h

DISTFILES += \
    Engine/Shaders/baseFrag.frag \
    Engine/Shaders/baseVert.vert

FORMS += \
    Engine/Editor/MainWindow_Qt.ui \
    Engine/Window/OpeningDialog.ui
