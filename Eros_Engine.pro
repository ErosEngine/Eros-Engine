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
    Engine/Runtime/Shaders/Shader.cpp \
    Engine/Runtime/OpenGL/Primitive.cpp \
    Engine/Editor/MainWindow_Qt.cpp \
    Engine/Runtime/Window/OpeningDialog.cpp \
    Engine/Editor/OpenGLViewPort.cpp \
    Engine/Runtime/Renderer/OpenGLRenderer.cpp \
    Engine/Runtime/OpenGL/Texture.cpp \
    Engine/Runtime/Renderer/FontRenderer.cpp \
    Engine/Runtime/OpenGL/Shape.cpp \
    ErosLib/BTextStream.cpp \
    ErosLib/EDebugStream.cpp \
    Engine/Runtime/OpenGL/Camera.cpp \
    Engine/Developer/Client/Input.cpp \
    Engine/Runtime/Renderer/ShapeData.cpp \
    Engine/Runtime/OpenGL/Transform.cpp \
    Engine/Runtime/OpenGL/Model.cpp \
    Engine/Developer/FileSystem/EFile.cpp \
    Engine/Developer/Util/Util.cpp \
    Engine/Editor/DebugLogger.cpp \
    Engine/Editor/LoggerMessage.cpp
    

HEADERS += \
    Engine/Runtime/Window/MainWindow.h \
    Engine/Runtime/Shaders/Shader.h \
    Engine/Runtime/OpenGL/Primitive.h \
    Engine/Runtime/Renderer/OpenGLRenderer.h \
    Engine/Developer/Util/Util.h \
    Engine/Editor/MainWindow_Qt.h \
    Engine/Runtime/Window/OpeningDialog.h \
    Engine/Editor/OpenGLViewPort.h \
    Engine/Developer/FileSystem/stb_image.h \
    Engine/Runtime/OpenGL/Texture.h \
    Engine/Runtime/Renderer/FontRenderer.h \
    Engine/Runtime/OpenGL/Shape.h \
    ErosLib/BTextStream.h \
    ErosLib/EDebugStream.h \
    Engine/Runtime/OpenGL/Camera.h \
    Engine/Developer/Client/Input.h \
    Engine/Runtime/Renderer/ShapeData.h \
    Engine/Runtime/OpenGL/Transform.h \
    Engine/Runtime/OpenGL/Model.h \
    ErosLib/ErosDefines.h \
    Engine/Developer/FileSystem/EFile.h \ 
    Engine/Editor/DebugLogger.h \
    Engine/Editor/LoggerMessage.h \
    ErosLib/Math.h

DISTFILES += \
    Engine/Runtime/Shaders/baseFrag.frag \
    Engine/Runtime/Shaders/baseVert.vert

FORMS += \
    Engine/Editor/MainWindow_Qt.ui \
    Engine/Runtime/Window/OpeningDialog.ui

RESOURCES += \
    Engine/Assets/PlayButton.qrc
