TEMPLATE = app
CONFIG += c++14
win32: CONFIG += windeployqt
CONFIG -= app_bundle console

QT += core gui widgets network opengl

win32: LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32 -llibfreetype-6
unix: LIBS += -lGLEW -lSDL2 -lfreetype

INCLUDEPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/ExtLibs/include

SOURCES += main.cpp \
    Engine/Runtime/Window/MainWindow.cpp \
    Engine/Runtime/Shaders/Shader.cpp \
    Engine/Developer/FileSystem/Resource.cpp \
    Engine/Runtime/OpenGL/Shape/Primitive.cpp \
    Engine/Editor/MainWindow_Qt.cpp \
    Engine/Runtime/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Runtime/Renderer/OpenGLRenderer.cpp \
    Engine/Runtime/OpenGL/Shape/Texture.cpp \
    Engine/Runtime/Renderer/FontRenderer.cpp \
    Engine/Runtime/OpenGL/Shape/Shape.cpp \
    Engine/Developer/Util/BTextStream.cpp \
    Engine/Developer/Util/EDebugStream.cpp \
    Engine/Runtime/OpenGL/Camera.cpp \
    Engine/Developer/Client/Input.cpp \
    Engine/Runtime/Renderer/ShapeData.cpp \
    Engine/Runtime/OpenGL/Shape/Transform.cpp
    

HEADERS += \
    Engine/Runtime/Window/MainWindow.h \
    Engine/Runtime/Shaders/Shader.h \
    Engine/Runtime/OpenGL/Coordinates.h \
    Engine/Developer/FileSystem/Resource.h \
    Engine/Runtime/OpenGL/Shape/Primitive.h \
    Engine/Runtime/Renderer/OpenGLRenderer.h \
    Engine/Developer/Util/Util.h \
    Engine/Editor/MainWindow_Qt.h \
    Engine/Runtime/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/Developer/FileSystem/stb_image.h \
    Engine/Runtime/OpenGL/Shape/Texture.h \
    Engine/Runtime/Renderer/FontRenderer.h \
    Engine/Runtime/OpenGL/Shape/Shape.h \
    Engine/Developer/Util/BTextStream.h \
    Engine/Developer/Util/EDebugStream.h \
    Engine/Runtime/OpenGL/Camera.h \
    Engine/Developer/Client/Input.h \
    Engine/Runtime/Renderer/ShapeData.h \
    Engine/Runtime/OpenGL/Shape/Transform.h

DISTFILES += \
    Engine/Runtime/Shaders/baseFrag.frag \
    Engine/Runtime/Shaders/baseVert.vert

FORMS += \
    Engine/Editor/MainWindow_Qt.ui \
    Engine/Runtime/Window/OpeningDialog.ui

RESOURCES += \
    Assets/PlayButton.qrc
