#include "Engine/Runtime/Window/OpeningDialog.h"
#include "Engine/Runtime/Window/MainWindow.h"
#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Editor/OpenGLViewPort.h"
#include <QApplication>

#define TEST 0

int main(int argc, char **argv)
{
#if TEST
    
    QApplication a(argc, argv);
    OpenGLViewPort p;
    p.show();
    a.exec();
    
#else
    
    QApplication a(argc, argv);
    
    OpeningDialog d;
    d.show();
    d.exec();
    
    if (d.returnedType == WindowType::WINDOW_SDL)
    {
        MainWindowSDL w;
        w.create("Eros Engine", 1000, 650, WINDOWED_RESIZEABLE_WINDOW);
        return 0;
    }
    if (d.returnedType == WindowType::WINDOW_QT)
    {
        MainWindow_Qt w;
        w.show();
        a.exec();
    }
    
#endif
    
    return 0;
}

