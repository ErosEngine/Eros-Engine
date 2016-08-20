TEMPLATE = app
CONFIG += c++14 windeployqt
CONFIG -= app_bundle console

QT += core gui widgets network opengl

LIBS += -L$$PWD/ExtLibs/libs/ -lglew32 -lSDL2 -lSDL2main -lSDL2test -lopengl32

INCLUDEPATH += $$PWD/ExtLibs/include
DEPENDPATH += $$PWD/ExtLibs/include

SOURCES += main.cpp \
    Engine/Window/MainWindow.cpp \
    Engine/Shaders/Shader.cpp \
    Engine/FileSystem/Resource.cpp \
    Engine/Geometry/Primitive.cpp \
    Engine/Window/MainWindow_Qt.cpp \
    Engine/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Renderer/OpenGLRenderer.cpp \
    Engine/Geometry/Texture.cpp
    

HEADERS += \
    Engine/Window/MainWindow.h \
    Engine/Shaders/Shader.h \
    Engine/Geometry/Coordinates.h \
    Engine/FileSystem/Resource.h \
    Engine/Geometry/Primitive.h \
    Engine/Renderer/OpenGLRenderer.h \
    Engine/Window/Util.h \
    Engine/Window/MainWindow_Qt.h \
    Engine/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/FileSystem/stb_image.h \
    Engine/Geometry/Texture.h

DISTFILES += \
    Engine/Shaders/baseFrag.frag \
    Engine/Shaders/baseVert.vert

FORMS += \
    Engine/Window/MainWindow_Qt.ui \
    Engine/Window/OpeningDialog.ui
